.set LOCALID_LUGIA, 1

NavelRock_Bottom_MapScripts:: @ 8269255
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Bottom_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_Bottom_OnResume
	.byte 0

NavelRock_Bottom_OnTransition: @ 8269260
	call_if_set FLAG_CAUGHT_SKOMACHI, NavelRock_Bottom_EventScript_HideSKomachi
	call_if_unset FLAG_CAUGHT_SKOMACHI, NavelRock_Bottom_EventScript_TryShowSKomachi
	end

NavelRock_Bottom_EventScript_HideSKomachi:: @ 8269273
	setflag FLAG_HIDE_SKOMACHI
	return

NavelRock_Bottom_EventScript_TryShowSKomachi:: @ 8269277
	goto_if_set FLAG_DEFEATED_SKOMACHI, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_SKOMACHI
	return

NavelRock_Bottom_OnResume: @ 8269284
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NavelRock_Bottom_EventScript_TryRemoveSKomachi
	end

NavelRock_Bottom_EventScript_TryRemoveSKomachi:: @ 826928E
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject LOCALID_LUGIA
	return

NavelRock_Bottom_EventScript_SKomachi:: @ 82692A2
	lock
	faceplayer
	waitse
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	delay 50
	waitse
	playmoncry SPECIES_SKOMACHI, 2
	waitmoncry
	delay 20
	setvar VAR_0x8004, SPECIES_SKOMACHI
	setvar VAR_0x8005, 70  @ level
	setvar VAR_0x8006, ITEM_NONE
	special CreateObedientEnemyMon
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq NavelRock_Bottom_EventScript_DefeatedSKomachi
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq NavelRock_Bottom_EventScript_RanFromSKomachi
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq NavelRock_Bottom_EventScript_RanFromSKomachi
	setflag FLAG_CAUGHT_SKOMACHI
	release
	end

NavelRock_Bottom_EventScript_DefeatedSKomachi:: @ 8269336
	setflag FLAG_DEFEATED_SKOMACHI
	setvar VAR_0x8004, SPECIES_SKOMACHI
	goto Common_EventScript_LegendaryFlewAway
	end

NavelRock_Bottom_EventScript_RanFromSKomachi:: @ 8269344
	setvar VAR_0x8004, SPECIES_SKOMACHI
	goto Common_EventScript_LegendaryFlewAway
	end
