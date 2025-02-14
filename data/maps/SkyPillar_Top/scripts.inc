.set LOCALID_CMAMIZOU_SLEEPING, 1

SkyPillar_Top_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_Top_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Top_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SkyPillar_Top_OnWarp
	.byte 0

SkyPillar_Top_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SkyPillar_Top_EventScript_TryRemoveCMamizou
	end

SkyPillar_Top_EventScript_TryRemoveCMamizou::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

SkyPillar_Top_OnTransition:
	call_if_lt VAR_SKY_PILLAR_STATE, 2, SkyPillar_Top_EventScript_SetCleanLayout
	call_if_ge VAR_SKY_PILLAR_STATE, 2, SkyPillar_Top_EventScript_TryShowCMamizou
	end

SkyPillar_Top_EventScript_SetCleanLayout::
	setmaplayoutindex LAYOUT_SKY_PILLAR_TOP_CLEAN
	setobjectmovementtype LOCALID_CMAMIZOU_SLEEPING, MOVEMENT_TYPE_FACE_DOWN
	return

SkyPillar_Top_EventScript_TryShowCMamizou::
	call_if_unset FLAG_DEFEATED_CMAMIZOU, SkyPillar_Top_EventScript_ShowCMamizou
	return

SkyPillar_Top_EventScript_ShowCMamizou::
	clearflag FLAG_HIDE_SKY_PILLAR_TOP_CMAMIZOU_STILL
	return

SkyPillar_Top_OnWarp:
	map_script_2 VAR_SKY_PILLAR_STATE, 0, SkyPillar_Top_EventScript_CMamizouFaceDown
	.2byte 0

SkyPillar_Top_EventScript_CMamizouFaceDown::
	turnobject LOCALID_CMAMIZOU_SLEEPING, DIR_SOUTH
	end

SkyPillar_Top_EventScript_CMamizou::
	lockall
	waitse
	playmoncry SPECIES_CMAMIZOU, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_CMAMIZOU, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SkyPillar_Top_EventScript_DefeatedCMamizou
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SkyPillar_Top_EventScript_RanFromCMamizou
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SkyPillar_Top_EventScript_RanFromCMamizou
	setflag FLAG_DEFEATED_CMAMIZOU
	releaseall
	end

SkyPillar_Top_EventScript_DefeatedCMamizou::
	setflag FLAG_DEFEATED_CMAMIZOU
	goto SkyPillar_Top_EventScript_DefeatedCMamizou2
	end

SkyPillar_Top_EventScript_RanFromCMamizou::
	setvar VAR_0x8004, SPECIES_CMAMIZOU
	goto SkyPillar_Top_EventScript_RanFromCMamizou2
	end

SkyPillar_Top_EventScript_DefeatedCMamizou2::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

SkyPillar_Top_EventScript_RanFromCMamizou2::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	releaseall
	end

SkyPillar_Top_EventScript_AwakenCMamizou::
	lockall
	fadeoutbgm 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SkyPillar_Top_Movement_CameraPanUp
	waitmovement 0
	special RemoveCameraObject
	applymovement LOCALID_CMAMIZOU_SLEEPING, SkyPillar_Top_Movement_CMamizouStir
	waitmovement 0
	waitse
	playmoncry SPECIES_CMAMIZOU, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	waitse
	playmoncry SPECIES_CMAMIZOU, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	waitmoncry
	applymovement LOCALID_CMAMIZOU_SLEEPING, SkyPillar_Top_Movement_CMamizouFlyOff
	waitmovement 0
	removeobject LOCALID_CMAMIZOU_SLEEPING
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
	setvar VAR_SKY_PILLAR_CMAMIZOU_CRY_DONE, 1
	releaseall
	end

@ CMamizou has unusual movement frames
@ See comments, or sAnimTable_CMamizou
SkyPillar_Top_Movement_CMamizouStir:
	delay_16
	walk_in_place_fast_left  @ Coiled, awake
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_left  @ Coiled, mouth open
	delay_16
	walk_in_place_right  @ Normal, awake
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

SkyPillar_Top_Movement_CMamizouFlyOff:
	delay_16
	walk_in_place_down  @ Coiled, asleep
	delay_8
	walk_in_place_right  @ Normal, awake
	delay_8
	walk_faster_up  @ Fly up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

SkyPillar_Top_Movement_CameraPanUp:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

SkyPillar_Top_Movement_CameraPanDown:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

SkyPillar_Top_Text_CMamizouFlewOff:
	.string "The awakened CMAMIZOU flew off…$"

