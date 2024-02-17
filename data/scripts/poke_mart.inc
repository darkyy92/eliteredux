General_Pokemart_Script::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart PokeMart_No_Badges
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

General_Pokemart_Script_No_Badges::
	msgbox Text_Pokemart_Script_No_Badges, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeMart_No_Badges::
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_LEAF_STONE
    .2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_DUSK_STONE
    .2byte ITEM_DAWN_STONE
    .2byte ITEM_SHINY_STONE
	.2byte ITEM_ICE_STONE
    .2byte ITEM_PRISM_SCALE
    .2byte ITEM_METAL_COAT
    .2byte ITEM_KINGS_ROCK
    .2byte ITEM_RAZOR_FANG
    .2byte ITEM_RAZOR_CLAW
    .2byte ITEM_UPGRADE
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_PROTECTOR
	.2byte ITEM_DRAGON_SCALE
	.2byte ITEM_ELECTIRIZER
	.2byte ITEM_MAGMARIZER
	.2byte ITEM_REAPER_CLOTH
	.2byte ITEM_DEEP_SEA_TOOTH
	.2byte ITEM_DEEP_SEA_SCALE
	.2byte ITEM_OVAL_STONE
	.2byte ITEM_SACHET
	.2byte ITEM_WHIPPED_DREAM
	.2byte ITEM_SWEET_APPLE
	.2byte ITEM_TART_APPLE
	.2byte ITEM_CRACKED_POT
	.2byte ITEM_NONE
	release
	end

Mart_Stone_Badge::
	pokemart PokeMart_Stone_Badge
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeMart_Stone_Badge::
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_LEAF_STONE
    .2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_DUSK_STONE
    .2byte ITEM_DAWN_STONE
    .2byte ITEM_SHINY_STONE
    .2byte ITEM_PRISM_SCALE
    .2byte ITEM_METAL_COAT
    .2byte ITEM_KINGS_ROCK
    .2byte ITEM_RAZOR_FANG
    .2byte ITEM_RAZOR_CLAW
    .2byte ITEM_UPGRADE
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_NONE
	release
	end
	
Mart_Knuckle_Badge::
	pokemart PokeMart_Knuckle_Badge
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeMart_Knuckle_Badge::
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_LEAF_STONE
    .2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_DUSK_STONE
    .2byte ITEM_DAWN_STONE
    .2byte ITEM_SHINY_STONE
    .2byte ITEM_PRISM_SCALE
    .2byte ITEM_METAL_COAT
    .2byte ITEM_KINGS_ROCK
    .2byte ITEM_RAZOR_FANG
    .2byte ITEM_RAZOR_CLAW
    .2byte ITEM_UPGRADE
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_NONE
	release
	end
	
Mart_Dynamo_Badge::
	pokemart PokeMart_Dynamo_Badge
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeMart_Dynamo_Badge::
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_LEAF_STONE
    .2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_DUSK_STONE
    .2byte ITEM_DAWN_STONE
    .2byte ITEM_SHINY_STONE
    .2byte ITEM_PRISM_SCALE
    .2byte ITEM_METAL_COAT
    .2byte ITEM_KINGS_ROCK
    .2byte ITEM_RAZOR_FANG
    .2byte ITEM_RAZOR_CLAW
    .2byte ITEM_UPGRADE
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_NONE
	release
	end

Mart_Heat_Badge::
	pokemart PokeMart_Heat_Badge
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeMart_Heat_Badge::
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_LEAF_STONE
    .2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_DUSK_STONE
    .2byte ITEM_DAWN_STONE
    .2byte ITEM_SHINY_STONE
    .2byte ITEM_PRISM_SCALE
    .2byte ITEM_METAL_COAT
    .2byte ITEM_KINGS_ROCK
    .2byte ITEM_RAZOR_FANG
    .2byte ITEM_RAZOR_CLAW
    .2byte ITEM_UPGRADE
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_NONE
	release
	end
	
Mart_Balance_Badge::
	pokemart PokeMart_Balance_Badge
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeMart_Balance_Badge::
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_LEAF_STONE
    .2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_DUSK_STONE
    .2byte ITEM_DAWN_STONE
    .2byte ITEM_SHINY_STONE
    .2byte ITEM_PRISM_SCALE
    .2byte ITEM_METAL_COAT
    .2byte ITEM_KINGS_ROCK
    .2byte ITEM_RAZOR_FANG
    .2byte ITEM_RAZOR_CLAW
    .2byte ITEM_UPGRADE
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_NONE
	release
	end
	
Mart_Feather_Badge::
	pokemart PokeMart_Feather_Badge
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeMart_Feather_Badge::
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_LEAF_STONE
    .2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_DUSK_STONE
    .2byte ITEM_DAWN_STONE
    .2byte ITEM_SHINY_STONE
    .2byte ITEM_PRISM_SCALE
    .2byte ITEM_METAL_COAT
    .2byte ITEM_KINGS_ROCK
    .2byte ITEM_RAZOR_FANG
    .2byte ITEM_RAZOR_CLAW
    .2byte ITEM_UPGRADE
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_NONE
	release
	end

Mart_Mind_Badge::
	pokemart PokeMart_Mind_Badge
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeMart_Mind_Badge::
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_LEAF_STONE
    .2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_DUSK_STONE
    .2byte ITEM_DAWN_STONE
    .2byte ITEM_SHINY_STONE
    .2byte ITEM_PRISM_SCALE
    .2byte ITEM_METAL_COAT
    .2byte ITEM_KINGS_ROCK
    .2byte ITEM_RAZOR_FANG
    .2byte ITEM_RAZOR_CLAW
    .2byte ITEM_UPGRADE
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_NONE
	release
	end
