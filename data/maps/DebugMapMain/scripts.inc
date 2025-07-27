DebugMapMain_MapScripts::
	.byte 0


DebugMapMain_SetMaxPlayTime::
	special PlayTimeCounter_SetToMax
	end

DebugMain_TestLinkStone::
	giveitem ITEM_LINK_STONE
	givemon SPECIES_KADABRA, 40
	giveitem ITEM_LINK_STONE
	giveitem ITEM_METAL_COAT
	givemon SPECIES_ONIX, 40
	end