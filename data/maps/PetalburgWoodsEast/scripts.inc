PetalburgWoodsEast_MapScripts::
	.byte 0

PetalburgWoodsEast_EventScript_LostBoy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE04_GET, PetalburgWoodsEast_EventScript_BeginMansionQuest
	msgbox PetalburgWoodsEast_Text_NobodyEnters, MSGBOX_NPC
	release
	end

PetalburgWoodsEast_EventScript_BeginMansionQuest::
	release
	end

PetalburgWoodsEast_EventScript_Lily::
	trainerbattle_single TRAINER_HEX_MANIAC_LILY, PetalburgWoodsEast_Text_ISenseSomethingOminous, PetalburgWoodsEast_Text_NoItCouldntBe
	msgbox PetalburgWoodsEast_Text_BeCarefulMyChild, MSGBOX_AUTOCLOSE
	end

PetalburgWoodsEast_Text_NobodyEnters::
	.string "Nobody enters the mansion! There's\n"
	.string "powerful POKéMON inside that could\l"
	.string "easily beat even the best trainers.$"

PetalburgWoodsEast_Text_OhYouSeemStrong::
	.string "Oh! You seem strong!$"

PetalburgWoodsEast_Text_ISenseSomethingOminous:
	.string "I sense something ominous in these\n"
	.string "woods. Is it you?$"

PetalburgWoodsEast_Text_NoItCouldntBe:
	.string "No… It couldn't be…$"

PetalburgWoodsEast_Text_BeCarefulMyChild:
	.string "Be careful, my child. Strange things \n"
	.string "lurk in the shadows of these trees.$"
