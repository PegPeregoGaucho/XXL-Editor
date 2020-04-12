#pragma once

#include <functional>
//#include <typeinfo>
#include <cassert>
#include <set>
#include <map>

struct File;
struct KEnvironment;

struct CKObject {
	static std::map<CKObject*, int> refCounts;
	//int refCount = 0;
	void addref() { refCounts[this]++; }
	void release() { refCounts[this]--; }
	int getRefCount() { return refCounts[this]; }
	virtual bool isSubclassOfID(uint32_t fid) = 0;
	virtual int getClassCategory() = 0;
	virtual int getClassID() = 0;
	virtual const char *getClassName() = 0;
	virtual void deserialize(KEnvironment* kenv, File *file, size_t length);
	virtual void serialize(KEnvironment* kenv, File *file);
	virtual ~CKObject() {};

	bool isSubclassOfID(int clcat, int clid) { return isSubclassOfID(clcat | (clid << 6)); }
	template<typename T> bool isSubclassOf() { return isSubclassOfID(T::FULL_ID); }
	uint32_t getClassFullID() { return getClassCategory() | (getClassID() << 6); }
	template<class T> T *cast() {
		assert(isSubclassOfID(T::FULL_ID) && "CKObject Cast Fail");
		return (T*)this;
	}
};

struct CKUnknown : CKObject {
	static const int FULL_ID = -1;
	int clCategory, clId;
	void *mem = nullptr;
	size_t length = 0;

	static std::set<std::pair<int, int>> hits;

	bool isSubclassOfID(uint32_t fid) override;
	int getClassCategory() override;
	int getClassID() override;
	const char *getClassName() override;
	void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	void serialize(KEnvironment* kenv, File *file) override;
	CKUnknown(int category, int id) : clCategory(category), clId(id) {
		hits.insert(std::make_pair(category, id));
	}
	CKUnknown(const CKUnknown &another);
	~CKUnknown();
};

struct KFactory {
	uint32_t fullid;
	CKObject *(*create)();
	CKObject *(*createArray)(int);

	KFactory() : fullid(~0) {}
	KFactory(uint32_t fullid, CKObject *(*create)(), CKObject *(*createArray)(int)) :
		fullid(fullid), create(create), createArray(createArray) {}

	template<class T> static KFactory of() {
		return KFactory(T::FULL_ID, []() -> CKObject* {return new T; }, [](int n) -> CKObject* {return new T[n]; });
	}
};

template<int T_CAT> struct CKCategory : CKObject {
	static const int CATEGORY = T_CAT;
	bool isSubclassOfID(uint32_t fid) override { return fid == CATEGORY; }
	int getClassCategory() override { return CATEGORY; }
};

template<class T, int T_ID> struct CKSubclass : T {
	static const int CLASS_ID = T_ID;
	static const int FULL_ID = T::CATEGORY | (T_ID << 6);
	
	bool isSubclassOfID(uint32_t fid) override {
		//printf("%i :: isSubclass(%i)\n", FULL_ID, fid);
		if (fid == FULL_ID)
			return true;
		return T::isSubclassOfID(fid);
	}
	
	int getClassID() override { return T_ID; }
	const char *getClassName() override { return typeid(*this).name(); }
};

template<class T> struct kobjref {
	CKObject *_pointer;
	T *operator->() const { return (T*)_pointer; }
	T &operator*() const { return *(T*)_pointer; }
	void reset(T *newpointer = nullptr) {
		if (_pointer)
			_pointer->release();
		_pointer = (CKObject*)newpointer;
		if (_pointer)
			_pointer->addref();
	}
	T *get() const { return (T*)_pointer; }
	kobjref() : _pointer(nullptr) {}
	kobjref(T *pointer)				{ _pointer = (CKObject*)pointer; if (_pointer) _pointer->addref(); }
	kobjref(const kobjref &another)	{ _pointer = another._pointer; if (_pointer) _pointer->addref(); }
	kobjref(kobjref &&another)		{ _pointer = another._pointer; another._pointer = nullptr; }
	void operator=(const kobjref &another) { reset((T*)another._pointer); }
	void operator=(kobjref &&another) {
		if (_pointer)
			_pointer->release();
		_pointer = another._pointer;
		another._pointer = nullptr;
	}
	//bool operator==(const kobjref &another) const { return _pointer == another._pointer; }
	//bool operator!=(const kobjref &another) const { return _pointer != another._pointer; }
	~kobjref() { if(_pointer) _pointer->release(); }
};

template<class T, class U> bool operator==(const kobjref<T> &a, const kobjref<U> &b) { return a._pointer == b._pointer; }
template<class T, class U> bool operator!=(const kobjref<T> &a, const kobjref<U> &b) { return a._pointer != b._pointer; }

//struct CKManager : CKCategory<0> {};
//struct CKService : CKCategory<1> {};
//struct CKHook : CKCategory<2> {};
//struct CKHookLife : CKCategory<3> {};
//struct CKGroup : CKCategory<4> {};
//struct CKGroupLife : CKCategory<5> {};
//struct CKComponent : CKCategory<6> {};
//struct CKCamera : CKCategory<7> {};
//struct CKCinematicBloc : CKCategory<8> {};
//struct CKDictionary : CKCategory<9> {};
//struct CKGeometry : CKCategory<10> {};
//struct CKNode : CKCategory<11> {};
//struct CKLogic : CKCategory<12> {};
//struct CKGraphical : CKCategory<13> {};
//struct CKError : CKCategory<14> {};