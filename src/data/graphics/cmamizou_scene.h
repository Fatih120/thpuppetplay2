// Scene 1 (RAY_ANIM_DUO_FIGHT / RAY_ANIM_DUO_FIGHT_PRE)
const u32 gRaySceneDuoFight_Miko_Gfx[]           = INCBIN_U32("graphics/cmamizou_scene/scene_1/miko.4bpp.lz");
const u32 gRaySceneDuoFight_MikoShoulder_Gfx[]   = INCBIN_U32("graphics/cmamizou_scene/scene_1/miko_shoulder.4bpp.lz");
const u32 gRaySceneDuoFight_MikoClaw_Gfx[]       = INCBIN_U32("graphics/cmamizou_scene/scene_1/miko_claw.4bpp.lz");
const u32 gRaySceneDuoFight_CMiko_Gfx[]            = INCBIN_U32("graphics/cmamizou_scene/scene_1/cmiko.4bpp.lz");
const u32 gRaySceneDuoFight_CMikoPectoralFin_Gfx[] = INCBIN_U32("graphics/cmamizou_scene/scene_1/cmiko_pectoral_fin.4bpp.lz");
const u32 gRaySceneDuoFight_CMikoDorsalFin_Gfx[]   = INCBIN_U32("graphics/cmamizou_scene/scene_1/cmiko_dorsal_fin.4bpp.lz");
const u32 gRaySceneDuoFight_Miko_Pal[]           = INCBIN_U32("graphics/cmamizou_scene/scene_1/miko.gbapal.lz");
const u32 gRaySceneDuoFight_CMiko_Pal[]            = INCBIN_U32("graphics/cmamizou_scene/scene_1/cmiko.gbapal.lz");
const u32 gRaySceneDuoFight_Clouds_Gfx[]            = INCBIN_U32("graphics/cmamizou_scene/scene_1/clouds.4bpp.lz");
const u32 gRaySceneDuoFight_Clouds_Pal[]            = INCBIN_U32("graphics/cmamizou_scene/scene_1/clouds.gbapal.lz"); // pal 1 clouds, pal 2 rain
const u32 gRaySceneDuoFight_Clouds1_Tilemap[]       = INCBIN_U32("graphics/cmamizou_scene/scene_1/clouds1.bin.lz");
const u32 gRaySceneDuoFight_Clouds2_Tilemap[]       = INCBIN_U32("graphics/cmamizou_scene/scene_1/clouds2.bin.lz");
const u32 gRaySceneDuoFight_Clouds3_Tilemap[]       = INCBIN_U32("graphics/cmamizou_scene/scene_1/clouds3.bin.lz");

// Scene 2 (RAY_ANIM_TAKES_FLIGHT)
const u32 gRaySceneTakesFlight_Smoke_Gfx[]        = INCBIN_U32("graphics/cmamizou_scene/scene_2/smoke.4bpp.lz");
const u32 gRaySceneTakesFlight_Smoke_Pal[]        = INCBIN_U32("graphics/cmamizou_scene/scene_2/smoke.gbapal.lz");
const u32 gRaySceneTakesFlight_CMamizou_Gfx[]     = INCBIN_U32("graphics/cmamizou_scene/scene_2/cmamizou.8bpp.lz");
const u32 gRaySceneTakesFlight_CMamizou_Pal[]     = INCBIN_U32("graphics/cmamizou_scene/scene_2/cmamizou.gbapal.lz");
const u32 gRaySceneTakesFlight_CMamizou_Tilemap[] = INCBIN_U32("graphics/cmamizou_scene/scene_2/cmamizou.bin.lz");
const u32 gRaySceneTakesFlight_Bg_Gfx[]           = INCBIN_U32("graphics/cmamizou_scene/scene_2/bg.4bpp.lz"); // uses pal 2 of gRaySceneTakesFlight_CMamizou_Pal
const u32 gRaySceneTakesFlight_Bg_Tilemap[]       = INCBIN_U32("graphics/cmamizou_scene/scene_2/bg.bin.lz");

// Scene 3 (RAY_ANIM_DESCENDS)
const u32 gRaySceneDescends_CMamizou_Gfx[]     = INCBIN_U32("graphics/cmamizou_scene/scene_3/cmamizou.4bpp.lz");
// for some reason there are an extra 0xC bytes at the end of the original cmamizou_tail.4bpp, so in order to produce the correct lz,
// we have to cat the bytes at the end with a make rule. not sure why those bytes are there, it may have been a bug in Game Freak's software.
const u32 gRaySceneDescends_CMamizouTail_Gfx[] = INCBIN_U32("graphics/cmamizou_scene/scene_3/cmamizou_tail_fix.4bpp.lz");
const u32 gRaySceneDescends_Bg_Gfx[]           = INCBIN_U32("graphics/cmamizou_scene/scene_3/bg.4bpp.lz");
const u32 gRaySceneDescends_Light_Gfx[]        = INCBIN_U32("graphics/cmamizou_scene/scene_3/light.4bpp.lz"); // uses pal 2 of gRaySceneDescends_Bg_Pal
const u32 gRaySceneDescends_Bg_Pal[]           = INCBIN_U32("graphics/cmamizou_scene/scene_3/bg.gbapal.lz");
const u32 gRaySceneDescends_Bg_Tilemap[]       = INCBIN_U32("graphics/cmamizou_scene/scene_3/bg.bin.lz");
const u32 gRaySceneDescends_Light_Tilemap[]    = INCBIN_U32("graphics/cmamizou_scene/scene_3/light.bin.lz");

// Scene 4 (RAY_ANIM_CHARGES)
const u32 gRaySceneCharges_Bg_Gfx[]           = INCBIN_U32("graphics/cmamizou_scene/scene_4/bg.4bpp.lz");
const u32 gRaySceneCharges_Bg_Tilemap[]       = INCBIN_U32("graphics/cmamizou_scene/scene_4/bg.bin.lz");
const u32 gRaySceneCharges_Streaks_Gfx[]      = INCBIN_U32("graphics/cmamizou_scene/scene_4/streaks.4bpp.lz");
const u32 gRaySceneCharges_Streaks_Tilemap[]  = INCBIN_U32("graphics/cmamizou_scene/scene_4/streaks.bin.lz");
const u32 gRaySceneCharges_CMamizou_Gfx[]     = INCBIN_U32("graphics/cmamizou_scene/scene_4/cmamizou.4bpp.lz");
const u32 gRaySceneCharges_CMamizou_Tilemap[] = INCBIN_U32("graphics/cmamizou_scene/scene_4/cmamizou.bin.lz");
const u32 gRaySceneCharges_Orbs_Tilemap[]     = INCBIN_U32("graphics/cmamizou_scene/scene_4/orbs.bin.lz");
const u32 gRaySceneCharges_Bg_Pal[]           = INCBIN_U32("graphics/cmamizou_scene/scene_4/bg.gbapal.lz");

// Scene 5 (RAY_ANIM_CHASES_AWAY)
const u32 gRaySceneChasesAway_Miko_Gfx[]      = INCBIN_U32("graphics/cmamizou_scene/scene_5/miko.4bpp.lz");
const u32 gRaySceneChasesAway_MikoTail_Gfx[]  = INCBIN_U32("graphics/cmamizou_scene/scene_5/miko_tail.4bpp.lz");
const u32 gRaySceneChasesAway_CMiko_Gfx[]       = INCBIN_U32("graphics/cmamizou_scene/scene_5/cmiko.4bpp.lz");
const u32 gRaySceneChasesAway_CMamizou_Gfx[]     = INCBIN_U32("graphics/cmamizou_scene/scene_5/cmamizou.4bpp.lz");
const u32 gRaySceneChasesAway_CMamizouTail_Gfx[] = INCBIN_U32("graphics/cmamizou_scene/scene_5/cmamizou_tail.4bpp.lz");
const u32 gRaySceneChasesAway_CMikoSplash_Gfx[] = INCBIN_U32("graphics/cmamizou_scene/scene_5/cmiko_splash.4bpp.lz");
const u32 gRaySceneChasesAway_Miko_Pal[]      = INCBIN_U32("graphics/cmamizou_scene/scene_5/miko.gbapal.lz");
const u32 gRaySceneChasesAway_CMiko_Pal[]       = INCBIN_U32("graphics/cmamizou_scene/scene_5/cmiko.gbapal.lz");
const u32 gRaySceneChasesAway_CMamizou_Pal[]     = INCBIN_U32("graphics/cmamizou_scene/scene_5/cmamizou.gbapal.lz");
const u32 gRaySceneChasesAway_CMikoSplash_Pal[] = INCBIN_U32("graphics/cmamizou_scene/scene_5/cmiko_splash.gbapal.lz");
const u32 gRaySceneChasesAway_Light_Gfx[]        = INCBIN_U32("graphics/cmamizou_scene/scene_5/light.4bpp.lz");
const u32 gRaySceneChasesAway_Ring_Gfx[]         = INCBIN_U32("graphics/cmamizou_scene/scene_5/ring.8bpp.lz");
const u32 gRaySceneChasesAway_Light_Tilemap[]    = INCBIN_U32("graphics/cmamizou_scene/scene_5/light.bin.lz");
const u32 gRaySceneChasesAway_Bg_Tilemap[]       = INCBIN_U32("graphics/cmamizou_scene/scene_5/bg.bin.lz");
const u32 gRaySceneChasesAway_Ring_Tilemap[]     = INCBIN_U32("graphics/cmamizou_scene/scene_5/ring.bin.lz");
const u32 gRaySceneChasesAway_Bg_Pal[]           = INCBIN_U32("graphics/cmamizou_scene/scene_5/bg.gbapal.lz");
