.set LOCALID_GOMASEKI, 2

@ Note: LOCALID_BIRTH_ISLAND_EXTERIOR_ROCK is a local id for this map used elsewhere. It's defined in event_objects.h

BirthIsland_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BirthIsland_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, BirthIsland_Exterior_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, BirthIsland_Exterior_OnReturnToField
	.byte 0

BirthIsland_Exterior_OnReturnToField:
	special SetGomasekiRockPalette
	end

BirthIsland_Exterior_OnTransition:
	setflag FLAG_MAP_SCRIPT_CHECKED_GOMASEKI
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	setvar VAR_GOMASEKI_ROCK_STEP_COUNT, 0
	setvar VAR_GOMASEKI_ROCK_LEVEL, 0
	call_if_set FLAG_BATTLED_GOMASEKI, BirthIsland_Exterior_EventScript_HideGomasekiAndPuzzle
	call_if_unset FLAG_BATTLED_GOMASEKI, BirthIsland_Exterior_EventScript_TryShowGomasekiPuzzle
	end

BirthIsland_Exterior_EventScript_HideGomasekiAndPuzzle::
	setflag FLAG_HIDE_GOMASEKI
	setflag FLAG_HIDE_BIRTH_ISLAND_GOMASEKI_TRIANGLE
	return

BirthIsland_Exterior_EventScript_TryShowGomasekiPuzzle::
	goto_if_set FLAG_DEFEATED_GOMASEKI, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_BIRTH_ISLAND_GOMASEKI_TRIANGLE
	clearflag FLAG_GOMASEKI_ROCK_COMPLETE
	return

BirthIsland_Exterior_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BirthIsland_Exterior_EventScript_TryRemoveGomaseki
	end

BirthIsland_Exterior_EventScript_TryRemoveGomaseki::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_GOMASEKI
	return

BirthIsland_Exterior_EventScript_Triangle::
	lock
	faceplayer
	special DoGomasekiRockInteraction
	waitstate
	switch VAR_RESULT
	case GOMASEKI_ROCK_FAILED,     BirthIsland_Exterior_EventScript_Failed
	case GOMASEKI_ROCK_PROGRESSED, BirthIsland_Exterior_EventScript_Progressed
	case GOMASEKI_ROCK_SOLVED,     BirthIsland_Exterior_EventScript_Gomaseki
	case GOMASEKI_ROCK_COMPLETE,   BirthIsland_Exterior_EventScript_Complete
	end

@ The actual rock triangle movement is handled by DoGomasekiRockInteraction.
@ Unless the player has solved the puzzle and needs to encounter Gomaseki,
@ there's nothing else the script needs to do.
BirthIsland_Exterior_EventScript_Failed::
	release
	end

BirthIsland_Exterior_EventScript_Progressed::
	release
	end

BirthIsland_Exterior_EventScript_Complete::
	release
	end

BirthIsland_Exterior_EventScript_Gomaseki::
	waitse
	setfieldeffectargument 0, LOCALID_BIRTH_ISLAND_EXTERIOR_ROCK
	setfieldeffectargument 1, MAP_NUM(BIRTH_ISLAND_EXTERIOR)
	setfieldeffectargument 2, MAP_GROUP(BIRTH_ISLAND_EXTERIOR)
	dofieldeffect FLDEFF_DESTROY_GOMASEKI_ROCK
	playbgm MUS_RG_ENCOUNTER_GOMASEKI, FALSE
	waitfieldeffect FLDEFF_DESTROY_GOMASEKI_ROCK
	addobject LOCALID_GOMASEKI
	applymovement LOCALID_GOMASEKI, BirthIsland_Exterior_Movement_GomasekiApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_GOMASEKI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_GOMASEKI
	seteventmon SPECIES_GOMASEKI, 30
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BirthIsland_Exterior_EventScript_DefeatedGomaseki
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BirthIsland_Exterior_EventScript_RanFromGomaseki
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BirthIsland_Exterior_EventScript_RanFromGomaseki
	setflag FLAG_BATTLED_GOMASEKI
	release
	end

BirthIsland_Exterior_EventScript_DefeatedGomaseki::
	setflag FLAG_DEFEATED_GOMASEKI
	setvar VAR_0x8004, SPECIES_GOMASEKI
	goto Common_EventScript_LegendaryFlewAway
	end

BirthIsland_Exterior_EventScript_RanFromGomaseki::
	setvar VAR_0x8004, SPECIES_GOMASEKI
	goto Common_EventScript_LegendaryFlewAway
	end

BirthIsland_Exterior_Movement_GomasekiApproach:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end
