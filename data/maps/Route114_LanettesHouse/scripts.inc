Route114_LanettesHouse_MapScripts::
# 3 "data/maps/Route114_LanettesHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Route114_LanettesHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 5 "data/maps/Route114_LanettesHouse/scripts.pory"
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end


Route114_LanettesHouse_EventScript_Lanette::
# 12 "data/maps/Route114_LanettesHouse/scripts.pory"
	lock
# 13 "data/maps/Route114_LanettesHouse/scripts.pory"
	faceplayer
# 14 "data/maps/Route114_LanettesHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_Lanette_2
# 28 "data/maps/Route114_LanettesHouse/scripts.pory"
	setflag FLAG_SYS_PC_LANETTE
# 29 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
# 30 "data/maps/Route114_LanettesHouse/scripts.pory"
	givedecoration DECOR_LOTAD_DOLL
# 31 "data/maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Route114_LanettesHouse_EventScript_Lanette_10
# 37 "data/maps/Route114_LanettesHouse/scripts.pory"
	setflag FLAG_RECEIVED_DOLL_LANETTE
Route114_LanettesHouse_EventScript_Lanette_1:
# 40 "data/maps/Route114_LanettesHouse/scripts.pory"
	release
	end

Route114_LanettesHouse_EventScript_Lanette_2:
# 16 "data/maps/Route114_LanettesHouse/scripts.pory"
	specialvar VAR_RESULT, HasAllHoennMons
# 17 "data/maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Route114_LanettesHouse_EventScript_Lanette_7
Route114_LanettesHouse_EventScript_Lanette_6:
# 23 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	goto Route114_LanettesHouse_EventScript_Lanette_1

Route114_LanettesHouse_EventScript_Lanette_5:
# 19 "data/maps/Route114_LanettesHouse/scripts.pory"
	goto Route114_LanettesHouse_EventScript_GiveShinyCharm
	goto Route114_LanettesHouse_EventScript_Lanette_1

Route114_LanettesHouse_EventScript_Lanette_7:
# 17 "data/maps/Route114_LanettesHouse/scripts.pory"
	goto_if_unset FLAG_RECEIVED_SHINY_CHARM, Route114_LanettesHouse_EventScript_Lanette_5
	goto Route114_LanettesHouse_EventScript_Lanette_6

Route114_LanettesHouse_EventScript_Lanette_10:
# 33 "data/maps/Route114_LanettesHouse/scripts.pory"
	goto Common_EventScript_ShowNoRoomForDecor
	goto Route114_LanettesHouse_EventScript_Lanette_1


Route114_LanettesHouse_EventScript_Notebook::
# 46 "data/maps/Route114_LanettesHouse/scripts.pory"
	lockall
# 47 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
# 48 "data/maps/Route114_LanettesHouse/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
# 49 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
# 50 "data/maps/Route114_LanettesHouse/scripts.pory"
	release
	end


Route114_LanettesHouse_EventScript_NotebookPage2::
# 56 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
# 57 "data/maps/Route114_LanettesHouse/scripts.pory"
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
# 58 "data/maps/Route114_LanettesHouse/scripts.pory"
	releaseall
	end


Route114_LanettesHouse_EventScript_NotebookPage3::
# 64 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return


Route114_LanettesHouse_EventScript_PC::
# 70 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end


Route114_LanettesHouse_EventScript_GiveShinyCharm::
# 76 "data/maps/Route114_LanettesHouse/scripts.pory"
	applymovement LOCALID_LANETTE, Common_Movement_ExclamationMark
# 77 "data/maps/Route114_LanettesHouse/scripts.pory"
	waitmovement 0
# 78 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_EventScript_GiveShinyCharm_Text_0
# 82 "data/maps/Route114_LanettesHouse/scripts.pory"
	applymovement LOCALID_LANETTE, Common_Movement_WalkInPlaceDown
# 83 "data/maps/Route114_LanettesHouse/scripts.pory"
	waitmovement 0
# 84 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_EventScript_GiveShinyCharm_Text_1
# 85 "data/maps/Route114_LanettesHouse/scripts.pory"
	giveitem ITEM_SHINY_CHARM
# 86 "data/maps/Route114_LanettesHouse/scripts.pory"
	setflag FLAG_RECEIVED_SHINY_CHARM
# 87 "data/maps/Route114_LanettesHouse/scripts.pory"
	release
	end


# 91 "data/maps/Route114_LanettesHouse/scripts.pory"

# 92 "data/maps/Route114_LanettesHouse/scripts.pory"

# 93 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
# 94 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "LANETTE: Oh! {PLAYER}{KUN}!\p"
# 95 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "I'm sorry everything is so cluttered…\n"
# 96 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "When I get engrossed in research,\l"
# 97 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "things end up this way…\p"
# 98 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "This is embarrassing… Please keep\n"
# 99 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "this a secret in exchange for this.$"
# 100 "data/maps/Route114_LanettesHouse/scripts.pory"

# 101 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_OrganizeYourBoxes:
# 102 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "May I offer advice about my POKéMON\n"
# 103 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "Storage System?\p"
# 104 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "You should organize your BOXES so you\n"
# 105 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "can tell which POKéMON are in them.$"
# 106 "data/maps/Route114_LanettesHouse/scripts.pory"

# 107 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_ResearchNotesPage1:
# 108 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "It's LANETTE's research notes.\n"
# 109 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "There's information about BOXES.\p"
# 110 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "Design BOXES to hold 30 POKéMON each.\p"
# 111 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "Each TRAINER should be able to store\n"
# 112 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "420 POKéMON on the PC system.\p"
# 113 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "Keep reading?$"
# 114 "data/maps/Route114_LanettesHouse/scripts.pory"

# 115 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_ResearchNotesPage2:
# 116 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "A marking system should be added to\n"
# 117 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "make POKéMON easier to organize.\p"
# 118 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "The name and wallpaper design of each\n"
# 119 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "BOX will be made changeable to please\l"
# 120 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "the stored POKéMON.\p"
# 121 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "Keep reading?$"
# 122 "data/maps/Route114_LanettesHouse/scripts.pory"

# 123 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_ResearchNotesPage3:
# 124 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "When storing a POKéMON, it should be\n"
# 125 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "sent to the BOX inspected last.\p"
# 126 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "If that BOX is full, the received\n"
# 127 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "POKéMON is stored in the next BOX.\p"
# 128 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "In other words, when a BOX is examined,\n"
# 129 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "it is automatically selected as the BOX\l"
# 130 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "to which POKéMON are sent.$"
# 131 "data/maps/Route114_LanettesHouse/scripts.pory"

# 132 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_ClosedTheNotebook:
# 133 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "{PLAYER} closed the notebook.$"
# 134 "data/maps/Route114_LanettesHouse/scripts.pory"

# 135 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_EmailFromBill:
# 136 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "There's an e-mail from someone on\n"
# 137 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "the PC.\p"
# 138 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "“… … … … … … …\p"
# 139 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "“Your Storage System offers more\n"
# 140 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "convenience than mine.\p"
# 141 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "“It has a lot of user-friendly features\n"
# 142 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "that make it fun and useful, too.\p"
# 143 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "“It makes me proud that I played\n"
# 144 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "a part in its development.\p"
# 145 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "“Here's hoping that you'll continue\n"
# 146 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "research in Storage Systems.\p"
# 147 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "“From BILL\n"
# 148 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "… … … … … … … …”$"

Route114_LanettesHouse_EventScript_GiveShinyCharm_Text_0:
# 78 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "Oh! {PLAYER}{KUN}!\p"
	.string "Is that a completed POKéDEX?!\p"
	.string "This is no small feat you've\n"
	.string "accomplished, and all on your own!\p"
	.string "Of course, I'm sure the Storage System\n"
	.string "I developed played a small part in\l"
	.string "helping you.$"

Route114_LanettesHouse_EventScript_GiveShinyCharm_Text_1:
# 84 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "Here… I would like you to have this. As\n"
	.string "thanks for letting me be a part of your\l"
	.string "adventure.$"
