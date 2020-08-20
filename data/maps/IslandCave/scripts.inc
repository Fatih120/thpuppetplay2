IslandCave_MapScripts:: @ 8238E2A
	map_script MAP_SCRIPT_ON_RESUME, IslandCave_OnResume
	map_script MAP_SCRIPT_ON_LOAD, IslandCave_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, IslandCave_OnTransition
	.byte 0

IslandCave_OnResume: @ 8238E3A
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, IslandCave_EventScript_TryRemoveCFuto
	end

IslandCave_EventScript_TryRemoveCFuto:: @ 8238E44
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

IslandCave_OnLoad: @ 8238E58
	call_if_unset FLAG_SYS_BRAILLE_CFUTO_COMPLETED, IslandCave_EventScript_HideRegiEntrance
	end

IslandCave_EventScript_HideRegiEntrance:: @ 8238E62
	setmetatile 7, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 8, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 9, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	return

IslandCave_OnTransition: @ 8238E99
	setflag FLAG_LANDMARK_ISLAND_CAVE
	call IslandCave_EventScript_ClearSteps
	call_if_unset FLAG_DEFEATED_CFUTO, IslandCave_EventScript_ShowCFuto
	end

IslandCave_EventScript_ShowCFuto:: @ 8238EAB
	clearflag FLAG_HIDE_CFUTO
	return

IslandCave_EventScript_OpenRegiEntrance:: @ 8238EAF
	setmetatile 7, 19, METATILE_Cave_SealedChamberEntrance_TopLeft, 1
	setmetatile 8, 19, METATILE_Cave_SealedChamberEntrance_TopMid, 1
	setmetatile 9, 19, METATILE_Cave_SealedChamberEntrance_TopRight, 1
	setmetatile 7, 20, METATILE_Cave_SealedChamberEntrance_BottomLeft, 1
	setmetatile 8, 20, METATILE_Cave_SealedChamberEntrance_BottomMid, 0
	setmetatile 9, 20, METATILE_Cave_SealedChamberEntrance_BottomRight, 1
	special DrawWholeMapView
	playse SE_BANG
	setflag FLAG_SYS_BRAILLE_CFUTO_COMPLETED
	end

IslandCave_EventScript_CaveEntranceMiddle:: @ 8238EEF
	lockall
	call_if_set FLAG_TEMP_3, IslandCave_EventScript_ClearSteps
	goto_if_set FLAG_SYS_BRAILLE_CFUTO_COMPLETED, IslandCave_EventScript_BigHoleInWall
	braillemessage IslandCave_Braille_RunLapAroundWall
	setflag FLAG_TEMP_2
	special ShouldDoBrailleCFutoPuzzle
	goto IslandCave_EventScript_CloseBrailleMsg
	end

IslandCave_EventScript_BigHoleInWall:: @ 8238F13
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

IslandCave_EventScript_CaveEntranceSide:: @ 8238F1D
	lockall
	call_if_set FLAG_TEMP_3, IslandCave_EventScript_ClearSteps
	braillemessage IslandCave_Braille_RunLapAroundWall
	goto_if_set FLAG_SYS_BRAILLE_CFUTO_COMPLETED, IslandCave_EventScript_CloseBrailleMsg
	setflag FLAG_TEMP_2
	special ShouldDoBrailleCFutoPuzzle
	goto IslandCave_EventScript_CloseBrailleMsg
	end

IslandCave_EventScript_CloseBrailleMsg:: @ 8238F41
	waitbuttonpress
	closebraillemessage
	releaseall
	end

IslandCave_EventScript_ClearSteps:: @ 8238F45
	setvar VAR_CFUTO_STEPS_1, 0
	setvar VAR_CFUTO_STEPS_2, 0
	setvar VAR_CFUTO_STEPS_3, 0
	clearflag FLAG_TEMP_3
	return

IslandCave_EventScript_CFuto:: @ 8238F58
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CFUTO, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_CFUTO, 40, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq IslandCave_EventScript_DefeatedCFuto
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq IslandCave_EventScript_RanFromCFuto
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq IslandCave_EventScript_RanFromCFuto
	setflag FLAG_DEFEATED_CFUTO
	release
	end

IslandCave_EventScript_DefeatedCFuto:: @ 8238F9F
	setflag FLAG_DEFEATED_CFUTO
	goto Common_EventScript_RemoveStaticPokemon
	end

IslandCave_EventScript_RanFromCFuto:: @ 8238FA8
	setvar VAR_0x8004, SPECIES_CFUTO
	goto Common_EventScript_LegendaryFlewAway
	end
