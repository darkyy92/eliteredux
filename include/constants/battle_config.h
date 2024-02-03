#ifndef GUARD_CONSTANTS_BATTLE_CONFIG_H
#define GUARD_CONSTANTS_BATTLE_CONFIG_H

#include "constants/expansion_branches.h"

#ifndef GEN_3
    #define GEN_3 0
    #define GEN_4 1
    #define GEN_5 2
    #define GEN_6 3
    #define GEN_7 4
    #define GEN_8 5
#endif

// Mega Evolution settings
#define B_MEGA_EVO_TURN_ORDER GEN_7 // In Gen7, a Pokémon's Speed after Mega Evolution is used to determine turn order, not its Speed before.

// Calculation settings
#define B_CRIT_CHANCE               GEN_7 // Chances of a critical hit landing. See CalcCritChanceStage.
#define B_CRIT_MULTIPLIER           GEN_7 // In Gen6+, critical hits multiply damage by 1.5 instead of 2.
#define B_PARALYSIS_SPEED           GEN_7 // In Gen7+, Speed is decreased by 50% instead of 75%.
#define B_CONFUSION_SELF_DMG_CHANCE GEN_7 // In Gen7+, confusion has a 33.3% of self-damage, instead of 50%.
#define B_MULTI_HIT_CHANCE          GEN_7 // In Gen5+, multi-hit moves have different %. See Cmd_setmultihitcounter for values.
#define B_BEAT_UP_DMG               GEN_8 // In Gen5+, Beat Up uses a different formula to calculate the damage of each hit, and deals Dark-type damage.

// Exp and stat settings
#define B_EXP_CATCH                 GEN_7 // In Gen6+, Pokémon get experience from catching.
#define B_TRAINER_EXP_MULTIPLIER    GEN_7 // In Gen7+, trainer battles no longer give a 1.5 multiplier to EXP gain.
#define B_SPLIT_EXP                 GEN_7 // In Gen6+, all participating mon get full experience.
#define B_SCALED_EXP                GEN_7 // In Gen5 and Gen7+, experience is weighted by level difference.
#define B_BADGE_BOOST               GEN_7 // In Gen4+, Gym Badges no longer boost a Pokémon's stats.
#define B_MAX_LEVEL_EV_GAINS        GEN_7 // In Gen5+, Lv100 Pokémon can obtain Effort Values normally.
#define B_RECALCULATE_STATS         GEN_7 // In Gen5+, the stats of the Pokémon who participate in battle are recalculated at the end of each battle.

// Damage settings
#define B_BURN_DAMAGE               GEN_7 // In Gen7+, burn damage is 1/16th of max HP instead of 1/8th.
#define B_BINDING_DAMAGE            GEN_7 // In Gen6+, binding damage is 1/8 of max HP instead of 1/16. (With Binding Band, 1/6 and 1/8 respectively.)
#define B_PSYWAVE_DMG               GEN_7 // Psywave's damage formula. See Cmd_psywavedamageeffect.
#define B_PAYBACK_SWITCH_BOOST      GEN_7 // In Gen5+, if the opponent switches out, Payback's damage will no longer be doubled.
#define B_HIDDEN_POWER_DMG          GEN_7 // In Gen6+, Hidden Power's base power was set to always be 60. Before, it was determined by the mon's IVs.
#define B_ROUGH_SKIN_DMG            GEN_7 // In Gen4+, Rough Skin contact damage is 1/8th of max HP instead of 1/16th. This will also affect Iron Barbs.
#define B_KNOCK_OFF_DMG             GEN_8 // In Gen6+, Knock Off deals 50% more damage when knocking off an item

// Type settings
#define B_GHOSTS_ESCAPE             GEN_7 // In Gen6+, abilities like Shadow Tag or moves like Mean Look fail on Ghost-type Pokémon. They can also escape any Wild Battle.
#define B_PARALYZE_ELECTRIC         GEN_7 // In Gen6+, Electric-type Pokémon can't be paralyzed.
#define B_POWDER_GRASS              GEN_7 // In Gen6+, Grass-type Pokémon are immune to powder and spore moves.
#define B_STEEL_RESISTANCES         GEN_7 // In Gen6+, Steel-type Pokémon are no longer resistant to Dark-type and Ghost-type moves.
#define B_PRANKSTER_DARK_TYPES      GEN_7 // In Gen8+, Prankster-elevated status moves do not affect Dark type Pokémon.

// Turn count settings
#define B_BINDING_TURNS             GEN_7 // In Gen5+, binding moves last for 4-5 turns instead of 2-5 turns. (With Grip Claw, 7 and 5 turns respectively.)
#define B_UPROAR_TURNS              GEN_7 // In Gen5+, Uproar lasts for 3 turns instead of 2-5 turns.
#define B_DISABLE_TURNS             GEN_7 // Disable's turns. See Cmd_disablelastusedattack.
#define B_TAILWIND_TURNS            GEN_7 // In Gen5+, Tailwind lasts 4 turns instead of 3.
#define B_SLEEP_TURNS               GEN_7 // In Gen5+, sleep lasts for 1-3 turns instead of 2-5 turns.
#define B_TAUNT_TURNS               GEN_7 // In Gen5+, Taunt lasts 3 turns if the user acts before the target, or 4 turns if the target acted before the user. In Gen3, taunt lasts 2 turns and in Gen 4, 3-5 turns.

// Move data settings
#define B_UPDATED_MOVE_DATA         GEN_8 // Updates move data in gBattleMoves, including Power, Accuracy, PP, stat changes, targets, chances of secondary effects, etc.
#define B_PHYSICAL_SPECIAL_SPLIT    GEN_6 // In Gen3, the move's type determines if it will do physical or special damage. The split icon in the summary will reflect this.
#define B_FELL_STINGER_STAT_RAISE   GEN_7 // In Gen7+, it raises Atk by 3 stages instead of 2 if it causes the target to faint.
#define B_KINGS_SHIELD_LOWER_ATK    GEN_8 // In Gen7+, it lowers Atk by 1 stage instead of 2 of oponents that hit it.
#define B_SPEED_BUFFING_RAPID_SPIN  GEN_8 // In Gen8, Rapid Spin raises the user's Speed by 1 stage.
#define B_RECOIL_IF_MISS_DMG        GEN_7 // In Gen5+, Jump Kick and High Jump Kick will always do half of the user's max HP when missing.

// Move accuracy settings
#define B_TOXIC_NEVER_MISS          GEN_7 // In Gen6+, if Toxic is used by a Poison-type Pokémon, it will never miss.
#define B_MINIMIZE_DMG_ACC          GEN_7 // In Gen6+, moves that causes double damage to minimized Pokémon will also skip accuracy checks.
#define B_BLIZZARD_HAIL             GEN_7 // In Gen4+, Blizzard bypasses accuracy checks if it's hailing.

// Other move settings
#define B_SOUND_SUBSTITUTE          GEN_7 // In Gen6+, sound moves bypass Substitute.
#define B_INCINERATE_GEMS           GEN_7 // In Gen6+, Incinerate can destroy Gems.
#define B_PP_REDUCED_BY_SPITE       GEN_7 // In Gen4+, Spite reduces the foe's last move's PP by 4, instead of 2 to 5.
#define B_CAN_SPITE_FAIL            GEN_7 // In Gen4+, Spite can no longer fail if the foe's last move only has 1 remaining PP.
#define B_CRASH_IF_TARGET_IMMUNE    GEN_7 // In Gen4+, The user of Jump Kick or High Jump Kick will "keep going and crash" if it attacks a target that is immune to the move.
#define B_MEMENTO_FAIL              GEN_7 // In Gen4+, Memento fails if there is no target or if the target is protected or behind substitute. But not if Atk/Sp. Atk are at -6.
#define B_GLARE_GHOST               GEN_7 // In Gen4+, Glare can hit Ghost-type Pokémon normally.
#define B_SKILL_SWAP                GEN_7 // In Gen4+, Skill Swap triggers switch-in abilities after use.
#define B_BRICK_BREAK               GEN_7 // In Gen4+, you can destroy your own side's screens. In Gen 5+, screens are not removed if the target is immune.
#define B_WISH_HP_SOURCE            GEN_7 // In Gen5+, Wish heals half of the user's max HP instead of the target's.
#define B_RAMPAGE_CANCELLING        GEN_7 // In Gen5+, a failed Thrash, etc, will cancel except on its last turn.
#define B_TELEPORT_BEHAVIOR         GEN_8 // In Gen7+, starting with Pokémon LGPE, Teleport allows the user to swap out with another party member.

// Ability settings
#define B_ABILITY_WEATHER           GEN_8 // In Gen6+, ability-induced weather lasts 5 turns. Before, it lasted until the battle ended or until it was changed by a move.
#define B_GALE_WINGS                GEN_8 // In Gen7+ requires full HP to trigger.
#define B_STANCE_CHANGE_FAIL        GEN_7 // In Gen7+, Stance Change fails if the Pokémon is unable to use a move because of confusion, paralysis, etc. In Gen6, it doesn't.
#define B_SHADOW_TAG_ESCAPE         GEN_7 // In Gen4+, if both sides have a Pokémon with Shadow Tag, all battlers can escape. Before, neither side could escape this situation.
#define B_MOODY_ACC_EVASION         GEN_8 // In Gen8, Moody CANNOT raise Accuracy and Evasion anymore.
#define B_FLASH_FIRE_FROZEN         GEN_7 // In Gen5+, Flash Fire can trigger even when frozen, when it couldn't before.
#define B_SYNCHRONIZE_NATURE        GEN_8 // In Gen8, if a Pokémon with Synchronize is leading the party, it's 100% guaranteed that wild Pokémon will have the same ability, as opposed to 50% previously.
#define B_SYNCHRONIZE_TOXIC         GEN_8 // In Gen5+, if a Pokémon with Synchronize is badly poisoned, the opponent will also become badly poisoned. Previously, the opponent would become regular poisoned.
#define B_UPDATED_INTIMIDATE        GEN_8 // In Gen8, Intimidate doesn't work on opponents with the Inner Focus, Scrappy, Own Tempo or Oblivious abilities.
#define B_PARENTAL_BOND_DAMAGE      GEN_8 // In Gen7+, Parental Bond's second hit does 25% of the initial hits damage. Before, it did 50%.

// Item settings
#define B_HP_BERRIES                GEN_7 // In Gen4+, berries which restore hp activate immediately after HP drops to half. In Gen3, the effect occurs at the end of the turn.
#define B_BERRIES_INSTANT           GEN_7 // In Gen4+, most berries activate on battle start/switch-in if applicable. In Gen3, they only activate either at the move end or turn end.
#define B_X_ITEMS_BUFF              GEN_7 // In Gen7+, the X Items raise a stat by 2 stages instead of 1.
#define B_MENTAL_HERB               GEN_5 // In Gen5+, the Mental Herb cures Infatuation, Taunt, Encore, Torment, Heal Block, and Disable
#define B_TRAINERS_KNOCK_OFF_ITEMS  TRUE  // If TRUE, trainers can steal/swap your items (non-berries are restored after battle). In vanilla games trainers cannot steal items.
#define B_SOUL_DEW_BOOST            GEN_3 // In Gens3-6, Soul Dew boosts Lati@s' Sp. Atk and Sp. Def. In Gen7+ it boosts the power of their Psychic and Dragon type moves instead.
#define B_NET_BALL_MODIFIER         GEN_7 // In Gen7+, Net Ball's catch multiplier is x5 instead of x3.
#define B_DIVE_BALL_MODIFIER        GEN_7 // In Gen4+, Dive Ball's effectiveness increases by when Surfing or Fishing.
#define B_NEST_BALL_MODIFIER        GEN_7 // Nest Ball's formula varies depending on the Gen. See Cmd_handleballthrow.
#define B_REPEAT_BALL_MODIFIER      GEN_7 // In Gen7+, Repeat Ball's catch multiplier is x3.5 instead of x3.
#define B_TIMER_BALL_MODIFIER       GEN_7 // In Gen5+, Timer Ball's effectiveness increases by x0.3 per turn instead of x0.1
#define B_DUSK_BALL_MODIFIER        GEN_7 // In Gen7+, Dusk Ball's catch multiplier is x3 instead of x3.5.
#define B_QUICK_BALL_MODIFIER       GEN_7 // In Gen5+, Quick Ball's catch multiplier is x5 instead of x4.
#define B_LURE_BALL_MODIFIER        GEN_7 // In Gen7+, Lure Ball's catch multiplier is x5 instead of x3.
#define B_HEAVY_BALL_MODIFIER       GEN_7 // In Gen7+, Heavy Ball's ranges change. See Cmd_handleballthrow.
#define B_DREAM_BALL_MODIFIER       GEN_8 // In Gen8, Dream Ball's catch multiplier is x4 when the target is asleep or has the ability Comatose.
#define B_SERENE_GRACE_BOOST        GEN_7 // In Gen5+, Serene Grace boosts the added flinch chance of King's Rock and Razor Fang.
#define B_LEEK_ALWAYS_CRIT          GEN_7 // In Gen6+, if a Farfetch'd or Sirfetch'd holding a Leek use a move with increased Critical Hit ratio, it will always result in a Critical Hit.

// Flag settings
// To use the following features in scripting, replace the 0s with the flag ID you're assigning it to.
// Eg: Replace with FLAG_UNUSED_0x264 so you can use that flag to toggle the feature.
#define B_FLAG_INVERSE_BATTLE       FLAG_SYS_INVERSE_BATTLE    // If this flag is set, the battle's type effectiveness are inversed. For example, fire is super effective against water.
#define B_FLAG_FORCE_DOUBLE_WILD    0                          // If this flag is set, all land and surfing wild battles will be double battles.
#define B_SMART_WILD_AI_FLAG        FLAG_SMART_AI              // If not 0, you can set this flag in a script to enable smart wild pokemon

// Var Settings
// To use the following features in scripting, replace the 0s with the var ID you're assigning it to.
// Eg: Replace with VAR_UNUSED_0x40F7 so you can use VAR_TERRAIN for that feature.
#define VAR_TERRAIN                 0     // If this var has a value, assigning a STATUS_FIELD_xx_TERRAIN to it before battle causes the battle to start with that terrain active
#define B_VAR_WILD_AI_FLAGS         0     // If not 0, you can use this var to add to default wild AI flags. NOT usable with flags above (1 << 15)

// Terrain settings
#define B_TERRAIN_BG_CHANGE         TRUE  // If set to TRUE, terrain moves permanently change the default battle background until the effect fades.
#define B_THUNDERSTORM_TERRAIN      TRUE  // If TRUE, overworld Thunderstorm generates Rain and Electric Terrain as in Gen 8.
#define B_TERRAIN_TYPE_BOOST        GEN_8 // In Gen8, damage is boosted by 30% instead of 50%.
#define B_SECRET_POWER_EFFECT       GEN_7 // Secret Power's effects change depending on terrain and generation. See GetSecretPowerMoveEffect.
#define B_SECRET_POWER_ANIMATION    GEN_7 // Secret Power's animations change depending on terrain and generation.
#define B_NATURE_POWER_MOVES        GEN_8 // Nature Power calls different moves depending on terrain and generation. See sNaturePowerMoves.
#define B_CAMOUFLAGE_TYPES          GEN_7 // Camouflage changes the user to different types depending on terrain and generation. See sTerrainToType.

// Interface settings
#define B_ABILITY_POP_UP            TRUE  // In Gen5+, the Pokémon abilities are displayed in a pop-up, when they activate in battle.
#define B_FAST_INTRO                TRUE  // If set to TRUE, battle intro texts print at the same time as animation of a Pokémon, as opposing to waiting for the animation to end.
#define B_SHOW_TARGETS              TRUE  // If set to TRUE, all available targets, for moves hitting 2 or 3 Pokémon, will be shown before selecting a move.
#define B_SHOW_SPLIT_ICON           TRUE  // If set to TRUE, it will show an icon in the summary showing the move's category split.
#define B_HIDE_HEALTHBOX_IN_ANIMS   TRUE  // If set to TRUE, hides healthboxes during move animations.

// Catching settings
#define B_SEMI_INVULNERABLE_CATCH   GEN_7    // In Gen4+, you cannot throw a ball against a Pokemon that is in a semi-invulnerable state (dig/fly/etc)
#define B_CATCHING_CHARM_BOOST      20       // % boost in Critical Capture odds if player has the Catching Charm.
#define B_CRITICAL_CAPTURE          TRUE     // If set to TRUE, Critical Capture will be enabled.
#define B_LAST_USED_BALL            TRUE     // If TRUE, the "last used ball" feature from Gen 7 will be implemented
#define B_LAST_USED_BALL_BUTTON     R_BUTTON // If last used ball is implemented, this button (or button combo) will trigger throwing the last used ball.

// Other
#define B_DOUBLE_WILD_CHANCE                 0    // % chance of encountering two Pokémon in a Wild Encounter.
#define B_USE_FROSTBITE                      TRUE // In PLA, Frostbite replaces Freeze. Enabling this flag does the same here. Moves can still be cherry-picked to either Freeze or Frostbite. Freeze-Dry, Secret Power & Tri Attack depend on this config.
#define B_DISABLE_LEGENDARY_FROM_RANDOMIZER  TRUE // Disables Sub-Legendary, Legendary and Mythicals from the randomizer

// Animation Settings
#define B_NEW_SWORD_PARTICLE            FALSE    // If set to TRUE, it updates Swords Dance's particle.
#define B_NEW_LEECH_SEED_PARTICLE       FALSE    // If set to TRUE, it updates Leech Seed's animation particle.
#define B_NEW_HORN_ATTACK_PARTICLE      FALSE    // If set to TRUE, it updates Horn Attack's horn particle.
#define B_NEW_LEAF_PARTICLE             FALSE    // If set to TRUE, it updates leaf particle.
#define B_NEW_EMBER_PARTICLES           FALSE    // If set to TRUE, it updates Ember's fire particle.
#define B_NEW_MEAN_LOOK_PARTICLE        FALSE    // If set to TRUE, it updates Mean Look's eye particle.
#define B_NEW_TEETH_PARTICLE            FALSE    // If set to TRUE, it updates Bite/Crunch teeth particle.
#define B_NEW_HANDS_FEET_PARTICLE       FALSE    // If set to TRUE, it updates chop/kick/punch particles.
#define B_NEW_SPIKES_PARTICLE           FALSE    // If set to TRUE, it updates Spikes particle.
#define B_NEW_FLY_BUBBLE_PARTICLE       FALSE    // If set to TRUE, it updates Fly's 'bubble' particle.
#define B_NEW_CURSE_NAIL_PARTICLE       FALSE    // If set to TRUE, it updates Curse's nail.
#define B_NEW_BATON_PASS_BALL_PARTICLE  FALSE    // If set to TRUE, it updates Baton Pass' Poké Ball sprite.
#define B_NEW_MORNING_SUN_STAR_PARTICLE FALSE    // If set to TRUE, it updates Morning Sun's star particles.
#define B_NEW_IMPACT_PALETTE            FALSE    // If set to TRUE, it updates the basic 'hit' palette.
#define B_NEW_SURF_PARTICLE_PALETTE     FALSE    // If set to TRUE, it updates Surf's wave palette.

#ifdef DEBUG_BUILD
    #define B_ENABLE_DEBUG                  TRUE    // If set to TRUE, enables a debug menu to use in battles by pressing the Select button.
#else
    #define B_ENABLE_DEBUG                  FALSE    // If set to TRUE, enables a debug menu to use in battles by pressing the Select button.
#endif

#define B_PERFECT_IVS         			    TRUE    // If set to TRUE, the stat calculation makes it as if the Pokemon has perfect Ivs.
#define B_ENABLE_FIELD_POISON         	    FALSE   // If set to FALSE, your Pokemon won't get damaged when Poisoned in the overworld
#define B_USE_COUNTER_MIRROR_COAT_RIGHT     TRUE    // If set to TRUE, the AI will use Mirror coat when it predicts an Special Move and counter for Physical moves
#define B_NEUTRALIZING_GAS_WORKS_ON_INNATES TRUE    // If set to TRUE, Neutralizing Gas/Gastro Acid will disable innates
#define B_MOLD_BREAKER_WORKS_ON_INNATES     TRUE    // If set to TRUE, Mold Breaker will disable innates

// Item Restoration Settings
#define B_RESTORE_ALL_ITEMS             TRUE     // If set to TRUE, all items are restored after Trainer battles, including berries, even they were not stolen.
#define B_ALWAYS_RESTORE_ITEMS          TRUE     // If set to TRUE, stolen items (or all items if set above) will be restored after Wild battles.

#endif // GUARD_CONSTANTS_BATTLE_CONFIG_H
