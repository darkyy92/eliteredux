# 1 "data/maps/SSTidalLowerDeck/scripts.pory"

# 2 "data/maps/SSTidalLowerDeck/scripts.pory"
SSTidalLowerDeck_MapScripts:: @ 823C818
# 3 "data/maps/SSTidalLowerDeck/scripts.pory"
	.byte 0
# 4 "data/maps/SSTidalLowerDeck/scripts.pory"

# 5 "data/maps/SSTidalLowerDeck/scripts.pory"
SSTidalLowerDeck_EventScript_Phillip:: @ 823C819
# 6 "data/maps/SSTidalLowerDeck/scripts.pory"
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
# 7 "data/maps/SSTidalLowerDeck/scripts.pory"
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
# 8 "data/maps/SSTidalLowerDeck/scripts.pory"
	end
# 9 "data/maps/SSTidalLowerDeck/scripts.pory"

# 10 "data/maps/SSTidalLowerDeck/scripts.pory"
SSTidalLowerDeck_EventScript_Leonard:: @ 823C830
# 11 "data/maps/SSTidalLowerDeck/scripts.pory"
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
# 12 "data/maps/SSTidalLowerDeck/scripts.pory"
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
# 13 "data/maps/SSTidalLowerDeck/scripts.pory"
	end
# 14 "data/maps/SSTidalLowerDeck/scripts.pory"

# 15 "data/maps/SSTidalLowerDeck/scripts.pory"
SSTidalLowerDeck_Text_PhillipIntro: @ 823C847
# 16 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "Arrrgh! I'm fed up and dog-tired of\n"
# 17 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "cleaning this huge place!\p"
# 18 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "Let's have a quick battle!$"
# 19 "data/maps/SSTidalLowerDeck/scripts.pory"

# 20 "data/maps/SSTidalLowerDeck/scripts.pory"
SSTidalLowerDeck_Text_PhillipDefeat: @ 823C8A0
# 21 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "Little bro, I lost!$"
# 22 "data/maps/SSTidalLowerDeck/scripts.pory"

# 23 "data/maps/SSTidalLowerDeck/scripts.pory"
SSTidalLowerDeck_Text_PhillipPostBattle: @ 823C8B4
# 24 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "We're the Cleanup Brothers!\p"
# 25 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "The old one dumps the detergent,\n"
# 26 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "and the young one does the scrubbing!$"
# 27 "data/maps/SSTidalLowerDeck/scripts.pory"

# 28 "data/maps/SSTidalLowerDeck/scripts.pory"
SSTidalLowerDeck_Text_LeonardIntro: @ 823C917
# 29 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "This is the bottom of the ship's hull.\n"
# 30 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "There's plenty of room.\l"
# 31 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "It'll be alright for a Pokémon battle.$"
# 32 "data/maps/SSTidalLowerDeck/scripts.pory"

# 33 "data/maps/SSTidalLowerDeck/scripts.pory"
SSTidalLowerDeck_Text_LeonardDefeat: @ 823C97D
# 34 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "Big bro, I lost!$"
# 35 "data/maps/SSTidalLowerDeck/scripts.pory"

# 36 "data/maps/SSTidalLowerDeck/scripts.pory"
SSTidalLowerDeck_Text_LeonardPostBattle: @ 823C98E
# 37 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "We're the Cleanup Brothers!\p"
# 38 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "The old one dumps the detergent,\n"
# 39 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "and the young one does the scrubbing!$"
