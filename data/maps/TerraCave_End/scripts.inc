.set LOCALID_MIKO, 1

TerraCave_End_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TerraCave_End_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, TerraCave_End_OnTransition
	.byte 0

TerraCave_End_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, TerraCave_End_EventScript_TryRemoveMiko
	end

TerraCave_End_EventScript_TryRemoveMiko::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_MIKO
	return

TerraCave_End_OnTransition:
	call_if_unset FLAG_DEFEATED_MIKO, TerraCave_End_EventScript_ShowMiko
	end

TerraCave_End_EventScript_ShowMiko::
	clearflag FLAG_HIDE_TERRA_CAVE_MIKO
	setvar VAR_TEMP_1, 1
	return

TerraCave_End_EventScript_Miko::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_MIKO, TerraCave_End_Movement_MikoApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_MIKO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_MIKO
	setwildbattle SPECIES_MIKO, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TerraCave_End_EventScript_DefeatedMiko
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, TerraCave_End_EventScript_RanFromMiko
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, TerraCave_End_EventScript_RanFromMiko
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	setflag FLAG_DEFEATED_MIKO
	releaseall
	end

TerraCave_End_EventScript_DefeatedMiko::
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	setflag FLAG_DEFEATED_MIKO
	goto Common_EventScript_RemoveStaticPokemon
	end

TerraCave_End_EventScript_RanFromMiko::
	setvar VAR_0x8004, SPECIES_MIKO
	goto Common_EventScript_LegendaryFlewAway
	end

TerraCave_End_Movement_MikoApproach:
	init_affine_anim
	walk_down_start_affine
	delay_16
	delay_16
	walk_down_affine
	delay_16
	delay_16
	walk_down_affine
	step_end

