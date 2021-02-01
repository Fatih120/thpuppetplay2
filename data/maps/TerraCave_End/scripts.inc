.set LOCALID_GROUDON, 1

TerraCave_End_MapScripts:: @ 823B0B0
	map_script MAP_SCRIPT_ON_RESUME, TerraCave_End_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, TerraCave_End_OnTransition
	.byte 0

TerraCave_End_OnResume: @ 823B0BB
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, TerraCave_End_EventScript_TryRemoveMiko
	end

TerraCave_End_EventScript_TryRemoveMiko:: @ 823B0C5
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject LOCALID_GROUDON
	return

TerraCave_End_OnTransition: @ 823B0D9
	call_if_unset FLAG_DEFEATED_MIKO, TerraCave_End_EventScript_ShowMiko
	end

TerraCave_End_EventScript_ShowMiko:: @ 823B0E3
	clearflag FLAG_HIDE_TERRA_CAVE_MIKO
	setvar VAR_TEMP_1, 1
	return

TerraCave_End_EventScript_Miko:: @ 823B0EC
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement 1, TerraCave_End_Movement_MikoApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_MIKO, 2
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, 1
	setwildbattle SPECIES_MIKO, 70, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq TerraCave_End_EventScript_DefeatedMiko
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq TerraCave_End_EventScript_RanFromMiko
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq TerraCave_End_EventScript_RanFromMiko
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	setflag FLAG_DEFEATED_MIKO
	releaseall
	end

TerraCave_End_EventScript_DefeatedMiko:: @ 823B155
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	setflag FLAG_DEFEATED_MIKO
	goto Common_EventScript_RemoveStaticPokemon
	end

TerraCave_End_EventScript_RanFromMiko:: @ 823B163
	setvar VAR_0x8004, SPECIES_MIKO
	goto Common_EventScript_LegendaryFlewAway
	end

TerraCave_End_Movement_MikoApproach: @ 823B16E
	init_affine_anim
	walk_down_start_affine
	delay_16
	delay_16
	walk_down_affine
	delay_16
	delay_16
	walk_down_affine
	step_end

