.set LOCALID_SKOMACHI, 1

NavelRock_Bottom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Bottom_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_Bottom_OnResume
	.byte 0

NavelRock_Bottom_OnTransition:
	call_if_set FLAG_CAUGHT_SKOMACHI, NavelRock_Bottom_EventScript_HideSKomachi
	call_if_unset FLAG_CAUGHT_SKOMACHI, NavelRock_Bottom_EventScript_TryShowSKomachi
	end

NavelRock_Bottom_EventScript_HideSKomachi::
	setflag FLAG_HIDE_SKOMACHI
	return

NavelRock_Bottom_EventScript_TryShowSKomachi::
	goto_if_set FLAG_DEFEATED_SKOMACHI, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_SKOMACHI
	return

NavelRock_Bottom_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NavelRock_Bottom_EventScript_TryRemoveSKomachi
	end

NavelRock_Bottom_EventScript_TryRemoveSKomachi::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_SKOMACHI
	return

NavelRock_Bottom_EventScript_SKomachi::
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
	playmoncry SPECIES_SKOMACHI, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_SKOMACHI, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NavelRock_Bottom_EventScript_DefeatedSKomachi
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NavelRock_Bottom_EventScript_RanFromSKomachi
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NavelRock_Bottom_EventScript_RanFromSKomachi
	setflag FLAG_CAUGHT_SKOMACHI
	release
	end

NavelRock_Bottom_EventScript_DefeatedSKomachi::
	setflag FLAG_DEFEATED_SKOMACHI
	setvar VAR_0x8004, SPECIES_SKOMACHI
	goto Common_EventScript_LegendaryFlewAway
	end

NavelRock_Bottom_EventScript_RanFromSKomachi::
	setvar VAR_0x8004, SPECIES_SKOMACHI
	goto Common_EventScript_LegendaryFlewAway
	end
