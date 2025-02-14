SootopolisCity_House6_MapScripts::
	.byte 0

SootopolisCity_House6_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DMEILING_DOLL, SootopolisCity_House6_EventScript_ReceivedDMeilingDoll
	msgbox SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, SootopolisCity_House6_EventScript_DeclineDMeilingDoll
	msgbox SootopolisCity_House6_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	givedecoration DECOR_DMEILING_DOLL
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_House6_EventScript_NoRoomForDMeilingDoll
	setflag FLAG_RECEIVED_DMEILING_DOLL
	release
	end

SootopolisCity_House6_EventScript_DeclineDMeilingDoll::
	msgbox SootopolisCity_House6_Text_DontWantThisDoll, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_ReceivedDMeilingDoll::
	msgbox SootopolisCity_House6_Text_LovePlushDolls, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_NoRoomForDMeilingDoll::
	bufferdecorationname STR_VAR_2, DECOR_DMEILING_DOLL
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	msgbox SootopolisCity_House6_Text_IllHoldItForYou, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll:
	.string "Hello! You're our first guest in\n"
	.string "a good while.\p"
	.string "You've brightened up my day, so I'll\n"
	.string "give you a big DMEILING DOLL.$"

SootopolisCity_House6_Text_TakeGoodCareOfIt:
	.string "Take good care of it!$"

SootopolisCity_House6_Text_IllHoldItForYou:
	.string "Oh, you want it, but not right now?\n"
	.string "Okay, then I'll hold it for you.$"

SootopolisCity_House6_Text_DontWantThisDoll:
	.string "Are you sure?\n"
	.string "You don't want this DOLL?$"

SootopolisCity_House6_Text_LovePlushDolls:
	.string "I love plush DOLLS!$"

