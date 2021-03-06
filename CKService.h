#pragma once

#include "KObject.h"
#include <vector>
#include <array>
#include "vecmat.h"
#include "Shape.h"
#include "CKUtils.h"
#include "Events.h"

struct CKBeaconKluster;
struct CKSceneNode;
struct CKPFGraphNode;
struct CKHook;
struct CKCinematicScene;
struct CKTriggerDomain;

struct CKService : CKCategory<1> {};

struct CKSrvCollision : CKSubclass<CKService, 2> {
	uint16_t numWhat;
	uint8_t huh;
	std::array<kobjref<CKSceneNode>, 50> dynBSphereProjectiles;
	std::vector<std::vector<kobjref<CKObject>>> objs;
	uint16_t unk1, unk2;
	std::vector<kobjref<CKObject>> objs2; // * unk1
	struct Bing {
		uint16_t v1;
		kobjref<CKObject> obj1, obj2;
		uint16_t b1, b2;
		uint8_t v2;
		std::array<uint8_t, 6> aa;
	};
	std::vector<Bing> bings;
	uint32_t lastnum;

	void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	void serialize(KEnvironment* kenv, File *file) override;
};

struct CKSrvCinematic : CKSubclass<CKService, 4> {
	std::vector<kobjref<CKCinematicScene>> cineScenes;
	kobjref<CKObject> cineBillboard1, cineBillboard2, cineBillboard3;

	void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	void serialize(KEnvironment* kenv, File *file) override;
};

struct CKSrvEvent : CKSubclass<CKService, 5>
{
	struct StructB {
		uint8_t _1, _2; std::vector<CKObject *> users; bool userFound = false;
	};
	uint16_t numA, numB, numC, numObjs;
	std::vector<StructB> bees;
	std::vector<KPostponedRef<CKObject>> objs;
	std::vector<uint16_t> objInfos;

	void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	void serialize(KEnvironment* kenv, File *file) override;
	void onLevelLoaded2(KEnvironment *kenv) override;
};

struct CKSrvPathFinding : CKSubclass<CKService, 6> {
	std::vector<kobjref<CKPFGraphNode>> nodes;
	std::array<kobjref<CKObject>, 4> arQuadTreeBranches;
	std::array<uint32_t, 4> arQTBInts;
	float x2flt = 2.0f;

	void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	void serialize(KEnvironment* kenv, File *file) override;
};

struct CKSrvDetector : CKSubclass<CKService, 7> {
	struct Rectangle {
		Vector3 center;
		float length1, length2;
		uint8_t direction;
	};

	struct Detector {
		uint16_t shapeIndex, nodeIndex, flags; EventNode eventSeqIndex;
	};

	uint16_t numA, numB, numC, numD, numE, numAABB, numSpheres, numRectangles, numRefs, numJ;

	std::vector<AABoundingBox> aaBoundingBoxes;
	std::vector<BoundingSphere> spheres;
	std::vector<Rectangle> rectangles;

	std::vector<Detector> aDetectors, bDetectors, cDetectors, dDetectors, eDetectors;

	std::vector<kobjref<CKSceneNode>> nodes;

	void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	void serialize(KEnvironment* kenv, File *file) override;
};

struct CKSrvMarker : CKSubclass<CKService, 8> {
	struct Marker {
		Vector3 position;
		uint8_t orientation1, orientation2;
		uint16_t val3;
	};
	std::vector<std::vector<Marker>> lists;

	void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	void serialize(KEnvironment* kenv, File *file) override;
};

struct CKSrvBeacon : CKSubclass<CKService, 11> {
	uint8_t unk1;
	uint32_t numHandlers;
	struct Handler {
		uint8_t unk2a, numBits, handlerIndex, handlerId, persistent, x2respawn;
		kobjref<CKObject> object;
	};
	std::vector<Handler> handlers;
	uint32_t numSectors;
	struct BeaconSector {
		uint32_t numUsedBings, numBings, beaconArraySize, numBits;
		std::vector<bool> bits;
		uint32_t numBeaconKlusters;
		std::vector<uint32_t> bkids;
		std::vector<kobjref<CKBeaconKluster>> beaconKlusters;
	};
	std::vector<BeaconSector> beaconSectors;

	void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	void serialize(KEnvironment* kenv, File *file) override;
	void onLevelLoaded(KEnvironment *kenv) override;
};

struct CKSrvTrigger : CKSubclass<CKService, 18> {
	kobjref<CKTriggerDomain> rootDomain;
	uint32_t stUnk1, stUnk2;

	void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	void serialize(KEnvironment* kenv, File *file) override;
};