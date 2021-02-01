.set LOCALID_WINGULL, 3

MossdeepCity_House2_MapScripts:: @ 82220DE
	.byte 0

MossdeepCity_House2_EventScript_Man:: @ 82220DF
	msgbox MossdeepCity_House2_Text_SisterMailsBoyfriendInFortree, MSGBOX_NPC
	end

MossdeepCity_House2_EventScript_Twin:: @ 82220E8
	msgbox MossdeepCity_House2_Text_PokemonCarriesMailBackAndForth, MSGBOX_NPC
	end

MossdeepCity_House2_EventScript_TKogasa:: @ 82220F1
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TKOGASA, 0
	msgbox MossdeepCity_House2_Text_TKogasa, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	setflag FLAG_TKOGASA_DELIVERED_MAIL
	clearflag FLAG_HIDE_FORTREE_CITY_HOUSE_4_TKOGASA
	compare VAR_FACING, DIR_NORTH
	call_if_eq MossdeepCity_House2_EventScript_TKogasaExitNorth
	compare VAR_FACING, DIR_WEST
	call_if_eq MossdeepCity_House2_EventScript_TKogasaExitWest
	removeobject 3
	release
	end

MossdeepCity_House2_EventScript_TKogasaExitNorth:: @ 8222124
	applymovement 3, MossdeepCity_House2_Movement_TKogasaExitNorth
	waitmovement 0
	return

MossdeepCity_House2_EventScript_TKogasaExitWest:: @ 822212F
	applymovement 3, MossdeepCity_House2_Movement_TKogasaExitEast
	waitmovement 0
	return

MossdeepCity_House2_Movement_TKogasaExitNorth: @ 822213A
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	delay_8
	step_end

MossdeepCity_House2_Movement_TKogasaExitEast: @ 8222141
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

MossdeepCity_House2_Text_SisterMailsBoyfriendInFortree: @ 8222146
	.string "My little sister exchanges MAIL with\n"
	.string "her boyfriend in FORTREE.\p"
	.string "I don't envy her one bit at all.$"

MossdeepCity_House2_Text_PokemonCarriesMailBackAndForth: @ 82221A6
	.string "Even though I can't see my friend in\n"
	.string "FORTREE, my POKéMON carries MAIL\l"
	.string "back and forth for us.\p"
	.string "I'm not lonesome, even though we're\n"
	.string "apart.$"

MossdeepCity_House2_Text_TKogasa: @ 822222E
	.string "TKOGASA: Pihyoh!$"

