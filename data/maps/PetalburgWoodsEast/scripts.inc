# 1 "data/maps/PetalburgWoodsEast/scripts.pory"

# 2 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_MapScripts::
# 3 "data/maps/PetalburgWoodsEast/scripts.pory"
	.byte 0
# 4 "data/maps/PetalburgWoodsEast/scripts.pory"

# 5 "data/maps/PetalburgWoodsEast/scripts.pory"
// ==== Lost Boy Mansion Quest =====================================================================
# 6 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_EventScript_LostBoy::
# 7 "data/maps/PetalburgWoodsEast/scripts.pory"
	lockall
# 8 "data/maps/PetalburgWoodsEast/scripts.pory"
	faceplayer
# 9 "data/maps/PetalburgWoodsEast/scripts.pory"
	goto_if_set FLAG_BADGE04_GET, PetalburgWoodsEast_EventScript_BeginMansionQuest
# 10 "data/maps/PetalburgWoodsEast/scripts.pory"
	msgbox PetalburgWoodsEast_Text_NobodyIsAllowed, MSGBOX_NPC
# 11 "data/maps/PetalburgWoodsEast/scripts.pory"
	releaseall
# 12 "data/maps/PetalburgWoodsEast/scripts.pory"
	end
# 13 "data/maps/PetalburgWoodsEast/scripts.pory"

# 14 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_EventScript_BeginMansionQuest::
# 15 "data/maps/PetalburgWoodsEast/scripts.pory"
	applymovement LOCALID_LOST_BOY, Common_Movement_ExclamationMark
# 16 "data/maps/PetalburgWoodsEast/scripts.pory"
	waitmovement 0
# 17 "data/maps/PetalburgWoodsEast/scripts.pory"
	delay 48
# 18 "data/maps/PetalburgWoodsEast/scripts.pory"
	msgbox PetalburgWoodsEast_Text_OhIsThat, MSGBOX_DEFAULT
# 19 "data/maps/PetalburgWoodsEast/scripts.pory"
	waitmessage
# 20 "data/maps/PetalburgWoodsEast/scripts.pory"
	applymovement LOCALID_LOST_BOY, PetalburgWoodsEast_Movement_LostBoyLookBack
# 21 "data/maps/PetalburgWoodsEast/scripts.pory"
	waitmovement 0
# 22 "data/maps/PetalburgWoodsEast/scripts.pory"
	delay 48
# 23 "data/maps/PetalburgWoodsEast/scripts.pory"
	msgbox PetalburgWoodsEast_Text_MaybeYouCanHelp, MSGBOX_DEFAULT
# 24 "data/maps/PetalburgWoodsEast/scripts.pory"
	waitmessage
# 25 "data/maps/PetalburgWoodsEast/scripts.pory"
	msgbox PetalburgWoodsEast_Text_IfITryToGo, MSGBOX_DEFAULT
# 26 "data/maps/PetalburgWoodsEast/scripts.pory"
	waitmessage
# 27 "data/maps/PetalburgWoodsEast/scripts.pory"
	goto PetalburgWoodsEast_EventScript_AcceptMansionQuest
# 28 "data/maps/PetalburgWoodsEast/scripts.pory"

# 29 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_EventScript_AcceptMansionQuest::
# 30 "data/maps/PetalburgWoodsEast/scripts.pory"
	msgbox PetalburgWoodsEast_Text_WouldYouGoLook, MSGBOX_YESNO
# 31 "data/maps/PetalburgWoodsEast/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgWoodsEast_EventScript_RespondedNo
# 32 "data/maps/PetalburgWoodsEast/scripts.pory"
	msgbox PetalburgWoodsEast_Text_OhThankYou, MSGBOX_DEFAULT
# 33 "data/maps/PetalburgWoodsEast/scripts.pory"
	waitmessage
# 34 "data/maps/PetalburgWoodsEast/scripts.pory"
	closemessage
# 35 "data/maps/PetalburgWoodsEast/scripts.pory"
	goto PetalburgWoodsEast_EventScript_LostBoyReturnHome
# 36 "data/maps/PetalburgWoodsEast/scripts.pory"

# 37 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_EventScript_RespondedNo::
# 38 "data/maps/PetalburgWoodsEast/scripts.pory"
	msgbox PetalburgWoodsEast_Text_PleaseWillYou, MSGBOX_DEFAULT
# 39 "data/maps/PetalburgWoodsEast/scripts.pory"
	waitmessage
# 40 "data/maps/PetalburgWoodsEast/scripts.pory"
	goto PetalburgWoodsEast_EventScript_AcceptMansionQuest
# 41 "data/maps/PetalburgWoodsEast/scripts.pory"

# 42 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_EventScript_LostBoyReturnHome::
# 43 "data/maps/PetalburgWoodsEast/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 44 "data/maps/PetalburgWoodsEast/scripts.pory"
	goto_if_eq VAR_0x8004, 13, PetalburgWoodsEast_EventScript_WalkAroundPlayer
# 45 "data/maps/PetalburgWoodsEast/scripts.pory"
	applymovement LOCALID_LOST_BOY, PetalburgWoodsEast_Movement_LostBoyWalkAway
# 46 "data/maps/PetalburgWoodsEast/scripts.pory"
	waitmovement
# 47 "data/maps/PetalburgWoodsEast/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_WOODS_EAST_LOST_BOY
# 48 "data/maps/PetalburgWoodsEast/scripts.pory"
	releaseall
# 49 "data/maps/PetalburgWoodsEast/scripts.pory"
	end
# 50 "data/maps/PetalburgWoodsEast/scripts.pory"

# 51 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_EventScript_WalkAroundPlayer::
# 52 "data/maps/PetalburgWoodsEast/scripts.pory"
	applymovement LOCALID_LOST_BOY, PetalburgWoodsEast_Movement_LostBoyWalkAround
# 53 "data/maps/PetalburgWoodsEast/scripts.pory"
	waitmovement
# 54 "data/maps/PetalburgWoodsEast/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_WOODS_EAST_LOST_BOY
# 55 "data/maps/PetalburgWoodsEast/scripts.pory"
	releaseall
# 56 "data/maps/PetalburgWoodsEast/scripts.pory"
	end
# 57 "data/maps/PetalburgWoodsEast/scripts.pory"

# 58 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_Movement_LostBoyLookBack:
# 59 "data/maps/PetalburgWoodsEast/scripts.pory"
	face_up
# 60 "data/maps/PetalburgWoodsEast/scripts.pory"
	delay_16
# 61 "data/maps/PetalburgWoodsEast/scripts.pory"
	delay_16
# 62 "data/maps/PetalburgWoodsEast/scripts.pory"
	delay_16
# 63 "data/maps/PetalburgWoodsEast/scripts.pory"
	face_player
# 64 "data/maps/PetalburgWoodsEast/scripts.pory"
	step_end
# 65 "data/maps/PetalburgWoodsEast/scripts.pory"

# 66 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_Movement_LostBoyWalkAway:
# 67 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_down
# 68 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_down
# 69 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_down
# 70 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_left
# 71 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_left
# 72 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_left
# 73 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_left
# 74 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_left
# 75 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_left
# 76 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_left
# 77 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_left
# 78 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_left
# 79 "data/maps/PetalburgWoodsEast/scripts.pory"
	step_end
# 80 "data/maps/PetalburgWoodsEast/scripts.pory"

# 81 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_Movement_LostBoyWalkAround:
# 82 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_left
# 83 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_down
# 84 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_down
# 85 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_down
# 86 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_left
# 87 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_left
# 88 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_left
# 89 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_left
# 90 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_left
# 91 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_left
# 92 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_left
# 93 "data/maps/PetalburgWoodsEast/scripts.pory"
	walk_left
# 94 "data/maps/PetalburgWoodsEast/scripts.pory"
	step_end
# 95 "data/maps/PetalburgWoodsEast/scripts.pory"

# 96 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_Text_NobodyIsAllowed:
# 97 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "Nobody is allowed inside the manor!\n"
# 98 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "Somebody could easily get hurt if they\l"
# 99 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "aren't careful!$"
# 100 "data/maps/PetalburgWoodsEast/scripts.pory"

# 101 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_Text_OhIsThat:
# 102 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "Oh! Is that the BADGE from LAVARIDGE\n"
# 103 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "GYM? You must be pretty strong!$"
# 104 "data/maps/PetalburgWoodsEast/scripts.pory"

# 105 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_Text_MaybeYouCanHelp:
# 106 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "… … … … … …\p"
# 107 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "Maybe you can help me out.\p"
# 108 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "You see… I dared my friend to go inside\n"
# 109 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "the manor.\p"
# 110 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "Rumors say it's supposed to be haunted,\n"
# 111 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "but he didn't believe a word of it.\p"
# 112 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "Well, that was some time ago, and now I'm\n"
# 113 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "starting to get worried.$"
# 114 "data/maps/PetalburgWoodsEast/scripts.pory"

# 115 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_Text_IfITryToGo:
# 116 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "If I try to go get help myself, I'll get\n"
# 117 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "in trouble for playing around here.$"
# 118 "data/maps/PetalburgWoodsEast/scripts.pory"

# 119 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_Text_WouldYouGoLook:
# 120 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "Could you go in and look for him?$"
# 121 "data/maps/PetalburgWoodsEast/scripts.pory"

# 122 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_Text_PleaseWillYou:
# 123 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "Please will you go look for him? I don't\n"
# 124 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "know what else to do!$"
# 125 "data/maps/PetalburgWoodsEast/scripts.pory"

# 126 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_Text_OhThankYou:
# 127 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "Oh, thank you! Please be careful inside.\n"
# 128 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "The manor is home to all kinds of wild\l"
# 129 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "POKéMON.$"
# 130 "data/maps/PetalburgWoodsEast/scripts.pory"

# 131 "data/maps/PetalburgWoodsEast/scripts.pory"
// ==== Hex Maniac Lily ============================================================================
# 132 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_EventScript_Lily::
# 133 "data/maps/PetalburgWoodsEast/scripts.pory"
	trainerbattle_single TRAINER_HEX_MANIAC_LILY, PetalburgWoodsEast_Text_ISenseSomethingOminous, PetalburgWoodsEast_Text_NoItCouldntBe
# 134 "data/maps/PetalburgWoodsEast/scripts.pory"
	msgbox PetalburgWoodsEast_Text_BeCarefulMyChild, MSGBOX_AUTOCLOSE
# 135 "data/maps/PetalburgWoodsEast/scripts.pory"
	end
# 136 "data/maps/PetalburgWoodsEast/scripts.pory"

# 137 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_Text_ISenseSomethingOminous:
# 138 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "I sense something ominous in these\n"
# 139 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "woods. Is it you?$"
# 140 "data/maps/PetalburgWoodsEast/scripts.pory"

# 141 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_Text_NoItCouldntBe:
# 142 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "No… It couldn't be…$"
# 143 "data/maps/PetalburgWoodsEast/scripts.pory"

# 144 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_Text_BeCarefulMyChild:
# 145 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "Be careful, my child. Strange things\n"
# 146 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "lurk in the shadows of these trees.$"
# 147 "data/maps/PetalburgWoodsEast/scripts.pory"

# 148 "data/maps/PetalburgWoodsEast/scripts.pory"
// ==== Youngster Michael ==========================================================================
# 149 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_EventScript_Michael::
# 150 "data/maps/PetalburgWoodsEast/scripts.pory"
	trainerbattle_single TRAINER_YOUNGSTER_MICHAEL, PetalburgWoodsEast_Text_WatchOut, PetalburgWoodsEast_Text_Drat
# 151 "data/maps/PetalburgWoodsEast/scripts.pory"
	msgbox PetalburgWoodsEast_Text_NotAllTallGrass, MSGBOX_AUTOCLOSE
# 152 "data/maps/PetalburgWoodsEast/scripts.pory"
	end
# 153 "data/maps/PetalburgWoodsEast/scripts.pory"

# 154 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_Text_WatchOut:
# 155 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "Watch out! I just caught some really\n"
# 156 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "strong POKéMON!$"
# 157 "data/maps/PetalburgWoodsEast/scripts.pory"

# 158 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_Text_Drat:
# 159 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "Drat! That could've gone better.$"
# 160 "data/maps/PetalburgWoodsEast/scripts.pory"

# 161 "data/maps/PetalburgWoodsEast/scripts.pory"
PetalburgWoodsEast_Text_NotAllTallGrass:
# 162 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "Not all tall grass is the same.\p"
# 163 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "Some POKéMON like to hide in different\n"
# 164 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "spots, so be sure to check around\l"
# 165 "data/maps/PetalburgWoodsEast/scripts.pory"
	.string "everywhere.$"
