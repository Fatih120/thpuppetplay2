Route120_EventScript_SWriggle1:: @ 82722DB
	lock
	faceplayer
	setvar VAR_0x8009, 1
	goto EventScript_SWriggle
	end

Route120_EventScript_SWriggle2:: @ 82722E8
	lock
	faceplayer
	setvar VAR_0x8009, 2
	goto EventScript_SWriggle
	end

Route120_EventScript_SWriggle3:: @ 82722F5
	lock
	faceplayer
	setvar VAR_0x8009, 3
	goto EventScript_SWriggle
	end

Route120_EventScript_SWriggle4:: @ 8272302
	lock
	faceplayer
	setvar VAR_0x8009, 4
	goto EventScript_SWriggle
	end

Route120_EventScript_SWriggle5:: @ 827230F
	lock
	faceplayer
	setvar VAR_0x8009, 5
	goto EventScript_SWriggle
	end

Route119_EventScript_SWriggle1:: @ 827231C
	lock
	faceplayer
	setvar VAR_0x8009, 6
	goto EventScript_SWriggle
	end

Route119_EventScript_SWriggle2:: @ 8272329
	lock
	faceplayer
	setvar VAR_0x8009, 7
	goto EventScript_SWriggle
	end

EventScript_SWriggle:: @ 8272336
	checkitem ITEM_DEVON_SCOPE, 1
	compare VAR_RESULT, 1
	goto_if_eq EventScript_AskUseDevonScope
	msgbox SWriggle_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

EventScript_AskUseDevonScope:: @ 8272350
	msgbox SWriggle_Text_WantToUseDevonScope, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_BattleSWriggle
	release
	end

EventScript_BattleSWriggle:: @ 8272365
	msgbox SWriggle_Text_UseDevonScopeMonAttacked, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	applymovement VAR_LAST_TALKED, Movement_SWriggleAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_SWRIGGLE, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_SWRIGGLE, 30, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EventScript_RemoveSWriggle
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq EventScript_RemoveSWriggle
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq EventScript_RemoveSWriggle
	release
	end

EventScript_RemoveSWriggle:: @ 82723C1
	goto Common_EventScript_RemoveStaticPokemon
	end

Movement_SWriggleAppears: @ 82723C7
	set_visible
	delay_4
	set_invisible
	delay_4
	set_visible
	delay_4
	set_invisible
	delay_4
	set_visible
	delay_8
	set_invisible
	delay_8
	set_visible
	delay_8
	set_invisible
	delay_8
	set_visible
	delay_16
	set_invisible
	delay_16
	set_visible
	step_end
