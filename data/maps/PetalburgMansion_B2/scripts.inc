# 1 "data/maps/PetalburgMansion_B2/scripts.pory"

# 2 "data/maps/PetalburgMansion_B2/scripts.pory"
PetalburgMansion_B2_MapScripts::
# 3 "data/maps/PetalburgMansion_B2/scripts.pory"
	.byte 0
# 4 "data/maps/PetalburgMansion_B2/scripts.pory"

# 5 "data/maps/PetalburgMansion_B2/scripts.pory"
@ Script for lost boy hiding
# 6 "data/maps/PetalburgMansion_B2/scripts.pory"
PetalburgMansion_F2_LostBoy::
# 7 "data/maps/PetalburgMansion_B2/scripts.pory"
	lock
# 8 "data/maps/PetalburgMansion_B2/scripts.pory"
	faceplayer
# 9 "data/maps/PetalburgMansion_B2/scripts.pory"
	msgbox PetalburgMansion_F2_Text_AhhhStayAway, MSGBOX_DEFAULT
# 10 "data/maps/PetalburgMansion_B2/scripts.pory"
	playse SE_PIN
# 11 "data/maps/PetalburgMansion_B2/scripts.pory"
	applymovement LOCALID_LOST_MANSION_BOY, Common_Movement_ExclamationMark
# 12 "data/maps/PetalburgMansion_B2/scripts.pory"
	waitmovement 0
# 13 "data/maps/PetalburgMansion_B2/scripts.pory"
	applymovement LOCALID_LOST_MANSION_BOY, Common_Movement_Delay48
# 14 "data/maps/PetalburgMansion_B2/scripts.pory"
	waitmovement 0
# 15 "data/maps/PetalburgMansion_B2/scripts.pory"
	msgbox PetalburgMansion_F2_Text_WaitYoureNot, MSGBOX_DEFAULT
# 16 "data/maps/PetalburgMansion_B2/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 17 "data/maps/PetalburgMansion_B2/scripts.pory"
	goto_if_eq VAR_TEMP_1, 5, PetalburgMansion_F2_LostBoyTalkRight
# 18 "data/maps/PetalburgMansion_B2/scripts.pory"
	goto_if_eq VAR_TEMP_1, 4 PetalburgMansion_F2_LostBoyTalkUp
# 19 "data/maps/PetalburgMansion_B2/scripts.pory"

# 20 "data/maps/PetalburgMansion_B2/scripts.pory"
@ Player is to the right of the boy
# 21 "data/maps/PetalburgMansion_B2/scripts.pory"
PetalburgMansion_F2_LostBoyTalkRight::
# 22 "data/maps/PetalburgMansion_B2/scripts.pory"
	applymovement LOCALID_LOST_MANSION_BOY, PetalburgMansion_F2_Movement_WalkInPlaceRight
# 23 "data/maps/PetalburgMansion_B2/scripts.pory"
	waitmovement 0
# 24 "data/maps/PetalburgMansion_B2/scripts.pory"
	goto PetalburgMansion_F2_LostBoySecondPart
# 25 "data/maps/PetalburgMansion_B2/scripts.pory"

# 26 "data/maps/PetalburgMansion_B2/scripts.pory"
@ Player is to the top of the boy
# 27 "data/maps/PetalburgMansion_B2/scripts.pory"
PetalburgMansion_F2_LostBoyTalkUp::
# 28 "data/maps/PetalburgMansion_B2/scripts.pory"
	applymovement LOCALID_LOST_MANSION_BOY, PetalburgMansion_F2_Movement_WalkInPlaceUp
# 29 "data/maps/PetalburgMansion_B2/scripts.pory"
	waitmovement 0
# 30 "data/maps/PetalburgMansion_B2/scripts.pory"
	goto PetalburgMansion_F2_LostBoySecondPart
# 31 "data/maps/PetalburgMansion_B2/scripts.pory"

# 32 "data/maps/PetalburgMansion_B2/scripts.pory"
PetalburgMansion_F2_Movement_WalkInPlaceRight:
# 33 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_in_place_right
# 34 "data/maps/PetalburgMansion_B2/scripts.pory"
	step_end
# 35 "data/maps/PetalburgMansion_B2/scripts.pory"

# 36 "data/maps/PetalburgMansion_B2/scripts.pory"
PetalburgMansion_F2_Movement_WalkInPlaceUp:
# 37 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_in_place_up
# 38 "data/maps/PetalburgMansion_B2/scripts.pory"
	step_end
# 39 "data/maps/PetalburgMansion_B2/scripts.pory"

# 40 "data/maps/PetalburgMansion_B2/scripts.pory"
@ Continue script after movement
# 41 "data/maps/PetalburgMansion_B2/scripts.pory"
PetalburgMansion_F2_LostBoySecondPart::
# 42 "data/maps/PetalburgMansion_B2/scripts.pory"
	msgbox PetalburgMansion_F2_Text_IDidntBelieve, MSGBOX_DEFAULT
# 43 "data/maps/PetalburgMansion_B2/scripts.pory"
	msgbox PetalburgMansion_F2_Text_NowThatYouve, MSGBOX_DEFAULT
# 44 "data/maps/PetalburgMansion_B2/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 45 "data/maps/PetalburgMansion_B2/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 46 "data/maps/PetalburgMansion_B2/scripts.pory"
	goto_if_eq VAR_TEMP_1, 4, PetalburgMansion_F2_LostBoyLeaveRight
# 47 "data/maps/PetalburgMansion_B2/scripts.pory"
	goto_if_eq VAR_TEMP_1, 5, PetalburgMansion_F2_LostBoyLeaveUp
# 48 "data/maps/PetalburgMansion_B2/scripts.pory"

# 49 "data/maps/PetalburgMansion_B2/scripts.pory"
@ Lost boy leave when player is to the north
# 50 "data/maps/PetalburgMansion_B2/scripts.pory"
PetalburgMansion_F2_LostBoyLeaveRight::
# 51 "data/maps/PetalburgMansion_B2/scripts.pory"
	applymovement LOCALID_LOST_MANSION_BOY, PetalburgMansion_F2_Movement_LeaveRight
# 52 "data/maps/PetalburgMansion_B2/scripts.pory"
	closemessage
# 53 "data/maps/PetalburgMansion_B2/scripts.pory"
	waitmovement 0
# 54 "data/maps/PetalburgMansion_B2/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_MANSION_F2_LOST_BOY
# 55 "data/maps/PetalburgMansion_B2/scripts.pory"
	removeobject LOCALID_LOST_MANSION_BOY
# 56 "data/maps/PetalburgMansion_B2/scripts.pory"
	goto PetalburgMansion_F2_EndScript
# 57 "data/maps/PetalburgMansion_B2/scripts.pory"

# 58 "data/maps/PetalburgMansion_B2/scripts.pory"
@ Lost boy leave when player is to the east
# 59 "data/maps/PetalburgMansion_B2/scripts.pory"
PetalburgMansion_F2_LostBoyLeaveUp::
# 60 "data/maps/PetalburgMansion_B2/scripts.pory"
	applymovement LOCALID_LOST_MANSION_BOY, PetalburgMansion_F2_Movement_LeaveUp
# 61 "data/maps/PetalburgMansion_B2/scripts.pory"
	closemessage
# 62 "data/maps/PetalburgMansion_B2/scripts.pory"
	waitmovement 0
# 63 "data/maps/PetalburgMansion_B2/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_MANSION_F2_LOST_BOY
# 64 "data/maps/PetalburgMansion_B2/scripts.pory"
	removeobject LOCALID_LOST_MANSION_BOY
# 65 "data/maps/PetalburgMansion_B2/scripts.pory"
	goto PetalburgMansion_F2_EndScript
# 66 "data/maps/PetalburgMansion_B2/scripts.pory"

# 67 "data/maps/PetalburgMansion_B2/scripts.pory"
PetalburgMansion_F2_Movement_LeaveRight:
# 68 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_right
# 69 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_right
# 70 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_right
# 71 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_right
# 72 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_right
# 73 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_right
# 74 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_down
# 75 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_down
# 76 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_down
# 77 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_right
# 78 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_right
# 79 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_right
# 80 "data/maps/PetalburgMansion_B2/scripts.pory"
	step_end
# 81 "data/maps/PetalburgMansion_B2/scripts.pory"

# 82 "data/maps/PetalburgMansion_B2/scripts.pory"
PetalburgMansion_F2_Movement_LeaveUp:
# 83 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_up
# 84 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_right
# 85 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_right
# 86 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_right
# 87 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_down
# 88 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_right
# 89 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_right
# 90 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_right
# 91 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_down
# 92 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_down
# 93 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_down
# 94 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_right
# 95 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_right
# 96 "data/maps/PetalburgMansion_B2/scripts.pory"
	walk_right
# 97 "data/maps/PetalburgMansion_B2/scripts.pory"
	step_end
# 98 "data/maps/PetalburgMansion_B2/scripts.pory"

# 99 "data/maps/PetalburgMansion_B2/scripts.pory"
@ End the script
# 100 "data/maps/PetalburgMansion_B2/scripts.pory"
PetalburgMansion_F2_EndScript::
# 101 "data/maps/PetalburgMansion_B2/scripts.pory"
	release
# 102 "data/maps/PetalburgMansion_B2/scripts.pory"
	end
# 103 "data/maps/PetalburgMansion_B2/scripts.pory"

# 104 "data/maps/PetalburgMansion_B2/scripts.pory"
PetalburgMansion_F2_Text_AhhhStayAway:
# 105 "data/maps/PetalburgMansion_B2/scripts.pory"
	.string "Ahhh!\n"
# 106 "data/maps/PetalburgMansion_B2/scripts.pory"
	.string "Stay away you GHOST!$"
# 107 "data/maps/PetalburgMansion_B2/scripts.pory"

# 108 "data/maps/PetalburgMansion_B2/scripts.pory"
PetalburgMansion_F2_Text_WaitYoureNot:
# 109 "data/maps/PetalburgMansion_B2/scripts.pory"
	.string "Wait a minute…\n"
# 110 "data/maps/PetalburgMansion_B2/scripts.pory"
	.string "You're not a GHOST POKéMON.\p"
# 111 "data/maps/PetalburgMansion_B2/scripts.pory"
	.string "Phew, thank goodness, too!\p"
# 112 "data/maps/PetalburgMansion_B2/scripts.pory"
	.string "I don't think I could handle it if I\n"
# 113 "data/maps/PetalburgMansion_B2/scripts.pory"
	.string "encountered a wild POKéMON.$"
# 114 "data/maps/PetalburgMansion_B2/scripts.pory"

# 115 "data/maps/PetalburgMansion_B2/scripts.pory"
PetalburgMansion_F2_Text_IDidntBelieve:
# 116 "data/maps/PetalburgMansion_B2/scripts.pory"
	.string "I didn't believe my friend when he said\n"
# 117 "data/maps/PetalburgMansion_B2/scripts.pory"
	.string "this place was spooky, so he dared me\l"
# 118 "data/maps/PetalburgMansion_B2/scripts.pory"
	.string "to go inside.\p"
# 119 "data/maps/PetalburgMansion_B2/scripts.pory"
	.string "It didn't take me long to get lost,\n"
# 120 "data/maps/PetalburgMansion_B2/scripts.pory"
	.string "though, and I was too scared to go\l"
# 121 "data/maps/PetalburgMansion_B2/scripts.pory"
	.string "looking for the exit.$"
# 122 "data/maps/PetalburgMansion_B2/scripts.pory"

# 123 "data/maps/PetalburgMansion_B2/scripts.pory"
PetalburgMansion_F2_Text_NowThatYouve:
# 124 "data/maps/PetalburgMansion_B2/scripts.pory"
	.string "Now that you made it here, I think I can\n"
# 125 "data/maps/PetalburgMansion_B2/scripts.pory"
	.string "find my way back.\p"
# 126 "data/maps/PetalburgMansion_B2/scripts.pory"
	.string "Oh!\n"
# 127 "data/maps/PetalburgMansion_B2/scripts.pory"
	.string "Before I go!\p"
# 128 "data/maps/PetalburgMansion_B2/scripts.pory"
	.string "Take this as a thanks for looking for\n"
# 129 "data/maps/PetalburgMansion_B2/scripts.pory"
	.string "me.$"
