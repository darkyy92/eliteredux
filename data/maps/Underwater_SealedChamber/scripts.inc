# 1 "data/maps/Underwater_SealedChamber/scripts.pory"

# 2 "data/maps/Underwater_SealedChamber/scripts.pory"
Underwater_SealedChamber_MapScripts:: @ 82390C4
# 3 "data/maps/Underwater_SealedChamber/scripts.pory"
	map_script MAP_SCRIPT_ON_DIVE_WARP, Underwater_SealedChamber_OnDive
# 4 "data/maps/Underwater_SealedChamber/scripts.pory"
	.byte 0
# 5 "data/maps/Underwater_SealedChamber/scripts.pory"

# 6 "data/maps/Underwater_SealedChamber/scripts.pory"
Underwater_SealedChamber_OnDive: @ 82390CA
# 7 "data/maps/Underwater_SealedChamber/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 8 "data/maps/Underwater_SealedChamber/scripts.pory"
	compare VAR_0x8004, 12
# 9 "data/maps/Underwater_SealedChamber/scripts.pory"
	goto_if_ne Underwater_SealedChamber_EventScript_SurfaceRoute134
# 10 "data/maps/Underwater_SealedChamber/scripts.pory"
	compare VAR_0x8005, 44
# 11 "data/maps/Underwater_SealedChamber/scripts.pory"
	goto_if_ne Underwater_SealedChamber_EventScript_SurfaceRoute134
# 12 "data/maps/Underwater_SealedChamber/scripts.pory"
	goto Underwater_SealedChamber_EventScript_SurfaceSealedChamber
# 13 "data/maps/Underwater_SealedChamber/scripts.pory"

# 14 "data/maps/Underwater_SealedChamber/scripts.pory"
Underwater_SealedChamber_EventScript_SurfaceRoute134:: @ 82390EA
# 15 "data/maps/Underwater_SealedChamber/scripts.pory"
	setdivewarp MAP_ROUTE134, 255, 60, 31
# 16 "data/maps/Underwater_SealedChamber/scripts.pory"
	end
# 17 "data/maps/Underwater_SealedChamber/scripts.pory"

# 18 "data/maps/Underwater_SealedChamber/scripts.pory"
Underwater_SealedChamber_EventScript_SurfaceSealedChamber:: @ 82390F3
# 19 "data/maps/Underwater_SealedChamber/scripts.pory"
	setdivewarp MAP_SEALED_CHAMBER_OUTER_ROOM, 255, 10, 19
# 20 "data/maps/Underwater_SealedChamber/scripts.pory"
	end
# 21 "data/maps/Underwater_SealedChamber/scripts.pory"

# 22 "data/maps/Underwater_SealedChamber/scripts.pory"
Underwater_SealedChamber_EventScript_Braille:: @ 82390FC
# 23 "data/maps/Underwater_SealedChamber/scripts.pory"
	lockall
# 24 "data/maps/Underwater_SealedChamber/scripts.pory"
	braillemessage Underwater_SealedChamber_Braille_GoUpHere
# 25 "data/maps/Underwater_SealedChamber/scripts.pory"
	waitbuttonpress
# 26 "data/maps/Underwater_SealedChamber/scripts.pory"
	closebraillemessage
# 27 "data/maps/Underwater_SealedChamber/scripts.pory"
	releaseall
# 28 "data/maps/Underwater_SealedChamber/scripts.pory"
	end
