#pragma once

#include "KObject.h"
#include <array>
#include "vecmat.h"
#include "CKPartlyUnknown.h"
#include "CKUtils.h"
#include "Events.h"

struct CKHookLife;
struct CKGrpBonusPool;
struct CKGrpWildBoarPool;
struct CAnimationDictionary;
struct CKSceneNode;
struct CKBoundingShape;
struct CAnimatedClone;
struct CKHook;
struct CKSoundDictionaryID;
struct CKFlaggedPath;

struct CKHook : CKMRSubclass<CKHook, CKMemberReflectable<CKCategory<2>>, 0> {
	kobjref<CKHook> next;
	uint32_t unk1 = 0;
	kobjref<CKHookLife> life;
	KPostponedRef<CKSceneNode> node;

	// XXL2+:
	uint32_t x2UnkA, x2UnkB;

	void reflectMembers(MemberListener &r);
	void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	void serialize(KEnvironment* kenv, File *file) override;
	void onLevelLoaded(KEnvironment *kenv) override;
};

struct CKHookLife : CKCategory<3> {
	kobjref<CKHook> hook;
	kobjref<CKHookLife> nextLife;
	uint32_t unk1 = 0;

	void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	void serialize(KEnvironment* kenv, File *file) override;
};

struct CKHkPressionStone : CKMRSubclass<CKHkPressionStone, CKHook, 21> {
	kobjref<CKObject> psSquad;
	KPostponedRef<CKObject> psDynGround;
	kobjref<CKObject> psSndDict;
	EventNode psEvtSeq1;
	EventNode psEvtSeq2;
	float psUnk5;
	float psUnk6;
	float psUnk7;
	float psUnk8;
	void reflectMembers(MemberListener &r);
};
struct CKHkHero : CKMRSubclass<CKHkHero, CKHook, 25> {
	kobjref<CKObject> heroGrpTrio;
	uint8_t heroUnk1;
	uint8_t heroUnk2;
	float heroUnk3;
	float heroUnk4;
	float heroUnk5;
	float heroUnk6;
	float heroUnk7;
	float heroUnk8;
	float heroUnk9;
	float heroUnk10;
	float heroUnk11;
	kobjref<CKObject> heroBranch1;
	float heroUnk13;
	float heroUnk14;
	float heroUnk15;
	float heroUnk16;
	float heroUnk17;
	float heroUnk18;
	float heroUnk19;
	float heroUnk20;
	float heroUnk21;
	float heroUnk22;
	float heroUnk23;
	kobjref<CKObject> heroAnimDict;
	float heroUnk25;
	Vector3 heroUnk26;
	Vector3 heroUnk27;
	float heroUnk28;
	float heroUnk29;
	kobjref<CKObject> heroBranch2;
	Vector3 heroUnk31;
	uint8_t heroUnk32;
	float heroUnk33;
	float heroUnk34;
	float heroUnk35;
	std::array<float, 4> heroUnk36;
	std::array<float, 4> heroUnk37;
	std::array<uint8_t, 3> heroUnk38;
	float heroUnk39;
	kobjref<CKObject> heroSphere;
	float heroUnk41;
	float heroUnk42;
	kobjref<CKObject> heroDynSphere;
	kobjref<CKObject> heroCylinder;
	float heroUnk45;
	float heroUnk46;
	kobjref<CKObject> heroParticleNode;
	kobjref<CKObject> heroTrailNode;
	kobjref<CKObject> heroSndDict;
	float heroUnk50;
	float heroUnk51;
	float heroUnk52;
	Vector3 heroUnk53;
	Vector3 heroUnk54;
	uint8_t heroUnk55;
	uint8_t heroUnk56;
	uint8_t heroUnk57;
	float heroUnk58;
	float heroUnk59;
	float heroUnk60;
	float heroUnk61;
	float heroUnk62;
	float heroUnk63;
	float heroUnk64;
	float heroUnk65;
	float heroUnk66;
	float heroUnk67;
	float heroUnk68;
	float heroUnk69;
	float heroUnk70;
	float heroUnk71;
	float heroUnk72;
	float heroUnk73;
	float heroUnk74;
	float heroUnk75;
	float heroUnk76;
	float heroUnk77;
	float heroUnk78;
	float heroUnk79;
	float heroUnk80;
	float heroUnk81;
	float heroUnk82;
	float heroUnk83;
	kobjref<CKObject> heroBranch3;
	float heroUnk85;
	float heroUnk86;
	float heroUnk87;
	float heroUnk88;
	float heroUnk89;
	float heroUnk90;
	float heroUnk91;
	float heroUnk92;
	float heroUnk93;
	uint8_t heroUnk94;
	float heroUnk95;
	float heroUnk96;
	float heroUnk97;
	float heroUnk98;
	float heroUnk99;
	float heroUnk100;
	float heroUnk101;
	float heroUnk102;
	float heroUnk103;
	float heroUnk104;
	float heroUnk105;
	float heroUnk106;
	float heroUnk107;
	std::array<float, 8> heroUnk108;
	float heroUnk109;
	float heroUnk110;
	float heroUnk111;
	float heroUnk112;
	float heroUnk113;
	uint8_t heroUnk114;
	uint8_t heroUnk115;
	float heroUnk116;
	float heroUnk117;
	float heroUnk118;
	float heroUnk119;
	float heroUnk120;
	uint8_t heroUnk121;
	float heroUnk122;
	float heroUnk123;
	float heroUnk124;
	float heroUnk125;
	float heroUnk126;
	float heroUnk127;
	float heroUnk128;
	float heroUnk129;
	uint8_t heroUnk130;
	std::array<float, 16> heroUnk131;
	std::array<float, 2> heroUnk132;
	float heroUnk133;
	float heroUnk134;
	float heroUnk135;
	float heroUnk136;
	float heroUnk137;
	float heroUnk138;
	float heroUnk139;
	float heroUnk140;
	float heroUnk141;
	std::array<float, 5> heroUnk142;
	float heroUnk143;
	float heroUnk144;
	float heroUnk145;
	std::array<float, 16> heroUnk146;
	float heroUnk147;
	float heroUnk148;
	float heroUnk149;
	float heroUnk150;
	float heroUnk151;
	float heroUnk152;
	float heroUnk153;
	float heroUnk154;
	float heroUnk155;
	float heroUnk156;
	float heroUnk157;
	float heroUnk158;
	float heroUnk159;
	float heroUnk160;
	float heroUnk161;
	float heroUnk162;
	float heroUnk163;
	float heroUnk164;
	float heroUnk165;
	float heroUnk166;
	float heroUnk167;
	float heroUnk168;
	float heroUnk169;
	float heroUnk170;
	float heroUnk171;
	float heroUnk172;
	float heroUnk173;
	float heroUnk174;
	float heroUnk175;
	kobjref<CKObject> heroShadowCpnt;
	kobjref<CKObject> heroWaterFxHook;
	float heroUnk178;
	void reflectMembers(MemberListener &r);
};
struct CKHkAsterix : CKMRSubclass<CKHkAsterix, CKHkHero, 28> {
	float asteUnk0;
	float asteUnk1;
	float asteUnk2;
	float asteUnk3;
	float asteUnk4;
	float asteUnk5;
	float asteUnk6;
	float asteUnk7;
	float asteUnk8;
	float asteUnk9;
	float asteUnk10;
	float asteUnk11;
	float asteUnk12;
	float asteUnk13;
	float asteUnk14;
	float asteUnk15;
	float asteUnk16;
	float asteUnk17;
	float asteUnk18;
	float asteUnk19;
	float asteUnk20;
	float asteUnk21;
	float asteUnk22;
	float asteUnk23;
	float asteUnk24;
	kobjref<CKObject> asteDynSphere1;
	kobjref<CKObject> asteDynSphere2;
	kobjref<CKObject> asteBranch1;
	kobjref<CKObject> asteBranch2;
	float asteUnk29;
	float asteUnk30;
	kobjref<CKObject> asteSphere1;
	kobjref<CKObject> asteSphere2;
	kobjref<CKObject> asteBranch3;
	kobjref<CKObject> asteBranch4;
	kobjref<CKObject> asteParticleNode0;
	kobjref<CKObject> asteParticleNode1;
	kobjref<CKObject> asteParticleNode2;
	kobjref<CKObject> asteParticleNode3;
	kobjref<CKObject> asteParticleNode4;
	kobjref<CKObject> asteParticleNode5;
	kobjref<CKObject> asteParticleNode6;
	kobjref<CKObject> asteParticleNode7;
	kobjref<CKObject> asteParticleNode8;
	kobjref<CKObject> asteParticleNode9;
	kobjref<CKObject> asteParticleNode10;
	kobjref<CKObject> asteParticleNode11;
	kobjref<CKObject> asteParticleNode12;
	kobjref<CKObject> asteParticleNode13;
	kobjref<CKObject> asteParticleNode14;
	kobjref<CKObject> asteParticleNode15;
	kobjref<CKObject> asteParticleNode16;
	kobjref<CKObject> asteBranch5;
	kobjref<CKObject> asteBranch6;
	void reflectMembers(MemberListener &r);
};
struct CKHkObelix : CKMRSubclass<CKHkObelix, CKHkHero, 29> {
	float obeUnk0;
	kobjref<CKObject> obeDynSphere1;
	kobjref<CKObject> obeDynSphere2;
	kobjref<CKObject> obeBranchA1;
	kobjref<CKObject> obeBranchA2;
	float obeUnk5;
	float obeUnk6;
	float obeUnk7;
	kobjref<CKObject> obeSphere1;
	kobjref<CKObject> obeSphere2;
	kobjref<CKObject> obeBranchB1;
	kobjref<CKObject> obeBranchB2;
	kobjref<CKObject> obeParticleNode0;
	kobjref<CKObject> obeParticleNode1;
	kobjref<CKObject> obeParticleNode2;
	kobjref<CKObject> obeParticleNode3;
	kobjref<CKObject> obeParticleNode4;
	kobjref<CKObject> obeParticleNode5;
	kobjref<CKObject> obeParticleNode6;
	kobjref<CKObject> obeParticleNode7;
	kobjref<CKObject> obeParticleNode8;
	kobjref<CKObject> obeParticleNode9;
	kobjref<CKObject> obeParticleNode10;
	kobjref<CKObject> obeParticleNode11;
	kobjref<CKObject> obeParticleNode12;
	kobjref<CKObject> obeParticleNode13;
	kobjref<CKObject> obeParticleNode14;
	kobjref<CKObject> obeParticleNode15;
	kobjref<CKObject> obeParticleNode16;
	kobjref<CKObject> obeParticleNode17;
	kobjref<CKObject> obeBranchE1;
	kobjref<CKObject> obeBranchE2;
	kobjref<CKObject> obeBranchE3;
	kobjref<CKObject> obeBranchE4;
	kobjref<CKObject> obeBranchE5;
	kobjref<CKObject> obeBranchE6;
	void reflectMembers(MemberListener &r);
};
struct CKHkIdefix : CKMRSubclass<CKHkIdefix, CKHkHero, 30> {
	float ideUnk0;
	kobjref<CKObject> ideSphere;
	kobjref<CKObject> ideBranch;
	float ideUnk3;
	float ideUnk4;
	float ideUnk5;
	float ideUnk6;
	uint8_t ideUnk7;
	kobjref<CKObject> ideParticleNode1;
	kobjref<CKObject> ideParticleNode2;
	void reflectMembers(MemberListener &r);
};

struct CKHkMachinegun : CKMRSubclass<CKHkMachinegun, CKHook, 31> {
	float mgunUnk0;
	float mgunUnk1;
	kobjref<CKObject> mgunSpline;
	float mgunUnk3;
	float mgunUnk4;
	Vector3 mgunUnk5;
	float mgunUnk6;
	float mgunUnk7;
	float mgunUnk8;
	float mgunUnk9;
	float mgunUnk10;
	float mgunUnk11;
	float mgunUnk12;
	uint8_t mgunUnk13;
	uint8_t mgunUnk14;
	float mgunUnk15;
	float mgunUnk16;
	float mgunUnk17;
	float mgunUnk18;
	float mgunUnk19;
	float mgunUnk20;
	float mgunUnk21;
	kobjref<CKObject> mgunAnimDict;
	kobjref<CKObject> mgunSndDict;
	kobjref<CKObject> mgunAnimNode;
	kobjref<CKObject> mgunNode;
	Vector3 mgunUnk26;
	kobjref<CKObject> mgunParticles1;
	kobjref<CKObject> mgunParticles2;
	kobjref<CKObject> mgunParticles3;
	float mgunUnk30;
	float mgunUnk31;
	float mgunUnk32;
	float mgunUnk33;
	std::array<kobjref<CKObject>, 4> mgunClones;
	Vector3 mgunUnk35;
	float mgunUnk36;
	float mgunUnk37;
	float mgunUnk38;
	float mgunUnk39;
	float mgunUnk40;
	kobjref<CKObject> mgunBranch1;
	kobjref<CKObject> mgunBranch2;
	kobjref<CKObject> mgunBranch3;
	kobjref<CKObject> mgunBranch4;
	uint8_t mgunUnk45;
	uint16_t mgunUnk46;
	uint16_t mgunUnk47;
	KPostponedRef<CKObject> mgunDynGround1;
	KPostponedRef<CKObject> mgunDynGround2;
	kobjref<CKObject> mgunProjectile;
	Vector3 mgunUnk51;
	Vector3 mgunUnk52;
	kobjref<CKObject> mgunShadowCpnt;
	float mgunUnk54;
	uint8_t mgunUnk55;
	void reflectMembers(MemberListener &r);
};


struct CKHkTorch : CKMRSubclass<CKHkTorch, CKHook, 32> {
	kobjref<CKObject> torchSndDict;
	kobjref<CKObject> torchBranch;
	float torchUnk2;
	float torchUnk3;
	float torchUnk4;
	float torchUnk5;
	float torchUnk6;
	uint8_t torchUnk7;
	std::array<float, 16> torchUnk8;
	EventNode torchEvtSeq1;
	EventNode torchEvtSeq2;
	EventNode torchEvtSeq3;
	void reflectMembers(MemberListener &r);
};
struct CKHkHearth : CKMRSubclass<CKHkHearth, CKHook, 33> {
	kobjref<CKObject> hearthSndDict;
	KPostponedRef<CKObject> hearthDynGround;
	EventNode hearthEvtSeq1;
	EventNode hearthEvtSeq2;
	EventNode hearthEvtSeq3;
	EventNode hearthEvtSeq4;
	EventNode hearthEvtSeq5;
	float hearthUnk7;
	float hearthUnk8;
	float hearthUnk9;
	float hearthUnk10;
	float hearthUnk11;
	float hearthUnk12;
	float hearthUnk13;
	float hearthUnk14;
	void reflectMembers(MemberListener &r);
};
struct CKHkDrawbridge : CKMRSubclass<CKHkDrawbridge, CKHook, 34> {
	KPostponedRef<CKObject> dbStaticGround;
	KPostponedRef<CKObject> dbDynGround;
	kobjref<CKObject> dbSndDict;
	EventNode dbEvtSeq;
	float dbUnk4;
	float dbUnk5;
	float dbUnk6;
	float dbUnk7;
	float dbUnk8;
	void reflectMembers(MemberListener &r);
};
struct CKHkMegaAshtray : CKMRSubclass<CKHkMegaAshtray, CKHook, 37> {
	kobjref<CKObject> maAnimDict;
	kobjref<CKObject> maSndDict;
	KPostponedRef<CKObject> maDynGround1;
	KPostponedRef<CKObject> maDynGround2;
	float maUnk4;
	float maUnk5;
	void reflectMembers(MemberListener &r);
};
struct CKHkCorkscrew : CKMRSubclass<CKHkCorkscrew, CKHook, 44> {
	KPostponedRef<CKObject> cswDynGround;
	kobjref<CKObject> cswSndDict;
	uint32_t cswUnk2;
	EventNode cswUnk3;
	EventNode cswUnk4;
	float cswUnk5;
	float cswUnk6;
	float cswUnk7;
	float cswUnk8;
	float cswUnk9;
	float cswUnk10;
	float cswUnk11;
	void reflectMembers(MemberListener &r);
};
struct CKHkTurnstile : CKMRSubclass<CKHkTurnstile, CKHook, 45> {
	KPostponedRef<CKObject> tsDynGround;
	kobjref<CKObject> tsSndDict;
	kobjref<CKObject> tsCylinder;
	EventNode tsUnk3;
	EventNode tsUnk4;
	EventNode tsUnk5;
	float tsUnk6;
	float tsUnk7;
	float tsUnk8;
	void reflectMembers(MemberListener &r);
};
struct CKHkLifter : CKMRSubclass<CKHkLifter, CKHook, 47> {
	kobjref<CKObject> liftSquad;
	KPostponedRef<CKObject> liftDynGround;
	KPostponedRef<CKObject> liftStaticGround;
	KPostponedRef<CKObject> liftNode1;
	KPostponedRef<CKObject> liftNode2;
	kobjref<CKObject> liftSndDict;
	float liftUnk6;
	float liftUnk7;
	float liftUnk8;
	float liftUnk9;
	float liftUnk10;
	std::array<float, 6> liftUnk11;
	EventNode liftUnk12;
	EventNode liftUnk13;
	EventNode liftUnk14;
	EventNode liftUnk15;
	EventNode liftUnk16;
	EventNode liftUnk17;
	void reflectMembers(MemberListener &r);
};

struct CKHkActivator : CKMRSubclass<CKHkActivator, CKHook, 52> {
	kobjref<CAnimationDictionary> actAnimDict;
	kobjref<CKSoundDictionaryID> actSndDict;
	kobjref<CKBoundingShape> actSphere1;
	kobjref<CKBoundingShape> actSphere2;
	float actUnk4;
	EventNode actEvtSeq1;
	EventNode actEvtSeq2;

	//void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	//void serialize(KEnvironment* kenv, File *file) override;
	void reflectMembers(MemberListener &r);
};

struct CKHkRotaryBeam : CKMRSubclass<CKHkRotaryBeam, CKHook, 57> {
	kobjref<CKObject> rbAnimDict;
	kobjref<CKObject> rbSndDict;
	uint16_t rbUnk2;
	uint16_t rbUnk3;
	float rbUnk4;
	float rbUnk5;
	float rbUnk6;
	float rbUnk7;
	float rbUnk8;
	float rbUnk9;
	float rbUnk10;
	float rbUnk11;
	float rbUnk12;
	void reflectMembers(MemberListener &r);
};
struct CKHkLightPillar : CKMRSubclass<CKHkLightPillar, CKHook, 60> {
	void reflectMembers(MemberListener &r);
};
struct CKHkWind : CKMRSubclass<CKHkWind, CKHook, 73> {
	kobjref<CKObject> windSndDict;
	std::array<KPostponedRef<CKObject>, 2> windFogBoxes;
	float windUnk2;
	float windUnk3;
	float windUnk4;
	float windUnk5;
	Vector3 windUnk6;
	EventNode windUnk7;
	EventNode windUnk8;
	void reflectMembers(MemberListener &r);
};
struct CKHkPowderKeg : CKMRSubclass<CKHkPowderKeg, CKHook, 77> {
	KPostponedRef<CKObject> pkGround;
	kobjref<CKObject> pkCylinder;
	kobjref<CKObject> pkSndDict;
	kobjref<CKObject> pkUnk3;
	EventNode pkUnk4;
	EventNode pkUnk5;
	float pkUnk6;
	float pkUnk7;
	float pkUnk8;
	float pkUnk9;
	void reflectMembers(MemberListener &r);
};

struct CKHkEnemy : CKSubclass<CKHook, 80> {
	uint32_t unk1;
	Vector3 unk2;
	float unk3;
	uint8_t unk4, unk5;
	kobjref<CKObject> squad;
	Vector3 unk7;
	float unk8;
	kobjref<CKObject> unk9;
	kobjref<CKObject> unkA;
	kobjref<CKObject> shadowCpnt;
	kobjref<CKObject> hkWaterFx;

	void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	void serialize(KEnvironment* kenv, File *file) override;
};

struct CKHkSeizableEnemy : CKSubclass<CKHkEnemy, 84> {
	uint32_t sunk1;
	uint8_t sunk2, sunk3, sunk4;
	std::array<kobjref<CKBoundingShape>, 4> boundingShapes;
	kobjref<CKSceneNode> particlesNodeFx1, particlesNodeFx2, particlesNodeFx3;
	kobjref<CKSceneNode> fogBoxNode;
	uint32_t sunused;
	kobjref<CKHook> hero;
	kobjref<CKSceneNode> romanAnimatedClone;
	uint8_t sunk5;
	std::array<float, 7> sunk6;

	void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	void serialize(KEnvironment* kenv, File *file) override;
};

struct CKHkSquadSeizableEnemy : CKSubclass<CKHkSeizableEnemy, 92> {
	std::array<float, 9> matrix33;
	uint32_t sunk7;

	void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	void serialize(KEnvironment* kenv, File *file) override;
};

struct CKHkBasicEnemy : CKSubclass<CKHkSquadSeizableEnemy, 93> {
	kobjref<CKSceneNode> beClone1, beClone2, beClone3, beClone4;
	kobjref<CKSceneNode> beParticleNode1, beParticleNode2, beParticleNode3, beParticleNode4;
	kobjref<CAnimationDictionary> beAnimDict;
	kobjref<CKObject> beSoundDict;
	kobjref<CKBoundingShape> beBoundNode;

	kobjref<CAnimatedClone> romanAnimatedClone2;
	uint8_t beUnk1;
	std::array<float, 7> beUnk2;
	kobjref<CAnimatedClone> romanAnimatedClone3;
	uint8_t beUnk3;
	std::array<float, 7> beUnk4;
	float beUnk5, beUnk6;

	void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	void serialize(KEnvironment* kenv, File *file) override;
};

struct CKHkAnimatedCharacter : CKSubclass<CKHook, 97> {
	kobjref<CAnimationDictionary> animDict;
	kobjref<CKObject> shadowCpnt;
	kobjref<CKObject> unkRef1;
	Matrix matrix;
	Vector3 position;
	Vector3 orientation;
	std::array<float, 7> unkFloatArray;
	float unkFloat1, unkFloat2, unkFloat3, unkFloat4;
	uint8_t sector;

	void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	void serialize(KEnvironment* kenv, File *file) override;
};

struct CKHkSwingDoor : CKMRSubclass<CKHkSwingDoor, CKHook, 98> {
	kobjref<CKObject> swdSndDict;
	EventNode swdEvtSeq1;
	EventNode swdEvtSeq2;
	float swdUnk3;
	float swdUnk4;
	uint8_t swdUnk5;
	uint8_t swdUnk6;
	uint8_t swdUnk7;
	KPostponedRef<CKObject> swdNode1;
	KPostponedRef<CKObject> swdNode2;
	void reflectMembers(MemberListener &r);
};
struct CKHkSlideDoor : CKMRSubclass<CKHkSlideDoor, CKHook, 100> {
	kobjref<CKObject> sldSndDict;
	EventNode sldEvtSeq1;
	EventNode sldEvtSeq2;
	float sldUnk3;
	float sldUnk4;
	uint8_t sldUnk5;
	uint8_t sldUnk6;
	uint8_t sldUnk7;
	KPostponedRef<CKObject> sldNode;
	KPostponedRef<CKObject> sldDynGround;
	Vector3 sldUnk10;
	Vector3 sldUnk11;
	void reflectMembers(MemberListener &r);
};
struct CKHkCrumblyZone : CKMRSubclass<CKHkCrumblyZone, CKHook, 102> {
	kobjref<CKObject> czSndDict;
	KPostponedRef<CKObject> czGround;
	kobjref<CKObject> czNode1;
	kobjref<CKObject> czNode2;
	kobjref<CKObject> czObb;
	kobjref<CKObject> czProjectileScrap;
	kobjref<CKObject> czParticleNode;
	float czUnk7;
	std::array<float, 2> czUnk8;
	uint16_t czEvtSeqMaybe;
	EventNode czEvtSeq2;
	void reflectMembers(MemberListener &r);
};
struct CKHkHelmetCage : CKMRSubclass<CKHkHelmetCage, CKHook, 108> {
	kobjref<CKObject> hcNode1;
	kobjref<CKObject> hcClone1;
	kobjref<CKObject> hcClone2;
	KPostponedRef<CKObject> hcDynGround1;
	KPostponedRef<CKObject> hcDynGround2;
	kobjref<CKObject> hcSndDict;
	float hcUnk6;
	float hcUnk7;
	float hcUnk8;
	float hcUnk9;
	float hcUnk10;
	float hcUnk11;
	float hcUnk12;
	float hcUnk13;
	float hcUnk14;
	float hcUnk15;
	kobjref<CKObject> hcObb1;
	kobjref<CKObject> hcObb2;
	void reflectMembers(MemberListener &r);
};
struct CKHkTeleBridge : CKMRSubclass<CKHkTeleBridge, CKHook, 111> {
	struct Part {
		kobjref<CKObject> mClone1;
		KPostponedRef<CKObject> mDynGround;
		kobjref<CKObject> mClone2;
		kobjref<CKObject> mClone3;
		void reflectMembers(MemberListener &r);
	};
	KPostponedRef<CKObject> tbStaticGround;
	kobjref<CKObject> tbSndDict;
	float tbUnk2;
	float tbUnk3;
	float tbUnk4;
	float tbUnk5;
	float tbUnk6;
	float tbUnk7;
	float tbUnk8;
	float tbUnk9;
	EventNode tbUnk10;
	EventNode tbUnk11;
	std::array<Part, 6> tbParts;
	void reflectMembers(MemberListener &r);
};
struct CKHkBasicBonus : CKSubclass<CKHook, 114> {
	kobjref<CKHkBasicBonus> nextBonus;
	kobjref<CKGrpBonusPool> pool;
	kobjref<CKObject> cpnt;
	kobjref<CKObject> hero;
	std::array<float, 7> somenums;

	void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	void serialize(KEnvironment* kenv, File *file) override;
};

struct CKHkRollingStone : CKMRSubclass<CKHkRollingStone, CKHook, 126> {
	kobjref<CKFlaggedPath> rlstPath;
	kobjref<CKObject> rlstSphere;
	kobjref<CKObject> rlstProjScrap;
	kobjref<CKObject> rlstSndDict;
	kobjref<CKObject> rlstClone;
	float rlstUnk5;
	float rlstUnk6;
	float rlstUnk7;
	float rlstUnk8;
	float rlstUnk9;
	float rlstUnk10;
	float rlstUnk11;
	float rlstUnk12;
	float rlstUnk13;
	EventNode rlstUnk14;
	void reflectMembers(MemberListener &r);
	void onLevelLoaded(KEnvironment *kenv) override;
};

struct CKHkPushPullAsterix : CKMRSubclass<CKHkPushPullAsterix, CKHook, 147> {
	struct Special {
		float mUnk0;
		float mUnk1;
		float mUnk2;
		float mUnk3;
		float mUnk4;
		float mUnk5;
		float mUnk6;
		kobjref<CKObject> mSndDict;
		void reflectMembers(MemberListener &r);
	};
	uint16_t ppaUnk0;
	Vector3 ppaUnk1;
	Vector3 ppaUnk2;
	Vector3 ppaUnk3;
	Vector3 ppaUnk4;
	float ppaUnk5;
	float ppaUnk6;
	float ppaUnk7;
	float ppaUnk8;
	float ppaUnk9;
	float ppaUnk10;
	float ppaUnk11;
	float ppaUnk12;
	kobjref<CKObject> ppaFlaggedPath;
	kobjref<CKObject> ppaLine;
	float ppaUnk15;
	float ppaUnk16;
	float ppaUnk17;
	float ppaUnk18;
	float ppaUnk19;
	float ppaUnk20;
	float ppaUnk21;
	kobjref<CKObject> ppaObb;
	float ppaUnk23;
	float ppaUnk24;
	float ppaUnk25;
	Special ppaUnk26;
	kobjref<CKObject> ppaParticleNode1;
	kobjref<CKObject> ppaParticleNode2;
	float ppaUnk29;
	kobjref<CKObject> ppaSndDict;
	KPostponedRef<CKObject> ppaDynGround;
	EventNode ppaUnk32;
	EventNode ppaUnk33;
	EventNode ppaUnk34;
	EventNode ppaUnk35;
	Vector3 ppaUnk36;
	float ppaUnk37;
	float ppaUnk38;
	kobjref<CKObject> ppaBranch1;
	kobjref<CKObject> ppaBranch2;
	kobjref<CKObject> ppaBranch3;
	kobjref<CKObject> ppaBranch4;
	uint32_t ppaUnk43;
	uint32_t ppaUnk44;
	void reflectMembers(MemberListener &r);
	void onLevelLoaded(KEnvironment *kenv) override;
};
struct CKHkTelepher : CKMRSubclass<CKHkTelepher, CKHook, 158> {
	kobjref<CKObject> telUnk0;
	float telUnk1;
	kobjref<CKObject> telUnk2;
	kobjref<CKObject> telUnk3;
	kobjref<CKObject> telFlaggedPath;
	KPostponedRef<CKObject> telDynGround;
	uint32_t telUnk6;
	float telUnk7;
	float telUnk8;
	float telUnk9;
	float telUnk10;
	float telUnk11;
	float telUnk12;
	float telUnk13;
	float telUnk14;
	float telUnk15;
	float telUnk16;
	float telUnk17;
	float telUnk18;
	float telUnk19;
	float telUnk20;
	EventNode telUnk21;
	kobjref<CKObject> telSndDict;
	void reflectMembers(MemberListener &r);
};
struct CKHkTowedTelepher : CKMRSubclass<CKHkTowedTelepher, CKHkTelepher, 159> {
	kobjref<CKObject> towtelTowNode1;
	kobjref<CKObject> towtelTowNode2;
	kobjref<CKObject> towtelParticleNode;
	float towtelUnk3;
	float towtelUnk4;
	float towtelUnk5;
	float towtelUnk6;
	float towtelUnk7;
	float towtelUnk8;
	float towtelUnk9;
	float towtelUnk10;
	float towtelUnk11;
	kobjref<CKObject> towtelSphere;
	Matrix towtelUnk13;
	EventNode towtelUnk14;
	EventNode towtelUnk15;
	void reflectMembers(MemberListener &r);
};
struct CKHkBumper : CKMRSubclass<CKHkBumper, CKHook, 160> {
	kobjref<CKObject> bmpBranch;
	kobjref<CKObject> bmpAnimnode;
	kobjref<CKObject> bmpAnimDict;
	kobjref<CKObject> bmpSndDict;
	kobjref<CKObject> bmpObb;
	KPostponedRef<CKObject> bmpGround;
	uint16_t bmpUnk6;
	uint32_t bmpUnk7;
	uint32_t bmpUnk8;
	uint32_t bmpUnk9;
	uint8_t bmpUnk10;
	void reflectMembers(MemberListener &r);
};

struct CKHkClueMan : CKMRSubclass<CKHkClueMan, CKHook, 161> {
	struct Ing {
		uint8_t mUnk0;
		kobjref<CKObject> mCamera;
		float mUnk2;
		float mUnk3;
		void reflectMembers(MemberListener &r);
	};
	uint8_t cmUnk0;
	uint8_t cmUnk1;
	float cmUnk2;
	float cmUnk3;
	float cmUnk4;
	float cmUnk5;
	float cmUnk6;
	float cmUnk7;
	// uint16_t sizeFor_cmBings;
	std::vector<Ing> cmBings;
	// uint16_t sizeFor_cmDings;
	std::vector<Ing> cmDings;
	// uint16_t sizeFor_cmFings;
	std::vector<Ing> cmFings;
	float cmUnk14;
	float cmUnk15;
	float cmUnk16;
	float cmUnk17;
	float cmUnk18;
	EventNode cmUnk19;
	EventNode cmUnk20;
	EventNode cmUnk21;
	EventNode cmUnk22;
	EventNode cmUnk23;
	uint8_t cmUnk24;
	uint8_t cmUnk25;
	uint8_t cmUnk26;
	uint8_t cmUnk27;
	uint8_t cmUnk28;
	uint8_t cmUnk29;
	uint8_t cmUnk30;
	kobjref<CKObject> cmUnk31;
	kobjref<CKObject> cmUnk32;
	kobjref<CKObject> cmUnk33;
	kobjref<CKObject> cmUnk34;
	kobjref<CKObject> cmUnk35;
	kobjref<CKObject> cmUnk36;
	uint8_t cmUnk37;
	kobjref<CKObject> cmBillboard1;
	kobjref<CKObject> cmBillboard2;
	Vector3 cmUnk40;
	float cmUnk41;
	float cmUnk42;
	float cmUnk43;
	float cmUnk44;
	Vector3 cmUnk45;
	float cmUnk46;
	float cmUnk47;
	float cmUnk48;
	float cmUnk49;
	float cmUnk50;
	float cmUnk51;
	float cmUnk52;
	float cmUnk53;
	float cmUnk54;
	float cmUnk55;
	float cmUnk56;
	float cmUnk57;
	float cmUnk58;
	Vector3 cmUnk59;
	float cmUnk60;
	void reflectMembers(MemberListener &r);
};
struct CKHkSky : CKMRSubclass<CKHkSky, CKHook, 163> {
	void reflectMembers(MemberListener &r);
};

struct CKHkRocketRoman : CKSubclass<CKHkBasicEnemy, 164> {
	kobjref<CKObject> rrAnimDict, rrParticleNode, rrCylinderNode, rrSoundDictID;

	void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	void serialize(KEnvironment* kenv, File *file) override;
};

struct CKHkWildBoar : CKSubclass<CKHook, 171> {
	kobjref<CKHkWildBoar> nextBoar;
	kobjref<CKSceneNode> boundingSphere;
	kobjref<CKObject> animationDictionary;
	kobjref<CKObject> cpnt;
	kobjref<CKGrpWildBoarPool> pool;
	std::array<float, 4> somenums;
	kobjref<CKObject> shadowCpnt;

	void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	void serialize(KEnvironment* kenv, File *file) override;
};

struct CKHkAsterixShop : CKMRSubclass<CKHkAsterixShop, CKHook, 172> {
	kobjref<CKObject> shopAnimNode2;
	kobjref<CKObject> shopAnimDict1;
	kobjref<CKObject> shopAnimDict2;
	kobjref<CKObject> shopSndDict;
	kobjref<CKObject> shopBillboardList;
	kobjref<CKObject> shopText1;
	kobjref<CKObject> shopText2;
	kobjref<CKObject> shopText3;
	kobjref<CKObject> shopText4;
	kobjref<CKObject> shopBillboard1;
	kobjref<CKObject> shopBillboard2;
	std::array<float, 8> shopUnk11;
	std::array<uint32_t, 2> shopUnk12;
	uint32_t shopUnk13;
	std::array<uint32_t, 6> shopUnk14;
	std::array<uint32_t, 14> shopUnk15;
	std::array<uint32_t, 10> shopUnk16;
	std::array<uint32_t, 12> shopUnk17;
	std::array<uint8_t, 3> shopUnk18;
	kobjref<CKObject> shopCameraTrack;
	Vector3 shopUnk20;
	Vector3 shopUnk21;
	float shopUnk22;
	float shopUnk23;
	float shopUnk24;
	kobjref<CKObject> shopDynGround;
	Vector3 shopUnk26;
	Vector3 shopUnk27;
	float shopUnk28;
	float shopUnk29;
	float shopUnk30;
	float shopUnk31;
	void reflectMembers(MemberListener &r);
};
struct CKHkWaterFall : CKMRSubclass<CKHkWaterFall, CKHook, 185> {
	kobjref<CKObject> wfallBranch2;
	float wfallUnk1;
	float wfallUnk2;
	void reflectMembers(MemberListener &r);
};
struct CKHkAsterixCheckpoint : CKMRSubclass<CKHkAsterixCheckpoint, CKHook, 193> {
	kobjref<CKObject> acpNode;
	kobjref<CKObject> acpAnimDict;
	kobjref<CKObject> acpSndDict;
	kobjref<CKObject> acpSphere1;
	kobjref<CKObject> acpSphere2;
	kobjref<CKObject> acpSphere3;
	kobjref<CKObject> acpParticleNode1;
	kobjref<CKObject> acpParticleNode2;
	kobjref<CKObject> acpGrpCheckpoint;
	Vector3 acpUnk9;
	void reflectMembers(MemberListener &r);
};
struct CKHkBonusSpitter : CKMRSubclass<CKHkBonusSpitter, CKHook, 194> {
	KPostponedRef<CKObject> bsDynGround;
	KPostponedRef<CKObject> bsNode;
	float bsUnk2;
	float bsUnk3;
	float bsUnk4;
	uint32_t bsBonusType;
	void reflectMembers(MemberListener &r);
};
struct CKHkLight : CKMRSubclass<CKHkLight, CKHook, 195> {
	kobjref<CKObject> lightGrpLight;
	EventNode lightEvtSeq1;
	EventNode lightEvtSeq2;
	EventNode lightEvtSeq3;
	EventNode lightEvtSeq4;
	void reflectMembers(MemberListener &r);
};

// Unknown hook classes. To implement later!
//struct CKHkPressionStone : CKPartlyUnknown<CKHook, 21> {};
//struct CKHkAsterix : CKPartlyUnknown<CKHook, 28> {};
//struct CKHkObelix : CKPartlyUnknown<CKHook, 29> {};
//struct CKHkIdefix : CKPartlyUnknown<CKHook, 30> {};
//struct CKHkMachinegun : CKPartlyUnknown<CKHook, 31> {};
//struct CKHkTorch : CKPartlyUnknown<CKHook, 32> {};
//struct CKHkHearth : CKPartlyUnknown<CKHook, 33> {};
//struct CKHkDrawbridge : CKPartlyUnknown<CKHook, 34> {};
//struct CKHkMegaAshtray : CKPartlyUnknown<CKHook, 37> {};
struct CKHkBoat : CKPartlyUnknown<CKHook, 39> {};
//struct CKHkCorkscrew : CKPartlyUnknown<CKHook, 44> {};
//struct CKHkTurnstile : CKPartlyUnknown<CKHook, 45> {};
//struct CKHkLifter : CKPartlyUnknown<CKHook, 47> {};
//struct CKHkActivator : CKPartlyUnknown<CKHook, 52> {};
//struct CKHkRotaryBeam : CKPartlyUnknown<CKHook, 57> {};
//struct CKHkLightPillar : CKPartlyUnknown<CKHook, 60> {};
//struct CKHkWind : CKPartlyUnknown<CKHook, 73> {};
struct CKHkJumpingRoman : CKPartlyUnknown<CKHkSquadSeizableEnemy, 75> {};
struct CKHkWaterJet : CKPartlyUnknown<CKHook, 76> {};
//struct CKHkPowderKeg : CKPartlyUnknown<CKHook, 77> {};
struct CKHkTriangularTurtle : CKPartlyUnknown<CKHkEnemy, 90> {};
struct CKHkRomanArcher : CKPartlyUnknown<CKHkSquadSeizableEnemy, 95> {};
//struct CKHkAnimatedCharacter : CKPartlyUnknown<CKHook, 97> {}; ////////
//struct CKHkSwingDoor : CKPartlyUnknown<CKHook, 98> {};
//struct CKHkSlideDoor : CKPartlyUnknown<CKHook, 100> {};
//struct CKHkCrumblyZone : CKPartlyUnknown<CKHook, 102> {};
//struct CKHkHelmetCage : CKPartlyUnknown<CKHook, 108> {};
struct CKHkSquareTurtle : CKPartlyUnknown<CKHkEnemy, 110> {};
//struct CKHkTeleBridge : CKPartlyUnknown<CKHook, 111> {};
struct CKHkCrate : CKPartlyUnknown<CKHook, 112> {};
struct CKHkDonutTurtle : CKPartlyUnknown<CKHkEnemy, 124> {};
struct CKHkPyramidalTurtle : CKPartlyUnknown<CKHkEnemy, 125> {};
//struct CKHkRollingStone : CKPartlyUnknown<CKHook, 126> {};
struct CKHkInterfaceBase : CKPartlyUnknown<CKHook, 128> {};
struct CKHkInterfaceEvolution : CKPartlyUnknown<CKHook, 129> {};
struct CKHkCatapult : CKPartlyUnknown<CKHook, 130> {};
struct CKHkInterfacePause : CKPartlyUnknown<CKHook, 131> {};
struct CKHkInterfaceInGame : CKPartlyUnknown<CKHook, 132> {};
struct CKHkInterfaceOption : CKPartlyUnknown<CKHook, 133> {};
struct CKHkInterfaceMain : CKPartlyUnknown<CKHook, 136> {};
struct CKHkInterfaceLoadSave : CKPartlyUnknown<CKHook, 138> {};
struct CKHkInterfaceCloth : CKPartlyUnknown<CKHook, 141> {};
struct CKHkInterfaceShop : CKPartlyUnknown<CKHook, 144> {};
//struct CKHkPushPullAsterix : CKPartlyUnknown<CKHook, 147> {};
struct CKHkBasicEnemyLeader : CKPartlyUnknown<CKHkBasicEnemy, 148> {};
//struct CKHkTelepher : CKPartlyUnknown<CKHook, 158> {};
//struct CKHkTowedTelepher : CKPartlyUnknown<CKHook, 159> {};
//struct CKHkBumper : CKPartlyUnknown<CKHook, 160> {};
//struct CKHkClueMan : CKPartlyUnknown<CKHook, 161> {};
//struct CKHkSky : CKPartlyUnknown<CKHook, 163> {};
struct CKHkJetPackRoman : CKPartlyUnknown<CKHkEnemy, 167> {};
//struct CKHkAsterixShop : CKPartlyUnknown<CKHook, 172> {};
struct CKHkWater : CKPartlyUnknown<CKHook, 173> {};
struct CKHkMobileTower : CKPartlyUnknown<CKHkEnemy, 176> {};
struct CKHkBoss : CKPartlyUnknown<CKHook, 177> {};
struct CKHkInterfaceDemo : CKPartlyUnknown<CKHook, 179> {};
struct CKHkWaterFx : CKPartlyUnknown<CKHook, 180> {};
struct CKHkHighGrass : CKPartlyUnknown<CKHook, 183> {};
//struct CKHkWaterFall : CKPartlyUnknown<CKHook, 185> {};
struct CKHkInterfaceGallery : CKPartlyUnknown<CKHook, 187> {};
struct CKHkTrioCatapult : CKPartlyUnknown<CKHook, 190> {};
struct CKHkObelixCatapult : CKPartlyUnknown<CKHook, 191> {};
struct CKHkInterfaceOpening : CKPartlyUnknown<CKHook, 192> {};
//struct CKHkAsterixCheckpoint : CKPartlyUnknown<CKHook, 193> {};
//struct CKHkBonusSpitter : CKPartlyUnknown<CKHook, 194> {};
//struct CKHkLight : CKPartlyUnknown<CKHook, 195> {};

///--- Hook life classes ---///

struct CKHkAsterixLife : CKSubclass<CKHookLife, 27> {};

struct CKHkBoatLife : CKSubclass<CKHookLife, 55> {
	kobjref<CKHook> boatHook;

	void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	void serialize(KEnvironment* kenv, File *file) override;
};

struct CKHkObelixLife : CKSubclass<CKHookLife, 57> {};
struct CKHkMecaLife : CKSubclass<CKHookLife, 59> {};
struct CKHkIdefixLife : CKSubclass<CKHookLife, 66> {};
struct CKHkEnemyLife : CKSubclass<CKHookLife, 93> {};
struct CKHkTriangularLife : CKSubclass<CKHookLife, 95> {};

struct CKHkAnimatedCharacterLife : CKSubclass<CKHookLife, 99> {};
struct CKHkSquareTurtleLife : CKSubclass<CKHookLife, 102> {};
struct CKHkDonutTurtleLife : CKSubclass<CKHookLife, 104> {};
struct CKHkPyramidalTurtleLife : CKSubclass<CKHookLife, 105> {};
struct CKHkCatapultLife : CKSubclass<CKHookLife, 108> {};

struct CKHkSkyLife : CKSubclass<CKHookLife, 112> {
	uint32_t skyColor, cloudColor;

	void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	void serialize(KEnvironment* kenv, File *file) override;
};

struct CKHkWaterLife : CKSubclass<CKHookLife, 115> {};
struct CKHkBossLife : CKSubclass<CKHookLife, 118> {};
struct CKHkWaterFxLife : CKSubclass<CKHookLife, 120> {};
struct CKHkAsterixCheckpointLife : CKSubclass<CKHookLife, 124> {};
struct CKHkWaterFallLife : CKSubclass<CKHookLife, 125> {};
