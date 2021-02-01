.set LOCALID_KYOGRE, 1

MarineCave_End_MapScripts:: @ 823AFDF
	map_script MAP_SCRIPT_ON_RESUME, MarineCave_End_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MarineCave_End_OnTransition
	.byte 0

MarineCave_End_OnResume: @ 823AFEA
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MarineCave_End_EventScript_TryRemoveCMiko
	end

MarineCave_End_EventScript_TryRemoveCMiko:: @ 823AFF4
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject LOCALID_KYOGRE
	return

MarineCave_End_OnTransition: @ 823B008
	call_if_unset FLAG_DEFEATED_CMIKO, MarineCave_End_EventScript_ShowCMiko
	end

MarineCave_End_EventScript_ShowCMiko:: @ 823B012
	clearflag FLAG_HIDE_MARINE_CAVE_CMIKO
	setvar VAR_TEMP_1, 1
	return

MarineCave_End_EventScript_CMiko:: @ 823B01B
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement 1, MarineCave_End_Movement_CMikoApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_CMIKO, 2
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, 1
	setwildbattle SPECIES_CMIKO, 70, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MarineCave_End_EventScript_DefeatedCMiko
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq MarineCave_End_EventScript_RanFromCMiko
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq MarineCave_End_EventScript_RanFromCMiko
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	setflag FLAG_DEFEATED_CMIKO
	releaseall
	end

MarineCave_End_EventScript_DefeatedCMiko:: @ 823B084
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	setflag FLAG_DEFEATED_CMIKO
	goto Common_EventScript_RemoveStaticPokemon
	end

MarineCave_End_EventScript_RanFromCMiko:: @ 823B092
	setvar VAR_0x8004, SPECIES_CMIKO
	goto Common_EventScript_LegendaryFlewAway
	end

MarineCave_End_Movement_CMikoApproach: @ 823B09D
	init_affine_anim
	walk_down_start_affine
	delay_16
	delay_16
	walk_down_affine
	delay_16
	delay_16
	walk_down_affine
	step_end

