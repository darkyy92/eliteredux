static const u8 sNullDescription[] = _(
    "");

static const u8 sPoundDescription[] = _(
    "Pounds the foe with\n"
    "forelegs or tail.");

static const u8 sKarateChopDescription[] = _(
    "A chopping attack with a\n"
    "high critical-hit ratio.");

static const u8 sDoubleSlapDescription[] = _(
    "Repeatedly slaps the foe\n"
    "2 to 5 times.");

static const u8 sCometPunchDescription[] = _(
    "Repeatedly punches the foe\n"
    "2 to 5 times. +1 priority.");

static const u8 sMegaPunchDescription[] = _(
    "A strong punch thrown with\n"
    "incredible power.");

static const u8 sPayDayDescription[] = _(
    "Throws coins at the foe.\n"
    "Money is recovered after.");

static const u8 sFirePunchDescription[] = _(
    "A fiery punch that may burn\n"
    "the foe.");

static const u8 sIcePunchDescription[] = _(
    "An icy punch that may\n"
    #if B_USE_FROSTBITE == TRUE
    "leave the foe with frostbite.");
    #else
        "freeze the foe.");
    #endif

static const u8 sThunderPunchDescription[] = _(
    "An electrified punch that\n"
    "may paralyze the foe.");

static const u8 sScratchDescription[] = _(
    "Scratches the foe with\n"
    "sharp claws.");

static const u8 sViseGripDescription[] = _(
    "Grips the foe with large and\n"
    "powerful pincers.");

static const u8 sGuillotineDescription[] = _( // new
    "A powerful pincer attack\n"
    "High critical ratio.");

static const u8 sRazorWindDescription[] = _(
    "A 2-turn move that strikes\n"
    "the foe on the 2nd turn.");

static const u8 sSwordsDanceDescription[] = _(
    "A fighting dance that\n"
    "sharply raises Attack.");

static const u8 sCutDescription[] = _(
    "Cuts the foe.\n"
    "Always crits.");

static const u8 sGustDescription[] = _(
    "A sudden gust of wind.\n"
    "Has +1 priority.");

static const u8 sWingAttackDescription[] = _(
    "Strikes the foe with wings\n"
    "spread wide.");

static const u8 sWhirlwindDescription[] = _(
    "Blows away the foe with\n"
    "wind and ends the battle.");

static const u8 sFlyDescription[] = _(
    "Flies up on the first turn,\n"
    "then strikes the next turn.");

static const u8 sBindDescription[] = _(
    "Binds and squeezes the foe\n"
    "for 2 to 5 turns.");

static const u8 sSlamDescription[] = _(
    "Slams the foe with a long\n"
    "tail, vine, etc.");

static const u8 sVineWhipDescription[] = _(
    "Strikes with slender vines.\n"
    "Has 30% flinch chance.");

static const u8 sStompDescription[] = _(
    "Stomps the enemy with a big\n"
    "foot. May cause flinching.");

static const u8 sDoubleKickDescription[] = _(
    "A double-kicking attack\n"
    "that strikes the foe twice.");

static const u8 sMegaKickDescription[] = _(
    "An extremely powerful kick\n"
    "with intense force.");

static const u8 sJumpKickDescription[] = _(
    "A strong jumping kick. May\n"
    "miss and hurt the kicker.");

static const u8 sRollingKickDescription[] = _(
    "A fast kick delivered from\n"
    "a rapid spin.");

static const u8 sSandAttackDescription[] = _(
    "Reduces the foe's accuracy\n"
    "by hurling sand in its face.");

static const u8 sHeadbuttDescription[] = _(
    "A ramming attack that may\n"
    "cause flinching.");

static const u8 sHornAttackDescription[] = _(
    "Jabs the foe with sharp\n"
    "horns. High crit chance.");

static const u8 sFuryAttackDescription[] = _(
    "Jabs the foe 2 to 5 times\n"
    "with sharp horns, etc.");

static const u8 sHornDrillDescription[] = _( // new
    "Ignores abilities and\n"
    "stat changes. High crit.");

static const u8 sTackleDescription[] = _(
    "Charges the foe with a full-\n"
    "body tackle.");

static const u8 sBodySlamDescription[] = _(
    "A full-body slam that may\n"
    "cause paralysis.");

static const u8 sWrapDescription[] = _(
    "Wraps and squeezes the foe\n"
    "2 to 5 times with vines, etc.");

static const u8 sTakeDownDescription[] = _(
    "A reckless charge attack\n"
    "that also hurts the user.");

static const u8 sThrashDescription[] = _(
    "A rampage of 2 to 3 turns\n"
    "that confuses the user.");

static const u8 sDoubleEdgeDescription[] = _(
    "A life-risking tackle that\n"
    "also hurts the user.");

static const u8 sTailWhipDescription[] = _(
    "Wags the tail to lower the\n"
    "foe's Defense.");

static const u8 sPoisonStingDescription[] = _(
    "Has 30% poison chance\n"
    "and +1 priority.");

static const u8 sTwineedleDescription[] = _(
    "Stingers on the forelegs\n"
    "jab the foe twice.");

static const u8 sPinMissileDescription[] = _(
    "Sharp pins are fired to\n"
    "strike 2 to 5 times.");

static const u8 sLeerDescription[] = _(
    "Frightens the foe with a\n"
    "leer to lower Defense.");

static const u8 sBiteDescription[] = _(
    "Bites with vicious fangs.\n"
    "May cause flinching.");

static const u8 sGrowlDescription[] = _(
    "Growls cutely to reduce the\n"
    "foe's Attack.");

static const u8 sRoarDescription[] = _(
    "Makes the foe flee to end\n"
    "the battle.");

static const u8 sSingDescription[] = _(
    "A soothing song lulls the\n"
    "foe into a deep slumber.");

static const u8 sSupersonicDescription[] = _(
    "Emits bizarre sound waves\n"
    "that may confuse the foe.");

static const u8 sSonicBoomDescription[] = _(
    "Launches shock waves that\n"
    "always inflict 20 HP damage.");

static const u8 sDisableDescription[] = _(
    "Psychically disables one of\n"
    "the foe's moves.");

static const u8 sAcidDescription[] = _(
    "Sprays a hide-melting acid.\n"
    "May lower Defense.");

static const u8 sEmberDescription[] = _(
    "A weak fire attack that may\n"
    "inflict a burn.");

static const u8 sFlamethrowerDescription[] = _(
    "A powerful fire attack that\n"
    "may inflict a burn.");

static const u8 sMistDescription[] = _(
    "Creates a mist that stops\n"
    "reduction of abilities.");

static const u8 sWaterGunDescription[] = _(
    "Squirts water to attack\n"
    "the foe.");

static const u8 sHydroPumpDescription[] = _(
    "Blasts water at high power\n"
    "to strike the foe.");

static const u8 sSurfDescription[] = _(
    "Creates a huge wave, then\n"
    "crashes it down on the foe.");

static const u8 sIceBeamDescription[] = _(
    "Blasts the foe with an icy\n"
    #if B_USE_FROSTBITE == TRUE
    "beam. May cause frostbite.");
    #else
        "beam that may freeze it.");
    #endif

static const u8 sBlizzardDescription[] = _(
    "Hits the foe with an icy\n"
    #if B_USE_FROSTBITE == TRUE
        "storm. May cause frostbite.");
    #else
        "storm that may freeze it.");
    #endif

static const u8 sFreezingGlareDescription[] = _(
    "Shoots psychic power from\n"
#if B_USE_FROSTBITE == TRUE
    "the eyes. May frostbite.");
#else
    "the eyes. May freeze the foe.");
#endif

static const u8 sPsybeamDescription[] = _(
    "Fires a peculiar ray that\n"
    "may confuse the foe.");

static const u8 sBubbleBeamDescription[] = _(
    "Forcefully sprays bubbles\n"
    "that may lower Speed.");

static const u8 sAuroraBeamDescription[] = _(
    "A rainbow-colored beam which\n"
    "lowers the foe's Attack 100%.");

static const u8 sHyperBeamDescription[] = _(
    "Powerful, but leaves the\n"
    "user immobile the next turn.");

static const u8 sGigaImpactDescription[] = _(
    "Powerful, but leaves the\n"
    "user immobile the next turn.");

static const u8 sPeckDescription[] = _(
    "Attacks the foe with a\n"
    "jabbing beak, etc.");

#ifdef REBALANCED_VERSION
    static const u8 sDrillPeckDescription[] = _(
        "A corkscrewing attack with\n"
        "a high critical-hit ratio.");
#else
    static const u8 sDrillPeckDescription[] = _(
        "A corkscrewing attack with\n"
        "the beak acting as a drill.");
#endif

static const u8 sSubmissionDescription[] = _(
    "A reckless body slam that\n"
    "also hurts the user.");

static const u8 sLowKickDescription[] = _(
    "A kick that inflicts more\n"
    "damage on heavier foes.");

static const u8 sCounterDescription[] = _(
    "Retaliates any physical hit\n"
    "with double the power.");

static const u8 sSeismicTossDescription[] = _(
    "Inflicts damage identical\n"
    "to the user's level.");

static const u8 sStrengthDescription[] = _(
    "A powerful slam attack.\n"
    "Lowers the user's defenses.");

static const u8 sAbsorbDescription[] = _(
    "An attack that absorbs\n"
    "half the damage inflicted.");

static const u8 sMegaDrainDescription[] = _(
    "An attack that absorbs\n"
    "half the damage inflicted.");

static const u8 sLeechSeedDescription[] = _(
    "Plants a seed on the foe to\n"
    "steal HP on every turn.");

static const u8 sGrowthDescription[] = _(
    "Forces the body to grow.\n"
    "Ups Attack and Sp. Atk.");

static const u8 sRazorLeafDescription[] = _(
    "Cuts both foes with sharp\n"
    "leaves. Always crits.");

static const u8 sSolarBeamDescription[] = _(
    "Absorbs light in one turn,\n"
    "then attacks next turn.");

static const u8 sPoisonPowderDescription[] = _(
    "Scatters a toxic powder\n"
    "that may poison the foe.");

static const u8 sStunSporeDescription[] = _(
    "Scatters a powder that may\n"
    "paralyze the foe.");

static const u8 sSleepPowderDescription[] = _(
    "Scatters a powder that may\n"
    "cause the foe to sleep.");

static const u8 sPetalDanceDescription[] = _(
    "A rampage of 2 to 3 turns\n"
    "that confuses the user.");

static const u8 sStringShotDescription[] = _(
    "Binds the foes with string\n"
    "to harshly reduce Speed.");

static const u8 sDragonRageDescription[] = _(
    "Launches shock waves that\n"
    "always inflict 40 HP damage.");

static const u8 sFireSpinDescription[] = _(
    "Traps the foe in a ring of\n"
    "fire for 2 to 5 turns.");

static const u8 sThunderShockDescription[] = _(
    "An electrical attack that\n"
    "may paralyze the foe.");

static const u8 sThunderboltDescription[] = _(
    "A strong electrical attack\n"
    "that may paralyze the foe.");

static const u8 sThunderWaveDescription[] = _(
    "A weak jolt of electricity\n"
    "that paralyzes the foe.");

static const u8 sThunderDescription[] = _(
    "A lightning attack that may\n"
    "cause paralysis.");

static const u8 sRockThrowDescription[] = _(
    "Throws small rocks to\n"
    "strike the foe.");

static const u8 sEarthquakeDescription[] = _(
    "A powerful quake, but has\n"
    "no effect on flying foes.");

static const u8 sFissureDescription[] = _( // new
    "Very powerful attack.\n"
    "Hits both foes.");

static const u8 sDigDescription[] = _(
    "Digs underground the first\n"
    "turn and strikes next turn.");

static const u8 sToxicDescription[] = _(
    "Poisons the foe with an\n"
    "intensifying toxin.");

static const u8 sConfusionDescription[] = _(
    "A psychic attack that may\n"
    "cause confusion.");

static const u8 sPsychicDescription[] = _(
    "A powerful psychic attack\n"
    "that may lower Sp. Def.");

static const u8 sHypnosisDescription[] = _(
    "A hypnotizing move that\n"
    "may induce sleep.");

static const u8 sMeditateDescription[] = _(
    "Meditates in a peaceful\n"
    "fashion to raise Attack.");

static const u8 sAgilityDescription[] = _(
    "Relaxes the body to sharply\n"
    "boost Speed.");

static const u8 sQuickAttackDescription[] = _(
    "An extremely fast attack\n"
    "that always strikes first.");

static const u8 sRageDescription[] = _(
    "Raises the user's Attack\n"
    "every time it is hit.");

static const u8 sTeleportDescription[] = _(
    "A psychic move for fleeing\n"
    "from battle instantly.");

static const u8 sNightShadeDescription[] = _(
    "Inflicts damage identical\n"
    "to the user's level.");

static const u8 sMimicDescription[] = _(
    "Copies a move used by the\n"
    "foe during one battle.");

static const u8 sScreechDescription[] = _(
    "Emits a screech to sharply\n"
    "reduce the foe's Defense.");

static const u8 sDoubleTeamDescription[] = _(
    "Creates illusory copies to\n"
    "raise evasiveness.");

static const u8 sRecoverDescription[] = _(
    "Recovers up to half the\n"
    "user's maximum HP.");

static const u8 sHardenDescription[] = _(
    "Stiffens the body's \n"
    "muscles to raise Defense.");

static const u8 sMinimizeDescription[] = _(
    "Minimizes the user's size\n"
    "to raise evasiveness.");

static const u8 sSmokescreenDescription[] = _(
    "Lowers the foe's accuracy\n"
    "using smoke, ink, etc.");

static const u8 sConfuseRayDescription[] = _(
    "A sinister ray that\n"
    "confuses the foe.");

static const u8 sWithdrawDescription[] = _(
    "Withdraws the body into its\n"
    "hard shell to raise Defense.");

static const u8 sDefenseCurlDescription[] = _(
    "Curls up to conceal weak\n"
    "spots and raise Defense.");

static const u8 sBarrierDescription[] = _(
    "Creates a barrier that\n"
    "sharply raises Defense.");

static const u8 sLightScreenDescription[] = _(
    "Creates a wall of light that\n"
    "lowers Sp. Atk damage.");

static const u8 sHazeDescription[] = _(
    "Creates a black haze that\n"
    "eliminates all stat changes.");

static const u8 sReflectDescription[] = _(
    "Creates a wall of light that\n"
    "weakens physical attacks.");

static const u8 sFocusEnergyDescription[] = _(
    "Focuses power to raise the\n"
    "critical-hit ratio.");

static const u8 sBideDescription[] = _(
    "Endures attack for 2\n"
    "turns to retaliate double.");

static const u8 sMetronomeDescription[] = _(
    "Waggles a finger to use any\n"
    "Pokémon move at random.");

static const u8 sMirrorMoveDescription[] = _(
    "Counters the foe's attack\n"
    "with the same move.");

static const u8 sSelfDestructDescription[] = _(
    "Inflicts severe damage but\n"
    "makes the user faint.");

static const u8 sEggBombDescription[] = _(
    "An egg is forcibly hurled at\n"
    "the foe.");

static const u8 sLickDescription[] = _(
    "Licks with a long tongue to\n"
    "injure. May also paralyze.");

static const u8 sSmogDescription[] = _(
    "An exhaust-gas attack\n"
    "that may also poison.");

static const u8 sSludgeDescription[] = _(
    "Sludge is hurled to inflict\n"
    "damage. May also poison.");

static const u8 sBoneClubDescription[] = _(
    "Clubs the foe with a bone.\n"
    "May cause flinching.");

static const u8 sFireBlastDescription[] = _(
    "Incinerates everything it\n"
    "strikes. May cause a burn.");

static const u8 sWaterfallDescription[] = _(
    "Charges the foe with speed\n"
    "to climb waterfalls.");

static const u8 sClampDescription[] = _(
    "Traps and squeezes the\n"
    "foe for 2 to 5 turns.");

static const u8 sSwiftDescription[] = _(
    "Sprays star-shaped rays\n"
    "that never miss.");

static const u8 sSkullBashDescription[] = _(
    "Tucks in the head, then\n"
    "attacks on the next turn.");

static const u8 sSpikeCannonDescription[] = _(
    "Launches sharp spikes that\n"
    "strike 2 to 5 times.");

static const u8 sConstrictDescription[] = _(
    "Constricts to inflict pain.\n"
    "May lower Speed.");

static const u8 sAmnesiaDescription[] = _(
    "Forgets about something\n"
    "and sharply raises Sp. Def.");

static const u8 sKinesisDescription[] = _(
    "Distracts the foe.\n"
    "May lower accuracy.");

static const u8 sSoftBoiledDescription[] = _(
    "Recovers up to half the\n"
    "user's maximum HP.");

static const u8 sHighJumpKickDescription[] = _(
    "A jumping knee kick. If it\n"
    "misses, the user is hurt.");

static const u8 sGlareDescription[] = _(
    "Intimidates and frightens\n"
    "the foe into paralysis.");

static const u8 sDreamEaterDescription[] = _(
    "Takes one half the damage\n"
    "inflicted on a sleeping foe.");

static const u8 sPoisonGasDescription[] = _(
    "Envelops the foe in a toxic\n"
    "gas that may poison.");

static const u8 sBarrageDescription[] = _(
    "Hurls round objects at the\n"
    "foe 2 to 5 times.");

static const u8 sLeechLifeDescription[] = _(
    "An attack that steals half\n"
    "the damage inflicted.");

static const u8 sLovelyKissDescription[] = _(
    "Demands a kiss with a scary\n"
    "face that induces sleep.");

static const u8 sSkyAttackDescription[] = _(
    "Searches out weak spots,\n"
    "then strikes the next turn.");

static const u8 sTransformDescription[] = _(
    "Alters the user's cells to\n"
    "become a copy of the foe.");

static const u8 sBubbleDescription[] = _(
    "An attack using bubbles.\n"
    "Always lowers foe's Speed.");

static const u8 sDizzyPunchDescription[] = _(
    "A rhythmic punch that may\n"
    "confuse the foe.");

static const u8 sSporeDescription[] = _(
    "Scatters a cloud of spores\n"
    "that always induce sleep.");

static const u8 sFlashDescription[] = _(
    "Looses a blast of light.\n"
    "50% chance to drop Atk.");

static const u8 sPsywaveDescription[] = _(
    "Quick wave of psychic energy.\n"
    "Has +1 priority.");

static const u8 sSplashDescription[] = _(
    "It's just a splash...\n"
    "Has no effect whatsoever.");

static const u8 sAcidArmorDescription[] = _(
    "Liquifies the user's body\n"
    "to sharply raise Defense.");

static const u8 sCrabhammerDescription[] = _(
    "Hammers with a pincer. Has a\n"
    "high critical-hit ratio.");

static const u8 sExplosionDescription[] = _(
    "Inflicts severe damage but\n"
    "makes the user faint.");

static const u8 sFurySwipesDescription[] = _(
    "Rakes the foe with sharp\n"
    "claws, etc., 2 to 5 times.");

#ifdef REBALANCED_VERSION
    static const u8 sBonemerangDescription[] = _(
        "Throws a bone. Hits airborne\n"
        "targets and strikes twice.");
#else
    static const u8 sBonemerangDescription[] = _(
        "Throws a bone boomerang\n"
        "that strikes twice.");
#endif

static const u8 sRestDescription[] = _(
    "The user sleeps for 2 turns,\n"
    "restoring HP and status.");

static const u8 sRockSlideDescription[] = _(
    "Large boulders are hurled.\n"
    "May cause flinching.");

static const u8 sHyperFangDescription[] = _(
    "Attacks with sharp fangs.\n"
    "May cause flinching.");

static const u8 sSharpenDescription[] = _(
    "Reduces the polygon count\n"
    "and raises Attack.");

static const u8 sConversionDescription[] = _(
    "Changes the user's type\n"
    "into a known move's type.");

static const u8 sTriAttackDescription[] = _(
    "Fires three types of beams\n"
    "at the same time.");

static const u8 sSuperFangDescription[] = _(
    "Attacks with sharp fangs\n"
    "and cuts half the foe's HP.");

static const u8 sSlashDescription[] = _(
    "Slashes with claws, etc. Has\n"
    "a high critical-hit ratio.");

static const u8 sSubstituteDescription[] = _(
    "Creates a decoy using 1/4\n"
    "of the user's maximum HP.");

static const u8 sStruggleDescription[] = _(
    "Used only if all PP are gone.\n"
    "Also hurts the user a little.");

static const u8 sSketchDescription[] = _(
    "Copies the foe's last move\n"
    "permanently.");

static const u8 sTripleKickDescription[] = _(
    "Kicks the foe 3 times in a\n"
    "row with rising intensity.");

static const u8 sThiefDescription[] = _(
    "While attacking, it may\n"
    "steal the foe's held item.");

static const u8 sSpiderWebDescription[] = _(
    "Ensnares the foe to stop it\n"
    "from fleeing or switching.");

static const u8 sMindReaderDescription[] = _(
    "Senses the foe's action to\n"
    "ensure the next move's hit.");

static const u8 sNightmareDescription[] = _(
    "Inflicts 1/4 damage on a\n"
    "sleeping foe every turn.");

static const u8 sFlameWheelDescription[] = _(
    "A fiery charge attack that\n"
    "may inflict a burn.");

static const u8 sSnoreDescription[] = _(
    "A loud attack that can be\n"
    "used only while asleep.");

static const u8 sCurseDescription[] = _(
    "A move that functions\n"
    "differently for GHOSTS.");

static const u8 sFlailDescription[] = _(
    "Inflicts more damage when\n"
    "the user's HP is down.");

static const u8 sConversion2Description[] = _(
    "Makes the user resistant\n"
    "to the last attack's type.");

static const u8 sAeroblastDescription[] = _( // new
    "Launches a vacuumed blast.\n"
    "High crit ratio.");

static const u8 sCottonSporeDescription[] = _(
    "Spores cling to the foe,\n"
    "sharply reducing Speed.");

static const u8 sReversalDescription[] = _(
    "Inflicts more damage when\n"
    "the user's HP is down.");

static const u8 sSpiteDescription[] = _(
    "Spitefully cuts the PP\n"
    "of the foe's last move.");

static const u8 sPowderSnowDescription[] = _(
    "Blasts the foe with a snowy\n"
    "gust. May cause freezing.");

static const u8 sProtectDescription[] = _(
    "Evades attack, but may fail\n"
    "if used in succession.");

static const u8 sMachPunchDescription[] = _(
    "A punch is thrown at wicked\n"
    "speed to strike first.");

static const u8 sScaryFaceDescription[] = _(
    "Frightens with a scary face\n"
    "to sharply reduce Speed.");

static const u8 sFeintAttackDescription[] = _(
    "Draws the foe close, then\n"
    "strikes without fail.");

static const u8 sSweetKissDescription[] = _(
    "Demands a kiss with a cute\n"
    "look. May cause confusion.");

static const u8 sBellyDrumDescription[] = _(
    "Maximizes Attack while\n"
    "sacrificing HP.");

static const u8 sSludgeBombDescription[] = _(
    "Sludge is hurled to inflict\n"
    "damage. May also poison.");

static const u8 sMudSlapDescription[] = _(
    "Hurls mud in the foe's face\n"
    "to reduce its accuracy.");

static const u8 sOctazookaDescription[] = _(
    "Fires a lump of ink to\n"
    "damage and cut accuracy.");

static const u8 sSpikesDescription[] = _(
    "Sets spikes that hurt a \n"
    "foe switching in.");

static const u8 sZapCannonDescription[] = _(
    "Powerful and sure to cause\n"
    "paralysis, but inaccurate.");

static const u8 sForesightDescription[] = _(
    "Negates the foe's efforts\n"
    "to heighten evasiveness.");

static const u8 sDestinyBondDescription[] = _(
    "If the user faints, the foe\n"
    "is also made to faint.");

static const u8 sPerishSongDescription[] = _(
    "Any Pokémon hearing this\n"
    "song faints in 3 turns.");

static const u8 sIcyWindDescription[] = _(
    "A chilling attack that\n"
    "lowers the foe's Speed.");

static const u8 sDetectDescription[] = _(
    "Evades attack, but may fail\n"
    "if used in succession.");

#ifdef REBALANCED_VERSION
    static const u8 sBoneRushDescription[] = _(
        "Strikes with a bone 2 to 5\n"
        "times. Always goes first.");
#else
    static const u8 sBoneRushDescription[] = _(
        "Strikes the foe with a bone\n"
        "in hand 2 to 5 times.");
#endif

static const u8 sLockOnDescription[] = _(
    "Locks on to the foe to\n"
    "ensure the next move hits.");

static const u8 sOutrageDescription[] = _(
    "A rampage of 2 to 3 turns\n"
    "that confuses the user.");

static const u8 sSandstormDescription[] = _(
    "Causes a sandstorm that\n"
    "rages for several turns.");

static const u8 sGigaDrainDescription[] = _(
    "An attack that steals half\n"
    "the damage inflicted.");

static const u8 sEndureDescription[] = _(
    "Endures any attack for\n"
    "1 turn, leaving at least 1HP.");

static const u8 sCharmDescription[] = _(
    "Charms the foe and sharply\n"
    "reduces its Attack.");

static const u8 sRolloutDescription[] = _(
    "An attack lasting 5 turns\n"
    "with rising intensity.");

static const u8 sFalseSwipeDescription[] = _(
    "An attack that leaves the\n"
    "foe with at least 1 HP.");

static const u8 sSwaggerDescription[] = _(
    "Confuses the foe, but also\n"
    "sharply raises Attack.");

static const u8 sMilkDrinkDescription[] = _(
    "Recovers up to half the\n"
    "user's maximum HP.");

static const u8 sSparkDescription[] = _(
    "An electrified tackle with\n"
    "+2 priority. May paralyze.");

static const u8 sFuryCutterDescription[] = _(
    "An attack that intensifies\n"
    "on each successive hit.");

static const u8 sSteelWingDescription[] = _(
    "Strikes the foe with hard\n"
    "wings spread wide.");

static const u8 sMeanLookDescription[] = _(
    "Fixes the foe with a mean\n"
    "look that prevents escape.");

static const u8 sAttractDescription[] = _(
    "Halves the Atk & SpAtk of\n"
    "the opposite gender.");

static const u8 sSleepTalkDescription[] = _(
    "Uses an available move\n"
    "randomly while asleep.");

static const u8 sHealBellDescription[] = _(
    "Chimes soothingly to heal\n"
    "all status abnormalities.");

static const u8 sReturnDescription[] = _(
    "A reliable and strong\n"
    "Normal-type attack.");

static const u8 sPresentDescription[] = _(
    "A gift in the form of a\n"
    "bomb. May restore HP.");

static const u8 sFrustrationDescription[] = _(
    "A reliable and strong\n"
    "Dark-type attack.");

static const u8 sSafeguardDescription[] = _(
    "A mystical force prevents\n"
    "all status problems.");

static const u8 sPainSplitDescription[] = _(
    "Adds the user and foe's HP,\n"
    "then shares them equally.");

static const u8 sSacredFireDescription[] = _(
    "A mystical fire attack that\n"
    "may inflict a burn.");

static const u8 sMagnitudeDescription[] = _(
    "A ground-shaking attack\n"
    "of random intensity.");

static const u8 sDynamicPunchDescription[] = _(
    "Powerful and sure to cause\n"
    "confusion, but inaccurate.");

static const u8 sMegahornDescription[] = _(
    "A brutal ramming attack\n"
    "using out-thrust horns.");

static const u8 sDragonBreathDescription[] = _(
    "Strikes the foe with an\n"
    "incredible blast of breath.");

static const u8 sBatonPassDescription[] = _(
    "Switches out the user while\n"
    "keeping effects in play.");

static const u8 sEncoreDescription[] = _(
    "Makes the foe repeat its\n"
    "last move over 2 to 6 turns.");

static const u8 sPursuitDescription[] = _(
    "Inflicts bad damage if used\n"
    "on a foe switching out.");

static const u8 sRapidSpinDescription[] = _(
    "Clears some hazards.\n"
    "Ups speed by +1.");

static const u8 sSweetScentDescription[] = _(
    "Allures the foe to harshly\n"
    "reduce evasiveness.");

static const u8 sIronTailDescription[] = _(
    "Attacks with a rock-hard\n"
    "tail. May lower Defense.");

static const u8 sMetalClawDescription[] = _(
    "A claw attack that may\n"
    "raise the user's Attack.");

static const u8 sVitalThrowDescription[] = _(
    "Makes the user's move last,\n"
    "but it never misses.");

static const u8 sMorningSunDescription[] = _(
    "Restores HP. The amount\n"
    "varies with the weather.");

static const u8 sSynthesisDescription[] = _(
    "Restores HP. The amount\n"
    "varies with the weather.");

static const u8 sMoonlightDescription[] = _(
    "Restores HP. The amount\n"
    "varies with the weather.");

static const u8 sHiddenPowerDescription[] = _(
    "The effectiveness varies\n"
    "with the user.");

static const u8 sCrossChopDescription[] = _(
    "A double-chopping attack.\n"
    "High critical-hit ratio.");

static const u8 sTwisterDescription[] = _(
    "Whips up a vicious twister\n"
    "to tear at the foe.");

static const u8 sRainDanceDescription[] = _(
    "Boosts the power of Water-\n"
    "type moves for 5 turns.");

static const u8 sSunnyDayDescription[] = _(
    "Boosts the power of Fire-\n"
    "type moves for 5 turns.");

static const u8 sCrunchDescription[] = _(
    "Crunches with sharp fangs.\n"
    "May lower Defense.");

static const u8 sMirrorCoatDescription[] = _(
    "Counters the foe's special\n"
    "attack at double the power.");

static const u8 sPsychUpDescription[] = _(
    "Copies the foe's effect(s)\n"
    "and gives to the user.");

static const u8 sExtremeSpeedDescription[] = _(
    "An extremely fast and\n"
    "powerful attack.");

static const u8 sAncientPowerDescription[] = _(
    "An attack that may raise\n"
    "all stats.");

static const u8 sShadowBallDescription[] = _(
    "Hurls a black blob that may\n"
    "lower the foe's Sp. Def.");

static const u8 sFutureSightDescription[] = _(
    "Heightens inner power to\n"
    "strike 2 turns later.");

#ifdef REBALANCED_VERSION
    static const u8 sRockSmashDescription[] = _(
        "A rock-crushing attack that\n"
        "lowers the foe's Defense.");
#else
    static const u8 sRockSmashDescription[] = _(
        "A rock-crushing attack\n"
        "that may lower Defense.");
#endif

static const u8 sWhirlpoolDescription[] = _(
    "Traps and hurts the foe in\n"
    "a whirlpool for 2 to 5 turns.");

static const u8 sBeatUpDescription[] = _(
    "Summons party Pokémon to\n"
    "join in the attack.");

static const u8 sFakeOutDescription[] = _(
    "A 1st-turn, 1st-strike move\n"
    "that causes flinching.");

static const u8 sUproarDescription[] = _(
    "Causes an uproar for 2 to 5\n"
    "turns and prevents sleep.");

static const u8 sStockpileDescription[] = _(
    "Charges up power for up to\n"
    "3 turns.");

static const u8 sSpitUpDescription[] = _(
    "Releases stockpiled power\n"
    "(the more the better).");

static const u8 sSwallowDescription[] = _(
    "Absorbs stockpiled power\n"
    "and restores HP.");

static const u8 sHeatWaveDescription[] = _(
    "Exhales a hot breath on the\n"
    "foe. May inflict a burn.");

static const u8 sHailDescription[] = _(
    "Summons a hailstorm that\n"
    "strikes every turn.");

static const u8 sTormentDescription[] = _(
    "Torments the foe and stops\n"
    "successive use of a move.");

static const u8 sFlatterDescription[] = _(
    "Confuses the foe, but\n"
    "raises its Sp. Atk.");

static const u8 sWillOWispDescription[] = _(
    "Inflicts a burn on the foe\n"
    "with intense fire.");

static const u8 sMementoDescription[] = _(
    "The user faints and lowers\n"
    "the foe's abilities.");

static const u8 sFacadeDescription[] = _(
    "Boosts Attack when burned,\n"
    "paralyzed, or poisoned.");

static const u8 sFocusPunchDescription[] = _(
    "A powerful loyalty attack.\n"
    "The user flinches if hit.");

static const u8 sSmellingSaltsDescription[] = _(
    "Powerful against paralyzed\n"
    "foes, but also heals them.");

static const u8 sFollowMeDescription[] = _(
    "Draws attention to make\n"
    "foes attack only the user.");

static const u8 sNaturePowerDescription[] = _(
    "The type of attack varies\n"
    "depending on the location.");

static const u8 sChargeDescription[] = _(
    "Charges power to boost the\n"
    "electric move used next.");

static const u8 sTauntDescription[] = _(
    "Taunts the foe into only\n"
    "using attack moves.");

static const u8 sHelpingHandDescription[] = _(
    "Boosts the power of the\n"
    "recipient's moves.");

static const u8 sTrickDescription[] = _(
    "Tricks the foe into trading\n"
    "held items.");

static const u8 sRolePlayDescription[] = _(
    "Mimics the target and\n"
    "copies its special ability.");

static const u8 sWishDescription[] = _(
    "A wish that restores HP.\n"
    "It takes time to work.");

static const u8 sAssistDescription[] = _(
    "Attacks randomly with one\n"
    "of the partner's moves.");

static const u8 sIngrainDescription[] = _(
    "Lays roots that restore HP.\n"
    "The user can't switch out.");

static const u8 sSuperpowerDescription[] = _(
    "Boosts strength sharply,\n"
    "but lowers abilities.");

static const u8 sMagicCoatDescription[] = _(
    "Reflects special effects\n"
    "back to the attacker.");

static const u8 sRecycleDescription[] = _(
    "Recycles a used item for\n"
    "one more use.");

static const u8 sRevengeDescription[] = _(
    "An attack that gains power\n"
    "if injured by the foe.");

static const u8 sBrickBreakDescription[] = _(
    "Destroys barriers such as\n"
    "Reflect and causes damage.");

static const u8 sYawnDescription[] = _(
    "Lulls the foe into yawning,\n"
    "then sleeping next turn.");

static const u8 sKnockOffDescription[] = _(
    "Knocks down the foe's held\n"
    "item to prevent its use.");

static const u8 sEndeavorDescription[] = _(
    "Gains power if the user's HP\n"
    "is lower than the foe's HP.");

static const u8 sEruptionDescription[] = _(
    "The higher the user's HP,\n"
    "the more damage caused.");

static const u8 sSkillSwapDescription[] = _(
    "The user swaps special\n"
    "abilities with the target.");

static const u8 sImprisonDescription[] = _(
    "Prevents foes from using\n"
    "moves known by the user.");

static const u8 sRefreshDescription[] = _(
    "Heals poisoning, paralysis,\n"
    "or a burn.");

static const u8 sGrudgeDescription[] = _(
    "If the user faints, deletes\n"
    "all PP of foe's last move.");

static const u8 sSnatchDescription[] = _(
    "Steals the effects of the\n"
    "move the target uses next.");

static const u8 sSecretPowerDescription[] = _(
    "An attack with effects\n"
    "that vary by location.");

static const u8 sDiveDescription[] = _(
    "Dives underwater the first\n"
    "turn and strikes next turn.");

static const u8 sArmThrustDescription[] = _(
    "Straight-arm punches that\n"
    "strike the foe 2 to 5 times.");

static const u8 sCamouflageDescription[] = _(
    "Alters the Pokémon's type\n"
    "depending on the location.");

static const u8 sTailGlowDescription[] = _(
    "Flashes a light that raises\n"
    "Sp. Atk by +3.");

static const u8 sLusterPurgeDescription[] = _(
    "Attacks with a burst of\n"
    "light. May lower Sp. Def.");

static const u8 sMistBallDescription[] = _(
    "Attacks with a flurry of\n"
    "down. May lower Sp. Atk.");

static const u8 sFeatherDanceDescription[] = _(
    "Envelops the foe with down\n"
    "to sharply reduce Attack.");

static const u8 sTeeterDanceDescription[] = _(
    "Confuses all Pokémon on\n"
    "the scene.");

static const u8 sBlazeKickDescription[] = _(
    "A kick with a high critical-\n"
    "hit ratio. May cause a burn.");

static const u8 sMudSportDescription[] = _(
    "Covers the user in mud to\n"
    "raise electrical resistance.");

static const u8 sIceBallDescription[] = _(
    "A 5-turn attack that gains\n"
    "power on successive hits.");

static const u8 sNeedleArmDescription[] = _(
    "Attacks with thorny arms.\n"
    "May cause flinching.");

static const u8 sSlackOffDescription[] = _(
    "Slacks off and restores\n"
    "half the maximum HP.");

static const u8 sHyperVoiceDescription[] = _(
    "A loud attack that uses\n"
    "sound waves to injure.");

static const u8 sPoisonFangDescription[] = _(
    "A sharp-fanged attack.\n"
    "May badly poison the foe.");

static const u8 sCrushClawDescription[] = _(
    "Tears at the foe with sharp\n"
    "claws. May lower Defense.");

static const u8 sBlastBurnDescription[] = _(
    "Powerful, but leaves the\n"
    "user immobile the next turn.");

static const u8 sHydroCannonDescription[] = _(
    "Powerful, but leaves the\n"
    "user immobile the next turn.");

static const u8 sMeteorMashDescription[] = _(
    "Fires a meteor-like punch.\n"
    "May raise Attack.");

static const u8 sAstonishDescription[] = _(
    "An attack that may shock\n"
    "the foe into flinching.");

static const u8 sWeatherBallDescription[] = _(
    "The move's type and power\n"
    "change with the weather.");

static const u8 sAromatherapyDescription[] = _(
    "Heals all status problems\n"
    "with a soothing scent.");

static const u8 sFakeTearsDescription[] = _(
    "Feigns crying to sharply\n"
    "lower the foe's Sp. Def.");

static const u8 sAirCutterDescription[] = _(
    "Hacks with razorlike wind.\n"
    "High critical-hit ratio.");

static const u8 sOverheatDescription[] = _(
    "Allows a full-power attack,\n"
    "but sharply lowers Sp. Atk.");

static const u8 sOdorSleuthDescription[] = _(
    "Negates the foe's efforts\n"
    "to heighten evasiveness.");

static const u8 sRockTombDescription[] = _(
    "Stops the foe from moving\n"
    "with rocks and cuts Speed.");

static const u8 sSilverWindDescription[] = _(
    "A powdery attack that may\n"
    "raise abilities.");

static const u8 sMetalSoundDescription[] = _(
    "Emits a horrible screech\n"
    "that sharply lowers Sp. Def.");

static const u8 sGrassWhistleDescription[] = _(
    "Lulls the foe into sleep\n"
    "with a pleasant melody.");

static const u8 sTickleDescription[] = _(
    "Makes the foe laugh to\n"
    "lower Attack and Defense.");

static const u8 sCosmicPowerDescription[] = _(
    "Raises Defense and Sp. Def\n"
    "with a mystic power.");

static const u8 sWaterSpoutDescription[] = _(
    "Inflicts more damage if the\n"
    "user's HP is high.");

static const u8 sSignalBeamDescription[] = _(
    "A strange beam attack that\n"
    "may confuse the foe.");

static const u8 sShadowPunchDescription[] = _(
    "An unavoidable punch that\n"
    "is thrown from shadows.");

static const u8 sExtrasensoryDescription[] = _(
    "Attacks with a peculiar\n"
    "power. May cause flinching.");

static const u8 sSkyUppercutDescription[] = _(
    "An uppercut thrown as if\n"
    "leaping into the sky.");

static const u8 sSandTombDescription[] = _(
    "Traps and hurts the foe in\n"
    "quicksand for 2 to 5 turns.");

static const u8 sSheerColdDescription[] = _( // new
    "Super effective on Water.\n"
    "20% frostbite chance.");

static const u8 sMuddyWaterDescription[] = _(
    "Attacks with muddy water.\n"
    "May lower accuracy.");

static const u8 sBulletSeedDescription[] = _(
    "Shoots 2 to 5 seeds in a row\n"
    "to strike the foe.");

static const u8 sAerialAceDescription[] = _(
    "An extremely speedy and\n"
    "unavoidable attack.");

static const u8 sIcicleSpearDescription[] = _(
    "Attacks the foe by firing\n"
    "2 to 5 icicles in a row.");

static const u8 sIronDefenseDescription[] = _(
    "Hardens the body's surface\n"
    "to sharply raise Defense.");

static const u8 sBlockDescription[] = _(
    "Blocks the foe's way to\n"
    "prevent escape.");

static const u8 sHowlDescription[] = _(
    "Howls to raise the spirit\n"
    "and boosts Attack.");

static const u8 sDragonClawDescription[] = _(
    "Slashes the foe with sharp\n"
    "claws.");

static const u8 sFrenzyPlantDescription[] = _(
    "Powerful, but leaves the\n"
    "user immobile the next turn.");

static const u8 sBulkUpDescription[] = _(
    "Bulks up the body to boost\n"
    "both Attack and Defense.");

static const u8 sBounceDescription[] = _(
    "Bounces up, then down the\n"
    "next turn. May paralyze.");

static const u8 sMudShotDescription[] = _(
    "10% Speed drop chance.\n"
    "Has +1 priority.");

static const u8 sPoisonTailDescription[] = _(
    "Has a high critical-hit\n"
    "ratio. May also poison.");

static const u8 sCovetDescription[] = _(
    "Cutely begs to obtain an\n"
    "item held by the foe.");

static const u8 sVoltTackleDescription[] = _(
    "A life-risking tackle that\n"
    "slightly hurts the user.");

static const u8 sMagicalLeafDescription[] = _(
    "Attacks with a strange leaf\n"
    "that cannot be evaded.");

static const u8 sWaterSportDescription[] = _(
    "The user becomes soaked to\n"
    "raise resistance to fire.");

static const u8 sCalmMindDescription[] = _(
    "Raises Sp. Atk and Sp. Def\n"
    "by focusing the mind.");

static const u8 sLeafBladeDescription[] = _(
    "Slashes with a sharp leaf.\n"
    "High critical-hit ratio.");

static const u8 sDragonDanceDescription[] = _(
    "A mystical dance that ups\n"
    "Attack and Speed.");

static const u8 sRockBlastDescription[] = _(
    "Hurls boulders at the foe\n"
    "2 to 5 times in a row.");

static const u8 sShockWaveDescription[] = _(
    "A fast and unavoidable\n"
    "+2 priority attack.");

static const u8 sWaterPulseDescription[] = _(
    "Attacks with ultrasonic\n"
    "waves. May confuse the foe.");

static const u8 sDoomDesireDescription[] = _(
    "Summons strong sunlight to\n"
    "attack 2 turns later.");

static const u8 sPsychoBoostDescription[] = _(
    "Allows a full-power attack,\n"
    "but sharply lowers Sp. Atk.");

static const u8 sROOSTDescription[] = _(
    "Restores the user's HP by\n"
    "half of its max HP.");

static const u8 sGRAVITYDescription[] = _(
    "Gravity is intensified\n"
    "negating levitation.");

static const u8 sMIRACLE_EYEDescription[] = _(
    "Negate evasiveness and\n"
    "Dark-type's immunities.");

static const u8 sWAKE_UP_SLAPDescription[] = _(
    "Powerful against sleeping\n"
    "foes, but also heals them.");

static const u8 sHAMMER_ARMDescription[] = _(
    "A swinging fist attack\n"
    "that also lowers Speed.");

static const u8 sGYRO_BALLDescription[] = _(
    "A high-speed spin that does\n"
    "more damage to faster foes.");

static const u8 sHEALING_WISHDescription[] = _(
    "The user faints to heal up\n"
    "the recipient.");

static const u8 sBRINEDescription[] = _(
    "Does double damage to foes\n"
    "with half HP.");

static const u8 sNATURAL_GIFTDescription[] = _(
    "The effectiveness varies\n"
    "with the held Berry.");

static const u8 sFEINTDescription[] = _(
    "An attack that hits foes\n"
    "using moves like Protect.");

static const u8 sPLUCKDescription[] = _(
    "Eats the foe's held Berry\n"
    "gaining its effect.");

static const u8 sDRACONIC_FANGSDescription[] = _(
    "Bites with draconic fangs.\n"
    "May cause flinching.");

static const u8 sTAILWINDDescription[] = _(
    "Whips up a turbulent breeze\n"
    "that raises Speed.");

static const u8 sACUPRESSUREDescription[] = _(
    "The user sharply raises\n"
    "one of its stats.");

static const u8 sMETAL_BURSTDescription[] = _(
    "Retaliates any hit with\n"
    "greater power.");

static const u8 sU_TURNDescription[] = _(
    "Does damage then switches\n"
    "out the user.");

static const u8 sCLOSE_COMBATDescription[] = _(
    "A strong attack but lowers\n"
    "the defensive stats.");

static const u8 sPAYBACKDescription[] = _(
    "An attack that gains power\n"
    "if the user moves last.");

static const u8 sASSURANCEDescription[] = _(
    "An attack that gains power\n"
    "if the foe has been hurt.");

static const u8 sEMBARGODescription[] = _(
    "Prevents the foe from\n"
    "using any items.");

static const u8 sFLINGDescription[] = _(
    "The effectiveness varies\n"
    "with the held item.");

static const u8 sPSYCHO_SHIFTDescription[] = _(
    "Transfers status problems\n"
    "to the foe.");

static const u8 sTRUMP_CARDDescription[] = _(
    "The less PP the move has\n"
    "the more damage it does.");

static const u8 sHEAL_BLOCKDescription[] = _(
    "Prevents the foe from\n"
    "recovering any HP.");

static const u8 sWRING_OUTDescription[] = _(
    "The higher the foe's HP\n"
    "the more damage caused.");

static const u8 sPOWER_TRICKDescription[] = _(
    "The user swaps its Attack\n"
    "and Defense stats.");

static const u8 sGASTRO_ACIDDescription[] = _(
    "Stomach acid suppresses\n"
    "the foe's ability.");

static const u8 sLUCKY_CHANTDescription[] = _(
    "Prevents the foe from\n"
    "landing critical hits.");

static const u8 sME_FIRSTDescription[] = _(
    "Executes the foe's attack\n"
    "with greater power.");

static const u8 sCOPYCATDescription[] = _(
    "The user mimics the last\n"
    "move used by a foe.");

static const u8 sPOWER_SWAPDescription[] = _(
    "Swaps changes to Attack\n"
    "and Sp. Atk with the foe.");

static const u8 sGUARD_SWAPDescription[] = _(
    "Swaps changes to Defense\n"
    "and Sp. Def with the foe.");

static const u8 sPUNISHMENTDescription[] = _(
    "Does more damage if the\n"
    "foe has powered up.");

static const u8 sLAST_RESORTDescription[] = _(
    "Can only be used if every\n"
    "other move has been used.");

static const u8 sWORRY_SEEDDescription[] = _(
    "Plants a seed on the foe\n"
    "giving it Insomnia.");

static const u8 sSUCKER_PUNCHDescription[] = _(
    "Strikes first if the foe\n"
    "is preparing an attack.");

static const u8 sTOXIC_SPIKESDescription[] = _(
    "Sets spikes that poison a\n"
    "foe switching in.");

static const u8 sHEART_SWAPDescription[] = _(
    "Swaps any stat changes\n"
    "with the foe.");

static const u8 sAQUA_RINGDescription[] = _(
    "Forms a veil of water\n"
    "that restores HP.");

static const u8 sMAGNET_RISEDescription[] = _(
    "The user levitates with\n"
    "electromagnetism.");

static const u8 sFLARE_BLITZDescription[] = _(
    "A charge that may burn the\n"
    "foe. Also hurts the user.");

static const u8 sFORCE_PALMDescription[] = _(
    "A shock wave attack that\n"
    "may paralyze the foe.");

static const u8 sAURA_SPHEREDescription[] = _(
    "Attacks with an aura blast\n"
    "that cannot be evaded.");

static const u8 sROCK_POLISHDescription[] = _(
    "Polishes the body to\n"
    "sharply raise Speed.");

static const u8 sPOISON_JABDescription[] = _(
    "A stabbing attack that\n"
    "may poison the foe.");

static const u8 sDARK_PULSEDescription[] = _(
    "Attacks with a horrible\n"
    "aura. May cause flinching.");

static const u8 sNIGHT_SLASHDescription[] = _(
    "Hits as soon as possible.\n"
    "High critical-hit ratio.");

static const u8 sAQUA_TAILDescription[] = _(
    "The user swings its tail\n"
    "like a wave to attack.");

static const u8 sSEED_BOMBDescription[] = _(
    "A barrage of hard seeds\n"
    "is fired at the foe.");

static const u8 sAIR_SLASHDescription[] = _(
    "Attacks with a blade of\n"
    "air. May cause flinching.");

#ifdef REBALANCED_VERSION
    static const u8 sX_SCISSORDescription[] = _(
        "Cuts like scissors.\n"
        "High critical-hit ratio.");
#else
    static const u8 sX_SCISSORDescription[] = _(
        "Slashes the foe with crossed\n"
        "scythes, claws, etc.");
#endif

static const u8 sBUG_BUZZDescription[] = _(
    "A damaging sound wave that\n"
    "may lower Sp. Def.");

static const u8 sDRAGON_PULSEDescription[] = _(
    "Generates a shock wave to\n"
    "damage the foe.");

static const u8 sDRAGON_RUSHDescription[] = _(
    "Tackles the foe with menace.\n"
    "May cause flinching.");

static const u8 sPOWER_GEMDescription[] = _(
    "Attacks with rays of light\n"
    "that sparkle like diamonds.");

static const u8 sDRAIN_PUNCHDescription[] = _(
    "A punch that absorbs over\n"
    "30% of damage inflicted.");

static const u8 sVACUUM_WAVEDescription[] = _(
    "Whirls its fists to send\n"
    "a wave that strikes first.");

static const u8 sFOCUS_BLASTDescription[] = _(
    "Attacks at full power.\n"
    "May lower Sp. Def.");

static const u8 sENERGY_BALLDescription[] = _(
    "Draws power from nature to\n"
    "attack. May lower Sp. Def.");

static const u8 sBRAVE_BIRDDescription[] = _(
    "A low altitude charge that\n"
    "also hurts the user.");

static const u8 sEARTH_POWERDescription[] = _(
    "Makes the ground erupt with\n"
    "power. May lower Sp. Def.");

static const u8 sSWITCHEROODescription[] = _(
    "Swaps items with the foe\n"
    "faster than the eye can see.");

static const u8 sNASTY_PLOTDescription[] = _(
    "Thinks bad thoughts to\n"
    "sharply boost Sp. Atk.");

static const u8 sBULLET_PUNCHDescription[] = _(
    "Punches as fast as a bul-\n"
    "let. It always hits first.");

static const u8 sICE_SHARDDescription[] = _(
    "Hurls a chunk of ice that\n"
    "always strike first.");

static const u8 sSHADOW_CLAWDescription[] = _(
    "Strikes with a shadow claw.\n"
    "High critical-hit ratio.");

static const u8 sTHUNDER_FANGDescription[] = _(
    "May cause flinching or\n"
    "leave the foe paralyzed.");

static const u8 sICE_FANGDescription[] = _(
    "May cause flinching or\n"
    "leave the foe frozen.");

static const u8 sFIRE_FANGDescription[] = _(
    "May cause flinching or\n"
    "leave the foe with a burn.");

static const u8 sSHADOW_SNEAKDescription[] = _(
    "Extends the user's shadow\n"
    "to strike first.");

static const u8 sMUD_BOMBDescription[] = _(
    "Throws a blob of mud to\n"
    "damage and cut accuracy.");

static const u8 sPSYCHO_CUTDescription[] = _(
    "Tears with psychic blades.\n"
    "High critical-hit ratio.");

static const u8 sZEN_HEADBUTTDescription[] = _(
    "Hits with a strong head-\n"
    "butt. May cause flinching.");

static const u8 sMIRROR_SHOTDescription[] = _(
    "Emits a flash of energy to\n"
    "damage and cut accuracy.");

static const u8 sFLASH_CANNONDescription[] = _(
    "Releases a blast of light\n"
    "that may lower Sp. Def.");

static const u8 sROCK_CLIMBDescription[] = _(
    "A charging attack that may\n"
    "confuse the foe.");

static const u8 sDEFOGDescription[] = _(
    "Removes obstacles and\n"
    "lowers evasion.");

static const u8 sTRICK_ROOMDescription[] = _(
	"Slower Pokémon get to move\n"
	"first for 5 turns.");

static const u8 sDRACO_METEORDescription[] = _(
    "Casts comets onto the foe.\n"
    "Harshly lowers the Sp. Atk.");

static const u8 sDISCHARGEDescription[] = _(
    "Zaps the field with electri-\n"
    "city. May cause paralysis.");

static const u8 sPOWER_WHIPDescription[] = _(
    "Violently lashes the foe\n"
    "with vines or tentacles.");

static const u8 sCROSS_POISONDescription[] = _(
    "A slash that may poison a\n"
    "foe and do critical damage.");

static const u8 sGUNK_SHOTDescription[] = _(
    "Shoots filthy garbage at\n"
    "the foe. May also poison.");

static const u8 sIRON_HEADDescription[] = _(
    "Slams the foe with a hard\n"
    "head. May cause flinching.");

static const u8 sMAGNET_BOMBDescription[] = _(
    "Launches a magnet that\n"
    "strikes without fail.");

static const u8 sSTONE_EDGEDescription[] = _(
    "Stabs the foe with stones.\n"
    "High critical-hit ratio.");

static const u8 sCAPTIVATEDescription[] = _(
    "Makes the opposite gender\n"
    "sharply reduce its Sp. Atk.");

static const u8 sSTEALTH_ROCKDescription[] = _(
    "Sets floating stones that\n"
    "hurt a foe switching in.");

static const u8 sGRASS_KNOTDescription[] = _(
    "A snare attack that does\n"
    "more damage to heavier foes.");

static const u8 sCHATTERDescription[] = _(
    "Attacks with a sound wave\n"
    "that causes confusion.");

static const u8 sJUDGMENTDescription[] = _(
    "The type varies with the\n"
    "kind of Plate held.");

static const u8 sCHARGE_BEAMDescription[] = _(
    "Fires a beam of electricity.\n"
    "Raises Sp. Atk by one stage.");

static const u8 sPRIMAL_BEAMDescription[] = _(
    "An strange beam that uses\n"
    "the user's Attack, may rise it.");

static const u8 sWOOD_HAMMERDescription[] = _(
    "Slams the body into a foe\n"
    "The user gets hurt too.");

static const u8 sAQUA_JETDescription[] = _(
    "Strikes first by dashing\n"
    "at the foe at a high speed.");

static const u8 sATTACK_ORDERDescription[] = _(
    "Underlings pummel the foe.\n"
    "High critical-hit ratio.");

static const u8 sDEFEND_ORDERDescription[] = _(
    "Raises Defense and Sp. Def\n"
    "with a living shield.");

static const u8 sHEAL_ORDERDescription[] = _(
    "The user's underlings show\n"
    "up to heal half its max HP.");

static const u8 sHEAD_SMASHDescription[] = _(
    "A life-risking headbutt that\n"
    "seriously hurts the user.");

static const u8 sDOUBLE_HITDescription[] = _(
    "Slams the foe with a tail\n"
    "etc. Strikes twice.");

static const u8 sROAR_OF_TIMEDescription[] = _(
    "Moves last, but forces\n"
    "the target to switch out.");

static const u8 sSPACIAL_RENDDescription[] = _(
    "Tears the foe, and space.\n"
    "High critical-hit ratio.");

static const u8 sMAGMA_STORMDescription[] = _(
    "Traps the foe in a vortex\n"
    "of fire for 2 to 5 turns.");

static const u8 sDARK_VOIDDescription[] = _(
    "Drags the foe into total\n"
    "darkness, inducing Sleep.");

static const u8 sSEED_FLAREDescription[] = _(
    "Generates a shock wave that\n"
    "sharply reduces Sp. Def.");

static const u8 sOMINOUS_WINDDescription[] = _(
    "A repulsive attack that may\n"
    "raise all stats.");

static const u8 sSHADOW_FORCEDescription[] = _(
    "Vanishes on the first turn\n"
    "then strikes the next turn.");

static const u8 sHONE_CLAWSDescription[] = _(
    "Sharpens its claws to raise\n"
    "Attack and Accuracy.");

static const u8 sWIDE_GUARDDescription[] = _(
    "Evades wide-ranging attacks\n"
    "for one turn.");

static const u8 sGUARD_SPLITDescription[] = _(
    "Averages changes to Defense\n"
    "and Sp. Def with the foe.");

static const u8 sPOWER_SPLITDescription[] = _(
    "Averages changes to Attack\n"
    "and Sp. Atk with the foe.");

static const u8 sWONDER_ROOMDescription[] = _(
    "Defense and Sp. Def stats\n"
    "are swapped for 5 turns.");

static const u8 sPSYSHOCKDescription[] = _(
    "Attacks with a psychic wave\n"
    "that does physical damage.");

static const u8 sTAIL_SLAPDescription[] = _(
    "Strikes the foe with its\n"
    "tail 2 to 5 times.");

static const u8 sVENOSHOCKDescription[] = _(
    "Does double damage if the\n"
    "foe is poisoned.");

static const u8 sAUTOTOMIZEDescription[] = _(
    "Sheds additional weight to\n"
    "sharply boost Speed.");

static const u8 sRAGE_POWDERDescription[] = _(
    "Scatters powder to make\n"
    "foes attack only the user.");

static const u8 sTELEKINESISDescription[] = _(
    "Makes the foe float. It is\n"
    "easier to hit for 3 turns.");

static const u8 sMAGIC_ROOMDescription[] = _(
    "Hold items lose their\n"
    "effects for 5 turns.");

static const u8 sSMACK_DOWNDescription[] = _(
    "Throws a rock to knock the\n"
    "foe down to the ground.");

static const u8 sSTORM_THROWDescription[] = _(
    "This attack always results\n"
    "in a critical hit.");

static const u8 sFLAME_BURSTDescription[] = _(
    "Also hits the foe's ally\n"
    "for 1/4 dmg. Has +1 priority.");

static const u8 sSLUDGE_WAVEDescription[] = _(
    "Swamps the foe with a wave\n"
    "of sludge. May also poison.");

static const u8 sQUIVER_DANCEDescription[] = _(
    "Dances to raise Sp. Atk\n"
    "Sp. Def and Speed.");

static const u8 sHEAVY_SLAMDescription[] = _(
    "Does more damage if the\n"
    "user outweighs the foe.");

static const u8 sSYNCHRONOISEDescription[] = _(
    "An odd shock wave that only\n"
    "damages same-type foes.");

static const u8 sELECTRO_BALLDescription[] = _(
    "Hurls an orb that does more\n"
    "damage to slower foes.");

static const u8 sSOAKDescription[] = _(
    "Sprays water at the foe\n"
    "making it Water-type.");

static const u8 sFLAME_CHARGEDescription[] = _(
    "Attacks in a cloak of\n"
    "flames. Raises Speed.");

static const u8 sCOILDescription[] = _(
    "Coils up to raise Attack\n"
    "Defense and Accuracy.");

static const u8 sLOW_SWEEPDescription[] = _(
    "Attacks the foe's legs\n"
    "lowering its Speed.");

static const u8 sACID_SPRAYDescription[] = _(
    "Sprays a hide-melting acid.\n"
    "Sharply reduces Sp. Def.");

static const u8 sFOUL_PLAYDescription[] = _(
    "The higher the foe's Attack\n"
    "the more damage caused.");

static const u8 sSIMPLE_BEAMDescription[] = _(
    "A beam that changes the\n"
    "foe's ability to Simple.");

static const u8 sENTRAINMENTDescription[] = _(
    "Makes the foe mimic the\n"
    "user, gaining its ability.");

static const u8 sAFTER_YOUDescription[] = _(
    "Helps out the foe, letting\n"
    "it move next.");

static const u8 sROUNDDescription[] = _(
    "A song that inflicts damage.\n"
    "Others can join in too.");

static const u8 sECHOED_VOICEDescription[] = _(
    "Does more damage every turn\n"
    "it is used.");

static const u8 sCHIP_AWAYDescription[] = _(
    "Strikes through the foe's\n"
    "stat changes.");

static const u8 sCLEAR_SMOGDescription[] = _(
    "Attacks with white haze that\n"
    "eliminates all stat changes.");

static const u8 sSTORED_POWERDescription[] = _(
    "The higher the user's stats\n"
    "the more damage caused.");

static const u8 sQUICK_GUARDDescription[] = _(
    "Evades priority attacks\n"
    "for one turn.");

static const u8 sALLY_SWITCHDescription[] = _(
    "The user switches places\n"
    "with its partner.");

static const u8 sSCALDDescription[] = _(
    "Shoots boiling water at the\n"
    "foe. May inflict a burn.");

static const u8 sSHELL_SMASHDescription[] = _(
    "Raises offensive stats, but\n"
    "lowers defensive stats.");

static const u8 sHEAL_PULSEDescription[] = _(
    "Recovers up to half the\n"
    "target's maximum HP.");

static const u8 sHEXDescription[] = _(
    "Does double damage if the\n"
    "foe has a status problem.");

static const u8 sSKY_DROPDescription[] = _(
    "Takes the foe into the sky\n"
    "then drops it the next turn.");

static const u8 sSHIFT_GEARDescription[] = _(
    "Rotates its gears to raise\n"
    "Attack and Speed.");

static const u8 sCIRCLE_THROWDescription[] = _(
    "Knocks the foe away to end\n"
    "the battle.");

static const u8 sINCINERATEDescription[] = _(
    "Burns up Berries and Gems\n"
    "preventing their use.");

static const u8 sQUASHDescription[] = _(
    "Suppresses the foe, making\n"
    "it move last.");

static const u8 sACROBATICSDescription[] = _(
    "Does double damage if the\n"
    "user has no item.");

static const u8 sREFLECT_TYPEDescription[] = _(
    "The user reflects the foe's\n"
    "type, copying it.");

static const u8 sRETALIATEDescription[] = _(
    "An attack that does more\n"
    "damage if an ally fainted.");

static const u8 sFINAL_GAMBITDescription[] = _(
    "The user faints to damage\n"
    "the foe equal to its HP.");

static const u8 sBESTOWDescription[] = _(
    "The user gives its held\n"
    "item to the foe.");

static const u8 sINFERNODescription[] = _(
    "Powerful and sure to inflict\n"
    "a burn, but inaccurate.");

static const u8 sWATER_PLEDGEDescription[] = _(
    "Attacks with a column of\n"
    "water. May make a rainbow.");

static const u8 sFIRE_PLEDGEDescription[] = _(
    "Attacks with a column of\n"
    "fire. May burn the grass.");

static const u8 sGRASS_PLEDGEDescription[] = _(
    "Attacks with a column of\n"
    "grass. May create a swamp.");

static const u8 sSTRUGGLE_BUGDescription[] = _(
    "Resisting, the user attacks\n"
    "the foe. Lowers Sp. Atk.");

static const u8 sBULLDOZEDescription[] = _(
    "Stomps down on the ground.\n"
    "Lowers Speed.");

static const u8 sWORK_UPDescription[] = _(
    "The user is roused.\n"
    "Ups Attack and Sp. Atk.");

static const u8 sELECTROWEBDescription[] = _(
    "Snares the foe with an\n"
    "electric net. Lowers Speed.");

static const u8 sWILD_CHARGEDescription[] = _(
    "An electrical tackle with\n"
    "10% paralyze chance.");

static const u8 sDRILL_RUNDescription[] = _(
    "Spins its body like a drill.\n"
    "High critical-hit ratio.");

static const u8 sDUAL_CHOPDescription[] = _(
    "Attacks with brutal hits\n"
    "that strike twice.");

static const u8 sHEART_STAMPDescription[] = _(
    "A sudden blow after a cute\n"
    "act. May cause flinching.");

static const u8 sRAZOR_SHELLDescription[] = _(
    "Tears at the foe with sharp\n"
    "shells. May lower Defense.");

static const u8 sLEAF_TORNADODescription[] = _(
    "Traps and hurts the foe in\n"
    "a tornado for 2 to 5 turns.");

static const u8 sSTEAMROLLERDescription[] = _(
    "Crushes the foe with its\n"
    "body. May cause flinching.");

static const u8 sCOTTON_GUARDDescription[] = _(
    "Wraps its body in cotton.\n"
    "Drastically raises Defense.");

static const u8 sNIGHT_DAZEDescription[] = _(
    "Looses a pitch-black shock\n"
    "wave. Has +1 priority.");

static const u8 sHURRICANEDescription[] = _(
    "Traps the foe in a fierce\n"
    "wind. May cause confusion.");

static const u8 sHEAD_CHARGEDescription[] = _(
    "A charge using guard hair.\n"
    "It hurts the user a little.");

static const u8 sGEAR_GRINDDescription[] = _(
    "Throws two steel gears\n"
    "that strike twice.");

static const u8 sTECHNO_BLASTDescription[] = _(
    "The type varies with the\n"
    "kind of Drive held.");

static const u8 sRELIC_SONGDescription[] = _(
    "Attacks with an ancient\n"
    "song. May induce sleep.");

static const u8 sSECRET_SWORDDescription[] = _(
    "Cuts with a long horn that\n"
    "does physical damage.");

static const u8 sGLACIATEDescription[] = _(
    "Blows very cold air at the\n"
    "foe. It lowers their Speed.");

static const u8 sBOLT_STRIKEDescription[] = _(
    "Strikes with a great amount\n"
    "of lightning. May paralyze.");

static const u8 sBLUE_FLAREDescription[] = _(
    "Engulfs the foe in a blue\n"
    "flame. May inflict a burn.");

static const u8 sFIERY_DANCEDescription[] = _(
    "Dances cloaked in flames.\n"
    "May raise Sp. Atk.");

static const u8 sFREEZE_SHOCKDescription[] = _(
    "A powerful 2-turn move that\n"
    "may paralyze the foe.");

static const u8 sICE_BURNDescription[] = _(
    "A powerful 2-turn move that\n"
    "may inflict a burn.");

static const u8 sSNARLDescription[] = _(
    "Yells and rants at the foe\n"
    "lowering its Sp. Atk.");

static const u8 sICICLE_CRASHDescription[] = _(
    "Drops large icicles on the\n"
    "foe. May cause flinching.");

static const u8 sV_CREATEDescription[] = _(
    "Very powerful, but lowers\n"
    "Defense, Sp. Def and Speed.");

static const u8 sFUSION_FLAREDescription[] = _(
    "Summons a fireball. Works\n"
    "well with a thunderbolt.");

static const u8 sFUSION_BOLTDescription[] = _(
    "Summons a thunderbolt.\n"
    "Works well with a fireball.");

static const u8 sFLYING_PRESSDescription[] = _(
    "This attack does Fighting\n"
    "and Flying-type damage.");

static const u8 sMAT_BLOCKDescription[] = _(
    "Evades damaging moves\n"
    "for one turn.");

static const u8 sBELCHDescription[] = _(
    "Lets out a loud belch.\n"
    "Must eat a Berry to use it.");

static const u8 sROTOTILLERDescription[] = _(
	"Ups the Attack and Sp. Atk\n"
	"of Grass-type Pokémon.");

static const u8 sSTICKY_WEBDescription[] = _(
    "Weaves a sticky net that\n"
    "slows foes switching in.");

static const u8 sFELL_STINGERDescription[] = _(
    "If it knocks out a foe\n"
    "the Attack stat is raised.");

static const u8 sTRICK_OR_TREATDescription[] = _(
    "Goes trick-or-treating\n"
    "making the foe Ghost-type.");

static const u8 sNOBLE_ROARDescription[] = _(
    "Intimidates the foe, to cut\n"
    "Attack and Sp. Atk.");

static const u8 sION_DELUGEDescription[] = _(
    "Electrifies Normal-type\n"
    "moves with charged atoms.");

#ifdef REBALANCED_VERSION
    static const u8 sPARABOLIC_CHARGEDescription[] = _(
        "Damages adjacent Pokémon and\n"
        "heals up by 1/4 of it.");
#else
    static const u8 sPARABOLIC_CHARGEDescription[] = _(
        "Damages adjacent Pokémon and\n"
        "heals up by 25% of it.");
#endif

static const u8 sFORESTS_CURSEDescription[] = _(
    "Puts a curse on the foe\n"
    "making the foe Grass-type.");

static const u8 sPETAL_BLIZZARDDescription[] = _(
    "Stirs up a violent storm\n"
    "of petals to attack.");

static const u8 sFREEZE_DRYDescription[] = _(
	"Super effective on Water-\n"
	"types. May cause freezing.");

static const u8 sDISARMING_VOICEDescription[] = _(
    "Lets out a charming cry\n"
    "that cannot be evaded.");

static const u8 sPARTING_SHOTDescription[] = _(
    "Lowers the foe's Attack and\n"
    "Sp. Atk, then switches out.");

static const u8 sTOPSY_TURVYDescription[] = _(
    "Swaps all stat changes that\n"
    "affect the target.");

#ifdef REBALANCED_VERSION
    static const u8 sDRAINING_KISSDescription[] = _(
        "An attack that absorbs over\n"
        "30% of damage inflicted.");
#else
    static const u8 sDRAINING_KISSDescription[] = _(
        "An attack that absorbs over\n"
        "30% of damage inflicted.");
#endif

static const u8 sOBLIVION_WINGDescription[] = _(
        "An attack that absorbs over\n"
        "75% of damage inflicted.");

static const u8 sCRAFTY_SHIELDDescription[] = _(
    "Evades status moves for\n"
    "one turn.");

static const u8 sFLOWER_SHIELDDescription[] = _(
	"Raises the Defense of\n"
	"Grass-type Pokémon.");

static const u8 sGRASSY_TERRAINDescription[] = _(
    "The ground turns to grass\n"
    "for 5 turns. Restores HP.");

static const u8 sMISTY_TERRAINDescription[] = _(
    "Covers the ground with mist\n"
    "for 5 turns. Blocks status.");

static const u8 sELECTRIFYDescription[] = _(
    "Electrifies the foe, making\n"
    "its next move Electric-type.");

static const u8 sPLAY_ROUGHDescription[] = _(
    "Plays rough with the foe.\n"
    "May lower Attack.");

static const u8 sFAIRY_WINDDescription[] = _(
    "Quick cloud of pixie dust.\n"
    "Has +1 priority.");

static const u8 sMOONBLASTDescription[] = _(
    "Attacks with the power of\n"
    "the moon. May lower Sp. Atk.");

static const u8 sBOOMBURSTDescription[] = _(
    "Attacks everything with a\n"
    "destructive sound wave.");

static const u8 sFAIRY_LOCKDescription[] = _(
    "Locks down the battlefield\n"
    "preventing escape next turn.");

static const u8 sKINGS_SHIELDDescription[] = _(
    "Evades damage, and sharply\n"
    "reduces Attack if struck.");

static const u8 sPLAY_NICEDescription[] = _(
    "Befriend the foe, lowering\n"
    "its Attack without fail.");

static const u8 sCONFIDEDescription[] = _(
    "Shares a secret with the\n"
    "foe, lowering Sp. Atk.");

static const u8 sDIAMOND_STORMDescription[] = _(
    "Whips up a storm of\n"
    "diamonds. May up Defense.");

static const u8 sSTEAM_ERUPTIONDescription[] = _(
    "Immerses the foe in heated\n"
    "steam. May inflict a burn.");

static const u8 sHYPERSPACE_HOLEDescription[] = _(
    "Uses a warp hole to attack.\n"
    "Can't be evaded.");

static const u8 sWATER_SHURIKENDescription[] = _(
    "Throws 2 to 5 stars that\n"
    "are sure to strike first.");

static const u8 sMYSTICAL_FIREDescription[] = _(
    "Breathes a special, hot\n"
    "fire. May lower Sp. Atk.");

static const u8 sSPIKY_SHIELDDescription[] = _(
    "Evades attack, and damages\n"
    "the foe if struck.");

static const u8 sAROMATIC_MISTDescription[] = _(
	"Raises the Sp. Def of a\n"
	"partner Pokémon.");

static const u8 sEERIE_IMPULSEDescription[] = _(
    "Exposes the foe to a pulse\n"
    "that sharply cuts Sp. Atk.");

static const u8 sVENOM_DRENCHDescription[] = _(
    "Lowers the Attack, Sp. Atk\n"
    "and Speed of a poisoned foe.");

static const u8 sPOWDERDescription[] = _(
    "Damages the foe if it uses\n"
    "a Fire-type move.");

static const u8 sGEOMANCYDescription[] = _(
    "Raises Sp. Atk, Sp. Def and\n"
    "Speed on the 2nd turn.");

static const u8 sMAGNETIC_FLUXDescription[] = _(
    "Boosts the defenses of\n"
    "those with Plus or Minus.");

static const u8 sHAPPY_HOURDescription[] = _(
    "Doubles the amount of\n"
    "Prize Money received.");

static const u8 sELECTRIC_TERRAINDescription[] = _(
    "Electrifies the ground for\n"
    "5 turns. Prevents sleep.");

static const u8 sDAZZLING_GLEAMDescription[] = _(
    "Damages foes by emitting\n"
    "a bright flash.");

static const u8 sCELEBRATEDescription[] = _(
    "Congratulates you on your\n"
    "special day.");

static const u8 sHOLD_HANDSDescription[] = _(
    "The user and ally hold hands\n"
    "making them happy.");

static const u8 sBABYDOLL_EYESDescription[] = _(
    "Lowers the foe's Attack\n"
    "before it can move.");

static const u8 sNUZZLEDescription[] = _(
    "Rubs its cheeks against\n"
    "the foe, paralyzing it.");

static const u8 sINFESTATIONDescription[] = _(
    "The foe is infested and\n"
    "attacked for 2 to 5 turns.");

static const u8 sPOWER_UP_PUNCHDescription[] = _(
    "A hard punch that raises\n"
    "the user's Attack.");

static const u8 sTHOUSAND_ARROWSDescription[] = _(
    "Can hit Flying foes, then\n"
    "knocks them to the ground.");

static const u8 sTHOUSAND_WAVESDescription[] = _(
    "Those hit by the wave can\n"
    "no longer escape.");

static const u8 sLANDS_WRATHDescription[] = _(
    "Gathers the energy of the\n"
    "land to attack every foe.");

static const u8 sLIGHT_OF_RUINDescription[] = _(
    "Fires a great beam of light\n"
    "that also hurts the user.");

static const u8 sORIGIN_PULSEDescription[] = _(
    "Beams of glowing blue light\n"
    "blast both foes.");

static const u8 sPRECIPICE_BLADESDescription[] = _(
    "Fearsome blades of stone\n"
    "attack both foes.");

static const u8 sLAVA_PLUMEDescription[] = _(
    "Scarlet flames torch\n"
    "everything around the user.");

static const u8 sLEAF_STORMDescription[] = _(
	"Whips up a storm of leaves.\n"
	"Harshly lowers Sp. Atk.");

static const u8 sSHORE_UPDescription[] = _(
    "Restores the user's HP.\n"
    "More HP in a sandstorm.");

static const u8 sFIRST_IMPRESSIONDescription[] = _(
    "Hits hard and first.\n"
    "Only works first turn.");

static const u8 sBANEFUL_BUNKERDescription[] = _(
    "Protects user and poisons\n"
    "foes on contact.");

static const u8 sSPIRIT_SHACKLEDescription[] = _(
    "After being hit, foes can\n"
    "no longer escape.");

static const u8 sDARKEST_LARIATDescription[] = _(
    "Swings the arms to strike\n"
    "It ignores stat changes.");

static const u8 sSPARKLING_ARIADescription[] = _(
    "Sings with bubbles. Cures\n"
    "burns on contact.");

static const u8 sICE_HAMMERDescription[] = _(
	"Swings a fist to strike.\n"
	"Lowers the user's Speed.");

static const u8 sFLORAL_HEALINGDescription[] = _(
    "Restores an ally's HP.\n"
    "Heals more on grass.");

static const u8 sHIGH_HORSEPOWERDescription[] = _(
    "Slams hard into the foe with\n"
    "its entire body.");

static const u8 sSTRENGTH_SAPDescription[] = _(
    "Saps the foe's Attack to\n"
    "heal HP, then drops Attack.");

static const u8 sSOLAR_BLADEDescription[] = _(
    "Charges first turn, then\n"
    "chops with a blade of light.");

static const u8 sLEAFAGEDescription[] = _(
    "Attacks with a flurry of\n"
    "small leaves.");

static const u8 sSPOTLIGHTDescription[] = _(
	"Makes the foe attack the\n"
	"spotlighted Pokémon.");

static const u8 sTOXIC_THREADDescription[] = _(
    "Attacks with a thread that\n"
    "poisons and drops Speed.");

static const u8 sLASER_FOCUSDescription[] = _(
    "Guarantees the next move\n"
    "will be a critical hit.");

static const u8 sGEAR_UPDescription[] = _(
    "Boosts the attacks of\n"
    "those with Plus or Minus.");

static const u8 sTHROAT_CHOPDescription[] = _(
    "Chops the throat to disable\n"
    "sound moves for 2 turns.");

static const u8 sPOLLEN_PUFFDescription[] = _(
    "Explodes on foes, but\n"
    "restores ally's HP.");

static const u8 sANCHOR_SHOTDescription[] = _(
    "Strangles the foe with a\n"
    "chain. The foe can't switch.");

static const u8 sPSYCHIC_TERRAINDescription[] = _(
    "The ground turns weird for\n"
    "5 turns. Blocks priority.");

static const u8 sLUNGEDescription[] = _(
    "Lunges at the foe to lower\n"
    "its Attack stat.");

static const u8 sFIRE_LASHDescription[] = _(
    "Whips the foe with fire\n"
    "lowering its Defense.");

static const u8 sPOWER_TRIPDescription[] = _(
    "It hits harder the more\n"
    "stat boosts the user has.");

static const u8 sBURN_UPDescription[] = _(
    "Burns out the user fully\n"
    "removing the Fire type.");

static const u8 sSPEED_SWAPDescription[] = _(
    "Swaps user's Speed with\n"
    "the target's.");

static const u8 sSMART_STRIKEDescription[] = _(
    "Hits with an accurate\n"
    "horn that never misses.");

static const u8 sPURIFYDescription[] = _(
    "Cures the foe's status\n"
    "to restore HP.");

static const u8 sREVELATION_DANCEDescription[] = _(
    "Dances with mystical power.\n"
    "Matches user's first type.");

static const u8 sCORE_ENFORCERDescription[] = _(
    "Hits with a ray that\n"
    "nullifies the foe's ability.");

static const u8 sTROP_KICKDescription[] = _(
    "An intense kick from the\n"
    "tropics. Lowers Attack.");

static const u8 sINSTRUCTDescription[] = _(
    "Orders the target to use\n"
    "its last move again.");

static const u8 sBEAK_BLASTDescription[] = _(
    "Heats up beak to attack.\n"
    "Burns foe on contact.");

static const u8 sCLANGING_SCALESDescription[] = _(
    "Makes a big noise with\n"
    "its scales. Drops Defense.");

static const u8 sDRAGON_HAMMERDescription[] = _(
    "Swings its whole body\n"
    "like a hammer to damage.");

static const u8 sBRUTAL_SWINGDescription[] = _(
    "Violently swings around\n"
    "to hurt everyone nearby.");

static const u8 sAURORA_VEILDescription[] = _(
    "Weakens all attacks, but\n"
    "only usable with hail.");

static const u8 sSHELL_TRAPDescription[] = _(
    "Sets a shell trap that\n"
    "damages on contact.");

static const u8 sFLEUR_CANNONDescription[] = _(
    "A strong ray that harshly\n"
    "lowers Sp. Attack.");

static const u8 sPSYCHIC_FANGSDescription[] = _(
    "Chomps with psychic fangs.\n"
    "Destroys any barriers.");

static const u8 sSTOMPING_TANTRUMDescription[] = _(
    "Stomps around angrily.\n"
    "Stronger after a failure.");

static const u8 sSHADOW_BONEDescription[] = _(
    "Strikes with a haunted\n"
    "bone. Might drop Defense.");

static const u8 sACCELEROCKDescription[] = _(
    "Hits with a high-speed\n"
    "rock that always goes first.");

static const u8 sLIQUIDATIONDescription[] = _(
    "Slams the foe with water.\n"
    "Can lower Defense.");

static const u8 sPRISMATIC_LASERDescription[] = _(
    "A high power laser that\n"
    "forces recharge next turn.");

static const u8 sSPECTRAL_THIEFDescription[] = _(
    "Steals the target's stat\n"
    "boosts, then attacks.");

static const u8 sSUNSTEEL_STRIKEDescription[] = _(
    "A sun-fueled strike that\n"
    "ignores abilities.");

static const u8 sMOONGEIST_BEAMDescription[] = _(
    "A moon-powered beam that\n"
    "ignores abilities.");

static const u8 sTEARFUL_LOOKDescription[] = _(
    "The user tears up, dropping\n"
    "Attack and Sp. Attack.");

static const u8 sZING_ZAPDescription[] = _(
    "An electrified impact that\n"
    "can cause flinching.");

static const u8 sNATURES_MADNESSDescription[] = _(
    "Halves the foe's HP with\n"
    "the power of nature.");

static const u8 sMULTI_ATTACKDescription[] = _(
    "An attack that changes\n"
    "with Memories.");

static const u8 sMIND_BLOWNDescription[] = _(
    "It explodes the user's head\n"
    "to damage everything around.");

static const u8 sPLASMA_FISTSDescription[] = _(
    "Hits with electrical fists.\n"
    "Normal moves become Electric.");

static const u8 sPHOTON_GEYSERDescription[] = _(
    "User's highest attack stat\n"
    "determines its category.");

static const u8 sZIPPY_ZAPDescription[] = _(
    "Electric bursts always go\n"
    "first and land a critical hit.");

static const u8 sSPLISHY_SPLASHDescription[] = _(
    "A huge electrified wave that\n"
    "may paralyze the foe.");

static const u8 sFLOATY_FALLDescription[] = _(
    "Floats in air and dives at\n"
    "angle. May cause flinching.");

static const u8 sPIKA_PAPOWDescription[] = _(
    "Pikachu's love increases its\n"
    "power. It never misses.");

static const u8 sBOUNCY_BUBBLEDescription[] = _(
    "An attack that absorbs\n"
#if B_UPDATED_MOVE_DATA >= GEN_8
    "all the damage inflicted.");
#else
    "half the damage inflicted.");
#endif

static const u8 sBUZZY_BUZZDescription[] = _(
    "Shoots a jolt of electricity\n"
    "that always paralyzes.");

static const u8 sSIZZLY_SLIDEDescription[] = _(
    "User cloaked in fire charges.\n"
    "Leaves the foe with a burn.");

static const u8 sGLITZY_GLOWDescription[] = _(
    "Telekinetic force that sets\n"
    "wall, lowering Sp. Atk damage.");

static const u8 sBADDY_BADDescription[] = _(
    "Acting badly, attacks. Sets\n"
    "wall, lowering Attack damage.");

static const u8 sSAPPY_SEEDDescription[] = _(
    "Giant stalk scatters seeds\n"
    "that drain HP every turn.");

static const u8 sFREEZY_FROSTDescription[] = _(
    "Crystal from cold haze hits.\n"
    "Eliminates all stat changes.");

static const u8 sSPARKLY_SWIRLDescription[] = _(
    "Wrap foe with whirlwind of\n"
    "scent. Heals party's status.");

static const u8 sVEEVEE_VOLLEYDescription[] = _(
    "Eevee's love increases its\n"
    "power. It never misses.");

static const u8 sDOUBLE_IRON_BASHDescription[] = _(
    "The user spins and hits with\n"
    "its arms. May cause flinch.");
    
// GEN 8
static const u8 sDYNAMAX_CANNONDescription[] = _(
    "Fires a strong beam. Deals\n"
    "2x damage to Dynamaxed foes.");
    
static const u8 sSNIPE_SHOTDescription[] = _(
    "The user ignores effects\n"
    "that draw in moves.");
    
static const u8 sJAW_LOCKDescription[] = _(
    "Prevents the user and\n"
    "the target from escaping.");
    
static const u8 sSTUFF_CHEEKSDescription[] = _(
    "Consumes the user's Berry,\n"
    "then sharply raises Def.");
    
static const u8 sNO_RETREATDescription[] = _(
    "Raises all of the user's\n"
    "stats but prevents escape.");
    
static const u8 sTAR_SHOTDescription[] = _(
    "Lowers the foe's Speed and\n"
    "makes it weak to Fire.");
    
static const u8 sMAGIC_POWDERDescription[] = _(
    "Magic powder changes the\n"
    "target into a Psychic-type.");
    
static const u8 sDRAGON_DARTSDescription[] = _(
    "The user attacks twice. No\n"
    "additional effect.");
    
static const u8 sTEATIMEDescription[] = _(
    "All Pokémon have teatime\n"
    "and eat their Berries.");
    
static const u8 sOCTOLOCKDescription[] = _(
    "Traps the foe to lower Def\n"
    "and Sp. Def fall each turn.");
    
static const u8 sBOLT_BEAKDescription[] = _(
    "Double power if the user\n"
    "moves before the target.");
    
static const u8 sFISHIOUS_RENDDescription[] = _(
    "Double power if the user\n"
    "moves before the target.");
    
static const u8 sCOURT_CHANGEDescription[] = _(
    "The user swaps effects on\n"
    "either side of the field.");
    
static const u8 sCLANGOROUS_SOULDescription[] = _(
    "The user uses some of its\n"
    "HP to raise all its stats.");
    
static const u8 sBODY_PRESSDescription[] = _(
    "Does more damage the\n"
    "higher the user's Def.");
    
static const u8 sDECORATEDescription[] = _(
    "The user sharply raises\n"
    "the target's Atk and Sp.Atk");
    
static const u8 sDRUM_BEATINGDescription[] = _(
    "Plays a drum to attack.\n"
    "The foe's Speed is lowered.");
    
static const u8 sSNAP_TRAPDescription[] = _(
    "Snares the target in a snap\n"
    "trap for four to five turns.");
    
static const u8 sPYRO_BALLDescription[] = _(
    "Launches a fiery ball at the\n"
    "target. It may cause a burn.");
    
static const u8 sBEHEMOTH_BLADEDescription[] = _(
    "Strikes as a sword. It deals\n"
    "2x damage to Dynamaxed foes.");
    
static const u8 sBEHEMOTH_BASHDescription[] = _(
    "Attacks as a sheild. Deals\n"
    "2x damage to Dynamaxed foes.");
    
static const u8 sAURA_WHEELDescription[] = _(
    "Raises Speed to attack. The\n"
    "Type is based on its form.");
    
static const u8 sBREAKING_SWIPEDescription[] = _(
    "Swings its tail to attack.\n"
    "Lowers the Atk of those hit.");
    
static const u8 sBRANCH_POKEDescription[] = _(
    "The user pokes the target\n"
    "with a pointed branch.");
    
static const u8 sOVERDRIVEDescription[] = _(
    "The user twangs its guitar,\n"
    "causing strong vibrations.");
    
static const u8 sAPPLE_ACIDDescription[] = _(
    "Attacks with tart apple acid\n"
    "to lower the foe's Sp. Def.");
    
static const u8 sGRAV_APPLEDescription[] = _(
    "Drops an apple from above.\n"
    "Lowers the foe's Defense.");
    
static const u8 sSPIRIT_BREAKDescription[] = _(
    "Attacks with spirit-breaking\n"
    "force. Lowers Sp. Atk.");
    
static const u8 sSTRANGE_STEAMDescription[] = _(
    "Emits a strange steam to\n"
    "potentially confuse the foe.");
    
static const u8 sLIFE_DEWDescription[] = _(
    "Scatters water to restore\n"
    "the HP of itself and allies.");
    
static const u8 sOBSTRUCTDescription[] = _(
    "Protects itself, harshly\n"
    "lowering Def on contact.");
    
static const u8 sFALSE_SURRENDERDescription[] = _(
    "Bows to stab the foe\n"
    "with hair. It never misses.");
    
static const u8 sMETEOR_ASSAULTDescription[] = _(
    "Attacks with a thick leek.\n"
    "The user must then rest.");
    
static const u8 sETERNABEAMDescription[] = _(
    "Eternatus' strongest move.\n"
    "The user rests next turn.");
    
static const u8 sSTEEL_BEAMDescription[] = _(
    "Fires a beam of steel from\n"
    "its body. It hurts the user.");

static const u8 sEXPANDING_FORCEDescription[] = _(
    "Power goes up and damages\n"
    "all foes on Psychic Terrain.");

static const u8 sSTEEL_ROLLERDescription[] = _(
    "Destroys terrain. Fails if\n"
    "ground isn't terrain.");

static const u8 sSCALE_SHOTDescription[] = _(
    "Shoots scales 2 to 5 times.\n"
    "Ups Speed, lowers defense.");

static const u8 sMETEOR_BEAMDescription[] = _(
    "A 2-turn move that raises\n"
    "Sp. Attack before attacking.");

static const u8 sSHELL_SIDE_ARMDescription[] = _(
    "Deals better of physical and\n"
    "special damage. May poison.");

static const u8 sMISTY_EXPLOSIONDescription[] = _(
    "Hit everything and faint.\n"
    "Powers up on Misty Terrain.");

static const u8 sGRASSY_GLIDEDescription[] = _(
    "Gliding on ground, hits. Goes\n"
    "first on Grassy Terrain.");

static const u8 sRISING_VOLTAGEDescription[] = _(
    "This move's power doubles\n"
    "when on Electric Terrain.");

static const u8 sTERRAIN_PULSEDescription[] = _(
    "Type and power changes\n"
    "depending on the terrain.");

static const u8 sSKITTER_SMACKDescription[] = _(
    "User skitters behind foe to\n"
    "attack. Lowers foe's Sp. Atk.");

static const u8 sBURNING_JEALOUSYDescription[] = _(
    "Attacks both foes with a\n"
    "50% chance to burn them.");

static const u8 sLASH_OUTDescription[] = _(
    "If stats lowered during this\n"
    "turn, power is doubled.");

static const u8 sPOLTERGEISTDescription[] = _(
    "Control foe's item to attack.\n"
    "Fails if foe has no item.");

static const u8 sCORROSIVE_GASDescription[] = _(
    "Highly acidic gas melts items\n"
    "held by surrounding Pokémon.");

static const u8 sCOACHINGDescription[] = _(
    "Properly coaches allies to\n"
    "up their Attack and Defense.");

static const u8 sFLIP_TURNDescription[] = _(
    "Attacks and rushes back to\n"
    "switch with a party Pokémon.");

static const u8 sTRIPLE_AXELDescription[] = _(
    "A 3-kick attack that gets\n"
    "more powerful with each hit.");

static const u8 sDUAL_WINGBEATDescription[] = _(
    "User slams the target with\n"
    "wings and hits twice in a row.");

static const u8 sSCORCHING_SANDSDescription[] = _(
    "Throws scorching sand at\n"
    "the target. May leave a burn.");

static const u8 sJUNGLE_HEALINGDescription[] = _(
    "Heals HP and status of\n"
    "itself and allies in battle.");

static const u8 sWICKED_BLOWDescription[] = _(
    "Mastering the Dark style,\n"
    "strikes with a critical hit.");

static const u8 sSURGING_STRIKESDescription[] = _(
    "Mastering the Water style,\n"
    "strikes with 3 critical hits.");

static const u8 sTHUNDER_CAGEDescription[] = _(
    "Traps the foe in a cage of\n"
    "electricity for 2 to 5 turns.");

static const u8 sDRAGON_ENERGYDescription[] = _(
    "The higher the user's HP\n"
    "the more damage caused.");

static const u8 sFREEZING_GLAREDescription[] = _(
    "Shoots psychic power from\n"
    "the eyes. May frostbite the foe.");

static const u8 sFIERY_WRATHDescription[] = _(
    "An attack fueled by your\n"
    "wrath. May cause flinching.");

static const u8 sTHUNDEROUS_KICKDescription[] = _(
    "Uses a lightning-like kick\n"
    "to hit. Lowers foe's Defense.");

static const u8 sGLACIAL_LANCEDescription[] = _(
    "Strikes by hurling a blizzard-\n"
    "cloaked icicle lance at a foe.");

static const u8 sASTRAL_BARRAGEDescription[] = _(
    "Strikes by sending a frightful\n"
    "amount of ghosts at a foe.");

static const u8 sEERIE_SPELLDescription[] = _(
    "Attacks with psychic power.\n"
    "Foe's last move has 3 PP cut.");

// Darky's Custom Moves
static const u8 sDEATHROLLDescription[] = _(
    "Does a deadly roll in water.\n"
    "Ignores target's stat changes.");

static const u8 sEXCALIBURDescription[] = _(
	"Double damage on Dragon-\n"
	"types. High critical ratio.");

static const u8 sAQUA_FANGDescription[] = _(
    "Has 10% flinch chance.\n"
    "Strong Jaw boost.");

static const u8 sWAVE_CRASHDescription[] = _(
    "A life-risking tackle that\n"
    "with 33% recoil damage.");

static const u8 sSMITEDescription[] = _(
    "Attacks from above with strong\n"
    "electricity. Smack Down effect.");

static const u8 sOUTBURSTDescription[] = _(
    "Severe special damage but\n"
    "makes the user faint.");

static const u8 sIRON_FANGSDescription[] = _(
    "Chomps with hard fangs.\n"
    "Destroys any barriers.");

static const u8 sLOVELY_BITEDescription[] = _(
    "Bites the foe with love.\n"
    "10% chance to infatuate.");

static const u8 sSHADOW_FANGSDescription[] = _(
    "A bone-chilling bite.\n"
    "10% curse chance.");

static const u8 sJAGGED_FANGSDescription[] = _(
    "Bites aggressively.\n"
    "10% chance to up Atk.");

static const u8 sSCORCHED_EARTHDescription[] = _(
    "Precisely burns the ground\n"
    "under the foe. May burn.");

static const u8 sSEISMIC_FISTDescription[] = _(
    "A ground-breaking punch.\n"
    "20% chance to drop Def.");

static const u8 sRAGINGFURYDescription[] = _(
    "A rampage of 2 to 3 turns\n"
    "that confuses the user.");

static const u8 sPLASMAPULSEDescription[] = _(
    "Double damage to foes\n"
    "with status problems.");

static const u8 sPIXIE_BEAMDescription[] = _(
    "A powerfull magic beam\n"
    "30% chance to drop user SpAtk.");

static const u8 sPIXIE_SLASHDescription[] = _(
    "The foe is slashed with a\n"
    "whimsical blade. High Crit ratio.");

static const u8 sARCHER_SHOTDescription[] = _(
    "Shoots a dead center arrow at the\n"
    "target. Archer boost.");

static const u8 sFROST_BRANDDescription[] = _(
    "The foe is slashed with an icy blade.\n"
    "10% chance to inflict frostbite.");

static const u8 sSEISMIC_BLADEDescription[] = _(
    "The foe is slashed with a\n"
    "tectonic blade. High Crit ratio.");

static const u8 sMOUNTAIN_CHUNKDescription[] =_(
    "Hurls a chunk of a mountain\n"
    "at the opponent. Can Flinch.");

static const u8 sNotDoneYetDescription[] = _(
    "Not done yet.");

// MOVE_NONE is ignored in this table. Make sure to always subtract 1 before getting the right pointer.
const u8 *const gMoveDescriptionPointers[MOVES_COUNT - 1] =
{
    [MOVE_POUND - 1] = sPoundDescription,
    [MOVE_KARATE_CHOP - 1] = sKarateChopDescription,
    [MOVE_DOUBLE_SLAP - 1] = sDoubleSlapDescription,
    [MOVE_COMET_PUNCH - 1] = sCometPunchDescription,
    [MOVE_MEGA_PUNCH - 1] = sMegaPunchDescription,
    [MOVE_PAY_DAY - 1] = sPayDayDescription,
    [MOVE_FIRE_PUNCH - 1] = sFirePunchDescription,
    [MOVE_ICE_PUNCH - 1] = sIcePunchDescription,
    [MOVE_THUNDER_PUNCH - 1] = sThunderPunchDescription,
    [MOVE_SCRATCH - 1] = sScratchDescription,
    [MOVE_VISE_GRIP - 1] = sViseGripDescription,
    [MOVE_GUILLOTINE - 1] = sGuillotineDescription,
    [MOVE_RAZOR_WIND - 1] = sRazorWindDescription,
    [MOVE_SWORDS_DANCE - 1] = sSwordsDanceDescription,
    [MOVE_CUT - 1] = sCutDescription,
    [MOVE_GUST - 1] = sGustDescription,
    [MOVE_WING_ATTACK - 1] = sWingAttackDescription,
    [MOVE_WHIRLWIND - 1] = sWhirlwindDescription,
    [MOVE_FLY - 1] = sFlyDescription,
    [MOVE_BIND - 1] = sBindDescription,
    [MOVE_SLAM - 1] = sSlamDescription,
    [MOVE_VINE_WHIP - 1] = sVineWhipDescription,
    [MOVE_STOMP - 1] = sStompDescription,
    [MOVE_DOUBLE_KICK - 1] = sDoubleKickDescription,
    [MOVE_MEGA_KICK - 1] = sMegaKickDescription,
    [MOVE_JUMP_KICK - 1] = sJumpKickDescription,
    [MOVE_ROLLING_KICK - 1] = sRollingKickDescription,
    [MOVE_SAND_ATTACK - 1] = sSandAttackDescription,
    [MOVE_HEADBUTT - 1] = sHeadbuttDescription,
    [MOVE_HORN_ATTACK - 1] = sHornAttackDescription,
    [MOVE_FURY_ATTACK - 1] = sFuryAttackDescription,
    [MOVE_HORN_DRILL - 1] = sHornDrillDescription,
    [MOVE_TACKLE - 1] = sTackleDescription,
    [MOVE_BODY_SLAM - 1] = sBodySlamDescription,
    [MOVE_WRAP - 1] = sWrapDescription,
    [MOVE_TAKE_DOWN - 1] = sTakeDownDescription,
    [MOVE_THRASH - 1] = sThrashDescription,
    [MOVE_DOUBLE_EDGE - 1] = sDoubleEdgeDescription,
    [MOVE_TAIL_WHIP - 1] = sTailWhipDescription,
    [MOVE_POISON_STING - 1] = sPoisonStingDescription,
    [MOVE_TWINEEDLE - 1] = sTwineedleDescription,
    [MOVE_PIN_MISSILE - 1] = sPinMissileDescription,
    [MOVE_LEER - 1] = sLeerDescription,
    [MOVE_BITE - 1] = sBiteDescription,
    [MOVE_GROWL - 1] = sGrowlDescription,
    [MOVE_ROAR - 1] = sRoarDescription,
    [MOVE_SING - 1] = sSingDescription,
    [MOVE_SUPERSONIC - 1] = sSupersonicDescription,
    [MOVE_SONIC_BOOM - 1] = sSonicBoomDescription,
    [MOVE_DISABLE - 1] = sDisableDescription,
    [MOVE_ACID - 1] = sAcidDescription,
    [MOVE_EMBER - 1] = sEmberDescription,
    [MOVE_FLAMETHROWER - 1] = sFlamethrowerDescription,
    [MOVE_MIST - 1] = sMistDescription,
    [MOVE_WATER_GUN - 1] = sWaterGunDescription,
    [MOVE_HYDRO_PUMP - 1] = sHydroPumpDescription,
    [MOVE_SURF - 1] = sSurfDescription,
    [MOVE_ICE_BEAM - 1] = sIceBeamDescription,
    [MOVE_BLIZZARD - 1] = sBlizzardDescription,
    [MOVE_PSYBEAM - 1] = sPsybeamDescription,
    [MOVE_BUBBLE_BEAM - 1] = sBubbleBeamDescription,
    [MOVE_AURORA_BEAM - 1] = sAuroraBeamDescription,
    [MOVE_HYPER_BEAM - 1] = sHyperBeamDescription,
    [MOVE_PECK - 1] = sPeckDescription,
    [MOVE_DRILL_PECK - 1] = sDrillPeckDescription,
    [MOVE_SUBMISSION - 1] = sSubmissionDescription,
    [MOVE_LOW_KICK - 1] = sLowKickDescription,
    [MOVE_COUNTER - 1] = sCounterDescription,
    [MOVE_SEISMIC_TOSS - 1] = sSeismicTossDescription,
    [MOVE_STRENGTH - 1] = sStrengthDescription,
    [MOVE_ABSORB - 1] = sAbsorbDescription,
    [MOVE_MEGA_DRAIN - 1] = sMegaDrainDescription,
    [MOVE_LEECH_SEED - 1] = sLeechSeedDescription,
    [MOVE_GROWTH - 1] = sGrowthDescription,
    [MOVE_RAZOR_LEAF - 1] = sRazorLeafDescription,
    [MOVE_SOLAR_BEAM - 1] = sSolarBeamDescription,
    [MOVE_POISON_POWDER - 1] = sPoisonPowderDescription,
    [MOVE_STUN_SPORE - 1] = sStunSporeDescription,
    [MOVE_SLEEP_POWDER - 1] = sSleepPowderDescription,
    [MOVE_PETAL_DANCE - 1] = sPetalDanceDescription,
    [MOVE_STRING_SHOT - 1] = sStringShotDescription,
    [MOVE_DRAGON_RAGE - 1] = sDragonRageDescription,
    [MOVE_FIRE_SPIN - 1] = sFireSpinDescription,
    [MOVE_THUNDER_SHOCK - 1] = sThunderShockDescription,
    [MOVE_THUNDERBOLT - 1] = sThunderboltDescription,
    [MOVE_THUNDER_WAVE - 1] = sThunderWaveDescription,
    [MOVE_THUNDER - 1] = sThunderDescription,
    [MOVE_ROCK_THROW - 1] = sRockThrowDescription,
    [MOVE_EARTHQUAKE - 1] = sEarthquakeDescription,
    [MOVE_FISSURE - 1] = sFissureDescription,
    [MOVE_DIG - 1] = sDigDescription,
    [MOVE_TOXIC - 1] = sToxicDescription,
    [MOVE_CONFUSION - 1] = sConfusionDescription,
    [MOVE_PSYCHIC - 1] = sPsychicDescription,
    [MOVE_HYPNOSIS - 1] = sHypnosisDescription,
    [MOVE_MEDITATE - 1] = sMeditateDescription,
    [MOVE_AGILITY - 1] = sAgilityDescription,
    [MOVE_QUICK_ATTACK - 1] = sQuickAttackDescription,
    [MOVE_RAGE - 1] = sRageDescription,
    [MOVE_TELEPORT - 1] = sTeleportDescription,
    [MOVE_NIGHT_SHADE - 1] = sNightShadeDescription,
    [MOVE_MIMIC - 1] = sMimicDescription,
    [MOVE_SCREECH - 1] = sScreechDescription,
    [MOVE_DOUBLE_TEAM - 1] = sDoubleTeamDescription,
    [MOVE_RECOVER - 1] = sRecoverDescription,
    [MOVE_HARDEN - 1] = sHardenDescription,
    [MOVE_MINIMIZE - 1] = sMinimizeDescription,
    [MOVE_SMOKESCREEN - 1] = sSmokescreenDescription,
    [MOVE_CONFUSE_RAY - 1] = sConfuseRayDescription,
    [MOVE_WITHDRAW - 1] = sWithdrawDescription,
    [MOVE_DEFENSE_CURL - 1] = sDefenseCurlDescription,
    [MOVE_BARRIER - 1] = sBarrierDescription,
    [MOVE_LIGHT_SCREEN - 1] = sLightScreenDescription,
    [MOVE_HAZE - 1] = sHazeDescription,
    [MOVE_REFLECT - 1] = sReflectDescription,
    [MOVE_FOCUS_ENERGY - 1] = sFocusEnergyDescription,
    [MOVE_BIDE - 1] = sBideDescription,
    [MOVE_METRONOME - 1] = sMetronomeDescription,
    [MOVE_MIRROR_MOVE - 1] = sMirrorMoveDescription,
    [MOVE_SELF_DESTRUCT - 1] = sSelfDestructDescription,
    [MOVE_EGG_BOMB - 1] = sEggBombDescription,
    [MOVE_LICK - 1] = sLickDescription,
    [MOVE_SMOG - 1] = sSmogDescription,
    [MOVE_SLUDGE - 1] = sSludgeDescription,
    [MOVE_BONE_CLUB - 1] = sBoneClubDescription,
    [MOVE_FIRE_BLAST - 1] = sFireBlastDescription,
    [MOVE_WATERFALL - 1] = sWaterfallDescription,
    [MOVE_CLAMP - 1] = sClampDescription,
    [MOVE_SWIFT - 1] = sSwiftDescription,
    [MOVE_SKULL_BASH - 1] = sSkullBashDescription,
    [MOVE_SPIKE_CANNON - 1] = sSpikeCannonDescription,
    [MOVE_CONSTRICT - 1] = sConstrictDescription,
    [MOVE_AMNESIA - 1] = sAmnesiaDescription,
    [MOVE_KINESIS - 1] = sKinesisDescription,
    [MOVE_SOFT_BOILED - 1] = sSoftBoiledDescription,
    [MOVE_HIGH_JUMP_KICK - 1] = sHighJumpKickDescription,
    [MOVE_GLARE - 1] = sGlareDescription,
    [MOVE_DREAM_EATER - 1] = sDreamEaterDescription,
    [MOVE_POISON_GAS - 1] = sPoisonGasDescription,
    [MOVE_BARRAGE - 1] = sBarrageDescription,
    [MOVE_LEECH_LIFE - 1] = sLeechLifeDescription,
    [MOVE_LOVELY_KISS - 1] = sLovelyKissDescription,
    [MOVE_SKY_ATTACK - 1] = sSkyAttackDescription,
    [MOVE_TRANSFORM - 1] = sTransformDescription,
    [MOVE_BUBBLE - 1] = sBubbleDescription,
    [MOVE_DIZZY_PUNCH - 1] = sDizzyPunchDescription,
    [MOVE_SPORE - 1] = sSporeDescription,
    [MOVE_FLASH - 1] = sFlashDescription,
    [MOVE_PSYWAVE - 1] = sPsywaveDescription,
    [MOVE_SPLASH - 1] = sSplashDescription,
    [MOVE_ACID_ARMOR - 1] = sAcidArmorDescription,
    [MOVE_CRABHAMMER - 1] = sCrabhammerDescription,
    [MOVE_EXPLOSION - 1] = sExplosionDescription,
    [MOVE_FURY_SWIPES - 1] = sFurySwipesDescription,
    [MOVE_BONEMERANG - 1] = sBonemerangDescription,
    [MOVE_REST - 1] = sRestDescription,
    [MOVE_ROCK_SLIDE - 1] = sRockSlideDescription,
    [MOVE_HYPER_FANG - 1] = sHyperFangDescription,
    [MOVE_SHARPEN - 1] = sSharpenDescription,
    [MOVE_CONVERSION - 1] = sConversionDescription,
    [MOVE_TRI_ATTACK - 1] = sTriAttackDescription,
    [MOVE_SUPER_FANG - 1] = sSuperFangDescription,
    [MOVE_SLASH - 1] = sSlashDescription,
    [MOVE_SUBSTITUTE - 1] = sSubstituteDescription,
    [MOVE_STRUGGLE - 1] = sStruggleDescription,
    [MOVE_SKETCH - 1] = sSketchDescription,
    [MOVE_TRIPLE_KICK - 1] = sTripleKickDescription,
    [MOVE_THIEF - 1] = sThiefDescription,
    [MOVE_SPIDER_WEB - 1] = sSpiderWebDescription,
    [MOVE_MIND_READER - 1] = sMindReaderDescription,
    [MOVE_NIGHTMARE - 1] = sNightmareDescription,
    [MOVE_FLAME_WHEEL - 1] = sFlameWheelDescription,
    [MOVE_SNORE - 1] = sSnoreDescription,
    [MOVE_CURSE - 1] = sCurseDescription,
    [MOVE_FLAIL - 1] = sFlailDescription,
    [MOVE_CONVERSION_2 - 1] = sConversion2Description,
    [MOVE_AEROBLAST - 1] = sAeroblastDescription,
    [MOVE_COTTON_SPORE - 1] = sCottonSporeDescription,
    [MOVE_REVERSAL - 1] = sReversalDescription,
    [MOVE_SPITE - 1] = sSpiteDescription,
    [MOVE_POWDER_SNOW - 1] = sPowderSnowDescription,
    [MOVE_PROTECT - 1] = sProtectDescription,
    [MOVE_MACH_PUNCH - 1] = sMachPunchDescription,
    [MOVE_SCARY_FACE - 1] = sScaryFaceDescription,
    [MOVE_FEINT_ATTACK - 1] = sFeintAttackDescription,
    [MOVE_SWEET_KISS - 1] = sSweetKissDescription,
    [MOVE_BELLY_DRUM - 1] = sBellyDrumDescription,
    [MOVE_SLUDGE_BOMB - 1] = sSludgeBombDescription,
    [MOVE_MUD_SLAP - 1] = sMudSlapDescription,
    [MOVE_OCTAZOOKA - 1] = sOctazookaDescription,
    [MOVE_SPIKES - 1] = sSpikesDescription,
    [MOVE_ZAP_CANNON - 1] = sZapCannonDescription,
    [MOVE_FORESIGHT - 1] = sForesightDescription,
    [MOVE_DESTINY_BOND - 1] = sDestinyBondDescription,
    [MOVE_PERISH_SONG - 1] = sPerishSongDescription,
    [MOVE_ICY_WIND - 1] = sIcyWindDescription,
    [MOVE_DETECT - 1] = sDetectDescription,
    [MOVE_BONE_RUSH - 1] = sBoneRushDescription,
    [MOVE_LOCK_ON - 1] = sLockOnDescription,
    [MOVE_OUTRAGE - 1] = sOutrageDescription,
    [MOVE_SANDSTORM - 1] = sSandstormDescription,
    [MOVE_GIGA_DRAIN - 1] = sGigaDrainDescription,
    [MOVE_ENDURE - 1] = sEndureDescription,
    [MOVE_CHARM - 1] = sCharmDescription,
    [MOVE_ROLLOUT - 1] = sRolloutDescription,
    [MOVE_FALSE_SWIPE - 1] = sFalseSwipeDescription,
    [MOVE_SWAGGER - 1] = sSwaggerDescription,
    [MOVE_MILK_DRINK - 1] = sMilkDrinkDescription,
    [MOVE_SPARK - 1] = sSparkDescription,
    [MOVE_FURY_CUTTER - 1] = sFuryCutterDescription,
    [MOVE_STEEL_WING - 1] = sSteelWingDescription,
    [MOVE_MEAN_LOOK - 1] = sMeanLookDescription,
    [MOVE_ATTRACT - 1] = sAttractDescription,
    [MOVE_SLEEP_TALK - 1] = sSleepTalkDescription,
    [MOVE_HEAL_BELL - 1] = sHealBellDescription,
    [MOVE_RETURN - 1] = sReturnDescription,
    [MOVE_PRESENT - 1] = sPresentDescription,
    [MOVE_FRUSTRATION - 1] = sFrustrationDescription,
    [MOVE_SAFEGUARD - 1] = sSafeguardDescription,
    [MOVE_PAIN_SPLIT - 1] = sPainSplitDescription,
    [MOVE_SACRED_FIRE - 1] = sSacredFireDescription,
    [MOVE_MAGNITUDE - 1] = sMagnitudeDescription,
    [MOVE_DYNAMIC_PUNCH - 1] = sDynamicPunchDescription,
    [MOVE_MEGAHORN - 1] = sMegahornDescription,
    [MOVE_DRAGON_BREATH - 1] = sDragonBreathDescription,
    [MOVE_BATON_PASS - 1] = sBatonPassDescription,
    [MOVE_ENCORE - 1] = sEncoreDescription,
    [MOVE_PURSUIT - 1] = sPursuitDescription,
    [MOVE_RAPID_SPIN - 1] = sRapidSpinDescription,
    [MOVE_SWEET_SCENT - 1] = sSweetScentDescription,
    [MOVE_IRON_TAIL - 1] = sIronTailDescription,
    [MOVE_METAL_CLAW - 1] = sMetalClawDescription,
    [MOVE_VITAL_THROW - 1] = sVitalThrowDescription,
    [MOVE_MORNING_SUN - 1] = sMorningSunDescription,
    [MOVE_SYNTHESIS - 1] = sSynthesisDescription,
    [MOVE_MOONLIGHT - 1] = sMoonlightDescription,
    [MOVE_HIDDEN_POWER - 1] = sHiddenPowerDescription,
    [MOVE_CROSS_CHOP - 1] = sCrossChopDescription,
    [MOVE_TWISTER - 1] = sTwisterDescription,
    [MOVE_RAIN_DANCE - 1] = sRainDanceDescription,
    [MOVE_SUNNY_DAY - 1] = sSunnyDayDescription,
    [MOVE_CRUNCH - 1] = sCrunchDescription,
    [MOVE_MIRROR_COAT - 1] = sMirrorCoatDescription,
    [MOVE_PSYCH_UP - 1] = sPsychUpDescription,
    [MOVE_EXTREME_SPEED - 1] = sExtremeSpeedDescription,
    [MOVE_ANCIENT_POWER - 1] = sAncientPowerDescription,
    [MOVE_SHADOW_BALL - 1] = sShadowBallDescription,
    [MOVE_FUTURE_SIGHT - 1] = sFutureSightDescription,
    [MOVE_ROCK_SMASH - 1] = sRockSmashDescription,
    [MOVE_WHIRLPOOL - 1] = sWhirlpoolDescription,
    [MOVE_BEAT_UP - 1] = sBeatUpDescription,
    [MOVE_FAKE_OUT - 1] = sFakeOutDescription,
    [MOVE_UPROAR - 1] = sUproarDescription,
    [MOVE_STOCKPILE - 1] = sStockpileDescription,
    [MOVE_SPIT_UP - 1] = sSpitUpDescription,
    [MOVE_SWALLOW - 1] = sSwallowDescription,
    [MOVE_HEAT_WAVE - 1] = sHeatWaveDescription,
    [MOVE_HAIL - 1] = sHailDescription,
    [MOVE_TORMENT - 1] = sTormentDescription,
    [MOVE_FLATTER - 1] = sFlatterDescription,
    [MOVE_WILL_O_WISP - 1] = sWillOWispDescription,
    [MOVE_MEMENTO - 1] = sMementoDescription,
    [MOVE_FACADE - 1] = sFacadeDescription,
    [MOVE_FOCUS_PUNCH - 1] = sFocusPunchDescription,
    [MOVE_SMELLING_SALTS - 1] = sSmellingSaltsDescription,
    [MOVE_FOLLOW_ME - 1] = sFollowMeDescription,
    [MOVE_NATURE_POWER - 1] = sNaturePowerDescription,
    [MOVE_CHARGE - 1] = sChargeDescription,
    [MOVE_TAUNT - 1] = sTauntDescription,
    [MOVE_HELPING_HAND - 1] = sHelpingHandDescription,
    [MOVE_TRICK - 1] = sTrickDescription,
    [MOVE_ROLE_PLAY - 1] = sRolePlayDescription,
    [MOVE_WISH - 1] = sWishDescription,
    [MOVE_ASSIST - 1] = sAssistDescription,
    [MOVE_INGRAIN - 1] = sIngrainDescription,
    [MOVE_SUPERPOWER - 1] = sSuperpowerDescription,
    [MOVE_MAGIC_COAT - 1] = sMagicCoatDescription,
    [MOVE_RECYCLE - 1] = sRecycleDescription,
    [MOVE_REVENGE - 1] = sRevengeDescription,
    [MOVE_BRICK_BREAK - 1] = sBrickBreakDescription,
    [MOVE_YAWN - 1] = sYawnDescription,
    [MOVE_KNOCK_OFF - 1] = sKnockOffDescription,
    [MOVE_ENDEAVOR - 1] = sEndeavorDescription,
    [MOVE_ERUPTION - 1] = sEruptionDescription,
    [MOVE_SKILL_SWAP - 1] = sSkillSwapDescription,
    [MOVE_IMPRISON - 1] = sImprisonDescription,
    [MOVE_REFRESH - 1] = sRefreshDescription,
    [MOVE_GRUDGE - 1] = sGrudgeDescription,
    [MOVE_SNATCH - 1] = sSnatchDescription,
    [MOVE_SECRET_POWER - 1] = sSecretPowerDescription,
    [MOVE_DIVE - 1] = sDiveDescription,
    [MOVE_ARM_THRUST - 1] = sArmThrustDescription,
    [MOVE_CAMOUFLAGE - 1] = sCamouflageDescription,
    [MOVE_TAIL_GLOW - 1] = sTailGlowDescription,
    [MOVE_LUSTER_PURGE - 1] = sLusterPurgeDescription,
    [MOVE_MIST_BALL - 1] = sMistBallDescription,
    [MOVE_FEATHER_DANCE - 1] = sFeatherDanceDescription,
    [MOVE_TEETER_DANCE - 1] = sTeeterDanceDescription,
    [MOVE_BLAZE_KICK - 1] = sBlazeKickDescription,
    [MOVE_MUD_SPORT - 1] = sMudSportDescription,
    [MOVE_ICE_BALL - 1] = sIceBallDescription,
    [MOVE_NEEDLE_ARM - 1] = sNeedleArmDescription,
    [MOVE_SLACK_OFF - 1] = sSlackOffDescription,
    [MOVE_HYPER_VOICE - 1] = sHyperVoiceDescription,
    [MOVE_POISON_FANG - 1] = sPoisonFangDescription,
    [MOVE_CRUSH_CLAW - 1] = sCrushClawDescription,
    [MOVE_BLAST_BURN - 1] = sBlastBurnDescription,
    [MOVE_HYDRO_CANNON - 1] = sHydroCannonDescription,
    [MOVE_METEOR_MASH - 1] = sMeteorMashDescription,
    [MOVE_ASTONISH - 1] = sAstonishDescription,
    [MOVE_WEATHER_BALL - 1] = sWeatherBallDescription,
    [MOVE_AROMATHERAPY - 1] = sAromatherapyDescription,
    [MOVE_FAKE_TEARS - 1] = sFakeTearsDescription,
    [MOVE_AIR_CUTTER - 1] = sAirCutterDescription,
    [MOVE_OVERHEAT - 1] = sOverheatDescription,
    [MOVE_ODOR_SLEUTH - 1] = sOdorSleuthDescription,
    [MOVE_ROCK_TOMB - 1] = sRockTombDescription,
    [MOVE_SILVER_WIND - 1] = sSilverWindDescription,
    [MOVE_METAL_SOUND - 1] = sMetalSoundDescription,
    [MOVE_GRASS_WHISTLE - 1] = sGrassWhistleDescription,
    [MOVE_TICKLE - 1] = sTickleDescription,
    [MOVE_COSMIC_POWER - 1] = sCosmicPowerDescription,
    [MOVE_WATER_SPOUT - 1] = sWaterSpoutDescription,
    [MOVE_SIGNAL_BEAM - 1] = sSignalBeamDescription,
    [MOVE_SHADOW_PUNCH - 1] = sShadowPunchDescription,
    [MOVE_EXTRASENSORY - 1] = sExtrasensoryDescription,
    [MOVE_SKY_UPPERCUT - 1] = sSkyUppercutDescription,
    [MOVE_SAND_TOMB - 1] = sSandTombDescription,
    [MOVE_SHEER_COLD - 1] = sSheerColdDescription,
    [MOVE_MUDDY_WATER - 1] = sMuddyWaterDescription,
    [MOVE_BULLET_SEED - 1] = sBulletSeedDescription,
    [MOVE_AERIAL_ACE - 1] = sAerialAceDescription,
    [MOVE_ICICLE_SPEAR - 1] = sIcicleSpearDescription,
    [MOVE_IRON_DEFENSE - 1] = sIronDefenseDescription,
    [MOVE_BLOCK - 1] = sBlockDescription,
    [MOVE_HOWL - 1] = sHowlDescription,
    [MOVE_DRAGON_CLAW - 1] = sDragonClawDescription,
    [MOVE_FRENZY_PLANT - 1] = sFrenzyPlantDescription,
    [MOVE_BULK_UP - 1] = sBulkUpDescription,
    [MOVE_BOUNCE - 1] = sBounceDescription,
    [MOVE_MUD_SHOT - 1] = sMudShotDescription,
    [MOVE_POISON_TAIL - 1] = sPoisonTailDescription,
    [MOVE_COVET - 1] = sCovetDescription,
    [MOVE_VOLT_TACKLE - 1] = sVoltTackleDescription,
    [MOVE_MAGICAL_LEAF - 1] = sMagicalLeafDescription,
    [MOVE_WATER_SPORT - 1] = sWaterSportDescription,
    [MOVE_CALM_MIND - 1] = sCalmMindDescription,
    [MOVE_LEAF_BLADE - 1] = sLeafBladeDescription,
    [MOVE_DRAGON_DANCE - 1] = sDragonDanceDescription,
    [MOVE_ROCK_BLAST - 1] = sRockBlastDescription,
    [MOVE_SHOCK_WAVE - 1] = sShockWaveDescription,
    [MOVE_WATER_PULSE - 1] = sWaterPulseDescription,
    [MOVE_DOOM_DESIRE - 1] = sDoomDesireDescription,
    [MOVE_PSYCHO_BOOST - 1] = sPsychoBoostDescription,
    [MOVE_ROOST - 1] = sROOSTDescription,
    [MOVE_GRAVITY - 1] = sGRAVITYDescription,
    [MOVE_MIRACLE_EYE - 1] = sMIRACLE_EYEDescription,
    [MOVE_WAKE_UP_SLAP - 1] = sWAKE_UP_SLAPDescription,
    [MOVE_HAMMER_ARM - 1] = sHAMMER_ARMDescription,
    [MOVE_GYRO_BALL - 1] = sGYRO_BALLDescription,
    [MOVE_HEALING_WISH - 1] = sHEALING_WISHDescription,
    [MOVE_BRINE - 1] = sBRINEDescription,
    [MOVE_NATURAL_GIFT - 1] = sNATURAL_GIFTDescription,
    [MOVE_FEINT - 1] = sFEINTDescription,
    [MOVE_PLUCK - 1] = sPLUCKDescription,
    [MOVE_TAILWIND - 1] = sTAILWINDDescription,
    [MOVE_ACUPRESSURE - 1] = sACUPRESSUREDescription,
    [MOVE_METAL_BURST - 1] = sMETAL_BURSTDescription,
    [MOVE_U_TURN - 1] = sU_TURNDescription,
    [MOVE_CLOSE_COMBAT - 1] = sCLOSE_COMBATDescription,
    [MOVE_PAYBACK - 1] = sPAYBACKDescription,
    [MOVE_ASSURANCE - 1] = sASSURANCEDescription,
    [MOVE_EMBARGO - 1] = sEMBARGODescription,
    [MOVE_FLING - 1] = sFLINGDescription,
    [MOVE_PSYCHO_SHIFT - 1] = sPSYCHO_SHIFTDescription,
    [MOVE_TRUMP_CARD - 1] = sTRUMP_CARDDescription,
    [MOVE_HEAL_BLOCK - 1] = sHEAL_BLOCKDescription,
    [MOVE_WRING_OUT - 1] = sWRING_OUTDescription,
    [MOVE_POWER_TRICK - 1] = sPOWER_TRICKDescription,
    [MOVE_GASTRO_ACID - 1] = sGASTRO_ACIDDescription,
    [MOVE_LUCKY_CHANT - 1] = sLUCKY_CHANTDescription,
    [MOVE_ME_FIRST - 1] = sME_FIRSTDescription,
    [MOVE_COPYCAT - 1] = sCOPYCATDescription,
    [MOVE_POWER_SWAP - 1] = sPOWER_SWAPDescription,
    [MOVE_GUARD_SWAP - 1] = sGUARD_SWAPDescription,
    [MOVE_PUNISHMENT - 1] = sPUNISHMENTDescription,
    [MOVE_LAST_RESORT - 1] = sLAST_RESORTDescription,
    [MOVE_WORRY_SEED - 1] = sWORRY_SEEDDescription,
    [MOVE_SUCKER_PUNCH - 1] = sSUCKER_PUNCHDescription,
    [MOVE_TOXIC_SPIKES - 1] = sTOXIC_SPIKESDescription,
    [MOVE_HEART_SWAP - 1] = sHEART_SWAPDescription,
    [MOVE_AQUA_RING - 1] = sAQUA_RINGDescription,
    [MOVE_MAGNET_RISE - 1] = sMAGNET_RISEDescription,
    [MOVE_FLARE_BLITZ - 1] = sFLARE_BLITZDescription,
    [MOVE_FORCE_PALM - 1] = sFORCE_PALMDescription,
    [MOVE_AURA_SPHERE - 1] = sAURA_SPHEREDescription,
    [MOVE_ROCK_POLISH - 1] = sROCK_POLISHDescription,
    [MOVE_POISON_JAB - 1] = sPOISON_JABDescription,
    [MOVE_DARK_PULSE - 1] = sDARK_PULSEDescription,
    [MOVE_NIGHT_SLASH - 1] = sNIGHT_SLASHDescription,
    [MOVE_AQUA_TAIL - 1] = sAQUA_TAILDescription,
    [MOVE_SEED_BOMB - 1] = sSEED_BOMBDescription,
    [MOVE_AIR_SLASH - 1] = sAIR_SLASHDescription,
    [MOVE_X_SCISSOR - 1] = sX_SCISSORDescription,
    [MOVE_BUG_BUZZ - 1] = sBUG_BUZZDescription,
    [MOVE_DRAGON_PULSE - 1] = sDRAGON_PULSEDescription,
    [MOVE_DRAGON_RUSH - 1] = sDRAGON_RUSHDescription,
    [MOVE_POWER_GEM - 1] = sPOWER_GEMDescription,
    [MOVE_DRAIN_PUNCH - 1] = sDRAIN_PUNCHDescription,
    [MOVE_VACUUM_WAVE - 1] = sVACUUM_WAVEDescription,
    [MOVE_FOCUS_BLAST - 1] = sFOCUS_BLASTDescription,
    [MOVE_ENERGY_BALL - 1] = sENERGY_BALLDescription,
    [MOVE_BRAVE_BIRD - 1] = sBRAVE_BIRDDescription,
    [MOVE_EARTH_POWER - 1] = sEARTH_POWERDescription,
    [MOVE_SWITCHEROO - 1] = sSWITCHEROODescription,
    [MOVE_GIGA_IMPACT - 1] = sGigaImpactDescription,
    [MOVE_NASTY_PLOT - 1] = sNASTY_PLOTDescription,
    [MOVE_BULLET_PUNCH - 1] = sBULLET_PUNCHDescription,
    [MOVE_AVALANCHE - 1] = sRevengeDescription,
    [MOVE_ICE_SHARD - 1] = sICE_SHARDDescription,
    [MOVE_SHADOW_CLAW - 1] = sSHADOW_CLAWDescription,
    [MOVE_THUNDER_FANG - 1] = sTHUNDER_FANGDescription,
    [MOVE_ICE_FANG - 1] = sICE_FANGDescription,
    [MOVE_FIRE_FANG - 1] = sFIRE_FANGDescription,
    [MOVE_SHADOW_SNEAK - 1] = sSHADOW_SNEAKDescription,
    [MOVE_MUD_BOMB - 1] = sMUD_BOMBDescription,
    [MOVE_PSYCHO_CUT - 1] = sPSYCHO_CUTDescription,
    [MOVE_ZEN_HEADBUTT - 1] = sZEN_HEADBUTTDescription,
    [MOVE_MIRROR_SHOT - 1] = sMIRROR_SHOTDescription,
    [MOVE_FLASH_CANNON - 1] = sFLASH_CANNONDescription,
    [MOVE_ROCK_CLIMB - 1] = sROCK_CLIMBDescription,
    [MOVE_DEFOG - 1] = sDEFOGDescription,
    [MOVE_TRICK_ROOM - 1] = sTRICK_ROOMDescription,
    [MOVE_DRACO_METEOR - 1] = sDRACO_METEORDescription,
    [MOVE_DISCHARGE - 1] = sDISCHARGEDescription,
    [MOVE_LAVA_PLUME - 1] = sLAVA_PLUMEDescription,
    [MOVE_LEAF_STORM - 1] = sLEAF_STORMDescription,
    [MOVE_POWER_WHIP - 1] = sPOWER_WHIPDescription,
    [MOVE_ROCK_WRECKER - 1] = sHyperBeamDescription,
    [MOVE_CROSS_POISON - 1] = sCROSS_POISONDescription,
    [MOVE_GUNK_SHOT - 1] = sGUNK_SHOTDescription,
    [MOVE_IRON_HEAD - 1] = sIRON_HEADDescription,
    [MOVE_MAGNET_BOMB - 1] = sMAGNET_BOMBDescription,
    [MOVE_STONE_EDGE - 1] = sSTONE_EDGEDescription,
    [MOVE_CAPTIVATE - 1] = sCAPTIVATEDescription,
    [MOVE_STEALTH_ROCK - 1] = sSTEALTH_ROCKDescription,
    [MOVE_GRASS_KNOT - 1] = sGRASS_KNOTDescription,
    [MOVE_CHATTER - 1] = sCHATTERDescription,
    [MOVE_JUDGMENT - 1] = sJUDGMENTDescription,
    [MOVE_BUG_BITE - 1] = sPLUCKDescription,
    [MOVE_DRACONIC_FANGS - 1] = sDRACONIC_FANGSDescription,
    [MOVE_CHARGE_BEAM - 1] = sCHARGE_BEAMDescription,
    [MOVE_PRIMAL_BEAM - 1] = sPRIMAL_BEAMDescription,
    [MOVE_WOOD_HAMMER - 1] = sWOOD_HAMMERDescription,
    [MOVE_AQUA_JET - 1] = sAQUA_JETDescription,
    [MOVE_ATTACK_ORDER - 1] = sATTACK_ORDERDescription,
    [MOVE_DEFEND_ORDER - 1] = sDEFEND_ORDERDescription,
    [MOVE_HEAL_ORDER - 1] = sHEAL_ORDERDescription,
    [MOVE_HEAD_SMASH - 1] = sHEAD_SMASHDescription,
    [MOVE_DOUBLE_HIT - 1] = sDOUBLE_HITDescription,
    [MOVE_ROAR_OF_TIME - 1] = sROAR_OF_TIMEDescription,
    [MOVE_SPACIAL_REND - 1] = sSPACIAL_RENDDescription,
    [MOVE_LUNAR_DANCE - 1] = sHEALING_WISHDescription,
    [MOVE_CRUSH_GRIP - 1] = sWRING_OUTDescription,
    [MOVE_MAGMA_STORM - 1] = sMAGMA_STORMDescription,
    [MOVE_DARK_VOID - 1] = sDARK_VOIDDescription,
    [MOVE_SEED_FLARE - 1] = sSEED_FLAREDescription,
    [MOVE_OMINOUS_WIND - 1] = sOMINOUS_WINDDescription,
    [MOVE_SHADOW_FORCE - 1] = sSHADOW_FORCEDescription,
    [MOVE_HONE_CLAWS - 1] = sHONE_CLAWSDescription,
    [MOVE_WIDE_GUARD - 1] = sWIDE_GUARDDescription,
    [MOVE_GUARD_SPLIT - 1] = sGUARD_SPLITDescription,
    [MOVE_POWER_SPLIT - 1] = sPOWER_SPLITDescription,
    [MOVE_WONDER_ROOM - 1] = sWONDER_ROOMDescription,
    [MOVE_PSYSHOCK - 1] = sPSYSHOCKDescription,
    [MOVE_VENOSHOCK - 1] = sVENOSHOCKDescription,
    [MOVE_AUTOTOMIZE - 1] = sAUTOTOMIZEDescription,
    [MOVE_RAGE_POWDER - 1] = sRAGE_POWDERDescription,
    [MOVE_TELEKINESIS - 1] = sTELEKINESISDescription,
    [MOVE_MAGIC_ROOM - 1] = sMAGIC_ROOMDescription,
    [MOVE_SMACK_DOWN - 1] = sSMACK_DOWNDescription,
    [MOVE_STORM_THROW - 1] = sSTORM_THROWDescription,
    [MOVE_FLAME_BURST - 1] = sFLAME_BURSTDescription,
    [MOVE_SLUDGE_WAVE - 1] = sSLUDGE_WAVEDescription,
    [MOVE_QUIVER_DANCE - 1] = sQUIVER_DANCEDescription,
    [MOVE_HEAVY_SLAM - 1] = sHEAVY_SLAMDescription,
    [MOVE_SYNCHRONOISE - 1] = sSYNCHRONOISEDescription,
    [MOVE_ELECTRO_BALL - 1] = sELECTRO_BALLDescription,
    [MOVE_SOAK - 1] = sSOAKDescription,
    [MOVE_FLAME_CHARGE - 1] = sFLAME_CHARGEDescription,
    [MOVE_COIL - 1] = sCOILDescription,
    [MOVE_LOW_SWEEP - 1] = sLOW_SWEEPDescription,
    [MOVE_ACID_SPRAY - 1] = sACID_SPRAYDescription,
    [MOVE_FOUL_PLAY - 1] = sFOUL_PLAYDescription,
    [MOVE_SIMPLE_BEAM - 1] = sSIMPLE_BEAMDescription,
    [MOVE_ENTRAINMENT - 1] = sENTRAINMENTDescription,
    [MOVE_AFTER_YOU - 1] = sAFTER_YOUDescription,
    [MOVE_ROUND - 1] = sROUNDDescription,
    [MOVE_ECHOED_VOICE - 1] = sECHOED_VOICEDescription,
    [MOVE_CHIP_AWAY - 1] = sCHIP_AWAYDescription,
    [MOVE_CLEAR_SMOG - 1] = sCLEAR_SMOGDescription,
    [MOVE_STORED_POWER - 1] = sSTORED_POWERDescription,
    [MOVE_QUICK_GUARD - 1] = sQUICK_GUARDDescription,
    [MOVE_ALLY_SWITCH - 1] = sALLY_SWITCHDescription,
    [MOVE_SCALD - 1] = sSCALDDescription,
    [MOVE_SHELL_SMASH - 1] = sSHELL_SMASHDescription,
    [MOVE_HEAL_PULSE - 1] = sHEAL_PULSEDescription,
    [MOVE_HEX - 1] = sHEXDescription,
    [MOVE_SKY_DROP - 1] = sSKY_DROPDescription,
    [MOVE_SHIFT_GEAR - 1] = sSHIFT_GEARDescription,
    [MOVE_CIRCLE_THROW - 1] = sCIRCLE_THROWDescription,
    [MOVE_INCINERATE - 1] = sINCINERATEDescription,
    [MOVE_QUASH - 1] = sQUASHDescription,
    [MOVE_ACROBATICS - 1] = sACROBATICSDescription,
    [MOVE_REFLECT_TYPE - 1] = sREFLECT_TYPEDescription,
    [MOVE_RETALIATE - 1] = sRETALIATEDescription,
    [MOVE_FINAL_GAMBIT - 1] = sFINAL_GAMBITDescription,
    [MOVE_BESTOW - 1] = sBESTOWDescription,
    [MOVE_INFERNO - 1] = sINFERNODescription,
    [MOVE_WATER_PLEDGE - 1] = sWATER_PLEDGEDescription,
    [MOVE_FIRE_PLEDGE - 1] = sFIRE_PLEDGEDescription,
    [MOVE_GRASS_PLEDGE - 1] = sGRASS_PLEDGEDescription,
    [MOVE_VOLT_SWITCH - 1] = sU_TURNDescription,
    [MOVE_STRUGGLE_BUG - 1] = sSTRUGGLE_BUGDescription,
    [MOVE_BULLDOZE - 1] = sBULLDOZEDescription,
    [MOVE_FROST_BREATH - 1] = sSTORM_THROWDescription,
    [MOVE_DRAGON_TAIL - 1] = sCIRCLE_THROWDescription,
    [MOVE_WORK_UP - 1] = sWORK_UPDescription,
    [MOVE_ELECTROWEB - 1] = sELECTROWEBDescription,
    [MOVE_WILD_CHARGE - 1] = sWILD_CHARGEDescription,
    [MOVE_DRILL_RUN - 1] = sDRILL_RUNDescription,
    [MOVE_DUAL_CHOP - 1] = sDUAL_CHOPDescription,
    [MOVE_HEART_STAMP - 1] = sHEART_STAMPDescription,
    [MOVE_HORN_LEECH - 1] = sMegaDrainDescription,
    [MOVE_SACRED_SWORD - 1] = sCHIP_AWAYDescription,
    [MOVE_RAZOR_SHELL - 1] = sRAZOR_SHELLDescription,
    [MOVE_HEAT_CRASH - 1] = sHEAVY_SLAMDescription,
    [MOVE_LEAF_TORNADO - 1] = sLEAF_TORNADODescription,
    [MOVE_STEAMROLLER - 1] = sSTEAMROLLERDescription,
    [MOVE_COTTON_GUARD - 1] = sCOTTON_GUARDDescription,
    [MOVE_NIGHT_DAZE - 1] = sNIGHT_DAZEDescription,
    [MOVE_PSYSTRIKE - 1] = sPSYSHOCKDescription,
    [MOVE_TAIL_SLAP - 1] = sTAIL_SLAPDescription,
    [MOVE_HURRICANE - 1] = sHURRICANEDescription,
    [MOVE_HEAD_CHARGE - 1] = sHEAD_CHARGEDescription,
    [MOVE_GEAR_GRIND - 1] = sGEAR_GRINDDescription,
    [MOVE_SEARING_SHOT - 1] = sLAVA_PLUMEDescription,
    [MOVE_TECHNO_BLAST - 1] = sTECHNO_BLASTDescription,
    [MOVE_RELIC_SONG - 1] = sRELIC_SONGDescription,
    [MOVE_SECRET_SWORD - 1] = sSECRET_SWORDDescription,
    [MOVE_GLACIATE - 1] = sGLACIATEDescription,
    [MOVE_BOLT_STRIKE - 1] = sBOLT_STRIKEDescription,
    [MOVE_BLUE_FLARE - 1] = sBLUE_FLAREDescription,
    [MOVE_FIERY_DANCE - 1] = sFIERY_DANCEDescription,
    [MOVE_FREEZE_SHOCK - 1] = sFREEZE_SHOCKDescription,
    [MOVE_ICE_BURN - 1] = sICE_BURNDescription,
    [MOVE_SNARL - 1] = sSNARLDescription,
    [MOVE_ICICLE_CRASH - 1] = sICICLE_CRASHDescription,
    [MOVE_V_CREATE - 1] = sV_CREATEDescription,
    [MOVE_FUSION_FLARE - 1] = sFUSION_FLAREDescription,
    [MOVE_FUSION_BOLT - 1] = sFUSION_BOLTDescription,
    [MOVE_FLYING_PRESS - 1] = sFLYING_PRESSDescription,
    [MOVE_MAT_BLOCK - 1] = sMAT_BLOCKDescription,
    [MOVE_BELCH - 1] = sBELCHDescription,
    [MOVE_ROTOTILLER - 1] = sROTOTILLERDescription,
    [MOVE_STICKY_WEB - 1] = sSTICKY_WEBDescription,
    [MOVE_FELL_STINGER - 1] = sFELL_STINGERDescription,
    [MOVE_PHANTOM_FORCE - 1] = sSHADOW_FORCEDescription,
    [MOVE_TRICK_OR_TREAT - 1] = sTRICK_OR_TREATDescription,
    [MOVE_NOBLE_ROAR - 1] = sNOBLE_ROARDescription,
    [MOVE_ION_DELUGE - 1] = sION_DELUGEDescription,
    [MOVE_PARABOLIC_CHARGE - 1] = sPARABOLIC_CHARGEDescription,
    [MOVE_FORESTS_CURSE - 1] = sFORESTS_CURSEDescription,
    [MOVE_PETAL_BLIZZARD - 1] = sPETAL_BLIZZARDDescription,
    [MOVE_FREEZE_DRY - 1] = sFREEZE_DRYDescription,
    [MOVE_DISARMING_VOICE - 1] = sDISARMING_VOICEDescription,
    [MOVE_PARTING_SHOT - 1] = sPARTING_SHOTDescription,
    [MOVE_TOPSY_TURVY - 1] = sTOPSY_TURVYDescription,
    [MOVE_DRAINING_KISS - 1] = sDRAINING_KISSDescription,
    [MOVE_CRAFTY_SHIELD - 1] = sCRAFTY_SHIELDDescription,
    [MOVE_FLOWER_SHIELD - 1] = sFLOWER_SHIELDDescription,
    [MOVE_GRASSY_TERRAIN - 1] = sGRASSY_TERRAINDescription,
    [MOVE_MISTY_TERRAIN - 1] = sMISTY_TERRAINDescription,
    [MOVE_ELECTRIFY - 1] = sELECTRIFYDescription,
    [MOVE_PLAY_ROUGH - 1] = sPLAY_ROUGHDescription,
    [MOVE_FAIRY_WIND - 1] = sFAIRY_WINDDescription,
    [MOVE_MOONBLAST - 1] = sMOONBLASTDescription,
    [MOVE_BOOMBURST - 1] = sBOOMBURSTDescription,
    [MOVE_FAIRY_LOCK - 1] = sFAIRY_LOCKDescription,
    [MOVE_KINGS_SHIELD - 1] = sKINGS_SHIELDDescription,
    [MOVE_PLAY_NICE - 1] = sPLAY_NICEDescription,
    [MOVE_CONFIDE - 1] = sCONFIDEDescription,
    [MOVE_DIAMOND_STORM - 1] = sDIAMOND_STORMDescription,
    [MOVE_STEAM_ERUPTION - 1] = sSTEAM_ERUPTIONDescription,
    [MOVE_HYPERSPACE_HOLE - 1] = sHYPERSPACE_HOLEDescription,
    [MOVE_WATER_SHURIKEN - 1] = sWATER_SHURIKENDescription,
    [MOVE_MYSTICAL_FIRE - 1] = sMYSTICAL_FIREDescription,
    [MOVE_SPIKY_SHIELD - 1] = sSPIKY_SHIELDDescription,
    [MOVE_AROMATIC_MIST - 1] = sAROMATIC_MISTDescription,
    [MOVE_EERIE_IMPULSE - 1] = sEERIE_IMPULSEDescription,
    [MOVE_VENOM_DRENCH - 1] = sVENOM_DRENCHDescription,
    [MOVE_POWDER - 1] = sPOWDERDescription,
    [MOVE_GEOMANCY - 1] = sGEOMANCYDescription,
    [MOVE_MAGNETIC_FLUX - 1] = sMAGNETIC_FLUXDescription,
    [MOVE_HAPPY_HOUR - 1] = sHAPPY_HOURDescription,
    [MOVE_ELECTRIC_TERRAIN - 1] = sELECTRIC_TERRAINDescription,
    [MOVE_DAZZLING_GLEAM - 1] = sDAZZLING_GLEAMDescription,
    [MOVE_CELEBRATE - 1] = sCELEBRATEDescription,
    [MOVE_HOLD_HANDS - 1] = sHOLD_HANDSDescription,
    [MOVE_BABY_DOLL_EYES - 1] = sBABYDOLL_EYESDescription,
    [MOVE_NUZZLE - 1] = sNUZZLEDescription,
    [MOVE_HOLD_BACK - 1] = sFalseSwipeDescription,
    [MOVE_INFESTATION - 1] = sINFESTATIONDescription,
    [MOVE_POWER_UP_PUNCH - 1] = sPOWER_UP_PUNCHDescription,
    [MOVE_OBLIVION_WING - 1] = sOBLIVION_WINGDescription,
    [MOVE_THOUSAND_ARROWS - 1] = sTHOUSAND_ARROWSDescription,
    [MOVE_THOUSAND_WAVES - 1] = sTHOUSAND_WAVESDescription,
    [MOVE_LANDS_WRATH - 1] = sLANDS_WRATHDescription,
    [MOVE_LIGHT_OF_RUIN - 1] = sLIGHT_OF_RUINDescription,
    [MOVE_ORIGIN_PULSE - 1] = sORIGIN_PULSEDescription,
    [MOVE_PRECIPICE_BLADES - 1] = sPRECIPICE_BLADESDescription,
    [MOVE_DRAGON_ASCENT - 1] = sCLOSE_COMBATDescription,
    [MOVE_HYPERSPACE_FURY - 1] = sHYPERSPACE_HOLEDescription,
    [MOVE_SHORE_UP - 1] = sSHORE_UPDescription,
    [MOVE_FIRST_IMPRESSION - 1] = sFIRST_IMPRESSIONDescription,
    [MOVE_BANEFUL_BUNKER - 1] = sBANEFUL_BUNKERDescription,
    [MOVE_SPIRIT_SHACKLE - 1] = sSPIRIT_SHACKLEDescription,
    [MOVE_DARKEST_LARIAT - 1] = sDARKEST_LARIATDescription,
    [MOVE_SPARKLING_ARIA - 1] = sSPARKLING_ARIADescription,
    [MOVE_ICE_HAMMER - 1] = sICE_HAMMERDescription,
    [MOVE_FLORAL_HEALING - 1] = sFLORAL_HEALINGDescription,
    [MOVE_HIGH_HORSEPOWER - 1] = sHIGH_HORSEPOWERDescription,
    [MOVE_STRENGTH_SAP - 1] = sSTRENGTH_SAPDescription,
    [MOVE_SOLAR_BLADE - 1] = sSOLAR_BLADEDescription,
    [MOVE_LEAFAGE - 1] = sLEAFAGEDescription,
    [MOVE_SPOTLIGHT - 1] = sSPOTLIGHTDescription,
    [MOVE_TOXIC_THREAD - 1] = sTOXIC_THREADDescription,
    [MOVE_LASER_FOCUS - 1] = sLASER_FOCUSDescription,
    [MOVE_GEAR_UP - 1] = sGEAR_UPDescription,
    [MOVE_THROAT_CHOP - 1] = sTHROAT_CHOPDescription,
    [MOVE_POLLEN_PUFF - 1] = sPOLLEN_PUFFDescription,
    [MOVE_ANCHOR_SHOT - 1] = sANCHOR_SHOTDescription,
    [MOVE_PSYCHIC_TERRAIN - 1] = sPSYCHIC_TERRAINDescription,
    [MOVE_LUNGE - 1] = sLUNGEDescription,
    [MOVE_FIRE_LASH - 1] = sFIRE_LASHDescription,
    [MOVE_POWER_TRIP - 1] = sPOWER_TRIPDescription,
    [MOVE_BURN_UP - 1] = sBURN_UPDescription,
    [MOVE_SPEED_SWAP - 1] = sSPEED_SWAPDescription,
    [MOVE_SMART_STRIKE - 1] = sSMART_STRIKEDescription,
    [MOVE_PURIFY - 1] = sPURIFYDescription,
    [MOVE_REVELATION_DANCE - 1] = sREVELATION_DANCEDescription,
    [MOVE_CORE_ENFORCER - 1] = sCORE_ENFORCERDescription,
    [MOVE_TROP_KICK - 1] = sTROP_KICKDescription,
    [MOVE_INSTRUCT - 1] = sINSTRUCTDescription,
    [MOVE_BEAK_BLAST - 1] = sBEAK_BLASTDescription,
    [MOVE_CLANGING_SCALES - 1] = sCLANGING_SCALESDescription,
    [MOVE_DRAGON_HAMMER - 1] = sDRAGON_HAMMERDescription,
    [MOVE_BRUTAL_SWING - 1] = sBRUTAL_SWINGDescription,
    [MOVE_AURORA_VEIL - 1] = sAURORA_VEILDescription,
    [MOVE_SHELL_TRAP - 1] = sSHELL_TRAPDescription,
    [MOVE_FLEUR_CANNON - 1] = sFLEUR_CANNONDescription,
    [MOVE_PSYCHIC_FANGS - 1] = sPSYCHIC_FANGSDescription,
    [MOVE_STOMPING_TANTRUM - 1] = sSTOMPING_TANTRUMDescription,
    [MOVE_SHADOW_BONE - 1] = sSHADOW_BONEDescription,
    [MOVE_ACCELEROCK - 1] = sACCELEROCKDescription,
    [MOVE_LIQUIDATION - 1] = sLIQUIDATIONDescription,
    [MOVE_PRISMATIC_LASER - 1] = sPRISMATIC_LASERDescription,
    [MOVE_SPECTRAL_THIEF - 1] = sSPECTRAL_THIEFDescription,
    [MOVE_SUNSTEEL_STRIKE - 1] = sSUNSTEEL_STRIKEDescription,
    [MOVE_MOONGEIST_BEAM - 1] = sMOONGEIST_BEAMDescription,
    [MOVE_TEARFUL_LOOK - 1] = sTEARFUL_LOOKDescription,
    [MOVE_ZING_ZAP - 1] = sZING_ZAPDescription,
    [MOVE_NATURES_MADNESS - 1] = sNATURES_MADNESSDescription,
    [MOVE_MULTI_ATTACK - 1] = sMULTI_ATTACKDescription,
    [MOVE_MIND_BLOWN - 1] = sMIND_BLOWNDescription,
    [MOVE_PLASMA_FISTS - 1] = sPLASMA_FISTSDescription,
    [MOVE_PHOTON_GEYSER - 1] = sPHOTON_GEYSERDescription,
    [MOVE_ZIPPY_ZAP - 1] = sZIPPY_ZAPDescription,
    [MOVE_SPLISHY_SPLASH - 1] = sSPLISHY_SPLASHDescription,
    [MOVE_FLOATY_FALL - 1] = sFLOATY_FALLDescription,
    [MOVE_PIKA_PAPOW - 1] = sPIKA_PAPOWDescription,
    [MOVE_BOUNCY_BUBBLE - 1] = sBOUNCY_BUBBLEDescription,
    [MOVE_BUZZY_BUZZ - 1] = sBUZZY_BUZZDescription,
    [MOVE_SIZZLY_SLIDE - 1] = sSIZZLY_SLIDEDescription,
    [MOVE_GLITZY_GLOW - 1] = sGLITZY_GLOWDescription,
    [MOVE_BADDY_BAD - 1] = sBADDY_BADDescription,
    [MOVE_SAPPY_SEED - 1] = sSAPPY_SEEDDescription,
    [MOVE_FREEZY_FROST - 1] = sFREEZY_FROSTDescription,
    [MOVE_SPARKLY_SWIRL - 1] = sSPARKLY_SWIRLDescription,
    [MOVE_VEEVEE_VOLLEY - 1] = sVEEVEE_VOLLEYDescription,
    [MOVE_DOUBLE_IRON_BASH - 1] = sDOUBLE_IRON_BASHDescription,

    //GEN 8
    [MOVE_DYNAMAX_CANNON - 1] = sDYNAMAX_CANNONDescription,
    [MOVE_SNIPE_SHOT - 1] = sSNIPE_SHOTDescription,
    [MOVE_JAW_LOCK - 1] = sJAW_LOCKDescription,
    [MOVE_STUFF_CHEEKS - 1] = sSTUFF_CHEEKSDescription,
    [MOVE_NO_RETREAT - 1] = sNO_RETREATDescription,
    [MOVE_TAR_SHOT - 1] = sTAR_SHOTDescription,
    [MOVE_MAGIC_POWDER - 1] = sMAGIC_POWDERDescription,
    [MOVE_DRAGON_DARTS - 1] = sDRAGON_DARTSDescription,
    [MOVE_TEATIME - 1] = sTEATIMEDescription,
    [MOVE_OCTOLOCK - 1] = sOCTOLOCKDescription,
    [MOVE_BOLT_BEAK - 1] = sBOLT_BEAKDescription,
    [MOVE_FISHIOUS_REND - 1] = sFISHIOUS_RENDDescription,
    [MOVE_COURT_CHANGE - 1] = sCOURT_CHANGEDescription,
    [MOVE_CLANGOROUS_SOUL - 1] = sCLANGOROUS_SOULDescription,
    [MOVE_BODY_PRESS - 1] = sBODY_PRESSDescription,
    [MOVE_DECORATE - 1] = sDECORATEDescription,
    [MOVE_DRUM_BEATING - 1] = sDRUM_BEATINGDescription,
    [MOVE_SNAP_TRAP - 1] = sSNAP_TRAPDescription,
    [MOVE_PYRO_BALL - 1] = sPYRO_BALLDescription,
    [MOVE_BEHEMOTH_BLADE - 1] = sBEHEMOTH_BLADEDescription,
    [MOVE_BEHEMOTH_BASH - 1] = sBEHEMOTH_BASHDescription,
    [MOVE_AURA_WHEEL - 1] = sAURA_WHEELDescription,
    [MOVE_BREAKING_SWIPE - 1] = sBREAKING_SWIPEDescription,
    [MOVE_BRANCH_POKE - 1] = sBRANCH_POKEDescription,
    [MOVE_OVERDRIVE - 1] = sOVERDRIVEDescription,
    [MOVE_APPLE_ACID - 1] = sAPPLE_ACIDDescription,
    [MOVE_GRAV_APPLE - 1] = sGRAV_APPLEDescription,
    [MOVE_SPIRIT_BREAK - 1] = sSPIRIT_BREAKDescription,
    [MOVE_STRANGE_STEAM - 1] = sSTRANGE_STEAMDescription,
    [MOVE_LIFE_DEW - 1] = sLIFE_DEWDescription,
    [MOVE_OBSTRUCT - 1] = sOBSTRUCTDescription,
    [MOVE_FALSE_SURRENDER - 1] = sFALSE_SURRENDERDescription,
    [MOVE_METEOR_ASSAULT - 1] = sMETEOR_ASSAULTDescription,
    [MOVE_ETERNABEAM - 1] = sETERNABEAMDescription,
    [MOVE_STEEL_BEAM - 1] = sSTEEL_BEAMDescription,
    [MOVE_EXPANDING_FORCE - 1] = sEXPANDING_FORCEDescription,
    [MOVE_STEEL_ROLLER - 1] = sSTEEL_ROLLERDescription,
    [MOVE_SCALE_SHOT - 1] = sSCALE_SHOTDescription,
    [MOVE_METEOR_BEAM - 1] = sMETEOR_BEAMDescription,
    [MOVE_SHELL_SIDE_ARM - 1] = sSHELL_SIDE_ARMDescription,
    [MOVE_MISTY_EXPLOSION - 1] = sMISTY_EXPLOSIONDescription,
    [MOVE_GRASSY_GLIDE - 1] = sGRASSY_GLIDEDescription,
    [MOVE_RISING_VOLTAGE - 1] = sRISING_VOLTAGEDescription,
    [MOVE_TERRAIN_PULSE - 1] = sTERRAIN_PULSEDescription,
    [MOVE_SKITTER_SMACK - 1] = sSKITTER_SMACKDescription,
    [MOVE_BURNING_JEALOUSY - 1] = sBURNING_JEALOUSYDescription,
    [MOVE_LASH_OUT - 1] = sLASH_OUTDescription,
    [MOVE_POLTERGEIST - 1] = sPOLTERGEISTDescription,
    [MOVE_CORROSIVE_GAS - 1] = sCORROSIVE_GASDescription,
    [MOVE_COACHING - 1] = sCOACHINGDescription,
    [MOVE_FLIP_TURN - 1] = sFLIP_TURNDescription,
    [MOVE_TRIPLE_AXEL - 1] = sTRIPLE_AXELDescription,
    [MOVE_DUAL_WINGBEAT - 1] = sDUAL_WINGBEATDescription,
    [MOVE_SCORCHING_SANDS - 1] = sSCORCHING_SANDSDescription,
    [MOVE_JUNGLE_HEALING - 1] = sJUNGLE_HEALINGDescription,
    [MOVE_WICKED_BLOW - 1] = sWICKED_BLOWDescription,
    [MOVE_SURGING_STRIKES - 1] = sSURGING_STRIKESDescription,
    [MOVE_THUNDER_CAGE - 1] = sTHUNDER_CAGEDescription,
    [MOVE_DRAGON_ENERGY - 1] = sDRAGON_ENERGYDescription,
    [MOVE_FREEZING_GLARE - 1] = sFREEZING_GLAREDescription,
    [MOVE_FIERY_WRATH - 1] = sFIERY_WRATHDescription,
    [MOVE_THUNDEROUS_KICK - 1] = sTHUNDEROUS_KICKDescription,
    [MOVE_GLACIAL_LANCE - 1] = sGLACIAL_LANCEDescription,
    [MOVE_ASTRAL_BARRAGE - 1] = sASTRAL_BARRAGEDescription,
    [MOVE_EERIE_SPELL - 1] = sEERIE_SPELLDescription,

    // Darky's Custom Moves
    [MOVE_DEATHROLL       - 1] = sDEATHROLLDescription,
    [MOVE_EXCALIBUR       - 1] = sEXCALIBURDescription,
    [MOVE_AQUA_FANG       - 1] = sAQUA_FANGDescription,
    [MOVE_WAVE_CRASH      - 1] = sWAVE_CRASHDescription,
    [MOVE_SMITE           - 1] = sSMITEDescription,
    [MOVE_OUTBURST        - 1] = sOUTBURSTDescription,
    [MOVE_SEISMIC_FIST    - 1] = sSEISMIC_FISTDescription,
    [MOVE_IRON_FANGS      - 1] = sIRON_FANGSDescription,
    [MOVE_SHADOW_FANGS    - 1] = sSHADOW_FANGSDescription,
    [MOVE_LOVELY_BITE     - 1] = sLOVELY_BITEDescription,
    [MOVE_JAGGED_FANGS    - 1] = sJAGGED_FANGSDescription,
    [MOVE_SCORCHED_EARTH  - 1] = sSCORCHED_EARTHDescription,
    [MOVE_RAGING_FURY     - 1] = sRAGINGFURYDescription,
    [MOVE_PLASMA_PULSE    - 1] = sPLASMAPULSEDescription,
    [MOVE_PIXIE_BEAM      - 1] = sPIXIE_BEAMDescription,
    [MOVE_PIXIE_SLASH     - 1] = sPIXIE_SLASHDescription,
    [MOVE_SEISMIC_BLADE   - 1] = sSEISMIC_BLADEDescription,
    [MOVE_MOUNTAIN_CHUNK  - 1] = sMOUNTAIN_CHUNKDescription,
    [MOVE_ARCHER_SHOT     - 1] = sARCHER_SHOTDescription,  
    [MOVE_FROST_BRAND     - 1] = sFROST_BRANDDescription,
    [MOVE_FROST_BOLT      - 1] = sFROST_BRANDDescription, //ToChange
    [MOVE_ZEPHYR_RUSH     - 1] = sFROST_BRANDDescription, //ToChange 
    [MOVE_GLACIER_CRASH   - 1] = sFROST_BRANDDescription, //ToChange 
    [MOVE_SUPERSONIC_SHOT - 1] = sFROST_BRANDDescription, //ToChange 
    [MOVE_SHOCKING_JAB    - 1] = sFROST_BRANDDescription, //ToChange 
    [MOVE_SHOCKING_EDGE   - 1] = sFROST_BRANDDescription, //ToChange 
    [MOVE_LIGHTING_SRIKE  - 1] = sFROST_BRANDDescription, //ToChange 
    [MOVE_VOLT_BOLT       - 1] = sFROST_BRANDDescription, //ToChange 
};

static const u8 sMoveFourLineDescription_Pound[] = _("A physical attack\ndelivered with a\nlong tail or a\nforeleg, etc.");
static const u8 sMoveFourLineDescription_KarateChop[] = _("The foe is attacked\nwith a sharp chop.\nIt has a high\ncritical-hit ratio.");
static const u8 sMoveFourLineDescription_DoubleSlap[] = _("The foe is slapped\nrepeatedly, back\nand forth, two to\nfive times.");
static const u8 sMoveFourLineDescription_CometPunch[] = _("Hits 2 to 5 times.\nHas +1 priority.\nIron Fist boost."); // new
static const u8 sMoveFourLineDescription_MegaPunch[] = _("The foe is slugged\nby a punch with\ngreat power.\nIron Fist boost."); // new
static const u8 sMoveFourLineDescription_PayDay[] = _("Numerous coins are\nhurled at the foe.\nMoney is earned\nafter battle.");
static const u8 sMoveFourLineDescription_FirePunch[] = _("The foe is punched\nwith a fiery fist.\n10% burn chance.\nIron Fist boost."); // new
#if B_USE_FROSTBITE == TRUE
    static const u8 sMoveFourLineDescription_IcePunch[] = _("The foe is punched\nwith an icy fist.\n10% frostbite chance.\nIron Fist boost."); // new
#else
    static const u8 sMoveFourLineDescription_IcePunch[] = _("The foe is punched\nwith an icy fist.\n10% freeze chance.\nIron Fist boost."); // new
#endif
static const u8 sMoveFourLineDescription_ThunderPunch[] = _("A punch with an\nelectrified fist.\n10% paralyze chance.\nIron Fist boost."); // new
static const u8 sMoveFourLineDescription_Scratch[] = _("Hard, pointed, and\nsharp claws rake\nthe foe.");
static const u8 sMoveFourLineDescription_ViseGrip[] = _("Huge, impressive\npincers grip and\nsqueeze the foe.\nHigh crit ratio."); // new
static const u8 sMoveFourLineDescription_Guillotine[] = _("A vicious tearing\nattack with pincers.\nKeen Edge boost.\nHigh crit ratio."); // new
static const u8 sMoveFourLineDescription_RazorWind[] = _("Blades of wind hit\nthe foe on the 2nd\nturn. High crit.\nAir-based."); // new
static const u8 sMoveFourLineDescription_SwordsDance[] = _("A frenetic dance of\nfighting. It sharply\nraises the Attack\nstat.");
static const u8 sMoveFourLineDescription_Cut[] = _("Sharp Steel attack,\nalways crits.\nKeen Edge boost.\nField-based"); // new
static const u8 sMoveFourLineDescription_Gust[] = _("Strikes the foe\nwith a gust of wind\nwhipped up by\nwings. Air-based."); // new
static const u8 sMoveFourLineDescription_WingAttack[] = _("The foe is struck\nwith large, imposing\nwings spread wide.\nAir-based."); // new
static const u8 sMoveFourLineDescription_Whirlwind[] = _("The foe is made to\nswitch out with an\nally. In the wild,\nthe battle ends.");
static const u8 sMoveFourLineDescription_Fly[] = _("A 2-turn move.\nUse it to fly\nto any known town.\nAir-based."); // new
#if B_BINDING_TURNS >= GEN_5
static const u8 sMoveFourLineDescription_Bind[] = _("A long body or\ntentacles are used\nto bind the foe for\nfour or five turns.");
#else
static const u8 sMoveFourLineDescription_Bind[] = _("A long body or\ntentacles are used\nto bind the foe for\ntwo to five turns.");
#endif
static const u8 sMoveFourLineDescription_Slam[] = _("The foe is struck\nwith a long tail,\nvines, etc.");
static const u8 sMoveFourLineDescription_VineWhip[] = _("The foe is struck\nwith slender, whip-\nlike vines.\n30% flinch chance.");
static const u8 sMoveFourLineDescription_Stomp[] = _("Stomps the foe.\nHas 30% flinch\nchance. Striker\nboost."); // new
static const u8 sMoveFourLineDescription_DoubleKick[] = _("Kicks the foe\nquickly twice.\nStriker boost."); // new
static const u8 sMoveFourLineDescription_MegaKick[] = _("The foe is attacked\nby a kick with\ngreat power.\nStriker boost."); // new
static const u8 sMoveFourLineDescription_JumpKick[] = _("The user jumps up\nhigh, then kicks.\nHurts on miss.\nStriker boost."); // new
static const u8 sMoveFourLineDescription_RollingKick[] = _("A quick kick from a\nrolling spin.\n30% flinch chance.\nStriker boost."); // new
static const u8 sMoveFourLineDescription_SandAttack[] = _("A lot of sand is\nhurled in the foe's\nface, reducing its\naccuracy.");
static const u8 sMoveFourLineDescription_Headbutt[] = _("The user sticks its\nhead out and rams.\n30% flinch chance.\nField-based."); // new
static const u8 sMoveFourLineDescription_HornAttack[] = _("Jabs with sharply\npointed horn.\nHigh crit.\nMighty Horn boost."); // new
static const u8 sMoveFourLineDescription_FuryAttack[] = _("Hits 2-5x\nwith a horn or\nbeak. High crit.\nMighty Horn boost."); // new
static const u8 sMoveFourLineDescription_HornDrill[] = _("Ignores the target's\nability and stat\nchanges. High crit.\nMighty Horn boost."); // new
static const u8 sMoveFourLineDescription_Tackle[] = _("A physical attack\nin which the user\ncharges, full body,\ninto the foe.");
static const u8 sMoveFourLineDescription_BodySlam[] = _("The user drops its\nfull body on the\nfoe. 30% paralyze\nchance."); // new
#if B_BINDING_TURNS >= GEN_5
static const u8 sMoveFourLineDescription_Wrap[] = _("A long body or\nvines are used to\nwrap the foe for\nfour or five turns.");
#else
static const u8 sMoveFourLineDescription_Wrap[] = _("A long body or\nvines are used to\nwrap the foe for\ntwo to five turns.");
#endif
static const u8 sMoveFourLineDescription_TakeDown[] = _("A reckless, full-\nbody charge attack.\nHas 25% recoil\ndamage."); // new
static const u8 sMoveFourLineDescription_Thrash[] = _("The user rampages\nabout for two to\nthree turns, then\nbecomes confused.");
static const u8 sMoveFourLineDescription_DoubleEdge[] = _("A reckless, life-\nrisking tackle that\nalso has 33%\nrecoil damage."); // new
static const u8 sMoveFourLineDescription_TailWhip[] = _("The user wags its\ntail cutely, making\nthe foe lower its\nDefense stat.");
static const u8 sMoveFourLineDescription_PoisonSting[] = _("Quick and painful\nsting. Has 30%\npoison chance.\nHas +1 priority."); // new
static const u8 sMoveFourLineDescription_Twineedle[] = _("The foe is stabbed\ntwice with foreleg\nstingers. 50%\npoison chance."); // new
static const u8 sMoveFourLineDescription_PinMissile[] = _("Sharp pins are shot\nat the foe and hit\ntwo to five times\nat once.");
static const u8 sMoveFourLineDescription_Leer[] = _("The foe is given an\nintimidating look\nthat lowers its\nDefense stat.");
static const u8 sMoveFourLineDescription_Bite[] = _("The user bites with\nvicious fangs.\n30% flinch chance.\nStrong Jaw boost."); // new
static const u8 sMoveFourLineDescription_DragonFang[] = _("The user bites with\ndraconic fangs.\n30% flinch chance.\nStrong Jaw boost."); // new
static const u8 sMoveFourLineDescription_Growl[] = _("The user growls in\na cute way, making\nthe foe lower its\nAttack stat.");
static const u8 sMoveFourLineDescription_Roar[] = _("The foe is made to\nswitch out with an\nally. In the wild,\nthe battle ends.");
static const u8 sMoveFourLineDescription_Sing[] = _("A soothing song\nin a calming voice\nlulls the foe into\na deep slumber.");
static const u8 sMoveFourLineDescription_Supersonic[] = _("The user generates\nodd sound waves.\nIt confuses the\nfoe."); // new
static const u8 sMoveFourLineDescription_SonicBoom[] = _("The foe is hit with\na shock wave that\nalways inflicts 20-\nHP damage.");
static const u8 sMoveFourLineDescription_Disable[] = _("For a few turns,\nit prevents the foe\nfrom using the move\nit last used.");
static const u8 sMoveFourLineDescription_Acid[] = _("A harsh acid\nhits both foes.\n10% chance to\nlower SpDef."); // new
static const u8 sMoveFourLineDescription_Ember[] = _("The foe is attacked\nwith small flames.\n10% burn chance."); // new
static const u8 sMoveFourLineDescription_Flamethrower[] = _("The foe is scorched\nwith intense flames.\n10% burn chance."); // new
static const u8 sMoveFourLineDescription_Mist[] = _("The ally party is\nprotected by a\nmist that prevents\nstat reductions.");
static const u8 sMoveFourLineDescription_WaterGun[] = _("The foe is struck\nwith a lot of water\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_HydroPump[] = _("A high volume of\nwater is blasted at\nwith high pressure.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_Surf[] = _("A big wave crashes\ndown on the foe.\nField-based."); // new
static const u8 sMoveFourLineDescription_Blizzard[] = _("The foe is blasted\nwith a blizzard.\n10% frostbite chance.\nWeather-based."); // new
static const u8 sMoveFourLineDescription_IceBeam[] = _("The foe is struck\nwith an icy beam.\n10% frostbite chance.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_Psybeam[] = _("A peculiar ray is\nshot at the foe.\n10% confusion.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_BubbleBeam[] = _("A spray of bubbles\nstrikes the foe.\n10% speed drop.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_AuroraBeam[] = _("A rainbow-colored\nattack beam.\n100% attack drop.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_HyperBeam[] = _("Does severe\ndamage.\nNeeds recharging.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_GigaImpact[] = _("Does severe\ndamage.\nNeeds recharging."); // new
static const u8 sMoveFourLineDescription_Peck[] = _("Hits 2-5x with\na horn or beak.\nMighty Horn boost."); // new
static const u8 sMoveFourLineDescription_DrillPeck[] = _("A corkscrewing\nattack.\nHigh crit.\nMighty Horn boost."); // new
static const u8 sMoveFourLineDescription_Submission[] = _("A reckless, full-\nbody throw attack.\n50% recoil damage."); // new
static const u8 sMoveFourLineDescription_LowKick[] = _("Inflicts more\ndamage on\nheavier\nfoes.\nStriker boost."); // new
static const u8 sMoveFourLineDescription_Counter[] = _("A retaliation move\nthat counters any\nphysical hit with\ndouble the damage.");
static const u8 sMoveFourLineDescription_SeismicToss[] = _("A gravity-fed throw\nthat causes damage\nmatching the user's\nlevel.");
static const u8 sMoveFourLineDescription_Strength[] = _("The foe is slugged\nat maximum power.\nDrops Defenses.\nField-based."); // new
static const u8 sMoveFourLineDescription_Absorb[] = _("An attack that\nabsorbs half the\ndamage it inflicted\nto restore HP.");
static const u8 sMoveFourLineDescription_MegaDrain[] = _("A tough attack that\ndrains half the\ndamage it inflicted\nto restore HP.");
static const u8 sMoveFourLineDescription_LeechSeed[] = _("A seed is planted\non the foe to steal\nsome HP for the \nuser on every turn.");
static const u8 sMoveFourLineDescription_Growth[] = _("The user's body is\nforced to grow,\nraising its Atk.\nand Sp. Atk stat.");
static const u8 sMoveFourLineDescription_RazorLeaf[] = _("Both foes are hit\nwith a cutting leaf.\nAlways crits.\nKeen Edge boost."); // new
static const u8 sMoveFourLineDescription_SolarBeam[] = _("Strong 2-turn move.\nWeather-based.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_PoisonPowder[] = _("A cloud of toxic\ndust is scattered.\nIt poisons the\nfoe."); // new
static const u8 sMoveFourLineDescription_StunSpore[] = _("Paralyzing dust is\nscattered wildly.\nIt paralyzes\nthe foe."); // new
static const u8 sMoveFourLineDescription_SleepPowder[] = _("A sleep-inducing\ndust is scattered\nin high volume\naround a foe.");
static const u8 sMoveFourLineDescription_PetalDance[] = _("The user attacks\nwith petals for two\nto three turns,\nthen gets confused.");
static const u8 sMoveFourLineDescription_StringShot[] = _("The foe is bound\nwith strings shot\nfrom the mouth to\nreduce its Speed.");
static const u8 sMoveFourLineDescription_DragonRage[] = _("The foe is hit with\na shock wave that\nalways inflicts 40-\nHP damage.");
#if B_BINDING_TURNS >= GEN_5
static const u8 sMoveFourLineDescription_FireSpin[] = _("The foe is trapped\nin an intense spiral\nof fire that rages\nfour or five turns.");
#else
static const u8 sMoveFourLineDescription_FireSpin[] = _("The foe is trapped\nin an intense spiral\nof fire that rages\ntwo to five turns.");
#endif
static const u8 sMoveFourLineDescription_ThunderShock[] = _("An electric shock\nattack with a 10%\nparalyze chance."); // new
static const u8 sMoveFourLineDescription_Thunderbolt[] = _("A strong electrical\nattack with a\n10% paralyze\nchance."); // new
static const u8 sMoveFourLineDescription_ThunderWave[] = _("A weak electric\nshock that is sure\nto cause paralysis\nif it hits.");
static const u8 sMoveFourLineDescription_Thunder[] = _("A brutal lightning\nattack. 30%\nparalyze chance.\nWeather-based."); // new
static const u8 sMoveFourLineDescription_RockThrow[] = _("The foe is attacked\nwith a shower of\nsmall, easily\nthrown rocks.");
static const u8 sMoveFourLineDescription_Earthquake[] = _("An earthquake that\nstrikes all Pokémon\nin battle excluding\nthe user.");
static const u8 sMoveFourLineDescription_Fissure[] = _("The foe is dropped\ninto a fissure.\nHits both foes."); // new
static const u8 sMoveFourLineDescription_Dig[] = _("An attack that hits\non the 2nd turn.\nField-based."); // new
static const u8 sMoveFourLineDescription_Toxic[] = _("A move that badly\npoisons the foe.\nIts poison damage\nworsens every turn.");
static const u8 sMoveFourLineDescription_Confusion[] = _("A weak telekinetic\nattack with a\n10% confusion\nchance."); // new
static const u8 sMoveFourLineDescription_Psychic[] = _("A strong telekinetic\nattack. 10%\nchance to drop\nfoe's SpDef stat."); // new
static const u8 sMoveFourLineDescription_Hypnosis[] = _("Hypnotic suggestion\nis used to make the\nfoe fall into a\ndeep sleep.");
static const u8 sMoveFourLineDescription_Meditate[] = _("The user meditates\nto awaken its power\nand raise its\nAttack stat.");
static const u8 sMoveFourLineDescription_Agility[] = _("The user relaxes\nand lightens its\nbody to sharply\nboost its Speed.");
static const u8 sMoveFourLineDescription_QuickAttack[] = _("An almost invisibly\nfast attack with\n+1 priority."); // new
static const u8 sMoveFourLineDescription_Rage[] = _("An attack that\nbecomes stronger\neach time the user\nis hit in battle.");
static const u8 sMoveFourLineDescription_Teleport[] = _("Use it to flee from\nany wild Pokémon.\nAlso warps to the\nlast POKé CENTER.");
static const u8 sMoveFourLineDescription_NightShade[] = _("An attack with a\nmirage that inflicts\ndamage matching\nthe user's level.");
static const u8 sMoveFourLineDescription_Mimic[] = _("The user copies the\nmove last used by\nthe foe for the\nrest of the battle.");
static const u8 sMoveFourLineDescription_Screech[] = _("An ear-splitting\nscreech is emitted\nto sharply reduce\nthe foe's Defense.");
static const u8 sMoveFourLineDescription_DoubleTeam[] = _("The user creates\nillusory copies of\nitself to raise its\nevasiveness.");
static const u8 sMoveFourLineDescription_Recover[] = _("A self-healing move\nthat restores HP by\nup to half of the\nuser's maximum HP.");
static const u8 sMoveFourLineDescription_Harden[] = _("The user stiffens\nall the muscles in\nits body to raise\nits Defense stat.");
static const u8 sMoveFourLineDescription_Minimize[] = _("The user compresses\nall the cells in its\nbody to raise its\nevasiveness.");
static const u8 sMoveFourLineDescription_Smokescreen[] = _("An obscuring cloud\nof smoke or ink\nreduces the foe's\naccuracy.");
static const u8 sMoveFourLineDescription_ConfuseRay[] = _("The foe is exposed\nto a sinister ray\nthat triggers\nconfusion.");
static const u8 sMoveFourLineDescription_Withdraw[] = _("The user withdraws\nits body in its hard\nshell, raising its\nDefense stat.");
static const u8 sMoveFourLineDescription_DefenseCurl[] = _("The user curls up\nto conceal weak\nspots and raise its\nDefense stat.");
static const u8 sMoveFourLineDescription_Barrier[] = _("The user creates a\nsturdy wall that\nsharply raises its\nDefense stat.");
static const u8 sMoveFourLineDescription_LightScreen[] = _("A wall of light\ncuts damage from\nSp. Atk attacks\nfor five turns.");
static const u8 sMoveFourLineDescription_Haze[] = _("Eliminates all stat\nchanges among all\nPokémon engaged in\nbattle.");
static const u8 sMoveFourLineDescription_Reflect[] = _("A wall of light\ncuts damage from\nphysical attacks\nfor five turns.");
static const u8 sMoveFourLineDescription_FocusEnergy[] = _("The user takes a\ndeep breath and\nfocuses to raise its\ncritical-hit ratio.");
static const u8 sMoveFourLineDescription_Bide[] = _("The user endures\nattacks for two\nturns, then strikes\nback double.");
static const u8 sMoveFourLineDescription_Metronome[] = _("Waggles a finger\nand stimulates the\nbrain into using any\nmove at random.");
static const u8 sMoveFourLineDescription_MirrorMove[] = _("The user counters\nthe move last used\nby the foe with the\nsame move.");
static const u8 sMoveFourLineDescription_SelfDestruct[] = _("The user blows up\nto inflict severe\ndamage, even\nmaking itself faint.");
static const u8 sMoveFourLineDescription_EggBomb[] = _("A large egg is\nhurled with great\nforce. 10%\nburn chance."); // new
static const u8 sMoveFourLineDescription_Lick[] = _("The foe is licked\nand hit with a long\ntongue. 30%\nparalyze chance."); // new
static const u8 sMoveFourLineDescription_Smog[] = _("The foe is attacked\nwith exhaust gases.\n50% poison\nchance."); // new
static const u8 sMoveFourLineDescription_Sludge[] = _("Toxic sludge is\nhurled at the foe.\n30% poison\nchance."); // new
static const u8 sMoveFourLineDescription_BoneClub[] = _("The foe is clubbed\nwith a bone.\n30% flinch chance."); // new
static const u8 sMoveFourLineDescription_FireBlast[] = _("The foe is hit with\nan intense flame.\nIt has a 20%\nburn chance."); // new
static const u8 sMoveFourLineDescription_Waterfall[] = _("A powerful charge\nattack. 20%\nflinch chance.\nField-based."); // new
#if B_BINDING_TURNS >= GEN_5
static const u8 sMoveFourLineDescription_Clamp[] = _("The foe is clamped\nand squeezed by\nthe user's shell for\nfour or five turns.");
#else
static const u8 sMoveFourLineDescription_Clamp[] = _("The foe is clamped\nand squeezed by\nthe user's shell for\ntwo to five turns.");
#endif
static const u8 sMoveFourLineDescription_Swift[] = _("Star-shaped rays\nthat never miss are\nfired at all foes in\nbattle.");
static const u8 sMoveFourLineDescription_SkullBash[] = _("The user raises its\nDefense in the 1st\nturn, then attacks\nin the 2nd turn.");
static const u8 sMoveFourLineDescription_SpikeCannon[] = _("Sharp spikes are\nfired two to\nfive times.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_Constrict[] = _("The foe is attacked\nwith long tentacles\nor vines. Lowers\nfoe's Speed."); // new
static const u8 sMoveFourLineDescription_Amnesia[] = _("Forgets about\nsomething and\nsharply raises\nSp. Def.");
static const u8 sMoveFourLineDescription_Kinesis[] = _("The user distracts\nthe foe by bending\na spoon. It\nlowers accuracy."); // new
static const u8 sMoveFourLineDescription_SoftBoiled[] = _("Heals the user by\nup to half its full\nHP. It can be used\nto heal an ally.");
static const u8 sMoveFourLineDescription_HighJumpKick[] = _("A strong jumping\nknee kick.\nHurts on miss.\nStriker boost."); // new
static const u8 sMoveFourLineDescription_Glare[] = _("The user intimidates\nthe foe with the\ndesign on its belly\nto cause paralysis.");
static const u8 sMoveFourLineDescription_DreamEater[] = _("Absorbs half the\ndamage it inflicted\non a sleeping foe\nto restore HP.");
static const u8 sMoveFourLineDescription_PoisonGas[] = _("Sprays with a cloud\nof toxic gas that\npoisons all foes."); // new
static const u8 sMoveFourLineDescription_Barrage[] = _("Round objects are\nhurled at the foe\nto strike two to\nfive times.");
static const u8 sMoveFourLineDescription_LeechLife[] = _("An attack that\nabsorbs half the\ndamage it inflicted.\nStrong Jaw boost."); // new
static const u8 sMoveFourLineDescription_LovelyKiss[] = _("The user forces a\nkiss on the foe\nwith a scary face\nthat induces sleep.");
static const u8 sMoveFourLineDescription_SkyAttack[] = _("A 2nd-turn attack\nmove with a high\ncritical-hit ratio.\n30% flinch chance."); // new
static const u8 sMoveFourLineDescription_Transform[] = _("The user transforms\ninto a copy of the\nfoe with even the\nsame move set.");
static const u8 sMoveFourLineDescription_Bubble[] = _("A spray of bubbles\nhits both foes.\n100% chance to\ndrop foe's Speed."); // new
static const u8 sMoveFourLineDescription_DizzyPunch[] = _("The foe is hit with\na rhythmic punch.\n20% confusion\nchance."); // new
static const u8 sMoveFourLineDescription_Spore[] = _("The user scatters\nbursts of fine\nspores that induce\nsleep.");
static const u8 sMoveFourLineDescription_Flash[] = _("A blast of light\nthat has 50% chance\nto drop foe's Atk.\nField-based."); // new
static const u8 sMoveFourLineDescription_Psywave[] = _("A quick wave of\npsychic energy.\n+1 priority. 30%\nconfusion chance."); // new
static const u8 sMoveFourLineDescription_Splash[] = _("The user just flops\nand splashes around\nwithout having any\neffect.");
static const u8 sMoveFourLineDescription_AcidArmor[] = _("The user alters its\ncells to liquefy\nitself and sharply\nraise Defense.");
static const u8 sMoveFourLineDescription_Crabhammer[] = _("A large pincer is\nused to hammer the\nfoe. It has a high\ncritical-hit ratio.");
static const u8 sMoveFourLineDescription_Explosion[] = _("The user explodes\nto inflict terrible\ndamage even while\nfainting itself.");
static const u8 sMoveFourLineDescription_FurySwipes[] = _("Hits 2-5x\nwith sharp claws or\nscythes. Has a\nhigh crit ratio."); // new
static const u8 sMoveFourLineDescription_Bonemerang[] = _("The user throws a\nbone that hits the\nfoe once, then once\nagain on return.");
static const u8 sMoveFourLineDescription_Rest[] = _("The user sleeps for\ntwo turns to fully\nrestore HP and heal\nany status problem.");
static const u8 sMoveFourLineDescription_RockSlide[] = _("Large boulders are\nhurled at the foe.\n20% flinch chance."); // new
static const u8 sMoveFourLineDescription_HyperFang[] = _("The foe is attacked\nwith sharp fangs.\n30% flinch chance.\nStrong Jaw boost."); // new
static const u8 sMoveFourLineDescription_Sharpen[] = _("The user reduces\nits polygon count\nto sharpen edges\nand raise Attack.");
static const u8 sMoveFourLineDescription_Conversion[] = _("The user changes\nits type to match\nthe type of one of\nits moves.");
static const u8 sMoveFourLineDescription_TriAttack[] = _("A simultaneous\n3-beam attack. 30%\nchance to paralyze,\nburn or frostbite foes."); // new
static const u8 sMoveFourLineDescription_SuperFang[] = _("The user attacks\nwith sharp fangs\nand halves the\nfoe's HP.");
static const u8 sMoveFourLineDescription_Slash[] = _("The foe is slashed\nwith claws, etc.\nHigh crit.\nKeen Edge boost."); // new
static const u8 sMoveFourLineDescription_Substitute[] = _("The user creates a\ndecoy using one-\nquarter of its full\nHP.");
static const u8 sMoveFourLineDescription_Struggle[] = _("An attack that is\nused only if there\nis no PP. It also\nhurts the user.");
static const u8 sMoveFourLineDescription_Sketch[] = _("This move copies\nthe move last used\nby the foe, then\ndisappears.");
static const u8 sMoveFourLineDescription_TripleKick[] = _("A 3-kick attack.\nMore powerful with\neach successive hit.\nStriker boost."); // new
static const u8 sMoveFourLineDescription_Thief[] = _("An attack that may\ntake the foe's held\nitem if the user\nisn't holding one.");
static const u8 sMoveFourLineDescription_SpiderWeb[] = _("Ensnares the foe \nwith sticky string\nso it doesn't flee\nor switch out.");
static const u8 sMoveFourLineDescription_MindReader[] = _("The user predicts\nthe foe's action to\nensure its next\nattack hits.");
static const u8 sMoveFourLineDescription_Nightmare[] = _("A sleeping foe is\nshown a nightmare\nthat inflicts some\ndamage every turn.");
static const u8 sMoveFourLineDescription_FlameWheel[] = _("The user makes a\nfiery charge at the\nfoe. 10%\nburn chance."); // new
static const u8 sMoveFourLineDescription_Snore[] = _("An attack that can\nbe used only while\nasleep. Has a\n30% flinch chance."); // new
static const u8 sMoveFourLineDescription_Curse[] = _("A move that works\ndifferently for the\nGHOST-type and all\nthe other types.");
static const u8 sMoveFourLineDescription_Flail[] = _("A desperate attack\nthat becomes more\npowerful the less\nHP the user has.");
static const u8 sMoveFourLineDescription_Conversion2[] = _("The user changes\ntype to make itself\nresistant to the\nlast attack it took.");
static const u8 sMoveFourLineDescription_Aeroblast[] = _("A vortex of air is\nshot at the foe.\nHigh crit ratio.\nAir-based."); // new
static const u8 sMoveFourLineDescription_CottonSpore[] = _("Cotton-like spores\ncling to the foe,\nsharply reducing\nits Speed stat.");
static const u8 sMoveFourLineDescription_Reversal[] = _("An all-out attack\nthat becomes more\npowerful the less\nHP the user has.");
static const u8 sMoveFourLineDescription_Spite[] = _("A move that cuts\n2 to 5 PP from the\nmove last used by\nthe foe.");
static const u8 sMoveFourLineDescription_PowderSnow[] = _("Blasts the foe with\na snowy gust.\n30% chance to\nfrostbite the foe."); // new
static const u8 sMoveFourLineDescription_Protect[] = _("Enables the user to\nevade all attacks.\nIt may fail if used\nin succession.");
static const u8 sMoveFourLineDescription_MachPunch[] = _("A punch thrown at\nblinding speed.\n+1 priority.\nIron Fist boost."); // new
static const u8 sMoveFourLineDescription_ScaryFace[] = _("Frightens the foe\nwith a scary face\nto sharply reduce\nits Speed.");
static const u8 sMoveFourLineDescription_FeintAttack[] = _("The user draws up\nclose to the foe\ndisarmingly, then\nhits without fail.");
static const u8 sMoveFourLineDescription_SweetKiss[] = _("The user kisses\nthe foe with sweet\ncuteness that\ncauses confusion.");
static const u8 sMoveFourLineDescription_BellyDrum[] = _("The user maximizes\nits Attack stat at\nthe cost of half\nits full HP.");
static const u8 sMoveFourLineDescription_SludgeBomb[] = _("Filthy sludge is\nhurled at the foe.\n30% poison\nchance."); // new
static const u8 sMoveFourLineDescription_MudSlap[] = _("Mud is hurled in\nthe foe's face to\ninflict damage and\nlower its accuracy.");
static const u8 sMoveFourLineDescription_Octazooka[] = _("Ink is blasted in\nthe foe's face.\nLowers accuracy.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_Spikes[] = _("A trap of spikes is\nlaid around the\nfoe's party to hurt\nfoes switching in.");
static const u8 sMoveFourLineDescription_ZapCannon[] = _("An electric blast is\nfired like a cannon.\nAlways paralyzes.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_Foresight[] = _("Completely negates\nthe foe's efforts to\nheighten its ability\nto evade.");
static const u8 sMoveFourLineDescription_DestinyBond[] = _("If the user faints,\nthe foe delivering\nthe final hit also\nfaints.");
static const u8 sMoveFourLineDescription_PerishSong[] = _("Any battler that\nhears this faints\nin three turns\nunless it switches.");
static const u8 sMoveFourLineDescription_IcyWind[] = _("A chilling wind is\nused to attack.\nLowers foe's Speed.\nAir-based."); // new
static const u8 sMoveFourLineDescription_Detect[] = _("Enables the user to\nevade all attacks.\nIt may fail if used\nin succession.");
static const u8 sMoveFourLineDescription_BoneRush[] = _("The user strikes\ntwo to five times.\n+1 priority."); // new
static const u8 sMoveFourLineDescription_LockOn[] = _("The user locks on\nto the foe, making\nthe next move sure\nto hit.");
static const u8 sMoveFourLineDescription_Outrage[] = _("The user thrashes\nabout for two to\nthree turns, then\nbecomes confused.");
static const u8 sMoveFourLineDescription_Sandstorm[] = _("A 5-turn sandstorm\nthat damages all\ntypes except Rock,\nGround, and Steel.");
static const u8 sMoveFourLineDescription_GigaDrain[] = _("A harsh attack that\nabsorbs half the\ndamage it inflicted\nto restore HP.");
static const u8 sMoveFourLineDescription_Endure[] = _("The user endures\nany hit with 1 HP\nleft. It may fail if\nused in succession.");
static const u8 sMoveFourLineDescription_Charm[] = _("The foe is charmed\nby the user's cute\nappeals, sharply\ncutting its Attack.");
static const u8 sMoveFourLineDescription_Rollout[] = _("A 5-turn rolling\nattack that becomes\nstronger each time\nit hits.");
static const u8 sMoveFourLineDescription_FalseSwipe[] = _("Always leaves the\nfoe with at\nleast 1 HP.\nKeen Edge boost."); // new
static const u8 sMoveFourLineDescription_Swagger[] = _("A move that makes\nthe foe confused,\nbut also sharply\nraises its Attack.");
static const u8 sMoveFourLineDescription_MilkDrink[] = _("Heals the user by\nup to half its full\nHP. It can be used\nto heal an ally.");
static const u8 sMoveFourLineDescription_Spark[] = _("Rapid electrical\ntackle. Has 10%\nparalyze chance.\nHas +2 priority."); // new
static const u8 sMoveFourLineDescription_FuryCutter[] = _("Doubles power on\neach successive hit.\nMax 160 base power.\nKeen Edge boost."); // new
static const u8 sMoveFourLineDescription_SteelWing[] = _("Hits with wings\nof steel. 20% chance\nto raise Defense.\nAir-based."); // new
static const u8 sMoveFourLineDescription_MeanLook[] = _("The foe is fixed\nwith a mean look\nthat prevents it\nfrom escaping.");
static const u8 sMoveFourLineDescription_Attract[] = _("Inflicts infatuation\non opposite gender\nwhich halves\nAtk and SpAtk."); // new
static const u8 sMoveFourLineDescription_SleepTalk[] = _("While asleep, the\nuser randomly uses\none of the moves it\nknows.");
static const u8 sMoveFourLineDescription_HealBell[] = _("A soothing bell\nchimes to heal the\nstatus problems of\nall allies.");
static const u8 sMoveFourLineDescription_Return[] = _("A strong and reliable\nNormal-type attack.");
static const u8 sMoveFourLineDescription_Present[] = _("The foe is given a\nbooby-trapped gift.\nIt restores HP\nsometimes, however.");
static const u8 sMoveFourLineDescription_Frustration[] = _("A strong and reliable\nDark-type attack.");
static const u8 sMoveFourLineDescription_Safeguard[] = _("It protects the\nuser's party from\nall status problems\nfor five turns.");
static const u8 sMoveFourLineDescription_PainSplit[] = _("The user adds its\nHP to the foe's HP,\nthen equally shares\nthe total HP.");
static const u8 sMoveFourLineDescription_SacredFire[] = _("A mystical and\npowerful fire\nattack that always\ninflicts a burn."); // new
static const u8 sMoveFourLineDescription_Magnitude[] = _("A ground-shaking\nattack against all\nstanding Pokémon.\nIts power varies.");
static const u8 sMoveFourLineDescription_DynamicPunch[] = _("The foe is punched\nwith the user's full\npower. It confuses\nthe foe if it hits.");
static const u8 sMoveFourLineDescription_Megahorn[] = _("A brutal ramming\nattack. Ignores foe's\nstat changes.\nMighty Horn boost."); // new
static const u8 sMoveFourLineDescription_DragonBreath[] = _("The foe is hit with\nan incredible blast.\n30% burn chance."); // new
static const u8 sMoveFourLineDescription_BatonPass[] = _("The user switches\nout, passing along\nany stat changes\nto the new battler.");
static const u8 sMoveFourLineDescription_Encore[] = _("Makes the foe use\nthe move it last\nused repeatedly for\ntwo to six turns.");
static const u8 sMoveFourLineDescription_Pursuit[] = _("An attack move that\nworks especially\nwell on a foe that\nis switching out.");
static const u8 sMoveFourLineDescription_RapidSpin[] = _("Frees the user from\nBind, Leech Seed,\nSpikes etc.\nUps Speed by +1."); // new
static const u8 sMoveFourLineDescription_SweetScent[] = _("Allures the foe to\nreduce evasiveness.\nIt also attracts\nwild Pokémon.");
static const u8 sMoveFourLineDescription_IronTail[] = _("An attack with a\nsteel-hard tail.\n30% chance to\nlower foe's Defense."); // new
static const u8 sMoveFourLineDescription_MetalClaw[] = _("The foe is attacked\nwith steel claws.\n20% chance to raise\nthe user's Attack."); // new
static const u8 sMoveFourLineDescription_VitalThrow[] = _("Makes the user\nattack after the\nfoe. In return,\nit will not miss.");
static const u8 sMoveFourLineDescription_MorningSun[] = _("Restores the user's\nHP. The amount of\nHP regained varies\nwith the weather.");
static const u8 sMoveFourLineDescription_Synthesis[] = _("Restores the user's\nHP. The amount of\nHP regained varies\nwith the weather.");
static const u8 sMoveFourLineDescription_Moonlight[] = _("Restores the user's\nHP. The amount of\nHP regained varies\nwith the weather.");
static const u8 sMoveFourLineDescription_HiddenPower[] = _("An attack that\nvaries in type and\nintensity depending\non the user.");
static const u8 sMoveFourLineDescription_CrossChop[] = _("The foe is hit with\ndouble chops.\nIt has a high\ncritical-hit ratio.");
static const u8 sMoveFourLineDescription_Twister[] = _("A vicious twister\nattacks the foe.\n20% flinch chance.\nAir-based."); // new
static const u8 sMoveFourLineDescription_RainDance[] = _("A heavy rain falls\nfor five turns,\npowering up Water-\ntype moves 50%."); // new
static const u8 sMoveFourLineDescription_SunnyDay[] = _("The sun blazes for\nfive turns, powering\nup Fire-type\nmoves by 50%."); // new
#if B_UPDATED_MOVE_DATA >= GEN_4
static const u8 sMoveFourLineDescription_Crunch[] = _("The foe is crunched\nwith sharp fangs.\n20% chance to\nlower foe's Def."); // new
#else
static const u8 sMoveFourLineDescription_Crunch[] = _("The foe is crunched\nwith sharp fangs.\n20% chance to\nlower foe's SpDef."); // new
#endif
static const u8 sMoveFourLineDescription_MirrorCoat[] = _("A retaliation move\nthat pays back the\nfoe's special attack\ndouble.");
static const u8 sMoveFourLineDescription_PsychUp[] = _("The user hypnotizes\nitself into copying\nany stat change\nmade by the foe.");
static const u8 sMoveFourLineDescription_ExtremeSpeed[] = _("A blindingly speedy\ncharge attack with\n+2 priority."); // new
static const u8 sMoveFourLineDescription_AncientPower[] = _("An ancient power is\nused to attack. 10%\nchance to raise all\nthe user's stats."); // new
static const u8 sMoveFourLineDescription_ShadowBall[] = _("A shadowy blob is\nhurled at the foe.\n20% chance to\nlower foe's SpDef."); // new
static const u8 sMoveFourLineDescription_FutureSight[] = _("Two turns after\nthis move is used,\nthe foe is attacked\npsychically.");
static const u8 sMoveFourLineDescription_RockSmash[] = _("An attack which also\ncuts foe's Defense.\nIt can also smash\ncracked boulders."); // new
#if B_BINDING_TURNS >= GEN_5
static const u8 sMoveFourLineDescription_Whirlpool[] = _("The foe is trapped\nfor four or\nfive turns.\nField-based."); // new
#else
static const u8 sMoveFourLineDescription_Whirlpool[] = _("The foe is trapped\nin a fast, vicious\nwhirlpool for two\nto five turns.");
#endif
static const u8 sMoveFourLineDescription_BeatUp[] = _("All party Pokémon\njoin in the attack.\nThe more allies,\nthe more damage.");
static const u8 sMoveFourLineDescription_FakeOut[] = _("An attack that hits\nfirst and causes\nflinching. Usable\nonly on 1st turn.");
static const u8 sMoveFourLineDescription_Uproar[] = _("The user attacks in\nan uproar that\nprevents sleep for\ntwo to five turns.");
static const u8 sMoveFourLineDescription_Stockpile[] = _("The user charges\nup power for use\nlater. It can be\nused three times.");
static const u8 sMoveFourLineDescription_SpitUp[] = _("The power built\nusing Stockpile is\nreleased at once\nfor attack.");
static const u8 sMoveFourLineDescription_Swallow[] = _("The energy it built\nusing Stockpile is\nabsorbed to restore\nHP.");
static const u8 sMoveFourLineDescription_HeatWave[] = _("The user exhales a\nheated breath. 10%\nburn chance.\nAir-based."); // new
static const u8 sMoveFourLineDescription_Hail[] = _("A hailstorm lasting\nfive turns damages\nall Pokémon except\nthe Ice-type.");
static const u8 sMoveFourLineDescription_Torment[] = _("It enrages the foe,\nmaking it incapable\nof using the same\nmove successively.");
static const u8 sMoveFourLineDescription_Flatter[] = _("Flattery is used to\nconfuse the foe,\nbut its Sp. Atk\nalso rises.");
static const u8 sMoveFourLineDescription_WillOWisp[] = _("A sinister, bluish\nwhite flame is shot\nat the foe to\ninflict a burn.");
static const u8 sMoveFourLineDescription_Memento[] = _("The user faints,\nbut sharply lowers\nthe foe's Attack\nand Sp. Atk.");
static const u8 sMoveFourLineDescription_Facade[] = _("An attack that is\nboosted if user is\nburned, poisoned,\nor paralyzed.");
static const u8 sMoveFourLineDescription_FocusPunch[] = _("Moves last.\nThe user flinches\nif hit beforehand.\nIron Fist boost."); // new
static const u8 sMoveFourLineDescription_SmellingSalts[] = _("Doubly effective on\na paralyzed foe,\nbut it also cures\nthe foe's paralysis.");
static const u8 sMoveFourLineDescription_FollowMe[] = _("The user draws\nattention to itself,\nmaking foes attack\nonly the user.");
static const u8 sMoveFourLineDescription_NaturePower[] = _("An attack that\nchanges type\ndepending on the\nuser's location.");
static const u8 sMoveFourLineDescription_Charge[] = _("The user charges\npower to boost the\nElectric move it\nuses next.");
static const u8 sMoveFourLineDescription_Taunt[] = _("The foe is taunted\ninto a rage that\nallows it to use\nonly attack moves.");
static const u8 sMoveFourLineDescription_HelpingHand[] = _("A move that boosts\nthe power of the\nally's attack in a\nbattle.");
static const u8 sMoveFourLineDescription_Trick[] = _("A move that tricks\nthe foe into\ntrading held items\nwith the user.");
static const u8 sMoveFourLineDescription_RolePlay[] = _("The user mimics the\nfoe completely and\ncopies the foe's\nability.");
static const u8 sMoveFourLineDescription_Wish[] = _("A self-healing move\nthat restores half\nthe full HP on the\nnext turn.");
static const u8 sMoveFourLineDescription_Assist[] = _("The user randomly\npicks and uses a\nmove of an allied\nPokémon.");
static const u8 sMoveFourLineDescription_Ingrain[] = _("The user lays roots\nthat restore HP on\nevery turn.\nIt can't switch out.");
static const u8 sMoveFourLineDescription_Superpower[] = _("A powerful attack,\nbut it also lowers\nthe user's Attack\nand Defense stats.");
static const u8 sMoveFourLineDescription_MagicCoat[] = _("Reflects back the\nfoe's Leech Seed\nand any status-\ndamaging move.");
static const u8 sMoveFourLineDescription_Recycle[] = _("A move that\nrecycles a used\nitem for use once\nmore.");
static const u8 sMoveFourLineDescription_Revenge[] = _("An attack move that\ngains in intensity if\nthe target has hurt\nthe user.");
static const u8 sMoveFourLineDescription_BrickBreak[] = _("An attack that also\nbreaks any barrier\nlike Light Screen\nand Reflect.");
static const u8 sMoveFourLineDescription_Yawn[] = _("A huge yawn lulls\nthe foe into falling\nasleep on the next\nturn.");
static const u8 sMoveFourLineDescription_KnockOff[] = _("Knocks down the\nfoe's held item to\nprevent its use\nduring the battle.");
static const u8 sMoveFourLineDescription_Endeavor[] = _("Gains power the\nfewer HP the user\nhas compared with\nthe foe.");
static const u8 sMoveFourLineDescription_Eruption[] = _("The higher the\nuser's HP, the more\npowerful it is.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_SkillSwap[] = _("The user employs\nits psychic power\nto swap abilities\nwith the foe.");
static const u8 sMoveFourLineDescription_Imprison[] = _("Prevents foes from\nusing any move\nthat is also known\nby the user.");
static const u8 sMoveFourLineDescription_Refresh[] = _("A self-healing move\nthat cures the user\nof a poisoning,\nburn, or paralysis.");
static const u8 sMoveFourLineDescription_Grudge[] = _("If the user faints,\nthis move deletes\nthe PP of the move\nthat finished it.");
static const u8 sMoveFourLineDescription_Snatch[] = _("Steals the effects\nof the foe's\nhealing or status-\nchanging move.");
static const u8 sMoveFourLineDescription_SecretPower[] = _("May have an additional\neffect that varies\nwith the terrain.\nField-based."); // new
static const u8 sMoveFourLineDescription_Dive[] = _("The user dives\nunderwater and\nhits next turn.\nField-based."); // new
static const u8 sMoveFourLineDescription_ArmThrust[] = _("Straigh-arm punches\nthat hit\ntwo to five times.\nHigh crit ratio."); // new
static const u8 sMoveFourLineDescription_Camouflage[] = _("Alters the user's\ntype depending on\nthe location's\nterrain.");
static const u8 sMoveFourLineDescription_TailGlow[] = _("The user flashes a\nlight that raises\nits Sp. Atk\nstat by +3."); // new
static const u8 sMoveFourLineDescription_LusterPurge[] = _("A burst of light\ninjures the foe. Has\n50% chance to lower\nthe foe's SpDef."); // new
static const u8 sMoveFourLineDescription_MistBall[] = _("A flurry of down\nhits the foe. Has\n50% chance to lower\nthe foe's SpAtk."); // new
static const u8 sMoveFourLineDescription_FeatherDance[] = _("The foe is covered\nwith a mass of down\nthat sharply cuts\nthe Attack stat.");
static const u8 sMoveFourLineDescription_TeeterDance[] = _("A wobbly dance\nthat confuses all\nthe Pokémon in\nbattle.");
static const u8 sMoveFourLineDescription_BlazeKick[] = _("A fiery kick with a\nhigh crit ratio.\n10% burn chance.\nStriker boost."); // new
static const u8 sMoveFourLineDescription_MudSport[] = _("Weakens Electric-\ntype attacks while\nthe user is in the\nbattle.");
static const u8 sMoveFourLineDescription_IceBall[] = _("A 5-turn rolling\nattack that becomes\nstronger each time\nit rolls.");
static const u8 sMoveFourLineDescription_NeedleArm[] = _("An attack using\nthorny arms.\n30% flinch chance."); // new
static const u8 sMoveFourLineDescription_SlackOff[] = _("The user slacks off\nand restores its HP\nby half its full\nHP.");
static const u8 sMoveFourLineDescription_HyperVoice[] = _("The user lets loose\na horribly loud\nshout with the\npower to damage.");
static const u8 sMoveFourLineDescription_PoisonFang[] = _("The foe is bitten\nwith toxic fangs.\n50% poison chance.\nStrong Jaw boost."); // new
static const u8 sMoveFourLineDescription_CrushClaw[] = _("The foe is attacked\nwith sharp claws.\n50% chance to\nlower foe's Defense."); // new
static const u8 sMoveFourLineDescription_BlastBurn[] = _("The foe is hit with\na huge explosion.\nNeeds recharging.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_HydroCannon[] = _("The foe is hit with\na watery cannon.\nNeeds recharging.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_MeteorMash[] = _("Hard, fast punch.\n20% chance to\nraise user's Attack.\nIron Fist boost."); // new
static const u8 sMoveFourLineDescription_Astonish[] = _("An attack using a\nstartling shout.\n30% flinch chance."); // new
static const u8 sMoveFourLineDescription_WeatherBall[] = _("Varies in power and\ntype depending on\nthe weather.\nWeather-based."); // new
static const u8 sMoveFourLineDescription_Aromatherapy[] = _("A soothing scent is\nreleased to heal\nall status problems\nin the user's party."); // Reference
static const u8 sMoveFourLineDescription_FakeTears[] = _("The user feigns\ncrying to sharply\nlower the foe's\nSp. Def stat.");
static const u8 sMoveFourLineDescription_AirCutter[] = _("The foe is hit with\nrazor-like wind.\nHigh crit ratio.\nAir-based."); // new
static const u8 sMoveFourLineDescription_Overheat[] = _("An intense attack\nthat also sharply\nreduces the user's\nSp. Atk stat.");
static const u8 sMoveFourLineDescription_OdorSleuth[] = _("Completely negates\nthe foe's efforts to\nheighten its ability\nto evade.");
static const u8 sMoveFourLineDescription_RockTomb[] = _("Boulders are hurled\nat the foe. It also\nlowers the foe's\nSpeed if it hits.");
static const u8 sMoveFourLineDescription_SilverWind[] = _("Attacks with\nsilver dust. 10%\nchance to raise all\nstats. Weather-based."); // new
static const u8 sMoveFourLineDescription_MetalSound[] = _("A horrible metallic\nscreech is used to\nsharply lower the\nfoe's Sp. Def.");
static const u8 sMoveFourLineDescription_GrassWhistle[] = _("A pleasant melody\nis played to lull\nthe foe into a deep\nsleep.");
static const u8 sMoveFourLineDescription_Tickle[] = _("The foe is made to\nlaugh, reducing its\nAttack and Defense\nstats.");
static const u8 sMoveFourLineDescription_CosmicPower[] = _("The user absorbs a\nmystic power to\nraise its Defense\nand Sp. Def.");
static const u8 sMoveFourLineDescription_WaterSpout[] = _("The higher the\nuser's HP, the more\npowerful it is.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_SignalBeam[] = _("Hits with a\nflashing beam.\n10% confusion chance\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_ShadowPunch[] = _("A strong punch from\nthe shadows.\nAlways hits.\nIron Fist boost."); // new
static const u8 sMoveFourLineDescription_Extrasensory[] = _("The user attacks\nwith an odd power.\n10% flinch chance."); // new
static const u8 sMoveFourLineDescription_SkyUppercut[] = _("The user attacks\nwith an uppercut\nthrown skywards.\nIron Fist boost."); // new
#if B_BINDING_TURNS >= GEN_5
static const u8 sMoveFourLineDescription_SandTomb[] = _("The foe is trapped\ninside a painful\nsandstorm for four\nor five turns.");
#else
static const u8 sMoveFourLineDescription_SandTomb[] = _("The foe is trapped\ninside a painful\nsandstorm for two\nto five turns.");
#endif
static const u8 sMoveFourLineDescription_SheerCold[] = _("This move is super\neffective on Water.\n20% frostbite chance."); // new
static const u8 sMoveFourLineDescription_MuddyWater[] = _("The user attacks\nwith muddy water.\n30% chance to\nlower foe's accuracy."); // new
static const u8 sMoveFourLineDescription_BulletSeed[] = _("The user shoots\nseeds at the foe.\nTwo to five seeds\nare shot at once.");
static const u8 sMoveFourLineDescription_AerialAce[] = _("An extremely fast\nattack. It can't\nbe evaded.\nKeen Edge boost."); // new
static const u8 sMoveFourLineDescription_IcicleSpear[] = _("Sharp icicles are\nfired at the foe.\nIt strikes two to\nfive times.");
static const u8 sMoveFourLineDescription_IronDefense[] = _("The user hardens\nits body's surface\nto sharply raise its\nDefense stat.");
static const u8 sMoveFourLineDescription_Block[] = _("The user blocks the\nfoe's way with arms\nspread wide to\nprevent escape.");
static const u8 sMoveFourLineDescription_Howl[] = _("The user howls to\nraise its spirit and\nboost its Attack\nstat.");
static const u8 sMoveFourLineDescription_DragonClaw[] = _("Sharp, huge claws\nhook and slash the\nfoe quickly.\nKeen Edge boost."); // new
static const u8 sMoveFourLineDescription_FrenzyPlant[] = _("The foe is hit with\nan enormous branch.\nNeeds recharging.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_BulkUp[] = _("The user bulks up\nits body to boost\nboth its Attack and\nDefense stats.");
static const u8 sMoveFourLineDescription_Bounce[] = _("The user bounces\non the foe on the\n2nd turn. 30%\nparalyze chance."); // new
static const u8 sMoveFourLineDescription_MudShot[] = _("Has a 10% chance\nto drop foe's Speed.\nHas +1 priority.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_PoisonTail[] = _("An attack with a\nhigh critical-hit\nratio. 30%\npoison chance."); // new
static const u8 sMoveFourLineDescription_Covet[] = _("A cutely executed\nattack that also\nsteals the foe's\nhold item.");
static const u8 sMoveFourLineDescription_VoltTackle[] = _("The user throws an\nelectrified tackle.\n25% recoil, 10%\nparalyze chance."); // new
static const u8 sMoveFourLineDescription_MagicalLeaf[] = _("The foe is attacked\nwith a strange leaf\nthat cannot be\nevaded.");
static const u8 sMoveFourLineDescription_WaterSport[] = _("Weakens Fire-type\nattacks while the\nuser is in the\nbattle.");
static const u8 sMoveFourLineDescription_CalmMind[] = _("The user focuses\nits mind to raise\nthe Sp. Atk and\nSp. Def stats.");
static const u8 sMoveFourLineDescription_LeafBlade[] = _("The foe is slashed\nwith a sharp leaf.\nHigh crit ratio.\nKeen Edge boost."); // new
static const u8 sMoveFourLineDescription_DragonDance[] = _("A mystic, powerful\ndance that boosts\nthe user's Attack\nand Speed stats.");
static const u8 sMoveFourLineDescription_RockBlast[] = _("The user hurls two\nto five hard rocks\nat the foe to\nattack.");
static const u8 sMoveFourLineDescription_ShockWave[] = _("A rapid jolt of\nelectricity strikes.\nNever misses.\nHas +2 priority."); // new
static const u8 sMoveFourLineDescription_WaterPulse[] = _("A pulsing blast of\nwater. Has 20%\nconfusion chance.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_DoomDesire[] = _("A move that attacks\nthe foe with a\nblast of light two\nturns after use.");
static const u8 sMoveFourLineDescription_PsychoBoost[] = _("An intense attack\nthat also sharply\nreduces the user's\nSp. Atk stat.");
static const u8 sMoveFourLineDescription_Roost[] = _("The user lands and\nrests its body. It\nrestores up to half\nof its max HP.");
static const u8 sMoveFourLineDescription_Gravity[] = _("Gravity is upped for\nfive turns, making\nflight unusuable and\nnegating Levitate.");
static const u8 sMoveFourLineDescription_MiracleEye[] = _("Negates a foe's\nevasion, as well as\nits immunity to\nPsychic-type moves.");
static const u8 sMoveFourLineDescription_WakeUpSlap[] = _("This attack hits\nsleeping foes for\nbig damage. It also\nwakes the foe up.");
static const u8 sMoveFourLineDescription_HammerArm[] = _("A strong, heavy\nfist is swung. Drops\nthe user's Speed.\nIron Fist boost."); // new
static const u8 sMoveFourLineDescription_GyroBall[] = _("A fast spin. The\nslower the user,\nthe greater the\ndamage.");
static const u8 sMoveFourLineDescription_HealingWish[] = _("The user faints.\nIts replacement\nhas its HP restored\nand status cured.");
static const u8 sMoveFourLineDescription_Brine[] = _("If the foe's HP is\ndown to about half,\nthis will hit with\ndouble the power.");
static const u8 sMoveFourLineDescription_NaturalGift[] = _("The user's Berry\ndetermines this\nattack's type\nand its power.");
static const u8 sMoveFourLineDescription_Feint[] = _("Hits a foe using\nmoves like Protect,\nlifting the effect\nof those moves.");
static const u8 sMoveFourLineDescription_Pluck[] = _("If the foe has a\nBerry, user gains\ngains its effect.\nStrong Jaw boost."); // new
static const u8 sMoveFourLineDescription_Tailwind[] = _("A turbulent whirl-\nwind that ups the\nSpeed stat of the\nparty for 4 turns.");
static const u8 sMoveFourLineDescription_Acupressure[] = _("The user applies\npressure to stress\npoints, sharply\nboosting one stat.");
static const u8 sMoveFourLineDescription_MetalBurst[] = _("The user retaliates\nwith greater power\nagainst the last\nfoe to damage it.");
static const u8 sMoveFourLineDescription_UTurn[] = _("The user strikes,\nand then switches\nwith a waiting\nparty Pokémon.");
static const u8 sMoveFourLineDescription_CloseCombat[] = _("Fights up close,\nwithout guarding.\nCuts Defenses.\nIron Fist boost."); // new
static const u8 sMoveFourLineDescription_Payback[] = _("If the user moves\nafter the foe, this\nattack does double\nthe damage.");
static const u8 sMoveFourLineDescription_Assurance[] = _("Power doubles if\nthe foe has already\ntaken damage in the\nsame turn.");
static const u8 sMoveFourLineDescription_Embargo[] = _("Prevents the foe\nfrom using its item.\nItems cannot be\nused on it, either.");
static const u8 sMoveFourLineDescription_Fling[] = _("The user flings its\nitem to attack. Its\npower and effects\ndepend on the item.");
static const u8 sMoveFourLineDescription_PsychoShift[] = _("The user transfers\nits status problems\nto the target using\npsychic powers.");
static const u8 sMoveFourLineDescription_TrumpCard[] = _("The fewer PP this\nmove has, the\ngreater its power.");
static const u8 sMoveFourLineDescription_HealBlock[] = _("The foe cannot use\nany moves, held\nitems or Abilities\nthat recover HP.");
static const u8 sMoveFourLineDescription_WringOut[] = _("The user wrings the\nfoe. The more HP\nthe foe has, the\nstronger this move.");
static const u8 sMoveFourLineDescription_PowerTrick[] = _("The user employs\nits psychic power\nto swap its Attack\nand Defense stat.");
static const u8 sMoveFourLineDescription_GastroAcid[] = _("Stomach acids are\nspewed at the foe,\nnegating the effect\nof its Ability.");
static const u8 sMoveFourLineDescription_LuckyChant[] = _("For 5 turns, the\nfoe is prevented\nfrom landing\ncritical hits.");
static const u8 sMoveFourLineDescription_MeFirst[] = _("The foe's intended\nmove is stolen and\nused first, with\ngreater power.");
static const u8 sMoveFourLineDescription_Copycat[] = _("The user tries to\nmimic the move used\nimmediately before\nit.");
static const u8 sMoveFourLineDescription_PowerSwap[] = _("The user and foe\nswap any changes\nto their Attack and\nSp. Atk stats.");
static const u8 sMoveFourLineDescription_GuardSwap[] = _("The user and foe\nswap any changes\nto their Defense\nand Sp. Def stats.");
static const u8 sMoveFourLineDescription_Punishment[] = _("The more the foe\nhas powered up with\nstat changes, the\nharder this hits.");
static const u8 sMoveFourLineDescription_LastResort[] = _("This fails unless\nthe user has used\nits other moves in\nthe battle already.");
static const u8 sMoveFourLineDescription_WorrySeed[] = _("A seed that causes\nworry is planted on\nthe foe, giving it\nInsomnia.");
static const u8 sMoveFourLineDescription_SuckerPunch[] = _("User strikes first.\nIt fails if the foe\nis not attacking."); // new
static const u8 sMoveFourLineDescription_ToxicSpikes[] = _("Poison spikes are\nlaid at the foe's\nfeet. They poison\nfoes that switch in.");
static const u8 sMoveFourLineDescription_HeartSwap[] = _("The user employs\nits psychic powers\nto swap stat changes\nwith the target.");
static const u8 sMoveFourLineDescription_AquaRing[] = _("The user envelops\nitself in a veil of\nwater. It regains\n1/8 HP every turn."); // new
static const u8 sMoveFourLineDescription_MagnetRise[] = _("The user levitates\nusing electrically\ngenerated magnetism\nfor five turns.");
static const u8 sMoveFourLineDescription_FlareBlitz[] = _("A ruthless, fiery\ncharge which has\n33% recoil. Has\n10% burn chance."); // new
static const u8 sMoveFourLineDescription_ForcePalm[] = _("The foe is attacked\nwith a shock wave.\n30% paralyze chance."); // new
static const u8 sMoveFourLineDescription_AuraSphere[] = _("A strong blast of\naura power.\nAlways hits.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_RockPolish[] = _("The user polishes\nits body to reduce\ndrag. This sharply\nraises its Speed.");
static const u8 sMoveFourLineDescription_PoisonJab[] = _("A stabbing attack\nwith 30% poison\nchance. Iron Fist\n& Mighty Horn boost."); // new
static const u8 sMoveFourLineDescription_DarkPulse[] = _("Releases an aura\nwith dark thoughts.\n20% flinch chance.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_NightSlash[] = _("The user waits to\nstrike, slashing\nthe foe. High crit.\nKeen Edge boost."); // new
static const u8 sMoveFourLineDescription_AquaTail[] = _("The user attacks\nby swinging its\ntail as if it were\na vicious wave.");
static const u8 sMoveFourLineDescription_SeedBomb[] = _("A barrage of hard-\nshelled seeds is\nslammed on the\nfoe from above.");
static const u8 sMoveFourLineDescription_AirSlash[] = _("A blade of air with\n30% flinch chance.\nKeen Edge boost.\nAir-based."); // new
static const u8 sMoveFourLineDescription_XScissor[] = _("Slashes with crossed\nscythes, claws etc.\nHigh crit ratio.\nKeen Edge boost."); // new
static const u8 sMoveFourLineDescription_BugBuzz[] = _("A harsh sound wave\nfrom the user.\n10% chance to\ndrop foe's Sp. Def. "); // new
static const u8 sMoveFourLineDescription_DragonPulse[] = _("The user's gaping\nmouth generates a\nshock wave attack.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_DragonRush[] = _("A tackle exhibiting\ndevastating menace.\n20% flinch chance."); // new
static const u8 sMoveFourLineDescription_PowerGem[] = _("A ray of light is\nshot at the foe,\nsparkling as if it\nwere made of gems.");
static const u8 sMoveFourLineDescription_DrainPunch[] = _("A forceful punch\nthat recovers\n50% of the damage.\nIron Fist boost."); // new
static const u8 sMoveFourLineDescription_VacuumWave[] = _("A pure vacuum is\nfired at the foe.\n+1 priority."); // new
static const u8 sMoveFourLineDescription_FocusBlast[] = _("Mental power is un-\nleashed. 10% chance\nto lower foe's SpDef.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_EnergyBall[] = _("Power is drawn from\nnature and fired at\nthe foe. 10% chance\nto drop foe's SpDef."); // new
static const u8 sMoveFourLineDescription_BraveBird[] = _("Wings tucked in,\nthe user charges at\nthe foe. 33%\nrecoil damage."); // new
static const u8 sMoveFourLineDescription_EarthPower[] = _("The ground erupts\nbelow the foe. 10%\nchance to lower\nthe foe's SpDef."); // new
static const u8 sMoveFourLineDescription_Switcheroo[] = _("The user trades\nheld items with the\nfoe faster than the\neye can follow.");
static const u8 sMoveFourLineDescription_NastyPlot[] = _("The user stimulates\nits brain with bad\nthoughts, sharply\nraising its Sp. Atk.");
static const u8 sMoveFourLineDescription_BulletPunch[] = _("Bullet-fast punches\nbarrage the target.\n+1 priority.\nIron Fist boost."); // new
static const u8 sMoveFourLineDescription_IceShard[] = _("Flash-frozen ice\nchunks are hurled\nat the foe.\n+1 priority."); // new
static const u8 sMoveFourLineDescription_ShadowClaw[] = _("Claws made from\nshadows strike the\nfoe. High crit.\nKeen Edge boost.");
static const u8 sMoveFourLineDescription_ThunderFang[] = _("Electrified fangs.\n10% paralyze or\nflinch chance.\nStrong Jaw boost."); // new
static const u8 sMoveFourLineDescription_IceFang[] = _("Frozen fangs.\n10% frostbite or\nflinch chance.\nStrong Jaw boost."); // new
static const u8 sMoveFourLineDescription_FireFang[] = _("Fiery fangs.\n10% burn or\nflinch chance.\nStrong Jaw boost."); // new
static const u8 sMoveFourLineDescription_ShadowSneak[] = _("The user's shadow\nextends and strikes\nthe foe.\n+1 priority."); // new
static const u8 sMoveFourLineDescription_MudBomb[] = _("A hard-packed mud\nball is hurled at\nthe foe. 30% chance\nto drop accuracy."); // new
static const u8 sMoveFourLineDescription_PsychoCut[] = _("Psychic blades\nstrike the foe.\nHigh crit ratio.\nKeen Edge boost."); // new
static const u8 sMoveFourLineDescription_ZenHeadbutt[] = _("The user focuses,\nand strikes the\nfoe. 20% flinch\nchance. Field-based."); // new
static const u8 sMoveFourLineDescription_MirrorShot[] = _("A flash of energy\nis loosed at the\nfoe. 30% chance to\ndrop their accuracy."); // new
static const u8 sMoveFourLineDescription_FlashCannon[] = _("Light energy attack.\n10% chance to lower\ntheir SpDef stat.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_RockClimb[] = _("A charging attack.\n20% confusion\nchance. Field-based."); // new
static const u8 sMoveFourLineDescription_Defog[] = _("Wind blows across\nthe battlefield,\nclearing barriers,\nobstacles, etc.");
static const u8 sMoveFourLineDescription_TrickRoom[] = _("A bizarre area is\nconstructed for 5\nturns where slower\nPokémon move first.");
static const u8 sMoveFourLineDescription_DracoMeteor[] = _("Comets strike down\nupon the foe. This\nharshly reduces the\nuser's Sp. Atk stat.");
static const u8 sMoveFourLineDescription_Discharge[] = _("Electricity is\nloosed on the field.\n30% paralyze\nchance to foes/ally."); // new
static const u8 sMoveFourLineDescription_LavaPlume[] = _("Scarlet flames wash\nover all Pokémon in\nbattle. 30%\nburn chance."); // new
static const u8 sMoveFourLineDescription_LeafStorm[] = _("A storm of sharp\nleaves is whipped\nup. The user's Sp.\nAtk sharply falls.");
static const u8 sMoveFourLineDescription_PowerWhip[] = _("The user violently\nwhirls its vines or\ntentacles to lash\nat the foe.");
static const u8 sMoveFourLineDescription_CrossPoison[] = _("High crit ratio.\n10% poison chance.\nKeen Edge boost."); // new
static const u8 sMoveFourLineDescription_GunkShot[] = _("Filthy garbage is\nshot at the foe.\n30% poison chance.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_IronHead[] = _("The user slams the\nfoe with its steel-\nhard head. 30%\nflinch chance."); // new
static const u8 sMoveFourLineDescription_MagnetBomb[] = _("A steel bomb is\nlaunched at the\nfoe. This attack\nwill not miss.");
static const u8 sMoveFourLineDescription_StoneEdge[] = _("Sharpened stones\nstab the foe from\nbelow. Critical hits\nland more easily.");
static const u8 sMoveFourLineDescription_Captivate[] = _("Foes of a different\ngender are charmed,\nharshly lowering\ntheir Sp. Atk stat.");
static const u8 sMoveFourLineDescription_StealthRock[] = _("Levitating stones\nsurround the foe.\nThis hurts foes\nthat switch in.");
static const u8 sMoveFourLineDescription_GrassKnot[] = _("A snaring grass\ntrap that inflicts\nmore damage on\nheavier foes.");
static const u8 sMoveFourLineDescription_Chatter[] = _("The foe is left\nconfused by sound\nwaves of deafening\nchatter.");
static const u8 sMoveFourLineDescription_Judgment[] = _("The type of this\nmove varies with\nthe kind of Plate\nthe user is holding.");
static const u8 sMoveFourLineDescription_BugBite[] = _("If the foe has a\nBerry, user gains\ngains its effect.\nStrong Jaw boost."); // new
static const u8 sMoveFourLineDescription_ChargeBeam[] = _("Attacks with an\nelectric charge.\nRaises own SpAtk.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_PrimalBeam[] = _("An strange beam\nthat uses the user's\nAttack, may\nrise own Atk.");
static const u8 sMoveFourLineDescription_WoodHammer[] = _("The user slams its\nrugged body into\nthe foe. 33%\nrecoil damage.");
static const u8 sMoveFourLineDescription_AquaJet[] = _("The user lunges at\nthe foe at a fast\nspeed. This has\n+1 priority."); // new
static const u8 sMoveFourLineDescription_AttackOrder[] = _("Underlings pummel\nthe foe. Critical\nhits land more\neasily.");
static const u8 sMoveFourLineDescription_DefendOrder[] = _("Underlings form a\nliving shield which\nup the user's Sp.\nDef and Defense.");
static const u8 sMoveFourLineDescription_HealOrder[] = _("The user calls out\nits underlings to\nheal it, restoring\nhalf of its max HP.");
static const u8 sMoveFourLineDescription_HeadSmash[] = _("A hazardous, full-\npower headbutt hits\nthe foe. 50%\nrecoil damage."); // new
static const u8 sMoveFourLineDescription_DoubleHit[] = _("The user slams the\nfoe with a tail,\netc. The foe is hit\ntwice in a row.");
static const u8 sMoveFourLineDescription_RoarOfTime[] = _("A blast which\ndistorts even time.\nForces the target\nto switch. Moves last."); // new
static const u8 sMoveFourLineDescription_SpacialRend[] = _("The foe, and the\nspace around it, is\ntorn. Critical hits\nland more easily.");
static const u8 sMoveFourLineDescription_CrushGrip[] = _("The user crushes\nthe foe. The more\nHP the foe has, the\nstronger this move.");
#if B_BINDING_TURNS >= GEN_5
static const u8 sMoveFourLineDescription_MagmaStorm[] = _("The foe becomes\ntrapped within a\nmaelstrom of fire\nfor 4 or 5 turns.");
#else
static const u8 sMoveFourLineDescription_MagmaStorm[] = _("The foe becomes\ntrapped within a\nmaelstrom of fire\nfor 2 to 5 turns.");
#endif
static const u8 sMoveFourLineDescription_DarkVoid[] = _("The foe is dragged\ninto a world of\ntotal darkness that\nputs it to sleep.");
static const u8 sMoveFourLineDescription_SeedFlare[] = _("A shock wave is\nloosed at the foe.\n40% chance to\nlower foe's SpDef."); // new
static const u8 sMoveFourLineDescription_OminousWind[] = _("Repulsive wind is\nblasted at the foe.\n10% chance to raise\nall user's stats."); // new
static const u8 sMoveFourLineDescription_ShadowForce[] = _("The user vanishes.\nThe next turn, it\nstrikes the foe,\nignoring Protect.");
static const u8 sMoveFourLineDescription_HoneClaws[] = _("The user sharpens\nits claws to boost\nits Attack stat and\naccuracy.");
static const u8 sMoveFourLineDescription_WideGuard[] = _("For 1 turn, the\nuser and its allies\nare protected from\nwide-ranging moves.");
static const u8 sMoveFourLineDescription_GuardSplit[] = _("The user's Defense\nand Sp. Def stats\nare averaged with\nthose of the target.");
static const u8 sMoveFourLineDescription_PowerSplit[] = _("The user's Attack\nand Sp. Atk stats\nare averaged with\nthose of the target.");
static const u8 sMoveFourLineDescription_WonderRoom[] = _("For 5 turns, all\nPokémon have their\nDefense and Sp. Def\nstats swapped.");
static const u8 sMoveFourLineDescription_Psyshock[] = _("The user casts an\nodd psychic wave to\nattack the foe for\nphysical damage.");
static const u8 sMoveFourLineDescription_TailSlap[] = _("The user attacks by\nstriking the foe\nwith its hard tail,\ntwo to five times.");
static const u8 sMoveFourLineDescription_Venoshock[] = _("A special liquid\nthat damages for\ndouble the power on\npoisoned targets.");
static const u8 sMoveFourLineDescription_Autotomize[] = _("The user sheds part\nof its body to be\nlighter, sharply\nraising its Speed.");
static const u8 sMoveFourLineDescription_RagePowder[] = _("Foes aim only at\nthe user, enraged\nby a cloud of its\nirritating powder.");
static const u8 sMoveFourLineDescription_Telekinesis[] = _("The user floats its\nfoe psychically for\n3 turns, making the\nfoe easier to hit.");
static const u8 sMoveFourLineDescription_MagicRoom[] = _("For 5 turns, the\neffects of held\nitems are negated\nby a bizarre area.");
static const u8 sMoveFourLineDescription_SmackDown[] = _("The user throws a\nstone at its foe.\nFlying foes will\nfall to the ground.");
static const u8 sMoveFourLineDescription_StormThrow[] = _("A fierce blow upon\nthe foe which will\nalways result in a\ncritical hit.");
static const u8 sMoveFourLineDescription_FlameBurst[] = _("Also hits foe's\nally for 1/4 dmg.\n+1 priority.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_SludgeWave[] = _("It swamps the area\naround the user\nwith sludge. 10%\npoison chance."); // new
static const u8 sMoveFourLineDescription_QuiverDance[] = _("A beautiful, mystic\ndance which boosts\nthe user's Sp. Atk,\nSp. Def and Speed.");
static const u8 sMoveFourLineDescription_HeavySlam[] = _("The user slams\nthe foe with its\nheavy body. Heavier\nusers are stronger.");
static const u8 sMoveFourLineDescription_Synchronoise[] = _("An odd shack wave\nthat only hurts\nPokémon of the same\ntype as the user.");
static const u8 sMoveFourLineDescription_ElectroBall[] = _("An electric orb is\nhurled at the foe.\nFaster users deal\ngreater damage.");
static const u8 sMoveFourLineDescription_Soak[] = _("The foe is struck\nby a torrent of\nwater which changes\nits type to Water.");
static const u8 sMoveFourLineDescription_FlameCharge[] = _("Cloaked in flames,\nthe user strikes.\nThis raises its\nSpeed stat.");
static const u8 sMoveFourLineDescription_Coil[] = _("The user coils up,\nraising its Attack,\nDefense and its\naccuracy.");
static const u8 sMoveFourLineDescription_LowSweep[] = _("The user strikes\nswiftly at the foe's\nlegs, lowering the\nfoe's Speed stat.");
static const u8 sMoveFourLineDescription_AcidSpray[] = _("An acidic fluid is\nspat at the foe.\nThis harshly lowers\nthe foe's Sp. Def.");
static const u8 sMoveFourLineDescription_FoulPlay[] = _("The higher the\nfoe's Attack stat,\nthe greater the\ndamage this deals.");
static const u8 sMoveFourLineDescription_SimpleBeam[] = _("The user's odd\npsychic wave\nchanges the foe's\nAbility to Simple.");
static const u8 sMoveFourLineDescription_Entrainment[] = _("An odd dance that\ncompels the target\nto mimic the\nAbility of the user.");
static const u8 sMoveFourLineDescription_AfterYou[] = _("The user helps the\ntarget and forces\nit to move right\nafter the user.");
static const u8 sMoveFourLineDescription_Round[] = _("A loud song attack.\nOthers can join in,\nincreasing the\npower of the move.");
static const u8 sMoveFourLineDescription_EchoedVoice[] = _("The user attacks\nwith an echoing\nvoice which builds\nin power each turn.");
static const u8 sMoveFourLineDescription_ChipAway[] = _("The user strikes at\nthe first opening,\nignoring its foe's\nstat changes.");
static const u8 sMoveFourLineDescription_ClearSmog[] = _("A clump of special\nmud is hurled at\nthe foe, resetting\ntheir stat changes.");
static const u8 sMoveFourLineDescription_StoredPower[] = _("The more the user's\nstats are raised,\nthe greater this\nmove's power.");
static const u8 sMoveFourLineDescription_QuickGuard[] = _("The user and its\nallies are\nprotected from\npriority moves.");
static const u8 sMoveFourLineDescription_AllySwitch[] = _("The user teleports\nusing a strange\npower and swaps\nwith its ally.");
static const u8 sMoveFourLineDescription_Scald[] = _("Boiling hot water\nis shot at the foe.\n30% burn chance."); // new
static const u8 sMoveFourLineDescription_ShellSmash[] = _("A broken shell ups\nAtk, Sp.Atk and Spe,\nwhile reducing Def\nand Sp.Def.");
static const u8 sMoveFourLineDescription_HealPulse[] = _("A pulse is loosed,\nhealing the target\nby up to half of\ntheir maximum HP.");
static const u8 sMoveFourLineDescription_Hex[] = _("Double damage to\nfoes affected by\nstatus problems."); // new
static const u8 sMoveFourLineDescription_SkyDrop[] = _("The user hurls and\ndrops the foe over\n2 turns, stopping\nthe foe from moving.");
static const u8 sMoveFourLineDescription_ShiftGear[] = _("The user rotates its\ngears, raising its\nAttack and sharply\nraising its Speed.");
static const u8 sMoveFourLineDescription_CircleThrow[] = _("The foe is thrown,\ndragging out another\nPokémon into battle.\nWild Pokémon flee.");
static const u8 sMoveFourLineDescription_Incinerate[] = _("A fiery attack that\nburns up any Berry\nor Gem the foe may\nbe holding.");
static const u8 sMoveFourLineDescription_Quash[] = _("The user suppresses\nthe foe and makes\nits move go last.");
static const u8 sMoveFourLineDescription_Acrobatics[] = _("The user nimbly\nstrikes the foe.\nDouble damage\nwithout an item."); // new
static const u8 sMoveFourLineDescription_ReflectType[] = _("The user reflects\nthe foe's type,\nmaking it the same\ntype as the foe.");
static const u8 sMoveFourLineDescription_Retaliate[] = _("This vengeful move\ndeals double damage\nif an ally fainted\nin the turn before.");
static const u8 sMoveFourLineDescription_FinalGambit[] = _("This attack causes\nthe user to faint,\nbut does damage\nequal to its HP.");
static const u8 sMoveFourLineDescription_Bestow[] = _("The user passes its\nheld item to the\nfoe when the foe is\nnot holding an item.");
static const u8 sMoveFourLineDescription_Inferno[] = _("The foe is engulfed\nin an intense fire.\nBurns the foe.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_WaterPledge[] = _("A column of water\nthat strikes for\nmore damage if used\nwith Fire Pledge.");
static const u8 sMoveFourLineDescription_FirePledge[] = _("A column of fire\nthat strikes for\nmore damage if used\nwith Grass Pledge.");
static const u8 sMoveFourLineDescription_GrassPledge[] = _("A column of grass\nthat strikes for\nmore damage if used\nwith Water Pledge.");
static const u8 sMoveFourLineDescription_StruggleBug[] = _("While resisting,\nthe user attacks.\nThis lowers the\nfoe's Sp. Atk stat.");
static const u8 sMoveFourLineDescription_Bulldoze[] = _("A mighty stomp\nwhich hits all\nfoes, and lowers\ntheir Speed stat.");
static const u8 sMoveFourLineDescription_FrostBreath[] = _("A cold breath which\nalways results in a\ncritical hit.");
static const u8 sMoveFourLineDescription_DragonTail[] = _("The foe is knocked\naway, and a\ndifferent Pokémon\nis dragged out.");
static const u8 sMoveFourLineDescription_WorkUp[] = _("The user is roused,\nand its Attack and\nSp. Atk stats\nincrease.");
static const u8 sMoveFourLineDescription_Electroweb[] = _("The foe is caught\nin an electric net.\nThis lowers their\nSpeed stat.");
static const u8 sMoveFourLineDescription_WildCharge[] = _("An electric,\nreckless crash\nattack with 10%\nparalyze chance."); // new
static const u8 sMoveFourLineDescription_DrillRun[] = _("Rotating its body\nlike a drill.\nHigh crit ratio.\nMighty Horn boost."); // new
static const u8 sMoveFourLineDescription_DualChop[] = _("Brutal strikes\nhit twice.\nHigh crit ratio.\nKeen Edge boost."); // new
static const u8 sMoveFourLineDescription_HeartStamp[] = _("The foe's guard\ndrops, and the user\nstrikes. 30%\nflinch chance."); // new
static const u8 sMoveFourLineDescription_HornLeech[] = _("Absorbs half the\ndamage. Ignores\nfoe's stat changes.\nMighty Horn boost."); // new
static const u8 sMoveFourLineDescription_SacredSword[] = _("The user cuts its\nfoe. Ignores foe's\nstat changes.\nKeen Edge boost."); // new
static const u8 sMoveFourLineDescription_RazorShell[] = _("High crit ratio.\n50% chance to\nlower foe's Def.\nKeen Edge boost."); // new
static const u8 sMoveFourLineDescription_HeatCrash[] = _("Covered in flames,\nthe user slams its\nfoe. Heavier users\ndeal more damage.");
static const u8 sMoveFourLineDescription_LeafTornado[] = _("The foe is trapped\nwith sharp leaves\nfor four or\nfive turns."); // new
static const u8 sMoveFourLineDescription_Steamroller[] = _("The user rolls over\nits foes. This\nattack has a 30%\nflinch chance."); // new
static const u8 sMoveFourLineDescription_CottonGuard[] = _("The user protects\nitself with soft\ncotton, drastically\nraising its Defense.");
static const u8 sMoveFourLineDescription_NightDaze[] = _("Strucks with a pitch-\nblack shock wave.\nHas +1 priority."); // new
static const u8 sMoveFourLineDescription_Hurricane[] = _("30% chance to\nconfuse the foe.\nWeather- and\nAir-based."); // new
static const u8 sMoveFourLineDescription_HeadCharge[] = _("Powerful guard hair\nheadbutts the foe\nin an attack. 25%\nrecoil damage."); // new
static const u8 sMoveFourLineDescription_GearGrind[] = _("The user attacks by\nthrowing steel\ngears at its target\ntwice.");
static const u8 sMoveFourLineDescription_SearingShot[] = _("Scarlet flames\ntorch the field.\n30% burn chance.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_TechnoBlast[] = _("A beam of light\nthat changes type\ndepending on the\nuser's held Drive.");
static const u8 sMoveFourLineDescription_RelicSong[] = _("An ancient song\nthat may induce\nsleep in its\nlisteners.");
static const u8 sMoveFourLineDescription_SecretSword[] = _("The user cuts its\nfoe, oddly dealing\nphysical damage.\nKeen Edge boost."); // new
static const u8 sMoveFourLineDescription_Glaciate[] = _("The user blows\nfreezing cold air\nat its foes that\nlowers their Speed.");
static const u8 sMoveFourLineDescription_BoltStrike[] = _("The user strikes\nits foe with\nelectricity. 30%\nparalyze chance."); // new
static const u8 sMoveFourLineDescription_BlueFlare[] = _("The foe is engulfed\nin a beautiful flame.\n20% burn chance."); // new
static const u8 sMoveFourLineDescription_FieryDance[] = _("The user flaps its\nflame-cloaked wings.\n50% chance to\nraise its SpAtk."); // new
static const u8 sMoveFourLineDescription_FreezeShock[] = _("Electrified ice\nhits the foe on the\n2nd turn. 30%\nparalyze chance."); // new
static const u8 sMoveFourLineDescription_IceBurn[] = _("Ultracold, freezing\nwind surrounds the\nfoe on the 2nd turn.\n30% burn chance."); // new
static const u8 sMoveFourLineDescription_Snarl[] = _("The user yells as\nif it is ranting,\nlowering the Sp.\nAtk of its foe.");
static const u8 sMoveFourLineDescription_IcicleCrash[] = _("Sharp icicles fall\nonto the foe, with\na 30% flinch\nchance."); // new
static const u8 sMoveFourLineDescription_VCreate[] = _("A powerful strike\nthat lowers the\nuser's Defense, Sp.\nDef and Speed.");
static const u8 sMoveFourLineDescription_FusionFlare[] = _("A giant flame that\ndeals more damage\nwhen joined with\na big thunderbolt.");
static const u8 sMoveFourLineDescription_FusionBolt[] = _("A giant thunderbolt\nthat deals more\ndamage when joined\nwith a big flame.");
static const u8 sMoveFourLineDescription_FlyingPress[] = _("A wrestling attack\nthat is Fighting-\nand Flying-type at\nthe same time.");
static const u8 sMoveFourLineDescription_MatBlock[] = _("A pulled-up mat is\nused to protect the\nuser and its ally\nfrom damaging moves.");
static const u8 sMoveFourLineDescription_Belch[] = _("The user eats its\nheld Berry and lets\nout a damaging\nbelch at the foe.");
static const u8 sMoveFourLineDescription_Rototiller[] = _("The user tills the\nsoil, raising the\nAttack and Sp. Atk\nof Grass-types.");
static const u8 sMoveFourLineDescription_StickyWeb[] = _("A sticky net woven\naround the foe that\ndrops the Speed of\nfoes that switch in.");
static const u8 sMoveFourLineDescription_FellStinger[] = _("If this attack\nknocks out a foe,\nthe user's Attack\nrises by +3."); // new
static const u8 sMoveFourLineDescription_TrickOrTreat[] = _("The user adds the\nGhost-type to its\nfoe by taking it\ntrick-or-treating.");
static const u8 sMoveFourLineDescription_NobleRoar[] = _("A noble roar that\nintimidates the foe\nand lowers its\nAttack and Sp. Atk.");
static const u8 sMoveFourLineDescription_IonDeluge[] = _("The user disperses\ncharged particles\nwhich electrify\nNormal-type moves.");
static const u8 sMoveFourLineDescription_ParabolicCharge[] = _("The user attacks\nall around it, and\nrestores HP by 25%\nof damage dealt.");
static const u8 sMoveFourLineDescription_ForestsCurse[] = _("The user puts a\nforest curse on the\nfoe. The foe is now\nGrass-type as well.");
static const u8 sMoveFourLineDescription_PetalBlizzard[] = _("A violent petal\nblizzard stirs up,\nhitting everything\naround it.");
static const u8 sMoveFourLineDescription_FreezeDry[] = _("This move is super\neffective on Water.\n10% frostbite chance.");
static const u8 sMoveFourLineDescription_DisarmingVoice[] = _("The user cries out\nwith a disarmingly\ncute voice. This\nnever misses.");
static const u8 sMoveFourLineDescription_PartingShot[] = _("The foe's Attack\nand Sp. Atk stats\nare lowered by a\nparting threat.");
static const u8 sMoveFourLineDescription_TopsyTurvy[] = _("All stat changes\naffecting the foe\nturn topsy-turvy\nand are inverted.");
static const u8 sMoveFourLineDescription_DrainingKiss[] = _("A kiss that absorbs\n30% of damage it\ninflicted to\nrestore HP.");  // new
static const u8 sMoveFourLineDescription_CraftyShield[] = _("A mysterious power\nprotects the user\nand its allies from\nstatus moves.");
static const u8 sMoveFourLineDescription_FlowerShield[] = _("A mysterious power\nraises the Defense\nof all Grass-type\nPokémon in battle.");
static const u8 sMoveFourLineDescription_GrassyTerrain[] = _("For 5 turns, the\nground turns grassy.\nThis ups Grass-type\nmoves, and heals.");
static const u8 sMoveFourLineDescription_MistyTerrain[] = _("Weakens Dragon-type\nmoves for 5 turns,\nand prevents status\nconditions for all.");
static const u8 sMoveFourLineDescription_Electrify[] = _("This move\nelectrifies the foe,\nmaking its next\nmove Electric-type.");
static const u8 sMoveFourLineDescription_PlayRough[] = _("The user and foe\nplay rough, with a\n10% chance to drop\nfoe's Attack."); // new
static const u8 sMoveFourLineDescription_FairyWind[] = _("A quick moving cloud\nof pixie dust.\nHas +1 Priority.\nAir-based."); // new
static const u8 sMoveFourLineDescription_Moonblast[] = _("The power of the\nmoon strikes the\nfoe. 30% chance to\nlower foe's SpAtk."); // new
static const u8 sMoveFourLineDescription_Boomburst[] = _("An explosively loud\nsound is let out,\nhitting all that\nsurrounds it.");
static const u8 sMoveFourLineDescription_FairyLock[] = _("For 1 turn, the\nuser locks down\nthe battlefield and\nprevents fleeing.");
static const u8 sMoveFourLineDescription_KingsShield[] = _("A protective stance\nis assumed. Contact\nby the foe harshly\nlowers its Attack.");
static const u8 sMoveFourLineDescription_PlayNice[] = _("Play Nice lowers the\ntarget's Attack by 1 stage.\nThis move always hits.");
static const u8 sMoveFourLineDescription_Confide[] = _("The foe's Sp. Atk\ndrops after being\ntold a secret by\nthe user.");
static const u8 sMoveFourLineDescription_DiamondStorm[] = _("A storm of diamonds\npelts the foes.\n50% chance to up\nuser's Defense."); // new
static const u8 sMoveFourLineDescription_SteamEruption[] = _("The foe is immersed\nin heated steam.\n30% burn chance.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_HyperspaceHole[] = _("Using a wormhole,\nthe user strikes.\nHas +1 priority.\nIgnores Protect etc."); // new
static const u8 sMoveFourLineDescription_WaterShuriken[] = _("The user hits the\nfoe with 2 to 5\nthrowing stars.\n+1 priority."); // new
static const u8 sMoveFourLineDescription_MysticalFire[] = _("The user breathes a\nspecial, hot fire.\nThis lowers the\nfoe's Sp. Atk stat."); // new
static const u8 sMoveFourLineDescription_SpikyShield[] = _("This prickly shield\nprotects the user\nand harms any foe\nthat makes contact.");
static const u8 sMoveFourLineDescription_AromaticMist[] = _("The user raises\nthe Sp. Def stat of\nits partner with a\nmysterious aroma.");
static const u8 sMoveFourLineDescription_EerieImpulse[] = _("The foe's Sp. Atk\nis harshly lowered\nby exposure to an\neerie impulse.");
static const u8 sMoveFourLineDescription_VenomDrench[] = _("Poisoned foes\nsuffer lowered\nAttack, Sp. Atk and\nSpeed stats.");
static const u8 sMoveFourLineDescription_Powder[] = _("If the foe uses a\nFire-type move, it\nwill be damaged by\nthis powder.");
static const u8 sMoveFourLineDescription_Geomancy[] = _("On the 2nd turn,\nthe user sharply\nups its Sp. Atk, Sp.\nDef and Speed stats.");
static const u8 sMoveFourLineDescription_MagneticFlux[] = _("The user boosts the\ndefenses of allies\nwith the Plus or\nMinus Ability.");
static const u8 sMoveFourLineDescription_HappyHour[] = _("This move doubles\nthe amount of prize\nmoney received\nafter battle.");
static const u8 sMoveFourLineDescription_ElectricTerrain[] = _("For 5 turns, the\ncharged ground ups\nElectric-type moves\nand prevents sleep.");
static const u8 sMoveFourLineDescription_DazzlingGleam[] = _("The user emits a\npowerful flash,\nhitting all foes.");
static const u8 sMoveFourLineDescription_Celebrate[] = _("The Pokémon\ncongratulates you\non your special\nday!");
static const u8 sMoveFourLineDescription_HoldHands[] = _("The user and ally\nhold hands. This\nmakes them very\nhappy.");
static const u8 sMoveFourLineDescription_BabyDollEyes[] = _("Before it can move,\nthe foe's Attack\nstat is lowered by\nan adorable stare.");
static const u8 sMoveFourLineDescription_Nuzzle[] = _("The user's\nelectrified cheeks\nnuzzle the foe,\nparalyzing the foe.");
#if B_BINDING_TURNS >= GEN_5
static const u8 sMoveFourLineDescription_Infestation[] = _("The foe is infested\nfor 4 or 5 turns.\nThe foe cannot flee\nduring this time.");
#else
static const u8 sMoveFourLineDescription_Infestation[] = _("The foe is infested\nfor 2 to 5 turns.\nThe foe cannot flee\nduring this time.");
#endif
static const u8 sMoveFourLineDescription_PowerUpPunch[] = _("The user strikes,\nstrengthening its\nfists. This raises\ntheir Attack stat.");
static const u8 sMoveFourLineDescription_OblivionWing[] = _("The user absorbs\nover 75% of the\ndamage inflicted.\nAir-based."); // new
static const u8 sMoveFourLineDescription_ThousandArrows[] = _("This move also hits\nfoes that are in\nthe air, and knocks\nthem down.");
static const u8 sMoveFourLineDescription_ThousandWaves[] = _("Those hit by this\ncrawling wave\ncan no longer\nescape the battle.");
static const u8 sMoveFourLineDescription_LandsWrath[] = _("The user gathers\nthe energy of the\nland and focuses it\non its foes.");
static const u8 sMoveFourLineDescription_LightOfRuin[] = _("The user fires a\npowerful beam of\nlight that has\n50% recoil damage."); // new
static const u8 sMoveFourLineDescription_OriginPulse[] = _("Attacks both foes\nwith deep blue\nbeams of light.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_PrecipiceBlades[] = _("The foes are all\nattacked with\nfearsome blades of\nstone and rock.");
static const u8 sMoveFourLineDescription_DragonAscent[] = _("The user soars up,\nthen strikes. This\ncuts its Defense\nand Sp. Def stats.");
static const u8 sMoveFourLineDescription_HyperspaceFury[] = _("The user barrages\nits foe, lowering\nits Defense and\nignoring protection.");
static const u8 sMoveFourLineDescription_ShoreUp[] = _("Heals the user by\nup to half its full\nHP, restoring more\nin a sandstorm.");
static const u8 sMoveFourLineDescription_FirstImpression[] = _("An attack that hits\nfirst with great\npower. Usable only\non first turn.");
static const u8 sMoveFourLineDescription_BanefulBunker[] = _("This move protects\nthe user and\npoisons any foe\nthat makes contact.");
static const u8 sMoveFourLineDescription_SpiritShackle[] = _("The foe's shadow is\npinned down when it\nis hit, preventing\nit from escaping.");
static const u8 sMoveFourLineDescription_DarkestLariat[] = _("The foe swings both\narms to hit its\nfoe, ignoring any\nstat changes.");
static const u8 sMoveFourLineDescription_SparklingAria[] = _("Musical bubbles hit\nthose around the\nuser, healing the\nburn of those hit.");
static const u8 sMoveFourLineDescription_FloralHealing[] = _("Heals the target by\nup to half its max\nHP. It heals more\nin grassy terrain.");
static const u8 sMoveFourLineDescription_HighHorsepower[] = _("The user fiercely\nattacks the foe.\nStriker boost."); // new
static const u8 sMoveFourLineDescription_StrengthSap[] = _("Restores HP by the\namount of the foe's\nAttack stat, and\ndrops their Attack.");
static const u8 sMoveFourLineDescription_SolarBlade[] = _("A 2-turn move that\nslices the foe.\nWeather-based.\nKeen Edge boost."); // new
static const u8 sMoveFourLineDescription_Leafage[] = _("The user attacks by\npelting the target\nwith leaves.");
static const u8 sMoveFourLineDescription_Spotlight[] = _("For 1 turn, a spot-\nlight is shone on\nthe foe so that\nonly it is attacked.");
static const u8 sMoveFourLineDescription_ToxicThread[] = _("Poisoned threads\nshoot at the foe,\npoisoning it and\nlowering its Speed.");
static const u8 sMoveFourLineDescription_LaserFocus[] = _("The user focuses\nintensely, making\nsure its next move\nis a critical hit.");
static const u8 sMoveFourLineDescription_GearUp[] = _("Allies with the\nPlus or Minus\nAbility have their\nattack stats upped.");
static const u8 sMoveFourLineDescription_ThroatChop[] = _("For 2 turns after\nbeing hit, the foe\ncannot use moves\nthat emit sound.");
static const u8 sMoveFourLineDescription_PollenPuff[] = _("A pollen puff that\nwill explode to\ndamage foes, but\nwill heal allies.");
static const u8 sMoveFourLineDescription_AnchorShot[] = _("The user's anchor\nchain strikes and\nentangles the foe,\npreventing escape.");
static const u8 sMoveFourLineDescription_PsychicTerrain[] = _("For 5 turns, faster\nmoves will fail and\nPsychic-type moves\ndeal more damage.");
static const u8 sMoveFourLineDescription_Lunge[] = _("The user lunges at\nthe foe with full\nforce, lowering the\nfoe's Attack stat.");
static const u8 sMoveFourLineDescription_FireLash[] = _("The foe is struck\nwith a burning\nlash that lowers\nits Defense stat.");
static const u8 sMoveFourLineDescription_PowerTrip[] = _("The more the user's\nstats are raised,\nthe greater this\nattack's power.");
static const u8 sMoveFourLineDescription_BurnUp[] = _("To strike at full\nforce, the user\nburns out and loses\nits Fire-type.");
static const u8 sMoveFourLineDescription_SpeedSwap[] = _("The user exchanges\nSpeed stats with\nthe target.");
static const u8 sMoveFourLineDescription_SmartStrike[] = _("Stabs the foe\nwith a sharp horn.\nNever misses.\nMighty Horn boost."); // new
static const u8 sMoveFourLineDescription_Purify[] = _("The user tries to\nheal the target's\nstatus condition to\nrestore its own HP.");
static const u8 sMoveFourLineDescription_RevelationDance[] = _("The user attacks by\ndancing. The user's\ntype determines the\ntype of this move.");
static const u8 sMoveFourLineDescription_CoreEnforcer[] = _("This attack will\nalso negate the\nfoe's Ability if it\nhas moved already.");
static const u8 sMoveFourLineDescription_TropKick[] = _("An intense, tropical\nkick. This lowers\nfoe's Attack.\nStriker boost."); // new
static const u8 sMoveFourLineDescription_Instruct[] = _("The user instructs\nthe target to use\nthe target's last\nmove again.");
static const u8 sMoveFourLineDescription_BeakBlast[] = _("The user strikes\nwith its heated\nbeak. Has 30%\nburn chance."); // new
static const u8 sMoveFourLineDescription_ClangingScales[] = _("The user attacks by\nrubbing the scales\non its body. This\nlowers its Defense.");
static const u8 sMoveFourLineDescription_DragonHammer[] = _("Using its body like\na hammer, the user\nattacks its foe.");
static const u8 sMoveFourLineDescription_BrutalSwing[] = _("The user violently\nswings its body\naround, damaging\neveryone nearby.");
static const u8 sMoveFourLineDescription_AuroraVeil[] = _("For 5 turns, damage\nfrom attacks are\nweakened. This\nfails without Hail.");
static const u8 sMoveFourLineDescription_ShellTrap[] = _("The user sets a\nshell trap that is\nset off by physical\nattacks.");
static const u8 sMoveFourLineDescription_FleurCannon[] = _("A strong beam.\nHarshly lowers the\nuser's Sp. Atk.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_PsychicFangs[] = _("Breaks any barrier\nlike Light Screen\nand Reflect.\nStrong Jaw boost."); // new
static const u8 sMoveFourLineDescription_StompingTantrum[] = _("A frustrated strike\nthat deals twice\nthe damage if the\nlast move failed.");
static const u8 sMoveFourLineDescription_ShadowBone[] = _("The foe is hit by a\nspirit bone.\n20% chance to drop\nfoe's Defense."); // new
static const u8 sMoveFourLineDescription_Accelerock[] = _("The user smashes\ninto the foe at\nhigh speed. Has\n+1 priority."); // new
static const u8 sMoveFourLineDescription_Liquidation[] = _("A full-force blast\nof water with a\n20% chance to lower\nfoe's Defense."); // new
static const u8 sMoveFourLineDescription_PrismaticLaser[] = _("Severely damaging\nlaser beams.\nNeeds recharging.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_SpectralThief[] = _("Hiding in the foe's\nshadow, the user\nsteals its stat\nboosts and attacks.");
static const u8 sMoveFourLineDescription_SunsteelStrike[] = _("Slams into the\nfoe like a meteor.\nIgnores Abilities.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_MoongeistBeam[] = _("A sinister ray\nattacks the foe.\nIgnores Abilities.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_TearfulLook[] = _("The foe's attack\nstats are lowered\nby the user's teary\neyes.");
static const u8 sMoveFourLineDescription_ZingZap[] = _("A strong electric\nblast crashes on\nthe foe. 30%\nflinch chance."); // new
static const u8 sMoveFourLineDescription_NaturesMadness[] = _("The user hits the\nfoe with the force\nof nature, halving\nthe foe's HP.");
static const u8 sMoveFourLineDescription_MultiAttack[] = _("A high-energy slam.\nThe memory held\ndetermines the\nmove's type.");
static const u8 sMoveFourLineDescription_MindBlown[] = _("The user attacks\neverything nearby,\ncausing its own\nhead to explode.");
static const u8 sMoveFourLineDescription_PlasmaFists[] = _("Electrifies Normal-\ntype moves used in\nthe same turn.\nIron Fist boost."); // new
static const u8 sMoveFourLineDescription_PhotonGeyser[] = _("A pillar of light.\nUses the best Atk\nstat.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_ZippyZap[] = _("High-speed electric\nbursts that always\ngo first and land\nin a critical hit.");
static const u8 sMoveFourLineDescription_SplishySplash[] = _("The user creates\na huge electrified\nwave that may\nparalyze the foe.");
static const u8 sMoveFourLineDescription_FloatyFall[] = _("Floats in the air and\ndives at a steep\nangle. It may make\nthe target flinch.");
static const u8 sMoveFourLineDescription_PikaPapow[] = _("Pikachu's love for\nits trainer raises\nthis move's power.\nIt never misses.");
#if B_UPDATED_MOVE_DATA >= GEN_8
static const u8 sMoveFourLineDescription_BouncyBubble[] = _("An attack that\nabsorbs all the\ndamage it inflicted\nto restore HP.");
#else
static const u8 sMoveFourLineDescription_BouncyBubble[] = _("An attack that\nabsorbs half the\ndamage it inflicted\nto restore HP.");
#endif
static const u8 sMoveFourLineDescription_BuzzyBuzz[] = _("The user shoots a\njolt of electricity\nthat always\nparalyzes the foe.");
static const u8 sMoveFourLineDescription_SizzlySlide[] = _("The user cloaks\nitself in fire and\ncharges at the foe,\nleaving a burn.");
static const u8 sMoveFourLineDescription_GlitzyGlow[] = _("A Telekinetic force\nattacks the foe,\nputting a wall that\nraises Sp. Defense.");
static const u8 sMoveFourLineDescription_BaddyBad[] = _("The user acts bad\nand attacks,\nputting a wall that\nraises Defense.");
static const u8 sMoveFourLineDescription_SappySeed[] = _("Grows a giant stalk,\nscattering seeds\nthat drain the foe's\nHP every turn.");
static const u8 sMoveFourLineDescription_FreezyFrost[] = _("Attack with crystal\nmade of cold frozen\nhaze. It eliminates\nall stat changes.");
static const u8 sMoveFourLineDescription_SparklySwirl[] = _("Wraps foe with a\nwhirlwind of scent.\nIt heals all status\nof the user's party.");
static const u8 sMoveFourLineDescription_VeeveeVolley[] = _("Eevee's love for\nits trainer raises\nthis move's power.\nIt never misses.");
static const u8 sMoveFourLineDescription_DoubleIronBash[] = _("Spinning rapidly,\nthe user strikes\ntwice. Has\n30% flinch chance."); // new

// GEN 8
static const u8 sMoveFourLineDescription_DynamaxCannon[] = _("The user unleashes\na strong beam that\ndamages Dynamaxed\nfoes twice as hard.");
static const u8 sMoveFourLineDescription_SnipeShot[] = _("The user ignores\neffects that draw\nin moves. High crit.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_JawLock[] = _("Prevents both the\nuser and the foe\nfrom switching out.\nStrong Jaw boost."); // new
static const u8 sMoveFourLineDescription_StuffCheeks[] = _("The user eats its\nheld Berry, then\nsharply raises its\nDefense stat.");
static const u8 sMoveFourLineDescription_NoRetreat[] = _("Ups all the user's\nstats. However, the\nuser cannot switch\nout or flee.");
static const u8 sMoveFourLineDescription_TarShot[] = _("Sticky tar lowers\nthe foe's Speed,\nand makes it weaker\nto Fire-type moves.");
static const u8 sMoveFourLineDescription_MagicPowder[] = _("A cloud of magic\npowder that changes\nthe foe to Psychic-\ntype.");
static const u8 sMoveFourLineDescription_DragonDarts[] = _("The user attacks\ntwice. No additional\neffect."); // new
static const u8 sMoveFourLineDescription_Teatime[] = _("All Pokémon in the\nbattle have\nteatime, and eat\ntheir held Berry.");
static const u8 sMoveFourLineDescription_Octolock[] = _("Prevents escape,\nand lowers the Sp.\nDef and Defense of\nthe foe each turn.");
static const u8 sMoveFourLineDescription_BoltBeak[] = _("If attacking before\nthe target, move power\ndoubles. Strong Jaw\nboost"); // new
static const u8 sMoveFourLineDescription_CourtChange[] = _("A mysterious power\nthat swaps the\neffects on either\nside of the field.");
static const u8 sMoveFourLineDescription_ClangorousSoul[] = _("The user raises all\nits stats by using\n1/3 of its HP."); // new
static const u8 sMoveFourLineDescription_BodyPress[] = _("A body slam attack\nwhich inflicts more\ndamage the higher\nthe user's Defense.");
static const u8 sMoveFourLineDescription_Decorate[] = _("The user sharply\nraises the target's\nAttack and Sp. Atk\nstats by decorating.");
static const u8 sMoveFourLineDescription_DrumBeating[] = _("The user attacks\nthe foe with its\ndrum, lowering the\nfoe's Speed stat.");
static const u8 sMoveFourLineDescription_SnapTrap[] = _("The user snares the\ntarget in a snap\ntrap for four to\nfive turns.");
static const u8 sMoveFourLineDescription_PyroBall[] = _("The user launches a\nfiery ball at the\nfoe. 10% chance\nto burn the foe."); // new
static const u8 sMoveFourLineDescription_BehemothBlade[] = _("The user strikes as\na sword, dealing\ndouble the damage\nto Dynamaxed foes.");
static const u8 sMoveFourLineDescription_BehemothBash[] = _("The user strikes as\na shield, dealing\ndouble the damage\nto Dynamaxed foes.");
static const u8 sMoveFourLineDescription_AuraWheel[] = _("The user attacks to\nup its Speed. The\nuser's form changes\nthis move's type.");
static const u8 sMoveFourLineDescription_BreakingSwipe[] = _("The user swings at\nboth foes with its\ntail, lowering the\nfoes' Attack stat.");
static const u8 sMoveFourLineDescription_BranchPoke[] = _("The user attacks\nthe foe by poking\nit with a sharply\npointed branch.");
static const u8 sMoveFourLineDescription_Overdrive[] = _("The user twangs its\nguitar to attack\nboth foes with a\nhuge, echoing boom.");
static const u8 sMoveFourLineDescription_AppleAcid[] = _("An acidic liquid\nattack created from\ntart apples. Lowers\nthe foe's Sp. Def.");
static const u8 sMoveFourLineDescription_GravApple[] = _("The user drops an\napple from high on\nthe foe, lowering\nthe foe's Defense.");
static const u8 sMoveFourLineDescription_SpiritBreak[] = _("A forceful, spirit-\nbreaking attack\nthat lowers the\nfoe's Sp. Atk stat.");
static const u8 sMoveFourLineDescription_StrangeSteam[] = _("The user attacks by\nemitting steam.\n20% chance to\nconfuse the foe."); // new
static const u8 sMoveFourLineDescription_LifeDew[] = _("The user restores\nthe HP of itself\nand its allies with\nmysterious water.");
static const u8 sMoveFourLineDescription_Obstruct[] = _("Protects the user,\nand harshly lowers\nthe Defense of foes\nthat make contact.");
static const u8 sMoveFourLineDescription_FalseSurrender[] = _("The user pretends\nto bow, then stabs\nits foe. This move\nnever misses.");
static const u8 sMoveFourLineDescription_MeteorAssault[] = _("Attacks wildly with\na thick leek. Needs\nrecharging. Keen Edge\nboost."); // new
static const u8 sMoveFourLineDescription_Eternabeam[] = _("Eternatus's most\npowerful move. On\nthe next turn, the\nuser must rest.");
static const u8 sMoveFourLineDescription_SteelBeam[] = _("Fires a powerful\nbeam of steel.\n50% recoil damage.\nMega Launcher boost."); // new

static const u8 sMoveFourLineDescription_ExpandingForce[] = _("This move's power\ngoes up and damages\nall foes while on\nPsychic Terrain.");
static const u8 sMoveFourLineDescription_SteelRoller[] = _("It destroys the\ncurrent terrain.\nFails if the ground\nisn't a terrain.");
static const u8 sMoveFourLineDescription_ScaleShot[] = _("Hits 2 to 5 times.\nBoosts Speed, but\nlowers Defense.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_MeteorBeam[] = _("A 2-turn move that\ngathers space power\nraising Sp. Attack\nbefore attacking.");
static const u8 sMoveFourLineDescription_ShellSideArm[] = _("Physical or special\ndamage, whichever\nis more effective\nMay poison the foe.");
static const u8 sMoveFourLineDescription_MistyExplosion[] = _("Attacks everything\nand faints the user.\nIts power increases\non Misty Terrain.");
static const u8 sMoveFourLineDescription_GrassyGlide[] = _("Gliding on the\nground, it attacks.\nAlways goes first\non Grassy Terrain.");
static const u8 sMoveFourLineDescription_RisingVoltage[] = _("Its power doubles\non Electric Terrain\nwhen the target\nis grounded.");
static const u8 sMoveFourLineDescription_TerrainPulse[] = _("This move's type\nand power changes\ndepending on the\nterrain when used.");
static const u8 sMoveFourLineDescription_SkitterSmack[] = _("The user skitters\nbehind the foe to\nattack. This lowers\nthe foe's Sp. Atk.");
static const u8 sMoveFourLineDescription_BurningJealousy[] = _("Attacks both foes\njealously. Has 50%\nburn chance."); // new
static const u8 sMoveFourLineDescription_LashOut[] = _("If the user's stats\nwere lowered in this\nturn, the move's\npower is doubled.");
static const u8 sMoveFourLineDescription_Poltergeist[] = _("Controls the foe's\nitem to attack.\nIt fails if the foe\nhas no item.");
static const u8 sMoveFourLineDescription_CorrosiveGas[] = _("Highly acidic gas\nthat melts items\nheld by every\nsurrounding {PKMN}.");
static const u8 sMoveFourLineDescription_Coaching[] = _("The user properly\ncoaches its ally {PKMN},\nupping their Attack\nand Defense.");
static const u8 sMoveFourLineDescription_DualWingbeat[] = _("The user slams the\nfoe with its wings.\nHits twice.\nAir-based."); // new
static const u8 sMoveFourLineDescription_ScorchingSands[] = _("Throws scorching\nsand at the target.\n30% chance to\nburn the target."); // new
static const u8 sMoveFourLineDescription_JungleHealing[] = _("Becomes one with\nthe jungle, healing\nHP and status of\nitself and allies.");
static const u8 sMoveFourLineDescription_WickedBlow[] = _("Having mastered the\nDark style, strikes\nwith a fierce blow.\nIron Fist boost."); // new
static const u8 sMoveFourLineDescription_SurgingStrikes[] = _("Having mastered the\nWater style, strikes\n3 critical hits with\na flowing motion.");
#if B_BINDING_TURNS >= GEN_5
static const u8 sMoveFourLineDescription_ThunderCage[] = _("The user traps the\nfoe in a cage of\nelectricity for\nfour or five turns.");
#else
static const u8 sMoveFourLineDescription_ThunderCage[] = _("The user traps the\nfoe in a cage of\nelectricity for\ntwo to five turns.");
#endif
static const u8 sMoveFourLineDescription_DragonEnergy[] = _("The higher the\nuser's HP, the more\npowerful it is.\nMega Launcher boost"); // new
#if B_USE_FROSTBITE == TRUE
    static const u8 sMoveFourLineDescription_FreezingGlare[] = _("The user shoots\npsychic power from\nits eyes to attack.\n10% frostbite chance."); // new
#else
    static const u8 sMoveFourLineDescription_FreezingGlare[] = _("The user shoots\npsychic power from\nits eyes to attack.\n10% freeze chance."); // new
#endif
static const u8 sMoveFourLineDescription_FieryWrath[] = _("It uses its wrath to\nfuel a fire-like aura\nattack. Has 20%\nflinch chance."); // new
static const u8 sMoveFourLineDescription_ThunderousKick[] = _("Fast lightning\nkick. It lowers\nthe foe's Defense.\nStriker boost."); // new
static const u8 sMoveFourLineDescription_GlacialLance[] = _("Strikes by hurling\na blizzard-cloaked\nicicle lance at\nopposing Pokémon.");
static const u8 sMoveFourLineDescription_AstralBarrage[] = _("Strikes by sending\na frightful amount\nof small ghosts at\nopposing Pokémon.");
static const u8 sMoveFourLineDescription_EerieSpell[] = _("Attacks with its\ntremendous psychic\npower. Foe's last\nmove has 3 PP cut.");

// Darky's Custom Moves
static const u8 sMoveFourLineDescription_Deathroll[] = _("20% confusion chance.\nStrong Jaw boost.\nIgnores target's\nstat changes."); // new
static const u8 sMoveFourLineDescription_Excalibur[] = _("Double damage\non Dragons.\nHigh critical ratio.\nKeen Edge boost."); // new
static const u8 sMoveFourLineDescription_AquaFang[] = _("Bites with aquatic\nfangs. Has 10%\nflinch chance.\nStrong Jaw boost."); // new
static const u8 sMoveFourLineDescription_WaveCrash[] = _("Slams the whole body\ninto the target\nwith lots of water.\n33% recoil."); // new
static const u8 sMoveFourLineDescription_Smite[] = _("Attacks from above\nwith strong electricity.\n20% paralysis chance.\nSmack Down effect."); // new
static const u8 sMoveFourLineDescription_Outburst[] = _("The user explodes\nto inflict terrible\ndamage even while\nfainting itself."); // new
static const u8 sMoveFourLineDescription_IronFangs[]     = _("Breaks any barrier\nlike Light Screen\nand Reflect.\nStrong Jaw boost."); // new
static const u8 sMoveFourLineDescription_LovelyBite[]    = _("An affectionate bite.\n10% chance to\ninfatuate the foe.\nStrong Jaw boost."); // new
static const u8 sMoveFourLineDescription_ShadowFangs[]   = _("The foe shudders.\n10% chance to\ncurse the foe.\nStrong Jaw boost."); // new
static const u8 sMoveFourLineDescription_JaggedFangs[]   = _("A ferocious bite.\n10% chance to\nraise user's Attack.\nStrong Jaw boost."); // new
static const u8 sMoveFourLineDescription_ScorchedEarth[] = _("Fire- and Ground-\ntype at the same\ntime. Has 10%\nburn chance."); // new
static const u8 sMoveFourLineDescription_SeismicFist[] = _("Throws a ground-\nbreaking fist.\n20% chance to drop\nthe foe's Def."); // new
static const u8 sMoveFourLineDescription_RagingFury[] = _("The user thrashes\nabout for two to\nthree turns, then\nbecomes confused."); // new
static const u8 sMoveFourLineDescription_PlasmaPulse[] = _("Double damage\nagainst status.\n10% paralyze chance.\nMega Launcher boost"); // new
static const u8 sMoveFourLineDescription_PixeBeam[] = _("The foe is hit with\nintense fairy magic.\nIt has a 30% chance\nto drop SpA."); // new
static const u8 sMoveFourLineDescription_PixeSlash[] = _("The foe is slashed\nwith a whimsical\nblade. High Crit ratio.\nKeen Edge boost."); // new
static const u8 sMoveFourLineDescription_ArcherShot[] = _("Shoots a dead center\narrow at the target.\nArcher boost."); // new
static const u8 sMoveFourLineDescription_FrostBrand[] = _("The foe is slashed with\na cryo blade. 10% chance\nto inflict frostbite.\nKeen Edge boost."); // new
static const u8 sMoveFourLineDescription_SeismicBlade[] = _("The foe is slashed\nwith a tectonic\nblade. High Crit ratio.\nKeen Edge boost."); // new
static const u8 sMoveFourLineDescription_MountainChunk[] = _("Hurls a chunk of a\nmountain at the\nopponent. 30% Flinch chance.\nMega Launcher Boosted."); // new

const u8 *const gMoveFourLineDescriptionPointers[MOVES_COUNT - 1] = {
    [MOVE_POUND         - 1] = sMoveFourLineDescription_Pound,
    [MOVE_KARATE_CHOP   - 1] = sMoveFourLineDescription_KarateChop,
    [MOVE_DOUBLE_SLAP   - 1] = sMoveFourLineDescription_DoubleSlap,
    [MOVE_COMET_PUNCH   - 1] = sMoveFourLineDescription_CometPunch,
    [MOVE_MEGA_PUNCH    - 1] = sMoveFourLineDescription_MegaPunch,
    [MOVE_PAY_DAY       - 1] = sMoveFourLineDescription_PayDay,
    [MOVE_FIRE_PUNCH    - 1] = sMoveFourLineDescription_FirePunch,
    [MOVE_ICE_PUNCH     - 1] = sMoveFourLineDescription_IcePunch,
    [MOVE_THUNDER_PUNCH - 1] = sMoveFourLineDescription_ThunderPunch,
    [MOVE_SCRATCH       - 1] = sMoveFourLineDescription_Scratch,
    [MOVE_VISE_GRIP     - 1] = sMoveFourLineDescription_ViseGrip,
    [MOVE_GUILLOTINE    - 1] = sMoveFourLineDescription_Guillotine,
    [MOVE_RAZOR_WIND    - 1] = sMoveFourLineDescription_RazorWind,
    [MOVE_SWORDS_DANCE  - 1] = sMoveFourLineDescription_SwordsDance,
    [MOVE_CUT           - 1] = sMoveFourLineDescription_Cut,
    [MOVE_GUST          - 1] = sMoveFourLineDescription_Gust,
    [MOVE_WING_ATTACK   - 1] = sMoveFourLineDescription_WingAttack,
    [MOVE_WHIRLWIND     - 1] = sMoveFourLineDescription_Whirlwind,
    [MOVE_FLY           - 1] = sMoveFourLineDescription_Fly,
    [MOVE_BIND          - 1] = sMoveFourLineDescription_Bind,
    [MOVE_SLAM          - 1] = sMoveFourLineDescription_Slam,
    [MOVE_VINE_WHIP     - 1] = sMoveFourLineDescription_VineWhip,
    [MOVE_STOMP         - 1] = sMoveFourLineDescription_Stomp,
    [MOVE_DOUBLE_KICK   - 1] = sMoveFourLineDescription_DoubleKick,
    [MOVE_MEGA_KICK     - 1] = sMoveFourLineDescription_MegaKick,
    [MOVE_JUMP_KICK     - 1] = sMoveFourLineDescription_JumpKick,
    [MOVE_ROLLING_KICK  - 1] = sMoveFourLineDescription_RollingKick,
    [MOVE_SAND_ATTACK   - 1] = sMoveFourLineDescription_SandAttack,
    [MOVE_HEADBUTT      - 1] = sMoveFourLineDescription_Headbutt,
    [MOVE_HORN_ATTACK   - 1] = sMoveFourLineDescription_HornAttack,
    [MOVE_FURY_ATTACK   - 1] = sMoveFourLineDescription_FuryAttack,
    [MOVE_HORN_DRILL    - 1] = sMoveFourLineDescription_HornDrill,
    [MOVE_TACKLE        - 1] = sMoveFourLineDescription_Tackle,
    [MOVE_BODY_SLAM     - 1] = sMoveFourLineDescription_BodySlam,
    [MOVE_WRAP          - 1] = sMoveFourLineDescription_Wrap,
    [MOVE_TAKE_DOWN     - 1] = sMoveFourLineDescription_TakeDown,
    [MOVE_THRASH        - 1] = sMoveFourLineDescription_Thrash,
    [MOVE_DOUBLE_EDGE   - 1] = sMoveFourLineDescription_DoubleEdge,
    [MOVE_TAIL_WHIP     - 1] = sMoveFourLineDescription_TailWhip,
    [MOVE_POISON_STING  - 1] = sMoveFourLineDescription_PoisonSting,
    [MOVE_TWINEEDLE     - 1] = sMoveFourLineDescription_Twineedle,
    [MOVE_PIN_MISSILE   - 1] = sMoveFourLineDescription_PinMissile,
    [MOVE_LEER          - 1] = sMoveFourLineDescription_Leer,
    [MOVE_BITE          - 1] = sMoveFourLineDescription_Bite,
    [MOVE_GROWL         - 1] = sMoveFourLineDescription_Growl,
    [MOVE_ROAR          - 1] = sMoveFourLineDescription_Roar,
    [MOVE_SING          - 1] = sMoveFourLineDescription_Sing,
    [MOVE_SUPERSONIC    - 1] = sMoveFourLineDescription_Supersonic,
    [MOVE_SONIC_BOOM    - 1] = sMoveFourLineDescription_SonicBoom,
    [MOVE_DISABLE       - 1] = sMoveFourLineDescription_Disable,
    [MOVE_ACID          - 1] = sMoveFourLineDescription_Acid,
    [MOVE_EMBER         - 1] = sMoveFourLineDescription_Ember,
    [MOVE_FLAMETHROWER  - 1] = sMoveFourLineDescription_Flamethrower,
    [MOVE_MIST          - 1] = sMoveFourLineDescription_Mist,
    [MOVE_WATER_GUN     - 1] = sMoveFourLineDescription_WaterGun,
    [MOVE_HYDRO_PUMP    - 1] = sMoveFourLineDescription_HydroPump,
    [MOVE_SURF          - 1] = sMoveFourLineDescription_Surf,
    [MOVE_ICE_BEAM      - 1] = sMoveFourLineDescription_IceBeam,
    [MOVE_BLIZZARD      - 1] = sMoveFourLineDescription_Blizzard,
    [MOVE_PSYBEAM       - 1] = sMoveFourLineDescription_Psybeam,
    [MOVE_BUBBLE_BEAM   - 1] = sMoveFourLineDescription_BubbleBeam,
    [MOVE_AURORA_BEAM   - 1] = sMoveFourLineDescription_AuroraBeam,
    [MOVE_HYPER_BEAM    - 1] = sMoveFourLineDescription_HyperBeam,
    [MOVE_PECK          - 1] = sMoveFourLineDescription_Peck,
    [MOVE_DRILL_PECK    - 1] = sMoveFourLineDescription_DrillPeck,
    [MOVE_SUBMISSION    - 1] = sMoveFourLineDescription_Submission,
    [MOVE_LOW_KICK      - 1] = sMoveFourLineDescription_LowKick,
    [MOVE_COUNTER       - 1] = sMoveFourLineDescription_Counter,
    [MOVE_SEISMIC_TOSS  - 1] = sMoveFourLineDescription_SeismicToss,
    [MOVE_STRENGTH      - 1] = sMoveFourLineDescription_Strength,
    [MOVE_ABSORB        - 1] = sMoveFourLineDescription_Absorb,
    [MOVE_MEGA_DRAIN    - 1] = sMoveFourLineDescription_MegaDrain,
    [MOVE_LEECH_SEED    - 1] = sMoveFourLineDescription_LeechSeed,
    [MOVE_GROWTH        - 1] = sMoveFourLineDescription_Growth,
    [MOVE_RAZOR_LEAF    - 1] = sMoveFourLineDescription_RazorLeaf,
    [MOVE_SOLAR_BEAM    - 1] = sMoveFourLineDescription_SolarBeam,
    [MOVE_POISON_POWDER - 1] = sMoveFourLineDescription_PoisonPowder,
    [MOVE_STUN_SPORE    - 1] = sMoveFourLineDescription_StunSpore,
    [MOVE_SLEEP_POWDER  - 1] = sMoveFourLineDescription_SleepPowder,
    [MOVE_PETAL_DANCE   - 1] = sMoveFourLineDescription_PetalDance,
    [MOVE_STRING_SHOT   - 1] = sMoveFourLineDescription_StringShot,
    [MOVE_DRAGON_RAGE   - 1] = sMoveFourLineDescription_DragonRage,
    [MOVE_FIRE_SPIN     - 1] = sMoveFourLineDescription_FireSpin,
    [MOVE_THUNDER_SHOCK - 1] = sMoveFourLineDescription_ThunderShock,
    [MOVE_THUNDERBOLT   - 1] = sMoveFourLineDescription_Thunderbolt,
    [MOVE_THUNDER_WAVE  - 1] = sMoveFourLineDescription_ThunderWave,
    [MOVE_THUNDER       - 1] = sMoveFourLineDescription_Thunder,
    [MOVE_ROCK_THROW    - 1] = sMoveFourLineDescription_RockThrow,
    [MOVE_EARTHQUAKE    - 1] = sMoveFourLineDescription_Earthquake,
    [MOVE_FISSURE       - 1] = sMoveFourLineDescription_Fissure,
    [MOVE_DIG           - 1] = sMoveFourLineDescription_Dig,
    [MOVE_TOXIC         - 1] = sMoveFourLineDescription_Toxic,
    [MOVE_CONFUSION     - 1] = sMoveFourLineDescription_Confusion,
    [MOVE_PSYCHIC       - 1] = sMoveFourLineDescription_Psychic,
    [MOVE_HYPNOSIS      - 1] = sMoveFourLineDescription_Hypnosis,
    [MOVE_MEDITATE      - 1] = sMoveFourLineDescription_Meditate,
    [MOVE_AGILITY       - 1] = sMoveFourLineDescription_Agility,
    [MOVE_QUICK_ATTACK  - 1] = sMoveFourLineDescription_QuickAttack,
    [MOVE_RAGE          - 1] = sMoveFourLineDescription_Rage,
    [MOVE_TELEPORT      - 1] = sMoveFourLineDescription_Teleport,
    [MOVE_NIGHT_SHADE   - 1] = sMoveFourLineDescription_NightShade,
    [MOVE_MIMIC         - 1] = sMoveFourLineDescription_Mimic,
    [MOVE_SCREECH       - 1] = sMoveFourLineDescription_Screech,
    [MOVE_DOUBLE_TEAM   - 1] = sMoveFourLineDescription_DoubleTeam,
    [MOVE_RECOVER       - 1] = sMoveFourLineDescription_Recover,
    [MOVE_HARDEN        - 1] = sMoveFourLineDescription_Harden,
    [MOVE_MINIMIZE      - 1] = sMoveFourLineDescription_Minimize,
    [MOVE_SMOKESCREEN   - 1] = sMoveFourLineDescription_Smokescreen,
    [MOVE_CONFUSE_RAY   - 1] = sMoveFourLineDescription_ConfuseRay,
    [MOVE_WITHDRAW      - 1] = sMoveFourLineDescription_Withdraw,
    [MOVE_DEFENSE_CURL  - 1] = sMoveFourLineDescription_DefenseCurl,
    [MOVE_BARRIER       - 1] = sMoveFourLineDescription_Barrier,
    [MOVE_LIGHT_SCREEN  - 1] = sMoveFourLineDescription_LightScreen,
    [MOVE_HAZE          - 1] = sMoveFourLineDescription_Haze,
    [MOVE_REFLECT       - 1] = sMoveFourLineDescription_Reflect,
    [MOVE_FOCUS_ENERGY  - 1] = sMoveFourLineDescription_FocusEnergy,
    [MOVE_BIDE          - 1] = sMoveFourLineDescription_Bide,
    [MOVE_METRONOME     - 1] = sMoveFourLineDescription_Metronome,
    [MOVE_MIRROR_MOVE   - 1] = sMoveFourLineDescription_MirrorMove,
    [MOVE_SELF_DESTRUCT - 1] = sMoveFourLineDescription_SelfDestruct,
    [MOVE_EGG_BOMB      - 1] = sMoveFourLineDescription_EggBomb,
    [MOVE_LICK          - 1] = sMoveFourLineDescription_Lick,
    [MOVE_SMOG          - 1] = sMoveFourLineDescription_Smog,
    [MOVE_SLUDGE        - 1] = sMoveFourLineDescription_Sludge,
    [MOVE_BONE_CLUB     - 1] = sMoveFourLineDescription_BoneClub,
    [MOVE_FIRE_BLAST    - 1] = sMoveFourLineDescription_FireBlast,
    [MOVE_WATERFALL     - 1] = sMoveFourLineDescription_Waterfall,
    [MOVE_CLAMP         - 1] = sMoveFourLineDescription_Clamp,
    [MOVE_SWIFT         - 1] = sMoveFourLineDescription_Swift,
    [MOVE_SKULL_BASH    - 1] = sMoveFourLineDescription_SkullBash,
    [MOVE_SPIKE_CANNON  - 1] = sMoveFourLineDescription_SpikeCannon,
    [MOVE_CONSTRICT     - 1] = sMoveFourLineDescription_Constrict,
    [MOVE_AMNESIA       - 1] = sMoveFourLineDescription_Amnesia,
    [MOVE_KINESIS       - 1] = sMoveFourLineDescription_Kinesis,
    [MOVE_SOFT_BOILED   - 1] = sMoveFourLineDescription_SoftBoiled,
    [MOVE_HIGH_JUMP_KICK - 1] = sMoveFourLineDescription_HighJumpKick,
    [MOVE_GLARE         - 1] = sMoveFourLineDescription_Glare,
    [MOVE_DREAM_EATER   - 1] = sMoveFourLineDescription_DreamEater,
    [MOVE_POISON_GAS    - 1] = sMoveFourLineDescription_PoisonGas,
    [MOVE_BARRAGE       - 1] = sMoveFourLineDescription_Barrage,
    [MOVE_LEECH_LIFE    - 1] = sMoveFourLineDescription_LeechLife,
    [MOVE_LOVELY_KISS   - 1] = sMoveFourLineDescription_LovelyKiss,
    [MOVE_SKY_ATTACK    - 1] = sMoveFourLineDescription_SkyAttack,
    [MOVE_TRANSFORM     - 1] = sMoveFourLineDescription_Transform,
    [MOVE_BUBBLE        - 1] = sMoveFourLineDescription_Bubble,
    [MOVE_DIZZY_PUNCH   - 1] = sMoveFourLineDescription_DizzyPunch,
    [MOVE_SPORE         - 1] = sMoveFourLineDescription_Spore,
    [MOVE_FLASH         - 1] = sMoveFourLineDescription_Flash,
    [MOVE_PSYWAVE       - 1] = sMoveFourLineDescription_Psywave,
    [MOVE_SPLASH        - 1] = sMoveFourLineDescription_Splash,
    [MOVE_ACID_ARMOR    - 1] = sMoveFourLineDescription_AcidArmor,
    [MOVE_CRABHAMMER    - 1] = sMoveFourLineDescription_Crabhammer,
    [MOVE_EXPLOSION     - 1] = sMoveFourLineDescription_Explosion,
    [MOVE_FURY_SWIPES   - 1] = sMoveFourLineDescription_FurySwipes,
    [MOVE_BONEMERANG    - 1] = sMoveFourLineDescription_Bonemerang,
    [MOVE_REST          - 1] = sMoveFourLineDescription_Rest,
    [MOVE_ROCK_SLIDE    - 1] = sMoveFourLineDescription_RockSlide,
    [MOVE_HYPER_FANG    - 1] = sMoveFourLineDescription_HyperFang,
    [MOVE_SHARPEN       - 1] = sMoveFourLineDescription_Sharpen,
    [MOVE_CONVERSION    - 1] = sMoveFourLineDescription_Conversion,
    [MOVE_TRI_ATTACK    - 1] = sMoveFourLineDescription_TriAttack,
    [MOVE_SUPER_FANG    - 1] = sMoveFourLineDescription_SuperFang,
    [MOVE_SLASH         - 1] = sMoveFourLineDescription_Slash,
    [MOVE_SUBSTITUTE    - 1] = sMoveFourLineDescription_Substitute,
    [MOVE_STRUGGLE      - 1] = sMoveFourLineDescription_Struggle,
    [MOVE_SKETCH        - 1] = sMoveFourLineDescription_Sketch,
    [MOVE_TRIPLE_KICK   - 1] = sMoveFourLineDescription_TripleKick,
    [MOVE_THIEF         - 1] = sMoveFourLineDescription_Thief,
    [MOVE_SPIDER_WEB    - 1] = sMoveFourLineDescription_SpiderWeb,
    [MOVE_MIND_READER   - 1] = sMoveFourLineDescription_MindReader,
    [MOVE_NIGHTMARE     - 1] = sMoveFourLineDescription_Nightmare,
    [MOVE_FLAME_WHEEL   - 1] = sMoveFourLineDescription_FlameWheel,
    [MOVE_SNORE         - 1] = sMoveFourLineDescription_Snore,
    [MOVE_CURSE         - 1] = sMoveFourLineDescription_Curse,
    [MOVE_FLAIL         - 1] = sMoveFourLineDescription_Flail,
    [MOVE_CONVERSION_2  - 1] = sMoveFourLineDescription_Conversion2,
    [MOVE_AEROBLAST     - 1] = sMoveFourLineDescription_Aeroblast,
    [MOVE_COTTON_SPORE  - 1] = sMoveFourLineDescription_CottonSpore,
    [MOVE_REVERSAL      - 1] = sMoveFourLineDescription_Reversal,
    [MOVE_SPITE         - 1] = sMoveFourLineDescription_Spite,
    [MOVE_POWDER_SNOW   - 1] = sMoveFourLineDescription_PowderSnow,
    [MOVE_PROTECT       - 1] = sMoveFourLineDescription_Protect,
    [MOVE_MACH_PUNCH    - 1] = sMoveFourLineDescription_MachPunch,
    [MOVE_SCARY_FACE    - 1] = sMoveFourLineDescription_ScaryFace,
    [MOVE_FEINT_ATTACK  - 1] = sMoveFourLineDescription_FeintAttack,
    [MOVE_SWEET_KISS    - 1] = sMoveFourLineDescription_SweetKiss,
    [MOVE_BELLY_DRUM    - 1] = sMoveFourLineDescription_BellyDrum,
    [MOVE_SLUDGE_BOMB   - 1] = sMoveFourLineDescription_SludgeBomb,
    [MOVE_MUD_SLAP      - 1] = sMoveFourLineDescription_MudSlap,
    [MOVE_OCTAZOOKA     - 1] = sMoveFourLineDescription_Octazooka,
    [MOVE_SPIKES        - 1] = sMoveFourLineDescription_Spikes,
    [MOVE_ZAP_CANNON    - 1] = sMoveFourLineDescription_ZapCannon,
    [MOVE_FORESIGHT     - 1] = sMoveFourLineDescription_Foresight,
    [MOVE_DESTINY_BOND  - 1] = sMoveFourLineDescription_DestinyBond,
    [MOVE_PERISH_SONG   - 1] = sMoveFourLineDescription_PerishSong,
    [MOVE_ICY_WIND      - 1] = sMoveFourLineDescription_IcyWind,
    [MOVE_DETECT        - 1] = sMoveFourLineDescription_Detect,
    [MOVE_BONE_RUSH     - 1] = sMoveFourLineDescription_BoneRush,
    [MOVE_LOCK_ON       - 1] = sMoveFourLineDescription_LockOn,
    [MOVE_OUTRAGE       - 1] = sMoveFourLineDescription_Outrage,
    [MOVE_SANDSTORM     - 1] = sMoveFourLineDescription_Sandstorm,
    [MOVE_GIGA_DRAIN    - 1] = sMoveFourLineDescription_GigaDrain,
    [MOVE_ENDURE        - 1] = sMoveFourLineDescription_Endure,
    [MOVE_CHARM         - 1] = sMoveFourLineDescription_Charm,
    [MOVE_ROLLOUT       - 1] = sMoveFourLineDescription_Rollout,
    [MOVE_FALSE_SWIPE   - 1] = sMoveFourLineDescription_FalseSwipe,
    [MOVE_SWAGGER       - 1] = sMoveFourLineDescription_Swagger,
    [MOVE_MILK_DRINK    - 1] = sMoveFourLineDescription_MilkDrink,
    [MOVE_SPARK         - 1] = sMoveFourLineDescription_Spark,
    [MOVE_FURY_CUTTER   - 1] = sMoveFourLineDescription_FuryCutter,
    [MOVE_STEEL_WING    - 1] = sMoveFourLineDescription_SteelWing,
    [MOVE_MEAN_LOOK     - 1] = sMoveFourLineDescription_MeanLook,
    [MOVE_ATTRACT       - 1] = sMoveFourLineDescription_Attract,
    [MOVE_SLEEP_TALK    - 1] = sMoveFourLineDescription_SleepTalk,
    [MOVE_HEAL_BELL     - 1] = sMoveFourLineDescription_HealBell,
    [MOVE_RETURN        - 1] = sMoveFourLineDescription_Return,
    [MOVE_PRESENT       - 1] = sMoveFourLineDescription_Present,
    [MOVE_FRUSTRATION   - 1] = sMoveFourLineDescription_Frustration,
    [MOVE_SAFEGUARD     - 1] = sMoveFourLineDescription_Safeguard,
    [MOVE_PAIN_SPLIT    - 1] = sMoveFourLineDescription_PainSplit,
    [MOVE_SACRED_FIRE   - 1] = sMoveFourLineDescription_SacredFire,
    [MOVE_MAGNITUDE     - 1] = sMoveFourLineDescription_Magnitude,
    [MOVE_DYNAMIC_PUNCH - 1] = sMoveFourLineDescription_DynamicPunch,
    [MOVE_MEGAHORN      - 1] = sMoveFourLineDescription_Megahorn,
    [MOVE_DRAGON_BREATH - 1] = sMoveFourLineDescription_DragonBreath,
    [MOVE_BATON_PASS    - 1] = sMoveFourLineDescription_BatonPass,
    [MOVE_ENCORE        - 1] = sMoveFourLineDescription_Encore,
    [MOVE_PURSUIT       - 1] = sMoveFourLineDescription_Pursuit,
    [MOVE_RAPID_SPIN    - 1] = sMoveFourLineDescription_RapidSpin,
    [MOVE_SWEET_SCENT   - 1] = sMoveFourLineDescription_SweetScent,
    [MOVE_IRON_TAIL     - 1] = sMoveFourLineDescription_IronTail,
    [MOVE_METAL_CLAW    - 1] = sMoveFourLineDescription_MetalClaw,
    [MOVE_VITAL_THROW   - 1] = sMoveFourLineDescription_VitalThrow,
    [MOVE_MORNING_SUN   - 1] = sMoveFourLineDescription_MorningSun,
    [MOVE_SYNTHESIS     - 1] = sMoveFourLineDescription_Synthesis,
    [MOVE_MOONLIGHT     - 1] = sMoveFourLineDescription_Moonlight,
    [MOVE_HIDDEN_POWER  - 1] = sMoveFourLineDescription_HiddenPower,
    [MOVE_CROSS_CHOP    - 1] = sMoveFourLineDescription_CrossChop,
    [MOVE_TWISTER       - 1] = sMoveFourLineDescription_Twister,
    [MOVE_RAIN_DANCE    - 1] = sMoveFourLineDescription_RainDance,
    [MOVE_SUNNY_DAY     - 1] = sMoveFourLineDescription_SunnyDay,
    [MOVE_CRUNCH        - 1] = sMoveFourLineDescription_Crunch,
    [MOVE_MIRROR_COAT   - 1] = sMoveFourLineDescription_MirrorCoat,
    [MOVE_PSYCH_UP      - 1] = sMoveFourLineDescription_PsychUp,
    [MOVE_EXTREME_SPEED - 1] = sMoveFourLineDescription_ExtremeSpeed,
    [MOVE_ANCIENT_POWER - 1] = sMoveFourLineDescription_AncientPower,
    [MOVE_SHADOW_BALL   - 1] = sMoveFourLineDescription_ShadowBall,
    [MOVE_FUTURE_SIGHT  - 1] = sMoveFourLineDescription_FutureSight,
    [MOVE_ROCK_SMASH    - 1] = sMoveFourLineDescription_RockSmash,
    [MOVE_WHIRLPOOL     - 1] = sMoveFourLineDescription_Whirlpool,
    [MOVE_BEAT_UP       - 1] = sMoveFourLineDescription_BeatUp,
    [MOVE_FAKE_OUT      - 1] = sMoveFourLineDescription_FakeOut,
    [MOVE_UPROAR        - 1] = sMoveFourLineDescription_Uproar,
    [MOVE_STOCKPILE     - 1] = sMoveFourLineDescription_Stockpile,
    [MOVE_SPIT_UP       - 1] = sMoveFourLineDescription_SpitUp,
    [MOVE_SWALLOW       - 1] = sMoveFourLineDescription_Swallow,
    [MOVE_HEAT_WAVE     - 1] = sMoveFourLineDescription_HeatWave,
    [MOVE_HAIL          - 1] = sMoveFourLineDescription_Hail,
    [MOVE_TORMENT       - 1] = sMoveFourLineDescription_Torment,
    [MOVE_FLATTER       - 1] = sMoveFourLineDescription_Flatter,
    [MOVE_WILL_O_WISP   - 1] = sMoveFourLineDescription_WillOWisp,
    [MOVE_MEMENTO       - 1] = sMoveFourLineDescription_Memento,
    [MOVE_FACADE        - 1] = sMoveFourLineDescription_Facade,
    [MOVE_FOCUS_PUNCH   - 1] = sMoveFourLineDescription_FocusPunch,
    [MOVE_SMELLING_SALTS - 1] = sMoveFourLineDescription_SmellingSalts,
    [MOVE_FOLLOW_ME     - 1] = sMoveFourLineDescription_FollowMe,
    [MOVE_NATURE_POWER  - 1] = sMoveFourLineDescription_NaturePower,
    [MOVE_CHARGE        - 1] = sMoveFourLineDescription_Charge,
    [MOVE_TAUNT         - 1] = sMoveFourLineDescription_Taunt,
    [MOVE_HELPING_HAND  - 1] = sMoveFourLineDescription_HelpingHand,
    [MOVE_TRICK         - 1] = sMoveFourLineDescription_Trick,
    [MOVE_ROLE_PLAY     - 1] = sMoveFourLineDescription_RolePlay,
    [MOVE_WISH          - 1] = sMoveFourLineDescription_Wish,
    [MOVE_ASSIST        - 1] = sMoveFourLineDescription_Assist,
    [MOVE_INGRAIN       - 1] = sMoveFourLineDescription_Ingrain,
    [MOVE_SUPERPOWER    - 1] = sMoveFourLineDescription_Superpower,
    [MOVE_MAGIC_COAT    - 1] = sMoveFourLineDescription_MagicCoat,
    [MOVE_RECYCLE       - 1] = sMoveFourLineDescription_Recycle,
    [MOVE_REVENGE       - 1] = sMoveFourLineDescription_Revenge,
    [MOVE_BRICK_BREAK   - 1] = sMoveFourLineDescription_BrickBreak,
    [MOVE_YAWN          - 1] = sMoveFourLineDescription_Yawn,
    [MOVE_KNOCK_OFF     - 1] = sMoveFourLineDescription_KnockOff,
    [MOVE_ENDEAVOR      - 1] = sMoveFourLineDescription_Endeavor,
    [MOVE_ERUPTION      - 1] = sMoveFourLineDescription_Eruption,
    [MOVE_SKILL_SWAP    - 1] = sMoveFourLineDescription_SkillSwap,
    [MOVE_IMPRISON      - 1] = sMoveFourLineDescription_Imprison,
    [MOVE_REFRESH       - 1] = sMoveFourLineDescription_Refresh,
    [MOVE_GRUDGE        - 1] = sMoveFourLineDescription_Grudge,
    [MOVE_SNATCH        - 1] = sMoveFourLineDescription_Snatch,
    [MOVE_SECRET_POWER  - 1] = sMoveFourLineDescription_SecretPower,
    [MOVE_DIVE          - 1] = sMoveFourLineDescription_Dive,
    [MOVE_ARM_THRUST    - 1] = sMoveFourLineDescription_ArmThrust,
    [MOVE_CAMOUFLAGE    - 1] = sMoveFourLineDescription_Camouflage,
    [MOVE_TAIL_GLOW     - 1] = sMoveFourLineDescription_TailGlow,
    [MOVE_LUSTER_PURGE  - 1] = sMoveFourLineDescription_LusterPurge,
    [MOVE_MIST_BALL     - 1] = sMoveFourLineDescription_MistBall,
    [MOVE_FEATHER_DANCE - 1] = sMoveFourLineDescription_FeatherDance,
    [MOVE_TEETER_DANCE  - 1] = sMoveFourLineDescription_TeeterDance,
    [MOVE_BLAZE_KICK    - 1] = sMoveFourLineDescription_BlazeKick,
    [MOVE_MUD_SPORT     - 1] = sMoveFourLineDescription_MudSport,
    [MOVE_ICE_BALL      - 1] = sMoveFourLineDescription_IceBall,
    [MOVE_NEEDLE_ARM    - 1] = sMoveFourLineDescription_NeedleArm,
    [MOVE_SLACK_OFF     - 1] = sMoveFourLineDescription_SlackOff,
    [MOVE_HYPER_VOICE   - 1] = sMoveFourLineDescription_HyperVoice,
    [MOVE_POISON_FANG   - 1] = sMoveFourLineDescription_PoisonFang,
    [MOVE_CRUSH_CLAW    - 1] = sMoveFourLineDescription_CrushClaw,
    [MOVE_BLAST_BURN    - 1] = sMoveFourLineDescription_BlastBurn,
    [MOVE_HYDRO_CANNON  - 1] = sMoveFourLineDescription_HydroCannon,
    [MOVE_METEOR_MASH   - 1] = sMoveFourLineDescription_MeteorMash,
    [MOVE_ASTONISH      - 1] = sMoveFourLineDescription_Astonish,
    [MOVE_WEATHER_BALL  - 1] = sMoveFourLineDescription_WeatherBall,
    [MOVE_AROMATHERAPY  - 1] = sMoveFourLineDescription_Aromatherapy,
    [MOVE_FAKE_TEARS    - 1] = sMoveFourLineDescription_FakeTears,
    [MOVE_AIR_CUTTER    - 1] = sMoveFourLineDescription_AirCutter,
    [MOVE_OVERHEAT      - 1] = sMoveFourLineDescription_Overheat,
    [MOVE_ODOR_SLEUTH   - 1] = sMoveFourLineDescription_OdorSleuth,
    [MOVE_ROCK_TOMB     - 1] = sMoveFourLineDescription_RockTomb,
    [MOVE_SILVER_WIND   - 1] = sMoveFourLineDescription_SilverWind,
    [MOVE_METAL_SOUND   - 1] = sMoveFourLineDescription_MetalSound,
    [MOVE_GRASS_WHISTLE - 1] = sMoveFourLineDescription_GrassWhistle,
    [MOVE_TICKLE        - 1] = sMoveFourLineDescription_Tickle,
    [MOVE_COSMIC_POWER  - 1] = sMoveFourLineDescription_CosmicPower,
    [MOVE_WATER_SPOUT   - 1] = sMoveFourLineDescription_WaterSpout,
    [MOVE_SIGNAL_BEAM   - 1] = sMoveFourLineDescription_SignalBeam,
    [MOVE_SHADOW_PUNCH  - 1] = sMoveFourLineDescription_ShadowPunch,
    [MOVE_EXTRASENSORY  - 1] = sMoveFourLineDescription_Extrasensory,
    [MOVE_SKY_UPPERCUT  - 1] = sMoveFourLineDescription_SkyUppercut,
    [MOVE_SAND_TOMB     - 1] = sMoveFourLineDescription_SandTomb,
    [MOVE_SHEER_COLD    - 1] = sMoveFourLineDescription_SheerCold,
    [MOVE_MUDDY_WATER   - 1] = sMoveFourLineDescription_MuddyWater,
    [MOVE_BULLET_SEED   - 1] = sMoveFourLineDescription_BulletSeed,
    [MOVE_AERIAL_ACE    - 1] = sMoveFourLineDescription_AerialAce,
    [MOVE_ICICLE_SPEAR  - 1] = sMoveFourLineDescription_IcicleSpear,
    [MOVE_IRON_DEFENSE  - 1] = sMoveFourLineDescription_IronDefense,
    [MOVE_BLOCK         - 1] = sMoveFourLineDescription_Block,
    [MOVE_HOWL          - 1] = sMoveFourLineDescription_Howl,
    [MOVE_DRAGON_CLAW   - 1] = sMoveFourLineDescription_DragonClaw,
    [MOVE_FRENZY_PLANT  - 1] = sMoveFourLineDescription_FrenzyPlant,
    [MOVE_BULK_UP       - 1] = sMoveFourLineDescription_BulkUp,
    [MOVE_BOUNCE        - 1] = sMoveFourLineDescription_Bounce,
    [MOVE_MUD_SHOT      - 1] = sMoveFourLineDescription_MudShot,
    [MOVE_POISON_TAIL   - 1] = sMoveFourLineDescription_PoisonTail,
    [MOVE_COVET         - 1] = sMoveFourLineDescription_Covet,
    [MOVE_VOLT_TACKLE   - 1] = sMoveFourLineDescription_VoltTackle,
    [MOVE_MAGICAL_LEAF  - 1] = sMoveFourLineDescription_MagicalLeaf,
    [MOVE_WATER_SPORT   - 1] = sMoveFourLineDescription_WaterSport,
    [MOVE_CALM_MIND     - 1] = sMoveFourLineDescription_CalmMind,
    [MOVE_LEAF_BLADE    - 1] = sMoveFourLineDescription_LeafBlade,
    [MOVE_DRAGON_DANCE  - 1] = sMoveFourLineDescription_DragonDance,
    [MOVE_ROCK_BLAST    - 1] = sMoveFourLineDescription_RockBlast,
    [MOVE_SHOCK_WAVE    - 1] = sMoveFourLineDescription_ShockWave,
    [MOVE_WATER_PULSE   - 1] = sMoveFourLineDescription_WaterPulse,
    [MOVE_DOOM_DESIRE   - 1] = sMoveFourLineDescription_DoomDesire,
    [MOVE_PSYCHO_BOOST  - 1] = sMoveFourLineDescription_PsychoBoost,
    [MOVE_ROOST             - 1] = sMoveFourLineDescription_Roost,
    [MOVE_GRAVITY           - 1] = sMoveFourLineDescription_Gravity,
    [MOVE_MIRACLE_EYE       - 1] = sMoveFourLineDescription_MiracleEye,
    [MOVE_WAKE_UP_SLAP      - 1] = sMoveFourLineDescription_WakeUpSlap,
    [MOVE_HAMMER_ARM        - 1] = sMoveFourLineDescription_HammerArm,
    [MOVE_GYRO_BALL         - 1] = sMoveFourLineDescription_GyroBall,
    [MOVE_HEALING_WISH      - 1] = sMoveFourLineDescription_HealingWish,
    [MOVE_BRINE             - 1] = sMoveFourLineDescription_Brine,
    [MOVE_NATURAL_GIFT      - 1] = sMoveFourLineDescription_NaturalGift,
    [MOVE_FEINT             - 1] = sMoveFourLineDescription_Feint,
    [MOVE_PLUCK             - 1] = sMoveFourLineDescription_Pluck,
    [MOVE_TAILWIND          - 1] = sMoveFourLineDescription_Tailwind,
    [MOVE_ACUPRESSURE       - 1] = sMoveFourLineDescription_Acupressure,
    [MOVE_METAL_BURST       - 1] = sMoveFourLineDescription_MetalBurst,
    [MOVE_U_TURN            - 1] = sMoveFourLineDescription_UTurn,
    [MOVE_CLOSE_COMBAT      - 1] = sMoveFourLineDescription_CloseCombat,
    [MOVE_PAYBACK           - 1] = sMoveFourLineDescription_Payback,
    [MOVE_ASSURANCE         - 1] = sMoveFourLineDescription_Assurance,
    [MOVE_EMBARGO           - 1] = sMoveFourLineDescription_Embargo,
    [MOVE_FLING             - 1] = sMoveFourLineDescription_Fling,
    [MOVE_PSYCHO_SHIFT      - 1] = sMoveFourLineDescription_PsychoShift,
    [MOVE_TRUMP_CARD        - 1] = sMoveFourLineDescription_TrumpCard,
    [MOVE_HEAL_BLOCK        - 1] = sMoveFourLineDescription_HealBlock,
    [MOVE_WRING_OUT         - 1] = sMoveFourLineDescription_WringOut,
    [MOVE_POWER_TRICK       - 1] = sMoveFourLineDescription_PowerTrick,
    [MOVE_GASTRO_ACID       - 1] = sMoveFourLineDescription_GastroAcid,
    [MOVE_LUCKY_CHANT       - 1] = sMoveFourLineDescription_LuckyChant,
    [MOVE_ME_FIRST          - 1] = sMoveFourLineDescription_MeFirst,
    [MOVE_COPYCAT           - 1] = sMoveFourLineDescription_Copycat,
    [MOVE_POWER_SWAP        - 1] = sMoveFourLineDescription_PowerSwap,
    [MOVE_GUARD_SWAP        - 1] = sMoveFourLineDescription_GuardSwap,
    [MOVE_PUNISHMENT        - 1] = sMoveFourLineDescription_Punishment,
    [MOVE_LAST_RESORT       - 1] = sMoveFourLineDescription_LastResort,
    [MOVE_WORRY_SEED        - 1] = sMoveFourLineDescription_WorrySeed,
    [MOVE_SUCKER_PUNCH      - 1] = sMoveFourLineDescription_SuckerPunch,
    [MOVE_TOXIC_SPIKES      - 1] = sMoveFourLineDescription_ToxicSpikes,
    [MOVE_HEART_SWAP        - 1] = sMoveFourLineDescription_HeartSwap,
    [MOVE_AQUA_RING         - 1] = sMoveFourLineDescription_AquaRing,
    [MOVE_MAGNET_RISE       - 1] = sMoveFourLineDescription_MagnetRise,
    [MOVE_FLARE_BLITZ       - 1] = sMoveFourLineDescription_FlareBlitz,
    [MOVE_FORCE_PALM        - 1] = sMoveFourLineDescription_ForcePalm,
    [MOVE_AURA_SPHERE       - 1] = sMoveFourLineDescription_AuraSphere,
    [MOVE_ROCK_POLISH       - 1] = sMoveFourLineDescription_RockPolish,
    [MOVE_POISON_JAB        - 1] = sMoveFourLineDescription_PoisonJab,
    [MOVE_DARK_PULSE        - 1] = sMoveFourLineDescription_DarkPulse,
    [MOVE_NIGHT_SLASH       - 1] = sMoveFourLineDescription_NightSlash,
    [MOVE_AQUA_TAIL         - 1] = sMoveFourLineDescription_AquaTail,
    [MOVE_SEED_BOMB         - 1] = sMoveFourLineDescription_SeedBomb,
    [MOVE_AIR_SLASH         - 1] = sMoveFourLineDescription_AirSlash,
    [MOVE_X_SCISSOR         - 1] = sMoveFourLineDescription_XScissor,
    [MOVE_BUG_BUZZ          - 1] = sMoveFourLineDescription_BugBuzz,
    [MOVE_DRAGON_PULSE      - 1] = sMoveFourLineDescription_DragonPulse,
    [MOVE_DRAGON_RUSH       - 1] = sMoveFourLineDescription_DragonRush,
    [MOVE_POWER_GEM         - 1] = sMoveFourLineDescription_PowerGem,
    [MOVE_DRAIN_PUNCH       - 1] = sMoveFourLineDescription_DrainPunch,
    [MOVE_VACUUM_WAVE       - 1] = sMoveFourLineDescription_VacuumWave,
    [MOVE_FOCUS_BLAST       - 1] = sMoveFourLineDescription_FocusBlast,
    [MOVE_ENERGY_BALL       - 1] = sMoveFourLineDescription_EnergyBall,
    [MOVE_BRAVE_BIRD        - 1] = sMoveFourLineDescription_BraveBird,
    [MOVE_EARTH_POWER       - 1] = sMoveFourLineDescription_EarthPower,
    [MOVE_SWITCHEROO        - 1] = sMoveFourLineDescription_Switcheroo,
    [MOVE_GIGA_IMPACT       - 1] = sMoveFourLineDescription_GigaImpact,
    [MOVE_NASTY_PLOT        - 1] = sMoveFourLineDescription_NastyPlot,
    [MOVE_BULLET_PUNCH      - 1] = sMoveFourLineDescription_BulletPunch,
    [MOVE_AVALANCHE         - 1] = sMoveFourLineDescription_Revenge,
    [MOVE_ICE_SHARD         - 1] = sMoveFourLineDescription_IceShard,
    [MOVE_SHADOW_CLAW       - 1] = sMoveFourLineDescription_ShadowClaw,
    [MOVE_THUNDER_FANG      - 1] = sMoveFourLineDescription_ThunderFang,
    [MOVE_ICE_FANG          - 1] = sMoveFourLineDescription_IceFang,
    [MOVE_FIRE_FANG         - 1] = sMoveFourLineDescription_FireFang,
    [MOVE_SHADOW_SNEAK      - 1] = sMoveFourLineDescription_ShadowSneak,
    [MOVE_MUD_BOMB          - 1] = sMoveFourLineDescription_MudBomb,
    [MOVE_PSYCHO_CUT        - 1] = sMoveFourLineDescription_PsychoCut,
    [MOVE_ZEN_HEADBUTT      - 1] = sMoveFourLineDescription_ZenHeadbutt,
    [MOVE_MIRROR_SHOT       - 1] = sMoveFourLineDescription_MirrorShot,
    [MOVE_FLASH_CANNON      - 1] = sMoveFourLineDescription_FlashCannon,
    [MOVE_ROCK_CLIMB        - 1] = sMoveFourLineDescription_RockClimb,
    [MOVE_DEFOG             - 1] = sMoveFourLineDescription_Defog,
    [MOVE_TRICK_ROOM        - 1] = sMoveFourLineDescription_TrickRoom,
    [MOVE_DRACO_METEOR      - 1] = sMoveFourLineDescription_DracoMeteor,
    [MOVE_DISCHARGE         - 1] = sMoveFourLineDescription_Discharge,
    [MOVE_LAVA_PLUME        - 1] = sMoveFourLineDescription_LavaPlume,
    [MOVE_LEAF_STORM        - 1] = sMoveFourLineDescription_LeafStorm,
    [MOVE_POWER_WHIP        - 1] = sMoveFourLineDescription_PowerWhip,
    [MOVE_ROCK_WRECKER      - 1] = sMoveFourLineDescription_GigaImpact,
    [MOVE_CROSS_POISON      - 1] = sMoveFourLineDescription_CrossPoison,
    [MOVE_GUNK_SHOT         - 1] = sMoveFourLineDescription_GunkShot,
    [MOVE_IRON_HEAD         - 1] = sMoveFourLineDescription_IronHead,
    [MOVE_MAGNET_BOMB       - 1] = sMoveFourLineDescription_MagnetBomb,
    [MOVE_STONE_EDGE        - 1] = sMoveFourLineDescription_StoneEdge,
    [MOVE_CAPTIVATE         - 1] = sMoveFourLineDescription_Captivate,
    [MOVE_STEALTH_ROCK      - 1] = sMoveFourLineDescription_StealthRock,
    [MOVE_GRASS_KNOT        - 1] = sMoveFourLineDescription_GrassKnot,
    [MOVE_CHATTER           - 1] = sMoveFourLineDescription_Chatter,
    [MOVE_JUDGMENT          - 1] = sMoveFourLineDescription_Judgment,
    [MOVE_BUG_BITE          - 1] = sMoveFourLineDescription_BugBite,
    [MOVE_DRACONIC_FANGS    - 1] = sMoveFourLineDescription_DragonFang,
    [MOVE_CHARGE_BEAM       - 1] = sMoveFourLineDescription_ChargeBeam,
    [MOVE_PRIMAL_BEAM       - 1] = sMoveFourLineDescription_PrimalBeam,
    [MOVE_WOOD_HAMMER       - 1] = sMoveFourLineDescription_WoodHammer,
    [MOVE_AQUA_JET          - 1] = sMoveFourLineDescription_AquaJet,
    [MOVE_ATTACK_ORDER      - 1] = sMoveFourLineDescription_AttackOrder,
    [MOVE_DEFEND_ORDER      - 1] = sMoveFourLineDescription_DefendOrder,
    [MOVE_HEAL_ORDER        - 1] = sMoveFourLineDescription_HealOrder,
    [MOVE_HEAD_SMASH        - 1] = sMoveFourLineDescription_HeadSmash,
    [MOVE_DOUBLE_HIT        - 1] = sMoveFourLineDescription_DoubleHit,
    [MOVE_ROAR_OF_TIME      - 1] = sMoveFourLineDescription_RoarOfTime,
    [MOVE_SPACIAL_REND      - 1] = sMoveFourLineDescription_SpacialRend,
    [MOVE_LUNAR_DANCE       - 1] = sMoveFourLineDescription_HealingWish,
    [MOVE_CRUSH_GRIP        - 1] = sMoveFourLineDescription_WringOut,
    [MOVE_MAGMA_STORM       - 1] = sMoveFourLineDescription_MagmaStorm,
    [MOVE_DARK_VOID         - 1] = sMoveFourLineDescription_DarkVoid,
    [MOVE_SEED_FLARE        - 1] = sMoveFourLineDescription_SeedFlare,
    [MOVE_OMINOUS_WIND      - 1] = sMoveFourLineDescription_OminousWind,
    [MOVE_SHADOW_FORCE      - 1] = sMoveFourLineDescription_ShadowForce,
    [MOVE_HONE_CLAWS        - 1] = sMoveFourLineDescription_HoneClaws,
    [MOVE_WIDE_GUARD        - 1] = sMoveFourLineDescription_WideGuard,
    [MOVE_GUARD_SPLIT       - 1] = sMoveFourLineDescription_GuardSplit,
    [MOVE_POWER_SPLIT       - 1] = sMoveFourLineDescription_PowerSplit,
    [MOVE_WONDER_ROOM       - 1] = sMoveFourLineDescription_WonderRoom,
    [MOVE_PSYSHOCK          - 1] = sMoveFourLineDescription_Psyshock,
    [MOVE_VENOSHOCK         - 1] = sMoveFourLineDescription_Venoshock,
    [MOVE_AUTOTOMIZE        - 1] = sMoveFourLineDescription_Autotomize,
    [MOVE_RAGE_POWDER       - 1] = sMoveFourLineDescription_RagePowder,
    [MOVE_TELEKINESIS       - 1] = sMoveFourLineDescription_Telekinesis,
    [MOVE_MAGIC_ROOM        - 1] = sMoveFourLineDescription_MagicRoom,
    [MOVE_SMACK_DOWN        - 1] = sMoveFourLineDescription_SmackDown,
    [MOVE_STORM_THROW       - 1] = sMoveFourLineDescription_StormThrow,
    [MOVE_FLAME_BURST       - 1] = sMoveFourLineDescription_FlameBurst,
    [MOVE_SLUDGE_WAVE       - 1] = sMoveFourLineDescription_SludgeWave,
    [MOVE_QUIVER_DANCE      - 1] = sMoveFourLineDescription_QuiverDance,
    [MOVE_HEAVY_SLAM        - 1] = sMoveFourLineDescription_HeavySlam,
    [MOVE_SYNCHRONOISE      - 1] = sMoveFourLineDescription_Synchronoise,
    [MOVE_ELECTRO_BALL      - 1] = sMoveFourLineDescription_ElectroBall,
    [MOVE_SOAK              - 1] = sMoveFourLineDescription_Soak,
    [MOVE_FLAME_CHARGE      - 1] = sMoveFourLineDescription_FlameCharge,
    [MOVE_COIL              - 1] = sMoveFourLineDescription_Coil,
    [MOVE_LOW_SWEEP         - 1] = sMoveFourLineDescription_LowSweep,
    [MOVE_ACID_SPRAY        - 1] = sMoveFourLineDescription_AcidSpray,
    [MOVE_FOUL_PLAY         - 1] = sMoveFourLineDescription_FoulPlay,
    [MOVE_SIMPLE_BEAM       - 1] = sMoveFourLineDescription_SimpleBeam,
    [MOVE_ENTRAINMENT       - 1] = sMoveFourLineDescription_Entrainment,
    [MOVE_AFTER_YOU         - 1] = sMoveFourLineDescription_AfterYou,
    [MOVE_ROUND             - 1] = sMoveFourLineDescription_Round,
    [MOVE_ECHOED_VOICE      - 1] = sMoveFourLineDescription_EchoedVoice,
    [MOVE_CHIP_AWAY         - 1] = sMoveFourLineDescription_ChipAway,
    [MOVE_CLEAR_SMOG        - 1] = sMoveFourLineDescription_ClearSmog,
    [MOVE_STORED_POWER      - 1] = sMoveFourLineDescription_StoredPower,
    [MOVE_QUICK_GUARD       - 1] = sMoveFourLineDescription_QuickGuard,
    [MOVE_ALLY_SWITCH       - 1] = sMoveFourLineDescription_AllySwitch,
    [MOVE_SCALD             - 1] = sMoveFourLineDescription_Scald,
    [MOVE_SHELL_SMASH       - 1] = sMoveFourLineDescription_ShellSmash,
    [MOVE_HEAL_PULSE        - 1] = sMoveFourLineDescription_HealPulse,
    [MOVE_HEX               - 1] = sMoveFourLineDescription_Hex,
    [MOVE_SKY_DROP          - 1] = sMoveFourLineDescription_SkyDrop,
    [MOVE_SHIFT_GEAR        - 1] = sMoveFourLineDescription_ShiftGear,
    [MOVE_CIRCLE_THROW      - 1] = sMoveFourLineDescription_CircleThrow,
    [MOVE_INCINERATE        - 1] = sMoveFourLineDescription_Incinerate,
    [MOVE_QUASH             - 1] = sMoveFourLineDescription_Quash,
    [MOVE_ACROBATICS        - 1] = sMoveFourLineDescription_Acrobatics,
    [MOVE_REFLECT_TYPE      - 1] = sMoveFourLineDescription_ReflectType,
    [MOVE_RETALIATE         - 1] = sMoveFourLineDescription_Retaliate,
    [MOVE_FINAL_GAMBIT      - 1] = sMoveFourLineDescription_FinalGambit,
    [MOVE_BESTOW            - 1] = sMoveFourLineDescription_Bestow,
    [MOVE_INFERNO           - 1] = sMoveFourLineDescription_Inferno,
    [MOVE_WATER_PLEDGE      - 1] = sMoveFourLineDescription_WaterPledge,
    [MOVE_FIRE_PLEDGE       - 1] = sMoveFourLineDescription_FirePledge,
    [MOVE_GRASS_PLEDGE      - 1] = sMoveFourLineDescription_GrassPledge,
    [MOVE_VOLT_SWITCH       - 1] = sMoveFourLineDescription_UTurn,
    [MOVE_STRUGGLE_BUG      - 1] = sMoveFourLineDescription_StruggleBug,
    [MOVE_BULLDOZE          - 1] = sMoveFourLineDescription_Bulldoze,
    [MOVE_FROST_BREATH      - 1] = sMoveFourLineDescription_StormThrow,
    [MOVE_DRAGON_TAIL       - 1] = sMoveFourLineDescription_CircleThrow,
    [MOVE_WORK_UP           - 1] = sMoveFourLineDescription_WorkUp,
    [MOVE_ELECTROWEB        - 1] = sMoveFourLineDescription_Electroweb,
    [MOVE_WILD_CHARGE       - 1] = sMoveFourLineDescription_WildCharge,
    [MOVE_DRILL_RUN         - 1] = sMoveFourLineDescription_DrillRun,
    [MOVE_DUAL_CHOP         - 1] = sMoveFourLineDescription_DualChop,
    [MOVE_HEART_STAMP       - 1] = sMoveFourLineDescription_HeartStamp,
    [MOVE_HORN_LEECH        - 1] = sMoveFourLineDescription_HornLeech,
    [MOVE_SACRED_SWORD      - 1] = sMoveFourLineDescription_SacredSword,
    [MOVE_RAZOR_SHELL       - 1] = sMoveFourLineDescription_RazorShell,
    [MOVE_HEAT_CRASH        - 1] = sMoveFourLineDescription_HeavySlam,
    [MOVE_LEAF_TORNADO      - 1] = sMoveFourLineDescription_LeafTornado,
    [MOVE_STEAMROLLER       - 1] = sMoveFourLineDescription_Steamroller,
    [MOVE_COTTON_GUARD      - 1] = sMoveFourLineDescription_CottonGuard,
    [MOVE_NIGHT_DAZE        - 1] = sMoveFourLineDescription_NightDaze,
    [MOVE_PSYSTRIKE         - 1] = sMoveFourLineDescription_Psyshock,
    [MOVE_TAIL_SLAP         - 1] = sMoveFourLineDescription_TailSlap,
    [MOVE_HURRICANE         - 1] = sMoveFourLineDescription_Hurricane,
    [MOVE_HEAD_CHARGE       - 1] = sMoveFourLineDescription_HeadCharge,
    [MOVE_GEAR_GRIND        - 1] = sMoveFourLineDescription_GearGrind,
    [MOVE_SEARING_SHOT      - 1] = sMoveFourLineDescription_SearingShot,
    [MOVE_TECHNO_BLAST      - 1] = sMoveFourLineDescription_TechnoBlast,
    [MOVE_RELIC_SONG        - 1] = sMoveFourLineDescription_RelicSong,
    [MOVE_SECRET_SWORD      - 1] = sMoveFourLineDescription_SecretSword,
    [MOVE_GLACIATE          - 1] = sMoveFourLineDescription_Glaciate,
    [MOVE_BOLT_STRIKE       - 1] = sMoveFourLineDescription_BoltStrike,
    [MOVE_BLUE_FLARE        - 1] = sMoveFourLineDescription_BlueFlare,
    [MOVE_FIERY_DANCE       - 1] = sMoveFourLineDescription_FieryDance,
    [MOVE_FREEZE_SHOCK      - 1] = sMoveFourLineDescription_FreezeShock,
    [MOVE_ICE_BURN          - 1] = sMoveFourLineDescription_IceBurn,
    [MOVE_SNARL             - 1] = sMoveFourLineDescription_Snarl,
    [MOVE_ICICLE_CRASH      - 1] = sMoveFourLineDescription_IcicleCrash,
    [MOVE_V_CREATE          - 1] = sMoveFourLineDescription_VCreate,
    [MOVE_FUSION_FLARE      - 1] = sMoveFourLineDescription_FusionFlare,
    [MOVE_FUSION_BOLT       - 1] = sMoveFourLineDescription_FusionBolt,
    [MOVE_FLYING_PRESS      - 1] = sMoveFourLineDescription_FlyingPress,
    [MOVE_MAT_BLOCK         - 1] = sMoveFourLineDescription_MatBlock,
    [MOVE_BELCH             - 1] = sMoveFourLineDescription_Belch,
    [MOVE_ROTOTILLER        - 1] = sMoveFourLineDescription_Rototiller,
    [MOVE_STICKY_WEB        - 1] = sMoveFourLineDescription_StickyWeb,
    [MOVE_FELL_STINGER      - 1] = sMoveFourLineDescription_FellStinger,
    [MOVE_PHANTOM_FORCE     - 1] = sMoveFourLineDescription_ShadowForce,
    [MOVE_TRICK_OR_TREAT    - 1] = sMoveFourLineDescription_TrickOrTreat,
    [MOVE_NOBLE_ROAR        - 1] = sMoveFourLineDescription_NobleRoar,
    [MOVE_ION_DELUGE        - 1] = sMoveFourLineDescription_IonDeluge,
    [MOVE_PARABOLIC_CHARGE  - 1] = sMoveFourLineDescription_ParabolicCharge,
    [MOVE_FORESTS_CURSE     - 1] = sMoveFourLineDescription_ForestsCurse,
    [MOVE_PETAL_BLIZZARD    - 1] = sMoveFourLineDescription_PetalBlizzard,
    [MOVE_FREEZE_DRY        - 1] = sMoveFourLineDescription_FreezeDry,
    [MOVE_DISARMING_VOICE   - 1] = sMoveFourLineDescription_DisarmingVoice,
    [MOVE_PARTING_SHOT      - 1] = sMoveFourLineDescription_PartingShot,
    [MOVE_TOPSY_TURVY       - 1] = sMoveFourLineDescription_TopsyTurvy,
    [MOVE_DRAINING_KISS     - 1] = sMoveFourLineDescription_DrainingKiss,
    [MOVE_CRAFTY_SHIELD     - 1] = sMoveFourLineDescription_CraftyShield,
    [MOVE_FLOWER_SHIELD     - 1] = sMoveFourLineDescription_FlowerShield,
    [MOVE_GRASSY_TERRAIN    - 1] = sMoveFourLineDescription_GrassyTerrain,
    [MOVE_MISTY_TERRAIN     - 1] = sMoveFourLineDescription_MistyTerrain,
    [MOVE_ELECTRIFY         - 1] = sMoveFourLineDescription_Electrify,
    [MOVE_PLAY_ROUGH        - 1] = sMoveFourLineDescription_PlayRough,
    [MOVE_FAIRY_WIND        - 1] = sMoveFourLineDescription_FairyWind,
    [MOVE_MOONBLAST         - 1] = sMoveFourLineDescription_Moonblast,
    [MOVE_BOOMBURST         - 1] = sMoveFourLineDescription_Boomburst,
    [MOVE_FAIRY_LOCK        - 1] = sMoveFourLineDescription_FairyLock,
    [MOVE_KINGS_SHIELD      - 1] = sMoveFourLineDescription_KingsShield,
    [MOVE_PLAY_NICE         - 1] = sMoveFourLineDescription_PlayNice,
    [MOVE_CONFIDE           - 1] = sMoveFourLineDescription_Confide,
    [MOVE_DIAMOND_STORM     - 1] = sMoveFourLineDescription_DiamondStorm,
    [MOVE_STEAM_ERUPTION    - 1] = sMoveFourLineDescription_SteamEruption,
    [MOVE_HYPERSPACE_HOLE   - 1] = sMoveFourLineDescription_HyperspaceHole,
    [MOVE_WATER_SHURIKEN    - 1] = sMoveFourLineDescription_WaterShuriken,
    [MOVE_MYSTICAL_FIRE     - 1] = sMoveFourLineDescription_MysticalFire,
    [MOVE_SPIKY_SHIELD      - 1] = sMoveFourLineDescription_SpikyShield,
    [MOVE_AROMATIC_MIST     - 1] = sMoveFourLineDescription_AromaticMist,
    [MOVE_EERIE_IMPULSE     - 1] = sMoveFourLineDescription_EerieImpulse,
    [MOVE_VENOM_DRENCH      - 1] = sMoveFourLineDescription_VenomDrench,
    [MOVE_POWDER            - 1] = sMoveFourLineDescription_Powder,
    [MOVE_GEOMANCY          - 1] = sMoveFourLineDescription_Geomancy,
    [MOVE_MAGNETIC_FLUX     - 1] = sMoveFourLineDescription_MagneticFlux,
    [MOVE_HAPPY_HOUR        - 1] = sMoveFourLineDescription_HappyHour,
    [MOVE_ELECTRIC_TERRAIN  - 1] = sMoveFourLineDescription_ElectricTerrain,
    [MOVE_DAZZLING_GLEAM    - 1] = sMoveFourLineDescription_DazzlingGleam,
    [MOVE_CELEBRATE         - 1] = sMoveFourLineDescription_Celebrate,
    [MOVE_HOLD_HANDS        - 1] = sMoveFourLineDescription_HoldHands,
    [MOVE_BABY_DOLL_EYES    - 1] = sMoveFourLineDescription_BabyDollEyes,
    [MOVE_NUZZLE            - 1] = sMoveFourLineDescription_Nuzzle,
    [MOVE_HOLD_BACK         - 1] = sMoveFourLineDescription_FalseSwipe,
    [MOVE_INFESTATION       - 1] = sMoveFourLineDescription_Infestation,
    [MOVE_POWER_UP_PUNCH    - 1] = sMoveFourLineDescription_PowerUpPunch,
    [MOVE_OBLIVION_WING     - 1] = sMoveFourLineDescription_OblivionWing,
    [MOVE_THOUSAND_ARROWS   - 1] = sMoveFourLineDescription_ThousandArrows,
    [MOVE_THOUSAND_WAVES    - 1] = sMoveFourLineDescription_ThousandWaves,
    [MOVE_LANDS_WRATH       - 1] = sMoveFourLineDescription_LandsWrath,
    [MOVE_LIGHT_OF_RUIN     - 1] = sMoveFourLineDescription_LightOfRuin,
    [MOVE_ORIGIN_PULSE      - 1] = sMoveFourLineDescription_OriginPulse,
    [MOVE_PRECIPICE_BLADES  - 1] = sMoveFourLineDescription_PrecipiceBlades,
    [MOVE_DRAGON_ASCENT     - 1] = sMoveFourLineDescription_DragonAscent,
    [MOVE_HYPERSPACE_FURY   - 1] = sMoveFourLineDescription_HyperspaceHole,
    [MOVE_SHORE_UP          - 1] = sMoveFourLineDescription_ShoreUp,
    [MOVE_FIRST_IMPRESSION  - 1] = sMoveFourLineDescription_FirstImpression,
    [MOVE_BANEFUL_BUNKER    - 1] = sMoveFourLineDescription_BanefulBunker,
    [MOVE_SPIRIT_SHACKLE    - 1] = sMoveFourLineDescription_SpiritShackle,
    [MOVE_DARKEST_LARIAT    - 1] = sMoveFourLineDescription_DarkestLariat,
    [MOVE_SPARKLING_ARIA    - 1] = sMoveFourLineDescription_SparklingAria,
    [MOVE_ICE_HAMMER        - 1] = sMoveFourLineDescription_HammerArm,
    [MOVE_FLORAL_HEALING    - 1] = sMoveFourLineDescription_FloralHealing,
    [MOVE_HIGH_HORSEPOWER   - 1] = sMoveFourLineDescription_HighHorsepower,
    [MOVE_STRENGTH_SAP      - 1] = sMoveFourLineDescription_StrengthSap,
    [MOVE_SOLAR_BLADE       - 1] = sMoveFourLineDescription_SolarBlade,
    [MOVE_LEAFAGE           - 1] = sMoveFourLineDescription_Leafage,
    [MOVE_SPOTLIGHT         - 1] = sMoveFourLineDescription_Spotlight,
    [MOVE_TOXIC_THREAD      - 1] = sMoveFourLineDescription_ToxicThread,
    [MOVE_LASER_FOCUS       - 1] = sMoveFourLineDescription_LaserFocus,
    [MOVE_GEAR_UP           - 1] = sMoveFourLineDescription_GearUp,
    [MOVE_THROAT_CHOP       - 1] = sMoveFourLineDescription_ThroatChop,
    [MOVE_POLLEN_PUFF       - 1] = sMoveFourLineDescription_PollenPuff,
    [MOVE_ANCHOR_SHOT       - 1] = sMoveFourLineDescription_AnchorShot,
    [MOVE_PSYCHIC_TERRAIN   - 1] = sMoveFourLineDescription_PsychicTerrain,
    [MOVE_LUNGE             - 1] = sMoveFourLineDescription_Lunge,
    [MOVE_FIRE_LASH         - 1] = sMoveFourLineDescription_FireLash,
    [MOVE_POWER_TRIP        - 1] = sMoveFourLineDescription_PowerTrip,
    [MOVE_BURN_UP           - 1] = sMoveFourLineDescription_BurnUp,
    [MOVE_SPEED_SWAP        - 1] = sMoveFourLineDescription_SpeedSwap,
    [MOVE_SMART_STRIKE      - 1] = sMoveFourLineDescription_SmartStrike,
    [MOVE_PURIFY            - 1] = sMoveFourLineDescription_Purify,
    [MOVE_REVELATION_DANCE  - 1] = sMoveFourLineDescription_RevelationDance,
    [MOVE_CORE_ENFORCER     - 1] = sMoveFourLineDescription_CoreEnforcer,
    [MOVE_TROP_KICK         - 1] = sMoveFourLineDescription_TropKick,
    [MOVE_INSTRUCT          - 1] = sMoveFourLineDescription_Instruct,
    [MOVE_BEAK_BLAST        - 1] = sMoveFourLineDescription_BeakBlast,
    [MOVE_CLANGING_SCALES   - 1] = sMoveFourLineDescription_ClangingScales,
    [MOVE_DRAGON_HAMMER     - 1] = sMoveFourLineDescription_DragonHammer,
    [MOVE_BRUTAL_SWING      - 1] = sMoveFourLineDescription_BrutalSwing,
    [MOVE_AURORA_VEIL       - 1] = sMoveFourLineDescription_AuroraVeil,
    [MOVE_SHELL_TRAP        - 1] = sMoveFourLineDescription_ShellTrap,
    [MOVE_FLEUR_CANNON      - 1] = sMoveFourLineDescription_FleurCannon,
    [MOVE_PSYCHIC_FANGS     - 1] = sMoveFourLineDescription_PsychicFangs,
    [MOVE_STOMPING_TANTRUM  - 1] = sMoveFourLineDescription_StompingTantrum,
    [MOVE_SHADOW_BONE       - 1] = sMoveFourLineDescription_ShadowBone,
    [MOVE_ACCELEROCK        - 1] = sMoveFourLineDescription_Accelerock,
    [MOVE_LIQUIDATION       - 1] = sMoveFourLineDescription_Liquidation,
    [MOVE_PRISMATIC_LASER   - 1] = sMoveFourLineDescription_PrismaticLaser,
    [MOVE_SPECTRAL_THIEF    - 1] = sMoveFourLineDescription_SpectralThief,
    [MOVE_SUNSTEEL_STRIKE   - 1] = sMoveFourLineDescription_SunsteelStrike,
    [MOVE_MOONGEIST_BEAM    - 1] = sMoveFourLineDescription_MoongeistBeam,
    [MOVE_TEARFUL_LOOK      - 1] = sMoveFourLineDescription_TearfulLook,
    [MOVE_ZING_ZAP          - 1] = sMoveFourLineDescription_ZingZap,
    [MOVE_NATURES_MADNESS   - 1] = sMoveFourLineDescription_NaturesMadness,
    [MOVE_MULTI_ATTACK      - 1] = sMoveFourLineDescription_MultiAttack,
    [MOVE_MIND_BLOWN        - 1] = sMoveFourLineDescription_MindBlown,
    [MOVE_PLASMA_FISTS      - 1] = sMoveFourLineDescription_PlasmaFists,
    [MOVE_PHOTON_GEYSER     - 1] = sMoveFourLineDescription_PhotonGeyser,
    [MOVE_ZIPPY_ZAP         - 1] = sMoveFourLineDescription_ZippyZap,
    [MOVE_SPLISHY_SPLASH    - 1] = sMoveFourLineDescription_SplishySplash,
    [MOVE_FLOATY_FALL       - 1] = sMoveFourLineDescription_FloatyFall,
    [MOVE_PIKA_PAPOW        - 1] = sMoveFourLineDescription_PikaPapow,
    [MOVE_BOUNCY_BUBBLE     - 1] = sMoveFourLineDescription_BouncyBubble,
    [MOVE_BUZZY_BUZZ        - 1] = sMoveFourLineDescription_BuzzyBuzz,
    [MOVE_SIZZLY_SLIDE      - 1] = sMoveFourLineDescription_SizzlySlide,
    [MOVE_GLITZY_GLOW       - 1] = sMoveFourLineDescription_GlitzyGlow,
    [MOVE_BADDY_BAD         - 1] = sMoveFourLineDescription_BaddyBad,
    [MOVE_SAPPY_SEED        - 1] = sMoveFourLineDescription_SappySeed,
    [MOVE_FREEZY_FROST      - 1] = sMoveFourLineDescription_FreezyFrost,
    [MOVE_SPARKLY_SWIRL     - 1] = sMoveFourLineDescription_SparklySwirl,
    [MOVE_VEEVEE_VOLLEY     - 1] = sMoveFourLineDescription_VeeveeVolley,
    [MOVE_DOUBLE_IRON_BASH  - 1] = sMoveFourLineDescription_DoubleIronBash,

    //GEN 8
    [MOVE_DYNAMAX_CANNON    - 1] = sMoveFourLineDescription_DynamaxCannon,
    [MOVE_SNIPE_SHOT        - 1] = sMoveFourLineDescription_SnipeShot,
    [MOVE_JAW_LOCK          - 1] = sMoveFourLineDescription_JawLock,
    [MOVE_STUFF_CHEEKS      - 1] = sMoveFourLineDescription_StuffCheeks,
    [MOVE_NO_RETREAT        - 1] = sMoveFourLineDescription_NoRetreat,
    [MOVE_TAR_SHOT          - 1] = sMoveFourLineDescription_TarShot,
    [MOVE_MAGIC_POWDER      - 1] = sMoveFourLineDescription_MagicPowder,
    [MOVE_DRAGON_DARTS      - 1] = sMoveFourLineDescription_DragonDarts,
    [MOVE_TEATIME           - 1] = sMoveFourLineDescription_Teatime,
    [MOVE_OCTOLOCK          - 1] = sMoveFourLineDescription_Octolock,
    [MOVE_BOLT_BEAK         - 1] = sMoveFourLineDescription_BoltBeak,
    [MOVE_FISHIOUS_REND     - 1] = sMoveFourLineDescription_BoltBeak,
    [MOVE_COURT_CHANGE      - 1] = sMoveFourLineDescription_CourtChange,
    [MOVE_CLANGOROUS_SOUL   - 1] = sMoveFourLineDescription_ClangorousSoul,
    [MOVE_BODY_PRESS        - 1] = sMoveFourLineDescription_BodyPress,
    [MOVE_DECORATE          - 1] = sMoveFourLineDescription_Decorate,
    [MOVE_DRUM_BEATING      - 1] = sMoveFourLineDescription_DrumBeating,
    [MOVE_SNAP_TRAP         - 1] = sMoveFourLineDescription_SnapTrap,
    [MOVE_PYRO_BALL         - 1] = sMoveFourLineDescription_PyroBall,
    [MOVE_BEHEMOTH_BLADE    - 1] = sMoveFourLineDescription_BehemothBlade,
    [MOVE_BEHEMOTH_BASH     - 1] = sMoveFourLineDescription_BehemothBash,
    [MOVE_AURA_WHEEL        - 1] = sMoveFourLineDescription_AuraWheel,
    [MOVE_BREAKING_SWIPE    - 1] = sMoveFourLineDescription_BreakingSwipe,
    [MOVE_BRANCH_POKE       - 1] = sMoveFourLineDescription_BranchPoke,
    [MOVE_OVERDRIVE         - 1] = sMoveFourLineDescription_Overdrive,
    [MOVE_APPLE_ACID        - 1] = sMoveFourLineDescription_AppleAcid,
    [MOVE_GRAV_APPLE        - 1] = sMoveFourLineDescription_GravApple,
    [MOVE_SPIRIT_BREAK      - 1] = sMoveFourLineDescription_SpiritBreak,
    [MOVE_STRANGE_STEAM     - 1] = sMoveFourLineDescription_StrangeSteam,
    [MOVE_LIFE_DEW          - 1] = sMoveFourLineDescription_LifeDew,
    [MOVE_OBSTRUCT          - 1] = sMoveFourLineDescription_Obstruct,
    [MOVE_FALSE_SURRENDER   - 1] = sMoveFourLineDescription_FalseSurrender,
    [MOVE_METEOR_ASSAULT    - 1] = sMoveFourLineDescription_MeteorAssault,
    [MOVE_ETERNABEAM        - 1] = sMoveFourLineDescription_Eternabeam,
    [MOVE_STEEL_BEAM        - 1] = sMoveFourLineDescription_SteelBeam,
    [MOVE_EXPANDING_FORCE   - 1] = sMoveFourLineDescription_ExpandingForce,
    [MOVE_STEEL_ROLLER      - 1] = sMoveFourLineDescription_SteelRoller,
    [MOVE_SCALE_SHOT        - 1] = sMoveFourLineDescription_ScaleShot,
    [MOVE_METEOR_BEAM       - 1] = sMoveFourLineDescription_MeteorBeam,
    [MOVE_SHELL_SIDE_ARM    - 1] = sMoveFourLineDescription_ShellSideArm,
    [MOVE_MISTY_EXPLOSION   - 1] = sMoveFourLineDescription_MistyExplosion,
    [MOVE_GRASSY_GLIDE      - 1] = sMoveFourLineDescription_GrassyGlide,
    [MOVE_RISING_VOLTAGE    - 1] = sMoveFourLineDescription_RisingVoltage,
    [MOVE_TERRAIN_PULSE     - 1] = sMoveFourLineDescription_TerrainPulse,
    [MOVE_SKITTER_SMACK     - 1] = sMoveFourLineDescription_SkitterSmack,
    [MOVE_BURNING_JEALOUSY  - 1] = sMoveFourLineDescription_BurningJealousy,
    [MOVE_LASH_OUT          - 1] = sMoveFourLineDescription_LashOut,
    [MOVE_POLTERGEIST       - 1] = sMoveFourLineDescription_Poltergeist,
    [MOVE_CORROSIVE_GAS     - 1] = sMoveFourLineDescription_CorrosiveGas,
    [MOVE_COACHING          - 1] = sMoveFourLineDescription_Coaching,
    [MOVE_FLIP_TURN         - 1] = sMoveFourLineDescription_UTurn,
    [MOVE_TRIPLE_AXEL       - 1] = sMoveFourLineDescription_TripleKick,
    [MOVE_DUAL_WINGBEAT     - 1] = sMoveFourLineDescription_DualWingbeat,
    [MOVE_SCORCHING_SANDS   - 1] = sMoveFourLineDescription_ScorchingSands,
    [MOVE_JUNGLE_HEALING    - 1] = sMoveFourLineDescription_JungleHealing,
    [MOVE_WICKED_BLOW       - 1] = sMoveFourLineDescription_WickedBlow,
    [MOVE_SURGING_STRIKES   - 1] = sMoveFourLineDescription_SurgingStrikes,
    [MOVE_THUNDER_CAGE      - 1] = sMoveFourLineDescription_ThunderCage,
    [MOVE_DRAGON_ENERGY     - 1] = sMoveFourLineDescription_DragonEnergy,
    [MOVE_FREEZING_GLARE    - 1] = sMoveFourLineDescription_FreezingGlare,
    [MOVE_FIERY_WRATH       - 1] = sMoveFourLineDescription_FieryWrath,
    [MOVE_THUNDEROUS_KICK   - 1] = sMoveFourLineDescription_ThunderousKick,
    [MOVE_GLACIAL_LANCE     - 1] = sMoveFourLineDescription_GlacialLance,
    [MOVE_ASTRAL_BARRAGE    - 1] = sMoveFourLineDescription_AstralBarrage,
    [MOVE_EERIE_SPELL       - 1] = sMoveFourLineDescription_EerieSpell,

    //Darky's Custom Moves
    [MOVE_DEATHROLL       - 1] = sMoveFourLineDescription_Deathroll,
    [MOVE_EXCALIBUR       - 1] = sMoveFourLineDescription_Excalibur,
    [MOVE_AQUA_FANG       - 1] = sMoveFourLineDescription_AquaFang,
    [MOVE_WAVE_CRASH      - 1] = sMoveFourLineDescription_WaveCrash,
    [MOVE_SMITE           - 1] = sMoveFourLineDescription_Smite,
    [MOVE_OUTBURST        - 1] = sMoveFourLineDescription_Outburst,
    [MOVE_SEISMIC_FIST    - 1] = sMoveFourLineDescription_SeismicFist,
    [MOVE_IRON_FANGS      - 1] = sMoveFourLineDescription_IronFangs,
    [MOVE_SHADOW_FANGS    - 1] = sMoveFourLineDescription_ShadowFangs,
    [MOVE_LOVELY_BITE     - 1] = sMoveFourLineDescription_LovelyBite,
    [MOVE_JAGGED_FANGS    - 1] = sMoveFourLineDescription_JaggedFangs,
    [MOVE_SCORCHED_EARTH  - 1] = sMoveFourLineDescription_ScorchedEarth,
    [MOVE_RAGING_FURY     - 1] = sMoveFourLineDescription_RagingFury,
    [MOVE_PLASMA_PULSE    - 1] = sMoveFourLineDescription_PlasmaPulse,
    [MOVE_PIXIE_BEAM      - 1] = sMoveFourLineDescription_PixeBeam,
    [MOVE_PIXIE_SLASH     - 1] = sMoveFourLineDescription_PixeSlash,
    [MOVE_SEISMIC_BLADE   - 1] = sMoveFourLineDescription_SeismicBlade,
    [MOVE_MOUNTAIN_CHUNK  - 1] = sMoveFourLineDescription_MountainChunk,
    [MOVE_ARCHER_SHOT     - 1] = sMoveFourLineDescription_ArcherShot,
    [MOVE_FROST_BRAND     - 1] = sMoveFourLineDescription_FrostBrand,
    [MOVE_FROST_BOLT      - 1] = sMoveFourLineDescription_FrostBrand, //ToChange
    [MOVE_GLACIER_CRASH   - 1] = sMoveFourLineDescription_FrostBrand, //ToChange 
    [MOVE_ZEPHYR_RUSH     - 1] = sMoveFourLineDescription_FrostBrand, //ToChange 
    [MOVE_SUPERSONIC_SHOT - 1] = sMoveFourLineDescription_FrostBrand, //ToChange 
    [MOVE_SHOCKING_JAB    - 1] = sMoveFourLineDescription_FrostBrand, //ToChange 
    [MOVE_SHOCKING_EDGE   - 1] = sMoveFourLineDescription_FrostBrand, //ToChange 
    [MOVE_LIGHTING_SRIKE  - 1] = sMoveFourLineDescription_FrostBrand, //ToChange 
    [MOVE_VOLT_BOLT       - 1] = sMoveFourLineDescription_FrostBrand, //ToChange 

};