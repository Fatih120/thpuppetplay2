.set LOCALID_TKOGASA, 3

FortreeCity_House4_MapScripts::
	.byte 0

FortreeCity_House4_EventScript_Woman::
	msgbox FortreeCity_House4_Text_BringsWorldCloserTogether, MSGBOX_NPC
	end

FortreeCity_House4_EventScript_Boy::
	lockall
	goto_if_set FLAG_RECEIVED_MENTAL_HERB, FortreeCity_House4_EventScript_ReceivedMentalHerb
	goto_if_set FLAG_TKOGASA_DELIVERED_MAIL, FortreeCity_House4_EventScript_TKogasaReturned
	goto_if_set FLAG_TKOGASA_SENT_ON_ERRAND, FortreeCity_House4_EventScript_TKogasaOnErrand
	msgbox FortreeCity_House4_Text_GoBirdPokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_TKOGASA_SENT_ON_ERRAND
	clearflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_TKOGASA
	applymovement LOCALID_TKOGASA, FortreeCity_House4_Movement_TKogasaExit
	waitmovement 0
	removeobject LOCALID_TKOGASA
	releaseall
	end

FortreeCity_House4_EventScript_TKogasaOnErrand::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_AskedTKogasaToRunErrand, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_EventScript_TKogasaReturned::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_WelcomeTKogasaTakeMentalHerb, MSGBOX_DEFAULT
	giveitem ITEM_MENTAL_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MENTAL_HERB
	releaseall
	end

FortreeCity_House4_EventScript_ReceivedMentalHerb::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_FriendsFarAwayThanksToTKogasa, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_Movement_TKogasaExit:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_down
	delay_8
	step_end

FortreeCity_House4_EventScript_TKogasa::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TKOGASA, CRY_MODE_NORMAL
	msgbox FortreeCity_House4_Text_TKogasa, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House4_Text_BringsWorldCloserTogether:
	.string "By being together with POKéMON,\n"
	.string "people make more and more friends.\p"
	.string "And that brings the world closer\n"
	.string "together. I think it's wonderful!$"

FortreeCity_House4_Text_GoBirdPokemon:
	.string "There!\n"
	.string "Go, BIRD POKéMON!$"

FortreeCity_House4_Text_AskedTKogasaToRunErrand:
	.string "Heheh, I asked my TKOGASA to run\n"
	.string "an errand for me.$"

FortreeCity_House4_Text_WelcomeTKogasaTakeMentalHerb:
	.string "Good!\n"
	.string "Welcome back, TKOGASA!\p"
	.string "Huh? What is this?\n"
	.string "What is it holding?\p"
	.string "A MENTAL HERB?\n"
	.string "It must have picked it up somewhere.\p"
	.string "But I'm not a TRAINER, so you can\n"
	.string "have it.$"

FortreeCity_House4_Text_FriendsFarAwayThanksToTKogasa:
	.string "Thanks to my TKOGASA, I have friends\n"
	.string "who live far away.$"

FortreeCity_House4_Text_TKogasa:
	.string "TKOGASA: Pihyoh!$"

