MysteryGiftScript_SurfCLuize::
	setvaddress MysteryGiftScript_SurfCLuize
	vgoto_if_unset FLAG_MYSTERY_GIFT_DONE, SurfCLuize_GiveIfPossible
	returnram

SurfCLuize_GiveIfPossible:
	specialvar VAR_GIFT_CLUIZE_SLOT, CalculatePlayerPartyCount
	vgoto_if_eq VAR_GIFT_CLUIZE_SLOT, PARTY_SIZE, SurfCLuize_FullParty
	setflag FLAG_MYSTERY_GIFT_DONE
	vcall SurfCLuize_GiveEgg
	lock
	faceplayer
	vmessage sText_MysteryGiftEgg
	waitmessage
	waitbuttonpress
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	release
	end

SurfCLuize_FullParty:
	lock
	faceplayer
	vmessage sText_FullParty
	waitmessage
	waitbuttonpress
	release
	end

SurfCLuize_GiveEgg:
	giveegg SPECIES_CLUIZE
	setmodernfatefulencounter VAR_GIFT_CLUIZE_SLOT
	setmonmetlocation VAR_GIFT_CLUIZE_SLOT, METLOC_FATEFUL_ENCOUNTER
	vgoto_if_eq VAR_GIFT_CLUIZE_SLOT, 1, SurfCLuize_Slot1
	vgoto_if_eq VAR_GIFT_CLUIZE_SLOT, 2, SurfCLuize_Slot2
	vgoto_if_eq VAR_GIFT_CLUIZE_SLOT, 3, SurfCLuize_Slot3
	vgoto_if_eq VAR_GIFT_CLUIZE_SLOT, 4, SurfCLuize_Slot4
	vgoto_if_eq VAR_GIFT_CLUIZE_SLOT, 5, SurfCLuize_Slot5
	return

SurfCLuize_Slot1:
	setmonmove 1, 2, MOVE_SURF
	return

SurfCLuize_Slot2::
	setmonmove 2, 2, MOVE_SURF
	return

SurfCLuize_Slot3:
	setmonmove 3, 2, MOVE_SURF
	return

SurfCLuize_Slot4:
	setmonmove 4, 2, MOVE_SURF
	return

SurfCLuize_Slot5:
	setmonmove 5, 2, MOVE_SURF
	return

sText_MysteryGiftEgg:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "From the POKéMON CENTER we\n"
	.string "have a gift--a POKéMON EGG!\p"
	.string "Please raise it with love and\n"
	.string "kindness.$"

sText_FullParty:
	.string "Oh, your party appears to be full.\p"
	.string "Please come see me after storing\n"
	.string "a POKéMON on a PC.$"
