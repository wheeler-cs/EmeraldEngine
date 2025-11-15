# 1 "data/maps/PetalburgMansionB1/scripts.pory"

# 2 "data/maps/PetalburgMansionB1/scripts.pory"
PetalburgMansionB1_MapScripts::
# 3 "data/maps/PetalburgMansionB1/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, PetalburgMansionB1_OnResume
# 4 "data/maps/PetalburgMansionB1/scripts.pory"
	.byte 0
# 5 "data/maps/PetalburgMansionB1/scripts.pory"

# 6 "data/maps/PetalburgMansionB1/scripts.pory"
@ Script ran on resume
# 7 "data/maps/PetalburgMansionB1/scripts.pory"
PetalburgMansionB1_OnResume::
# 8 "data/maps/PetalburgMansionB1/scripts.pory"
	goto_if_unset FLAG_DEFEATED_HAUNTED_TV, PetalburgMansionB1_CheckNightFlag
# 9 "data/maps/PetalburgMansionB1/scripts.pory"
	setweather WEATHER_SHADE
# 10 "data/maps/PetalburgMansionB1/scripts.pory"
	doweather
# 11 "data/maps/PetalburgMansionB1/scripts.pory"
	setmetatile 10, 1, 2, TRUE
# 12 "data/maps/PetalburgMansionB1/scripts.pory"
	end
# 13 "data/maps/PetalburgMansionB1/scripts.pory"

# 14 "data/maps/PetalburgMansionB1/scripts.pory"
@ Update the FLAG_IS_NIGHT flag
# 15 "data/maps/PetalburgMansionB1/scripts.pory"
PetalburgMansionB1_CheckNightFlag::
# 16 "data/maps/PetalburgMansionB1/scripts.pory"
	special UpdateNightFlag
# 17 "data/maps/PetalburgMansionB1/scripts.pory"
	goto_if_set FLAG_IS_NIGHT, PetalburgMansionB1_SetupRoom
# 18 "data/maps/PetalburgMansionB1/scripts.pory"
	setweather WEATHER_SHADE
# 19 "data/maps/PetalburgMansionB1/scripts.pory"
	doweather
# 20 "data/maps/PetalburgMansionB1/scripts.pory"
	end
# 21 "data/maps/PetalburgMansionB1/scripts.pory"

# 22 "data/maps/PetalburgMansionB1/scripts.pory"
@ Setup special weather when haunted TV can be battled
# 23 "data/maps/PetalburgMansionB1/scripts.pory"
PetalburgMansionB1_SetupRoom::
# 24 "data/maps/PetalburgMansionB1/scripts.pory"
	setweather WEATHER_FOG_HORIZONTAL
# 25 "data/maps/PetalburgMansionB1/scripts.pory"
	doweather
# 26 "data/maps/PetalburgMansionB1/scripts.pory"
	end
# 27 "data/maps/PetalburgMansionB1/scripts.pory"

# 28 "data/maps/PetalburgMansionB1/scripts.pory"
@ Script associated with TV object in-game
# 29 "data/maps/PetalburgMansionB1/scripts.pory"
PetalburgMansionB1_HauntedTV::
# 30 "data/maps/PetalburgMansionB1/scripts.pory"
	lockall
# 31 "data/maps/PetalburgMansionB1/scripts.pory"
	waitse
# 32 "data/maps/PetalburgMansionB1/scripts.pory"
	@ First Check: Has Haunted been defeated
# 33 "data/maps/PetalburgMansionB1/scripts.pory"
	goto_if_set FLAG_DEFEATED_HAUNTED_TV, PetalburgMansionB1_DefeatedTV
# 34 "data/maps/PetalburgMansionB1/scripts.pory"
	@ Second Check: Is it night
# 35 "data/maps/PetalburgMansionB1/scripts.pory"
	goto_if_unset FLAG_IS_NIGHT, PetalburgMansionB1_BrokenTV
# 36 "data/maps/PetalburgMansionB1/scripts.pory"
	@ Conditions are met, go to actual haunted TV script
# 37 "data/maps/PetalburgMansionB1/scripts.pory"
	goto PetalburgMansionB1_HauntedTVEvent
# 38 "data/maps/PetalburgMansionB1/scripts.pory"

# 39 "data/maps/PetalburgMansionB1/scripts.pory"
@ Battle with Haunter has already been done
# 40 "data/maps/PetalburgMansionB1/scripts.pory"
PetalburgMansionB1_DefeatedTV::
# 41 "data/maps/PetalburgMansionB1/scripts.pory"
	msgbox PetalburgMansionB1_Text_ThisWasTheTV
# 42 "data/maps/PetalburgMansionB1/scripts.pory"
	goto PetalburgMansionB1_EndScript
# 43 "data/maps/PetalburgMansionB1/scripts.pory"

# 44 "data/maps/PetalburgMansionB1/scripts.pory"
@ Battle with Haunter has not been done, but it is not yet night
# 45 "data/maps/PetalburgMansionB1/scripts.pory"
PetalburgMansionB1_BrokenTV::
# 46 "data/maps/PetalburgMansionB1/scripts.pory"
	msgbox PetalburgMansionB1_Text_TheTVShowsNothing
# 47 "data/maps/PetalburgMansionB1/scripts.pory"
	goto PetalburgMansionB1_EndScript
# 48 "data/maps/PetalburgMansionB1/scripts.pory"

# 49 "data/maps/PetalburgMansionB1/scripts.pory"
@ Actual haunted TV event when conditions are met
# 50 "data/maps/PetalburgMansionB1/scripts.pory"
PetalburgMansionB1_HauntedTVEvent::
# 51 "data/maps/PetalburgMansionB1/scripts.pory"
	@ Ask player if they want to battle
# 52 "data/maps/PetalburgMansionB1/scripts.pory"
	msgbox PetalburgMansionB1_Text_TheTVFeelsLike, MSGBOX_YESNO
# 53 "data/maps/PetalburgMansionB1/scripts.pory"
	switch VAR_RESULT
# 54 "data/maps/PetalburgMansionB1/scripts.pory"
	case NO, PetalburgMansionB1_LeftTVAlone
# 55 "data/maps/PetalburgMansionB1/scripts.pory"
	case YES, PetalburgMansionB1_DoHauntedBoss
# 56 "data/maps/PetalburgMansionB1/scripts.pory"
	case MULTI_B_PRESSED, PetalburgMansionB1_LeftTVAlone
# 57 "data/maps/PetalburgMansionB1/scripts.pory"

# 58 "data/maps/PetalburgMansionB1/scripts.pory"
@ Player didn't want to battle
# 59 "data/maps/PetalburgMansionB1/scripts.pory"
PetalburgMansionB1_LeftTVAlone::
# 60 "data/maps/PetalburgMansionB1/scripts.pory"
	msgbox PetalburgMansionB1_Text_YouLeftTheTV
# 61 "data/maps/PetalburgMansionB1/scripts.pory"
	goto PetalburgMansionB1_EndScript
# 62 "data/maps/PetalburgMansionB1/scripts.pory"

# 63 "data/maps/PetalburgMansionB1/scripts.pory"
@ Setup and run boss battle with Haunter
# 64 "data/maps/PetalburgMansionB1/scripts.pory"
PetalburgMansionB1_DoHauntedBoss::
# 65 "data/maps/PetalburgMansionB1/scripts.pory"
	@ Initialize enemy party with Haunter
# 66 "data/maps/PetalburgMansionB1/scripts.pory"
	setwildbattle SPECIES_HAUNTER, 25
# 67 "data/maps/PetalburgMansionB1/scripts.pory"
	@ Give special moveset to Haunter
# 68 "data/maps/PetalburgMansionB1/scripts.pory"
	setwildmonmove MOVE_SHADOW_BALL, 0
# 69 "data/maps/PetalburgMansionB1/scripts.pory"
	setwildmonmove MOVE_THUNDERBOLT, 1
# 70 "data/maps/PetalburgMansionB1/scripts.pory"
	setwildmonmove MOVE_SHADOW_PUNCH, 2
# 71 "data/maps/PetalburgMansionB1/scripts.pory"
	setwildmonmove MOVE_CHARGE, 3
# 72 "data/maps/PetalburgMansionB1/scripts.pory"
	@ Perform pre-fight cinematic
# 73 "data/maps/PetalburgMansionB1/scripts.pory"
	playmoncry SPECIES_HAUNTER, CRY_MODE_ENCOUNTER
# 74 "data/maps/PetalburgMansionB1/scripts.pory"
	delay 40
# 75 "data/maps/PetalburgMansionB1/scripts.pory"
	waitmoncry
# 76 "data/maps/PetalburgMansionB1/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 77 "data/maps/PetalburgMansionB1/scripts.pory"
	@ Do battle
# 78 "data/maps/PetalburgMansionB1/scripts.pory"
	dowildbattle
# 79 "data/maps/PetalburgMansionB1/scripts.pory"
	@ Reset weather to normal
# 80 "data/maps/PetalburgMansionB1/scripts.pory"
	setweather WEATHER_SHADE
# 81 "data/maps/PetalburgMansionB1/scripts.pory"
	doweather
# 82 "data/maps/PetalburgMansionB1/scripts.pory"
	setmetatile 10, 1, 2, TRUE
# 83 "data/maps/PetalburgMansionB1/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 84 "data/maps/PetalburgMansionB1/scripts.pory"
	@ Handle the outcome of the battle
# 85 "data/maps/PetalburgMansionB1/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 86 "data/maps/PetalburgMansionB1/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PetalburgMansionB1_HaunterFled
# 87 "data/maps/PetalburgMansionB1/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PetalburgMansionB1_HaunterFled
# 88 "data/maps/PetalburgMansionB1/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PetalburgMansionB1_HaunterFled
# 89 "data/maps/PetalburgMansionB1/scripts.pory"
	setflag FLAG_DEFEATED_HAUNTED_TV
# 90 "data/maps/PetalburgMansionB1/scripts.pory"
	goto PetalburgMansionB1_EndScript
# 91 "data/maps/PetalburgMansionB1/scripts.pory"

# 92 "data/maps/PetalburgMansionB1/scripts.pory"
@ Player defeated or ran away from battle
# 93 "data/maps/PetalburgMansionB1/scripts.pory"
PetalburgMansionB1_HaunterFled::
# 94 "data/maps/PetalburgMansionB1/scripts.pory"
	msgbox PetalburgMansionB1_Text_TheHaunterFled 
# 95 "data/maps/PetalburgMansionB1/scripts.pory"
	setflag FLAG_DEFEATED_HAUNTED_TV
# 96 "data/maps/PetalburgMansionB1/scripts.pory"
	goto PetalburgMansionB1_EndScript
# 97 "data/maps/PetalburgMansionB1/scripts.pory"

# 98 "data/maps/PetalburgMansionB1/scripts.pory"
@ General-use catch-all for ending script
# 99 "data/maps/PetalburgMansionB1/scripts.pory"
PetalburgMansionB1_EndScript::
# 100 "data/maps/PetalburgMansionB1/scripts.pory"
	releaseall
# 101 "data/maps/PetalburgMansionB1/scripts.pory"
	end
# 102 "data/maps/PetalburgMansionB1/scripts.pory"

# 103 "data/maps/PetalburgMansionB1/scripts.pory"
PetalburgMansionB1_Text_ThisWasTheTV:
# 104 "data/maps/PetalburgMansionB1/scripts.pory"
	.string "This was the TV controlled by the\n"
# 105 "data/maps/PetalburgMansionB1/scripts.pory"
	.string "HAUNTER.$"
# 106 "data/maps/PetalburgMansionB1/scripts.pory"

# 107 "data/maps/PetalburgMansionB1/scripts.pory"
PetalburgMansionB1_Text_TheTVShowsNothing:
# 108 "data/maps/PetalburgMansionB1/scripts.pory"
	.string "The TV shows nothing but static.\p"
# 109 "data/maps/PetalburgMansionB1/scripts.pory"
	.string "It must be broken.$"
# 110 "data/maps/PetalburgMansionB1/scripts.pory"

# 111 "data/maps/PetalburgMansionB1/scripts.pory"
PetalburgMansionB1_Text_TheTVFeelsLike:
# 112 "data/maps/PetalburgMansionB1/scripts.pory"
	.string "The TV feels like it's staring back at\n"
# 113 "data/maps/PetalburgMansionB1/scripts.pory"
	.string "you.\p"
# 114 "data/maps/PetalburgMansionB1/scripts.pory"
	.string "Try turning it off?$"
# 115 "data/maps/PetalburgMansionB1/scripts.pory"

# 116 "data/maps/PetalburgMansionB1/scripts.pory"
PetalburgMansionB1_Text_YouLeftTheTV:
# 117 "data/maps/PetalburgMansionB1/scripts.pory"
	.string "You left the TV alone.$"
# 118 "data/maps/PetalburgMansionB1/scripts.pory"

# 119 "data/maps/PetalburgMansionB1/scripts.pory"
PetalburgMansionB1_Text_TheHaunterFled:
# 120 "data/maps/PetalburgMansionB1/scripts.pory"
	.string "The HAUNTER controlling the TV fled…$"
