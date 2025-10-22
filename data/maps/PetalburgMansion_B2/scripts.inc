PetalburgMansion_B2_MapScripts::
	.byte 0

@ Script for lost boy hiding
PetalburgMansion_F2_LostBoy::
	lock
	faceplayer
	msgbox PetalburgMansion_F2_Text_AhhhStayAway, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_LOST_MANSION_BOY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LOST_MANSION_BOY, Common_Movement_Delay48
	waitmovement 0
	msgbox PetalburgMansion_F2_Text_WaitYoureNot, MSGBOX_DEFAULT
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_eq VAR_TEMP_1, 5, PetalburgMansion_F2_LostBoyTalkRight
	goto_if_eq VAR_TEMP_1, 4 PetalburgMansion_F2_LostBoyTalkUp

@ Player is to the right of the boy
PetalburgMansion_F2_LostBoyTalkRight::
	applymovement LOCALID_LOST_MANSION_BOY, PetalburgMansion_F2_Movement_WalkInPlaceRight
	waitmovement 0
	goto PetalburgMansion_F2_LostBoySecondPart

@ Player is to the top of the boy
PetalburgMansion_F2_LostBoyTalkUp::
	applymovement LOCALID_LOST_MANSION_BOY, PetalburgMansion_F2_Movement_WalkInPlaceUp
	waitmovement 0
	goto PetalburgMansion_F2_LostBoySecondPart

PetalburgMansion_F2_Movement_WalkInPlaceRight:
	walk_in_place_right
	step_end

PetalburgMansion_F2_Movement_WalkInPlaceUp:
	walk_in_place_up
	step_end

@ Continue script after movement
PetalburgMansion_F2_LostBoySecondPart::
	msgbox PetalburgMansion_F2_Text_IDidntBelieve, MSGBOX_DEFAULT
	msgbox PetalburgMansion_F2_Text_NowThatYouve, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_eq VAR_TEMP_1, 4, PetalburgMansion_F2_LostBoyLeaveRight
	goto_if_eq VAR_TEMP_1, 5, PetalburgMansion_F2_LostBoyLeaveUp

@ Lost boy leave when player is to the north
PetalburgMansion_F2_LostBoyLeaveRight::
	applymovement LOCALID_LOST_MANSION_BOY, PetalburgMansion_F2_Movement_LeaveRight
	closemessage
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_MANSION_F2_LOST_BOY
	removeobject LOCALID_LOST_MANSION_BOY
	goto PetalburgMansion_F2_EndScript

@ Lost boy leave when player is to the east
PetalburgMansion_F2_LostBoyLeaveUp::
	applymovement LOCALID_LOST_MANSION_BOY, PetalburgMansion_F2_Movement_LeaveUp
	closemessage
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_MANSION_F2_LOST_BOY
	removeobject LOCALID_LOST_MANSION_BOY
	goto PetalburgMansion_F2_EndScript

PetalburgMansion_F2_Movement_LeaveRight:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

PetalburgMansion_F2_Movement_LeaveUp:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

@ End the script
PetalburgMansion_F2_EndScript::
	release
	end

PetalburgMansion_F2_Text_AhhhStayAway:
	.string "Ahhh!\n"
	.string "Stay away you GHOST!$"

PetalburgMansion_F2_Text_WaitYoureNot:
	.string "Wait a minute…\n"
	.string "You're not a GHOST POKéMON.\p"
	.string "Phew, thank goodness, too!\p"
	.string "I don't think I could handle it if I\n"
	.string "encountered a wild POKéMON.$"

PetalburgMansion_F2_Text_IDidntBelieve:
	.string "I didn't believe my friend when he said\n"
	.string "this place was spooky, so he dared me\l"
	.string "to go inside.\p"
	.string "It didn't take me long to get lost,\n"
	.string "though, and I was too scared to go\l"
	.string "looking for the exit.$"

PetalburgMansion_F2_Text_NowThatYouve:
	.string "Now that you made it here, I think I can\n"
	.string "find my way back.\p"
	.string "Oh!\n"
	.string "Before I go!\p"
	.string "Take this as a thanks for looking for\n"
	.string "me.$"
