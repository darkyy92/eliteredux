#ifndef GUARD_CONSTANTS_ABILITIES_H
#define GUARD_CONSTANTS_ABILITIES_H

#define ABILITY_NONE 0 // No special ability.
#define ABILITY_STENCH 1 // 10% chance to cause a foe to flinch.
#define ABILITY_DRIZZLE 2 // Summons rain in battle. Lasts 8 turns.
#define ABILITY_SPEED_BOOST 3 // Gradually boosts Speed.
#define ABILITY_BATTLE_ARMOR 4 // Blocks critical hits. Takes 20% less damage.
#define ABILITY_STURDY 5 // Negates 1-hit KO attacks.
#define ABILITY_DAMP 6 // Prevents self-destruction.
#define ABILITY_LIMBER 7 // Prevents paralysis. Takes 50% less recoil damage.
#define ABILITY_SAND_VEIL 8 // Ups evasion in a sandstorm.
#define ABILITY_STATIC 9 // 30% chance to paralyze on contact. Works on offense too.
#define ABILITY_VOLT_ABSORB 10 // Turns electricity into HP.
#define ABILITY_WATER_ABSORB 11 // Changes water into HP.
#define ABILITY_OBLIVIOUS 12 // Prevents attraction.
#define ABILITY_CLOUD_NINE 13 // Negates weather effects.
#define ABILITY_COMPOUND_EYES 14 // 1.3x accuracy boost.
#define ABILITY_INSOMNIA 15 // Prevents sleep.
#define ABILITY_COLOR_CHANGE 16 // Changes type before getting hit.
#define ABILITY_IMMUNITY 17 // Prevents poisoning. Halves damage from Poison.
#define ABILITY_FLASH_FIRE 18 // Powers up Fire moves 50% if hit by fire.
#define ABILITY_SHIELD_DUST 19 // Prevents added effects. Avoids entry hazard damage.
#define ABILITY_OWN_TEMPO 20 // Prevents confusion. Blocks Intimidate and Scare.
#define ABILITY_SUCTION_CUPS 21 // Negates moves that force switching out.
#define ABILITY_INTIMIDATE 22 // Lowers the foe's Attack.
#define ABILITY_SHADOW_TAG 23 // Prevents the foe's escape.
#define ABILITY_ROUGH_SKIN 24 // 1/8 HP damage when touched.
#define ABILITY_WONDER_GUARD 25 // Only “Supereffective” hits.
#define ABILITY_LEVITATE 26 // Not hit by Ground attacks. Ups Flying moves by 25%.
#define ABILITY_EFFECT_SPORE 27 // Leaves spores on contact.
#define ABILITY_SYNCHRONIZE 28 // Passes on status problems.
#define ABILITY_CLEAR_BODY 29 // Prevents stat reductions.
#define ABILITY_NATURAL_CURE 30 // Heals status problems upon switching out.
#define ABILITY_LIGHTNING_ROD 31 // Draws electrical moves. Boosts Atk or SpAtk.
#define ABILITY_SERENE_GRACE 32 // Doubles the chance for added effects.
#define ABILITY_SWIFT_SWIM 33 // 1.5x Speed in rain.
#define ABILITY_CHLOROPHYLL 34 // 1.5x Speed in sunshine.
#define ABILITY_ILLUMINATE 35 // 1.2x accuracy boost.
#define ABILITY_TRACE 36 // Copies foe's ability. Does not copy Innates.
#define ABILITY_HUGE_POWER 37 // Doubles Attack.
#define ABILITY_POISON_POINT 38 // 30% chance to get poisoned on contact.
#define ABILITY_INNER_FOCUS 39 // Prevents flinching. Focus Blast has 90% acc.
#define ABILITY_MAGMA_ARMOR 40 // Prevents freezing. Takes 30% less damage from Water and Ice.
#define ABILITY_WATER_VEIL 41 // No burns. Aqua Ring on entry. Recovers 1/16 HP a turn.
#define ABILITY_MAGNET_PULL 42 // Traps Steel-type Pokémon.
#define ABILITY_SOUNDPROOF 43 // Avoids sound-based moves.
#define ABILITY_RAIN_DISH 44 // 1/8 HP recovery in rain.
#define ABILITY_SAND_STREAM 45 // Summons a sandstorm. Lasts 8 turns.
#define ABILITY_PRESSURE 46 // Doubles foe's PP usage.
#define ABILITY_THICK_FAT 47 // Takes half damage from Fire and Ice type attacks.
#define ABILITY_EARLY_BIRD 48 // Awakens twice as fast from sleep.
#define ABILITY_FLAME_BODY 49 // 30% chance to burn on contact. Also works on offense.
#define ABILITY_RUN_AWAY 50 // Makes escaping easier. Lowering stats ups Speed.
#define ABILITY_KEEN_EYE 51 // Prevents loss of accuracy. 1.2x accuracy boost.
#define ABILITY_HYPER_CUTTER 52 // Prevents Attack reduction. Ups crit level by +1.
#define ABILITY_PICKUP 53 // Removes all hazards on entry. Not immune to hazards.
#define ABILITY_TRUANT 54 // Moves only every two turns.
#define ABILITY_HUSTLE 55 // -10% accuracy, but +40% Atk & SpAtk.
#define ABILITY_CUTE_CHARM 56 // Infatuates on contact, which halves foe's power.
#define ABILITY_PLUS 57 // Doubles damage with Minus.
#define ABILITY_MINUS 58 // Doubles damage with Plus.
#define ABILITY_FORECAST 59 // Changes with the weather. Weather setting triggers attack.
#define ABILITY_STICKY_HOLD 60 // Prevents item theft.
#define ABILITY_SHED_SKIN 61 // 30% chance to heal status conditions.
#define ABILITY_GUTS 62 // Ups Attack by 50% if suffering.
#define ABILITY_MARVEL_SCALE 63 // Ups Defense by 50% if suffering.
#define ABILITY_LIQUID_OOZE 64 // Draining causes injury.
#define ABILITY_OVERGROW 65 // Ups Grass moves by 20%, 50% when at 1/3 HP.
#define ABILITY_BLAZE 66 // Ups Fire moves by 20%, 50% when at 1/3 HP.
#define ABILITY_TORRENT 67 // Ups Water moves by 20%, 50% when at 1/3 HP.
#define ABILITY_SWARM 68 // Ups Bug moves by 20%, 50% when at 1/3 HP.
#define ABILITY_ROCK_HEAD 69 // Prevents recoil damage.
#define ABILITY_DROUGHT 70 // Summons sunlight in battle. Lasts 8 turns.
#define ABILITY_ARENA_TRAP 71 // Prevents fleeing.
#define ABILITY_VITAL_SPIRIT 72 // Prevents sleep.
#define ABILITY_WHITE_SMOKE 73 // Prevents stat reduction.
#define ABILITY_PURE_POWER 74 // Doubles Attack.
#define ABILITY_SHELL_ARMOR 75 // Blocks critical hits. Takes 20% less damage.
#define ABILITY_AIR_LOCK 76 // Negates weather effects.

#define ABILITIES_COUNT_GEN3 (ABILITY_AIR_LOCK + 1)

#define ABILITY_TANGLED_FEET 77 // Ups evasion if confused.
#define ABILITY_MOTOR_DRIVE 78 // Electricity raises Speed by one level.
#define ABILITY_RIVALRY 79 // + 25% against same gender. Normal against opposite.
#define ABILITY_STEADFAST 80 // Flinching raises Speed by +1.
#define ABILITY_SNOW_CLOAK 81 // Ups evasion one level in Hail.
#define ABILITY_GLUTTONY 82 // Eats Berries early.
#define ABILITY_ANGER_POINT 83 // Critical hits maximize Attack. Getting hit raises Attack.
#define ABILITY_UNBURDEN 84 // Using a hold item doubles Speed.
#define ABILITY_HEATPROOF 85 // Burn damage protection. Halves Fire damage.
#define ABILITY_SIMPLE 86 // Doubles all stat changes.
#define ABILITY_DRY_SKIN 87 // Prefers moisture to heat. Immune to Water, 1.25x dmg from Fire.
#define ABILITY_DOWNLOAD 88 // Adjusts Attack or Special Attack favorably.
#define ABILITY_IRON_FIST 89 // Boosts punching moves by 30%.
#define ABILITY_POISON_HEAL 90 // Restores HP 1/8 if poisoned.
#define ABILITY_ADAPTABILITY 91 // Increases STAB bonus from 50% to 100%.
#define ABILITY_SKILL_LINK 92 // Multi-hit moves hit 5 times.
#define ABILITY_HYDRATION 93 // Cures status in rain.
#define ABILITY_SOLAR_POWER 94 // Powers up SpAtk by 50% in sunshine.
#define ABILITY_QUICK_FEET 95 // Ups Speed by 50% if suffering.
#define ABILITY_NORMALIZE 96 // Moves become Normal-type, get a 10% boost, and ignore resists.
#define ABILITY_SNIPER 97 // Critical hits do 225% instead of 150% damage.
#define ABILITY_MAGIC_GUARD 98 // Only damaged by attacks.
#define ABILITY_NO_GUARD 99 // Ensures that all moves hit.
#define ABILITY_STALL 100 // Always moves last.
#define ABILITY_TECHNICIAN 101 // Boosts moves with less than 60 BP by 50%.
#define ABILITY_LEAF_GUARD 102 // Blocks status in sunshine.
#define ABILITY_KLUTZ 103 // Can't use hold items.
#define ABILITY_MOLD_BREAKER 104 // Moves hit through abilities. Also affects innates.
#define ABILITY_SUPER_LUCK 105 // Raises critical-hit ratio of moves by one level.
#define ABILITY_AFTERMATH 106 // When fainted by a contact move, damages the foe.
#define ABILITY_ANTICIPATION 107 // Senses dangerous moves.
#define ABILITY_FOREWARN 108 // Determines a foe's move.
#define ABILITY_UNAWARE 109 // Ignores foe's stat changes.
#define ABILITY_TINTED_LENS 110 // “not very effective” deals normal damage.
#define ABILITY_FILTER 111 // Weakens “supereffective” by 35%.
#define ABILITY_SLOW_START 112 // Halves Attack and Speed during the first 5 turns.
#define ABILITY_SCRAPPY 113 // Hits Ghost-type Pokémon. Immune to Intimidate/Scare.
#define ABILITY_STORM_DRAIN 114 // Water ups Atk or SpAtk by +1.
#define ABILITY_ICE_BODY 115 // 1/8 HP recovery in Hail.
#define ABILITY_SOLID_ROCK 116 // Weakens “supereffective” by 35%.
#define ABILITY_SNOW_WARNING 117 // Summons a hailstorm. Lasts 8 turns.
#define ABILITY_HONEY_GATHER 118 // May gather Honey.
#define ABILITY_FRISK 119 // Checks a foe's item and disables it for two turns.
#define ABILITY_RECKLESS 120 // Boosts moves with recoil by 20%.
#define ABILITY_MULTITYPE 121 // Changes type to its Plate.
#define ABILITY_FLOWER_GIFT 122 // Transforms in sunshine.
#define ABILITY_BAD_DREAMS 123 // Damages sleeping Pokémon by 1/4 HP per round.

#define ABILITIES_COUNT_GEN4 (ABILITY_BAD_DREAMS + 1)

#define ABILITY_PICKPOCKET 124 // Steals the foe's held item on contact.
#define ABILITY_SHEER_FORCE 125 // Trades effects for 30% more power.
#define ABILITY_CONTRARY 126 // Inverts stat changes.
#define ABILITY_UNNERVE 127 // Foes can't eat Berries.
#define ABILITY_DEFIANT 128 // Lowered stats up Attack by two levels.
#define ABILITY_DEFEATIST 129 // Halves Atk and SpAtk at 1/3 HP.
#define ABILITY_CURSED_BODY 130 // 30% chance to disable moves on contact.
#define ABILITY_HEALER 131 // 30% chance to heal a partner from status conditions.
#define ABILITY_FRIEND_GUARD 132 // Lowers damage to partners by 50%.
#define ABILITY_WEAK_ARMOR 133 // On contact: -1 Defense and +2 Speed.
#define ABILITY_HEAVY_METAL 134 // Doubles weight.
#define ABILITY_LIGHT_METAL 135 // Raises speed by 30% Halves weight.
#define ABILITY_MULTISCALE 136 // Halves damage at full HP.
#define ABILITY_TOXIC_BOOST 137 // Ups Attack 50% if poisoned. Immune to Poison damage.
#define ABILITY_FLARE_BOOST 138 // Ups Sp. Atk 50% if burned. Immune to Burn damage.
#define ABILITY_HARVEST 139 // 50% chance to recycle a used berry, 100% in sunshine.
#define ABILITY_TELEPATHY 140 // Can't be damaged by an ally.
#define ABILITY_MOODY 141 // Every turn, a random stat goes -1 and another one goes +2.
#define ABILITY_OVERCOAT 142 // Blocks weather and powder. 20% less dmg from Special moves.
#define ABILITY_POISON_TOUCH 143 // 30% chance to get poisoned on contact.
#define ABILITY_REGENERATOR 144 // Heals 1/3 HP upon switching out.
#define ABILITY_BIG_PECKS 145 // Boosts contact moves by 30%.
#define ABILITY_SAND_RUSH 146 // 1.5x Speed in a sandstorm.
#define ABILITY_WONDER_SKIN 147 // Foe's status moves only have 50% accuracy.
#define ABILITY_ANALYTIC 148 // Moving last boosts power by 30%.
#define ABILITY_ILLUSION 149 // Appears as a partner + 30% boost under Illusion.
#define ABILITY_IMPOSTER 150 // Transforms into the foe.
#define ABILITY_INFILTRATOR 151 // Passes through barriers like Substitute and such.
#define ABILITY_MUMMY 152 // Spreads with contact.
#define ABILITY_MOXIE 153 // KOs raise Attack by +1.
#define ABILITY_JUSTIFIED 154 // Dark hits raise Attack by one level.
#define ABILITY_RATTLED 155 // Raises Speed +1 when hit by Bug, Ghost, Dark or scared.
#define ABILITY_MAGIC_BOUNCE 156 // Reflects status moves.
#define ABILITY_SAP_SIPPER 157 // Grass ups Atk or SpAtk by +1.
#define ABILITY_PRANKSTER 158 // Status moves have +1 priority. Fails on Dark types.
#define ABILITY_SAND_FORCE 159 // Powers up by 30% in a sandstorm.
#define ABILITY_IRON_BARBS 160 // 1/8 HP damage when touched.
#define ABILITY_ZEN_MODE 161 // Transforms into Zen Mode.
#define ABILITY_VICTORY_STAR 162 // 1.2x accuracy boost for itself and allies.
#define ABILITY_TURBOBLAZE 163 // Moves hit through abilities. Adds Fire-Type.
#define ABILITY_TERAVOLT 164 // Moves hit through abilities. Adds Electric-Type.

#define ABILITIES_COUNT_GEN5 (ABILITY_TERAVOLT + 1)

#define ABILITY_AROMA_VEIL 165 // Prevents limiting of moves.
#define ABILITY_FLOWER_VEIL 166 // Protects itself and ally Grass-types from stat lowering.
#define ABILITY_CHEEK_POUCH 167 // Eating Berries restores 33% HP.
#define ABILITY_PROTEAN 168 // Changes type to used move.
#define ABILITY_FUR_COAT 169 // Halves damage from physical moves against this Pokémon.
#define ABILITY_MAGICIAN 170 // Steals the foe's held item on non-contact.
#define ABILITY_BULLETPROOF 171 // Protects from projectiles, ball and bomb moves.
#define ABILITY_COMPETITIVE 172 // Lowered stats up Sp. Atk by two levels.
#define ABILITY_STRONG_JAW 173 // Boosts biting moves by 50%.
#define ABILITY_REFRIGERATE 174 // Normal moves become Ice and get a 10% boost.
#define ABILITY_SWEET_VEIL 175 // Prevents itself and allies from sleep.
#define ABILITY_STANCE_CHANGE 176 // Transforms as it battles.
#define ABILITY_GALE_WINGS 177 // Flying moves get +1 priority. Requires full HP.
#define ABILITY_MEGA_LAUNCHER 178 // Ups beam/pump/cannon/shot/gun/ zooka/aura/pulse moves by 50%.
#define ABILITY_GRASS_PELT 179 // Ups Defense 50% in Grassy Terrain.
#define ABILITY_SYMBIOSIS 180 // Passes its item to an ally.
#define ABILITY_TOUGH_CLAWS 181 // Boosts contact moves by 30%.
#define ABILITY_PIXILATE 182 // Normal moves become Fairy and get a 10% boost.
#define ABILITY_GOOEY 183 // Lowers Speed on contact by -1.
#define ABILITY_AERILATE 184 // Normal moves become Flying and get a 10% boost.
#define ABILITY_PARENTAL_BOND 185 // Moves hit twice. 2nd hit does 25% damage.
#define ABILITY_DARK_AURA 186 // Boosts Dark moves by 33%.
#define ABILITY_FAIRY_AURA 187 // Boosts Fairy moves by 33%.
#define ABILITY_AURA_BREAK 188 // Reverses aura abilities and makes them 25% weaker.
#define ABILITY_PRIMORDIAL_SEA 189 // Summons heavy rain. Fire has no effect.
#define ABILITY_DESOLATE_LAND 190 // Summons intense sunlight. Water has no effect.
#define ABILITY_DELTA_STREAM 191 // Summons strong winds. Immune to weather-based moves.

#define ABILITIES_COUNT_GEN6 (ABILITY_DELTA_STREAM + 1)

#define ABILITY_STAMINA 192 // Boosts Defense +1 when hit. Maxes Defense on crit.
#define ABILITY_WIMP_OUT 193 // Flees at half HP.
#define ABILITY_EMERGENCY_EXIT 194 // Flees at half HP.
#define ABILITY_WATER_COMPACTION 195 // Water boosts Defense by +2. Takes half damage from Water.
#define ABILITY_MERCILESS 196 // Criticals poisoned, speed -reduced or paralyzed foes.
#define ABILITY_SHIELDS_DOWN 197 // Shell breaks at half HP.
#define ABILITY_STAKEOUT 198 // Does double damage on foes switching in.
#define ABILITY_WATER_BUBBLE 199 // Half fire damage, no burns, doubles own Water moves.
#define ABILITY_STEELWORKER 200 // Powers up Steel moves by 30%.
#define ABILITY_BERSERK 201 // Boosts Sp. Atk by +1 when at half HP or lower.
#define ABILITY_SLUSH_RUSH 202 // 1.5x Speed in hail.
#define ABILITY_LONG_REACH 203 // Never makes contact and boost damage of non-contact 20%.
#define ABILITY_LIQUID_VOICE 204 // Makes sound moves Water and get a 20% boost.
#define ABILITY_TRIAGE 205 // Healing moves have +1 priority.
#define ABILITY_GALVANIZE 206 // Normal moves turn Electric and get a 10% boost.
#define ABILITY_SURGE_SURFER 207 // 1.5x Speed on Electric Terrain. Works while levitating.
#define ABILITY_SCHOOLING 208 // Forms a school when over 25% HP. Needs level 20 or higher.
#define ABILITY_DISGUISE 209 // Decoy protects it once.
#define ABILITY_BATTLE_BOND 210 // Changes form after a KO.
#define ABILITY_POWER_CONSTRUCT 211 // Cells aid it when under half HP.
#define ABILITY_CORROSION 212 // Poisons any type. Poison moves are super-effective to Steel.
#define ABILITY_COMATOSE 213 // Always drowsing. Immune to status moves.
#define ABILITY_QUEENLY_MAJESTY 214 // Protects itself and ally from priority moves.
#define ABILITY_INNARDS_OUT 215 // Hurts foe when defeated.
#define ABILITY_DANCER 216 // Dances along with others.
#define ABILITY_BATTERY 217 // Boosts ally's Sp. Atk by 30%.
#define ABILITY_FLUFFY 218 // Half damage from contact moves, takes double damage from Fire.
#define ABILITY_DAZZLING 219 // Protects itself and ally from priority moves.
#define ABILITY_SOUL_HEART 220 // KOs raise Sp. Atk by +1.
#define ABILITY_TANGLING_HAIR 221 // Lowers Speed on contact by -1.
#define ABILITY_RECEIVER 222 // Copies ally's ability.
#define ABILITY_POWER_OF_ALCHEMY 223 // Copies ally's ability.
#define ABILITY_BEAST_BOOST 224 // KOs boost best stat.
#define ABILITY_RKS_SYSTEM 225 // Memories change its type.
#define ABILITY_ELECTRIC_SURGE 226 // Field becomes Electric.
#define ABILITY_PSYCHIC_SURGE 227 // Field becomes weird.
#define ABILITY_MISTY_SURGE 228 // Field becomes misty.
#define ABILITY_GRASSY_SURGE 229 // Field becomes grassy.
#define ABILITY_FULL_METAL_BODY 230 // Prevents stat reduction.
#define ABILITY_SHADOW_SHIELD 231 // Halves damage at full HP.
#define ABILITY_PRISM_ARMOR 232 // Weakens “supereffective” by 35%.
#define ABILITY_NEUROFORCE 233 // Ups “supereffective” by 25%.

#define ABILITIES_COUNT_GEN7 (ABILITY_NEUROFORCE + 1)

#define ABILITY_INTREPID_SWORD 234 // Ups Attack on entry by +1.
#define ABILITY_DAUNTLESS_SHIELD 235 // Ups Defense on entry by +1.
#define ABILITY_LIBERO 236 // Changes type to move's.
#define ABILITY_BALL_FETCH 237 // Fetches failed Poké Ball.
#define ABILITY_COTTON_DOWN 238 // Lower Speed of all when hit.
#define ABILITY_PROPELLER_TAIL 239 // Ignores foe's redirection.
#define ABILITY_MIRROR_ARMOR 240 // Reflect stat decreases.
#define ABILITY_GULP_MISSILE 241 // If hit, spits prey from sea.
#define ABILITY_STALWART 242 // Ignores foe's redirection.
#define ABILITY_STEAM_ENGINE 243 // Fire or Water hits up Speed.
#define ABILITY_PUNK_ROCK 244 // Ups sound moves by 30% Takes half damage from sound.
#define ABILITY_SAND_SPIT 245 // Creates a sandstorm if hit.
#define ABILITY_ICE_SCALES 246 // Halves special damage.
#define ABILITY_RIPEN 247 // Doubles effect of Berries.
#define ABILITY_ICE_FACE 248 // Take a free hit. Hail renews.
#define ABILITY_POWER_SPOT 249 // Powers up ally moves by 30%.
#define ABILITY_MIMICRY 250 // Changes type on terrain.
#define ABILITY_SCREEN_CLEANER 251 // Removes walls of light.
#define ABILITY_STEELY_SPIRIT 252 // Boosts own and ally's Steel moves by 30%.
#define ABILITY_PERISH_BODY 253 // Foe faints in 3 turns if hit.
#define ABILITY_WANDERING_SPIRIT 254 // Trade abilities on contact.
#define ABILITY_GORILLA_TACTICS 255 // Ups Attack by 50% and locks move.
#define ABILITY_NEUTRALIZING_GAS 256 // All Abilities are nullified. Innates still work.
#define ABILITY_PASTEL_VEIL 257 // Sets up safeguard upon entry  for 5 turns.
#define ABILITY_HUNGER_SWITCH 258 // Changes form each turn.
#define ABILITY_QUICK_DRAW 259 // Moves first occasionally.
#define ABILITY_UNSEEN_FIST 260 // Contact evades protection.
#define ABILITY_CURIOUS_MEDICINE 261 // Remove ally's stat changes.
#define ABILITY_TRANSISTOR 262 // Ups Electric-type moves by 50%.
#define ABILITY_DRAGONS_MAW 263 // Ups Dragon-type moves by 30%.
#define ABILITY_CHILLING_NEIGH 264 // KOs boost Attack stat +1.
#define ABILITY_GRIM_NEIGH 265 // KOs boost Sp. Atk stat +1.
#define ABILITY_AS_ONE_ICE_RIDER 266 // Unnerve and Chilling Neigh.
#define ABILITY_AS_ONE_SHADOW_RIDER 267 // Unnerve and Grim Neigh.

#define ABILITIES_COUNT_LATEST_GEN (ABILITY_AS_ONE_SHADOW_RIDER + 1)

#define ABILITY_CHLOROPLAST 268 // Battles as if in sunlight. Does not trigger abilities.
#define ABILITY_WHITEOUT 269 // Boosts Ice moves by 50% in Hail.
#define ABILITY_PYROMANCY 270 // Fire moves burn 5x more often.
#define ABILITY_KEEN_EDGE 271 // Boosts slashing moves by 30%.
#define ABILITY_PRISM_SCALES 272 // Weakens Special Attacks by 30%.
#define ABILITY_POWER_FISTS 273 // Punches do special damage and 30% more damage.
#define ABILITY_SAND_SONG 274 // Normal sound moves become Ground and get a 20% boost.
#define ABILITY_RAMPAGE 275 // No recharge after a KO.
#define ABILITY_VENGEANCE 276 // Ups Ghost moves by 20%, 50% when at 1/3 HP.
#define ABILITY_BLITZ_BOXER 277 // Punching moves have +1 priority at full health.
#define ABILITY_ANTARCTIC_BIRD 278 // Ice and Flying-type moves gain 30% more power.
#define ABILITY_IMMOLATE 279 // Normal moves become Fire and get a 10% boost.
#define ABILITY_CRYSTALLIZE 280 // Rock moves become Ice and get a 10% boost.
#define ABILITY_ELECTROCYTES 281 // Increases Electric-type moves by 25%.
#define ABILITY_AERODYNAMICS 282 // Getting hit by Flying raises Speed by +1 instead.
#define ABILITY_CHRISTMAS_SPIRIT 283 // Reduces incoming damage in Hail by 50%.
#define ABILITY_EXPLOIT_WEAKNESS 284 // +25% damage against foes with any status problem.
#define ABILITY_GROUND_SHOCK 285 // Electric moves hit Ground not very effective.
#define ABILITY_ANCIENT_IDOL 286 // Hits with its Defense Stats respectively.
#define ABILITY_MYSTIC_POWER 287 // Gains STAB for all moves.
#define ABILITY_PERFECTIONIST 288 // +1 crit to moves <50 BP. +1 crit & +1 prio for <25 BP
#define ABILITY_GROWING_TOOTH 289 // Ups Attack by +1 when using biting moves.
#define ABILITY_INFLATABLE 290 // Ups both Defenses by +1 when hit by Flying or Fire Moves.
#define ABILITY_AURORA_BOREALIS 291 // Gains STAB for Ice Moves.
#define ABILITY_AVENGER 292 // Hits 50% harder one-time if an ally fainted last turn.
#define ABILITY_LETS_ROLL 293 // Starts in Defense Curl. Ups Defense by +1.
#define ABILITY_AQUATIC 294 // Adds Water-Type.
#define ABILITY_LOUD_BANG 295 // Sound moves have 50% chance to confuse the foe.
#define ABILITY_LEAD_COAT 296 // Reduces physical damage taken by 40%, but decreases Speed by 10%.
#define ABILITY_AMPHIBIOUS 297 // Water moves gain STAB (+ 50% power).
#define ABILITY_GROUNDED 298 // Adds Ground-Type.
#define ABILITY_EARTHBOUND 299 // Increases Ground-type moves by 25%.
#define ABILITY_FIGHT_SPIRIT 300 // Normal moves become Fighting and get a 10% boost.
#define ABILITY_FELINE_PROWESS 301 // Doubles Special Attack.
#define ABILITY_COIL_UP 302 // Biting moves have +1 priority the first time they are used.
#define ABILITY_FOSSILIZED 303 // Halves incoming Rock-type damage. Boosts Rock-type moves by 20%.
#define ABILITY_MAGICAL_DUST 304 // Adds Psychic-type to the foe if hit by a contact move
#define ABILITY_DREAMCATCHER 305 // Doubles move power when anyone on the field is asleep.
#define ABILITY_NOCTURNAL 306 // Boosts Dark-type moves by 25%, takes 25% less from Dark / Fairy.
#define ABILITY_SELF_SUFFICIENT 307 // Recovers 1/16 of its health each turn.
#define ABILITY_TECTONIZE 308 // Normal moves become Ground and get a 10% boost.
#define ABILITY_ICE_AGE 309 // Adds Ice-Type.
#define ABILITY_HALF_DRAKE 310 // Adds Dragon-Type.
#define ABILITY_LIQUIFIED 311 // Half damage from contact moves, takes double damage from Water.
#define ABILITY_DRAGONFLY 312 // Adds Dragon Type and levitates.
#define ABILITY_DRAGONSLAYER 313 // Does 50% more damage to Dragon-types.
#define ABILITY_MOUNTAINEER 314 // Immune to Rock-type and Stealth Rock damage.
#define ABILITY_HYDRATE 315 // Normal moves become Water and get a 10% boost.
#define ABILITY_METALLIC 316 // Adds Steel-Type.
#define ABILITY_PERMAFROST 317 // Weakens “supereffective” by 25%.
#define ABILITY_PRIMAL_ARMOR 318 // Weakens “supereffective” by 50%.
#define ABILITY_RAGING_BOXER 319 // Punch moves hit twice. 2nd hit does 0.5x damage.
#define ABILITY_AIR_BLOWER 320 // Sets up Tailwind for 3 turns when sent out.
#define ABILITY_JUGGERNAUT 321 // Contact moves use + 20% of its Defense stat. Can't get paralyzed.
#define ABILITY_SHORT_CIRCUIT 322 // Ups Electric moves by 20%, 50% when at 1/3 HP.
#define ABILITY_MAJESTIC_BIRD 323 // Boosts Special Attack by 50%.
#define ABILITY_PHANTOM 324 // Adds Ghost-Type.
#define ABILITY_INTOXICATE 325 // Normal moves become Poison and get a 10% boost.
#define ABILITY_IMPENETRABLE 326 // Takes no indirect damage.
#define ABILITY_HYPNOTIST 327 // Hypnosis accuracy is 90% now.
#define ABILITY_OVERWHELM 328 // Can hit Fairy with Dragon Blocks Intimidate and Scare.
#define ABILITY_SCARE 329 // Lowers the foe's Special Attack.
#define ABILITY_MAJESTIC_MOTH 330 // Ups highest stat by +1 on entry.
#define ABILITY_SOUL_EATER 331 // Heals 1/4 HP when defeating an enemy.
#define ABILITY_SOUL_LINKER 332 // Receives any damage inflicted, shares all damage taken.
#define ABILITY_SWEET_DREAMS 333 // Heals 1/8 HP when sleeping, immune to Bad Dreams.
#define ABILITY_BAD_LUCK 334 // Foes can't land crits, have -5% accuracy, and deal min damage.
#define ABILITY_HAUNTED_SPIRIT 335 // When the Pokemon faints, the attacker becomes cursed.
#define ABILITY_ELECTRIC_BURST 336 // Ups Electric moves by 35% but gets 10% recoil damage.
#define ABILITY_RAW_WOOD 337 // Halves incoming Grass-type damage. Boosts Grass-type moves by 20%.
#define ABILITY_SOLENOGLYPHS 338 // Biting moves have 50% chance to poison the target.
#define ABILITY_SPIDER_LAIR 339 // Sets up Sticky Web on entry. Disappears after 5 turns.
#define ABILITY_FATAL_PRECISION 340 // Super-effective never misses and gets 20% stronger.
#define ABILITY_FORT_KNOX 341 // Boosts Defense by +3 when stats are lowered.
#define ABILITY_SEAWEED 342 // Grass becomes neutral against Fire and vice-versa.
#define ABILITY_PSYCHIC_MIND 343 // Increases Psychic-type moves by 25%.
#define ABILITY_POISON_ABSORB 344 // Turns poison into HP.
#define ABILITY_SCAVENGER 345 // Heals 1/4 HP when defeating an enemy.
#define ABILITY_TWISTED_DIMENSION 346 // Sets up Trick Room on entry, lasts 3 turns.
#define ABILITY_MULTI_HEADED 347 // Hits as many times, as it has heads.
#define ABILITY_NORTH_WIND 348 // 3 turns Aurora Veil on entry. Immune to Hail damage.
#define ABILITY_OVERCHARGE 349 // Electric does 2x dmg to Electric. Can paralyze Electric.
#define ABILITY_VIOLENT_RUSH 350 // Boosts Speed by 50% + Attack by 20% on first turn.
#define ABILITY_FLAMING_SOUL 351 // Fire moves get +1 priority. Requires full HP.
#define ABILITY_SAGE_POWER 352 // Ups Special Attack by 50% and locks move.
#define ABILITY_BONE_ZONE 353 // Bone moves ignore immunities and deal 2x on not very effective.
#define ABILITY_WEATHER_CONTROL 354 // Negates all weather based moves from enemies.
#define ABILITY_SPEED_FORCE 355 // Contact moves use 20% of its Speed stat additionally.
#define ABILITY_SEA_GUARDIAN 356 // Ups highest stat by +1 on entry when it rains.
#define ABILITY_MOLTEN_DOWN 357 // Fire-type is super effective against Rock-type.
#define ABILITY_HYPER_AGGRESSIVE 358 // Moves hit twice. Second hit does 25% damage.
#define ABILITY_FLOCK 359 // Ups Flying moves by 20%, 50% when at 1/3 HP.
#define ABILITY_FIELD_EXPLORER 360 // Boosts field moves by 25%. Cut, Surf, Strength etc.
#define ABILITY_STRIKER 361 // Boosts kicking moves by 30%.
#define ABILITY_FROZEN_SOUL 362 // Ice moves get +1 priority. Requires full HP.
#define ABILITY_PREDATOR 363 // Heals 1/4 HP when defeating an enemy.
#define ABILITY_LOOTER 364 // Heals 1/4 HP when defeating an enemy.
#define ABILITY_LUNAR_ECLIPSE 365 // Fairy & Dark gains STAB. Hypnosis has 1.5x accuracy.
#define ABILITY_SOLAR_FLARE 366 // Chloroplast + Immolate. Fire moves gain STAB.
#define ABILITY_POWER_CORE 367 // The Pokémon uses +20% of its Defense or SpDef during moves.
#define ABILITY_SIGHTING_SYSTEM 368 // Moves always hit. Moves last for moves less than 80% accuracy.
#define ABILITY_BAD_COMPANY 369 // Not implemented right now.
#define ABILITY_OPPORTUNIST 370 // If target has less than half HP, single-target moves get +1 prio.
#define ABILITY_GIANT_WINGS 371 // Boosts all air, wind and wing moves by 25%
#define ABILITY_MOMENTUM 372 // Contact moves use the Speed stat for damage calculation.
#define ABILITY_GRIP_PINCER 373 // 50% chance to trap. Then ignores Defense & accuracy checks.
#define ABILITY_BIG_LEAVES 374 // Chloroplast/phyll, Harvest, Leaf Guard and Solar Power.
#define ABILITY_PRECISE_FIST 375 // Punching moves get +1 crit and double effect chance.
#define ABILITY_DEADEYE 376 // Never misses.
#define ABILITY_ARTILLERY 377 // Mega Launcher moves always hit. Single-target now hits both foes.
#define ABILITY_AMPLIFIER 378 // Ups sound moves by 30% and makes them hit both foes.
#define ABILITY_ICE_DEW 379 // Ice ups Atk or SpAtk by +1.
#define ABILITY_SUN_WORSHIP 380 // Ups highest stat by +1 on entry when sunny.
#define ABILITY_POLLINATE 381 // Normal moves become Bug and get a 10% boost.
#define ABILITY_VOLCANO_RAGE 382 // Triggers 50 BP Eruption after using a Fire-type move.
#define ABILITY_COLD_REBOUND 383 // Attacks with Icy Wind when hit by a contact move.
#define ABILITY_LOW_BLOW 384 // Attacks with Feint Attack on switch-in.
#define ABILITY_NOSFERATU 385 // Contact moves do +20% damage and heal 1/2 of damage dealt.
#define ABILITY_SPECTRAL_SHROUD 386 // Spectralize + 30% chance to badly poison the foe.
#define ABILITY_DISCIPLINE 387 // Rampage moves no longer trap you. Can't be confused or intimidated.
#define ABILITY_THUNDERCALL 388 // Triggers Smite at 20% power when using an Electric move.
#define ABILITY_MARINE_APEX 389 // 50% more damage to Water- types + Infiltrator.
#define ABILITY_MIGHTY_HORN 390 // Boosts horn- and drill-based moves by 30%.
#define ABILITY_HARDENED_SHEATH 391 // Ups Attack by +1 when using horn moves.
#define ABILITY_ARCTIC_FUR 392 // Weakens incoming physical and special moves by 35%.
#define ABILITY_SPECTRALIZE 393 // Normal moves turn Ghost and get a 10% boost.
#define ABILITY_LETHARGY 394 // Damage drops 20% each turn to 20%. Resets on switch-in.
#define ABILITY_IRON_BARRAGE 395 // Combines Mega Launcher with Sighting System.
#define ABILITY_STEEL_BARREL 396 // Prevents recoil damage.
#define ABILITY_PYRO_SHELLS 397 // Triggers 50 BP Outburst after using a Mega Launcher move.
#define ABILITY_FUNGAL_INFECTION 398 // Every attacking move inflicts Leech Seed on the target.
#define ABILITY_PARRY 399 // Takes 80% from Contact, then counters with Mach Punch.
#define ABILITY_SCRAPYARD 400 // Sets a layer of Spikes when hit (contact move).
#define ABILITY_LOOSE_QUILLS 401 // Sets a layer of Spikes when hit (contact move).
#define ABILITY_TOXIC_DEBRIS 402 // Sets a layer of Toxic Spikes when hit by contact moves.
#define ABILITY_ROUNDHOUSE 403 // Kicks always hit. Damages foes' weaker defenses.
#define ABILITY_MINERALIZE 404 // Normal moves become Rock and get a 10% boost.
#define ABILITY_LOOSE_ROCKS 405 // Deploys Stealth Rocks when hit.
#define ABILITY_SPINNING_TOP 406 // Fighting moves up speed +1 and clear hazards.
#define ABILITY_RETRIBUTION_BLOW 407 // Uses Hyper Beam if any foe uses an stat boosting move.
#define ABILITY_FEARMONGER 408 // Intimidate + Scare; 10% para chance on contact moves.
#define ABILITY_KINGS_WRATH 409 // Lowering any stats on its side raises Atk and Def.
#define ABILITY_QUEENS_MOURNING 410 // Lowering any stats on its side raises SpAtk and SpDef.
#define ABILITY_TOXIC_SPILL 411 // Non-Poison-types get 1/8 dmg every turn when on field.
#define ABILITY_DESERT_CLOAK 412 // Protects it's side from status and secondary effects in sand.
#define ABILITY_DRACONIZE 413 // Normal moves become Dragon and get a 10% boost.
#define ABILITY_PRETTY_PRINCESS 414 // Does 50% more damage if the target has any lowered stat.
#define ABILITY_SELF_REPAIR 415 // Leftovers + Natural Cure.
#define ABILITY_ATOMIC_BURST 416 // When hit super-effectively, triggers 50 BP Hyper Beam.
#define ABILITY_HELLBLAZE 417 // Ups Fire moves by 30%, 80% when at 1/3 HP.
#define ABILITY_RIPTIDE 418 // Ups Water moves by 30%, 80% when at 1/3 HP.
#define ABILITY_FOREST_RAGE 419 // Ups Grass moves by 30%, 80% when at 1/3 HP.
#define ABILITY_PRIMAL_MAW 420 // Biting moves hit twice. 2nd hit does 0.5x damage.
#define ABILITY_SWEEPING_EDGE 421 // Keen Edge moves always hit. Single-target now hits both foes.
#define ABILITY_GIFTED_MIND 422 // Nulls Psychic weakness; status moves always hit.
#define ABILITY_HYDRO_CIRCUIT 423 // Electric moves +50%; Water moves siphon 25% damage.
#define ABILITY_EQUINOX 424 // Boosts Atk or SpAtk to match the higher value.
#define ABILITY_ABSORBANT 425 // Drain moves recover +50% HP & apply Leech Seed.
#define ABILITY_CLUELESS 426 // Negates Weather, Rooms and Terrains.
#define ABILITY_CHEATING_DEATH 427 // Gets no damage for the first two hits.
#define ABILITY_CHEAP_TACTICS 428 // Attacks with Scratch on switch-in.
#define ABILITY_COWARD 429 // Sets up Protect on switch-in. Only works once.
#define ABILITY_VOLT_RUSH 430 // Electric moves get +1 priority. Requires full HP.
#define ABILITY_DUNE_TERROR 431 // Sand reduces damage by 35%. Boosts Ground moves by 20%.
#define ABILITY_INFERNAL_RAGE 432 // Fire-type moves are boosted by 35% with 5% recoil.
#define ABILITY_DUAL_WIELD 433 // Mega Launcher and Keen Edge moves hit twice for 75% damage.
#define ABILITY_ELEMENTAL_CHARGE 434 // 20% chance to BRN/FRZ/PARA with respective types.
#define ABILITY_AMBUSH 435 // Guaranteed critical hit on first turn.
#define ABILITY_ATLAS 436 // Sets Gravity on entry for 8 turns. User moves last.
#define ABILITY_RADIANCE 437 // +20% accuracy; Dark moves fail when user is present.
#define ABILITY_JAWS_OF_CARNAGE 438 // Devours half of the foe when defeating it.
#define ABILITY_ANGELS_WRATH 439 // Drastically alters all of the users moves.
#define ABILITY_PRISMATIC_FUR 440 // Color Change + Protean, Fur Coat + Ice Scales
#define ABILITY_SHOCKING_JAWS 441 // Biting moves have 50% chance to paralyze the target.
#define ABILITY_FAE_HUNTER 442 // Does 50% more damage to Fairy-types.
#define ABILITY_GRAVITY_WELL 443 // Sets Gravity on entry for 5 turns.
#define ABILITY_EVAPORATE 444 // Takes no damage and sets Mist if hit by water
#define ABILITY_LUMBERJACK 445 // 1.5x damage to GRASS types.
#define ABILITY_WELL_BAKED_BODY 446 // Halves damage and +2 defense  when hit by a FIRE type move.
#define ABILITY_FURNACE 447 // Upon getting hit by a rock move or switching on stealth rocks user gains +2 speed
#define ABILITY_ELECTROMORPHOSIS 448 // Charges up when getting hit.
#define ABILITY_ROCKY_PAYLOAD 449 // Powers up Rock-type moves
#define ABILITY_EARTH_EATER 450 // Changes ground into HP.
#define ABILITY_LINGERING_AROMA 451 // Spreads with contact.
#define ABILITY_FAIRY_TALE 452 // Adds fairy type
#define ABILITY_RAGING_MOTH 453 // Fire moves hits twice, both hits at %75 power.
#define ABILITY_ADRENALINE_RUSH 454 // KOs raise speed by +1.
#define ABILITY_ARCHMAGE 455 // 30% chance of adding a type related effect to each move.
#define ABILITY_CRYOMANCY 456 // Ice moves inflict frostbite 5x more often.
#define ABILITY_PHANTOM_PAIN 457 // Ghost type moves can hit normal type pokemon for neutral damage.
#define ABILITY_PURGATORY 458 // Ups GHOST moves by 30%,  80% when at 1/3 HP.
#define ABILITY_EMANATE 459 // Normal moves become PSYCHIC  and get a 10% boost.
#define ABILITY_KUNOICHI_BLADE 460 // Boost weaker moves and increases the frequency of multi-hit moves
#define ABILITY_MONKEY_BUSINESS 461 // Uses Tickle on-entry.
#define ABILITY_COMBAT_SPECIALIST 462 // Boosts punching and kicking moves by 30%.
#define ABILITY_JUNGLES_GUARD 463 // Ally Grass types and Itself are protected from status conditions and lowering stats.
#define ABILITY_HUNTERS_HORN 464 // Boost Horn moves and Heals  1/4 HP when defeating an enemy.
#define ABILITY_PIXIE_POWER 465 // Boosts Fairy moves by 33%  and 1.2x accuracy.
#define ABILITY_PLASMA_LAMP 466 // Boost accuracy and Fire & Electric type moves by 1.2x
#define ABILITY_MAGMA_EATER 467 // Predator + Molten Down.
#define ABILITY_SUPER_HOT_GOO 468 // Inflicts burn and lower the speed on contact.
#define ABILITY_NIKA 469 // Iron fist + Water moves function normally under sun.
#define ABILITY_ARCHER 470 // Boosts Arrow moves by 30%.
#define ABILITY_COLD_PLASMA 471 // Electric type moves now inflict burn instead of paralysis.
#define ABILITY_SUPER_SLAMMER 472 // Boosts Hammer and Slam moves by 30%
#define ABILITY_INVERSE_ROOM 473 // Sets up the Inverse field condition for 3 turns upon entry
#define ABILITY_ACCELERATE 474 // 2 turn based moves are now used instantly
#define ABILITY_FROST_BURN 475 // Triggers 40BP Ice Beam after using a Fire-type move.
#define ABILITY_ITCHY_DEFENSE 476 // Causes infestation when hit by a contact move.
#define ABILITY_GENERATOR 477 // Charges up on entry.
#define ABILITY_MOON_SPIRIT 478 // Fairy & Dark gains STAB. Moonlight recovers 75% HP.
#define ABILITY_DUST_CLOUD 479 // Attacks with Sand Attack on switch-in.
#define ABILITY_BERSERKER_RAGE 480 // Berserk + Rampage.
#define ABILITY_TRICKSTER 481 // Uses Disable on switch-in.
#define ABILITY_SAND_GUARD 482 // Blocks priority and reduces special damage by half in sand.
#define ABILITY_NATURAL_RECOVERY 483 // Natural Cure + Regenerator.
#define ABILITY_WIND_RIDER 484 // Increases attack in tailwind or when hit by wind move.
#define ABILITY_SOOTHING_AROMA 485 // Cures party status on entry.
#define ABILITY_PRIM_AND_PROPER 486 // Wonder Skin + Cute Charm.
#define ABILITY_SUPER_STRAIN 487 // KOs lower Attack by +1. Take 25% recoil damage.
#define ABILITY_TIPPING_POINT 488 // Critical hits maximize SpAtk. Getting hit raises SpAtk.
#define ABILITY_ENLIGHTENED 489 // Emanate + Inner Focus.
#define ABILITY_PEACEFUL_SLUMBER 490 // Sweet Dreams + Self Sufficient.
#define ABILITY_AFTERSHOCK 491 // Triggers Magnitude 4-7 after using a damaging move.
#define ABILITY_FREEZING_POINT 492 // 30% chance to get frostbitten on contact.
#define ABILITY_CRYO_PROFICIENCY 493 // Triggers hail when hit. 30% chance to frostbite on contact.
#define ABILITY_ARCANE_FORCE 494 // All moves gain STAB. Ups “supereffective” by 10%.
#define ABILITY_DOOMBRINGER 495 // Uses Doom Desire on switch-in.
#define ABILITY_WISHMAKER 496 // Uses Wish on switch-in. Three uses per battle.
#define ABILITY_YUKI_ONNA 497 // Scare + Intimidate. 10% chance to infatuate on hit.
#define ABILITY_SUPPRESS 498 // Uses Torment on entry.
#define ABILITY_REFRIGERATOR 499 // Refrigerate + Illuminate.
#define ABILITY_HEAVEN_ASUNDER 500 // Spacial Rend always crits. Ups crit level by +1.
#define ABILITY_PURIFYING_WATERS 501 // Hydration + Water Veil.
#define ABILITY_SEABORNE 502 // Drizzle + Swift Swim.
#define ABILITY_HIGH_TIDE 503 // Triggers 50 BP Surf after using a Water-type move.
#define ABILITY_CHANGE_OF_HEART 504 // Uses Heart Swap on switch-in.
#define ABILITY_MYSTIC_BLADES 505 // Keen edge moves do special damage and deal 30% more damage.
#define ABILITY_DETERMINATION 506 // Ups Special Attack by 50% if suffering.
#define ABILITY_FERTILIZE 507 // Normal moves become Grass and get a 10% boost.
#define ABILITY_PURE_LOVE 508 // Infatuates on contact. Heal 25% damage vs infatuated.
#define ABILITY_FIGHTER 509 // Ups Fighting moves by 20%, 50% when at 1/3 HP.
#define ABILITY_MYCELIUM_MIGHT 510 // Status moves ignore immunities but go last.
#define ABILITY_TELEKINETIC 511 // Uses Telekinesis on switch-in.
#define ABILITY_COMBUSTION 512 // Ups Fire moves by 50%.
#define ABILITY_PONY_POWER 513 // Keen Edge + Mystic Blades.
#define ABILITY_POWDER_BURST 514 // Uses Powder on switch-in.
#define ABILITY_RETRIEVER 515 // Retrieves item on switch-out.
#define ABILITY_MONSTER_MASH 516 // Uses Trick-or-Treat on switch-in.
#define ABILITY_TWO_STEP 517 // Triggers 50BP Revelation Dance after using a Dance move.
#define ABILITY_SPITEFUL 518 // Reduces attacker's PP on contact.
#define ABILITY_FORTITUDE 519 // Boosts SpDef +1 when hit. Maxes SpDef on crit.
#define ABILITY_DEVOURER 520 // Strong Jaw + Primal Maw.
#define ABILITY_PHANTOM_THIEF 521 // Uses 40BP Spectral Thief on switch-in.
#define ABILITY_EARLY_GRAVE 522 // Ghost moves get +1 priority. Requires full HP.
#define ABILITY_GRAPPLER 523 // Trapping moves last 6 turns. Trapping deals 1/6 HP.
#define ABILITY_BASS_BOOSTED 524 // Amplifier + Punk Rock.
#define ABILITY_FLAMING_JAWS 525 // Biting moves have 50% chance to burn the target.
#define ABILITY_MONSTER_HUNTER 526 // Does 50% more damage to Dark-types.
#define ABILITY_CROWNED_SWORD 527 // Intrepid Sword + Anger Point.
#define ABILITY_CROWNED_SHIELD 528 // Intrepid Shield + Stamina.
#define ABILITY_BERSERK_DNA 529 // Sharply ups highest attacking stat but confuses on entry.
#define ABILITY_CROWNED_KING 530 // Unnerve + Grim Neigh + Chilling Neigh.
#define ABILITY_SNAP_TRAP_WHEN_HIT 531 // Counters contact with 50BP Snap Trap.
#define ABILITY_PERMANENCE 532 // Foes can't heal.
#define ABILITY_HUBRIS 533 // KOs raise SpAtk by +1.
#define ABILITY_COSMIC_DAZE 534 // 2x damage vs confused. Enemies take 2x confusion damage.
#define ABILITY_MINDS_EYE 535 // Hits Ghost-type Pokémon. Accuracy can't be lowered.
#define ABILITY_BLOOD_PRICE 536 // Does 30% more damage but lose 10% HP when attacking.
#define ABILITY_SPIKE_ARMOR 537 // 30% chance to bleed on contact.
#define ABILITY_VOODOO_POWER 538 // 30% chance to bleed when hit by special attacks.
#define ABILITY_CHROME_COAT 539 // Reduces special damage taken by 40%, but decreases Speed by 10%.
#define ABILITY_BANSHEE 540 // Normal sound moves become Ghost and get a 20% boost.
#define ABILITY_WEB_SPINNER 541 // Uses String Shot on switch-in.
#define ABILITY_SHOWDOWN_MODE 542 // Ambush + Violent Rush.
#define ABILITY_SEED_SOWER 543 // Sets Grassy Terrain and Leech Seed when hit.
#define ABILITY_AIRBORNE 544 // Boosts own and ally's Flying moves by 30%.
#define ABILITY_PARROTING 545 // Copies sound moves used by others. Immune to sound.
#define ABILITY_BLOCK_ON_ENTRY 546 // Prevents opposing pokemon from fleeing on entry.
#define ABILITY_PURIFYING_SALT 547 // Immune to status conditions. Take half damage from Ghost.
#define ABILITY_PROTOSYNTHESIS 548 // Boosts highest stat in Sun or with Booster Energy.
#define ABILITY_QUARK_DRIVE 549 // Boosts highest stat in Electric Terrain or with Booster Energy.
#define ABILITY_WIND_POWER 550 // Charges up when hit by wind moves or Tailwind starts.
#define ABILITY_MOMENTUM_PLUS 551 // Non-contact moves use the Speed stat for damage.
#define ABILITY_SPECIAL_SPEED_FORCE 552 // Special moves use 20% of its Speed stat additionally.
#define ABILITY_GUARD_DOG 553 // Can't be forced out. Inverts Intimidate effects.
#define ABILITY_ANGER_SHELL 554 // Applies Shell Smash when reduced below half HP.
#define ABILITY_EGOIST 555 // Raises its own stats when foes raise theirs.
#define ABILITY_SUBDUE 556 // Doubles the power of stat dropping moves.
#define ABILITY_HUGE_POWER_FOR_ONE_TURN 557 // Doubles attack on first turn.
#define ABILITY_DARK_GALE_WINGS 558 // Dark moves get +1 priority. Requires full HP.
#define ABILITY_GUILT_TRIP 559 // Sharply lowers attacker's Attack and SpAtk when fainting.
#define ABILITY_WATER_GALE_WINGS 560 // Water moves get +1 priority. Requires full HP.
#define ABILITY_ZERO_TO_HERO 561 // Changes forms after switching out.
#define ABILITY_COSTAR 562 // Copies its ally's stat changes on switch-in.
#define ABILITY_COMMANDER 563 // Placeholder
#define ABILITY_EJECT_PACK_ABILITY 564 // Flees when stats are lowered.
#define ABILITY_VENGEFUL_SPIRIT 565 // Haunted Spirit + Vengeance.
#define ABILITY_CUD_CHEW 566 // Eats berries again at the end of the next turn.
#define ABILITY_ARMOR_TAIL 567 // Protects itself and ally from priority moves.
#define ABILITY_MIND_CRUSH 568 // Biting moves use SpAtk and deal 50% more damage.
#define ABILITY_SUPREME_OVERLORD 569 // Each fainted ally increases Attack and SpAtk by 10%.
#define ABILITY_ILL_WILL 570 // Deletes the PP of the move that faints this Pokemon.
#define ABILITY_FIRE_SCALES 571 // Halves special damage.
#define ABILITY_WATCH_YOUR_STEP 572 // Spreads two layers of Spikes on switch-in.
#define ABILITY_SPECIAL_VIOLENT_RUSH 573 // Boosts Speed by 50% + SpAtk by 20% on first turn.
#define ABILITY_DOUBLE_IRON_BARBS 574 // 1/6 HP damage when touched.
#define ABILITY_THERMAL_EXCHANGE 575 // Ups Attack when hit by Fire. Immune to burn.
#define ABILITY_GOOD_AS_GOLD 576 // Blocks Status moves.
#define ABILITY_SHARING_IS_CARING 577 // Stat changes are shared between all battlers.
#define ABILITY_TABLETS_OF_RUIN 578 // Lowers the Attack of other Pokemon by 25%.
#define ABILITY_SWORD_OF_RUIN 579 // Lowers the Defense of other Pokemon by 25%.
#define ABILITY_VESSEL_OF_RUIN 580 // Lowers the Special Attack of other Pokemon by 25%.
#define ABILITY_BEADS_OF_RUIN 581 // Lowers the Special Defense of other Pokemon by 25%.
#define ABILITY_PERMAFROST_CLONE 582 // Weakens “supereffective” by 25%.
#define ABILITY_GALLANTRY 583 // Gets no damage for first hit.
#define ABILITY_ORICHALCUM_PULSE 584 // Summons sunlight in battle. +33% Attack in Sun.
#define ABILITY_LEAF_GUARD_CLONE 585 // Blocks status in sunshine.
#define ABILITY_WINGED_KING 586 // Ups “supereffective” by 33%.
#define ABILITY_HADRON_ENGINE 587 // Field becomes Electric. +33% SpAtk in Electric Terrain.
#define ABILITY_IRON_SERPENT 588 // Ups “supereffective” by 33%.
#define ABILITY_WEATHER_DOUBLE_BOOST 589 // Sun boosts Water. Rain boosts Fire.
#define ABILITY_SWEEPING_EDGE_PLUS 590 // Sweeping Edge + Keen Edge.
#define ABILITY_CELESTIAL_BLESSING 591 // Recovers 1/12 of its health each turn under Misty Terrain.
#define ABILITY_MINION_CONTROL 592 // Moves hit an extra time for each healthy party member.
#define ABILITY_MOLTEN_BLADES 593 // Keen Edge + Keen Edge moves have a 20% chance to burn.
#define ABILITY_HAUNTING_FRENZY 594 // 20% chance to flinch the opponent. +1 speed on kill.
#define ABILITY_NOISE_CANCEL 595 // Protects the party from sound- based moves.
#define ABILITY_RADIO_JAM 596 // Sound-based moves inflict disable.
#define ABILITY_OLE 597 // 20% chance to evade physical moves.
#define ABILITY_MALICIOUS 598 // Lowers the foe's highest Attack and Defense stat.
#define ABILITY_DEAD_POWER 599 // 1.5x Attack boost. 20% chance to curse on contact moves.
#define ABILITY_BRAWLING_WYVERN 600 // Dragon type moves become punching moves.
#define ABILITY_MYTHICAL_ARROWS 601 // Arrow moves do special damage and deal 30% more damage.
#define ABILITY_LAWNMOWER 602 // Removes terrain on switch-in. Stat up if terrain removed.

#define ABILITIES_COUNT_CUSTOM (ABILITY_LAWNMOWER + 1)

#define ABILITIES_COUNT ABILITIES_COUNT_CUSTOM

#endif  // GUARD_CONSTANTS_ABILITIES_H
