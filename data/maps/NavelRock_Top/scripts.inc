.set LOCALID_AKOMACHI, 1

NavelRock_Top_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Top_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_Top_OnResume
	.byte 0

NavelRock_Top_OnTransition:
	call_if_set FLAG_CAUGHT_AKOMACHI, NavelRock_Top_EventScript_HideAKomachi
	call_if_unset FLAG_CAUGHT_AKOMACHI, NavelRock_Top_EventScript_TryShowAKomachi
	end

NavelRock_Top_EventScript_HideAKomachi::
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_AKOMACHI
	return

NavelRock_Top_EventScript_TryShowAKomachi::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_DEFEATED_AKOMACHI, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_AKOMACHI
	return

NavelRock_Top_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NavelRock_Top_EventScript_TryRemoveAKomachi
	end

NavelRock_Top_EventScript_TryRemoveAKomachi::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_AKOMACHI
	return

NavelRock_Top_EventScript_AKomachi::
	lockall
	setvar VAR_TEMP_1, 1
	special SpawnCameraObject
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement LOCALID_AKOMACHI, NavelRock_Top_Movement_AKomachiAppear
	applymovement OBJ_EVENT_ID_CAMERA, NavelRock_Top_Movement_CameraPanUp
	waitmovement 0
	delay 50
	setweather WEATHER_NONE
	doweather
	waitse
	playmoncry SPECIES_AKOMACHI, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	delay 60
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement OBJ_EVENT_ID_CAMERA, NavelRock_Top_Movement_CameraPanDown
	applymovement LOCALID_AKOMACHI, NavelRock_Top_Movement_AKomachiApproach
	waitmovement 0
	special RemoveCameraObject
	seteventmon SPECIES_AKOMACHI, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_LAST_TALKED, LOCALID_AKOMACHI
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NavelRock_Top_EventScript_DefeatedAKomachi
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NavelRock_Top_EventScript_RanFromAKomachi
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NavelRock_Top_EventScript_RanFromAKomachi
	setflag FLAG_CAUGHT_AKOMACHI
	releaseall
	end

NavelRock_Top_EventScript_DefeatedAKomachi::
	setflag FLAG_DEFEATED_AKOMACHI
	setvar VAR_0x8004, SPECIES_AKOMACHI
	goto Common_EventScript_LegendaryFlewAway
	end

NavelRock_Top_EventScript_RanFromAKomachi::
	setvar VAR_0x8004, SPECIES_AKOMACHI
	goto Common_EventScript_LegendaryFlewAway
	end

NavelRock_Top_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	step_end

NavelRock_Top_Movement_CameraPanDown:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

NavelRock_Top_Movement_AKomachiApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	delay_16
	delay_16
	step_end

NavelRock_Top_Movement_AKomachiAppear:
	delay_16
	delay_16
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end
