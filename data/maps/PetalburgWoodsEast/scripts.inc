PetalburgWoodsEast_MapScripts::
	.byte 0

// ==== Lost Boy Mansion Quest =====================================================================
PetalburgWoodsEast_EventScript_LostBoy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE04_GET, PetalburgWoodsEast_EventScript_BeginMansionQuest
	msgbox PetalburgWoodsEast_Text_NobodyIsAllowed, MSGBOX_NPC
	release
	end

PetalburgWoodsEast_EventScript_BeginMansionQuest::
	applymovement LOCALID_LOST_BOY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LOST_BOY, PetalburgWoodsEast_Movement_LostBoyLookBack
	waitmovement 0
	msgbox PetalburgWoodsEast_Text_OhIsThat, MSGBOX_DEFAULT
	release
	end

PetalburgWoodsEast_Movement_LostBoyLookBack:
	face_up
	delay_16
	face_player
	step_end

PetalburgWoodsEast_Text_NobodyIsAllowed:
	.string "Nobody is allowed inside the house.\n"
	.string "It's too dangerous for trainers\l"
	.string "because of a bunch of strong POKéMON.$"

PetalburgWoodsEast_Text_OhIsThat:
	.string "Oh! Is that the BADGE from LAVARIDGE\n"
	.string "GYM? You must be pretty strong!\p"

// ==== Hex Maniac Lily ============================================================================
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
	.string "Be careful, my child. Strange things\n"
	.string "lurk in the shadows of these trees.$"
