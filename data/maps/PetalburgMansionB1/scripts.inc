PetalburgMansionB1_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PetalburgMansionB1_OnResume
	.byte 0

@ Script ran on resume
PetalburgMansionB1_OnResume::
	goto_if_unset FLAG_DEFEATED_HAUNTED_TV, PetalburgMansionB1_CheckNightFlag
	setweather WEATHER_SHADE
	doweather
	setmetatile 10, 1, 2, TRUE
	end

@ Update the FLAG_IS_NIGHT flag
PetalburgMansionB1_CheckNightFlag::
	special UpdateNightFlag
	goto_if_set FLAG_IS_NIGHT, PetalburgMansionB1_SetupRoom
	setweather WEATHER_SHADE
	doweather
	end

@ Setup special weather when haunted TV can be battled
PetalburgMansionB1_SetupRoom::
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	end

@ Script associated with TV object in-game
PetalburgMansionB1_HauntedTV::
	lockall
	waitse
	@ First Check: Has Haunted been defeated
	goto_if_set FLAG_DEFEATED_HAUNTED_TV, PetalburgMansionB1_DefeatedTV
	@ Second Check: Is it night
	goto_if_unset FLAG_IS_NIGHT, PetalburgMansionB1_BrokenTV
	@ Conditions are met, go to actual haunted TV script
	goto PetalburgMansionB1_HauntedTVEvent

@ Battle with Haunter has already been done
PetalburgMansionB1_DefeatedTV::
	msgbox PetalburgMansionB1_Text_ThisWasTheTV
	goto PetalburgMansionB1_EndScript

@ Battle with Haunter has not been done, but it is not yet night
PetalburgMansionB1_BrokenTV::
	msgbox PetalburgMansionB1_Text_TheTVShowsNothing
	goto PetalburgMansionB1_EndScript

@ Actual haunted TV event when conditions are met
PetalburgMansionB1_HauntedTVEvent::
	@ Ask player if they want to battle
	msgbox PetalburgMansionB1_Text_TheTVFeelsLike, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, PetalburgMansionB1_LeftTVAlone
	case YES, PetalburgMansionB1_DoHauntedBoss
	case MULTI_B_PRESSED, PetalburgMansionB1_LeftTVAlone

@ Player didn't want to battle
PetalburgMansionB1_LeftTVAlone::
	msgbox PetalburgMansionB1_Text_YouLeftTheTV
	goto PetalburgMansionB1_EndScript

@ Setup and run boss battle with Haunter
PetalburgMansionB1_DoHauntedBoss::
	@ Initialize enemy party with Haunter
	setwildbattle SPECIES_HAUNTER, 25
	@ Give special moveset to Haunter
	setwildmonmove MOVE_SHADOW_BALL, 0
	setwildmonmove MOVE_THUNDERBOLT, 1
	setwildmonmove MOVE_SHADOW_PUNCH, 2
	setwildmonmove MOVE_MEAN_LOOK, 3
	@ Perform pre-fight cinematic
	playmoncry SPECIES_HAUNTER, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	@ Do battle
	dowildbattle
	@ Reset weather to normal
	setweather WEATHER_SHADE
	doweather
	setmetatile 10, 1, 2, TRUE
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	@ Handle the outcome of the battle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PetalburgMansionB1_HaunterFled
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PetalburgMansionB1_HaunterFled
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PetalburgMansionB1_HaunterFled
	setflag FLAG_DEFEATED_HAUNTED_TV
	goto PetalburgMansionB1_EndScript

@ Player defeated or ran away from battle
PetalburgMansionB1_HaunterFled::
	msgbox PetalburgMansionB1_Text_TheHaunterFled 
	setflag FLAG_DEFEATED_HAUNTED_TV
	goto PetalburgMansionB1_EndScript

@ General-use catch-all for ending script
PetalburgMansionB1_EndScript::
	releaseall
	end

PetalburgMansionB1_Text_ThisWasTheTV:
	.string "This was the TV controlled by the\n"
	.string "HAUNTER.$"

PetalburgMansionB1_Text_TheTVShowsNothing:
	.string "The TV shows nothing but static.\p"
	.string "It must be broken.$"

PetalburgMansionB1_Text_TheTVFeelsLike:
	.string "The TV feels like it's staring back at\n"
	.string "you.\p"
	.string "Try turning it off?$"

PetalburgMansionB1_Text_YouLeftTheTV:
	.string "You left the TV alone.$"

PetalburgMansionB1_Text_TheHaunterFled:
	.string "The HAUNTER controlling the TV fled…$"
