#pragma once

namespace game
{
	enum scriptInstance_t
	{
		SCRIPTINSTANCE_SERVER,
		SCRIPTINSTANCE_CLIENT,
	};

	struct scr_entref_t
	{
		unsigned short entnum;
		unsigned short classnum;
		unsigned short client;
	};

	struct BuiltinMethodDef
	{
		const char* actionString;
		unsigned int constId;
		int min_args;
		int max_args;
		void(__cdecl* actionFunc)(scr_entref_t);
		int type;
	};

	struct BuiltinFunctionDef
	{
		const char* actionString;
		unsigned int constId;
		int min_args;
		int max_args;
		void(__cdecl* actionFunc)();
		int type;
	};

	struct VariableStackBuffer
	{
		char* pos;
		char* creationPos;
		int waitTime;
		unsigned __int16 size;
		unsigned __int16 bufLen;
		unsigned __int16 localId;
		char buf[1];
	};

	union VariableUnion
	{
		int intValue;
		unsigned int uintValue;
		float floatValue;
		unsigned int stringValue;
		const float* vectorValue;
		char* codePosValue;
		unsigned int pointerValue;
		VariableStackBuffer* stackValue;
		unsigned int entityOffset;
	};

	struct VariableValue
	{
		int type;
		VariableUnion u;
	};

	struct function_stack_t
	{
		char* pos;
		VariableValue* top;
		unsigned int localId;
		unsigned int localVarCount;
		VariableValue* startTop;
	};

	struct function_frame_t
	{
		function_stack_t fs;
		char* creationPos;
	};

	struct scrVmPub_t
	{
		unsigned int* localVars;
		VariableValue* maxstack;
		int function_count;
		function_frame_t* function_frame;
		VariableValue* top;
		bool debugCode;
		bool abort_on_error;
		bool terminal_error;
		bool block_execution;
		unsigned int inparamcount;
		unsigned int outparamcount;
		unsigned int breakpointOutparamcount;
		bool showError;
		function_frame_t function_frame_start[32];
		VariableValue stack[2048];
		void(__cdecl* notifyListeners[1])(unsigned int, unsigned int);
	};

#pragma pack(push, 1)
	struct usercmd_s
	{
		int serverTime;
		int button_bits[2];
		int angles[3];
		unsigned int weapon;
		unsigned int offHandWeapon;
		unsigned int lastWeaponAltModeSwitch;
		char forwardmove;
		char rightmove;
		char upmove;
		char pitchmove;
		char yawmove;
		char _0x29[0x13];
	};
#pragma pack(pop)

	union hudelem_color_t
	{
		struct
		{
			char r;
			char g;
			char b;
			char a;
		} u;

		int rgba;
	};

	struct hudelem_s
	{
		float x;
		float y;
		float z;
		float fontScale;
		float fromFontScale;
		int fontScaleStartTime;
		hudelem_color_t color;
		hudelem_color_t fromColor;
		int fadeStartTime;
		int scaleStartTime;
		float fromX;
		float fromY;
		int moveStartTime;
		int time;
		int duration;
		float value;
		float sort;
		hudelem_color_t glowColor;
		int fxBirthTime;
		unsigned int flags;
		short targetEntNum;
		short fontScaleTime;
		short fadeTime;
		short label;
		short width;
		short height;
		short fromWidth;
		short fromHeight;
		short scaleTime;
		short moveTime;
		short text;
		unsigned short fxLetterTime;
		unsigned short fxDecayStartTime;
		unsigned short fxDecayDuration;
		unsigned short fxRedactDecayStartTime;
		unsigned short fxRedactDecayDuration;
		char type;
		char font;
		char alignOrg;
		char alignScreen;
		char materialIndex;
		char offscreenMaterialIdx;
		char fromAlignOrg;
		char fromAlignScreen;
		char soundID;
		char ui3dWindow;
	};

	struct playerState_s_hud
	{
		hudelem_s current[31];
		hudelem_s archival[31];
	};

	enum OffhandSecondaryClass
	{
		PLAYER_OFFHAND_SECONDARY_SMOKE = 0x0,
		PLAYER_OFFHAND_SECONDARY_FLASH = 0x1,
		PLAYER_OFFHAND_SECONDARIES_TOTAL = 0x2,
	};

	enum OffhandPrimaryClass
	{
		PLAYER_OFFHAND_PRIMARY_FRAG = 0x0,
		PLAYER_OFFHAND_PRIMARY_GEAR = 0x1,
		PLAYER_OFFHAND_PRIMARIES_TOTAL = 0x2,
	};

	enum ViewLockTypes
	{
		PLAYERVIEWLOCK_NONE = 0x0,
		PLAYERVIEWLOCK_FULL = 0x1,
		PLAYERVIEWLOCK_WEAPONJITTER = 0x2,
		PLAYERVIEWLOCKCOUNT = 0x3,
	};

	enum locSel_t
	{
		LOC_SEL_NONE = 0x0,
		LOC_SEL_ARTILLERY = 0x1,
		LOC_SEL_AIRSTRIKE = 0x2,
		LOC_SEL_MORTAR = 0x3,
		LOC_SEL_NAPALM = 0x4,
		LOC_SEL_COMLINK = 0x5,
	};

	struct PlayerVehicleState
	{
		float origin[3];
		float angles[3];
		float velocity[3];
		float angVelocity[3];
		float tilt[2];
		float tiltVelocity[2];
		float targetHeightDelta;
		float lastGroundHeight;
		int entity;
		int flags;
		bool fullPhysics;
	};

	struct renderOptions_s
	{
		unsigned int s;
	};

	struct PlayerHeldWeapon
	{
		unsigned int weapon;
		renderOptions_s options;
		float heatPercent;
		int fuelTankTime;
		int adsZoomSelect;
		bool overHeating;
		bool needsRechamber;
		bool heldBefore;
		bool quickReload;
		bool blockWeaponPickup;
		char model;
	};

	struct AmmoPool
	{
		int count;
	};

	struct AmmoClip
	{
		int count;
	};

	struct SprintState
	{
		int sprintButtonUpRequired;
		int sprintDelay;
		int lastSprintStart;
		int lastSprintEnd;
		int sprintStartMaxLength;
		int sprintDuration;
		int sprintCooldown;
	};

	struct MantleState
	{
		float yaw;
		int timer;
		int transIndex;
		int flags;
	};

	enum ActionSlotType
	{
		ACTIONSLOTTYPE_DONOTHING = 0x0,
		ACTIONSLOTTYPE_SPECIFYWEAPON = 0x1,
		ACTIONSLOTTYPE_ALTWEAPONTOGGLE = 0x2,
		ACTIONSLOTTYPE_NIGHTVISION = 0x3,
		ACTIONSLOTTYPECOUNT = 0x4,
	};

	struct ActionSlotParam_SpecifyWeapon
	{
		unsigned int weapon;
	};

	struct ActionSlotParam
	{
		ActionSlotParam_SpecifyWeapon specifyWeapon;
	};

	enum objectiveState_t
	{
		OBJST_EMPTY = 0x0,
		OBJST_ACTIVE = 0x1,
		OBJST_INVISIBLE = 0x2,
		OBJST_NUMSTATES = 0x3,
	};

	struct objective_t
	{
		objectiveState_t state;
		float origin[3];
		short entNum;
		float size[2];
		int icon;
		short ownerNum;
		unsigned short name;
		short teamMask;
		char progress;
		int clientUseMask[1];
		char gamemodeFlags;
		char flags;
		char teamNum;
	};

	struct playerState_s
	{
		int commandTime;
		int pm_type;
		int bobCycle;
		int pm_flags;
		__int64 weapFlags;
		int otherFlags;
		int pm_time;
		unsigned int loopSoundId;
		int loopSoundFade;
		float origin[3];
		float velocity[3];
		int remoteEyesEnt;
		int remoteEyesTagname;
		int remoteControlEnt;
		int weaponTime;
		int weaponDelay;
		int weaponTimeLeft;
		int weaponDelayLeft;
		int weaponIdleTime;
		int grenadeTimeLeft;
		int throwBackGrenadeOwner;
		int throwBackGrenadeTimeLeft;
		int weaponRestrictKickTime;
		bool mountAvailable;
		bool bRunLeftGun;
		bool bCarryingTurret;
		float mountPos[3];
		float mountDir;
		bool bThirdPerson;
		int foliageSoundTime;
		int gravity;
		float leanf;
		int speed;
		float delta_angles[3];
		int groundEntityNum;
		int moverEntityNum;
		int moverTimestamp;
		int groundType;
		float vLadderVec[3];
		int jumpTime;
		float jumpOriginZ;
		int slideTime;
		int moveType;
		int legsTimer;
		int torsoTimer;
		short legsAnim;
		short torsoAnim;
		int legsAnimDuration;
		int torsoAnimDuration;
		int damageTimer;
		int damageDuration;
		int dmgDirection;
		int dmgType;
		int corpseIndex;
		int movementDir;
		int eFlags;
		int eFlags2;
		PlayerVehicleState vehicleState;
		short predictableEventSequence;
		short predictableEventSequenceOld;
		int predictableEvents[4];
		unsigned int predictableEventParms[4];
		short unpredictableEventSequence;
		short unpredictableEventSequenceOld;
		int unpredictableEvents[4];
		unsigned int unpredictableEventParms[4];
		int clientNum;
		unsigned int offHandWeapon;
		OffhandSecondaryClass offhandSecondary;
		OffhandPrimaryClass offhandPrimary;
		renderOptions_s renderOptions;
		int momentum;
		unsigned int weapon;
		unsigned int lastStandPrevWeapon;
		unsigned int lastWeaponAltModeSwitch;
		unsigned int stowedWeapon;
		char unusedCompatibilityPadding;
		unsigned int meleeWeapon;
		int weaponstate;
		int weaponstateLeft;
		unsigned int weaponShotCount;
		unsigned int weaponShotCountLeft;
		float fWeaponPosFrac;
		int adsDelayTime;
		int spreadOverride;
		int spreadOverrideState;
		float weaponSpinLerp;
		int viewmodelIndex;
		float viewAngles[3];
		int viewHeightTarget;
		float viewHeightCurrent;
		int viewHeightLerpTime;
		int viewHeightLerpTarget;
		int viewHeightLerpDown;
		float viewAngleClampBase[2];
		float viewAngleClampRange[2];
		int damageEvent;
		int damageYaw;
		int damagePitch;
		int damageCount;
		int stats[4];
		PlayerHeldWeapon heldWeapons[15];
		AmmoPool ammoNotInClip[15];
		AmmoClip ammoInClip[15];
		float proneDirection;
		float proneDirectionPitch;
		float proneTorsoPitch;
		ViewLockTypes viewlocked;
		short viewlocked_entNum;
		int vehiclePos;
		int vehicleType;
		int vehicleAnimBoneIndex;
		int linkFlags;
		float linkAngles[3];
		int cursorHint;
		int cursorHintString;
		int cursorHintEntIndex;
		int cursorHintWeapon;
		int iCompassPlayerInfo;
		unsigned int spyplaneTypeEnabled;
		unsigned int satelliteTypeEnabled;
		int locationSelectionInfo;
		locSel_t locationSelectionType;
		SprintState sprintState;
		int lastDtpEnd;
		float fTorsoPitch;
		float fWaistPitch;
		float holdBreathScale;
		int holdBreathTimer;
		int chargeShotTimer;
		unsigned int chargeShotLevel;
		unsigned int shotsFiredFromChamber;
		float quickScopeScale;
		int quickScopeTimer;
		unsigned int clientFields;
		unsigned int clientFields2;
		unsigned int clientFields3;
		unsigned int entityStateClientFields;
		float moveSpeedScaleMultiplier;
		MantleState mantleState;
		int vehicleAnimStage;
		int vehicleEntryPoint;
		unsigned int scriptedAnim;
		int scriptedAnimTime;
		int meleeChargeEnt;
		int meleeChargeDist;
		int meleeChargeTime;
		int weapLockFlags;
		int weapLockedEntnum;
		unsigned int airburstMarkDistance;
		unsigned int perks[2];
		ActionSlotType actionSlotType[4];
		ActionSlotParam actionSlotParam[4];
		unsigned int inventoryWeapon;
		short wiiumoteAimX;
		short wiiumoteAimY;
		char wiiuControllerType;
		char vehicleDefIndex;
		int entityEventSequence;
		int weapAnim;
		int weapAnimLeft;
		float aimSpreadScale;
		int shellshockIndex;
		int shellshockTime;
		int shellshockDuration;
		float dofNearStart;
		float dofNearEnd;
		float dofFarStart;
		float dofFarEnd;
		float dofNearBlur;
		float dofFarBlur;
		float dofViewmodelStart;
		float dofViewmodelEnd;
		int waterlevel;
		int smokeColorIndex;
		int hudElemLastAssignedSoundID;
		int adsZoomSelect;
		int adsZoomLatchTime;
		bool adsZoomLatchState;
		int adsPrevZoomSelect;
		int adsPrevZoomSelectTime;
		int artilleryInboundIconLocation;
		float visionSetLerpRatio;
		int poisoned;
		int binoculars;
		int scriptCursorHintString;
		objective_t objective[32];
		int deltaTime;
		int killCamEntity;
		int killCamTargetEntity;
		int introShotsFired;
		playerState_s_hud hud;
	};

	enum sessionState_t
	{
		SESS_STATE_PLAYING = 0x0,
		SESS_STATE_DEAD = 0x1,
		SESS_STATE_SPECTATOR = 0x2,
		SESS_STATE_INTERMISSION = 0x3,
	};

	enum clientConnected_t
	{
		CON_DISCONNECTED = 0x0,
		CON_CONNECTING = 0x1,
		CON_CONNECTED = 0x2,
	};

	struct score_s
	{
		int ping; //0x0
		int status_icon; //0x4
		int place; //0x8
		int score; //0xC
		int kills; //0x10
		int assists; //0x14
		int deaths; //0x18
		int wagerWinnings; //0x1C
		int scoreboardColumns[5]; //0x20
		int downs; //0x34
		int revives; //0x38
		int headshots; //0x3C 
		int scoreMultiplier; //0x40
		int currentStreak; //0x44
	};

	struct clientState_s
	{
		int clientNum; //0x0
		int team; //0x4
		int oldTeam; //0x8
		char _0xC[0x38];
		char name[0x20]; //0x44
		char _0x64[0x4C];
		char clanAbbrev[8]; //0xB0
		char _0xB8[0x20];
		score_s scores; //0xD8
		int clientUIVisibilityFlags; //0x120
		int offhandWeaponVisible; //0x124
	};

	struct clientSession_t
	{
		sessionState_t sessionState; //0x00
		int forceSpectatorClient; //0x4
		int killCamEntity; //0x8
		int killCamTargetEntity; //0xC
		int archiveTime; //0x10
		unsigned __int16 scriptPersId; //0x14
		clientConnected_t connected; //0x18
		usercmd_s cmd; //0x1C
		usercmd_s oldcmd; //0x58
		int localClient; //0x94
		int predictItemPickup; //0x98
		char newnetname[32]; //0x9C
		int maxHealth; //0xBC
		int enterTime; //0xC0
		int location; //0xC4
		int voteCount; //0xC8
		int teamVoteCount; //0xCC
		float moveSpeedScaleMultiplier; //0xD0
		int viewmodelIndex; //0xD4
		int noSpectate; //0xD8
		int teamInfo; //0xDC
		clientState_s cs; //0xE0
		int psOffsetTime; //0x208
		int scoreboardColumnCache[26]; //0x20C
	};

	struct gclient_s
	{
		playerState_s ps; //0x0
		char _0x2A08[0x2A08];
		clientSession_t sess; //0x5410
		int flags; //0x5684
		char _0x5688[0x180];
		short prevLinkAnglesSet; //0x56F8
		char link_useTagAnglesForViewAngles; //0x56FA
		char link_useBaseAnglesForViewClamp; //0x56FB
		float linkAnglesFrac; //0x56FC
		int link_viewClamp; //0x5700
		char _0x5704[0xC];
		int link_viewClamp_max0; //0x5710
		char _0x5714[0x18];
		int link_viewClamp_max1; //0x572C
		char _0x5730[0xD8];
	};

	struct gentity_s
	{
		int entNum; //0x0
		char _0x4[0x130];
		float origin[3]; //0x134
		float angles[3]; //0x140
		char _0x14C[0x8];
		gclient_s* client; //0x154
		char _0x158[0x1E];
		short classname; //0x176
		char _0x178[0xC];
		int spawnflags; //0x184
		char _0x188[0x20];
		int health; //0x1A8
		char _0x1AC[0x170];
	};

	struct level_locals_t
	{
		gclient_s* clients; //0x0
		gentity_s* entities; //0x4
		int gentitySize; //0x8
		int num_entities; //0xC
		gentity_s* firstFreeEnt; //0x10
		gentity_s* lastFreeEnt; //0x14
		void* vehicles; //0x18
		gentity_s* firstFreeActor; //0x1C
		gentity_s* lastFreeActor; //0x20
		int num_actors; //0x24
		void* sentients; //0x28
		void* actors; //0x2C
		int actorCorpseCount; //0x30
		void* bots; //0x34
		void* turrets; //0x38
		int logFile; //0x3C
		int initializing; //0x40
		int clientIsSpawning; //0x44
		int maxClients; //0x48
		char _0x4C[0x748];
		int framenum; //0x794
		int time; //0x798
		int previousTime; //0x79C
		int frameTime; //0x7A0
		int startTime; //0x7A4
		char _0x7A8[0x2774];
		int numConnectedClients; //0x2F1C
		char _0x2F20[0xE0];
		int teamScores[10]; //0x3000
	};
}