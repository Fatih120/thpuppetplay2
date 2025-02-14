BattleFrontier_ExchangeServiceCorner_MapScripts::
	.byte 0

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	return

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize::
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor::
	checkdecorspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	adddecoration VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_PCIsFull, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem::
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_BagFull
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	additem VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_BagFull::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk1::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_DKanakoDoll
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_MargatroidDoll
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_CChenDoll
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_CYukariDoll
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_KedamaDoll
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_CEllyDoll
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_GenjiiDoll
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_OrangeDoll
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissPoster, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, DECOR_KISS_POSTER
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissCushion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_KISS_CUSHION
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DKanakoDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmDKanakoDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_DKANAKO_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MargatroidDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMargatroidDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_MARGATROID_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_CChenDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCChenDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_CCHEN_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_CYukariDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCYukariDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_CYUKARI_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KedamaDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKedamaDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_KEDAMA_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_CEllyDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCEllyDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CELLY_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_GenjiiDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmGenjiiDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_GENJII_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_OrangeDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmOrangeDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_ORANGE_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk2::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_TewiDoll
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_ByakurenDoll
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_CAliceDoll
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_ReisenDoll
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_CLilyBlackDoll
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TewiDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmTewiDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_TEWI_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ByakurenDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmByakurenDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_BYAKUREN_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_CAliceDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCAliceDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_CALICE_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ReisenDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmReisenDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_REISEN_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_CLilyBlackDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCLilyBlackDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_CLILYBLACK_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Protein
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_Calcium
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_Iron
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_Zinc
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Carbos
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_HPUp
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Protein::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmProtein, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_PROTEIN
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Calcium::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalcium, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CALCIUM
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Iron::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmIron, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_IRON
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Zinc::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmZinc, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_ZINC
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Carbos::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarbos, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CARBOS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HPUp::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmHPUp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_HP_UP
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_LEFTOVERS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_WHITE_HERB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_QUICK_CLAW
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_MENTAL_HERB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_BRIGHT_POWDER
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_CHOICE_BAND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_KINGS_ROCK
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_FOCUS_BAND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_SCOPE_LENS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Man::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Sailor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Girl::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "Hello, this is the EXCHANGE SERVICE\n"
	.string "CORNER.\p"
	.string "We exchange the Battle Points you\n"
	.string "have collected for lovely prizes.\p"
	.string "Please choose a prize from this list.$"

@ Unused
BattleFrontier_ExchangeServiceCorner_Text_PleaseChoosePrize:
	.string "Please choose a prize from this list.$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissPoster:
	.string "You've chosen the KISS POSTER.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissCushion:
	.string "You've chosen the KISS CUSHION.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmDKanakoDoll:
	.string "You've chosen the DKANAKO DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMargatroidDoll:
	.string "You've chosen the MARGATROID DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCChenDoll:
	.string "You've chosen the CCHEN DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCYukariDoll:
	.string "You've chosen the CYUKARI DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKedamaDoll:
	.string "You've chosen the KEDAMA DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCEllyDoll:
	.string "You've chosen the CELLY DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmGenjiiDoll:
	.string "You've chosen the GENJII DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmOrangeDoll:
	.string "You've chosen the ORANGE DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmTewiDoll:
	.string "You've chosen the TEWI DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmByakurenDoll:
	.string "You've chosen the BYAKUREN DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCAliceDoll:
	.string "You've chosen the CALICE DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmReisenDoll:
	.string "You've chosen the REISEN DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCLilyBlackDoll:
	.string "You've chosen the CLILYBLACK DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmProtein:
	.string "You've chosen the PROTEIN.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalcium:
	.string "You've chosen the CALCIUM.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmIron:
	.string "You've chosen the IRON.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmZinc:
	.string "You've chosen the ZINC.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarbos:
	.string "You've chosen the CARBOS.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmHPUp:
	.string "You've chosen the HP UP.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder:
	.string "You've chosen the BRIGHTPOWDER.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb:
	.string "You've chosen the WHITE HERB.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw:
	.string "You've chosen the QUICK CLAW.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb:
	.string "You've chosen the MENTAL HERB.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand:
	.string "You've chosen the CHOICE BAND.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock:
	.string "You've chosen the KING'S ROCK.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand:
	.string "You've chosen the FOCUS BAND.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens:
	.string "You've chosen the SCOPE LENS.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers:
	.string "You've chosen the LEFTOVERS.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC:
	.string "Thank you!\n"
	.string "We'll send it to your PC at home.$"

BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize:
	.string "Here is your prize!$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
	.string "I'm so sorry…\n"
	.string "You don't have enough Battle Points…$"

BattleFrontier_ExchangeServiceCorner_Text_PCIsFull:
	.string "I'm so sorry…\n"
	.string "Your PC appears to be full…$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
	.string "I'm so sorry…\n"
	.string "You don't have space to hold it…$"

BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.string "Thank you very much.\p"
	.string "Please visit us when you have\n"
	.string "saved up Battle Points.$"

BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.string "Oh, they're so nice!\n"
	.string "I wish I had them!\l"
	.string "Cute cushions!\l"
	.string "Big plush DOLLS!\l"
	.string "Little plush DOLLS!\l"
	.string "I wish I had them all!$"

BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.string "Leave it to your mommy!\p"
	.string "If it's anything you want, I'll go\n"
	.string "through anything to get it, honey!$"

BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "If I can get hold of the items here,\n"
	.string "my POKéMON will get tougher.\p"
	.string "You bet they will!\n"
	.string "No question about it!$"

BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.string "Hah?\n"
	.string "What are you gawking at?\p"
	.string "I don't like you staring at my plush\n"
	.string "doll like that.\p"
	.string "If you want it, go get one yourself!\n"
	.string "Isn't that right, DKANAKO?$"

BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "Did you know?\p"
	.string "If you stretch your record at any of\n"
	.string "the BATTLE facilities, they start\l"
	.string "giving you more and more Battle Points.$"

BattleFrontier_ExchangeServiceCorner_Text_KissPosterDesc::
	.string "A large poster with a DKANAKO print.$"

BattleFrontier_ExchangeServiceCorner_Text_KissCushionDesc::
	.string "A DKANAKO cushion.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_DKanakoDollDesc::
	.string "A DKANAKO DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_MargatroidDollDesc::
	.string "A MARGATROID DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_CChenDollDesc::
	.string "A CCHEN DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_CYukariDollDesc::
	.string "A CYUKARI DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_KedamaDollDesc::
	.string "A KEDAMA DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_CEllyDollDesc::
	.string "A CELLY DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_GenjiiDollDesc::
	.string "A GENJII DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_OrangeDollDesc::
	.string "A ORANGE DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_LargeDollDesc::
	.string "A large DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_ProteinDesc::
	.string "Raises the stat ATTACK of one\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_CalciumDesc::
	.string "Raises the stat SP. ATK of one\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_IronDesc::
	.string "Raises the stat DEFENSE of one\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_ZincDesc::
	.string "Raises the stat SP. DEF of one\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_CarbosDesc::
	.string "Raises the stat SPEED of one\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_HPUpDesc::
	.string "Raises the HP of one POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_LeftoversDesc::
	.string "A hold item that gradually restores\n"
	.string "HP in battle.$"

BattleFrontier_ExchangeServiceCorner_Text_WhiteHerbDesc::
	.string "A hold item that restores any\n"
	.string "lowered stat.$"

BattleFrontier_ExchangeServiceCorner_Text_QuickClawDesc::
	.string "A hold item that occasionally allows\n"
	.string "the first strike.$"

BattleFrontier_ExchangeServiceCorner_Text_MentalHerbDesc::
	.string "A hold item that snaps POKéMON out\n"
	.string "of infatuation.$"

BattleFrontier_ExchangeServiceCorner_Text_BrightpowderDesc::
	.string "A hold item that casts a glare to\n"
	.string "reduce accuracy.$"

BattleFrontier_ExchangeServiceCorner_Text_ChoiceBandDesc::
	.string "Raises a move's power, but permits\n"
	.string "only that move.$"

BattleFrontier_ExchangeServiceCorner_Text_KingsRockDesc::
	.string "A hold item that may cause flinching\n"
	.string "when the foe is hit.$"

BattleFrontier_ExchangeServiceCorner_Text_FocusBandDesc::
	.string "A hold item that occasionally\n"
	.string "prevents fainting.$"

BattleFrontier_ExchangeServiceCorner_Text_ScopeLensDesc::
	.string "A hold item that raises the\n"
	.string "critical-hit rate.$"
