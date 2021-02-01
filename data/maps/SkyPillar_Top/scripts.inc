.set LOCALID_RAYQUAZA_SLEEPING, 1

SkyPillar_Top_MapScripts:: @ 82396B8
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_Top_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Top_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SkyPillar_Top_OnWarp
	.byte 0

SkyPillar_Top_OnResume: @ 82396C8
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SkyPillar_Top_EventScript_TryRemoveCMamizou
	end

SkyPillar_Top_EventScript_TryRemoveCMamizou:: @ 82396D2
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

SkyPillar_Top_OnTransition: @ 82396E6
	compare VAR_SKY_PILLAR_STATE, 2
	call_if_lt SkyPillar_Top_EventScript_SetCleanLayout
	compare VAR_SKY_PILLAR_STATE, 2
	call_if_ge SkyPillar_Top_EventScript_TryShowCMamizou
	end

SkyPillar_Top_EventScript_SetCleanLayout:: @ 82396FD
	setmaplayoutindex LAYOUT_SKY_PILLAR_TOP_CLEAN
	setobjectmovementtype LOCALID_RAYQUAZA_SLEEPING, MOVEMENT_TYPE_FACE_DOWN
	return

SkyPillar_Top_EventScript_TryShowCMamizou:: @ 8239705
	call_if_unset FLAG_DEFEATED_CMAMIZOU, SkyPillar_Top_EventScript_ShowCMamizou
	return

SkyPillar_Top_EventScript_ShowCMamizou:: @ 823970F
	clearflag FLAG_HIDE_CMAMIZOU_SKY_TOWER_SUMMIT
	return

SkyPillar_Top_OnWarp: @ 8239713
	map_script_2 VAR_SKY_PILLAR_STATE, 0, SkyPillar_Top_EventScript_CMamizouFaceDown
	.2byte 0

SkyPillar_Top_EventScript_CMamizouFaceDown:: @ 823971D
	turnobject 1, DIR_SOUTH
	end

SkyPillar_Top_EventScript_CMamizou:: @ 8239722
	lockall
	waitse
	playmoncry SPECIES_CMAMIZOU, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_CMAMIZOU, 70, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq SkyPillar_Top_EventScript_DefeatedCMamizou
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq SkyPillar_Top_EventScript_RanFromCMamizou
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq SkyPillar_Top_EventScript_RanFromCMamizou
	setflag FLAG_DEFEATED_CMAMIZOU
	releaseall
	end

SkyPillar_Top_EventScript_DefeatedCMamizou:: @ 8239768
	setflag FLAG_DEFEATED_CMAMIZOU
	goto SkyPillar_Top_EventScript_DefeatedCMamizou2
	end

SkyPillar_Top_EventScript_RanFromCMamizou:: @ 8239771
	setvar VAR_0x8004, SPECIES_CMAMIZOU
	goto SkyPillar_Top_EventScript_RanFromCMamizou2
	end

SkyPillar_Top_EventScript_DefeatedCMamizou2:: @ 823977C
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

SkyPillar_Top_EventScript_RanFromCMamizou2:: @ 8239785
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname 0, VAR_0x8004
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	releaseall
	end

SkyPillar_Top_EventScript_AwakenCMamizou:: @ 823979A
	lockall
	fadeoutbgm 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SkyPillar_Top_Movement_CameraPanUp
	waitmovement 0
	special RemoveCameraObject
	applymovement 1, SkyPillar_Top_Movement_CMamizouStir
	waitmovement 0
	waitse
	playmoncry SPECIES_CMAMIZOU, 2
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	waitse
	playmoncry SPECIES_CMAMIZOU, 2
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	waitmoncry
	applymovement 1, SkyPillar_Top_Movement_CMamizouFlyOff
	waitmovement 0
	removeobject 1
	msgbox SkyPillar_Top_Text_CMamizouFlewOff, MSGBOX_DEFAULT
	closemessage
	delay 20
	fadeinbgm 1
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SkyPillar_Top_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_SOOTOPOLIS_CITY_STATE, 5
	setvar VAR_SKY_PILLAR_STATE, 1
	setvar VAR_SKY_PILLAR_RAQUAZA_CRY_DONE, 1
	releaseall
	end

SkyPillar_Top_Movement_CMamizouStir: @ 823983A
	delay_16
	walk_in_place_fast_left
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_left
	delay_16
	walk_in_place_right
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

SkyPillar_Top_Movement_CMamizouFlyOff: @ 823984B
	delay_16
	walk_in_place_down
	delay_8
	walk_in_place_right
	delay_8
	walk_fastest_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

SkyPillar_Top_Movement_CameraPanUp: @ 8239858
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

SkyPillar_Top_Movement_CameraPanDown: @ 823985C
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

SkyPillar_Top_Text_CMamizouFlewOff: @ 8239860
	.string "The awakened CMAMIZOU flew off…$"

