DebugMapMain_MapScripts::
	.byte 0


DebugMapMain_SetMaxPlayTime::
	special PlayTimeCounter_SetToMax
	end

DebugMain_TestLinkStone::
	giveitem ITEM_GREAT_BALL, 99
	closemessage
	end

DebugMapMain_GiveRockSmash::
	setflag FLAG_BADGE04_GET
	end
