# 1 "data/maps/DebugMapMain/scripts.pory"

# 2 "data/maps/DebugMapMain/scripts.pory"
DebugMapMain_MapScripts::
# 3 "data/maps/DebugMapMain/scripts.pory"
	.byte 0
# 4 "data/maps/DebugMapMain/scripts.pory"

# 5 "data/maps/DebugMapMain/scripts.pory"
DebugMapMain_Sign_Littleroot::
# 6 "data/maps/DebugMapMain/scripts.pory"
	msgbox DebugMapMain_Text_Littleroot, MSGBOX_SIGN
# 7 "data/maps/DebugMapMain/scripts.pory"
	end
# 8 "data/maps/DebugMapMain/scripts.pory"

# 9 "data/maps/DebugMapMain/scripts.pory"
DebugMapMain_Text_Littleroot:
# 10 "data/maps/DebugMapMain/scripts.pory"
	.string "LITTLEROOT TOWN$"
# 11 "data/maps/DebugMapMain/scripts.pory"

# 12 "data/maps/DebugMapMain/scripts.pory"
DebugMapMain_Sign_RegionMap::
# 13 "data/maps/DebugMapMain/scripts.pory"
	msgbox DebugMapMain_Text_RegionMap, MSGBOX_SIGN
# 14 "data/maps/DebugMapMain/scripts.pory"
	end
# 15 "data/maps/DebugMapMain/scripts.pory"

# 16 "data/maps/DebugMapMain/scripts.pory"
DebugMapMain_Text_RegionMap:
# 17 "data/maps/DebugMapMain/scripts.pory"
	.string "REGION MAP$"
# 18 "data/maps/DebugMapMain/scripts.pory"

# 19 "data/maps/DebugMapMain/scripts.pory"
DebugMapMain_Sign_BattleArea::
# 20 "data/maps/DebugMapMain/scripts.pory"
	msgbox DebugMapMain_Text_BattleArea, MSGBOX_SIGN
# 21 "data/maps/DebugMapMain/scripts.pory"
	end
# 22 "data/maps/DebugMapMain/scripts.pory"

# 23 "data/maps/DebugMapMain/scripts.pory"
DebugMapMain_Text_BattleArea:
# 24 "data/maps/DebugMapMain/scripts.pory"
	.string "BATTLE AREA$"
# 25 "data/maps/DebugMapMain/scripts.pory"

# 26 "data/maps/DebugMapMain/scripts.pory"

# 27 "data/maps/DebugMapMain/scripts.pory"
DebugMapMain_SetMaxPlayTime::
# 28 "data/maps/DebugMapMain/scripts.pory"
	special PlayTimeCounter_SetToMax
# 29 "data/maps/DebugMapMain/scripts.pory"
	end
# 30 "data/maps/DebugMapMain/scripts.pory"

# 31 "data/maps/DebugMapMain/scripts.pory"
DebugMapMain_GiveRockSmash::
# 32 "data/maps/DebugMapMain/scripts.pory"
	setflag FLAG_BADGE04_GET
# 33 "data/maps/DebugMapMain/scripts.pory"
	end
