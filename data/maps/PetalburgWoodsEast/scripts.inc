PetalburgWoodsEast_MapScripts::
	.byte 0

PetalburgWoodsEast_EventScript_Lily::
	trainerbattle_single TRAINER_HEX_MANIAC_LILY, PetalburgWoodsEast_Text_ISenseSomethingOminous, PetalburgWoodsEast_Text_NoItCouldntBe
	msgbox PetalburgWoodsEast_Text_BeCarefulMyChild, MSGBOX_AUTOCLOSE
	end

PetalburgWoodsEast_Text_ISenseSomethingOminous:
	.string "I sense something ominous in these\n"
	.string "woods. Is it you?$"

PetalburgWoodsEast_Text_NoItCouldntBe:
	.string "No… It couldn't be…$"

PetalburgWoodsEast_Text_BeCarefulMyChild:
	.string "Be careful, my child. Strange things \n"
	.string "lurk in the shadows of these trees.$"
