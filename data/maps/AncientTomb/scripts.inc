AncientTomb_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AncientTomb_OnResume
	map_script MAP_SCRIPT_ON_LOAD, AncientTomb_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, AncientTomb_OnTransition
	.byte 0

AncientTomb_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AncientTomb_EventScript_TryRemoveFuto
	end

AncientTomb_EventScript_TryRemoveFuto::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

AncientTomb_OnTransition:
	setflag FLAG_LANDMARK_ANCIENT_TOMB
	call_if_unset FLAG_DEFEATED_FUTO, AncientTomb_EventScript_ShowFuto
	end

AncientTomb_EventScript_ShowFuto::
	clearflag FLAG_HIDE_FUTO
	return

AncientTomb_OnLoad:
	call_if_unset FLAG_SYS_FUTO_PUZZLE_COMPLETED, AncientTomb_EventScript_HideRegiEntrance
	end

AncientTomb_EventScript_HideRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return

AncientTomb_EventScript_CaveEntranceMiddle::
	lockall
	goto_if_set FLAG_SYS_FUTO_PUZZLE_COMPLETED, AncientTomb_EventScript_BigHoleInWall
	braillemsgbox AncientTomb_Braille_ShineInTheMiddle
	releaseall
	end

AncientTomb_EventScript_BigHoleInWall::
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

AncientTomb_EventScript_CaveEntranceSide::
	lockall
	braillemsgbox AncientTomb_Braille_ShineInTheMiddle
	releaseall
	end

AncientTomb_EventScript_Futo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FUTO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_FUTO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AncientTomb_EventScript_DefeatedFuto
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AncientTomb_EventScript_RanFromFuto
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AncientTomb_EventScript_RanFromFuto
	setflag FLAG_DEFEATED_FUTO
	release
	end

AncientTomb_EventScript_DefeatedFuto::
	setflag FLAG_DEFEATED_FUTO
	goto Common_EventScript_RemoveStaticPokemon
	end

AncientTomb_EventScript_RanFromFuto::
	setvar VAR_0x8004, SPECIES_FUTO
	goto Common_EventScript_LegendaryFlewAway
	end

