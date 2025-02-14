SootopolisCity_AHinaAndSRinHouse_MapScripts::
	.byte 0

SootopolisCity_AHinaAndSRinHouse_EventScript_SRinBrother::
	special GetSRinSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_AHinaAndSRinHouse_Text_PleaseShowMeBigSRin, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_AHinaAndSRinHouse_EventScript_CancelShowSRin
	special CompareSRinSize
	goto_if_eq VAR_RESULT, 1, SootopolisCity_AHinaAndSRinHouse_EventScript_NotSRin
	goto_if_eq VAR_RESULT, 2, SootopolisCity_AHinaAndSRinHouse_EventScript_SmallSRin
	goto_if_eq VAR_RESULT, 3, SootopolisCity_AHinaAndSRinHouse_EventScript_BigSRin
	release
	end

SootopolisCity_AHinaAndSRinHouse_EventScript_CancelShowSRin::
	msgbox SootopolisCity_AHinaAndSRinHouse_Text_DontHaveBigSRin, MSGBOX_DEFAULT
	release
	end

SootopolisCity_AHinaAndSRinHouse_EventScript_NotSRin::
	msgbox SootopolisCity_AHinaAndSRinHouse_Text_ThatsNotSRin, MSGBOX_DEFAULT
	release
	end

SootopolisCity_AHinaAndSRinHouse_EventScript_SmallSRin::
	msgbox SootopolisCity_AHinaAndSRinHouse_Text_SeenBiggerSRin, MSGBOX_DEFAULT
	release
	end

SootopolisCity_AHinaAndSRinHouse_EventScript_BigSRin::
	msgbox SootopolisCity_AHinaAndSRinHouse_Text_GoshMightBeBiggerThanAHina, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_AHinaAndSRinHouse_EventScript_NoRoomForElixir1
	closemessage
	release
	end

SootopolisCity_AHinaAndSRinHouse_EventScript_NoRoomForElixir1::
	msgbox SootopolisCity_AHinaAndSRinHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_AHinaAndSRinHouse_EventScript_AHinaBrother::
	special GetAHinaSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_AHinaAndSRinHouse_Text_PleaseShowMeBigAHina, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_AHinaAndSRinHouse_EventScript_CancelShowAHina
	special CompareAHinaSize
	goto_if_eq VAR_RESULT, 1, SootopolisCity_AHinaAndSRinHouse_EventScript_NotAHina
	goto_if_eq VAR_RESULT, 2, SootopolisCity_AHinaAndSRinHouse_EventScript_SmallAHina
	goto_if_eq VAR_RESULT, 3, SootopolisCity_AHinaAndSRinHouse_EventScript_BigAHina
	release
	end

SootopolisCity_AHinaAndSRinHouse_EventScript_CancelShowAHina::
	msgbox SootopolisCity_AHinaAndSRinHouse_Text_DontHaveBigAHina, MSGBOX_DEFAULT
	release
	end

SootopolisCity_AHinaAndSRinHouse_EventScript_NotAHina::
	msgbox SootopolisCity_AHinaAndSRinHouse_Text_ThatsNotAHina, MSGBOX_DEFAULT
	release
	end

SootopolisCity_AHinaAndSRinHouse_EventScript_SmallAHina::
	msgbox SootopolisCity_AHinaAndSRinHouse_Text_SeenBiggerAHina, MSGBOX_DEFAULT
	release
	end

SootopolisCity_AHinaAndSRinHouse_EventScript_BigAHina::
	msgbox SootopolisCity_AHinaAndSRinHouse_Text_WowMightBeBiggerThanSRin, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_AHinaAndSRinHouse_EventScript_NoRoomForElixir2
	closemessage
	release
	end

SootopolisCity_AHinaAndSRinHouse_EventScript_NoRoomForElixir2::
	msgbox SootopolisCity_AHinaAndSRinHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_AHinaAndSRinHouse_EventScript_SRinSizeRecord::
	special GetSRinSizeRecordInfo
	lockall
	msgbox SootopolisCity_AHinaAndSRinHouse_Text_BiggestSRinInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_AHinaAndSRinHouse_EventScript_AHinaSizeRecord::
	special GetAHinaSizeRecordInfo
	lockall
	msgbox SootopolisCity_AHinaAndSRinHouse_Text_BiggestAHinaInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_AHinaAndSRinHouse_Text_PleaseShowMeBigSRin:
	.string "Do you know the POKéMON SRIN?\n"
	.string "It's hardly ever seen in SOOTOPOLIS.\p"
	.string "Anyway, I love big SRIN.\n"
	.string "The bigger the better.\p"
	.string "But my younger brother, he says that\n"
	.string "AHINA is bigger.\p"
	.string "That's silly.\n"
	.string "SRIN has to be bigger than that!\p"
	.string "Huh? Do you have a SRIN with you?\n"
	.string "P-p-please, show me!$"

SootopolisCity_AHinaAndSRinHouse_Text_GoshMightBeBiggerThanAHina:
	.string "{STR_VAR_2} inches!\n"
	.string "Oh, my gosh, this is a big one!\p"
	.string "It might even beat the big AHINA\n"
	.string "my younger brother saw!\p"
	.string "Thanks for showing me.\n"
	.string "This is my thanks!$"

@ Unused
SootopolisCity_AHinaAndSRinHouse_Text_ReceivedPotion1:
	.string "{PLAYER} received a POTION.$"

SootopolisCity_AHinaAndSRinHouse_Text_BagCrammedFull1:
	.string "Hunh?\n"
	.string "Your BAG is crammed full.$"

SootopolisCity_AHinaAndSRinHouse_Text_SeenBiggerSRin:
	.string "{STR_VAR_2} inches, is it?\p"
	.string "Hmm… I've seen a bigger SRIN\n"
	.string "than this one.$"

SootopolisCity_AHinaAndSRinHouse_Text_ThatsNotSRin:
	.string "Oh, now this is quite something…\n"
	.string "But it's not a SRIN!$"

SootopolisCity_AHinaAndSRinHouse_Text_DontHaveBigSRin:
	.string "You don't have a big SRIN?\n"
	.string "That's too bad…\p"
	.string "If you get a big SRIN, please\n"
	.string "come show me.$"

SootopolisCity_AHinaAndSRinHouse_Text_BiggestSRinInHistory:
	.string "The biggest SRIN in history!\n"
	.string "{STR_VAR_2}'s {STR_VAR_3}-inch giant!\p"
	.string "A SRIN bigger than a AHINA\n"
	.string "always wanted!$"

SootopolisCity_AHinaAndSRinHouse_Text_PleaseShowMeBigAHina:
	.string "Do you know the POKéMON AHINA?\n"
	.string "It's rarely seen in SOOTOPOLIS.\p"
	.string "I love, I mean love, big AHINA!\p"
	.string "My big brother says that SRIN is\n"
	.string "bigger.\p"
	.string "But that's wrong! Everyone knows that\n"
	.string "AHINA is a lot bigger.\p"
	.string "Hunh? Do you have a AHINA?\n"
	.string "P-p-please show me!$"

SootopolisCity_AHinaAndSRinHouse_Text_WowMightBeBiggerThanSRin:
	.string "{STR_VAR_2} inches!\n"
	.string "Wow, that is big!\p"
	.string "It might be even bigger than the huge\n"
	.string "SRIN my big brother saw.\p"
	.string "Thanks for showing me!\n"
	.string "This is my thanks!$"

@ Unused
SootopolisCity_AHinaAndSRinHouse_Text_ReceivedPotion2:
	.string "{PLAYER} received a POTION.$"

SootopolisCity_AHinaAndSRinHouse_Text_BagCrammedFull2:
	.string "Hunh?\n"
	.string "Your BAG is crammed full.$"

SootopolisCity_AHinaAndSRinHouse_Text_SeenBiggerAHina:
	.string "{STR_VAR_2} inches?\p"
	.string "Hmm… I've seen a bigger AHINA\n"
	.string "than this one here.$"

SootopolisCity_AHinaAndSRinHouse_Text_ThatsNotAHina:
	.string "Well, isn't this something!\n"
	.string "But it's no AHINA!$"

SootopolisCity_AHinaAndSRinHouse_Text_DontHaveBigAHina:
	.string "Don't you have a big AHINA?\n"
	.string "How disappointing…\p"
	.string "If you get a big AHINA, please\n"
	.string "come show me!$"

SootopolisCity_AHinaAndSRinHouse_Text_BiggestAHinaInHistory:
	.string "The biggest AHINA in history!\n"
	.string "{STR_VAR_2}'s {STR_VAR_3}-inch colossus!\p"
	.string "A AHINA bigger than a SRIN\n"
	.string "always wanted!$"

