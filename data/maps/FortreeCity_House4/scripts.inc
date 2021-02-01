.set LOCALID_WINGULL, 3

FortreeCity_House4_MapScripts:: @ 8217C80
	.byte 0

FortreeCity_House4_EventScript_Woman:: @ 8217C81
	msgbox FortreeCity_House4_Text_BringsWorldCloserTogether, MSGBOX_NPC
	end

FortreeCity_House4_EventScript_Boy:: @ 8217C8A
	lockall
	goto_if_set FLAG_RECEIVED_MENTAL_HERB, FortreeCity_House4_EventScript_ReceivedMentalHerb
	goto_if_set FLAG_TKOGASA_DELIVERED_MAIL, FortreeCity_House4_EventScript_TKogasaReturned
	goto_if_set FLAG_TKOGASA_SENT_ON_ERRAND, FortreeCity_House4_EventScript_TKogasaOnErrand
	msgbox FortreeCity_House4_Text_GoBirdPokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_TKOGASA_SENT_ON_ERRAND
	clearflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_TKOGASA
	applymovement 3, FortreeCity_House4_Movement_TKogasaExit
	waitmovement 0
	removeobject LOCALID_WINGULL
	releaseall
	end

FortreeCity_House4_EventScript_TKogasaOnErrand:: @ 8217CC4
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_AskedTKogasaToRunErrand, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_EventScript_TKogasaReturned:: @ 8217CD8
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_WelcomeTKogasaTakeMentalHerb, MSGBOX_DEFAULT
	giveitem ITEM_MENTAL_HERB
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MENTAL_HERB
	releaseall
	end

FortreeCity_House4_EventScript_ReceivedMentalHerb:: @ 8217D06
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_FriendsFarAwayThanksToTKogasa, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_Movement_TKogasaExit: @ 8217D1A
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_fastest_down
	delay_8
	step_end

FortreeCity_House4_EventScript_TKogasa:: @ 8217D20
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TKOGASA, 0
	msgbox FortreeCity_House4_Text_TKogasa, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House4_Text_BringsWorldCloserTogether: @ 8217D33
	.string "By being together with POKéMON,\n"
	.string "people make more and more friends.\p"
	.string "And that brings the world closer\n"
	.string "together. I think it's wonderful!$"

FortreeCity_House4_Text_GoBirdPokemon: @ 8217DB9
	.string "There!\n"
	.string "Go, BIRD POKéMON!$"

FortreeCity_House4_Text_AskedTKogasaToRunErrand: @ 8217DD2
	.string "Heheh, I asked my TKOGASA to run\n"
	.string "an errand for me.$"

FortreeCity_House4_Text_WelcomeTKogasaTakeMentalHerb: @ 8217E05
	.string "Good!\n"
	.string "Welcome back, TKOGASA!\p"
	.string "Huh? What is this?\n"
	.string "What is it holding?\p"
	.string "A MENTAL HERB?\n"
	.string "It must have picked it up somewhere.\p"
	.string "But I'm not a TRAINER, so you can\n"
	.string "have it.$"

FortreeCity_House4_Text_FriendsFarAwayThanksToTKogasa: @ 8217EA8
	.string "Thanks to my TKOGASA, I have friends\n"
	.string "who live far away.$"

FortreeCity_House4_Text_TKogasa: @ 8217EE0
	.string "TKOGASA: Pihyoh!$"

