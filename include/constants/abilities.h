#ifndef GUARD_CONSTANTS_ABILITIES_H
#define GUARD_CONSTANTS_ABILITIES_H

#define ABILITY_NONE 0
#define ABILITY_STENCH 1 // This Pokemon's attacks without a chance to flinch gain a 10% chance to flinch.
#define ABILITY_DRIZZLE 2 // The Pokémon makes it rain when it enters a battle.
#define ABILITY_SPEED_BOOST 3 // Its Speed stat is boosted every turn.
#define ABILITY_BATTLE_ARMOR 4 // Hard armor protects the Pokémon from critical hits. Takes 20% less damage.
#define ABILITY_STURDY 5 // It cannot be knocked out with one hit. One-hit KO moves cannot knock it out, either.
#define ABILITY_DAMP 6 // Prevents the use of explosive moves, such as Self-Destruct, by dampening its surroundings.
#define ABILITY_LIMBER 7 // Its limber body protects the Pokémon from paralysis. Takes 30% less damage from crash damage.
#define ABILITY_SAND_VEIL 8 // Boosts the Pokémon's evasiveness in a sandstorm by 20%.
#define ABILITY_STATIC 9 // 30% chance to get paralyzed on contact against this Pokémon.
#define ABILITY_VOLT_ABSORB 10 // The Pokémon heals up to 1/4 of its maximum Hit Points when hit with Electric-type moves.
#define ABILITY_WATER_ABSORB 11 // The Pokémon heals up to 1/4 of its maximum Hit Points when hit with Water-type moves.
#define ABILITY_OBLIVIOUS 12 // The Pokémon is oblivious, and that keeps it from being infatuated or falling for taunts.
#define ABILITY_CLOUD_NINE 13 // Eliminates the effects of weather.
#define ABILITY_COMPOUND_EYES 14 // Raises the Pokémon’s accuracy by 30%.
#define ABILITY_INSOMNIA 15 // The Pokémon is suffering from insomnia and cannot fall asleep.
#define ABILITY_COLOR_CHANGE 16 // The Pokemon's type become the type that counters the move used on it before hit.
#define ABILITY_IMMUNITY 17 // The immune system of the Pokémon prevents it from getting poisoned. Halves damage from Poison-type moves.
#define ABILITY_FLASH_FIRE 18 // This ability makes the Pokémon immune to Fire-type moves and will activate when hit by one. When activated, the power of the Pokémon's Fire-type moves is increased by 50%.
#define ABILITY_SHIELD_DUST 19 // Damaging moves used by the opponent will not have an additional effect. Now also avoids damage from entry hazards.
#define ABILITY_OWN_TEMPO 20 // Prevents it from becoming confused.
#define ABILITY_SUCTION_CUPS 21 // *No innate* This Pokémon uses suction cups to stay in one spot to negate all moves and items that force switching out.
#define ABILITY_INTIMIDATE 22 // The Pokémon intimidates opposing Pokémon upon entering battle, lowering their Attack stat.
#define ABILITY_SHADOW_TAG 23 // This Pokémon steps on the opposing Pokémon's shadow to prevent it from escaping.
#define ABILITY_ROUGH_SKIN 24 // This Pokémon inflicts 1/8 HP damage on contact.
#define ABILITY_WONDER_GUARD 25 // *No innate* Its mysterious power only lets supereffective moves hit the Pokémon.
#define ABILITY_LEVITATE 26 // By floating in the air, the Pokémon receives full immunity to all Ground-type moves. Boosts the power of Flying-type moves by 25%.
#define ABILITY_EFFECT_SPORE 27 // When a Pokémon with this Ability is hit by a move that makes contact, there is a 10% chance that the attacking Pokémon will become either poisoned, paralyzed, or asleep, with a 3.3% probability each.
#define ABILITY_SYNCHRONIZE 28 // *No innate* The attacker will receive the same status condition if it inflicts a burn, poison, or paralysis to the Pokémon.
#define ABILITY_CLEAR_BODY 29 // Prevents other Pokémon's moves or Abilities from lowering the Pokémon's stats.
#define ABILITY_NATURAL_CURE 30 // All status conditions heal when the Pokémon switches out.
#define ABILITY_LIGHTNING_ROD 31 // The Pokémon draws in all Electric-type moves. Instead of being hit by Electric-type moves, it boosts its Attack or Sp. Attack stat (which is higher).
#define ABILITY_SERENE_GRACE 32 // Doubles the likelihood of additional effects occurring when attacking.
#define ABILITY_SWIFT_SWIM 33 // Doubles speed in rain.
#define ABILITY_CHLOROPHYLL 34 // Doubles speed in sunshine.
#define ABILITY_ILLUMINATE 35 // Boosts accuracy by 1.2x. Also has its existing field effect.
#define ABILITY_TRACE 36 // *No innate* When it enters a battle, the Pokémon copies an opposing Pokémon's Ability.
#define ABILITY_HUGE_POWER 37 // Doubles the Pokémon's Attack.
#define ABILITY_POISON_POINT 38 // 30% chance to get poisoned on contact against this Pokémon.
#define ABILITY_INNER_FOCUS 39 // The Pokémon's intensely focused, and that protects the Pokémon from flinching, Focus Blast has increased accuracy to 90%.
#define ABILITY_MAGMA_ARMOR 40 // Prevents the Pokémon from becoming frozen. Takes 30% less damage from Water- and Ice-type moves.
#define ABILITY_WATER_VEIL 41 // Prevents the Pokémon from getting a burn. Sets Aqua Ring on entry. [Aqua Ring effect: Restore 1/8 HP every turn]
#define ABILITY_MAGNET_PULL 42 // Traps Steel-type Pokémon.
#define ABILITY_SOUNDPROOF 43 // Soundproofing gives the Pokémon full immunity to all sound-based moves.
#define ABILITY_RAIN_DISH 44 // Restores 1/8 HP per turn under rain.
#define ABILITY_SAND_STREAM 45 // The Pokémon summons a sandstorm when it enters a battle.
#define ABILITY_PRESSURE 46 // When this Pokémon is hit by a move, the opponent’s PP lowers by 2 rather than 1.
#define ABILITY_THICK_FAT 47 // The Pokémon is protected by a layer of thick fat, which halves the damage taken from Fire- and Ice-type moves.
#define ABILITY_EARLY_BIRD 48 // The Pokémon awakens from sleep twice as fast as other Pokémon.
#define ABILITY_FLAME_BODY 49 // 30% chance to get burned on contact against this Pokémon.
#define ABILITY_RUN_AWAY 50 // Enables a sure getaway from wild Pokémon. Boosts the Pokémon's Speed stat sharply when its stats are lowered.
#define ABILITY_KEEN_EYE 51 // Prevents loss of accuracy. Ups accuracy by 20%.
#define ABILITY_HYPER_CUTTER 52 // Prevents other Pokémon from lowering its Attack stat. Contact moves have its critical hit rate increased by 1.
#define ABILITY_PICKUP 53 // Removes all hazards on entry. Has a 10% chance of finding and holding an item after battle. Will not work if this Pokémon is already holding an item. From Black & White, it allows for the user to pick up the item of its opponent or ally if they used up the item in battle.
#define ABILITY_TRUANT 54 // The Pokémon can't use a move if it had used a move on the previous turn.
#define ABILITY_HUSTLE 55 // Boosts the Attack stat by 40%, but lowers accuracy by 10%.
#define ABILITY_CUTE_CHARM 56 // The opponent has a 30% chance of being induced with Attract when using an attack, that requires physical contact, against this Pokémon.
#define ABILITY_PLUS 57 // When battling with Plus or Minus, Special Attack increases by 50%.
#define ABILITY_MINUS 58 // When battling with Plus or Minus, Special Attack increases by 50%.
#define ABILITY_FORECAST 59 // *No innate* This Pokémon’ changes its form and type if Harsh Sunlight, Heavy Rain or Hail is in effect.
#define ABILITY_STICKY_HOLD 60 // Prevents item theft.
#define ABILITY_SHED_SKIN 61 // Every turn, it has a 1 in 3 chance of healing from a status condition (BURN, PARALYZE, SLEEP, POISON, FREEZE).
#define ABILITY_GUTS 62 // Attack is increased by 50% when induced with a status (BURN, PARALYZE, SLEEP, POISON, FREEZE). Burn’s effect of lowering Attack is not applied.
#define ABILITY_MARVEL_SCALE 63 // The Pokémon's marvelous scales boost the Defense stats by 50% if it has a status condition.
#define ABILITY_LIQUID_OOZE 64 // *No innate* The oozed liquid has a strong stench, which damages attackers using any draining move.
#define ABILITY_OVERGROW 65 // Now always provides a 20% damage boost to their move types. This increases to 50% while the Pokémon is at or below 1/3 HP. These boosts do not stack (the 50% boost replaces the 20% one while weakened).
#define ABILITY_BLAZE 66 // // Now always provides a 20% damage boost to their move types. This increases to 50% while the Pokémon is at or below 1/3 HP. These boosts do not stack (the 50% boost replaces the 20% one while weakened).
#define ABILITY_TORRENT 67 // Now always provides a 20% damage boost to their move types. This increases to 50% while the Pokémon is at or below 1/3 HP. These boosts do not stack (the 50% boost replaces the 20% one while weakened).
#define ABILITY_SWARM 68 // Now always provides a 20% damage boost to their move types. This increases to 50% while the Pokémon is at or below 1/3 HP. These boosts do not stack (the 50% boost replaces the 20% one while weakened).
#define ABILITY_ROCK_HEAD 69 // Prevents recoil damage.
#define ABILITY_DROUGHT 70 // Summons sunshine on entry.
#define ABILITY_ARENA_TRAP 71 // Prevents fleeing.
#define ABILITY_VITAL_SPIRIT 72 // Prevents falling asleep.
#define ABILITY_WHITE_SMOKE 73 // The Pokémon is protected by its white smoke, which prevents other Pokémon from lowering its stats
#define ABILITY_PURE_POWER 74 // Doubles Attack.
#define ABILITY_SHELL_ARMOR 75 // A hard shell protects the Pokémon from critical hits. Takes 20% less damage.
#define ABILITY_AIR_LOCK 76 // Eliminates the effects of weather.

#define ABILITIES_COUNT_GEN3 77

// Gen 4
#define ABILITY_TANGLED_FEET 77 // *No innate* Pokémon’s evasion raises one level when Confused.
#define ABILITY_MOTOR_DRIVE 78 // Boosts its Speed stat if hit by an Electric-type move instead of taking damage.
#define ABILITY_RIVALRY 79 // Attack & Special Attack is increased by 25% if the foe is of the same gender.
#define ABILITY_STEADFAST 80 // *No innate* Raises speed by +1 when flinching.
#define ABILITY_SNOW_CLOAK 81 // Boosts the Pokémon's evasiveness in a hailstorm by 20%.
#define ABILITY_GLUTTONY 82 // Eats berries at 1/2 HP instead of 1/3 HP.
#define ABILITY_ANGER_POINT 83 // The Pokémon is angered when it takes a critical hit from physical move from opposing Pokémon, and that maxes its Attack stat. Boosts the Attack stat by one stage when hit by physical moves.
#define ABILITY_UNBURDEN 84 // *No innate* Doubles the Speed stat if the Pokémon's held item is used or lost.
#define ABILITY_HEATPROOF 85 // The heatproof body of the Pokémon halves the damage from Fire-type moves that hit it.
#define ABILITY_SIMPLE 86 // Doubles all stat changes.
#define ABILITY_DRY_SKIN 87 // Rain: HP will increase by 1/8 of its max HP each turn. Intense Sunlight: HP will decrease by 1/8 of its max HP each turn.
#define ABILITY_DOWNLOAD 88 // Compares an opposing Pokémon's Defense and Sp. Def stats before raising its own Attack or Sp. Atk stat—whichever will be more effective.
#define ABILITY_IRON_FIST 89 // The power of punching moves is increased by 30%.
#define ABILITY_POISON_HEAL 90 // Restores 1/8 HP per turn if the Pokémon is poisoned instead of losing HP.
#define ABILITY_ADAPTABILITY 91 // Increases the STAB Bonus from x1.5 to x2.
#define ABILITY_SKILL_LINK 92 // Maximizes the number of times multistrike moves hit.
#define ABILITY_HYDRATION 93 // Heals status conditions every turn if it's raining.
#define ABILITY_SOLAR_POWER 94 // Ups Sp. Atk in the sun by 1.5x. No longer decreases HP at end of every sun turn.
#define ABILITY_QUICK_FEET 95 // Boosts the Speed stat if the Pokémon has a status condition.
#define ABILITY_NORMALIZE 96 // All the Pokémon's moves become Normal type. The power of those moves is boosted by 10%.
#define ABILITY_SNIPER 97 // Power of critical-hit moves is increased to 225% rather than 150%.
#define ABILITY_MAGIC_GUARD 98 // The Pokémon only takes damage from attacks.
#define ABILITY_NO_GUARD 99 // The Pokémon employs no-guard tactics to ensure incoming and outgoing attacks always land.
#define ABILITY_STALL 100 // Always moves last.
#define ABILITY_TECHNICIAN 101 // Powers up the Pokémon's weaker moves with BP 60 or less.
#define ABILITY_LEAF_GUARD 102 // Prevents status conditions in harsh sunlight.
#define ABILITY_KLUTZ 103 // *No innate* Can't use items.
#define ABILITY_MOLD_BREAKER 104 // Moves can be used on the target regardless of its Abilities. Hits Levitate with Ground moves.
#define ABILITY_SUPER_LUCK 105 // Raises the critical-hit ratio of moves by one level.
#define ABILITY_AFTERMATH 106 // The foe that dealt the final hit loses 1/4 of its maximum HP if the move made physical contact.
#define ABILITY_ANTICIPATION 107 // *No innate* Warns when the foe knows 1-hit KO or super-effective moves.
#define ABILITY_FOREWARN 108 // *No innate* Reveals the foe’s strongest move.
#define ABILITY_UNAWARE 109 // Foe’s stat modifications are ignored.
#define ABILITY_TINTED_LENS 110 // The Pokémon can use "not very effective" moves to deal regular damage.
#define ABILITY_FILTER 111 // Reduces the power of supereffective attacks taken by 35%.
#define ABILITY_SLOW_START 112 // For five turns, the Pokémon's Attack and Speed stats are halved, but restores its stats after these five turns.
#define ABILITY_SCRAPPY 113 // The Pokémon can hit: Ghost-type Pokémon with Normal- and Fighting-type moves.
#define ABILITY_STORM_DRAIN 114 // Water-type moves are drawn to this Pokémon. Water-type moves will do no damage and the Pokémon's SP ATK is raised one stage
#define ABILITY_ICE_BODY 115 // Restores 1/8 HP every turn in hailstorm.
#define ABILITY_SOLID_ROCK 116 // Reduces the power of supereffective attacks taken by 35%.
#define ABILITY_SNOW_WARNING 117 // The Pokémon summons a hailstorm when it enters a battle.
#define ABILITY_HONEY_GATHER 118 // *No innate* The Pokémon may gather Honey after a battle.
#define ABILITY_FRISK 119 // *No innate* When it enters a battle, the Pokémon can check an opposing Pokémon's held item.
#define ABILITY_RECKLESS 120 // Powers up moves that have recoil and crash damage by 20%.
#define ABILITY_MULTITYPE 121 // *No innate* Changes the Pokémon's type to match the Plate or Z-Crystal it holds.
#define ABILITY_FLOWER_GIFT 122 // *No innate* Ally’s Attack and Special Defence are multiplied by 1.5 during strong sunlight.
#define ABILITY_BAD_DREAMS 123 // Reduces 1/4 HP of sleeping opposing Pokémon every turn.

#define ABILITIES_COUNT_GEN4 124

// Gen 5
#define ABILITY_PICKPOCKET 124 // *No innate* When a Pokémon makes physical contact with the Pokémon, the item of the opponent is stolen.
#define ABILITY_SHEER_FORCE 125 // Moves with a secondary effect are increased in power by 30% but lose their secondary effect
#define ABILITY_CONTRARY 126 // Makes stat changes have an opposite effect.
#define ABILITY_UNNERVE 127 // *No innate* Unnerves opposing Pokémon and makes them unable to eat Berries or use healing move (but doesn't prevent Leech seed, HP-draining moves, healing items effects ...).
#define ABILITY_DEFIANT 128 // Boosts the Pokémon's Attack stat sharply when its stats are lowered.
#define ABILITY_DEFEATIST 129 // *No innate* Halves Atk & SpAtk at 1/3 HP (instead of 1/2 HP).
#define ABILITY_CURSED_BODY 130 // May disable a move used on the Pokémon.
#define ABILITY_HEALER 131 // At the end of the turn, there is a 30% chance of either Ally being healed from a status condition
#define ABILITY_FRIEND_GUARD 132 // *No innate* The damage that ally Pokémon receive from attacks is reduced by 25%.
#define ABILITY_WEAK_ARMOR 133 // Physical attacks to the Pokémon lower its Defense and Sp. Defense stats but sharply raise its Attack, Sp. Attack and Speed stat.
#define ABILITY_HEAVY_METAL 134 // Doubles the Pokémon's weight.
#define ABILITY_LIGHT_METAL 135 // Halves the Pokémon's weight.
#define ABILITY_MULTISCALE 136 // Reduces damage afflicted to the Pokémon by 50% if at maximum HP
#define ABILITY_TOXIC_BOOST 137 // Attack stat increased by 50% when poisoned. Now immune to poison status damage.
#define ABILITY_FLARE_BOOST 138 // Special Attack stat increased by 50% when burned. Now immune to burn status damage.
#define ABILITY_HARVEST 139 // The Pokémon has a 50% chance of restoring a consumed berry. During sunshine, this chance increases to 100%
#define ABILITY_TELEPATHY 140 // *No innate* Anticipates an ally's attack and dodges it.
#define ABILITY_MOODY 141 // Raises one stat sharply and lowers another every turn.
#define ABILITY_OVERCOAT 142 // Protects the Pokémon from things like sand, hail, and powder. The Pokémon takes 20% less damage from special moves.
#define ABILITY_POISON_TOUCH 143 // 30% chance to badly poison a target when the Pokémon makes contact.
#define ABILITY_REGENERATOR 144 // Restores 1/3 HP when withdrawn from battle.
#define ABILITY_BIG_PECKS 145 // Powers up moves that make direct contact by 30%.
#define ABILITY_SAND_RUSH 146 // Doubles the Pokémon's Speed stat in a sandstorm.
#define ABILITY_WONDER_SKIN 147 // Makes non-damaging moves that are targeted at this Pokémon have the accuracy of 50%.
#define ABILITY_ANALYTIC 148 // Boosts move power by 30% when the Pokémon moves last.
#define ABILITY_ILLUSION 149 // 1.3x damage boost when in Illusion mode.
#define ABILITY_IMPOSTER 150 // *No innate* The Pokémon transforms itself into the Pokémon it's facing.
#define ABILITY_INFILTRATOR 151 // Passes through the opposing Pokémon's barrier, substitute, and the like and strikes.
#define ABILITY_MUMMY 152 // *No innate* Contact with the Pokémon changes the attacker's Ability to Mummy.
#define ABILITY_MOXIE 153 // Attack is raised by one stage when the Pokémon knocks out another Pokémon
#define ABILITY_JUSTIFIED 154 // Attack is raised by one stage when the Pokémon is hit by a Dark-type move
#define ABILITY_RATTLED 155 // Dark-, Ghost-, and Bug-type moves scare the Pokémon and boost its Speed stats.
#define ABILITY_MAGIC_BOUNCE 156 // Reflects status moves instead of getting hit by them.
#define ABILITY_SAP_SIPPER 157 // Immune to Grass-type moves. Instead of being hit by Grass-type moves, it boosts its Attack or Sp. Attack stat (which is higher).
#define ABILITY_PRANKSTER 158 // Gives priority to a status move.
#define ABILITY_SAND_FORCE 159 // Boosts the power of Rock-, Ground-, and Steel-type moves by 30% in a sandstorm.
#define ABILITY_IRON_BARBS 160 // Deals 1/8 HP damage on contact.
#define ABILITY_ZEN_MODE 161 // Changes form regardless of health (So, becomes Zen Mode as soon as Darmanitan is switched in)
#define ABILITY_VICTORY_STAR 162 // Boosts the accuracy of its allies and itself by 20%.
#define ABILITY_TURBOBLAZE 163 // Moves can be used on the target regardless of its Abilities. Adds the Fire-type to the Pokémon, in addition to the Pokémon's original type(s).
#define ABILITY_TERAVOLT 164 // Moves can be used on the target regardless of its Abilities. Adds the Electric-type to the Pokémon, in addition to the Pokémon's original type(s).

#define ABILITIES_COUNT_GEN5 165

// Gen 6
#define ABILITY_AROMA_VEIL 165 // *No innate* Protects itself and its allies from attacks that limit their move choices.
#define ABILITY_FLOWER_VEIL 166 // *No innate* Ally Grass-type Pokémon are protected from status conditions and the lowering of their stats.
#define ABILITY_CHEEK_POUCH 167 // *No innate* Restores HP as well when the Pokémon eats a Berry.
#define ABILITY_PROTEAN 168 // Changes the Pokémon's type to the type of the move it's about to use.
#define ABILITY_FUR_COAT 169 // Halves the damage from physical moves.
#define ABILITY_MAGICIAN 170 // *No innate* The Pokémon steals the held item of a Pokémon it hits with a move.
#define ABILITY_BULLETPROOF 171 // Protects the Pokémon from some ball and bomb moves.
#define ABILITY_COMPETITIVE 172 // Boosts the Sp. Atk stat sharply when a stat is lowered.
#define ABILITY_STRONG_JAW 173 // The Pokémon's strong jaw boosts the power of its biting moves. [Now affects Bug Bite, Super Fang, Deathroll]
#define ABILITY_REFRIGERATE 174 // All Normal-type moves used by the Pokémon to become Ice-type and receive a 10% power boost.
#define ABILITY_SWEET_VEIL 175 // *No innate* Prevents itself and ally Pokémon from falling asleep.
#define ABILITY_STANCE_CHANGE 176 // *No innate* The Pokémon changes its form to Blade Forme when it uses an attack move and changes to Shield Forme when it uses King's Shield.
#define ABILITY_GALE_WINGS 177 // Flying-type moves have +1 priority. Requires full HP.
#define ABILITY_MEGA_LAUNCHER 178 // Boosts all beam, pump, cannon, zooka, shot, gun, aura and pulse moves by 50%.
#define ABILITY_GRASS_PELT 179 // Increases Defense by 50% when battling on Grass or if the move Grassy Terrain is in effect
#define ABILITY_SYMBIOSIS 180 // May pass an item to an ally.
#define ABILITY_TOUGH_CLAWS 181 // Powers up moves by 30% that make direct contact.
#define ABILITY_PIXILATE 182 // All Normal-type moves used by the Pokémon to become Fairy-type and receive a 10% power boost.
#define ABILITY_GOOEY 183 // Lowers speed on contact.
#define ABILITY_AERILATE 184 // All Normal-type moves used by the Pokémon to become Flying-type and receive a 10% power boost.
#define ABILITY_PARENTAL_BOND 185 // Hits twice. Second hit deals 0.25x damage.
#define ABILITY_DARK_AURA 186 // Powers up each Pokémon's Dark-type moves by 50%.
#define ABILITY_FAIRY_AURA 187 // Powers up each Pokémon's Fairy-type moves by 50%.
#define ABILITY_AURA_BREAK 188 // *No innate* The effects of “Aura” Abilities are reversed to lower the power of affected moves.
#define ABILITY_PRIMORDIAL_SEA 189 // The Pokémon changes the weather to nullify Fire-type attacks.
#define ABILITY_DESOLATE_LAND 190 // The Pokémon changes the weather to nullify Water-type attacks.
#define ABILITY_DELTA_STREAM 191 // Creates the Strong Winds weather. This lasts until the Pokémon exits battle, and weakens moves used on Flying-type Pokémon that would be Super Effective

#define ABILITIES_COUNT_GEN6 192

// Gen 7
#define ABILITY_STAMINA 192 // Boosts the Defense stat when hit by an attack. When it takes a critical hit, it maxes its Defense stat.
#define ABILITY_WIMP_OUT 193 // *No innate* The Pokémon cowardly switches out when its HP becomes half or less.
#define ABILITY_EMERGENCY_EXIT 194 // The Pokémon, sensing danger, switches out when its HP becomes half or less.
#define ABILITY_WATER_COMPACTION 195 // When hit by a Water-type move, its Defense rises by +2. Reduces Water type damage by 50%.
#define ABILITY_MERCILESS 196 // The Pokémon's attacks become critical hits if the target is poisoned or its Speed stat stage is -1 or lower.
#define ABILITY_SHIELDS_DOWN 197 // *No innate* Changes the Pokémon into its Core form when its Hit Points drop below 50%. Before then, it cannot be affected by Status Conditions such as Burn or Paralysis
#define ABILITY_STAKEOUT 198 // Doubles the damage dealt to the target's replacement if the target switches out.
#define ABILITY_WATER_BUBBLE 199 // Water Bubble halves the damage dealt to the Pokémon with this Ability by Fire-type attacks and doubles the power of Water-type moves used by the Pokémon with this Ability. It also prevents the Pokémon with the Ability from being burned.
#define ABILITY_STEELWORKER 200 // Powers up Steel-type moves by 30%.
#define ABILITY_BERSERK 201 // *No innate* Boosts the Pokémon's Sp. Atk stat when it takes a hit that causes its HP to become half or less.
#define ABILITY_SLUSH_RUSH 202 // Doubles speed in hail.
#define ABILITY_LONG_REACH 203 // The Pokémon uses its moves without making contact with the target. If a physical move already doesn't make contact before applying this ability, boosts its damage by 20%.
#define ABILITY_LIQUID_VOICE 204 // All sound-based moves become Water-type moves and boosts them by 20%.
#define ABILITY_TRIAGE 205 // Gives +1 priority to healing moves.
#define ABILITY_GALVANIZE 206 // All Normal-type moves become Electric-type moves and boosts them by 10%.
#define ABILITY_SURGE_SURFER 207 // Doubles the Pokémon's Speed stat on Electric Terrain. Works while levitating.
#define ABILITY_SCHOOLING 208 // Changes the Pokémon's form when it is Level 20 and has more than 25% Hit Points. When Hit Points drop below 25%, it changes back to Solo Form
#define ABILITY_DISGUISE 209 // *No innate* Once per battle, the Pokémon can withstand one damaging attack without receiving any damage. Damage inflicted through entry hazards, weather or status conditions will not break the disguise. Damage from Confusion will break the Disguise. It causes 1/8th of max Hit Point damage when it breaks
#define ABILITY_BATTLE_BOND 210 // *No innate* Defeating an opposing Pokémon strengthens the Pokémon's bond with its Trainer, and it becomes Ash-Greninja. Water Shuriken gets more powerful.
#define ABILITY_POWER_CONSTRUCT 211 // *No innate* At the start of battle or at the end of a turn, if the HP of the Pokémon is below half, other cells gather to aid and it change into its Complete Forme. After the battle, if the Pokémon's HP is above half, it reverts to its original form.
#define ABILITY_CORROSION 212 // The Pokémon can poison or attack the target even if it's a Steel or Poison type. Poison-type moves deals "super-effective" damage against Steel-type Pokemon.
#define ABILITY_COMATOSE 213 // Always sleeping, but can use moves.
#define ABILITY_QUEENLY_MAJESTY 214 // Its majesty pressures the opposing Pokémon, making it unable to attack using priority moves.
#define ABILITY_INNARDS_OUT 215 // Damages the attacker landing the finishing hit by the amount equal to its last HP.
#define ABILITY_DANCER 216 // *No innate* When another Pokémon uses a dance move, it can use a dance move following it regardless of its Speed.
#define ABILITY_BATTERY 217 // Powers up ally Pokémon's special moves by 30%.
#define ABILITY_FLUFFY 218 // A Pokémon with Fluffy takes half damage from moves that make contact. It also takes double damage from Fire-type moves.
#define ABILITY_DAZZLING 219 // Surprises the opposing Pokémon, making it unable to attack using priority moves.
#define ABILITY_SOUL_HEART 220 // Boosts its Sp. Atk stat every time a Pokémon faints.
#define ABILITY_TANGLING_HAIR 221 // Contact with the Pokémon will lowers its Speed stat
#define ABILITY_RECEIVER 222 // *No innate* The Pokémon copies the Ability of a defeated ally.
#define ABILITY_POWER_OF_ALCHEMY 223 // *No innate* The Pokémon copies the Ability of a defeated ally.
#define ABILITY_BEAST_BOOST 224 // The Pokémon boosts its most proficient stat each time it knocks out a Pokémon.
#define ABILITY_RKS_SYSTEM 225 // *No innate* Changes the Pokémon's type to match the memory disc it holds.
#define ABILITY_ELECTRIC_SURGE 226 // Activates Electric Terrain for 5 turns when the Pokémon enters a battle.
#define ABILITY_PSYCHIC_SURGE 227 // Activates Psychic Terrain for 5 turns when the Pokémon enters a battle.
#define ABILITY_MISTY_SURGE 228 // Activates Misty Terrain for 5 turns when the Pokémon enters a battle.
#define ABILITY_GRASSY_SURGE 229 // Activates Grassy Terrain for 5 turns when the Pokémon enters a battle.
#define ABILITY_FULL_METAL_BODY 230 // Prevents other Pokémon's moves or abilities from lowering the Pokémon's stats.
#define ABILITY_SHADOW_SHIELD 231 // Reduces damage inflicted on this Pokémon when at max Hit Points by 50%. It is not affected by moves or abilities that would ignore the ability such as Mold Breaker, Moongeist Beam or Sunsteel Strike
#define ABILITY_PRISM_ARMOR 232 // Reduces the power of supereffective attacks taken by 35%.
#define ABILITY_NEUROFORCE 233 // Increases the power of Super Effective moves used by this Pokémon by 25%.

#define ABILITIES_COUNT_GEN7 234

// Gen 8
#define ABILITY_INTREPID_SWORD 234 // Boosts the Pokémon's Attack stat when the Pokémon enters a battle.
#define ABILITY_DAUNTLESS_SHIELD 235 // Boosts the Pokémon's Defense stat when the Pokémon enters a battle.
#define ABILITY_LIBERO 236 // Changes the Pokémon's type to the type of the move it's about to use.
#define ABILITY_BALL_FETCH 237 // *No innate* If the Pokémon is not holding an item, it will fetch the Poké Ball from the first failed throw of the battle.
#define ABILITY_COTTON_DOWN 238 // When the Pokémon is hit by an attack, it scatters cotton fluff around and lowers the Speed stat of all Pokémon except itself.
#define ABILITY_PROPELLER_TAIL 239 // *No innate* Ignores the effects of opposing Pokémon's Abilities and moves that draw in moves.
#define ABILITY_MIRROR_ARMOR 240 // Bounces back only the stat-lowering effects that the Pokémon receives.
#define ABILITY_GULP_MISSILE 241 // *No innate* When using Surf or Dive, it will change into Gulping Form if it has over 50% max HP or Gorging Form if it has less than 50% max HP. If hit afterwards, form reverts and it shoots out its prey to attack, doing 1/4th of opponent's maximum HP in damage. If the Cramorant was in Gulping Form, the opponent's Defense is lowered 1 stage. If the Cramorant was in Gorging Form, the opponent is paralyzed.
#define ABILITY_STALWART 242 // *No innate* Ignores the effects of opposing Pokémon's Abilities and moves that draw in moves.
#define ABILITY_STEAM_ENGINE 243 // Boosts the Pokémon's Speed stat drastically each time it is hit by a Fire- or Water-type move.
#define ABILITY_PUNK_ROCK 244 // Boosts the power of sound-based moves by 30%. The Pokémon also takes half the damage from these kinds of moves.
#define ABILITY_SAND_SPIT 245 // The Pokémon creates a sandstorm when it's hit by an attack.
#define ABILITY_ICE_SCALES 246 // The Pokémon is protected by ice scales, which halve the damage taken from special moves.
#define ABILITY_RIPEN 247 // Ripens Berries and doubles their effect.
#define ABILITY_ICE_FACE 248 // *No innate* Has a protective barrier that protects against Physical Attacks once and will change form to Noice Face after breaking. Confusion also breaks the barrier. Setting Hail or being sent out during hail will restore the Ice Face and change form to Ice Face
#define ABILITY_POWER_SPOT 249 // Increases the power of Ally Pokémon's attacks by 30%
#define ABILITY_MIMICRY 250 // *No innate* Changes the Pokémon's type depending on the terrain.
#define ABILITY_SCREEN_CLEANER 251 // *No innate* When the Pokémon enters a battle, the effects of Light Screen, Reflect, and Aurora Veil are nullified for both opposing and ally Pokémon.
#define ABILITY_STEELY_SPIRIT 252 // Increases the power of Steel-type moves used by the user or any Ally Pokémon by 30%
#define ABILITY_PERISH_BODY 253 // When hit by a move that makes direct contact, the Pokémon and the attacker will faint after three turns unless they switch out of battle.
#define ABILITY_WANDERING_SPIRIT 254 // The Pokémon exchanges Abilities with a Pokémon that hits it with a move that makes direct contact.
#define ABILITY_GORILLA_TACTICS 255 // Boosts the Pokémon's Attack stat but only allows the use of the first selected move.
#define ABILITY_NEUTRALIZING_GAS 256 // *No innate* If the Pokémon with Neutralizing Gas is in the battle, the effects of all Pokémon's abilities will be nullified or will not be triggered.
#define ABILITY_PASTEL_VEIL 257 // *No innate* Protects the Pokémon and its ally Pokémon from being poisoned.
#define ABILITY_HUNGER_SWITCH 258 // *No innate* Morpeko changes its form, alternating between its Full Belly Mode and Hangry Mode after the end of each turn.
#define ABILITY_QUICK_DRAW 259 // At the start of each turn, this Pokémon has a 30% chance of moving first in the Speed Priority Bracket
#define ABILITY_UNSEEN_FIST 260 // *No innate* If the Pokémon uses moves that make direct contact, it can attack the target even if the target protects itself.
#define ABILITY_CURIOUS_MEDICINE 261 // *No innate* When the Pokémon enters a battle, it scatters medicine from its shell, which removes all stat changes from allies.
#define ABILITY_TRANSISTOR 262 // Powers up Electric-type moves by 50%.
#define ABILITY_DRAGONS_MAW 263 // Powers up Dragon-type moves by 50%.
#define ABILITY_CHILLING_NEIGH 264 // *No innate* When the Pokémon knocks out a target, it utters a chilling neigh, which boosts its Attack stat.
#define ABILITY_GRIM_NEIGH 265 // *No innate* When the Pokémon knocks out a target, it utters a terrifying neigh, which boosts its Sp. Atk stat.
#define ABILITY_AS_ONE_ICE_RIDER 266 // *No innate* This ability combines the effects of both Calyrex's Unnerve ability and Glastrier's Chilling Neigh ability/Spectrier's Grim Neigh ability.
#define ABILITY_AS_ONE_SHADOW_RIDER 267 // *No innate* This ability combines the effects of both Calyrex's Unnerve ability and Glastrier's Chilling Neigh ability/Spectrier's Grim Neigh ability.

#define ABILITIES_COUNT_LATEST_GEN 268

// IE Custom Abilities
#define ABILITY_CHLOROPLAST      (ABILITIES_COUNT_LATEST_GEN)      // Moves function as if it's sunny, regardless of weather
#define ABILITY_WHITEOUT         (ABILITIES_COUNT_LATEST_GEN + 1)  // Boosts the power of Ice attacks in Hail by 50%
#define ABILITY_PYROMANCY        (ABILITIES_COUNT_LATEST_GEN + 2)  // Fire attacks are 5x more likely to inflict a burn
#define ABILITY_KEEN_EDGE        (ABILITIES_COUNT_LATEST_GEN + 3)  // Cutting moves do 30% more damage
#define ABILITY_PRISM_SCALES     (ABILITIES_COUNT_LATEST_GEN + 4)  // Reduces special damage taken by 30%
#define ABILITY_POWER_FISTS      (ABILITIES_COUNT_LATEST_GEN + 5)  // Punching moves do special damage and get 30% boost
#define ABILITY_SAND_SONG        (ABILITIES_COUNT_LATEST_GEN + 6)  // Sound moves become Ground type. No damage boost.
#define ABILITY_RAMPAGE          (ABILITIES_COUNT_LATEST_GEN + 7)  // If a recharge move KOs the foe, it doesn't need to recharge.
#define ABILITY_VENGEANCE        (ABILITIES_COUNT_LATEST_GEN + 8)  // Overgrow for Ghost moves.
#define ABILITY_BLITZ_BOXER      (ABILITIES_COUNT_LATEST_GEN + 9)  // Punching moves go first.

// Darky's Custom Abilities / Innates
#define ABILITY_ANTARCTIC_BIRD   (ABILITIES_COUNT_LATEST_GEN + 10) // Ice and Flying-type moves gain 1.3x power.
#define ABILITY_IMMOLATE          (ABILITIES_COUNT_LATEST_GEN + 11) // All Normal-type moves used by the Pokémon become Fire-type and receive a 10% power boost.
#define ABILITY_CRYSTALLIZE      (ABILITIES_COUNT_LATEST_GEN + 12) // All Rock-type moves used by the Pokémon become Ice-type and receive a 10% power boost.
#define ABILITY_ELECTROCYTES     (ABILITIES_COUNT_LATEST_GEN + 13) // Increases the power of Electric-type moves by 25%.
#define ABILITY_AERODYNAMICS     (ABILITIES_COUNT_LATEST_GEN + 14) // Boosts its Speed stat if hit by an Flying-type move instead of taking damage.
#define ABILITY_CHRISTMAS_SPIRIT (ABILITIES_COUNT_LATEST_GEN + 15) // The Pokémon is protected by a mysterious force that reduces all incoming damage by 50% during a hailstorm.
#define ABILITY_EXPLOIT_WEAKNESS (ABILITIES_COUNT_LATEST_GEN + 16) // Increases the power of moves by 25% against targets with status condition.
#define ABILITY_GROUND_SHOCK     (ABILITIES_COUNT_LATEST_GEN + 17) // Allows Electric-type moves to hit Ground-type Pokémon.
#define ABILITY_ANCIENT_IDOL     (ABILITIES_COUNT_LATEST_GEN + 18) // The Pokémon uses its Def/SpDef stat and stages during physical/special moves.
#define ABILITY_MYSTIC_POWER     (ABILITIES_COUNT_LATEST_GEN + 19) // All Pokémon's moves gain the same-type attack bonus (STAB) regardless the Pokémon's typing.
#define ABILITY_PERFECTIONIST    (ABILITIES_COUNT_LATEST_GEN + 20) // Ups crit by +1 for moves with BP 50 or less. Ups crit rate by +1 and priority by +1 for moves with BP 25 or less.
#define ABILITY_GROWING_TOOTH    (ABILITIES_COUNT_LATEST_GEN + 21) // Increases the Attack stat by one stage after using a fang move.
#define ABILITY_INFLATABLE       (ABILITIES_COUNT_LATEST_GEN + 22) // When the Pokémon is hit by Fire-type or Flying-type moves, its Defense and Special Defense stats are increased by one stage.
#define ABILITY_AURORA_BOREALIS  (ABILITIES_COUNT_LATEST_GEN + 23) // Ice-type moves gain STAB. No damage from Hailstorm.
#define ABILITY_AVENGER          (ABILITIES_COUNT_LATEST_GEN + 24) // Boosts the power of the move by 50% if a Pokémon from the user's party has fainted in the previous turn.
#define ABILITY_LETS_ROLL        (ABILITIES_COUNT_LATEST_GEN + 25) // Pokémon starts in Defense Curl, boosting the Defense stage by +1.
#define ABILITY_AQUATIC          (ABILITIES_COUNT_LATEST_GEN + 26) // Adds the Water-type to the Pokémon, in addition to the Pokémon's original type(s).
#define ABILITY_LOUD_BANG        (ABILITIES_COUNT_LATEST_GEN + 27) // There is a 50% chance that the enemy will become confused when affected by the Pokémon's sound-based damaging moves.
#define ABILITY_LEAD_COAT        (ABILITIES_COUNT_LATEST_GEN + 28) // Triples the Pokémon's weight. Increases the Defense stat by 40%, but decreases Speed stat by 10%.
#define ABILITY_AMPHIBIOUS       (ABILITIES_COUNT_LATEST_GEN + 29) // Water-type moves gain 1.5x power.
#define ABILITY_GROUNDED         (ABILITIES_COUNT_LATEST_GEN + 30) // Adds the Ground-type to the Pokémon, in addition to the Pokémon's original type(s).
#define ABILITY_EARTHBOUND       (ABILITIES_COUNT_LATEST_GEN + 31) // Increases own Ground-type attacks by 25%.
#define ABILITY_FIGHT_SPIRIT     (ABILITIES_COUNT_LATEST_GEN + 32) // All Normal-type moves used by the Pokémon become Fighting-type and receive a 10% power boost.
#define ABILITY_FELINE_PROWESS   (ABILITIES_COUNT_LATEST_GEN + 33) // Doubles Special Attack (special Huge/Pure Power).
#define ABILITY_COIL_UP          (ABILITIES_COUNT_LATEST_GEN + 34) // The Pokémon enters the battlefield coiled up. Coil: The next time the Pokémon uses a biting move, its priority is increased 1.
#define ABILITY_FOSSILIZED       (ABILITIES_COUNT_LATEST_GEN + 35) // Only takes half damage from Rock-type moves. Boosts Rock-type moves by 10%.
#define ABILITY_MAGICAL_DUST     (ABILITIES_COUNT_LATEST_GEN + 36) // When is hit by contact move, it leaves a Magic Powder that adds Psychic-type to the target.
#define ABILITY_DREAMCATCHER     (ABILITIES_COUNT_LATEST_GEN + 37) // Boosts power of moves by 50% if a Pokemon is asleep on the field.
#define ABILITY_NOCTURNAL        (ABILITIES_COUNT_LATEST_GEN + 38) // Boosts Dark-type moves by 25%, takes 25% less from Dark and Fairy
#define ABILITY_SELF_SUFFICIENT  (ABILITIES_COUNT_LATEST_GEN + 39) // Heals 1/16 at the end of every turn.
#define ABILITY_TECTONIZE        (ABILITIES_COUNT_LATEST_GEN + 40) // All Normal-type moves used by the Pokémon become Ground-type and receive a 10% power boost.
#define ABILITY_ICE_AGE          (ABILITIES_COUNT_LATEST_GEN + 41) // Adds the Ice-type to the Pokémon, in addition to the Pokémon's original type(s).
#define ABILITY_HALF_DRAKE       (ABILITIES_COUNT_LATEST_GEN + 42) // Adds the Dragon-type to the Pokémon, in addition to the Pokémon's original type(s).
#define ABILITY_LIQUIFIED        (ABILITIES_COUNT_LATEST_GEN + 43) // Takes half damage from contact moves. Takes 2x damage from Water-type moves.
#define ABILITY_DRAGONFLY        (ABILITIES_COUNT_LATEST_GEN + 44) // Adds the Dragon-type to the Pokémon, in addition to the Pokémon's original type(s). Immune to Ground-type moves.
#define ABILITY_DRAGONSLAYER     (ABILITIES_COUNT_LATEST_GEN + 45) // Increases the damage dealt against Dragon-type Pokémon by 50%.
#define ABILITY_MOUNTAINEER      (ABILITIES_COUNT_LATEST_GEN + 46) // Immune to Rock attacks and Stealth Rocks.
#define ABILITY_HYDRATE          (ABILITIES_COUNT_LATEST_GEN + 47) // All Normal-type moves used by the Pokémon become Water-type and receive a 10% power boost.
#define ABILITY_METALLIC         (ABILITIES_COUNT_LATEST_GEN + 48) // Adds the Steel-type to the Pokémon, in addition to the Pokémon's original type(s).
#define ABILITY_PERMAFROST       (ABILITIES_COUNT_LATEST_GEN + 49) // Reduces damage taken from super-effective attacks by 25%
#define ABILITY_PRIMAL_ARMOR     (ABILITIES_COUNT_LATEST_GEN + 50) // Reduces damage taken from super-effective attacks by 50%
#define ABILITY_RAGING_BOXER     (ABILITIES_COUNT_LATEST_GEN + 51) // Punch moves hit twice, second hit deals 0.5x.
#define ABILITY_AIR_BLOWER       (ABILITIES_COUNT_LATEST_GEN + 52) // Sets Tailwind for 5 turns when entering battle.
#define ABILITY_JUGGERNAUT       (ABILITIES_COUNT_LATEST_GEN + 53) // Contact moves use 20% of its Defense stat additionally. Also, the Pokémon cannot be paralyzed.
#define ABILITY_SHORT_CIRCUIT    (ABILITIES_COUNT_LATEST_GEN + 54) // Overgrow for Electric moves.
#define ABILITY_MAJESTIC_BIRD    (ABILITIES_COUNT_LATEST_GEN + 55) // Boosts Special Attack by 50%.
#define ABILITY_PHANTOM          (ABILITIES_COUNT_LATEST_GEN + 56) // Adds the Ghost-type to the Pokémon, in addition to the Pokémon's original type(s).
#define ABILITY_INTOXICATE        (ABILITIES_COUNT_LATEST_GEN + 57) // All Normal-type moves used by the Pokémon to become Poison-type and receive a 10% power boost.
#define ABILITY_IMPENETRABLE     (ABILITIES_COUNT_LATEST_GEN + 58) // Takes no indirect damage.
#define ABILITY_HYPNOTIST        (ABILITIES_COUNT_LATEST_GEN + 59) // Increases Hypnosis accuracy by 50%.
#define ABILITY_OVERWHELM        (ABILITIES_COUNT_LATEST_GEN + 60) // The Pokémon can hit Fairy-type Pokémon with Dragon-type moves. Also blocks Intimidate and Scare.
#define ABILITY_SCARE            (ABILITIES_COUNT_LATEST_GEN + 61) // Special Intimidate.
#define ABILITY_MAJESTIC_MOTH    (ABILITIES_COUNT_LATEST_GEN + 62) // Increases the highest stat by one stage upon entering the battlefield.
#define ABILITY_SOUL_EATER       (ABILITIES_COUNT_LATEST_GEN + 63) // Whenever another Pokémon faints, restores 25% of its maximum HP.
#define ABILITY_SOUL_LINKER      (ABILITIES_COUNT_LATEST_GEN + 64) // Your own and the enemy Pokemon get each damage. The effect won't activate if the one of the affected Pokémon faints.
#define ABILITY_SWEET_DREAMS     (ABILITIES_COUNT_LATEST_GEN + 65) // At the end of each turn, each sleeping allies restores 1/8 HP. Your side is immune to opposing Bad Dreams.
#define ABILITY_BAD_LUCK         (ABILITIES_COUNT_LATEST_GEN + 66) // Enemies can't critically hit and have decreased accuracy of 5%.
#define ABILITY_HAUNTED_SPIRIT   (ABILITIES_COUNT_LATEST_GEN + 67) // When the Pokémon faints by a damaging move from an opposing Pokémon, the attacker becomes cursed.
#define ABILITY_ELECTRIC_BURST   (ABILITIES_COUNT_LATEST_GEN + 68) // The Pokémon's Electric-type moves are boosted by 35%, but the Pokémon takes 10% of damage dealt.
#define ABILITY_RAW_WOOD         (ABILITIES_COUNT_LATEST_GEN + 69) // Halves incoming Rock-type damage. Boosts Rock-type moves by 10%.");
#define ABILITY_SOLENOGLYPHS     (ABILITIES_COUNT_LATEST_GEN + 70) // Biting moves have a 50% chance of badly poisoning the target.
#define ABILITY_SPIDER_LAIR      (ABILITIES_COUNT_LATEST_GEN + 71) // Sets up Sticky Web on entry.
#define ABILITY_FATAL_PRECISION  (ABILITIES_COUNT_LATEST_GEN + 72) // Super Effective Moves from this Pokemon can’t miss and receive a 20% damage boost.
#define ABILITY_FORT_KNOX        (ABILITIES_COUNT_LATEST_GEN + 73) // Boosts the Pokémon's Defense stat by +3 when its stats are lowered.
#define ABILITY_SEAWEED          (ABILITIES_COUNT_LATEST_GEN + 74) // Grass-type takes neutral damage from Fire-type moves. Deals neutral damage against Fire-type with Grass-type moves.
#define ABILITY_PSYCHIC_MIND     (ABILITIES_COUNT_LATEST_GEN + 75) // Boosts the power of Psychic-type moves by 25%.
#define ABILITY_POISON_ABSORB    (ABILITIES_COUNT_LATEST_GEN + 76) // Restore 1/4 HP when hit by Poison-type moves.
#define ABILITY_SCAVENGER        (ABILITIES_COUNT_LATEST_GEN + 77) // Heals 1/4 HP when defeating an enemy.
#define ABILITY_TWISTED_DIMENSION (ABILITIES_COUNT_LATEST_GEN + 78) // Summons Trick Room on entry.
#define ABILITY_MULTI_HEADED     (ABILITIES_COUNT_LATEST_GEN + 79) // Hit two or three times depending on the number of heads with single target moves, dealing 25% or 33% more damage. (Doesn't work with multi-hit moves like Comet Punch).
#define ABILITY_NORTH_WIND       (ABILITIES_COUNT_LATEST_GEN + 80) // Sets Aurora Veil on entry. Immune to Hail damage.
#define ABILITY_OVERCHARGE       (ABILITIES_COUNT_LATEST_GEN + 81) // Electric does 2x damage against Electric. Can paralyze Electric-types.
#define ABILITY_VIOLENT_RUSH     (ABILITIES_COUNT_LATEST_GEN + 82) // Boosts Speed by 1.5x, Attack by 1.2x on first turn (same activation requirements as Fake Out)
#define ABILITY_FLAMING_SOUL     (ABILITIES_COUNT_LATEST_GEN + 83) // Fire-type moves have +1 priority. Requires full HP.
#define ABILITY_SAGE_POWER       (ABILITIES_COUNT_LATEST_GEN + 84) // Automatically locked into the first move chosen, but boosts Special Attack by 1.5x (Gorilla Tactics for Special moves)
#define ABILITY_BONE_ZONE        (ABILITIES_COUNT_LATEST_GEN + 85) // Bone-Based moves ignore immunities and also deal double damage on not very effective. 
#define ABILITY_WEATHER_CONTROL  (ABILITIES_COUNT_LATEST_GEN + 86) // Negates all moves related to weather condition from opposing Pokémon. [Affected moves: Thunder, Blizzard, Solar Beam, Solar Blade, Hurricane]
#define ABILITY_SPEED_FORCE      (ABILITIES_COUNT_LATEST_GEN + 87) // Contact moves use 20% of its Speed stat additionally.
#define ABILITY_SEA_GUARDIAN     (ABILITIES_COUNT_LATEST_GEN + 88) // Ups highest stat on entry when it rains.
#define ABILITY_MOLTEN_DOWN      (ABILITIES_COUNT_LATEST_GEN + 89) // The Pokémon's Fire-type moves become super effective against Rock-type.
#define ABILITY_HYPER_AGGRESSIVE (ABILITIES_COUNT_LATEST_GEN + 90) // Hits twice. Second hit does 25% damage.
#define ABILITY_FLOCK            (ABILITIES_COUNT_LATEST_GEN + 91) // Overgrow for Flying moves.
#define ABILITY_FIELD_EXPLORER   (ABILITIES_COUNT_LATEST_GEN + 92) // Increases the power of field moves by 25%. [Affected moves: Dig, Headbutt, Secret Power, Chatter, Fly, Cut, Strength, Surf, Waterfall, Rock Climb, Flash, Whirlpool, Dive]
#define ABILITY_STRIKER          (ABILITIES_COUNT_LATEST_GEN + 93) // Boosts kicking moves by 1.3x. Moves affected by Striker: Blaze Kick, Jump Kick, High Jump Kick, Triple Axel, Triple Kick, Stomp, Mega Kick, Low Kick, Rolling Kick, Trop Kick, Pyro Ball, High Horsepower, Double Kick, Thunderous Kick.
#define ABILITY_FROZEN_SOUL      (ABILITIES_COUNT_LATEST_GEN + 94) // Ice--type moves have +1 priority. Requires full HP.
#define ABILITY_PREDATOR         (ABILITIES_COUNT_LATEST_GEN + 95) // Heals 1/4 HP when defeating an enemy.
#define ABILITY_LOOTER           (ABILITIES_COUNT_LATEST_GEN + 96) // Heals 1/4 HP when defeating an enemy.
#define ABILITY_LUNAR_ECLIPSE    (ABILITIES_COUNT_LATEST_GEN + 97) // The Pokémon's Fairy- and Dark-type moves gain same-type attack bonus regardless the Pokémon's typing. Hypnosis has its Accuracy increased by 50%.
#define ABILITY_SOLAR_FLARE      (ABILITIES_COUNT_LATEST_GEN + 98) // The Pokémon's Fire-type moves gain same-type attack bonus regardless the Pokémon's typing. The Pokémon does not need a turn to charge to use Solar Beam and Solar Blade and Morning Sun recovers twice as much HP.
#define ABILITY_POWER_CORE       (ABILITIES_COUNT_LATEST_GEN + 99) // The Pokémon uses 25% of its Defense stat during physical moves and Special Defense stat during special moves in addition to the default stat. (Defense and Special Defense stat stages still affects these percentage).
#define ABILITY_SIGHTING_SYSTEM  (ABILITIES_COUNT_LATEST_GEN + 100) // When the Pokémon uses a move with Accuracy of 50% or lower, the move will have 100% Accuracy, but have its priority decreased by 3.
#define ABILITY_BAD_COMPANY      (ABILITIES_COUNT_LATEST_GEN + 101) // *NO USE* Prevents self lowering stat drops and recoil.
#define ABILITY_OPPORTUNIST      (ABILITIES_COUNT_LATEST_GEN + 102) // If target's HP is 50% or below, your single-target damaging moves get priority +1.
#define ABILITY_GIANT_WINGS      (ABILITIES_COUNT_LATEST_GEN + 103) // Boosts all air, wing and wind moves by 25%, including Twister, Hurricane and Heat Wave.
#define ABILITY_MOMENTUM         (ABILITIES_COUNT_LATEST_GEN + 104) // Contact moves use Speed stat instead for the damage calculation (counts Speed stage-modifiers).
#define ABILITY_GRIP_PINCER      (ABILITIES_COUNT_LATEST_GEN + 105) // Contact moves have 50% chance to trap the foe for two to three turns. If the target is trapped, contact moves bypass target's Defense and accuracy check.
#define ABILITY_BIG_LEAVES       (ABILITIES_COUNT_LATEST_GEN + 106) // Solar Beam/Blade doesn't need to charge; Synthesis recovers twice as much HP; Growth doubles stat changes; Chlorophyll, Harvest, Leaf Guard and Solar Power are activated.
#define ABILITY_PRECISE_FIST     (ABILITIES_COUNT_LATEST_GEN + 107) // Punching moves have critical rate increased by +1 and have double the chance of secondary effects.
#define ABILITY_DEADEYE          (ABILITIES_COUNT_LATEST_GEN + 108) // Never misses.
#define ABILITY_ARTILLERY        (ABILITIES_COUNT_LATEST_GEN + 109) // Beam, pump, cannon, zooka, shot, aura and pulse moves cannot miss and single-target moves hit both foes.
#define ABILITY_AMPLIFIER        (ABILITIES_COUNT_LATEST_GEN + 110) // Sound-based moves now target all foes [Affected moves: Hyper Voice, Boomburst, Bug Buzz, Chatter, Confide, Disarming Voice, Echoed Voice, Eerie Spell, Grass Whistle, Metal Sound, Noble Roar, Parting Shot, Roar, Round, Screech, Sing, Snore, Supersonic, Uproar etc.]. Also boosts power by 30%.
#define ABILITY_ICE_DEW          (ABILITIES_COUNT_LATEST_GEN + 111) // Immune to Ice-type moves. Instead of being hit by Ice-type moves, it boosts its Attack or Sp. Attack stat (which is higher).
#define ABILITY_SUN_WORSHIP      (ABILITIES_COUNT_LATEST_GEN + 112) // Ups highest stat on entry when it's sunny.
#define ABILITY_POLLINATE        (ABILITIES_COUNT_LATEST_GEN + 113) // All Normal-type moves used by the Pokémon become Bug-type and receive a 10% power boost.
#define ABILITY_VOLCANO_RAGE     (ABILITIES_COUNT_LATEST_GEN + 114) // Triggers 50 BP Eruption after using a Fire-type move.
#define ABILITY_COLD_REBOUND     (ABILITIES_COUNT_LATEST_GEN + 115) // Everytime when hit by a contact move, counter-attacks with Icy Wind.
#define ABILITY_LOW_BLOW         (ABILITIES_COUNT_LATEST_GEN + 116) // Attacks with Feint Attack on switch-in.
#define ABILITY_NOSFERATU        (ABILITIES_COUNT_LATEST_GEN + 117) // Contact Moves do +20% damage and heal the user for 33% of the damage dealt.
#define ABILITY_SPECTRAL_SHROUD  (ABILITIES_COUNT_LATEST_GEN + 118) // Spectralize, plus 30% chance to badly poison.
#define ABILITY_DISCIPLINE       (ABILITIES_COUNT_LATEST_GEN + 119) // Moves like Outrage no longer trap you. Immunity to Confusion, Intimidate and Scare.
#define ABILITY_THUNDERCALL      (ABILITIES_COUNT_LATEST_GEN + 120) // When using an Electric-type move, follows up with Smite at 20% of its power.
#define ABILITY_MARINE_APEX      (ABILITIES_COUNT_LATEST_GEN + 121) // 50% more damage to Water-types + Infiltrator.
#define ABILITY_MIGHTY_HORN      (ABILITIES_COUNT_LATEST_GEN + 122) // Boosts horn / drill moves by 1.3x. Moves affected: Horn Attack, Horn Drill, Drill Peck, Megahorn, Drill Run, Horn Leech, Fury Attack, Poison Jab, Peck, Smart Strike
#define ABILITY_HARDENED_SHEATH  (ABILITIES_COUNT_LATEST_GEN + 123) // Increases the Attack stat by one stage after using a horn move. Moves affected: Horn Attack, Horn Drill, Drill Peck, Megahorn, Drill Run, Horn Leech, Fury Attack, Poison Jab, Peck, Smart Strike
#define ABILITY_ARCTIC_FUR       (ABILITIES_COUNT_LATEST_GEN + 124) // Takes 35% less damage from incoming physical & special moves.
#define ABILITY_SPECTRALIZE      (ABILITIES_COUNT_LATEST_GEN + 125) // All Normal-type moves used by the Pokémon become Ghost-type and receive a 10% power boost.
#define ABILITY_LETHARGY         (ABILITIES_COUNT_LATEST_GEN + 126) // Atk drops 20% each turn to 20%. Resets on switch-in.
#define ABILITY_IRON_BARRAGE     (ABILITIES_COUNT_LATEST_GEN + 127) // Combines Mega Launcher with Sighting System
#define ABILITY_STEEL_BARREL     (ABILITIES_COUNT_LATEST_GEN + 128) // Protects the Pokémon from recoil damage.
#define ABILITY_PYRO_SHELLS      (ABILITIES_COUNT_LATEST_GEN + 129) // Triggers 50 BP Outburst after using a Mega Launcher move.
#define ABILITY_FUNGAL_INFECTION (ABILITIES_COUNT_LATEST_GEN + 130) // Every attacking move inflicts Leech Seed on the target.
#define ABILITY_PARRY            (ABILITIES_COUNT_LATEST_GEN + 131) // Takes 80% from Contact, then counters with Mach Punch.
#define ABILITY_SCRAPYARD        (ABILITIES_COUNT_LATEST_GEN + 132) // when being hit by any attacking move (like Stamina), trigger Spikes
#define ABILITY_LOOSE_QUILLS     (ABILITIES_COUNT_LATEST_GEN + 133) // when being hit by any attacking move (like Stamina), trigger Spikes
#define ABILITY_TOXIC_DEBRIS     (ABILITIES_COUNT_LATEST_GEN + 134) // Scatters poison spikes at the feet of the opposing team when the Pokémon takes damage from physical moves.
#define ABILITY_ROUNDHOUSE       (ABILITIES_COUNT_LATEST_GEN + 135) // Kick Moves can't miss and also deal damage depending on the lower of the target's defenses.
#define ABILITY_MINERALIZE       (ABILITIES_COUNT_LATEST_GEN + 136) // All Normal-type moves used by the Pokémon become Rock-type and receive a 10% power boost.
#define ABILITY_LOOSE_ROCKS      (ABILITIES_COUNT_LATEST_GEN + 137) // when being hit by any attacking move (like Stamina), trigger Stealth Rock
#define ABILITY_SPINNING_TOP     (ABILITIES_COUNT_LATEST_GEN + 138) // Fighting-type moves raise speed by +1 and clear hazards.
#define ABILITY_RETRIBUTION_BLOW (ABILITIES_COUNT_LATEST_GEN + 139) // Everytime a foe uses a stat boosting move, trigger a full power Hyperbeam.
#define ABILITY_FEARMONGER       (ABILITIES_COUNT_LATEST_GEN + 140) // Scare + Intimidate + 10% chance to paralyze with attacks.
#define ABILITY_KINGS_WRATH      (ABILITIES_COUNT_LATEST_GEN + 141) // When a stat is lowered, boost Atk and Def by +1. Includes Ally Drops.
#define ABILITY_QUEENS_MOURNING  (ABILITIES_COUNT_LATEST_GEN + 142) // When a stat is lowered, boost SpAtk and SpDef by +1. Includes Ally Drops.
#define ABILITY_TOXIC_SPILL      (ABILITIES_COUNT_LATEST_GEN + 143) // The user regurgitates it's toxic fluids onto the field, causing all non-Poison Type Pokemon on the field to take 1/8th of their max HP at the end of every turn. Effect disappears when the Pokémon is not on the field anymore.
#define ABILITY_DESERT_CLOAK     (ABILITIES_COUNT_LATEST_GEN + 144) // The pokemon shrouds itself and allies protecting them from status conditions and secondary effects while under sand.
#define ABILITY_DRACONIZE        (ABILITIES_COUNT_LATEST_GEN + 145) // All Normal-type moves used by the Pokémon become Dragon-type and receive a 10% power boost.
#define ABILITY_PRETTY_PRINCESS  (ABILITIES_COUNT_LATEST_GEN + 146) // Increases the damage dealt against foes with lowered stats by 50%.
#define ABILITY_SELF_REPAIR      (ABILITIES_COUNT_LATEST_GEN + 147) // Self Sufficient + Natural Cure
#define ABILITY_ATOMIC_BURST     (ABILITIES_COUNT_LATEST_GEN + 148) // When taking super-effective damage, use Hyper Beam at 33% Power.
#define ABILITY_HELLBLAZE        (ABILITIES_COUNT_LATEST_GEN + 149) // Ups Fire moves by 30%, 80% when at 1/3 HP.
#define ABILITY_RIPTIDE          (ABILITIES_COUNT_LATEST_GEN + 150) // Ups Water moves by 30%, 80% when at 1/3 HP.
#define ABILITY_FOREST_RAGE      (ABILITIES_COUNT_LATEST_GEN + 151) // Ups Grass moves by 30%, 80% when at 1/3 HP.
#define ABILITY_PRIMAL_MAW       (ABILITIES_COUNT_LATEST_GEN + 152) // Biting moves hit twice, second hit deals 0.5x.
#define ABILITY_SWEEPING_EDGE    (ABILITIES_COUNT_LATEST_GEN + 153) // Keen Edge moves cannot miss and single-target moves hit both foes.
#define ABILITY_GIFTED_MIND      (ABILITIES_COUNT_LATEST_GEN + 154) // Immune to Psychic Weakness and always hits status moves
#define ABILITY_HYDRO_CIRCUIT    (ABILITIES_COUNT_LATEST_GEN + 155) // Electric moves get a 50% Boost and water moves drain 25% of the damage dealt.
#define ABILITY_EQUINOX          (ABILITIES_COUNT_LATEST_GEN + 156) // The user Attack and Special Attack are equal to the higher of the two, Applies after Stat Modifiers.
#define ABILITY_ABSORBANT        (ABILITIES_COUNT_LATEST_GEN + 157) // 1.5x drain on draining moves, draining moves can cause leech seed effect.
#define ABILITY_CLUELESS         (ABILITIES_COUNT_LATEST_GEN + 158) // When this Pokemon is on the field, all field effects, such as weather, rooms, or terrains, are negated
#define ABILITY_CHEATING_DEATH   (ABILITIES_COUNT_LATEST_GEN + 159) // You get no damage for the first two hits.
#define ABILITY_CHEAP_TACTICS    (ABILITIES_COUNT_LATEST_GEN + 160) // Attacks with Scratch on switch-in.
#define ABILITY_COWARD           (ABILITIES_COUNT_LATEST_GEN + 161) // Sets up Protect on switch-in. Only works once.
#define ABILITY_VOLT_RUSH        (ABILITIES_COUNT_LATEST_GEN + 162) // Electric-type moves have +1 priority. Requires full HP.
#define ABILITY_DUNE_TERROR      (ABILITIES_COUNT_LATEST_GEN + 163) // Sand reduces damage by 35%. Boosts Ground moves by 20%.
#define ABILITY_INFERNAL_RAGE    (ABILITIES_COUNT_LATEST_GEN + 164) // Fire-type moves are boosted by 35% with 5% recoil.
#define ABILITY_DUAL_WIELD       (ABILITIES_COUNT_LATEST_GEN + 165) // Mega Launcher moves hit twice, each hit at 75% power.
#define ABILITY_ELEMENTAL_CHARGE (ABILITIES_COUNT_LATEST_GEN + 166) // 20% chance to BRN/FRZ/PARA with respective types.
#define ABILITY_AMBUSH           (ABILITIES_COUNT_LATEST_GEN + 167) // Guaranteed critical hit on first turn.
#define ABILITY_ATLAS            (ABILITIES_COUNT_LATEST_GEN + 168) // Sets Gravity on entry for 8 turns. User moves last.
#define ABILITY_RADIANCE         (ABILITIES_COUNT_LATEST_GEN + 169) // +20% accuracy; Dark moves fail when user is present.
#define ABILITY_JAWS_OF_CARNAGE  (ABILITIES_COUNT_LATEST_GEN + 170) // Heals 50% HP when defeating an enemy.
#define ABILITY_ANGELS_WRATH     (ABILITIES_COUNT_LATEST_GEN + 171) // Radically changes the user's moves.
#define ABILITY_PRISMATIC_FUR    (ABILITIES_COUNT_LATEST_GEN + 172) // Color Change + Protean + Fur Coat + Ice Scales
#define ABILITY_SHOCKING_JAWS    (ABILITIES_COUNT_LATEST_GEN + 173) // Biting moves are 5x more likely to inflict paralysis
#define ABILITY_FAE_HUNTER       (ABILITIES_COUNT_LATEST_GEN + 174) // Increases the damage dealt against Fairy-type Pokémon by 50%.
#define ABILITY_GRAVITY_WELL     (ABILITIES_COUNT_LATEST_GEN + 175) // Sets Gravity on entry for 5 turns.
#define ABILITY_EVAPORATE        (ABILITIES_COUNT_LATEST_GEN + 176) // Takes no damage and sets Mist if hit by water
#define ABILITY_LUMBERJACK       (ABILITIES_COUNT_LATEST_GEN + 177) // 1.5x damage against GRASS types.
#define ABILITY_WELL_BAKED_BODY    (ABILITIES_COUNT_LATEST_GEN + 178) // Halves damage and +2 defense\n when hit by a FIRE type move.
#define ABILITY_FURNACE          (ABILITIES_COUNT_LATEST_GEN + 179) // Upon getting hit by a rock move or switching on stealth rocks user gains +2 speed 
#define ABILITIES_COUNT_CUSTOM   (ABILITY_FURNACE + 1)

#define ABILITIES_COUNT ABILITIES_COUNT_CUSTOM

#endif  // GUARD_CONSTANTS_ABILITIES_H
