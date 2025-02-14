.set LOCALID_CMIKO, 1

MarineCave_End_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MarineCave_End_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MarineCave_End_OnTransition
	.byte 0

MarineCave_End_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MarineCave_End_EventScript_TryRemoveCMiko
	end

MarineCave_End_EventScript_TryRemoveCMiko::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_CMIKO
	return

MarineCave_End_OnTransition:
	call_if_unset FLAG_DEFEATED_CMIKO, MarineCave_End_EventScript_ShowCMiko
	end

MarineCave_End_EventScript_ShowCMiko::
	clearflag FLAG_HIDE_MARINE_CAVE_CMIKO
	setvar VAR_TEMP_1, 1
	return

MarineCave_End_EventScript_CMiko::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_CMIKO, MarineCave_End_Movement_CMikoApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_CMIKO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_CMIKO
	setwildbattle SPECIES_CMIKO, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MarineCave_End_EventScript_DefeatedCMiko
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MarineCave_End_EventScript_RanFromCMiko
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MarineCave_End_EventScript_RanFromCMiko
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	setflag FLAG_DEFEATED_CMIKO
	releaseall
	end

MarineCave_End_EventScript_DefeatedCMiko::
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	setflag FLAG_DEFEATED_CMIKO
	goto Common_EventScript_RemoveStaticPokemon
	end

MarineCave_End_EventScript_RanFromCMiko::
	setvar VAR_0x8004, SPECIES_CMIKO
	goto Common_EventScript_LegendaryFlewAway
	end

MarineCave_End_Movement_CMikoApproach:
	init_affine_anim
	walk_down_start_affine
	delay_16
	delay_16
	walk_down_affine
	delay_16
	delay_16
	walk_down_affine
	step_end

