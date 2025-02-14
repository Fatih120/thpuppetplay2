IslandCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, IslandCave_OnResume
	map_script MAP_SCRIPT_ON_LOAD, IslandCave_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, IslandCave_OnTransition
	.byte 0

IslandCave_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, IslandCave_EventScript_TryRemoveCFuto
	end

IslandCave_EventScript_TryRemoveCFuto::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

IslandCave_OnLoad:
	call_if_unset FLAG_SYS_BRAILLE_CFUTO_COMPLETED, IslandCave_EventScript_HideRegiEntrance
	end

IslandCave_EventScript_HideRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return

IslandCave_OnTransition:
	setflag FLAG_LANDMARK_ISLAND_CAVE
	call IslandCave_EventScript_ClearSteps
	call_if_unset FLAG_DEFEATED_CFUTO, IslandCave_EventScript_ShowCFuto
	end

IslandCave_EventScript_ShowCFuto::
	clearflag FLAG_HIDE_CFUTO
	return

IslandCave_EventScript_OpenRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_SealedChamberEntrance_TopLeft, TRUE
	setmetatile 8, 19, METATILE_Cave_SealedChamberEntrance_TopMid, TRUE
	setmetatile 9, 19, METATILE_Cave_SealedChamberEntrance_TopRight, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberEntrance_BottomLeft, TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberEntrance_BottomMid, FALSE
	setmetatile 9, 20, METATILE_Cave_SealedChamberEntrance_BottomRight, TRUE
	special DrawWholeMapView
	playse SE_BANG
	setflag FLAG_SYS_BRAILLE_CFUTO_COMPLETED
	end

IslandCave_EventScript_CaveEntranceMiddle::
	lockall
	call_if_set FLAG_TEMP_CFUTO_PUZZLE_FAILED, IslandCave_EventScript_ClearSteps
	goto_if_set FLAG_SYS_BRAILLE_CFUTO_COMPLETED, IslandCave_EventScript_BigHoleInWall
	braillemessage IslandCave_Braille_RunLapAroundWall
	setflag FLAG_TEMP_CFUTO_PUZZLE_STARTED
	special ShouldDoBrailleCFutoPuzzle
	goto IslandCave_EventScript_CloseBrailleMsg
	end

IslandCave_EventScript_BigHoleInWall::
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

IslandCave_EventScript_CaveEntranceSide::
	lockall
	call_if_set FLAG_TEMP_CFUTO_PUZZLE_FAILED, IslandCave_EventScript_ClearSteps
	braillemessage IslandCave_Braille_RunLapAroundWall
	goto_if_set FLAG_SYS_BRAILLE_CFUTO_COMPLETED, IslandCave_EventScript_CloseBrailleMsg
	setflag FLAG_TEMP_CFUTO_PUZZLE_STARTED
	special ShouldDoBrailleCFutoPuzzle
	goto IslandCave_EventScript_CloseBrailleMsg
	end

IslandCave_EventScript_CloseBrailleMsg::
	waitbuttonpress
	closebraillemessage
	releaseall
	end

IslandCave_EventScript_ClearSteps::
	setvar VAR_CFUTO_STEPS_1, 0
	setvar VAR_CFUTO_STEPS_2, 0
	setvar VAR_CFUTO_STEPS_3, 0
	clearflag FLAG_TEMP_CFUTO_PUZZLE_FAILED
	return

IslandCave_EventScript_CFuto::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CFUTO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_CFUTO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, IslandCave_EventScript_DefeatedCFuto
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, IslandCave_EventScript_RanFromCFuto
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, IslandCave_EventScript_RanFromCFuto
	setflag FLAG_DEFEATED_CFUTO
	release
	end

IslandCave_EventScript_DefeatedCFuto::
	setflag FLAG_DEFEATED_CFUTO
	goto Common_EventScript_RemoveStaticPokemon
	end

IslandCave_EventScript_RanFromCFuto::
	setvar VAR_0x8004, SPECIES_CFUTO
	goto Common_EventScript_LegendaryFlewAway
	end
