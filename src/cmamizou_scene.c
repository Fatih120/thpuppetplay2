#include "global.h"
#include "cmamizou_scene.h"
#include "sprite.h"
#include "task.h"
#include "graphics.h"
#include "bg.h"
#include "main.h"
#include "malloc.h"
#include "palette.h"
#include "scanline_effect.h"
#include "menu.h"
#include "menu_helpers.h"
#include "gpu_regs.h"
#include "decompress.h"
#include "sound.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "random.h"

/*
    This file handles the cutscene showing CMamizou arriving to settle the Miko/CMiko fight
    It consists of 5 separate scenes:
    - Miko and CMiko facing one another in a thunderstorm             (RAY_ANIM_DUO_FIGHT)
    - Over-the-shoulder of CMamizou flying                                (RAY_ANIM_TAKES_FLIGHT)
    - CMamizou emerging from a spotlight down through the clouds          (RAY_ANIM_DESCENDS)
    - A close-up of CMamizou flying down                                  (RAY_ANIM_CHARGES)
    - CMamizou floating above Miko/CMiko as they back away offscreen  (RAY_ANIM_CHASES_AWAY)

    A shortened version of the first scene is used when the player first arrives
    in Sootopolis during the Miko/CMiko conflict, before awakening CMamizou (RAY_ANIM_DUO_FIGHT_PRE)
    This is indicated with the first two arguments to DoCMamizouScene
*/

enum
{
    RAY_ANIM_DUO_FIGHT_PRE,
    RAY_ANIM_DUO_FIGHT,
    RAY_ANIM_TAKES_FLIGHT,
    RAY_ANIM_DESCENDS,
    RAY_ANIM_CHARGES,
    RAY_ANIM_CHASES_AWAY,
    RAY_ANIM_END
};

#define TAG_DUOFIGHT_MIKO             30505
#define TAG_DUOFIGHT_MIKO_SHOULDER    30506
#define TAG_DUOFIGHT_MIKO_CLAW        30507
#define TAG_DUOFIGHT_CMIKO              30508
#define TAG_DUOFIGHT_CMIKO_PECTORAL_FIN 30509
#define TAG_DUOFIGHT_CMIKO_DORSAL_FIN   30510
#define TAG_FLIGHT_SMOKE                 30555
#define TAG_DESCENDS_CMAMIZOU            30556
#define TAG_DESCENDS_CMAMIZOU_TAIL       30557
#define TAG_CHASE_MIKO                30565
#define TAG_CHASE_MIKO_TAIL           30566
#define TAG_CHASE_CMIKO                 30568
#define TAG_CHASE_CMAMIZOU               30569
#define TAG_CHASE_CMAMIZOU_TAIL          30570
#define TAG_CHASE_SPLASH                 30571

#define MAX_SMOKE 10

typedef u8 ALIGNED(4) TilemapBuffer[BG_SCREEN_SIZE];

struct CMamizouScene
{
    MainCallback exitCallback;
    TilemapBuffer tilemapBuffers[4];
    u16 unk; // never read
    u8 animId;
    bool8 endEarly;
    s16 revealedLightLine;
    s16 revealedLightTimer;
    u8 unused[12];
};

static EWRAM_DATA struct CMamizouScene *sRayScene = NULL;

static void CB2_InitCMamizouScene(void);
static void CB2_CMamizouScene(void);
static void Task_EndAfterFadeScreen(u8);

// RAY_ANIM_DUO_FIGHT_PRE / RAY_ANIM_DUO_FIGHT
static void Task_DuoFightAnim(u8);
static void Task_HandleDuoFight(u8);
static void Task_DuoFightEnd(u8);
static void DuoFightEnd(u8, s8);
static void Task_DuoFight_AnimateClouds(u8);
static void DuoFight_PanOffScene(u8);
static void DuoFight_AnimateRain(void);
static void DuoFight_Lightning1(void);
static void DuoFight_Lightning2(void);
static void DuoFight_LightningLong(void);
static u8 DuoFightPre_CreateMikoSprites(void);
static u8 DuoFightPre_CreateCMikoSprites(void);
static u8 DuoFight_CreateMikoSprites(void);
static u8 DuoFight_CreateCMikoSprites(void);
static void SpriteCB_DuoFightPre_Miko(struct Sprite *);
static void SpriteCB_DuoFightPre_CMiko(struct Sprite *);
static void SpriteCB_DuoFight_Miko(struct Sprite *);
static void SpriteCB_DuoFight_CMiko(struct Sprite *);
static void DuoFight_SlideMikoDown(struct Sprite *);
static void DuoFight_SlideCMikoDown(struct Sprite *);

// RAY_ANIM_TAKES_FLIGHT
static void Task_RayTakesFlightAnim(u8);
static void Task_HandleRayTakesFlight(u8);
static void Task_RayTakesFlightEnd(u8);
static void Task_TakesFlight_CreateSmoke(u8);
static void SpriteCB_TakesFlight_Smoke(struct Sprite *);

// RAY_ANIM_DESCENDS
static void Task_RayDescendsAnim(u8);
static void Task_HandleRayDescends(u8);
static void Task_RayDescendsEnd(u8);
static u8 CreateDescendsCMamizouSprite(void);
static void SpriteCB_Descends_CMamizou(struct Sprite *);

// RAY_ANIM_CHARGES
static void Task_RayChargesAnim(u8);
static void Task_HandleRayCharges(u8);
static void Task_RayChargesEnd(u8);
static void Task_RayCharges_ShakeCMamizou(u8);
static void Task_RayCharges_FlyOffscreen(u8);
static void RayCharges_AnimateBg(void);

// RAY_ANIM_CHASES_AWAY
static void Task_RayChasesAwayAnim(u8);
static void Task_HandleRayChasesAway(u8);
static void Task_RayChasesAwayEnd(u8);
static void Task_ChasesAway_AnimateBg(u8);
static void ChasesAway_CMikoStartLeave(u8);
static void ChasesAway_MikoStartLeave(u8);
static void ChasesAway_CreateTrioSprites(u8);
static void Task_ChasesAway_AnimateRing(u8);
static void SpriteCB_ChasesAway_MikoLeave(struct Sprite *);
static void SpriteCB_ChasesAway_CMikoLeave(struct Sprite *);
static void SpriteCB_ChasesAway_CMamizouFloat(struct Sprite *);
static void SpriteCB_ChasesAway_CMamizou(struct Sprite *);
static void SpriteCB_ChasesAway_DuoRingPush(struct Sprite *);
static void ChasesAway_SetCMamizouAnim(struct Sprite *, u8, s16, s16);

static const TaskFunc sTasksForAnimations[] =
{
    [RAY_ANIM_DUO_FIGHT_PRE] = Task_DuoFightAnim,
    [RAY_ANIM_DUO_FIGHT]     = Task_DuoFightAnim,
    [RAY_ANIM_TAKES_FLIGHT]  = Task_RayTakesFlightAnim,
    [RAY_ANIM_DESCENDS]      = Task_RayDescendsAnim,
    [RAY_ANIM_CHARGES]       = Task_RayChargesAnim,
    [RAY_ANIM_CHASES_AWAY]   = Task_RayChasesAwayAnim,
    [RAY_ANIM_END]           = Task_EndAfterFadeScreen,
};

static const struct OamData sOam_64x64 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOam_32x32 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOam_64x32 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOam_32x16 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOam_16x8 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOam_16x32 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOam_16x16 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOam_32x8 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sAnim_DuoFightPre_Miko_Head[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(64, 30),
    ANIMCMD_FRAME(128, 30),
    ANIMCMD_FRAME(64, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_DuoFightPre_Miko_Body[] =
{
    ANIMCMD_FRAME(192, 30),
    ANIMCMD_FRAME(256, 30),
    ANIMCMD_FRAME(320, 30),
    ANIMCMD_FRAME(256, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_DuoFightPre_Miko[] =
{
    sAnim_DuoFightPre_Miko_Head,
    sAnim_DuoFightPre_Miko_Body
};

static const struct SpriteTemplate sSpriteTemplate_DuoFightPre_Miko =
{
    .tileTag = TAG_DUOFIGHT_MIKO,
    .paletteTag = TAG_DUOFIGHT_MIKO,
    .oam = &sOam_64x64,
    .anims = sAnims_DuoFightPre_Miko,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sAnim_DuoFightPre_MikoShoulderCMikoDorsalFin[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_DuoFightPre_MikoShoulderCMikoDorsalFin[] =
{
    sAnim_DuoFightPre_MikoShoulderCMikoDorsalFin
};

static const struct SpriteTemplate sSpriteTemplate_DuoFightPre_MikoShoulder =
{
    .tileTag = TAG_DUOFIGHT_MIKO_SHOULDER,
    .paletteTag = TAG_DUOFIGHT_MIKO,
    .oam = &sOam_32x32,
    .anims = sAnims_DuoFightPre_MikoShoulderCMikoDorsalFin,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sAnim_DuoFightPre_MikoClaw[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_DuoFightPre_MikoClaw[] =
{
    sAnim_DuoFightPre_MikoClaw
};

static const struct SpriteTemplate sSpriteTemplate_DuoFightPre_MikoClaw =
{
    .tileTag = TAG_DUOFIGHT_MIKO_CLAW,
    .paletteTag = TAG_DUOFIGHT_MIKO,
    .oam = &sOam_64x32,
    .anims = sAnims_DuoFightPre_MikoClaw,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sAnim_DuoFightPre_CMiko_TopLeft[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFightPre_CMiko_TopRight[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFightPre_CMiko_FaceLeft[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFightPre_CMiko_FaceRight[] =
{
    ANIMCMD_FRAME(24, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFightPre_CMiko_ChinLeft[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFightPre_CMiko_ChinRight[] =
{
    ANIMCMD_FRAME(40, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFightPre_CMiko_LeftPectoralFin[] =
{
    ANIMCMD_FRAME(48, 36),
    ANIMCMD_FRAME(64, 36),
    ANIMCMD_FRAME(80, 36),
    ANIMCMD_FRAME(64, 36),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_DuoFightPre_CMiko_LeftShoulder[] =
{
    ANIMCMD_FRAME(56, 36),
    ANIMCMD_FRAME(72, 36),
    ANIMCMD_FRAME(88, 36),
    ANIMCMD_FRAME(72, 36),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_DuoFightPre_CMiko_RightShoulder[] =
{
    ANIMCMD_FRAME(96, 36),
    ANIMCMD_FRAME(104, 36),
    ANIMCMD_FRAME(112, 36),
    ANIMCMD_FRAME(104, 36),
    ANIMCMD_JUMP(0),
};

// Edge of the right pectoral fin is its own sprite (see CMikoPectoralFin)
static const union AnimCmd *const sAnims_DuoFightPre_CMiko[] =
{
    sAnim_DuoFightPre_CMiko_TopLeft,
    sAnim_DuoFightPre_CMiko_TopRight,
    sAnim_DuoFightPre_CMiko_FaceLeft,
    sAnim_DuoFightPre_CMiko_FaceRight,
    sAnim_DuoFightPre_CMiko_ChinLeft,
    sAnim_DuoFightPre_CMiko_ChinRight,
    sAnim_DuoFightPre_CMiko_LeftPectoralFin,
    sAnim_DuoFightPre_CMiko_LeftShoulder,
    sAnim_DuoFightPre_CMiko_RightShoulder
};

static const struct SpriteTemplate sSpriteTemplate_DuoFightPre_CMiko =
{
    .tileTag = TAG_DUOFIGHT_CMIKO,
    .paletteTag = TAG_DUOFIGHT_CMIKO,
    .oam = &sOam_32x16,
    .anims = sAnims_DuoFightPre_CMiko,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sAnim_DuoFightPre_CMikoPectoralFin[] =
{
    ANIMCMD_FRAME(0, 36),
    ANIMCMD_FRAME(2, 36),
    ANIMCMD_FRAME(4, 36),
    ANIMCMD_FRAME(2, 36),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_DuoFightPre_CMikoPectoralFin[] =
{
    sAnim_DuoFightPre_CMikoPectoralFin
};

static const struct SpriteTemplate sSpriteTemplate_DuoFightPre_CMikoPectoralFin =
{
    .tileTag = TAG_DUOFIGHT_CMIKO_PECTORAL_FIN,
    .paletteTag = TAG_DUOFIGHT_CMIKO,
    .oam = &sOam_16x8,
    .anims = sAnims_DuoFightPre_CMikoPectoralFin,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_DuoFightPre_CMikoDorsalFin =
{
    .tileTag = TAG_DUOFIGHT_CMIKO_DORSAL_FIN,
    .paletteTag = TAG_DUOFIGHT_CMIKO,
    .oam = &sOam_32x32,
    .anims = sAnims_DuoFightPre_MikoShoulderCMikoDorsalFin,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct ScanlineEffectParams sScanlineParams_DuoFight_Clouds =
{
    .dmaDest = &REG_BG1HOFS,
    .dmaControl = SCANLINE_EFFECT_DMACNT_16BIT,
    .initState = 1
};

static const struct BgTemplate sBgTemplates_DuoFight[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
};

static const union AnimCmd sAnim_DuoFight_Miko_Head[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(64, 20),
    ANIMCMD_FRAME(128, 20),
    ANIMCMD_FRAME(64, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_DuoFight_Miko_Body[] =
{
    ANIMCMD_FRAME(192, 20),
    ANIMCMD_FRAME(256, 20),
    ANIMCMD_FRAME(320, 20),
    ANIMCMD_FRAME(256, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_DuoFight_Miko[] =
{
    sAnim_DuoFight_Miko_Head,
    sAnim_DuoFight_Miko_Body
};

static const struct CompressedSpriteSheet sSpriteSheet_DuoFight_Miko =
{
    gRaySceneDuoFight_Miko_Gfx, 0x3000, TAG_DUOFIGHT_MIKO
};

static const struct CompressedSpritePalette sSpritePal_DuoFight_Miko =
{
    gRaySceneDuoFight_Miko_Pal, TAG_DUOFIGHT_MIKO
};

static const struct SpriteTemplate sSpriteTemplate_DuoFight_Miko =
{
    .tileTag = TAG_DUOFIGHT_MIKO,
    .paletteTag = TAG_DUOFIGHT_MIKO,
    .oam = &sOam_64x64,
    .anims = sAnims_DuoFight_Miko,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sAnim_DuoFight_MikoShoulderCMikoDorsalFin[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_DuoFight_MikoShoulderCMikoDorsalFin[] =
{
    sAnim_DuoFight_MikoShoulderCMikoDorsalFin
};

static const struct CompressedSpriteSheet sSpriteSheet_DuoFight_MikoShoulder =
{
    gRaySceneDuoFight_MikoShoulder_Gfx, 0x200, TAG_DUOFIGHT_MIKO_SHOULDER
};

static const struct SpriteTemplate sSpriteTemplate_DuoFight_MikoShoulder =
{
    .tileTag = TAG_DUOFIGHT_MIKO_SHOULDER,
    .paletteTag = TAG_DUOFIGHT_MIKO,
    .oam = &sOam_32x32,
    .anims = sAnims_DuoFight_MikoShoulderCMikoDorsalFin,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sAnim_DuoFight_MikoClaw[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_DuoFight_MikoClaw[] =
{
    sAnim_DuoFight_MikoClaw
};

static const struct CompressedSpriteSheet sSpriteSheet_DuoFight_MikoClaw =
{
    gRaySceneDuoFight_MikoClaw_Gfx, 0x400, TAG_DUOFIGHT_MIKO_CLAW
};

static const struct SpriteTemplate sSpriteTemplate_DuoFight_MikoClaw =
{
    .tileTag = TAG_DUOFIGHT_MIKO_CLAW,
    .paletteTag = TAG_DUOFIGHT_MIKO,
    .oam = &sOam_64x32,
    .anims = sAnims_DuoFight_MikoClaw,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sAnim_DuoFight_CMiko_TopLeft[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFight_CMiko_TopRight[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFight_CMiko_FaceLeft[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFight_CMiko_FaceRight[] =
{
    ANIMCMD_FRAME(24, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFight_CMiko_ChinLeft[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFight_CMiko_ChinRight[] =
{
    ANIMCMD_FRAME(40, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DuoFight_CMiko_LeftPectoralFin[] =
{
    ANIMCMD_FRAME(48, 24),
    ANIMCMD_FRAME(64, 24),
    ANIMCMD_FRAME(80, 24),
    ANIMCMD_FRAME(64, 24),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_DuoFight_CMiko_LeftShoulder[] =
{
    ANIMCMD_FRAME(56, 24),
    ANIMCMD_FRAME(72, 24),
    ANIMCMD_FRAME(88, 24),
    ANIMCMD_FRAME(72, 24),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_DuoFight_CMiko_RightShoulder[] =
{
    ANIMCMD_FRAME(96, 24),
    ANIMCMD_FRAME(104, 24),
    ANIMCMD_FRAME(112, 24),
    ANIMCMD_FRAME(104, 24),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_DuoFight_CMiko[] =
{
    sAnim_DuoFight_CMiko_TopLeft,
    sAnim_DuoFight_CMiko_TopRight,
    sAnim_DuoFight_CMiko_FaceLeft,
    sAnim_DuoFight_CMiko_FaceRight,
    sAnim_DuoFight_CMiko_ChinLeft,
    sAnim_DuoFight_CMiko_ChinRight,
    sAnim_DuoFight_CMiko_LeftPectoralFin,
    sAnim_DuoFight_CMiko_LeftShoulder,
    sAnim_DuoFight_CMiko_RightShoulder
};

static const struct CompressedSpriteSheet sSpriteSheet_DuoFight_CMiko =
{
    gRaySceneDuoFight_CMiko_Gfx, 0xF00, TAG_DUOFIGHT_CMIKO
};

static const struct CompressedSpritePalette sSpritePal_DuoFight_CMiko =
{
    gRaySceneDuoFight_CMiko_Pal, TAG_DUOFIGHT_CMIKO
};

static const struct SpriteTemplate sSpriteTemplate_DuoFight_CMiko =
{
    .tileTag = TAG_DUOFIGHT_CMIKO,
    .paletteTag = TAG_DUOFIGHT_CMIKO,
    .oam = &sOam_32x16,
    .anims = sAnims_DuoFight_CMiko,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sAnim_DuoFight_CMikoPectoralFin[] =
{
    ANIMCMD_FRAME(0, 24),
    ANIMCMD_FRAME(2, 24),
    ANIMCMD_FRAME(4, 24),
    ANIMCMD_FRAME(2, 24),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_DuoFight_CMikoPectoralFin[] =
{
    sAnim_DuoFight_CMikoPectoralFin
};

static const struct CompressedSpriteSheet sSpriteSheet_DuoFight_CMikoPectoralFin =
{
    gRaySceneDuoFight_CMikoPectoralFin_Gfx, 0xC0, TAG_DUOFIGHT_CMIKO_PECTORAL_FIN
};

static const struct SpriteTemplate sSpriteTemplate_DuoFight_CMikoPectoralFin =
{
    .tileTag = TAG_DUOFIGHT_CMIKO_PECTORAL_FIN,
    .paletteTag = TAG_DUOFIGHT_CMIKO,
    .oam = &sOam_16x8,
    .anims = sAnims_DuoFight_CMikoPectoralFin,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct CompressedSpriteSheet sSpriteSheet_DuoFight_CMikoDorsalFin =
{
    gRaySceneDuoFight_CMikoDorsalFin_Gfx, 0x200, TAG_DUOFIGHT_CMIKO_DORSAL_FIN
};

static const struct SpriteTemplate sSpriteTemplate_DuoFight_CMikoDorsalFin =
{
    .tileTag = TAG_DUOFIGHT_CMIKO_DORSAL_FIN,
    .paletteTag = TAG_DUOFIGHT_CMIKO,
    .oam = &sOam_32x32,
    .anims = sAnims_DuoFight_MikoShoulderCMikoDorsalFin,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct BgTemplate sBgTemplates_TakesFlight[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 29,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    }
};

static const union AnimCmd sAnim_TakesFlight_Smoke[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_TakesFlight_Smoke[] =
{
    sAnim_TakesFlight_Smoke
};

static const union AffineAnimCmd sAffineAnim_TakesFlight_Smoke[] =
{
    AFFINEANIMCMD_FRAME(-64, -64, 0, 1),
    AFFINEANIMCMD_FRAME(32, 32, 0, 14),
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_JUMP(0)
};

static const union AffineAnimCmd *const sAffineAnims_TakesFlight_Smoke[] =
{
    sAffineAnim_TakesFlight_Smoke
};

static const struct CompressedSpriteSheet sSpriteSheet_TakesFlight_Smoke =
{
    gRaySceneTakesFlight_Smoke_Gfx, 0x100, TAG_FLIGHT_SMOKE
};

static const struct CompressedSpritePalette sSpritePal_TakesFlight_Smoke =
{
    gRaySceneTakesFlight_Smoke_Pal, TAG_FLIGHT_SMOKE
};

static const struct SpriteTemplate sSpriteTemplate_TakesFlight_Smoke =
{
    .tileTag = TAG_FLIGHT_SMOKE,
    .paletteTag = TAG_FLIGHT_SMOKE,
    .oam = &sOam_32x16,
    .anims = sAnims_TakesFlight_Smoke,
    .images = NULL,
    .affineAnims = sAffineAnims_TakesFlight_Smoke,
    .callback = SpriteCB_TakesFlight_Smoke,
};

static const s8 sTakesFlight_SmokeCoords[MAX_SMOKE][2] =
{
    {-1,  5},
    {-3, -4},
    { 5, -3},
    {-7,  2},
    {-9, -1},
    { 1, -5},
    { 3,  4},
    {-5,  3},
    { 7, -2},
    { 9,  1}
};

static const struct BgTemplate sBgTemplates_Descends[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 1,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const union AnimCmd sAnim_Descends_CMamizou[] =
{
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_FRAME(64, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_Descends_CMamizou[] =
{
    sAnim_Descends_CMamizou
};

static const union AnimCmd sAnim_Descends_CMamizouTail[] =
{
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_FRAME(8, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_Descends_CMamizouTail[] =
{
    sAnim_Descends_CMamizouTail
};

static const struct CompressedSpriteSheet sSpriteSheet_Descends_CMamizou =
{
    gRaySceneDescends_CMamizou_Gfx, 0x1000, TAG_DESCENDS_CMAMIZOU
};

static const struct CompressedSpriteSheet sSpriteSheet_Descends_CMamizouTail =
{
    gRaySceneDescends_CMamizouTail_Gfx, 0x200, TAG_DESCENDS_CMAMIZOU_TAIL
};

static const struct CompressedSpritePalette sSpritePal_Descends_CMamizou =
{
    gRaySceneTakesFlight_CMamizou_Pal, TAG_DESCENDS_CMAMIZOU // "Takes flight" palette re-used here
};

static const struct SpriteTemplate sSpriteTemplate_Descends_CMamizou =
{
    .tileTag = TAG_DESCENDS_CMAMIZOU,
    .paletteTag = TAG_DESCENDS_CMAMIZOU,
    .oam = &sOam_64x64,
    .anims = sAnims_Descends_CMamizou,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_Descends_CMamizouTail =
{
    .tileTag = TAG_DESCENDS_CMAMIZOU_TAIL,
    .paletteTag = TAG_DESCENDS_CMAMIZOU,
    .oam = &sOam_16x32,
    .anims = sAnims_Descends_CMamizouTail,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct BgTemplate sBgTemplates_Charges[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const union AnimCmd sAnim_ChasesAway_Miko_Still[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ChasesAway_Miko_Moving[] =
{
    ANIMCMD_FRAME(0, 48),
    ANIMCMD_FRAME(64, 32),
    ANIMCMD_FRAME(0, 48),
    ANIMCMD_FRAME(128, 32),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnims_ChasesAway_Miko[] =
{
    sAnim_ChasesAway_Miko_Still,
    sAnim_ChasesAway_Miko_Moving
};

static const union AnimCmd sAnim_ChasesAway_MikoTail[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_ChasesAway_MikoTail[] =
{
    sAnim_ChasesAway_MikoTail,
};

static const union AnimCmd sAnim_ChasesAway_CMiko_Front[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ChasesAway_CMiko_Back[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ChasesAway_CMiko_Tail[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_ChasesAway_CMiko[] =
{
    sAnim_ChasesAway_CMiko_Front,
    sAnim_ChasesAway_CMiko_Back,
    sAnim_ChasesAway_CMiko_Tail
};

static const union AnimCmd sAnim_ChasesAway_CMamizou_FlyingDown[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ChasesAway_CMamizou_Arriving[] =
{
    ANIMCMD_FRAME(64, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ChasesAway_CMamizou_Floating[] =
{
    ANIMCMD_FRAME(128, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ChasesAway_CMamizou_Shouting[] =
{
    ANIMCMD_FRAME(192, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_ChasesAway_CMamizou[] =
{
    sAnim_ChasesAway_CMamizou_FlyingDown,
    sAnim_ChasesAway_CMamizou_Arriving,
    sAnim_ChasesAway_CMamizou_Floating,
    sAnim_ChasesAway_CMamizou_Shouting
};

static const union AnimCmd sAnim_ChasesAway_CMamizouTail_FlyingDown[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ChasesAway_CMamizouTail_Arriving[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ChasesAway_CMamizouTail_Floating[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ChasesAway_CMamizouTail_Shouting[] =
{
    ANIMCMD_FRAME(48, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_ChasesAway_CMamizouTail[] =
{
    sAnim_ChasesAway_CMamizouTail_FlyingDown,
    sAnim_ChasesAway_CMamizouTail_Arriving,
    sAnim_ChasesAway_CMamizouTail_Floating,
    sAnim_ChasesAway_CMamizouTail_Shouting
};

static const union AnimCmd sAnim_ChasesAway_CMikoSplash[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_FRAME(12, 8),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(20, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnims_ChasesAway_CMikoSplash[] =
{
    sAnim_ChasesAway_CMikoSplash
};

static const struct CompressedSpriteSheet sSpriteSheet_ChasesAway_Miko =
{
    gRaySceneChasesAway_Miko_Gfx, 0x1800, TAG_CHASE_MIKO
};

static const struct CompressedSpriteSheet sSpriteSheet_ChasesAway_MikoTail =
{
    gRaySceneChasesAway_MikoTail_Gfx, 0x80, TAG_CHASE_MIKO_TAIL
};

static const struct CompressedSpriteSheet sSpriteSheet_ChasesAway_CMiko =
{
    gRaySceneChasesAway_CMiko_Gfx, 0x600, TAG_CHASE_CMIKO
};

static const struct CompressedSpriteSheet sSpriteSheet_ChasesAway_CMamizou =
{
    gRaySceneChasesAway_CMamizou_Gfx, 0x2000, TAG_CHASE_CMAMIZOU
};

static const struct CompressedSpriteSheet sSpriteSheet_ChasesAway_CMamizouTail =
{
    gRaySceneChasesAway_CMamizouTail_Gfx, 0x800, TAG_CHASE_CMAMIZOU_TAIL
};

static const struct CompressedSpriteSheet sSpriteSheet_ChasesAway_CMikoSplash =
{
    gRaySceneChasesAway_CMikoSplash_Gfx, 0x300, TAG_CHASE_SPLASH
};

static const struct CompressedSpritePalette sSpritePal_ChasesAway_Miko =
{
    gRaySceneChasesAway_Miko_Pal, TAG_CHASE_MIKO
};

static const struct CompressedSpritePalette sSpritePal_ChasesAway_CMiko =
{
    gRaySceneChasesAway_CMiko_Pal, TAG_CHASE_CMIKO
};

static const struct CompressedSpritePalette sSpritePal_ChasesAway_CMamizou =
{
    gRaySceneChasesAway_CMamizou_Pal, TAG_CHASE_CMAMIZOU
};

static const struct CompressedSpritePalette sSpritePal_ChasesAway_CMikoSplash =
{
    gRaySceneChasesAway_CMikoSplash_Pal, TAG_CHASE_SPLASH
};

static const struct SpriteTemplate sSpriteTemplate_ChasesAway_Miko =
{
    .tileTag = TAG_CHASE_MIKO,
    .paletteTag = TAG_CHASE_MIKO,
    .oam = &sOam_64x64,
    .anims = sAnims_ChasesAway_Miko,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_ChasesAway_MikoTail =
{
    .tileTag = TAG_CHASE_MIKO_TAIL,
    .paletteTag = TAG_CHASE_MIKO,
    .oam = &sOam_16x16,
    .anims = sAnims_ChasesAway_MikoTail,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_ChasesAway_CMiko =
{
    .tileTag = TAG_CHASE_CMIKO,
    .paletteTag = TAG_CHASE_CMIKO,
    .oam = &sOam_32x32,
    .anims = sAnims_ChasesAway_CMiko,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_ChasesAway_CMamizou =
{
    .tileTag = TAG_CHASE_CMAMIZOU,
    .paletteTag = TAG_CHASE_CMAMIZOU,
    .oam = &sOam_64x64,
    .anims = sAnims_ChasesAway_CMamizou,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ChasesAway_CMamizou,
};

static const struct SpriteTemplate sSpriteTemplate_ChasesAway_CMamizouTail =
{
    .tileTag = TAG_CHASE_CMAMIZOU_TAIL,
    .paletteTag = TAG_CHASE_CMAMIZOU,
    .oam = &sOam_32x32,
    .anims = sAnims_ChasesAway_CMamizouTail,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_ChasesAway_CMikoSplash =
{
    .tileTag = TAG_CHASE_SPLASH,
    .paletteTag = TAG_CHASE_SPLASH,
    .oam = &sOam_32x8,
    .anims = sAnims_ChasesAway_CMikoSplash,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct BgTemplate sBgTemplates_ChasesAway[] =
{
    {
        .bg = 0,
        .charBaseIndex = 1,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    }
};

void DoCMamizouScene(u8 animId, bool8 endEarly, void (*exitCallback)(void))
{
    sRayScene = AllocZeroed(sizeof(*sRayScene));
    sRayScene->animId = animId;
    sRayScene->exitCallback = exitCallback;
    sRayScene->endEarly = endEarly;
    SetMainCallback2(CB2_InitCMamizouScene);
}

static void CB2_InitCMamizouScene(void)
{
    SetVBlankHBlankCallbacksToNull();
    ClearScheduledBgCopiesToVram();
    ScanlineEffect_Stop();
    FreeAllSpritePalettes();
    ResetPaletteFade();
    ResetSpriteData();
    ResetTasks();
    FillPalette(RGB_BLACK, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
    CreateTask(sTasksForAnimations[sRayScene->animId], 0);
    SetMainCallback2(CB2_CMamizouScene);
}

static void CB2_CMamizouScene(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlankCB_CMamizouScene(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Task_EndAfterFadeScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        ResetSpriteData();
        FreeAllSpritePalettes();
        SetMainCallback2(sRayScene->exitCallback);
        Free(sRayScene);
        DestroyTask(taskId);
    }
}

static void Task_SetNextAnim(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (sRayScene->endEarly == TRUE)
        {
            gTasks[taskId].func = Task_EndAfterFadeScreen;
        }
        else
        {
            sRayScene->animId++;
            sRayScene->unk = 0;
            gTasks[taskId].func = sTasksForAnimations[sRayScene->animId];
        }
    }
}

// The cutscene window is cropped to a narrower view, with black borders on each vertical edge
// This function is used in scenes where sprites in these borders need to be hidden
static void SetWindowsHideVertBorders(void)
{
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_ALL);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, DISPLAY_WIDTH));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(24, DISPLAY_HEIGHT - 24));
    gPlttBufferUnfaded[0] = 0;
    gPlttBufferFaded[0] = 0;
}

static void ResetWindowDimensions(void)
{
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_ALL);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_ALL);
}


// RAY_ANIM_DUO_FIGHT / RAY_ANIM_DUO_FIGHT_PRE

#define tTimer           data[0]
#define tHelperTaskId    data[1]
#define tMikoSpriteId data[2]
#define tCMikoSpriteId  data[3]

#define sMikoBodySpriteId     data[0]
#define sMikoShoulderSpriteId data[1]
#define sMikoClawSpriteId     data[2]

static void Task_HandleDuoFightPre(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    DuoFight_AnimateRain();
    if (!gPaletteFade.active)
    {
        s16 frame = tTimer;
        if (frame == 64)
        {
            DuoFight_Lightning1();
        }
        else if (frame == 144)
        {
            DuoFight_Lightning2();
        }
        else
        {
            switch (frame)
            {
            case 328:
                DuoFightEnd(taskId, 0);
                return;
            case 148:
                DuoFight_LightningLong();
                break;
            }
        }

        tTimer++;
    }
}

static u8 DuoFightPre_CreateMikoSprites(void)
{
    u8 spriteId;
    s16 *data;

    spriteId = CreateSprite(&sSpriteTemplate_DuoFightPre_Miko, 88, 72, 3);
    gSprites[spriteId].callback = SpriteCB_DuoFightPre_Miko;
    data = gSprites[spriteId].data;
    sMikoBodySpriteId = CreateSprite(&sSpriteTemplate_DuoFightPre_Miko, 56, 104, 3);
    sMikoShoulderSpriteId = CreateSprite(&sSpriteTemplate_DuoFightPre_MikoShoulder, 75, 101, 0);
    sMikoClawSpriteId = CreateSprite(&sSpriteTemplate_DuoFightPre_MikoClaw, 109, 114, 1);
    StartSpriteAnim(&gSprites[sMikoBodySpriteId], 1);
    return spriteId;
}

static void SpriteCB_DuoFightPre_Miko(struct Sprite *sprite)
{
    s16 *data = sprite->data;
    data[5]++;
    data[5] &= 0x1F;
    if (data[5] == 0 && sprite->x != 72)
    {
        sprite->x--;
        gSprites[sprite->sMikoBodySpriteId].x--;
        gSprites[sMikoShoulderSpriteId].x--;
        gSprites[sMikoClawSpriteId].x--;
    }

    switch (sprite->animCmdIndex)
    {
    case 0:
        gSprites[sMikoShoulderSpriteId].x2 = 0;
        gSprites[sMikoShoulderSpriteId].y2 = 0;
        gSprites[sMikoClawSpriteId].x2 = 0;
        gSprites[sMikoClawSpriteId].y2 = 0;
        break;
    case 1:
    case 3:
        gSprites[sMikoShoulderSpriteId].x2 = -1;
        gSprites[sMikoShoulderSpriteId].y2 = 0;
        gSprites[sMikoClawSpriteId].x2 = -1;
        gSprites[sMikoClawSpriteId].y2 = 0;
        break;
    case 2:
        gSprites[sMikoShoulderSpriteId].x2 = -1;
        gSprites[sMikoShoulderSpriteId].y2 = 1;
        gSprites[sMikoClawSpriteId].x2 = -2;
        gSprites[sMikoClawSpriteId].y2 = 1;
        break;
    }
}

static u8 DuoFightPre_CreateCMikoSprites(void)
{
    u8 spriteId;
    s16 *data;

    spriteId = CreateSprite(&sSpriteTemplate_DuoFightPre_CMiko, 136, 96, 1);
    gSprites[spriteId].callback = SpriteCB_DuoFightPre_CMiko;
    data = gSprites[spriteId].data;

    data[0]  = CreateSprite(&sSpriteTemplate_DuoFightPre_CMiko, 168,  96, 1) << 8;
    data[0] |= CreateSprite(&sSpriteTemplate_DuoFightPre_CMiko, 136, 112, 1);
    data[1]  = CreateSprite(&sSpriteTemplate_DuoFightPre_CMiko, 168, 112, 1) << 8;
    data[1] |= CreateSprite(&sSpriteTemplate_DuoFightPre_CMiko, 136, 128, 1);
    data[2]  = CreateSprite(&sSpriteTemplate_DuoFightPre_CMiko, 168, 128, 1) << 8;
    data[2] |= CreateSprite(&sSpriteTemplate_DuoFightPre_CMiko, 104, 128, 2);
    data[3]  = CreateSprite(&sSpriteTemplate_DuoFightPre_CMiko, 136, 128, 2) << 8;
    data[3] |= CreateSprite(&sSpriteTemplate_DuoFightPre_CMiko, 184, 128, 0);
    data[4]  = CreateSprite(&sSpriteTemplate_DuoFightPre_CMikoPectoralFin, 208, 132, 0) << 8;
    data[4] |= CreateSprite(&sSpriteTemplate_DuoFightPre_CMikoDorsalFin, 200, 120, 1);

    StartSpriteAnim(&gSprites[data[0] >> 8], 1);
    StartSpriteAnim(&gSprites[data[0] & 0xFF], 2);
    StartSpriteAnim(&gSprites[data[1] >> 8], 3);
    StartSpriteAnim(&gSprites[data[1] & 0xFF], 4);
    StartSpriteAnim(&gSprites[data[2] >> 8], 5);
    StartSpriteAnim(&gSprites[data[2] & 0xFF], 6);
    StartSpriteAnim(&gSprites[data[3] >> 8], 7);
    StartSpriteAnim(&gSprites[data[3] & 0xFF], 8);

    return spriteId;
}

static void SpriteCB_DuoFightPre_CMiko(struct Sprite *sprite)
{
    s16 *data = sprite->data;
    data[5]++;
    data[5] &= 0x1F;
    if (data[5] == 0 && sprite->x != 152)
    {
        sprite->x++;
        gSprites[sprite->data[0] >> 8].x++;
        gSprites[sprite->data[0] & 0xFF].x++;
        gSprites[data[1] >> 8].x++;
        gSprites[data[1] & 0xFF].x++;
        gSprites[data[2] >> 8].x++;
        gSprites[data[2] & 0xFF].x++;
        gSprites[data[3] >> 8].x++;
        gSprites[data[3] & 0xFF].x++;
        gSprites[data[4] >> 8].x++;
        gSprites[data[4] & 0xFF].x++;
    }

    switch (gSprites[data[2] & 0xFF].animCmdIndex)
    {
    case 0:
        sprite->y2 = 0;
        gSprites[data[0] >> 8].y2 = 0;
        gSprites[data[0] & 0xFF].y2 = 0;
        gSprites[data[1] >> 8].y2 = 0;
        gSprites[data[1] & 0xFF].y2 = 0;
        gSprites[data[2] >> 8].y2 = 0;
        gSprites[data[2] & 0xFF].y2 = 0;
        gSprites[data[3] >> 8].y2 = 0;
        gSprites[data[3] & 0xFF].y2 = 0;
        gSprites[data[4] >> 8].y2 = 0;
        gSprites[data[4] & 0xFF].y2 = 0;
        break;
    case 1:
    case 3:
        sprite->y2 = 1;
        gSprites[data[0] >> 8].y2 = 1;
        gSprites[data[0] & 0xFF].y2 = 1;
        gSprites[data[1] >> 8].y2 = 1;
        gSprites[data[1] & 0xFF].y2 = 1;
        gSprites[data[2] >> 8].y2 = 1;
        gSprites[data[2] & 0xFF].y2 = 1;
        gSprites[data[3] >> 8].y2 = 1;
        gSprites[data[3] & 0xFF].y2 = 1;
        gSprites[data[4] >> 8].y2 = 1;
        gSprites[data[4] & 0xFF].y2 = 1;
        break;
    case 2:
        sprite->y2 = 2;
        gSprites[data[0] >> 8].y2 = 2;
        gSprites[data[0] & 0xFF].y2 = 2;
        gSprites[data[1] >> 8].y2 = 2;
        gSprites[data[1] & 0xFF].y2 = 2;
        gSprites[data[2] >> 8].y2 = 2;
        gSprites[data[4] & 0xFF].y2 = 2;
        break;
    }
}

static void VBlankCB_DuoFight(void)
{
    VBlankCB_CMamizouScene();
    ScanlineEffect_InitHBlankDmaTransfer();
}

static void InitDuoFightSceneBgs(void)
{
    ResetVramOamAndBgCntRegs();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates_DuoFight, ARRAY_COUNT(sBgTemplates_DuoFight));
    SetBgTilemapBuffer(0, sRayScene->tilemapBuffers[0]);
    SetBgTilemapBuffer(1, sRayScene->tilemapBuffers[1]);
    SetBgTilemapBuffer(2, sRayScene->tilemapBuffers[2]);
    ResetAllBgsCoordinates();
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static void LoadDuoFightSceneGfx(void)
{
    ResetTempTileDataBuffers();
    DecompressAndCopyTileDataToVram(0, gRaySceneDuoFight_Clouds_Gfx, 0, 0, 0);
    while (FreeTempTileDataBuffersIfPossible())
        ;
    LZDecompressWram(gRaySceneDuoFight_Clouds2_Tilemap, sRayScene->tilemapBuffers[0]);
    LZDecompressWram(gRaySceneDuoFight_Clouds1_Tilemap, sRayScene->tilemapBuffers[1]);
    LZDecompressWram(gRaySceneDuoFight_Clouds3_Tilemap, sRayScene->tilemapBuffers[2]);
    LoadCompressedPalette(gRaySceneDuoFight_Clouds_Pal, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
    LoadCompressedSpriteSheet(&sSpriteSheet_DuoFight_Miko);
    LoadCompressedSpriteSheet(&sSpriteSheet_DuoFight_MikoShoulder);
    LoadCompressedSpriteSheet(&sSpriteSheet_DuoFight_MikoClaw);
    LoadCompressedSpriteSheet(&sSpriteSheet_DuoFight_CMiko);
    LoadCompressedSpriteSheet(&sSpriteSheet_DuoFight_CMikoPectoralFin);
    LoadCompressedSpriteSheet(&sSpriteSheet_DuoFight_CMikoDorsalFin);
    LoadCompressedSpritePalette(&sSpritePal_DuoFight_Miko);
    LoadCompressedSpritePalette(&sSpritePal_DuoFight_CMiko);
}

static void Task_DuoFightAnim(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    ScanlineEffect_Clear();
    InitDuoFightSceneBgs();
    LoadDuoFightSceneGfx();
    CpuFastFill16(0, gScanlineEffectRegBuffers, sizeof(gScanlineEffectRegBuffers));
    ScanlineEffect_SetParams(sScanlineParams_DuoFight_Clouds);
    tTimer = 0;
    tHelperTaskId = CreateTask(Task_DuoFight_AnimateClouds, 0);
    if (sRayScene->animId == RAY_ANIM_DUO_FIGHT_PRE)
    {
        tMikoSpriteId = DuoFightPre_CreateMikoSprites();
        tCMikoSpriteId = DuoFightPre_CreateCMikoSprites();
        gTasks[taskId].func = Task_HandleDuoFightPre;
    }
    else
    {
        tMikoSpriteId = DuoFight_CreateMikoSprites();
        tCMikoSpriteId = DuoFight_CreateCMikoSprites();
        gTasks[taskId].func = Task_HandleDuoFight;
        StopMapMusic();
    }

    BlendPalettes(PALETTES_ALL, 0x10, RGB_BLACK);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
    SetVBlankCallback(VBlankCB_DuoFight);
    PlaySE(SE_DOWNPOUR);
}

static void Task_DuoFight_AnimateClouds(u8 taskId)
{
    s16 i;
    u16 *data = (u16*)gTasks[taskId].data;

    for (i = 24; i < 92; i++)
    {
        if (i <= 47)
        {
            gScanlineEffectRegBuffers[0][i] = data[0] >> 8;
            gScanlineEffectRegBuffers[1][i] = data[0] >> 8;
        }
        else if (i <= 63)
        {
            gScanlineEffectRegBuffers[0][i] = data[1] >> 8;
            gScanlineEffectRegBuffers[1][i] = data[1] >> 8;
        }
        else if (i <= 75)
        {
            gScanlineEffectRegBuffers[0][i] = data[2] >> 8;
            gScanlineEffectRegBuffers[1][i] = data[2] >> 8;
        }
        else if (i <= 83)
        {
            gScanlineEffectRegBuffers[0][i] = data[3] >> 8;
            gScanlineEffectRegBuffers[1][i] = data[3] >> 8;
        }
        else if (i <= 87)
        {
            gScanlineEffectRegBuffers[0][i] = data[4] >> 8;
            gScanlineEffectRegBuffers[1][i] = data[4] >> 8;
        }
        else
        {
            gScanlineEffectRegBuffers[0][i] = data[5] >> 8;
            gScanlineEffectRegBuffers[1][i] = data[5] >> 8;
        }
    }

    if (sRayScene->animId == RAY_ANIM_DUO_FIGHT_PRE)
    {
        data[0] += 448;
        data[1] += 384;
        data[2] += 320;
        data[3] += 256;
        data[4] += 192;
        data[5] += 128;
    }
    else
    {
        data[0] += 768;
        data[1] += 640;
        data[2] += 512;
        data[3] += 384;
        data[4] += 256;
        data[5] += 128;
    }
}

static void Task_HandleDuoFight(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    DuoFight_AnimateRain();
    if (!gPaletteFade.active)
    {
        s16 frame = tTimer;
        if (frame == 32 || frame == 112)
        {
            DuoFight_Lightning1();
        }
        else if (frame == 216)
        {
            DuoFight_Lightning2();
        }
        else if (frame == 220)
        {
            DuoFight_LightningLong();
        }
        else
        {
            switch (frame)
            {
            case 412:
                DuoFightEnd(taskId, 2);
                return;
            case 380:
                SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_TGT2_BG1 | BLDCNT_EFFECT_BLEND);
                gTasks[tHelperTaskId].func = DuoFight_PanOffScene;
                gTasks[tHelperTaskId].data[0] = 0;
                gTasks[tHelperTaskId].data[2] = data[2];
                gTasks[tHelperTaskId].data[3] = data[3];
                ScanlineEffect_Stop();
                break;
            }
        }

        tTimer++;
    }
}

// In the below functions, BlendPalettesGradually flashes the bg white and the duo black
// and gradually fades them back to original color to simulate lightning
static void DuoFight_Lightning1(void)
{
    PlaySE(SE_THUNDER);
    BlendPalettesGradually(PALETTES_BG & ~(0x8000), 0, 16, 0, RGB_WHITEALPHA, 0, 0);
    BlendPalettesGradually(PALETTES_OBJECTS, 0, 16, 0, RGB_BLACK,      0, 1);
}

static void DuoFight_Lightning2(void)
{
    PlaySE(SE_THUNDER);
    BlendPalettesGradually(PALETTES_BG & ~(0x8000), 0, 16, 16, RGB_WHITEALPHA, 0, 0);
    BlendPalettesGradually(PALETTES_OBJECTS, 0, 16, 16, RGB_BLACK,      0, 1);
}

static void DuoFight_LightningLong(void)
{
    BlendPalettesGradually(PALETTES_BG & ~(0x8000), 4, 16, 0, RGB_WHITEALPHA, 0, 0);
    BlendPalettesGradually(PALETTES_OBJECTS, 4, 16, 0, RGB_BLACK,      0, 1);
}

static void DuoFight_AnimateRain(void)
{
    ChangeBgX(2, 0x400, BG_COORD_ADD);
    ChangeBgY(2, 0x800, BG_COORD_SUB);
}

// Only used by the full version, which pans up at the end (so scene objects move down)
// DuoFightPre just fades to black with no pan
static void DuoFight_PanOffScene(u8 taskId)
{
    u16 bgY;
    s16 *data = gTasks[taskId].data;
    DuoFight_SlideMikoDown(&gSprites[tMikoSpriteId]);
    DuoFight_SlideCMikoDown(&gSprites[tCMikoSpriteId]);

    bgY = GetBgY(1);
    if (GetBgY(1) == 0 || bgY > 0x8000)
        ChangeBgY(1, 0x400, BG_COORD_SUB);

    if (tTimer != 16)
    {
        tTimer++;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16 - tTimer, tTimer));
    }
}

static void DuoFightEnd(u8 taskId, s8 palDelay)
{
    PlaySE(SE_DOWNPOUR_STOP);
    BeginNormalPaletteFade(PALETTES_ALL, palDelay, 0, 0x10, RGB_BLACK);
    gTasks[taskId].func = Task_DuoFightEnd;
}

static void Task_DuoFightEnd(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    DuoFight_AnimateRain();
    if (!gPaletteFade.active)
    {
        DestroyTask(tHelperTaskId);
        ChangeBgY(1, 0, BG_COORD_SET);
        SetVBlankCallback(NULL);
        ScanlineEffect_Stop();
        ResetSpriteData();
        FreeAllSpritePalettes();
        tTimer = 0;
        gTasks[taskId].func = Task_SetNextAnim;
    }
}

static u8 DuoFight_CreateMikoSprites(void)
{
    u8 spriteId;
    s16 *data;

    spriteId = CreateSprite(&sSpriteTemplate_DuoFight_Miko, 98, 72, 3);
    gSprites[spriteId].callback = SpriteCB_DuoFight_Miko;
    data = gSprites[spriteId].data;
    sMikoBodySpriteId = CreateSprite(&sSpriteTemplate_DuoFight_Miko, 66, 104, 3);
    sMikoShoulderSpriteId = CreateSprite(&sSpriteTemplate_DuoFight_MikoShoulder, 85, 101, 0);
    sMikoClawSpriteId = CreateSprite(&sSpriteTemplate_DuoFight_MikoClaw, 119, 114, 1);
    StartSpriteAnim(&gSprites[sMikoBodySpriteId], 1);
    return spriteId;
}

static void SpriteCB_DuoFight_Miko(struct Sprite *sprite)
{
    s16 *data = sprite->data;
    data[5]++;
    data[5] &= 0xF;
    if (!(data[5] & 7) && sprite->x != 72)
    {
        sprite->x--;
        gSprites[sprite->sMikoBodySpriteId].x--;
        gSprites[sMikoShoulderSpriteId].x--;
        gSprites[sMikoClawSpriteId].x--;
    }

    switch (sprite->animCmdIndex)
    {
    case 0:
        gSprites[sMikoShoulderSpriteId].x2 = 0;
        gSprites[sMikoShoulderSpriteId].y2 = 0;
        gSprites[sMikoClawSpriteId].x2 = 0;
        gSprites[sMikoClawSpriteId].y2 = 0;
        break;
    case 1:
    case 3:
        gSprites[sMikoShoulderSpriteId].x2 = -1;
        gSprites[sMikoShoulderSpriteId].y2 = 0;
        gSprites[sMikoClawSpriteId].x2 = -1;
        gSprites[sMikoClawSpriteId].y2 = 0;
        break;
    case 2:
        gSprites[sMikoShoulderSpriteId].x2 = -1;
        gSprites[sMikoShoulderSpriteId].y2 = 1;
        gSprites[sMikoClawSpriteId].x2 = -2;
        gSprites[sMikoClawSpriteId].y2 = 1;
        break;
    }
}

static void DuoFight_SlideMikoDown(struct Sprite *sprite)
{
    s16 *data = sprite->data;
    if (sprite->y <= DISPLAY_HEIGHT)
    {
        sprite->y += 8;
        gSprites[sprite->sMikoBodySpriteId].y += 8;
        gSprites[sMikoShoulderSpriteId].y += 8;
        gSprites[sMikoClawSpriteId].y += 8;
    }
}

static u8 DuoFight_CreateCMikoSprites(void)
{
    u8 spriteId;
    s16 *data;

    spriteId = CreateSprite(&sSpriteTemplate_DuoFight_CMiko, 126, 96, 1);
    gSprites[spriteId].callback = SpriteCB_DuoFight_CMiko;
    data = gSprites[spriteId].data;

    data[0] = CreateSprite(&sSpriteTemplate_DuoFight_CMiko, 158, 96, 1) << 8;
    data[0] |= CreateSprite(&sSpriteTemplate_DuoFight_CMiko, 126, 112, 1);
    data[1] = CreateSprite(&sSpriteTemplate_DuoFight_CMiko, 158, 112, 1) << 8;
    data[1] |= CreateSprite(&sSpriteTemplate_DuoFight_CMiko, 126, 128, 1);
    data[2] = CreateSprite(&sSpriteTemplate_DuoFight_CMiko, 158, 128, 1) << 8;
    data[2] |= CreateSprite(&sSpriteTemplate_DuoFight_CMiko, 94, 128, 2);
    data[3] = CreateSprite(&sSpriteTemplate_DuoFight_CMiko, 126, 128, 2) << 8;
    data[3] |= CreateSprite(&sSpriteTemplate_DuoFight_CMiko, 174, 128, 0);
    data[4] = CreateSprite(&sSpriteTemplate_DuoFight_CMikoPectoralFin, 198, 132, 0) << 8;
    data[4] |= CreateSprite(&sSpriteTemplate_DuoFight_CMikoDorsalFin, 190, 120, 1);

    StartSpriteAnim(&gSprites[data[0] >> 8], 1);
    StartSpriteAnim(&gSprites[data[0] & 0xFF], 2);
    StartSpriteAnim(&gSprites[data[1] >> 8], 3);
    StartSpriteAnim(&gSprites[data[1] & 0xFF], 4);
    StartSpriteAnim(&gSprites[data[2] >> 8], 5);
    StartSpriteAnim(&gSprites[data[2] & 0xFF], 6);
    StartSpriteAnim(&gSprites[data[3] >> 8], 7);
    StartSpriteAnim(&gSprites[data[3] & 0xFF], 8);

    return spriteId;
}

static void SpriteCB_DuoFight_CMiko(struct Sprite *sprite)
{
    s16 *data = sprite->data;
    data[5]++;
    data[5] &= 0xF;
    if (!(data[5] & 7) && sprite->x != 152)
    {
        sprite->x++;
        gSprites[sprite->data[0] >> 8].x++;
        gSprites[sprite->data[0] & 0xFF].x++;
        gSprites[data[1] >> 8].x++;
        gSprites[data[1] & 0xFF].x++;
        gSprites[data[2] >> 8].x++;
        gSprites[data[2] & 0xFF].x++;
        gSprites[data[3] >> 8].x++;
        gSprites[data[3] & 0xFF].x++;
        gSprites[data[4] >> 8].x++;
        gSprites[data[4] & 0xFF].x++;
    }

    switch (gSprites[data[2] & 0xFF].animCmdIndex)
    {
    case 0:
        sprite->y2 = 0;
        gSprites[data[0] >> 8].y2 = 0;
        gSprites[data[0] & 0xFF].y2 = 0;
        gSprites[data[1] >> 8].y2 = 0;
        gSprites[data[1] & 0xFF].y2 = 0;
        gSprites[data[2] >> 8].y2 = 0;
        gSprites[data[2] & 0xFF].y2 = 0;
        gSprites[data[3] >> 8].y2 = 0;
        gSprites[data[3] & 0xFF].y2 = 0;
        gSprites[data[4] >> 8].y2 = 0;
        gSprites[data[4] & 0xFF].y2 = 0;
        break;
    case 1:
    case 3:
        sprite->y2 = 1;
        gSprites[data[0] >> 8].y2 = 1;
        gSprites[data[0] & 0xFF].y2 = 1;
        gSprites[data[1] >> 8].y2 = 1;
        gSprites[data[1] & 0xFF].y2 = 1;
        gSprites[data[2] >> 8].y2 = 1;
        gSprites[data[2] & 0xFF].y2 = 1;
        gSprites[data[3] >> 8].y2 = 1;
        gSprites[data[3] & 0xFF].y2 = 1;
        gSprites[data[4] >> 8].y2 = 1;
        gSprites[data[4] & 0xFF].y2 = 1;
        break;
    case 2:
        sprite->y2 = 2;
        gSprites[data[0] >> 8].y2 = 2;
        gSprites[data[0] & 0xFF].y2 = 2;
        gSprites[data[1] >> 8].y2 = 2;
        gSprites[data[1] & 0xFF].y2 = 2;
        gSprites[data[2] >> 8].y2 = 2;
        gSprites[data[4] & 0xFF].y2 = 2;
        break;
    }
}

static void DuoFight_SlideCMikoDown(struct Sprite *sprite)
{
    s16 *data = sprite->data;
    if (sprite->y <= DISPLAY_HEIGHT)
    {
        sprite->y += 8;
        gSprites[sprite->data[0] >> 8].y += 8;
        gSprites[sprite->data[0] & 0xFF].y += 8;
        gSprites[data[1] >> 8].y += 8;
        gSprites[data[1] & 0xFF].y += 8;
        gSprites[data[2] >> 8].y += 8;
        gSprites[data[2] & 0xFF].y += 8;
        gSprites[data[3] >> 8].y += 8;
        gSprites[data[3] & 0xFF].y += 8;
        gSprites[data[4] >> 8].y += 8;
        gSprites[data[4] & 0xFF].y += 8;
    }
}

#undef tTimer
#undef tHelperTaskId
#undef tMikoSpriteId
#undef tCMikoSpriteId

#undef sMikoBodySpriteId
#undef sMikoShoulderSpriteId
#undef sMikoClawSpriteId


// RAY_ANIM_TAKES_FLIGHT

#define tState      data[0]
#define tTimer      data[1]
#define tScale      data[2]
#define tScaleSpeed data[3]
#define tYCoord     data[4]
#define tYSpeed     data[5]
#define tYOffset    data[6]
#define tYOffsetDir data[7]

static void InitTakesFlightSceneBgs(void)
{
    ResetVramOamAndBgCntRegs();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(1, sBgTemplates_TakesFlight, ARRAY_COUNT(sBgTemplates_TakesFlight));
    SetBgTilemapBuffer(0, sRayScene->tilemapBuffers[0]);
    SetBgTilemapBuffer(1, sRayScene->tilemapBuffers[1]);
    SetBgTilemapBuffer(2, sRayScene->tilemapBuffers[2]);
    ResetAllBgsCoordinates();
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static void LoadTakesFlightSceneGfx(void)
{
    ResetTempTileDataBuffers();
    DecompressAndCopyTileDataToVram(0, gRaySceneDuoFight_Clouds_Gfx, 0, 0, 0); // Re-uses clouds from previous scene
    DecompressAndCopyTileDataToVram(1, gRaySceneTakesFlight_Bg_Gfx, 0, 0, 0);
    DecompressAndCopyTileDataToVram(2, gRaySceneTakesFlight_CMamizou_Gfx, 0, 0, 0);
    while (FreeTempTileDataBuffersIfPossible())
        ;
    LZDecompressWram(gRaySceneDuoFight_Clouds2_Tilemap, sRayScene->tilemapBuffers[0]);
    LZDecompressWram(gRaySceneTakesFlight_Bg_Tilemap, sRayScene->tilemapBuffers[1]);
    LZDecompressWram(gRaySceneTakesFlight_CMamizou_Tilemap, sRayScene->tilemapBuffers[2]);
    LoadCompressedPalette(gRaySceneTakesFlight_CMamizou_Pal, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
    LoadCompressedSpriteSheet(&sSpriteSheet_TakesFlight_Smoke);
    LoadCompressedSpritePalette(&sSpritePal_TakesFlight_Smoke);
}

static void Task_RayTakesFlightAnim(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    PlayNewMapMusic(MUS_CMAMIZOU_APPEARS);
    InitTakesFlightSceneBgs();
    LoadTakesFlightSceneGfx();
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_OBJ | BLDCNT_TGT2_BG1 | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(8, 8));
    BlendPalettes(PALETTES_ALL, 16, 0);
    SetVBlankCallback(VBlankCB_CMamizouScene);
    CreateTask(Task_TakesFlight_CreateSmoke, 0);
    tState = 0;
    tTimer = 0;
    gTasks[taskId].func = Task_HandleRayTakesFlight;
}

// Animate CMamizou (flying up and down, and changing size as it gets further from the screen)
// In this scene CMamizou is a bg tilemap on bg 2, not a sprite
static void Task_HandleRayTakesFlight(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (tState)
    {
    case 0:
        // Delay, then fade in
        if (tTimer == 8)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
            tScale = 0;
            tScaleSpeed = 30;
            tYCoord = 0;
            tYSpeed = 7;
            tTimer = 0;
            tState++;
        }
        else
        {
            tTimer++;
        }
        break;
    case 1:
        // Fly in
        tScale += tScaleSpeed;
        tYCoord += tYSpeed;

        if (tScaleSpeed > 3)
            tScaleSpeed -= 3;

        if (tYSpeed != 0)
            tYSpeed--;

        if (tScale > 255)
        {
            tScale = 256;
            tScaleSpeed = 0;
            tYOffset = 12;
            tYOffsetDir = -1;
            tTimer = 0;
            tState++;
        }
        SetBgAffine(2, 0x7800, 0x1800, 120, tYCoord + 32, tScale, tScale, 0);
        break;
    case 2:
        // Float up and down
        tTimer++;
        SetBgAffine(2, 0x7800, 0x1800, 120, tYCoord + 32 + (tYOffset >> 2), tScale, tScale, 0);
        tYOffset += tYOffsetDir;
        if (tYOffset == 12 || tYOffset == -12)
        {
            tYOffsetDir *= -1;
            if (tTimer > 295)
            {
                tState++;
                BeginNormalPaletteFade(PALETTES_ALL, 6, 0, 0x10, RGB_BLACK);
            }
        }
        break;
    case 3:
        // Fly away, fade out
        tScale += 16;
        SetBgAffine(2, 0x7800, 0x1800, 120, tYCoord + 32, tScale, tScale, 0);
        Task_RayTakesFlightEnd(taskId);
        break;
    }
}

#undef tState
#undef tTimer
#undef tScale
#undef tScaleSpeed
#undef tYCoord
#undef tYSpeed
#undef tYOffset
#undef tYOffsetDir

static void Task_RayTakesFlightEnd(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetVBlankCallback(NULL);
        ResetSpriteData();
        FreeAllSpritePalettes();
        gTasks[taskId].func = Task_SetNextAnim;
    }
}

#define tSmokeId data[0]
#define tTimer   data[1]

#define sSmokeId data[0]
#define sTimer   data[1]

static void Task_TakesFlight_CreateSmoke(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if ((tTimer & 3) == 0)
    {
        u8 spriteId = CreateSprite(&sSpriteTemplate_TakesFlight_Smoke,
                                   (sTakesFlight_SmokeCoords[tSmokeId][0] * 4) + 120,
                                   (sTakesFlight_SmokeCoords[tSmokeId][1] * 4) + 80,
                                   0);
        gSprites[spriteId].sSmokeId = (s8)(tSmokeId);
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_DOUBLE;
        gSprites[spriteId].oam.priority = 2;
        InitSpriteAffineAnim(&gSprites[spriteId]);
        if (tSmokeId == MAX_SMOKE - 1)
        {
            DestroyTask(taskId);
            return;
        }
        else
        {
            tSmokeId++;
        }
    }

    tTimer++;
}

#undef tSmokeId
#undef tTimer

static void SpriteCB_TakesFlight_Smoke(struct Sprite *sprite)
{
    if (sprite->sTimer == 0)
    {
        sprite->x2 = 0;
        sprite->y2 = 0;
    }
    else
    {
        sprite->x2 += sTakesFlight_SmokeCoords[sprite->sSmokeId][0];
        sprite->y2 += sTakesFlight_SmokeCoords[sprite->sSmokeId][1];
    }

    sprite->sTimer++;
    sprite->sTimer &= 0xF;
}

#undef sSmokeId
#undef sTimer


// RAY_ANIM_DESCENDS

static void InitDescendsSceneBgs(void)
{
    ResetVramOamAndBgCntRegs();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates_Descends, ARRAY_COUNT(sBgTemplates_Descends));
    SetBgTilemapBuffer(0, sRayScene->tilemapBuffers[0]);
    SetBgTilemapBuffer(1, sRayScene->tilemapBuffers[1]);
    SetBgTilemapBuffer(2, sRayScene->tilemapBuffers[2]);
    SetBgTilemapBuffer(3, sRayScene->tilemapBuffers[3]);
    ResetAllBgsCoordinates();
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    ScheduleBgCopyTilemapToVram(3);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static void LoadDescendsSceneGfx(void)
{
    ResetTempTileDataBuffers();
    DecompressAndCopyTileDataToVram(0, gRaySceneDescends_Light_Gfx, 0, 0, 0);
    DecompressAndCopyTileDataToVram(1, gRaySceneDescends_Bg_Gfx, 0, 0, 0);
    while (FreeTempTileDataBuffersIfPossible())
        ;
    LZDecompressWram(gRaySceneDescends_Light_Tilemap, sRayScene->tilemapBuffers[0]);
    LZDecompressWram(gRaySceneDescends_Bg_Tilemap, sRayScene->tilemapBuffers[3]);
    CpuFastFill16(0, sRayScene->tilemapBuffers[2], BG_SCREEN_SIZE);
    CpuFastCopy(sRayScene->tilemapBuffers[3], sRayScene->tilemapBuffers[1], BG_SCREEN_SIZE);
    CpuFastFill16(0, &sRayScene->tilemapBuffers[1][0x100], 0x340);

    LoadCompressedPalette(gRaySceneDescends_Bg_Pal, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
    gPlttBufferUnfaded[0] = RGB_WHITE;
    gPlttBufferFaded[0] = RGB_WHITE;
    LoadCompressedSpriteSheet(&sSpriteSheet_Descends_CMamizou);
    LoadCompressedSpriteSheet(&sSpriteSheet_Descends_CMamizouTail);
    LoadCompressedSpritePalette(&sSpritePal_Descends_CMamizou);
}

// Draw ray of light emerging from the clouds
static void HBlankCB_RayDescends(void)
{
    u16 vcount = GetGpuReg(REG_OFFSET_VCOUNT);
    if (vcount >= 24 && vcount <= 135 && vcount - 24 <= sRayScene->revealedLightLine)
        REG_BLDALPHA = 0xD08; // This line is above where light has been revealed, draw it
    else
        REG_BLDALPHA = 0x1000; // Below where light has been revealed, hide it

    if (vcount == 0)
    {
        if (sRayScene->revealedLightLine <= 0x1FFF)
        {
            // Increase the number of pixel rows of the light that have been revealed
            // Gradually slows as it reaches the bottom
            if (sRayScene->revealedLightLine <= 39)
                sRayScene->revealedLightLine += 4;
            else if (sRayScene->revealedLightLine <= 79)
                sRayScene->revealedLightLine += 2;
            else
                sRayScene->revealedLightLine += 1;
        }

        // Pointless
        sRayScene->revealedLightTimer++;
    }
}

#define tState data[0]
#define tTimer data[1]

static void Task_RayDescendsAnim(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    InitDescendsSceneBgs();
    LoadDescendsSceneGfx();
    SetGpuRegBits(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    BlendPalettes(PALETTES_ALL, 0x10, RGB_BLACK);
    SetVBlankCallback(VBlankCB_CMamizouScene);
    sRayScene->revealedLightLine = 0;
    sRayScene->revealedLightTimer = 0;
    tState = 0;
    tTimer = 0;
    data[2] = 0; // Below data assignments do nothing
    data[3] = 0;
    data[4] = 0x1000;
    gTasks[taskId].func = Task_HandleRayDescends;
}

static void Task_HandleRayDescends(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (tState)
    {
    case 0:
        // Delay, then fade in
        if (tTimer == 8)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
            tTimer = 0;
            tState++;
        }
        else
        {
            tTimer++;
        }
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            // Delay, then start ray of light
            if (tTimer == 10)
            {
                tTimer = 0;
                tState++;
                SetHBlankCallback(HBlankCB_RayDescends);
                EnableInterrupts(INTR_FLAG_HBLANK | INTR_FLAG_VBLANK);
            }
            else
            {
                tTimer++;
            }
        }
        break;
    case 2:
        // Delay, then start CMamizou emerging from clouds
        if (tTimer == 80)
        {
            tTimer = 0;
            tState++;
            CreateDescendsCMamizouSprite();
        }
        else
        {
            tTimer++;
        }
        break;
    case 3:
        // Wait while CMamizou descends
        if (++tTimer == 368)
        {
            tTimer = 0;
            tState++;
        }
        break;
    case 4:
        // Fade out
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
        gTasks[taskId].func = Task_RayDescendsEnd;
        break;
    }
}

static void Task_RayDescendsEnd(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetVBlankCallback(NULL);
        SetHBlankCallback(NULL);
        ResetSpriteData();
        FreeAllSpritePalettes();
        gTasks[taskId].func = Task_SetNextAnim;
    }
}

#define sTailSpriteId data[0]
#define sTimer        data[2]
#define sXMovePeriod  data[3]
#define sYMovePeriod  data[4]

static u8 CreateDescendsCMamizouSprite(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_Descends_CMamizou, 160, 0, 0);
    s16 *data = gSprites[spriteId].data;
    sTailSpriteId = CreateSprite(&sSpriteTemplate_Descends_CMamizouTail, 184, -48, 0);
    gSprites[spriteId].callback = SpriteCB_Descends_CMamizou;
    gSprites[spriteId].oam.priority = 3;
    gSprites[sTailSpriteId].oam.priority = 3;
    return spriteId;
}

static void SpriteCB_Descends_CMamizou(struct Sprite *sprite)
{
    s16 *data = sprite->data;
    s16 frame = sTimer;

    // Updates to CMamizou's coords occur more frequently
    // as time goes on (it accelerates as it emerges)
    if (frame == 0)
    {
        sXMovePeriod = 12;
        sYMovePeriod = 8;
    }
    else if (frame == 256)
    {
        sXMovePeriod = 9;
        sYMovePeriod = 7;
    }
    else if (frame == 268)
    {
        sXMovePeriod = 8;
        sYMovePeriod = 6;
    }
    else if (frame == 280)
    {
        sXMovePeriod = 7;
        sYMovePeriod = 5;
    }
    else if (frame == 292)
    {
        sXMovePeriod = 6;
        sYMovePeriod = 4;
    }
    else if (frame == 304)
    {
        sXMovePeriod = 5;
        sYMovePeriod = 3;
    }
    else if (frame == 320)
    {
        sXMovePeriod = 4;
        sYMovePeriod = 2;
    }

    if (sTimer % sXMovePeriod == 0)
    {
        sprite->x2--;
        gSprites[sTailSpriteId].x2--;
    }
    if (sTimer % sYMovePeriod == 0)
    {
        sprite->y2++;
        gSprites[sTailSpriteId].y2++;
    }

    sTimer++;
}

#undef sTailSpriteId
#undef sTimer
#undef sXMovePeriod
#undef sYMovePeriod


// RAY_ANIM_CHARGES

static void InitChargesSceneBgs(void)
{
    ResetVramOamAndBgCntRegs();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates_Charges, ARRAY_COUNT(sBgTemplates_Charges));
    SetBgTilemapBuffer(0, sRayScene->tilemapBuffers[0]);
    SetBgTilemapBuffer(1, sRayScene->tilemapBuffers[1]);
    SetBgTilemapBuffer(2, sRayScene->tilemapBuffers[2]);
    SetBgTilemapBuffer(3, sRayScene->tilemapBuffers[3]);
    ResetAllBgsCoordinates();
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    ScheduleBgCopyTilemapToVram(3);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP | DISPCNT_WIN0_ON);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static void LoadChargesSceneGfx(void)
{
    ResetTempTileDataBuffers();
    DecompressAndCopyTileDataToVram(1, gRaySceneCharges_CMamizou_Gfx, 0, 0, 0);
    DecompressAndCopyTileDataToVram(2, gRaySceneCharges_Streaks_Gfx, 0, 0, 0);
    DecompressAndCopyTileDataToVram(3, gRaySceneCharges_Bg_Gfx, 0, 0, 0);
    while (FreeTempTileDataBuffersIfPossible())
        ;
    LZDecompressWram(gRaySceneCharges_Orbs_Tilemap, sRayScene->tilemapBuffers[0]);
    LZDecompressWram(gRaySceneCharges_CMamizou_Tilemap, sRayScene->tilemapBuffers[1]);
    LZDecompressWram(gRaySceneCharges_Streaks_Tilemap, sRayScene->tilemapBuffers[2]);
    LZDecompressWram(gRaySceneCharges_Bg_Tilemap, sRayScene->tilemapBuffers[3]);
    LoadCompressedPalette(gRaySceneCharges_Bg_Pal, BG_PLTT_ID(0), 4 * PLTT_SIZE_4BPP);
}

#define tState          data[0]
#define tTimer          data[1]
#define tCMamizouTaskId data[2]
#define tSoundTimer     data[3]

static void Task_RayChargesAnim(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    InitChargesSceneBgs();
    LoadChargesSceneGfx();
    SetWindowsHideVertBorders();
    BlendPalettes(PALETTES_ALL, 0x10, RGB_BLACK);
    SetVBlankCallback(VBlankCB_CMamizouScene);
    tState = 0;
    tTimer = 0;
    tCMamizouTaskId = CreateTask(Task_RayCharges_ShakeCMamizou, 0);
    gTasks[taskId].func = Task_HandleRayCharges;
}

static void Task_HandleRayCharges(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    RayCharges_AnimateBg();
    if ((tSoundTimer & 7) == 0 && tState <= 1 && tTimer <= 89)
        PlaySE(SE_INTRO_BLAST);

    tSoundTimer++;
    switch (tState)
    {
    case 0:
        // Delay, then fade in
        if (tTimer == 8)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
            tTimer = 0;
            tState++;
        }
        else
        {
            tTimer++;
        }
        break;
    case 1:
        // Delay while CMamizou shakes, then start CMamizou moving offscreen
        if (tTimer == 127)
        {
            tTimer = 0;
            tState++;
            gTasks[tCMamizouTaskId].func = Task_RayCharges_FlyOffscreen;
        }
        else
        {
            tTimer++;
        }
        break;
    case 2:
        // Delay for CMamizou's flying animation
        if (tTimer == 12)
        {
            tTimer = 0;
            tState++;
        }
        else
        {
            tTimer++;
        }
        break;
    case 3:
        // Fade out
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
        gTasks[taskId].func = Task_RayChargesEnd;
        break;
    }
}

#undef tState
#undef tTimer
#undef tSoundTimer

#define tState    data[0]
#define tOffset   data[1]
#define tShakeDir data[2]
#define tTimer    data[15]

static void Task_RayCharges_ShakeCMamizou(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if ((tTimer & 3) == 0)
    {
        ChangeBgX(1, (Random() % 8 - 4) << 8, BG_COORD_SET);
        ChangeBgY(1, (Random() % 8 - 4) << 8, BG_COORD_SET);
    }

    tTimer++;
}

// CMamizou backs up then launches forward
static void Task_RayCharges_FlyOffscreen(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (tState == 0)
    {
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        tState++;
        tOffset = 10;
        tShakeDir = -1;
    }
    else if (tState == 1)
    {
        ChangeBgX(1, tOffset << 8, BG_COORD_SUB);
        ChangeBgY(1, tOffset << 8, BG_COORD_ADD);
        tOffset += tShakeDir;
        if (tOffset == -10)
            tShakeDir *= -1;
    }
}

#undef tState
#undef tOffset
#undef tShakeDir
#undef tTimer

static void RayCharges_AnimateBg(void)
{
    // Update yellow orbs
    ChangeBgX(2, 0x400, BG_COORD_SUB);
    ChangeBgY(2, 0x400, BG_COORD_ADD);

    // Update blue streaks
    ChangeBgX(0, 0x800, BG_COORD_SUB);
    ChangeBgY(0, 0x800, BG_COORD_ADD);
}

static void Task_RayChargesEnd(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    RayCharges_AnimateBg();
    if (!gPaletteFade.active)
    {
        SetVBlankCallback(NULL);
        ResetWindowDimensions();
        DestroyTask(tCMamizouTaskId);
        gTasks[taskId].func = Task_SetNextAnim;
    }
}

#undef tCMamizouTaskId


// RAY_ANIM_CHASES_AWAY

static void InitChasesAwaySceneBgs(void)
{
    ResetVramOamAndBgCntRegs();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(1, sBgTemplates_ChasesAway, ARRAY_COUNT(sBgTemplates_ChasesAway));
    SetBgTilemapBuffer(0, sRayScene->tilemapBuffers[0]);
    SetBgTilemapBuffer(1, sRayScene->tilemapBuffers[1]);
    SetBgTilemapBuffer(2, sRayScene->tilemapBuffers[2]);
    ResetAllBgsCoordinates();
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP | DISPCNT_WIN0_ON);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static void LoadChasesAwaySceneGfx(void)
{
    ResetTempTileDataBuffers();
    DecompressAndCopyTileDataToVram(2, gRaySceneChasesAway_Ring_Gfx, 0, 0, 0);
    DecompressAndCopyTileDataToVram(0, gRaySceneChasesAway_Light_Gfx, 0, 0, 0);
    while (FreeTempTileDataBuffersIfPossible())
        ;
    LZDecompressWram(gRaySceneChasesAway_Bg_Tilemap, sRayScene->tilemapBuffers[1]);
    LZDecompressWram(gRaySceneChasesAway_Light_Tilemap, sRayScene->tilemapBuffers[0]);
    LZDecompressWram(gRaySceneChasesAway_Ring_Tilemap, sRayScene->tilemapBuffers[2]);
    LoadCompressedPalette(gRaySceneChasesAway_Bg_Pal, BG_PLTT_ID(0), 3 * PLTT_SIZE_4BPP);
    LoadCompressedSpriteSheet(&sSpriteSheet_ChasesAway_Miko);
    LoadCompressedSpriteSheet(&sSpriteSheet_ChasesAway_MikoTail);
    LoadCompressedSpriteSheet(&sSpriteSheet_ChasesAway_CMiko);
    LoadCompressedSpriteSheet(&sSpriteSheet_ChasesAway_CMamizou);
    LoadCompressedSpriteSheet(&sSpriteSheet_ChasesAway_CMamizouTail);
    LoadCompressedSpriteSheet(&sSpriteSheet_ChasesAway_CMikoSplash);
    LoadCompressedSpritePalette(&sSpritePal_ChasesAway_Miko);
    LoadCompressedSpritePalette(&sSpritePal_ChasesAway_CMiko);
    LoadCompressedSpritePalette(&sSpritePal_ChasesAway_CMamizou);
    LoadCompressedSpritePalette(&sSpritePal_ChasesAway_CMikoSplash);
}

#define tState    data[0]
#define tTimer    data[1]
#define tBgTaskId data[2]

static void Task_RayChasesAwayAnim(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    InitChasesAwaySceneBgs();
    LoadChasesAwaySceneGfx();
    SetWindowsHideVertBorders();
    ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG2_ON);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(9, 14));
    BlendPalettes(PALETTES_ALL, 0x10, RGB_BLACK);
    SetVBlankCallback(VBlankCB_CMamizouScene);
    tState = 0;
    tTimer = 0;
    gTasks[taskId].func = Task_HandleRayChasesAway;
    tBgTaskId = CreateTask(Task_ChasesAway_AnimateBg, 0);
    gTasks[tBgTaskId].data[0] = 0;
    gTasks[tBgTaskId].data[1] = 0;
    gTasks[tBgTaskId].data[2] = 0;
    gTasks[tBgTaskId].data[3] = 1;
    gTasks[tBgTaskId].data[4] = 1;
}

static void Task_HandleRayChasesAway(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (tState)
    {
    case 0:
        // Delay, then fade in
        if (tTimer == 8)
        {
            ChasesAway_CreateTrioSprites(taskId);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
            tTimer = 0;
            tState++;
        }
        else
        {
            tTimer++;
        }
        break;
    case 1:
        // Wait for CMamizou to enter and finish shout anim
        if (gSprites[data[5]].callback == SpriteCB_ChasesAway_CMamizouFloat)
        {
            // Delay, then start Miko/CMiko leaving
            if (tTimer == 64)
            {
                ChasesAway_CMikoStartLeave(taskId);
                ChasesAway_MikoStartLeave(taskId);
                tTimer = 0;
                tState++;
            }
            else
            {
                tTimer++;
            }
        }
        break;
    case 2:
        // Wait for Miko/CMiko to leave
        if (tTimer == 448)
        {
            tTimer = 0;
            tState++;
        }
        else
        {
            // Flash bg white and trio black a few times
            tTimer++;
            if (tTimer % 144 == 0)
            {
                BlendPalettesGradually(PALETTES_BG & ~1, 0, 16, 0, RGB_WHITEALPHA, 0, 0);
                BlendPalettesGradually(PALETTES_OBJECTS, 0, 16, 0, RGB_BLACK,      0, 1);
            }
        }
        break;
    case 3:
        // Fade out
        BeginNormalPaletteFade(PALETTES_ALL, 4, 0, 0x10, RGB_BLACK);
        gTasks[taskId].func = Task_RayChasesAwayEnd;
        break;
    }
}

#undef tState
#undef tTimer

#define tTimer      data[0]
#define tBlendHi    data[1]
#define tBlendLo    data[2]
#define tBlendHiDir data[3]
#define tBlendLoDir data[4]

// Flickers the ray of light behind CMamizou
static void Task_ChasesAway_AnimateBg(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if ((tTimer & 0xF) == 0)
    {
        SetGpuReg(REG_OFFSET_BLDALPHA, ((tBlendHi + 14) << 8 & 0x1F00) | ((tBlendLo + 9) & 0xF));
        tBlendHi -= tBlendHiDir;
        tBlendLo += tBlendLoDir;
        if (tBlendHi == -3 || tBlendHi == 0)
            tBlendHiDir *= -1;
        if (tBlendLo == 3 || tBlendLo == 0)
            tBlendLoDir *= -1;
    }

    tTimer++;
}

#undef tTimer
#undef tBlendHi
#undef tBlendLo
#undef tBlendHiDir
#undef tBlendLoDir

#define tTimer data[1]

static void Task_RayChasesAwayEnd(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        StopMapMusic();
        if (tTimer == 0)
        {
            SetVBlankCallback(NULL);
            ResetWindowDimensions();
            ResetSpriteData();
            FreeAllSpritePalettes();
            DestroyTask(tBgTaskId);
        }

        if (tTimer == 32)
        {
            tTimer = 0;
            gTasks[taskId].func = Task_SetNextAnim;
        }
        else
        {
            tTimer++;
        }
    }
}

#undef tTimer
#undef tBgTaskId

#define tMikoSpriteId  taskData[3]
#define tCMikoSpriteId   taskData[4]
#define tCMamizouSpriteId taskData[5]

static void ChasesAway_CreateTrioSprites(u8 taskId)
{
    s16 *taskData, *spriteData;

    taskData = gTasks[taskId].data;

    tMikoSpriteId = CreateSprite(&sSpriteTemplate_ChasesAway_Miko, 64, 120, 0);
    spriteData = gSprites[tMikoSpriteId].data;
    spriteData[0] = CreateSprite(&sSpriteTemplate_ChasesAway_MikoTail, 16, 130, 0);
    gSprites[tMikoSpriteId].oam.priority = 1;
    gSprites[spriteData[0]].oam.priority = 1;

    tCMikoSpriteId = CreateSprite(&sSpriteTemplate_ChasesAway_CMiko, 160, 128, 1);
    spriteData = gSprites[tCMikoSpriteId].data;
    spriteData[0] = CreateSprite(&sSpriteTemplate_ChasesAway_CMiko, 192, 128, 1);
    spriteData[1] = CreateSprite(&sSpriteTemplate_ChasesAway_CMiko, 224, 128, 1);
    gSprites[tCMikoSpriteId].oam.priority = 1;
    gSprites[spriteData[0]].oam.priority = 1;
    gSprites[spriteData[1]].oam.priority = 1;
    StartSpriteAnim(&gSprites[spriteData[0]], 1);
    StartSpriteAnim(&gSprites[spriteData[1]], 2);

    tCMamizouSpriteId = CreateSprite(&sSpriteTemplate_ChasesAway_CMamizou, 120, -65, 0);
    spriteData = gSprites[tCMamizouSpriteId].data;
    spriteData[0] = CreateSprite(&sSpriteTemplate_ChasesAway_CMamizouTail, 120, -113, 0);
    gSprites[tCMamizouSpriteId].oam.priority = 1;
    gSprites[spriteData[0]].oam.priority = 1;
}

#define sBodyPartSpriteId1 data[0]
#define sBodyPartSpriteId2 data[1]
#define sTimer             data[4]
#define sDecel             data[5]
#define sSpeed             data[6]
#define sIsCMiko          data[7]

static void ChasesAway_PushDuoBack(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;

    gSprites[tMikoSpriteId].callback = SpriteCB_ChasesAway_DuoRingPush;
    gSprites[tMikoSpriteId].sTimer = 0;
    gSprites[tMikoSpriteId].sDecel = 0;
    gSprites[tMikoSpriteId].sSpeed = 4;
    gSprites[tMikoSpriteId].sIsCMiko = FALSE;

    gSprites[tCMikoSpriteId].callback = SpriteCB_ChasesAway_DuoRingPush;
    gSprites[tCMikoSpriteId].sTimer = 0;
    gSprites[tCMikoSpriteId].sDecel = 0;
    gSprites[tCMikoSpriteId].sSpeed = 4;
    gSprites[tCMikoSpriteId].sIsCMiko = TRUE;
}

// Pushes Miko/CMiko back slightly, for when CMamizou's hyper voice ring comes out
static void SpriteCB_ChasesAway_DuoRingPush(struct Sprite *sprite)
{
    if ((sprite->sTimer & 7) == 0)
    {
        if (!sprite->sIsCMiko)
        {
            sprite->x -= sprite->sSpeed;
            gSprites[sprite->sBodyPartSpriteId1].x -= sprite->sSpeed;
        }
        else
        {
            sprite->x += sprite->sSpeed;
            gSprites[sprite->sBodyPartSpriteId1].x += sprite->sSpeed;
            gSprites[sprite->sBodyPartSpriteId2].x += sprite->sSpeed;
        }

        sprite->sDecel++;
        sprite->sSpeed -= sprite->sDecel;
        if (sprite->sDecel == 3)
        {
            sprite->sTimer = 0;
            sprite->sDecel = 0;
            sprite->sSpeed = 0;
            sprite->callback = SpriteCallbackDummy;
            return;
        }
    }

    sprite->sTimer++;
}

#undef sBodyPartSpriteId1
#undef sBodyPartSpriteId2
#undef sTimer
#undef sDecel
#undef sSpeed
#undef sIsCMiko

static void ChasesAway_MikoStartLeave(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    gSprites[tMikoSpriteId].callback = SpriteCB_ChasesAway_MikoLeave;
    StartSpriteAnim(&gSprites[tMikoSpriteId], 1);
}

static void SpriteCB_ChasesAway_MikoLeave(struct Sprite *sprite)
{
    switch (sprite->animCmdIndex)
    {
    case 0:
    case 2:
        if (sprite->animDelayCounter % 12 == 0)
        {
            sprite->x -= 2;
            gSprites[sprite->data[0]].x -=2;
        }
        gSprites[sprite->data[0]].y2 = 0;
        break;
    case 1:
    case 3:
        gSprites[sprite->data[0]].y2 = -2;
        if ((sprite->animDelayCounter & 15) == 0)
        {
            sprite->y++;
            gSprites[sprite->data[0]].y++;
        }
        break;
    }
}

static void ChasesAway_CMikoStartLeave(u8 taskId)
{
    s16 *taskData, *spriteData;

    taskData = gTasks[taskId].data;
    spriteData = gSprites[tCMikoSpriteId].data;

    gSprites[tCMikoSpriteId].callback = SpriteCB_ChasesAway_CMikoLeave;
    gSprites[spriteData[0]].callback = SpriteCB_ChasesAway_CMikoLeave;
    gSprites[spriteData[1]].callback = SpriteCB_ChasesAway_CMikoLeave;
}

static void SpriteCB_ChasesAway_CMikoLeave(struct Sprite *sprite)
{
    if ((sprite->data[4] & 3) == 0)
    {
        if (sprite->x2 == 1)
            sprite->x2 = -1;
        else
            sprite->x2 = 1;
    }
    if (sprite->data[5] == 128)
    {
        sprite->data[7] = CreateSprite(&sSpriteTemplate_ChasesAway_CMikoSplash, 152, 132, 0);
        gSprites[sprite->data[7]].oam.priority = 1;
        sprite->data[7] = CreateSprite(&sSpriteTemplate_ChasesAway_CMikoSplash, 224, 132, 0);
        gSprites[sprite->data[7]].oam.priority = 1;
        gSprites[sprite->data[7]].hFlip = 1;
        sprite->data[5]++;
    }
    if (sprite->data[5] > 127)
    {
        if (sprite->y2 != 32)
        {
            sprite->data[6]++;
            sprite->y2 = sprite->data[6] >> 4;
        }
    }
    else
    {
        sprite->data[5]++;
    }

    if (sprite->data[4] % 64 == 0)
        PlaySE(SE_M_WHIRLPOOL);

    sprite->data[4]++;
}

#define sTailSpriteId data[0]
#define sYOffset      data[4]
#define sYOffsetDir   data[5]
#define sFloatTimer   data[6]
#define sTimer        data[7]

#define sTailFloatDelay  data[4]
#define sTailFloatPeak   data[5]

static void SpriteCB_ChasesAway_CMamizou(struct Sprite *sprite)
{
    s16 frame = sprite->sTimer;
    if (frame <= 64)
    {
        sprite->y2 += 2;
        gSprites[sprite->sTailSpriteId].y2 += 2;
        if (sprite->sTimer == 64)
        {
            ChasesAway_SetCMamizouAnim(sprite, 1, 0, -48);
            sprite->sYOffset = 5;
            sprite->sYOffsetDir = -1;
            gSprites[sprite->sTailSpriteId].sTailFloatDelay = 3;
            gSprites[sprite->sTailSpriteId].sTailFloatPeak = 5;
        }
    }
    else if (frame <= 111)
    {
        SpriteCB_ChasesAway_CMamizouFloat(sprite);
        if (sprite->sYOffset == 0)
            PlaySE(SE_MUGSHOT);
        if (sprite->sYOffset == -3)
            ChasesAway_SetCMamizouAnim(sprite, 2, 48, 16);
    }
    else if (frame == 112)
    {
        gSprites[sprite->sTailSpriteId].sTailFloatDelay = 7;
        gSprites[sprite->sTailSpriteId].sTailFloatPeak = 3;
        SpriteCB_ChasesAway_CMamizouFloat(sprite);
    }
    else if (frame <= 327)
    {
        SpriteCB_ChasesAway_CMamizouFloat(sprite);
    }
    else if (frame == 328)
    {
        SpriteCB_ChasesAway_CMamizouFloat(sprite);
        ChasesAway_SetCMamizouAnim(sprite, 3, 48, 16);
        sprite->x2 = 1;
        gSprites[sprite->sTailSpriteId].x2 = 1;
        PlayCry_Normal(SPECIES_CMAMIZOU, 0);
        CreateTask(Task_ChasesAway_AnimateRing, 0);
    }
    else
    {
        switch (frame)
        {
        case 376:
            sprite->x2 = 0;
            gSprites[sprite->sTailSpriteId].x2 = 0;
            SpriteCB_ChasesAway_CMamizouFloat(sprite);
            ChasesAway_SetCMamizouAnim(sprite, 2, 48, 16);
            sprite->callback = SpriteCB_ChasesAway_CMamizouFloat;
            return;
        case 352:
            ChasesAway_PushDuoBack(FindTaskIdByFunc(Task_HandleRayChasesAway));
            break;
        }
    }

    if (sprite->sTimer > 328 && (sprite->sTimer & 1) == 0)
    {
        sprite->x2 *= -1;
        gSprites[sprite->sTailSpriteId].x2 = sprite->x2;
    }

    sprite->sTimer++;
}

static void SpriteCB_ChasesAway_CMamizouFloat(struct Sprite *body)
{
    struct Sprite *tail = &gSprites[body->sTailSpriteId];
    if (!(body->sFloatTimer & tail->sTailFloatDelay))
    {
        body->y2 += body->sYOffset;
        gSprites[body->sTailSpriteId].y2 += body->sYOffset; // why access gSprites again? tail->y2 would be sufficient
        body->sYOffset += body->sYOffsetDir;
        if (body->sYOffset >= tail->sTailFloatPeak || body->sYOffset <= -tail->sTailFloatPeak)
        {
            if (body->sYOffset > tail->sTailFloatPeak)
                body->sYOffset = tail->sTailFloatPeak;
            else if (body->sYOffset < -tail->sTailFloatPeak)
                body->sYOffset = -tail->sTailFloatPeak;

            body->sYOffsetDir *= -1;
        }
    }

    body->sFloatTimer++;
}

static void ChasesAway_SetCMamizouAnim(struct Sprite *body, u8 animNum, s16 x, s16 y)
{
    struct Sprite *tail = &gSprites[body->sTailSpriteId];

    tail->x = body->x + x;
    tail->y = body->y + y;

    tail->x2 = body->x2;
    tail->y2 = body->y2;

    StartSpriteAnim(body, animNum);
    StartSpriteAnim(tail, animNum);
}

#undef sTailSpriteId
#undef sYOffset
#undef sYOffsetDir
#undef sFloatTimer
#undef sTimer
#undef sTailFloatDelay
#undef sTailFloatPeak

#define tState      data[0]
#define tScale      data[1]
#define tNumRings   data[2]
#define tScaleTimer data[3]
#define tScaleSpeed data[4]
#define tSoundTimer data[5]

static void Task_ChasesAway_AnimateRing(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (tState)
    {
    case 0:
        SetBgAffine(2, 0x4000, 0x4000, 120, 64, 256, 256, 0);
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG2_ON);
        tScaleSpeed = 16;
        tState++;
        break;
    case 1:
        if (tSoundTimer == 8)
            PlaySE(SE_SLIDING_DOOR);
        if (tNumRings == 2)
        {
            tState++;
        }
        else
        {
            tScale += tScaleSpeed;
            tSoundTimer++;
            if (tScaleTimer % 3 == 0 && tScaleSpeed != 4)
                tScaleSpeed -= 2;

            tScaleTimer++;
            SetBgAffine(2, 0x4000, 0x4000, 120, 64, 256 - tScale, 256 - tScale, 0);
            if (tScale > 255)
            {
                tScale = 0;
                tScaleTimer = 0;
                tSoundTimer = 0;
                tScaleSpeed = 16;
                tNumRings++;
            }
        }
        break;
    case 2:
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG2_ON);
        DestroyTask(taskId);
        break;
    }
}
