.set LOCALID_TKOGASA, 3

MossdeepCity_House2_MapScripts::
	.byte 0

MossdeepCity_House2_EventScript_Man::
	msgbox MossdeepCity_House2_Text_SisterMailsBoyfriendInFortree, MSGBOX_NPC
	end

MossdeepCity_House2_EventScript_Twin::
	msgbox MossdeepCity_House2_Text_PokemonCarriesMailBackAndForth, MSGBOX_NPC
	end

MossdeepCity_House2_EventScript_TKogasa::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TKOGASA, CRY_MODE_NORMAL
	msgbox MossdeepCity_House2_Text_TKogasa, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	setflag FLAG_TKOGASA_DELIVERED_MAIL
	clearflag FLAG_HIDE_FORTREE_CITY_HOUSE_4_TKOGASA
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_House2_EventScript_TKogasaExitNorth
	call_if_eq VAR_FACING, DIR_WEST, MossdeepCity_House2_EventScript_TKogasaExitWest
	removeobject LOCALID_TKOGASA
	release
	end

MossdeepCity_House2_EventScript_TKogasaExitNorth::
	applymovement LOCALID_TKOGASA, MossdeepCity_House2_Movement_TKogasaExitNorth
	waitmovement 0
	return

MossdeepCity_House2_EventScript_TKogasaExitWest::
	applymovement LOCALID_TKOGASA, MossdeepCity_House2_Movement_TKogasaExitEast
	waitmovement 0
	return

MossdeepCity_House2_Movement_TKogasaExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	delay_8
	step_end

MossdeepCity_House2_Movement_TKogasaExitEast:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

MossdeepCity_House2_Text_SisterMailsBoyfriendInFortree:
	.string "My little sister exchanges MAIL with\n"
	.string "her boyfriend in FORTREE.\p"
	.string "I don't envy her one bit at all.$"

MossdeepCity_House2_Text_PokemonCarriesMailBackAndForth:
	.string "Even though I can't see my friend in\n"
	.string "FORTREE, my POKéMON carries MAIL\l"
	.string "back and forth for us.\p"
	.string "I'm not lonesome, even though we're\n"
	.string "apart.$"

MossdeepCity_House2_Text_TKogasa:
	.string "TKOGASA: Pihyoh!$"

