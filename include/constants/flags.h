#ifndef GUARD_CONSTANTS_FLAGS_H
#define GUARD_CONSTANTS_FLAGS_H

#include "constants/opponents.h"

// Temporary Flags
// These temporary flags are are cleared every time a map is loaded. They are used
// for things like shortening an NPCs introduction text if the player already spoke
// to them once.

#define TEMP_FLAGS_START                                 0
#define FLAG_TEMP_1                                      1
#define FLAG_TEMP_2                                      2
#define FLAG_TEMP_3                                      3
#define FLAG_TEMP_4                                      4
#define FLAG_TEMP_5                                      5  // Unused Flag
#define FLAG_TEMP_6                                      6  // Unused Flag
#define FLAG_TEMP_7                                      7  // Unused Flag
#define FLAG_TEMP_8                                      8  // Unused Flag
#define FLAG_TEMP_9                                      9  // Unused Flag
#define FLAG_TEMP_A                                      10 // Unused Flag
#define FLAG_TEMP_B                                      11 // Unused Flag
#define FLAG_TEMP_C                                      12 // Unused Flag
#define FLAG_TEMP_D                                      13 // Unused Flag
#define FLAG_TEMP_E                                      14 // Unused Flag
#define FLAG_TEMP_F                                      15 // Unused Flag
#define FLAG_TEMP_10                                     16 // Unused Flag
#define FLAG_TEMP_11                                     17
#define FLAG_TEMP_12                                     18
#define FLAG_TEMP_13                                     19
#define FLAG_TEMP_14                                     20
#define FLAG_TEMP_15                                     21
#define FLAG_TEMP_16                                     22
#define FLAG_TEMP_17                                     23
#define FLAG_TEMP_18                                     24
#define FLAG_TEMP_19                                     25
#define FLAG_TEMP_1A                                     26
#define FLAG_TEMP_1B                                     27
#define FLAG_TEMP_1C                                     28
#define FLAG_TEMP_1D                                     29
#define FLAG_TEMP_1E                                     30
#define FLAG_TEMP_1F                                     31
#define TEMP_FLAGS_END                                   FLAG_TEMP_1F

#define FLAG_HIDE_ROUTE111_CHANSEY                       32
#define FLAG_HIDE_ROUTE112_CHANSEY                       33
#define PETALBURG_WOODS_2_SUPER_POTION                   34
#define PETALBURG_WOODS_2_HEAL_BALL                      35
#define PETALBURG_WOODS_2_SUN_STONE                      36
#define PETALBURG_WOODS_2_VENOSHOCK                      37
#define PETALBURG_WOODS_3_GRASS_KNOT                     38
#define PETALBURG_WOODS_3_SLUDGE_WAVE                    39
#define PETALBURG_WOODS_3_BEEDRILLITE                    40
#define FLAG_LANDMARK_SEASPRAY_CAVE                      41
#define FLAG_SEASPRAY_CAVE_DAWN_STONE                    42
#define FLAG_SEASPRAY_CAVE_RARE_CANDY                    43
#define FLAG_SEASPRAY_CAVE_STEALTH_ROCK                  44
#define FLAG_SEASPRAY_CAVE_WATER_PULSE                   45
#define FLAG_SEASPRAY_CAVE_LURE_BALL                     46
#define FLAG_SEASPRAY_CAVE_BLASTOISINITE                 47
#define FLAG_GRANITE_CAVE_BRICK_BREAK                    48
#define FLAG_ROUTE_106_BIG_PEARL                         49
#define FLAG_DEWFORD_GYM_FRESHWATER                      50
#define FLAG_TALKED_TO_MOVE_TUTOR                        51
#define FLAG_PETALBURG_WOODS_BIG_ROOT                    52
#define FLAG_PETALBURG_WOODS_INSECT_PLATE                53
#define FLAG_DEWFORD_EVIOLITE                            54
#define FLAG_TM93_WILD_CHARGE                            55
#define FLAG_MAUVILLE_GYM_MOOMOOMILK                     56
#define FLAG_WANDA_GARDEVOIRITE                          57
#define FLAG_ROUTE111_LEFT_BREAKABLE_ROCK                58
#define FLAG_ROUTE111_RIGHT_BREAKABLE_ROCK               59
#define FLAG_HIDE_FALLARBOR_RIVAL1                       60
#define FLAG_HIDE_FALLARBOR_RIVAL_ON_BIKE                61
#define FLAG_MET_NATURE_CHANGER                          62
#define FLAG_ITEM_DEWFORD_MEADOW_BUTTERFRENITE           63
#define FLAG_SEASPRAY_CAVE_STONE_EDGE                    64
#define FLAG_SEASPRAY_CAVE_B1F_FREEZE_DRY                65
#define FLAG_SEASPRAY_CAVE_B1F_KINGS_ROCK                66
#define FLAG_SEASPRAY_CAVE_B1F_REVIVE                    67
#define FLAG_SEASPRAY_CAVE_B1F_ABOMASITE                 68
#define FLAG_EMBER_PATH_SMACK_DOWN                       69
#define FLAG_EMBER_PATH_CHARIZARDITE_Y                   70
#define FLAG_ASHEN_WOODS_FLAME_ORB                       71
#define FLAG_ASHEN_WOODS_PINSIRITE                       72
#define FLAG_ASHEN_WOODS_U_TURN                          73
#define FLAG_SANDSTREWN_RUINS_DOME_FOSSIL                74
#define FLAG_SANDSTREWN_RUINS_HELX_FOSSIL                75
#define FLAG_SANDSTREWN_RUINS_ARMOR_FOSSIL               76
#define FLAG_SANDSTREWN_RUINS_SKULL_FOSSIL               77
#define FLAG_SANDSTREWN_RUINS_PLUME_FOSSIL               78
#define FLAG_SANDSTREWN_RUINS_COVER_FOSSIL               79
#define FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA_STILL          80
#define FLAG_SET_WALL_CLOCK                              81
#define FLAG_RESCUED_BIRCH                               82
#define FLAG_LEGENDARIES_IN_SOOTOPOLIS                   83
#define FLAG_SANDSTREWN_RUINS_SAIL_FOSSIL                84
#define FLAG_SANDSTREWN_RUINS_JAW_FOSSIL                 85
#define FLAG_HIDE_CONTEST_POKE_BALL                      86  // Always set after new game, object it hides is added directly
#define FLAG_MET_RIVAL_MOM                               87
#define FLAG_BIRCH_AIDE_MET                              88
#define FLAG_DECLINED_BIKE                               89
#define FLAG_RECEIVED_BIKE                               90
#define FLAG_WATTSON_REMATCH_AVAILABLE                   91
#define FLAG_COLLECTED_ALL_SILVER_SYMBOLS                92
#define FLAG_GOOD_LUCK_SAFARI_ZONE                       93 // Set after talking to NPC blocking Safari Zone entrance/exit once.
#define FLAG_RECEIVED_WAILMER_PAIL                       94
#define FLAG_RECEIVED_POKEBLOCK_CASE                     95
#define FLAG_RECEIVED_SECRET_POWER                       96
#define FLAG_MET_TEAM_AQUA_HARBOR                        97
#define FLAG_TV_EXPLAINED                                98
#define FLAG_MAUVILLE_GYM_BARRIERS_STATE                 99
#define FLAG_MOSSDEEP_GYM_SWITCH_1                       100 // Leftover from the RS version of Mossdeep Gym, functionally unused
#define FLAG_MOSSDEEP_GYM_SWITCH_2                       101 //
#define FLAG_MOSSDEEP_GYM_SWITCH_3                       102 //
#define FLAG_MOSSDEEP_GYM_SWITCH_4                       103 //
#define FLAG_SANDSTREWN_RUINS_GARCHOMPITE                104
#define FLAG_OCEANIC_MUSEUM_MET_REPORTER                 105
#define FLAG_RECEIVED_HM04                               106
#define FLAG_RECEIVED_HM06                               107
#define FLAG_WHITEOUT_TO_LAVARIDGE                       108 // Set after defeating Flannery, so the player cant white out from poison before receiving Go Goggles
#define FLAG_RECEIVED_HM05                               109
#define FLAG_RECEIVED_HM02                               110
#define FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT              111
#define FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE              112
#define FLAG_UNUSED_RS_LEGENDARY_BATTLE_DONE             113 // Unused Flag. Used in R/S to indicate whether player defeated or caught Groudon/Kyogre in Cave of Origin.
#define FLAG_SCOTT_CALL_BATTLE_FRONTIER                  114 // Used in order to activate a phone call from Scott, inviting the player to the SS Tidal.
#define FLAG_RECEIVED_METEORITE                          115
#define FLAG_ADVENTURE_STARTED                           116 // RECEIVED Pokédex.
#define FLAG_DEFEATED_MAGMA_SPACE_CENTER                 117 // Set when Team Magma is defeated at Mossdeep's Space Center.
#define FLAG_MET_HIDDEN_POWER_GIVER                      118
#define FLAG_CANCEL_BATTLE_ROOM_CHALLENGE                119
#define FLAG_LANDMARK_MIRAGE_TOWER                       120
#define FLAG_RECEIVED_TM75                               121
#define FLAG_RECEIVED_HM03                               122
#define FLAG_RECEIVED_HM08                               123
#define FLAG_REGISTER_RIVAL_POKENAV                      124
#define FLAG_DEFEATED_RIVAL_ROUTE_104                    125
#define FLAG_DEFEATED_WALLY_VICTORY_ROAD                 126
#define FLAG_MET_PRETTY_PETAL_SHOP_OWNER                 127
#define FLAG_ENABLE_ROXANNE_FIRST_CALL                   128 // Set after defeating Brawly. This will activate a call with Roxanne in order to register her.
#define FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN              129
#define FLAG_DEFEATED_RIVAL_ROUTE103                     130
#define FLAG_RECEIVED_DOLL_LANETTE                       131
#define FLAG_RECEIVED_POTION_OLDALE                      132
#define FLAG_RECEIVED_AMULET_COIN                        133
#define FLAG_PENDING_DAYCARE_EGG                         134
#define FLAG_THANKED_FOR_PLAYING_WITH_WALLY              135
#define FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL             136 // Set after defeating Wally outside Mauville Gym. Will activate a call later to register Wally.
#define FLAG_RECEIVED_HM01                               137
#define FLAG_SCOTT_CALL_FORTREE_GYM                      138 // Triggers call from Scott after defeating Winona
#define FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY               139
#define FLAG_RECEIVED_6_SODA_POP                         140
#define FLAG_DEFEATED_SEASHORE_HOUSE                     141
#define FLAG_DEVON_GOODS_STOLEN                          142
#define FLAG_RECOVERED_DEVON_GOODS                       143
#define FLAG_RETURNED_DEVON_GOODS                        144
#define FLAG_CAUGHT_LUGIA                                145
#define FLAG_CAUGHT_HO_OH                                146
#define FLAG_MR_BRINEY_SAILING_INTRO                     147
#define FLAG_DOCK_REJECTED_DEVON_GOODS                   148
#define FLAG_DELIVERED_DEVON_GOODS                       149
#define FLAG_RECEIVED_TOGEPI_EGG                         150
#define FLAG_RECEIVED_CASTFORM                           151
#define FLAG_RECEIVED_SUPER_ROD                          152
#define FLAG_RUSTBORO_NPC_TRADE_COMPLETED                153
#define FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED              154
#define FLAG_FORTREE_NPC_TRADE_COMPLETED                 155
#define FLAG_BATTLE_FRONTIER_TRADE_DONE                  156
#define FLAG_FORCE_MIRAGE_TOWER_VISIBLE                  157
#define FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE               158
#define FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN 159
#define FLAG_COOL_PAINTING_MADE                          160
#define FLAG_BEAUTY_PAINTING_MADE                        161
#define FLAG_CUTE_PAINTING_MADE                          162
#define FLAG_SMART_PAINTING_MADE                         163
#define FLAG_TOUGH_PAINTING_MADE                         164
#define FLAG_RECEIVED_TM39                               165
#define FLAG_RECEIVED_TM08                               166
#define FLAG_RECEIVED_TM72                               167
#define FLAG_RECEIVED_TM50                               168
#define FLAG_RECEIVED_TM42                               169
#define FLAG_RECEIVED_TM51                               170
#define FLAG_RECEIVED_TM04                               177
#define FLAG_RECEIVED_TM03                               172
#define FLAG_DECORATION_0                                173
#define FLAG_DECORATION_1                                174
#define FLAG_DECORATION_2                                175
#define FLAG_DECORATION_3                                176
#define FLAG_DECORATION_4                                177
#define FLAG_DECORATION_5                                178
#define FLAG_DECORATION_6                                179
#define FLAG_DECORATION_7                                180
#define FLAG_DECORATION_8                                181
#define FLAG_DECORATION_9                                182
#define FLAG_DECORATION_10                               183
#define FLAG_DECORATION_11                               184
#define FLAG_DECORATION_12                               185
#define FLAG_DECORATION_13                               186
#define FLAG_DECORATION_14                               187
#define FLAG_RECEIVED_POKENAV                            188
#define FLAG_DELIVERED_STEVEN_LETTER                     186
#define FLAG_DEFEATED_WALLY_MAUVILLE                     190
#define FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F              191
#define FLAG_RECEIVED_SUN_STONE_MOSSDEEP                 192
#define FLAG_WALLY_SPEECH                                193
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1               194 // Leftover from the RS version of Puzzle Room 7, functionally unused
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2               195 //
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3               196 //
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4               197 //
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5               198 //
#define FLAG_RUSTURF_TUNNEL_OPENED                       199
#define FLAG_RECEIVED_RED_SCARF                          200
#define FLAG_RECEIVED_BLUE_SCARF                         201
#define FLAG_RECEIVED_PINK_SCARF                         202
#define FLAG_RECEIVED_GREEN_SCARF                        203
#define FLAG_RECEIVED_YELLOW_SCARF                       204
#define FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER         205
#define FLAG_ENCOUNTERED_LATIAS_OR_LATIOS                206
#define FLAG_MET_ARCHIE_METEOR_FALLS                     207
#define FLAG_GOT_BASEMENT_KEY_FROM_WATTSON               208
#define FLAG_GOT_TM24_FROM_WATTSON                       209
#define FLAG_FAN_CLUB_STRENGTH_SHARED                    210 // Set when you rate the strength of another trainer in Lilycove's Trainer Fan Club.
#define FLAG_DEFEATED_RIVAL_RUSTBORO                     211
#define FLAG_RECEIVED_RED_OR_BLUE_ORB                    212
#define FLAG_RECEIVED_PREMIER_BALL_RUSTBORO              213
#define FLAG_ENABLE_WALLY_MATCH_CALL                     214
#define FLAG_ENABLE_SCOTT_MATCH_CALL                     215
#define FLAG_ENABLE_MOM_MATCH_CALL                       216
#define FLAG_MET_DIVING_TREASURE_HUNTER                  217
#define FLAG_MET_WAILMER_TRAINER                         218
#define FLAG_EVIL_LEADER_PLEASE_STOP                     219
#define FLAG_NEVER_SET_0x0DC                             220 // This flag is read, but never written to
#define FLAG_RECEIVED_GO_GOGGLES                         221
#define FLAG_WINGULL_SENT_ON_ERRAND                      222
#define FLAG_RECEIVED_CHOICE_SCARF                       223
#define FLAG_WINGULL_DELIVERED_MAIL                      224
#define FLAG_RECEIVED_20_COINS                           225
#define FLAG_RECEIVED_STARTER_DOLL                       226
#define FLAG_RECEIVED_GOOD_ROD                           227
#define FLAG_REGI_DOORS_OPENED                           228
#define FLAG_SHOWN_DEOXYS_TO_COSMO                       229
#define FLAG_RECEIVED_TM36                               230
#define FLAG_RECEIVED_TM05                               231
#define FLAG_RECEIVED_TM19                               232
#define FLAG_SANDSTREWN_RUINS_OLD_AMBER                  233
#define FLAG_RECEIVED_TM44                               234
#define FLAG_RECEIVED_TM45                               235
#define FLAG_RECEIVED_GLASS_ORNAMENT                     236
#define FLAG_RECEIVED_SILVER_SHIELD                      237
#define FLAG_RECEIVED_GOLD_SHIELD                        238
#define FLAG_USED_STORAGE_KEY                            239
#define FLAG_USED_ROOM_1_KEY                             240
#define FLAG_USED_ROOM_2_KEY                             241
#define FLAG_USED_ROOM_4_KEY                             242
#define FLAG_USED_ROOM_6_KEY                             243
#define FLAG_MET_PROF_COZMO                              244
#define FLAG_RECEIVED_WAILMER_DOLL                       245
#define FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104             246
#define FLAG_DEFEATED_SS_TIDAL_TRAINERS                  247
#define FLAG_RECEIVED_SPELON_BERRY                       248
#define FLAG_RECEIVED_PAMTRE_BERRY                       249
#define FLAG_RECEIVED_WATMEL_BERRY                       250
#define FLAG_RECEIVED_DURIN_BERRY                        251
#define FLAG_RECEIVED_BELUE_BERRY                        252
#define FLAG_ENABLE_RIVAL_MATCH_CALL                     253
#define FLAG_RECEIVED_CHARCOAL                           254
#define FLAG_LATIOS_OR_LATIAS_ROAMING                    255
#define FLAG_RECEIVED_AGGRONITE                          256
#define FLAG_RECEIVED_OLD_ROD                            257
#define FLAG_RECEIVED_COIN_CASE                          258
#define FLAG_RETURNED_RED_OR_BLUE_ORB                    259
#define FLAG_RECEIVED_TM49                               260
#define FLAG_RECEIVED_TM28                               261
#define FLAG_RECEIVED_TM09                               262
#define FLAG_ENTERED_ELITE_FOUR                          263
#define FLAG_RECEIVED_TM10                               264
#define FLAG_RECEIVED_TM41                               265
#define FLAG_RECEIVED_LAVARIDGE_EGG                      266
#define FLAG_RECEIVED_REVIVED_FOSSIL_MON                 267
#define FLAG_SECRET_BASE_REGISTRY_ENABLED                268
#define FLAG_RECEIVED_TM46                               269
#define FLAG_CONTEST_SKETCH_CREATED                      270 // Set but never read
#define FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE               271
#define FLAG_RECEIVED_SCOPE_LENS                         272
#define FLAG_POKERUS_EXPLAINED                           273
#define FLAG_RECEIVED_RUNNING_SHOES                      274
#define FLAG_RECEIVED_QUICK_CLAW                         275
#define FLAG_RECEIVED_KINGS_ROCK                         276
#define FLAG_RECEIVED_LIFE_ORB                           277
#define FLAG_RECEIVED_SOOTHE_BELL                        278
#define FLAG_RECEIVED_WHITE_HERB                         279
#define FLAG_RECEIVED_SOFT_SAND                          280
#define FLAG_ENABLE_PROF_BIRCH_MATCH_CALL                281
#define FLAG_RECEIVED_CLEANSE_TAG                        282
#define FLAG_RECEIVED_FOCUS_BAND                         283
#define FLAG_DECLINED_WALLY_BATTLE_MAUVILLE              284
#define FLAG_RECEIVED_DEVON_SCOPE                        285
#define FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE              286
#define FLAG_MET_DEVON_EMPLOYEE                          287
#define FLAG_MET_RIVAL_RUSTBORO                          288
#define FLAG_RECEIVED_SILK_SCARF                         289
#define FLAG_NOT_READY_FOR_BATTLE_ROUTE_120              290
#define FLAG_RECEIVED_SS_TICKET                          291
#define FLAG_MET_RIVAL_LILYCOVE                          292
#define FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE           293
#define FLAG_EXCHANGED_SCANNER                           294
#define FLAG_KECLEON_FLED_FORTREE                        295
#define FLAG_PETALBURG_MART_EXPANDED_ITEMS               296
#define FLAG_RECEIVED_MIRACLE_SEED                       297
#define FLAG_RECEIVED_MELTAN                             298
#define FLAG_RECEIVED_DIANCITE                           299
#define FLAG_MET_FANCLUB_YOUNGER_BROTHER                 300
#define FLAG_RIVAL_LEFT_FOR_ROUTE103                     301
#define FLAG_OMIT_DIVE_FROM_STEVEN_LETTER                302
#define FLAG_HAS_MATCH_CALL                              303
#define FLAG_ADDED_MATCH_CALL_TO_POKENAV                 304
#define FLAG_REGISTERED_STEVEN_POKENAV                   305
#define FLAG_ENABLE_NORMAN_MATCH_CALL                    306
#define FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN             307 // Set after you follow Steven to the entrance of the Cave of Origin.
#define FLAG_MET_ARCHIE_SOOTOPOLIS                       308
#define FLAG_MET_MAXIE_SOOTOPOLIS                        309
#define FLAG_MET_SCOTT_RUSTBORO                          310
#define FLAG_WALLACE_GOES_TO_SKY_PILLAR                  311 // Set after speaking to Wallace within the Cave of Origin.
#define FLAG_RECEIVED_HM07                               312
#define FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS                313
#define FLAG_RECEIVED_AURORA_TICKET                      314
#define FLAG_RECEIVED_MYSTIC_TICKET                      315
#define FLAG_RECEIVED_OLD_SEA_MAP                        316 
#define FLAG_RECEIVED_ASH_GRENINJA                       317
#define FLAG_RECEIVED_ZYGARDE_10                         318
#define FLAG_UNUSED_MYSTERY_GIFT_0x13F                   319
#define FLAG_UNUSED_MYSTERY_GIFT_0x140                   320
#define FLAG_UNUSED_MYSTERY_GIFT_0x141                   321
#define FLAG_UNUSED_MYSTERY_GIFT_0x142                   322
#define FLAG_UNUSED_MYSTERY_GIFT_0x143                   323
#define FLAG_UNUSED_MYSTERY_GIFT_0x144                   324
#define FLAG_UNUSED_MYSTERY_GIFT_0x145                   325
#define FLAG_UNUSED_MYSTERY_GIFT_0x146                   326
#define FLAG_UNUSED_MYSTERY_GIFT_0x147                   327
#define FLAG_UNUSED_MYSTERY_GIFT_0x148                   328
#define FLAG_UNUSED_MYSTERY_GIFT_0x149                   329
#define FLAG_UNUSED_MYSTERY_GIFT_0x14A                   330
#define FLAG_UNUSED_MYSTERY_GIFT_0x14B                   331
#define FLAG_UNUSED_MYSTERY_GIFT_0x14C                   332
#define FLAG_UNUSED_MYSTERY_GIFT_0x14D                   333
#define FLAG_MIRAGE_TOWER_VISIBLE                        334
#define FLAG_CHOSE_ROOT_FOSSIL                           335
#define FLAG_CHOSE_CLAW_FOSSIL                           336
#define FLAG_RECEIVED_POWDER_JAR                         337
#define FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER             338
#define FLAG_MET_BATTLE_FRONTIER_BREEDER                 339
#define FLAG_MET_BATTLE_FRONTIER_MANIAC                  340
#define FLAG_ENTERED_CONTEST                             341
#define FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN              342
#define FLAG_MET_BATTLE_FRONTIER_GAMBLER                 343
#define FLAG_ENABLE_MR_STONE_POKENAV                     344
#define FLAG_NURSE_MENTIONS_GOLD_CARD                    345
#define FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR              346 // Will be unused
#define FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR             347 // Will be unused

// Trainer Rematch Flags
#define FLAG_MATCH_CALL_REGISTERED                       348
#define FLAG_REMATCH_ROSE                                349
#define FLAG_REMATCH_ANDRES                              350
#define FLAG_REMATCH_DUSTY                               351
#define FLAG_REMATCH_LOLA                                352
#define FLAG_REMATCH_RICKY                               353
#define FLAG_REMATCH_LILA_AND_ROY                        354
#define FLAG_REMATCH_CRISTIN                             355
#define FLAG_REMATCH_BROOKE                              356
#define FLAG_REMATCH_WILTON                              357
#define FLAG_REMATCH_VALERIE                             358
#define FLAG_REMATCH_CINDY                               359
#define FLAG_REMATCH_THALIA                              360
#define FLAG_REMATCH_JESSICA                             361
#define FLAG_REMATCH_WINSTON                             362
#define FLAG_REMATCH_STEVE                               363
#define FLAG_REMATCH_TONY                                364
#define FLAG_REMATCH_NOB                                 365
#define FLAG_REMATCH_KOJI                                366
#define FLAG_REMATCH_FERNANDO                            367
#define FLAG_REMATCH_DALTON                              368
#define FLAG_REMATCH_BERNIE                              369
#define FLAG_REMATCH_ETHAN                               370
#define FLAG_REMATCH_JOHN_AND_JAY                        371
#define FLAG_REMATCH_JEFFREY                             372
#define FLAG_REMATCH_CAMERON                             373
#define FLAG_REMATCH_JACKI                               374
#define FLAG_REMATCH_WALTER                              375
#define FLAG_REMATCH_KAREN                               376
#define FLAG_REMATCH_JERRY                               377
#define FLAG_REMATCH_ANNA_AND_MEG                        378
#define FLAG_REMATCH_ISABEL                              379
#define FLAG_REMATCH_MIGUEL                              380
#define FLAG_REMATCH_TIMOTHY                             381
#define FLAG_REMATCH_SHELBY                              382
#define FLAG_REMATCH_CALVIN                              383
#define FLAG_REMATCH_ELLIOT                              384
#define FLAG_REMATCH_ISAIAH                              385
#define FLAG_REMATCH_MARIA                               386
#define FLAG_REMATCH_ABIGAIL                             387
#define FLAG_REMATCH_DYLAN                               388
#define FLAG_REMATCH_KATELYN                             389
#define FLAG_REMATCH_BENJAMIN                            390
#define FLAG_REMATCH_PABLO                               391
#define FLAG_REMATCH_NICOLAS                             392
#define FLAG_REMATCH_ROBERT                              393
#define FLAG_REMATCH_LAO                                 394
#define FLAG_REMATCH_CYNDY                               395
#define FLAG_REMATCH_MADELINE                            396
#define FLAG_REMATCH_JENNY                               397
#define FLAG_REMATCH_DIANA                               398
#define FLAG_REMATCH_AMY_AND_LIV                         399
#define FLAG_REMATCH_ERNEST                              400
#define FLAG_REMATCH_CORY                                401
#define FLAG_REMATCH_EDWIN                               402
#define FLAG_REMATCH_LYDIA                               403
#define FLAG_REMATCH_ISAAC                               404
#define FLAG_REMATCH_GABRIELLE                           405
#define FLAG_REMATCH_CATHERINE                           406
#define FLAG_REMATCH_JACKSON                             407
#define FLAG_REMATCH_HALEY                               408
#define FLAG_REMATCH_JAMES                               409
#define FLAG_REMATCH_TRENT                               410
#define FLAG_REMATCH_SAWYER                              411
#define FLAG_REMATCH_KIRA_AND_DAN                        412
#define FLAG_REMATCH_WALLY                               413
#define FLAG_REMATCH_ROXANNE                             414
#define FLAG_REMATCH_BRAWLY                              415
#define FLAG_REMATCH_WATTSON                             416
#define FLAG_REMATCH_FLANNERY                            417
#define FLAG_REMATCH_NORMAN                              418
#define FLAG_REMATCH_WINONA                              419
#define FLAG_REMATCH_TATE_AND_LIZA                       420
#define FLAG_REMATCH_SIDNEY                              421
#define FLAG_REMATCH_PHOEBE                              422
#define FLAG_REMATCH_GLACIA                              423
#define FLAG_REMATCH_DRAKE                               424
#define FLAG_REMATCH_WALLACE                             425
#define FLAG_SANDSTREWN_RUINS_LEECH_LIFE                 426
#define FLAG_LAVARIDGE_GYM_ENERGY_ROOTS                  427
#define FLAG_DEFEATED_DEOXYS                             428
#define FLAG_BATTLED_DEOXYS                              429
#define FLAG_SHOWN_EON_TICKET                            430
#define FLAG_SHOWN_AURORA_TICKET                         431
#define FLAG_SHOWN_OLD_SEA_MAP                           432
#define FLAG_PETALBURG_GYM_CHILAN_BERRIES                433
#define FLAG_ITEM_MT_PYRE_SUMMIT_TM61_WILLOWISP          434
#define FLAG_MOVE_FORTREE_GYM_ENERGY_ROOT                435
#define FLAG_TRAINER_STEVEN_ROUTE118                     436
#define FLAG_LILYCOVE_MET_BALL_SWAPPER                   437
#define FLAG_HIDE_MOSSDEEP_CYNTHIA                       438
#define FLAG_RECEIVED_LATI_STONES                        439
#define FLAG_ITEM_DESERT_UNDERPASS_FLYGONITE             440
#define FLAG_ITEM_SEAFLOOR_CAVERN_KINGDRANITE            441
#define FLAG_HIDE_SLATEPORT_CITY_BRAWLY                  442
#define FLAG_DEFEATED_REGIROCK                           443
#define FLAG_DEFEATED_REGICE                             444
#define FLAG_DEFEATED_REGISTEEL                          445
#define FLAG_DEFEATED_KYOGRE                             446
#define FLAG_DEFEATED_GROUDON                            447
#define FLAG_DEFEATED_RAYQUAZA                           448
#define FLAG_DEFEATED_ELECTRODE_1_NEW_MAUVILLE           449
#define FLAG_DEFEATED_ELECTRODE_2_NEW_MAUVILLE           450
#define FLAG_DEFEATED_ELECTRODE_3_NEW_MAUVILLE           451
#define FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT           452
#define FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT           453
#define FLAG_DEFEATED_SUDOWOODO                          454
#define FLAG_DEFEATED_MEW                                455
#define FLAG_DEFEATED_LATIAS_OR_LATIOS                   456
#define FLAG_CAUGHT_LATIAS_OR_LATIOS                     457
#define FLAG_CAUGHT_MEW                                  458
#define FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE       459
#define FLAG_MET_SCOTT_IN_VERDANTURF                     460
#define FLAG_MET_SCOTT_IN_FALLARBOR                      461
#define FLAG_MET_SCOTT_IN_LILYCOVE                       462
#define FLAG_MET_SCOTT_IN_EVERGRANDE                     463
#define FLAG_MET_SCOTT_ON_SS_TIDAL                       464
#define FLAG_SCOTT_GIVES_BATTLE_POINTS                   465
#define FLAG_COLLECTED_ALL_GOLD_SYMBOLS                  466
#define FLAG_ENABLE_ROXANNE_MATCH_CALL                   467
#define FLAG_ENABLE_BRAWLY_MATCH_CALL                    468
#define FLAG_ENABLE_WATTSON_MATCH_CALL                   469
#define FLAG_ENABLE_FLANNERY_MATCH_CALL                  470
#define FLAG_ENABLE_WINONA_MATCH_CALL                    471
#define FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL             472
#define FLAG_ENABLE_JUAN_MATCH_CALL                      473

#define FLAG_ROUTE_131_SPLASH_PLATE          0x1DA

#define FLAG_SHOWN_MYSTIC_TICKET             0x1DB
#define FLAG_DEFEATED_HO_OH                  0x1DC
#define FLAG_DEFEATED_LUGIA                  0x1DD

#define FLAG_MOSSDEEP_GYM_REVIVAL_HERBS      0x1DE
#define FLAG_SHOALCAVE_SLOWBRONITE           0x1DF
#define FLAG_ROUTE118_GYARADOSITE            0x1E0
#define FLAG_SCORCHED_SLAB_TYRANITARITE      0x1E1
#define FLAG_ITEM_GRANITE_CAVE_B1F_TM65      0x1E2
#define FLAG_ROUTE_117_MAWILITE              0x1E3

// Mystery Gift Flags (Unknown)
#define FLAG_MYSTERY_EVENT_DONE              0x1E4
#define FLAG_MYSTERY_EVENT_1                 0x1E5
#define FLAG_MYSTERY_EVENT_2                 0x1E6
#define FLAG_MYSTERY_EVENT_3                 0x1E7
#define FLAG_MYSTERY_EVENT_4                 0x1E8
#define FLAG_MYSTERY_EVENT_5                 0x1E9
#define FLAG_MYSTERY_EVENT_6                 0x1EA
#define FLAG_MYSTERY_EVENT_7                 0x1EB
#define FLAG_MYSTERY_EVENT_8                 0x1EC
#define FLAG_MYSTERY_EVENT_9                 0x1ED
#define FLAG_MYSTERY_EVENT_10                0x1EE
#define FLAG_MYSTERY_EVENT_11                0x1EF
#define FLAG_MYSTERY_EVENT_12                0x1F0
#define FLAG_MYSTERY_EVENT_13                0x1F1
#define FLAG_MYSTERY_EVENT_14                0x1F2
#define FLAG_MYSTERY_EVENT_15                0x1F3

// Hidden Items -- sorted by number because that's far more useful than by location
#define FLAG_HIDDEN_ITEMS_START                              499
#define FLAG_HIDDEN_ITEM_LAVARIDGE_TOWN_ICE_HEAL             499
#define FLAG_HIDDEN_ITEM_TRICK_HOUSE_NUGGET                  500
#define FLAG_HIDDEN_ITEM_ROUTE_111_EARTH_PLATE               501
#define FLAG_HIDDEN_ITEM_ROUTE_113_ETHER                     502
#define FLAG_HIDDEN_ITEM_ROUTE_114_CARBOS                    503
#define FLAG_HIDDEN_ITEM_ROUTE_119_CALCIUM                   504
#define FLAG_HIDDEN_ITEM_ROUTE_119_ULTRA_BALL                505
#define FLAG_HIDDEN_ITEM_ROUTE_123_BLACK_SLUDGE              506
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_CARBOS               (FLAG_HIDDEN_ITEMS_START + 0x08)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_GREEN_SHARD          (FLAG_HIDDEN_ITEMS_START + 0x09)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_PEARL                (FLAG_HIDDEN_ITEMS_START + 0x0A)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_BIG_PEARL            (FLAG_HIDDEN_ITEMS_START + 0x0B)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_BLUE_SHARD           (FLAG_HIDDEN_ITEMS_START + 0x0C)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_BOTTLE_CAP_1         (FLAG_HIDDEN_ITEMS_START + 0x0D)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_BOTTLE_CAP           (FLAG_HIDDEN_ITEMS_START + 0x0E)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_ULTRA_BALL           (FLAG_HIDDEN_ITEMS_START + 0x0F)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_STARDUST             (FLAG_HIDDEN_ITEMS_START + 0x10)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_PEARL                (FLAG_HIDDEN_ITEMS_START + 0x11)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_YELLOW_SHARD         (FLAG_HIDDEN_ITEMS_START + 0x12)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_IRON                 (FLAG_HIDDEN_ITEMS_START + 0x13)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_BIG_PEARL            (FLAG_HIDDEN_ITEMS_START + 0x14)
#define FLAG_HIDDEN_ITEM_UNDERWATER_127_STAR_PIECE           (FLAG_HIDDEN_ITEMS_START + 0x15)
#define FLAG_HIDDEN_ITEM_UNDERWATER_127_HP_UP                (FLAG_HIDDEN_ITEMS_START + 0x16)
#define FLAG_HIDDEN_ITEM_UNDERWATER_127_BOTTLE_CAP           (FLAG_HIDDEN_ITEMS_START + 0x17)
#define FLAG_HIDDEN_ITEM_UNDERWATER_127_RED_SHARD            (FLAG_HIDDEN_ITEMS_START + 0x18)
#define FLAG_HIDDEN_ITEM_UNDERWATER_128_PROTEIN              (FLAG_HIDDEN_ITEMS_START + 0x19)
#define FLAG_HIDDEN_ITEM_UNDERWATER_128_PEARL                (FLAG_HIDDEN_ITEMS_START + 0x1A)
#define FLAG_HIDDEN_ITEM_LILYCOVE_CITY_BOTTLE_CAP            (FLAG_HIDDEN_ITEMS_START + 0x1B)
#define FLAG_HIDDEN_ITEM_FALLARBOR_TOWN_NUGGET               (FLAG_HIDDEN_ITEMS_START + 0x1C)
#define FLAG_HIDDEN_ITEM_MT_PYRE_EXTERIOR_ULTRA_BALL         (FLAG_HIDDEN_ITEMS_START + 0x1D)
#define FLAG_HIDDEN_ITEM_ROUTE_113_TM_32                     (FLAG_HIDDEN_ITEMS_START + 0x1E)
#define FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_1_KEY             (FLAG_HIDDEN_ITEMS_START + 0x1F)
#define FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_2_KEY             (FLAG_HIDDEN_ITEMS_START + 0x20)
#define FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_4_KEY             (FLAG_HIDDEN_ITEMS_START + 0x21)
#define FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_6_KEY             (FLAG_HIDDEN_ITEMS_START + 0x22)
#define FLAG_HIDDEN_ITEM_SS_TIDAL_LOWER_DECK_LEFTOVERS       (FLAG_HIDDEN_ITEMS_START + 0x23)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_CALCIUM              (FLAG_HIDDEN_ITEMS_START + 0x24)
#define FLAG_HIDDEN_ITEM_ROUTE_104_POTION                    (FLAG_HIDDEN_ITEMS_START + 0x25)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_BOTTLE_CAP_2         (FLAG_HIDDEN_ITEMS_START + 0x26)
#define FLAG_HIDDEN_ITEM_ROUTE_121_HP_UP                     (FLAG_HIDDEN_ITEMS_START + 0x27)
#define FLAG_HIDDEN_ITEM_ROUTE_121_NUGGET                    (FLAG_HIDDEN_ITEMS_START + 0x28)
#define FLAG_HIDDEN_ITEM_ROUTE_123_FOCUS_SASH                (FLAG_HIDDEN_ITEMS_START + 0x29)
#define FLAG_HIDDEN_ITEM_ROUTE_113_REVIVE                    (FLAG_HIDDEN_ITEMS_START + 0x2A)
#define FLAG_HIDDEN_ITEM_LILYCOVE_CITY_PP_UP                 (FLAG_HIDDEN_ITEMS_START + 0x2B)
#define FLAG_HIDDEN_ITEM_ROUTE_104_SUPER_POTION              (FLAG_HIDDEN_ITEMS_START + 0x2C)
#define FLAG_HIDDEN_ITEM_ROUTE_116_SUPER_POTION              (FLAG_HIDDEN_ITEMS_START + 0x2D)
#define FLAG_HIDDEN_ITEM_ROUTE_106_BIG_PEARL                 (FLAG_HIDDEN_ITEMS_START + 0x2E)
#define FLAG_HIDDEN_ITEM_ROUTE_106_PRISM_SCALE               (FLAG_HIDDEN_ITEMS_START + 0x2F)
#define FLAG_HIDDEN_ITEM_GRANITE_CAVE_B2F_EVERSTONE_1        (FLAG_HIDDEN_ITEMS_START + 0x30)
#define FLAG_HIDDEN_ITEM_GRANITE_CAVE_B2F_EVERSTONE_2        (FLAG_HIDDEN_ITEMS_START + 0x31)
#define FLAG_HIDDEN_ITEM_ROUTE_109_REVIVE                    (FLAG_HIDDEN_ITEMS_START + 0x32)
#define FLAG_HIDDEN_ITEM_ROUTE_109_GREAT_BALL                (FLAG_HIDDEN_ITEMS_START + 0x33)
#define FLAG_HIDDEN_ITEM_ROUTE_109_BOTTLE_CAP_1              (FLAG_HIDDEN_ITEMS_START + 0x34)
#define FLAG_HIDDEN_ITEM_ROUTE_110_GREAT_BALL                (FLAG_HIDDEN_ITEMS_START + 0x35)
#define FLAG_HIDDEN_ITEM_ROUTE_110_REVIVE                    (FLAG_HIDDEN_ITEMS_START + 0x36)
#define FLAG_HIDDEN_ITEM_ROUTE_110_FULL_HEAL                 (FLAG_HIDDEN_ITEMS_START + 0x37)
#define FLAG_HIDDEN_ITEM_ROUTE_111_PROTEIN                   (FLAG_HIDDEN_ITEMS_START + 0x38)
#define FLAG_HIDDEN_ITEM_ROUTE_111_RARE_CANDY                (FLAG_HIDDEN_ITEMS_START + 0x39)
#define FLAG_HIDDEN_ITEM_PETALBURG_WOODS_POTION              (FLAG_HIDDEN_ITEMS_START + 0x3A)
#define FLAG_HIDDEN_ITEM_PETALBURG_WOODS_TINY_MUSHROOM_1     (FLAG_HIDDEN_ITEMS_START + 0x3B)
#define FLAG_HIDDEN_ITEM_PETALBURG_WOODS_TINY_MUSHROOM_2     (FLAG_HIDDEN_ITEMS_START + 0x3C)
#define FLAG_HIDDEN_ITEM_PETALBURG_WOODS_POKE_BALL           (FLAG_HIDDEN_ITEMS_START + 0x3D)
#define FLAG_HIDDEN_ITEM_ROUTE_104_POKE_BALL                 (FLAG_HIDDEN_ITEMS_START + 0x3E)
#define FLAG_HIDDEN_ITEM_ROUTE_106_POKE_BALL                 (FLAG_HIDDEN_ITEMS_START + 0x3F)
#define FLAG_HIDDEN_ITEM_ROUTE_109_ETHER                     (FLAG_HIDDEN_ITEMS_START + 0x40)
#define FLAG_HIDDEN_ITEM_ROUTE_110_POKE_BALL                 (FLAG_HIDDEN_ITEMS_START + 0x41)
#define FLAG_HIDDEN_ITEM_ROUTE_118_BOTTLE_CAP                (FLAG_HIDDEN_ITEMS_START + 0x42)
#define FLAG_HIDDEN_ITEM_ROUTE_118_IRON                      (FLAG_HIDDEN_ITEMS_START + 0x43)
#define FLAG_HIDDEN_ITEM_ROUTE_119_FULL_HEAL                 (FLAG_HIDDEN_ITEMS_START + 0x44)
#define FLAG_HIDDEN_ITEM_ROUTE_120_RARE_CANDY_2              (FLAG_HIDDEN_ITEMS_START + 0x45)
#define FLAG_HIDDEN_ITEM_ROUTE_120_ZINC                      (FLAG_HIDDEN_ITEMS_START + 0x46)
#define FLAG_HIDDEN_ITEM_ROUTE_120_RARE_CANDY_1              (FLAG_HIDDEN_ITEMS_START + 0x47)
#define FLAG_HIDDEN_ITEM_ROUTE_117_BRIGHT_POWDER             (FLAG_HIDDEN_ITEMS_START + 0x48)
#define FLAG_HIDDEN_ITEM_ROUTE_121_FULL_HEAL                 (FLAG_HIDDEN_ITEMS_START + 0x49)
#define FLAG_HIDDEN_ITEM_ROUTE_123_HYPER_POTION              (FLAG_HIDDEN_ITEMS_START + 0x4A)
#define FLAG_HIDDEN_ITEM_LILYCOVE_CITY_DREAM_BALL            (FLAG_HIDDEN_ITEMS_START + 0x4B)
#define FLAG_HIDDEN_ITEM_JAGGED_PASS_LEVEL_BALL              (FLAG_HIDDEN_ITEMS_START + 0x4C)
#define FLAG_HIDDEN_ITEM_JAGGED_PASS_FULL_HEAL               (FLAG_HIDDEN_ITEMS_START + 0x4D)
#define FLAG_HIDDEN_ITEM_MT_PYRE_EXTERIOR_MAX_ETHER          (FLAG_HIDDEN_ITEMS_START + 0x4E)
#define FLAG_HIDDEN_ITEM_MT_PYRE_SUMMIT_SPOOKY_PLATE         (FLAG_HIDDEN_ITEMS_START + 0x4F)
#define FLAG_HIDDEN_ITEM_MT_PYRE_SUMMIT_RARE_CANDY           (FLAG_HIDDEN_ITEMS_START + 0x50)
#define FLAG_HIDDEN_ITEM_VICTORY_ROAD_1F_PP_MAX              (FLAG_HIDDEN_ITEMS_START + 0x51)
#define FLAG_HIDDEN_ITEM_VICTORY_ROAD_B2F_ELIXIR             (FLAG_HIDDEN_ITEMS_START + 0x52)
#define FLAG_HIDDEN_ITEM_VICTORY_ROAD_B2F_MAX_REPEL          (FLAG_HIDDEN_ITEMS_START + 0x53)
#define FLAG_HIDDEN_ITEM_ROUTE_120_TOXIC_PLATE               (FLAG_HIDDEN_ITEMS_START + 0x54)
#define FLAG_HIDDEN_ITEM_ROUTE_104_ANTIDOTE                  (FLAG_HIDDEN_ITEMS_START + 0x55)
#define FLAG_HIDDEN_ITEM_ROUTE_108_RARE_CANDY                (FLAG_HIDDEN_ITEMS_START + 0x56)
#define FLAG_HIDDEN_ITEM_ROUTE_119_MAX_ETHER                 (FLAG_HIDDEN_ITEMS_START + 0x57)
#define FLAG_HIDDEN_ITEM_ROUTE_104_BOTTLE_CAP                (FLAG_HIDDEN_ITEMS_START + 0x58)
#define FLAG_HIDDEN_ITEM_ROUTE_105_BOTTLE_CAP                (FLAG_HIDDEN_ITEMS_START + 0x59)
#define FLAG_HIDDEN_ITEM_ROUTE_109_BOTTLE_CAP_2              (FLAG_HIDDEN_ITEMS_START + 0x5A)
#define FLAG_HIDDEN_ITEM_ROUTE_109_BOTTLE_CAP_3              (FLAG_HIDDEN_ITEMS_START + 0x5B)
#define FLAG_HIDDEN_ITEM_ROUTE_128_BOTTLE_CAP_1              (FLAG_HIDDEN_ITEMS_START + 0x5C)
#define FLAG_HIDDEN_ITEM_ROUTE_128_BOTTLE_CAP_2              (FLAG_HIDDEN_ITEMS_START + 0x5D)
#define FLAG_HIDDEN_ITEM_ROUTE_128_BOTTLE_CAP_3              (FLAG_HIDDEN_ITEMS_START + 0x5E)
#define FLAG_HIDDEN_ITEM_PETALBURG_CITY_RARE_CANDY           (FLAG_HIDDEN_ITEMS_START + 0x5F)
#define FLAG_HIDDEN_ITEM_ROUTE_116_BLACK_GLASSES             (FLAG_HIDDEN_ITEMS_START + 0x60)
#define FLAG_HIDDEN_ITEM_ROUTE_115_BOTTLE_CAP                (FLAG_HIDDEN_ITEMS_START + 0x61)
#define FLAG_HIDDEN_ITEM_ROUTE_113_NUGGET                    (FLAG_HIDDEN_ITEMS_START + 0x62)
#define FLAG_HIDDEN_ITEM_ROUTE_123_PP_MAX                    (FLAG_HIDDEN_ITEMS_START + 0x63)
#define FLAG_HIDDEN_ITEM_ROUTE_121_MAX_REVIVE                (FLAG_HIDDEN_ITEMS_START + 0x64)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_CALCIUM            (FLAG_HIDDEN_ITEMS_START + 0x65)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_ZINC               (FLAG_HIDDEN_ITEMS_START + 0x66)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_PROTEIN            (FLAG_HIDDEN_ITEMS_START + 0x67)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_IRON               (FLAG_HIDDEN_ITEMS_START + 0x68)
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_SOUTH_EAST_FULL_RESTORE (FLAG_HIDDEN_ITEMS_START + 0x69)
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_NORTH_EAST_RARE_CANDY   (FLAG_HIDDEN_ITEMS_START + 0x6A)
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_NORTH_EAST_ZINC         (FLAG_HIDDEN_ITEMS_START + 0x6B)
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_SOUTH_EAST_PP_UP        (FLAG_HIDDEN_ITEMS_START + 0x6C)
#define FLAG_HIDDEN_ITEM_NAVEL_ROCK_TOP_SACRED_ASH           (FLAG_HIDDEN_ITEMS_START + 0x6D)
#define FLAG_HIDDEN_ITEM_ROUTE_123_RARE_CANDY                (FLAG_HIDDEN_ITEMS_START + 0x6E)
#define FLAG_HIDDEN_ITEM_ROUTE_105_BIG_PEARL                 (FLAG_HIDDEN_ITEMS_START + 0x6F)
#define FLAG_HIDDEN_ITEM_SEASPRAY_CAVE_B1F_ICICLE_PLATE      (FLAG_HIDDEN_ITEMS_START + 0x70)
#define FLAG_HIDDEN_ITEM_SEASPRAY_CAVE_B1F_ICE_STONE         (FLAG_HIDDEN_ITEMS_START + 0x71)
#define FLAG_HIDDEN_ITEM_EMBER_PATH_FLAME_PLATE              (FLAG_HIDDEN_ITEMS_START + 0x72)
#define FLAG_HIDDEN_ITEM_EMBER_PATH_MAGMARIZER               (FLAG_HIDDEN_ITEMS_START + 0x73)
#define FLAG_HIDDEN_ITEM_ASHEN_WOODS_PP_MAX                  (FLAG_HIDDEN_ITEMS_START + 0x74)
#define FLAG_SANDSTREWN_RUINS_PROTECTOR                      (FLAG_HIDDEN_ITEMS_START + 0x75)
#define FLAG_SANDSTREWN_RUINS_BIG_NUGGET                     (FLAG_HIDDEN_ITEMS_START + 0x76)
#define FLAG_HIDDEN_ITEM_SCORCHED_SLAB_STONE_PLATE           (FLAG_HIDDEN_ITEMS_START + 0x77)
#define FLAG_HIDDEN_ITEM_METEOR_FALLS_DRACO_PLATE            (FLAG_HIDDEN_ITEMS_START + 0x78)
#define FLAG_HIDDEN_ITEM_ROUTE_119_ZAP_PLATE                 (FLAG_HIDDEN_ITEMS_START + 0x79)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_PIXIE_PLATE          (FLAG_HIDDEN_ITEMS_START + 0x7A)
#define FLAG_HIDDEN_ITEM_ROUTE_115_FIST_PLATE                (FLAG_HIDDEN_ITEMS_START + 0x7B)
#define FLAG_HIDDEN_ITEM_SKY_PILLAR_SKY_PLATE                (FLAG_HIDDEN_ITEMS_START + 0x7C)
#define FLAG_HIDDEN_ITEM_UNDERWATER_127_MIND_PLATE           (FLAG_HIDDEN_ITEMS_START + 0x7D)
#define FLAG_HIDDEN_ITEM_ASHEN_WOODS_BALM_MUSHROOM_1         (FLAG_HIDDEN_ITEMS_START + 0x7E)
#define FLAG_HIDDEN_ITEM_ASHEN_WOODS_BALM_MUSHROOM_2         (FLAG_HIDDEN_ITEMS_START + 0x7F)
#define FLAG_HIDDEN_ITEM_RUINS_EXTERIOR_STAR_PIECE_1         (FLAG_HIDDEN_ITEMS_START + 0x80)
#define FLAG_HIDDEN_ITEM_RUINS_EXTERIOR_STAR_PIECE_2         (FLAG_HIDDEN_ITEMS_START + 0x81)
#define FLAG_HIDDEN_ITEM_RED_NECTAR                          (FLAG_HIDDEN_ITEMS_START + 0x82)
#define FLAG_HIDDEN_ITEM_PINK_NECTAR                         (FLAG_HIDDEN_ITEMS_START + 0x83)
#define FLAG_HIDDEN_ITEM_PURPLE_NECTAR                       (FLAG_HIDDEN_ITEMS_START + 0x84)
#define FLAG_HIDDEN_ITEM_YELLOW_NECTAR                       (FLAG_HIDDEN_ITEMS_START + 0x85)
#define FLAG_HIDDEN_ITEM_DEWFORD_MANOR_BOTTLE_CAP            (FLAG_HIDDEN_ITEMS_START + 0x86)
#define FLAG_HIDDEN_ITEM_AQUA_HIDEOUT_B1F_BOTTLE_CAP1        (FLAG_HIDDEN_ITEMS_START + 0x87)
#define FLAG_HIDDEN_ITEM_AQUA_HIDEOUT_B1F_BOTTLE_CAP2        (FLAG_HIDDEN_ITEMS_START + 0x88)
#define FLAG_HIDDEN_ITEM_ABANDONED_SHIP_ROOMS_B1F_BOTTLE_CAP (FLAG_HIDDEN_ITEMS_START + 0x89)
#define FLAG_HIDDEN_ITEM_CABLECAR_STATION_BOTTLE_CAP         (FLAG_HIDDEN_ITEMS_START + 0x8A)
#define FLAG_HIDDEN_ITEM_ROUTE110_BOTTLE_CAP                 (FLAG_HIDDEN_ITEMS_START + 0x8B)
#define FLAG_HIDDEN_ITEM_ROUTE_109_BOTTLE_CAP_4              (FLAG_HIDDEN_ITEMS_START + 0x8C)
#define FLAG_HIDDEN_ITEM_ROUTE_109_BOTTLE_CAP_5              (FLAG_HIDDEN_ITEMS_START + 0x8D)
#define FLAG_HIDDEN_ITEM_RUSTBORO_CITY_BOTTLE_CAP            (FLAG_HIDDEN_ITEMS_START + 0x8E)
#define FLAG_HIDDEN_ITEM_GAME_CORNER_BOTTLE_CAP1             (FLAG_HIDDEN_ITEMS_START + 0x8F)
#define FLAG_HIDDEN_ITEM_GAME_CORNER_BOTTLE_CAP2             (FLAG_HIDDEN_ITEMS_START + 0x90)
#define FLAG_HIDDEN_ITEM_MOSSDEEP_CITY_BOTTLE_CAP            (FLAG_HIDDEN_ITEMS_START + 0x91)
#define FLAG_HIDDEN_ITEM_DEWFORD_MEADOW_GRASS_GEM            (FLAG_HIDDEN_ITEMS_START + 0x92)
#define FLAG_HIDDEN_ITEM_DEWFORD_MEADOW_FAIRY_GEM            (FLAG_HIDDEN_ITEMS_START + 0x93)
#define FLAG_HIDDEN_ITEM_JIRACHIS_ROOM_COMET_SHARD           (FLAG_HIDDEN_ITEMS_START + 0x94)
#define FLAG_HIDDEN_ITEM_SANDSTREWN_RUINS_RED_SHARD          (FLAG_HIDDEN_ITEMS_START + 0x95)
#define FLAG_HIDDEN_ITEM_SANDSTREWN_RUINS_GREEN_SHARD        (FLAG_HIDDEN_ITEMS_START + 0x96)
#define FLAG_HIDDEN_ITEM_SANDSTREWN_RUINS_BLUE_SHARD         (FLAG_HIDDEN_ITEMS_START + 0x97)
#define FLAG_HIDDEN_ITEM_SANDSTREWN_RUINS_YELLOW_SHARD       (FLAG_HIDDEN_ITEMS_START + 0x98)
#define FLAG_HIDDEN_ITEM_ALTERING_CAVE_GOLD_BOTTLE_CAP       (FLAG_HIDDEN_ITEMS_START + 0x99)
#define FLAG_HIDDEN_ITEM_ALTERING_CAVE_CALCIUM               (FLAG_HIDDEN_ITEMS_START + 0x9A)
#define FLAG_HIDDEN_ITEM_ALTERING_CAVE_CARBOS                (FLAG_HIDDEN_ITEMS_START + 0x9B)
#define FLAG_HIDDEN_ITEM_ALTERING_CAVE_MAX_REVIVE            (FLAG_HIDDEN_ITEMS_START + 0x9C)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_IRON_PLATE           (FLAG_HIDDEN_ITEMS_START + 0x9D)
#define FLAG_HIDDEN_ITEM_DEWFORD_MANOR_DREAD_PLATE           (FLAG_HIDDEN_ITEMS_START + 0x9E) // 0x292
#define FLAG_MOVE_RELEARNER     0x293 // Used to distinguish between the actual move relearner and the Moves option in the party menu.

//Debug Flags
#define FLAG_SYS_NO_COLLISION        0x294 //DEBUG
#define FLAG_SYS_NO_ENCOUNTER        0x295 //DEBUG
#define FLAG_SYS_NO_TRAINER_SEE      0x296 //DEBUG
#define FLAG_SYS_NO_BAG_USE          0x297 //DEBUG
#define FLAG_SYS_NO_CATCHING         0x298 //DEBUG
#define FLAG_SYS_PC_FROM_DEBUG_MENU  0x299 //DEBUG

#define FLAG_SYS_MOVE_INFO                    0x29A // Battle Interface
#define FLAG_IS_DAYNIGHT_INVERTED             0x29B // Ported from ROWE
#define FLAG_SYS_AUTOWIN                      0x29C // DEBUG
#define FLAG_SYS_MGBA_PRINT                   0x29D // DEBUG
#define FLAG_SYS_DISABLE_AUTOHEAL             0x29E // Used in some battles
#define FLAG_SYS_DISABLE_DAMAGE_DONE          0x29F
#define FLAG_SYS_LOCKED_MODE                  0x2A0 // Elite Four only
#define FLAG_TOTEM_BATTLE                     0x2A1 // For Totem boost
#define FLAG_SMART_AI                         0x2A2 //
#define FLAG_DEFEATED_METEOR_FALLS_HAXORUS    0x2A3 //
#define FLAG_DEFEATED_SEASPRAY_CAVE_DEWGONG   0x2A4 //
#define FLAG_DEFEATED_PETALBURG_WOODS_BRELOOM 0x2A5 //
#define FLAG_OBTAINED_METEOR_FALLS_HAXORUS    0x2A6 // Hide Totem Mega Haxorus after defeat
#define FLAG_OBTAINED_SEASPRAY_CAVE_DEWGONG   0x2A7 //
#define FLAG_OBTAINED_PETALBURG_WOODS_BRELOOM 0x2A8 //
#define FLAG_DEFEATED_ROUTE114_FERALIGATR     0x2A9 //
#define FLAG_OBTAINED_ROUTE114_FERALIGATR     0x2AA //
#define FLAG_DEFEATED_ROUTE132_GYARADOS       0x2AB //
#define FLAG_OBTAINED_ROUTE132_GYARADOS       0x2AC //
#define FLAG_DEFEATED_ROUTE111_SANDSLASH      0x2AD //
#define FLAG_OBTAINED_ROUTE111_SANDSLASH      0x2AE //
#define FLAG_HIDE_ABANDONED_SHIP_SHEDINJITE      0x2AF // Hide Shedinjite until Bug Catcher is defeated
#define FLAG_DEFEATED_ABANDONDED_SHIP_BUGCATCHER 0x2B0 // Hide Shedinjite Bug Catcher when defeated
#define FLAG_SKY_PILLAR_GAUNTLET_HIDE_TRAINER_1  0x2B1 // 
#define FLAG_SKY_PILLAR_GAUNTLET_HIDE_TRAINER_2  0x2B2 //
#define FLAG_SKY_PILLAR_GAUNTLET_HIDE_TRAINER_3  0x2B3 //
#define FLAG_OBTAINED_DRAGONITENITE              0x2B4 //
#define FLAG_TRAINER_DRAGONITENITE_SAGE_1        0x2B5 // Trainer Flag
#define FLAG_TRAINER_DRAGONITENITE_SAGE_2        0x2B6 // Trainer Flag
#define FLAG_TRAINER_DRAGONITENITE_SAGE_3        0x2B7 // Trainer Flag
#define FLAG_OBTAINED_HITMON_MEGA_STONE          0x2B8 // Trainer Flag
#define FLAG_TRAINER_HITMONSTONE_BLACKBELT       0x2B9 // Trainer Flag
#define FLAG_TRAINER_GRANBULLITE_ROUTE123        0x2BA // Trainer Flag
#define FLAG_OBTAINED_SLAKINGITE                 0x2BB //

// Event Flags
#define FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG                      0x2BC
#define FLAG_HIDE_APPRENTICE                                        0x2BD
#define FLAG_HIDE_POKEMON_CENTER_2F_MYSTERY_GIFT_MAN                0x2BE
#define FLAG_HIDE_UNION_ROOM_PLAYER_1                               0x2BF
#define FLAG_HIDE_UNION_ROOM_PLAYER_2                               0x2C0
#define FLAG_HIDE_UNION_ROOM_PLAYER_3                               0x2C1
#define FLAG_HIDE_UNION_ROOM_PLAYER_4                               0x2C2
#define FLAG_HIDE_UNION_ROOM_PLAYER_5                               0x2C3
#define FLAG_HIDE_UNION_ROOM_PLAYER_6                               0x2C4
#define FLAG_HIDE_UNION_ROOM_PLAYER_7                               0x2C5
#define FLAG_HIDE_UNION_ROOM_PLAYER_8                               0x2C6
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1               0x2C7
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2               0x2C8
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3               0x2C9
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4               0x2CA
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5               0x2CB
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6               0x2CC
#define FLAG_HIDE_SAFARI_ZONE_SOUTH_CONSTRUCTION_WORKERS            0x2CD
#define FLAG_HIDE_MEW                                               0x2CE
#define FLAG_HIDE_ROUTE_104_RIVAL                                   0x2CF
#define FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE                  0x2D0
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH                  0x2D1
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM          0x2D2
#define FLAG_HIDE_ROUTE_103_RIVAL                                   0x2D3
#define FLAG_HIDE_PETALBURG_WOODS_DEVON_EMPLOYEE                    0x2D4
#define FLAG_HIDE_PETALBURG_WOODS_AQUA_GRUNT                        0x2D5
#define FLAG_HIDE_PETALBURG_CITY_WALLY                              0x2D6
#define FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_INVISIBLE_NINJA_BOY   0x2D7
#define FLAG_HIDE_PETALBURG_CITY_WALLYS_MOM                         0x2D8
#define FLAG_METEOR_FALLS_SALAMENCITE                               0x2D9
#define FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER                     0x2DA
#define FLAG_HIDE_RUSTBORO_CITY_AQUA_GRUNT                          0x2DB
#define FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1                    0x2DC
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE_ASLEEP              0x2DD
#define FLAG_HIDE_PLAYERS_HOUSE_DAD                                 0x2DE
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING      0x2DF
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING          0x2E0
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_MAGMA_NOTE             0x2E1
#define FLAG_HIDE_ROUTE_104_MR_BRINEY                               0x2E2
#define FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY                           0x2E3
#define FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN                            0x2E4
#define FLAG_HIDE_ROUTE_109_MR_BRINEY                               0x2E5
#define FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT                          0x2E6
#define FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN                       0x2E7
#define FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT                          0x2E8
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN            0x2E9
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY                    0x2EA
#define FLAG_HIDE_SAFARI_ZONE_SOUTH_EAST_EXPANSION                  0x2EB
#define FLAG_HIDE_LILYCOVE_HARBOR_EVENT_TICKET_TAKER                0x2EC
#define FLAG_HIDE_SLATEPORT_CITY_SCOTT                              0x2ED
#define FLAG_HIDE_ROUTE_101_ZIGZAGOON                               0x2EE
#define FLAG_HIDE_VICTORY_ROAD_EXIT_WALLY                           0x2EF
#define FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE                       0x2F0
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN              0x2F1
#define FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1          0x2F2
#define FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2          0x2F3
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA          0x2F4
#define FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_BEDROOM_MOM               0x2F5
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM                0x2F6
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM                    0x2F7
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM      0x2F8
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK              0x2F9
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK                  0x2FA
#define FLAG_HIDE_DEOXYS                                            0x2FB
#define FLAG_HIDE_BIRTH_ISLAND_DEOXYS_TRIANGLE                      0x2FC
#define FLAG_HIDE_MAUVILLE_CITY_SCOTT                               0x2FD
#define FLAG_HIDE_VERDANTURF_TOWN_SCOTT                             0x2FE
#define FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT                  0x2FF
#define FLAG_HIDE_ROUTE_111_VICTOR_WINSTRATE                        0x300
#define FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE                      0x301
#define FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE                          0x302
#define FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE                         0x303
#define FLAG_HIDE_PETALBURG_GYM_NORMAN                              0x304
#define FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA                           0x305
#define FLAG_HIDE_LILYCOVE_CONTEST_HALL_CONTEST_ATTENDANT_1         0x306
#define FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR                           0x307
#define FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_1                          0x308
#define FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_2                          0x309
#define FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_3                          0x30A
#define FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_4                          0x30B
#define FLAG_HIDE_LILYCOVE_MUSEUM_TOURISTS                          0x30C
#define FLAG_HIDE_PETALBURG_GYM_GREETER                             0x30D
#define FLAG_HIDE_MARINE_CAVE_KYOGRE                                0x30E
#define FLAG_HIDE_TERRA_CAVE_GROUDON                                0x30F
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM          0x310
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM              0x311
#define FLAG_HIDE_ROUTE_119_SCOTT                                   0x312
#define FLAG_HIDE_LILYCOVE_MOTEL_SCOTT                              0x313
#define FLAG_HIDE_MOSSDEEP_CITY_SCOTT                               0x314
#define FLAG_HIDE_FANCLUB_OLD_LADY                                  0x315
#define FLAG_HIDE_FANCLUB_BOY                                       0x316
#define FLAG_HIDE_FANCLUB_LITTLE_BOY                                0x317
#define FLAG_HIDE_FANCLUB_LADY                                      0x318
#define FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT               0x319
#define FLAG_HIDE_LITTLEROOT_TOWN_RIVAL                             0x31A
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCH                             0x31B
#define FLAG_HIDE_ROUTE_111_GABBY_AND_TY_1                          0x31C
#define FLAG_HIDE_ROUTE_118_GABBY_AND_TY_1                          0x31D
#define FLAG_HIDE_ROUTE_120_GABBY_AND_TY_1                          0x31E
#define FLAG_HIDE_ROUTE_111_GABBY_AND_TY_3                          0x31F
#define FLAG_HIDE_LUGIA                                             0x320
#define FLAG_HIDE_HO_OH                                             0x321
#define FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER                    0x322
#define FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER                   0x323
#define FLAG_HIDE_MAUVILLE_CITY_WALLY                               0x324
#define FLAG_HIDE_MAUVILLE_CITY_WALLYS_UNCLE                        0x325
#define FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY                0x326
#define FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND                   0x327
#define FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDAS_BOYFRIEND     0x328
#define FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE         0x329
#define FLAG_HIDE_SS_TIDAL_CORRIDOR_SCOTT                           0x32A
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CYNDAQUIL     0x32B
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_TOTODILE      0x32C
#define FLAG_HIDE_ROUTE_116_DROPPED_GLASSES_MAN                     0x32D
#define FLAG_HIDE_RUSTBORO_CITY_RIVAL                               0x32E
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL     0x32F
#define FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE                           0x330
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL       0x331
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL           0x332
#define FLAG_HIDE_ROUTE_112_TEAM_MAGMA                              0x333
#define FLAG_HIDE_CAVE_OF_ORIGIN_B1F_WALLACE                        0x334
#define FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE         0x335
#define FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE         0x336
#define FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA                          0x337
#define FLAG_HIDE_PETALBURG_GYM_WALLYS_DAD                          0x338
#define FLAG_MIRAGE_TOWER_4F_AERODACTYLITE                          0x339
#define FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE                            0x33A
#define FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE                             0x33B
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE                     0x33C
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE                      0x33D
#define FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD                         0x33E
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS               0x33F
#define FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER                0x340
#define FLAG_HIDE_GRANITE_CAVE_STEVEN                               0x341
#define FLAG_HIDE_ROUTE_128_STEVEN                                  0x342
#define FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY                       0x343
#define FLAG_HIDE_BATTLE_FRONTIER_RECEPTION_GATE_SCOTT              0x344
#define FLAG_HIDE_ROUTE_110_BIRCH                                   0x345
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CHIKORITA     0x346
#define FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1                             0x347
#define FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN                      0x348
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN               0x349
#define FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO                         0x34A
#define FLAG_HIDE_ROUTE_111_NURSE                                   0x34B
#define FLAG_HIDE_RUSTBORO_CITY_SCIENTIST                           0x34C
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT                  0x34D
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE                      0x34E
#define FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD                           0x34F
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW            0x350
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL          0x351
#define FLAG_HIDE_MAGMA_HIDEOUT_4F_GROUDON_ASLEEP                   0x352
#define FLAG_HIDE_ROUTE_119_RIVAL                                   0x353
#define FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS                         0x354
#define FLAG_HIDE_MAGMA_HIDEOUT_4F_GROUDON                          0x355
#define FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS                         0x356
#define FLAG_HIDE_SKY_PILLAR_WALLACE                                0x357
#define FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE                              0x358
#define FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS                              0x359
#define FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY                       0x35A
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE                     0x35B
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL                    0x35C
#define FLAG_HIDE_LILYCOVE_HARBOR_SSTIDAL                           0x35D
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA          0x35E
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN              0x35F
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1           0x360
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2           0x361
#define FLAG_HIDE_PETALBURG_GYM_WALLY                               0x362
#define FLAG_HIDE_JAGGED_PASS_CHANSEY                               0x363
#define FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN                           0x364
#define FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY          0x365
#define FLAG_HIDE_LANETTES_HOUSE_LANETTE                            0x366
#define FLAG_HIDE_FALLORBOR_POKEMON_CENTER_LANETTE                  0x367
#define FLAG_HIDE_TRICK_HOUSE_ENTRANCE_MAN                          0x368
#define FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER_REPLACEMENT    0x369
#define FLAG_HIDE_DESERT_UNDERPASS_FOSSIL                           0x36A
#define FLAG_HIDE_ROUTE_111_PLAYER_DESCENT                          0x36B
#define FLAG_HIDE_ROUTE_111_DESERT_FOSSIL                           0x36C
#define FLAG_HIDE_MT_CHIMNEY_TRAINERS                               0x36D
#define FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT                         0x36E
#define FLAG_HIDE_RUSTURF_TUNNEL_BRINEY                             0x36F
#define FLAG_HIDE_RUSTURF_TUNNEL_PEEKO                              0x370
#define FLAG_HIDE_BRINEYS_HOUSE_PEEKO                               0x371
#define FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA                          0x372
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS         0x373
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_1     0x374
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_2     0x375
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_ARCHIE           0x376
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_CAPTAIN_STERN    0x377
#define FLAG_HIDE_BATTLE_TOWER_OPPONENT                             0x378
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL                  0x379
#define FLAG_HIDE_ROUTE_119_TEAM_AQUA                               0x37A
#define FLAG_HIDE_ROUTE_116_MR_BRINEY                               0x37B
#define FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS                      0x37C
#define FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS                      0x37D
#define FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND                        0x37E
#define FLAG_HIDE_LILYCOVE_CONTEST_HALL_CONTEST_ATTENDANT_2         0x37F
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380          0x380
#define FLAG_HIDE_ROUTE_101_BIRCH                                   0x381
#define FLAG_HIDE_ROUTE_103_BIRCH                                   0x382
#define FLAG_HIDE_TRICK_HOUSE_END_MAN                               0x383
#define FLAG_HIDE_ROUTE_110_TEAM_AQUA                               0x384
#define FLAG_HIDE_ROUTE_118_GABBY_AND_TY_2                          0x385
#define FLAG_HIDE_ROUTE_120_GABBY_AND_TY_2                          0x386
#define FLAG_HIDE_ROUTE_111_GABBY_AND_TY_2                          0x387
#define FLAG_HIDE_ROUTE_118_GABBY_AND_TY_3                          0x388
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS                     0x389
#define FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST                      0x38A
#define FLAG_HIDE_FALLARBOR_AZURILL                                 0x38B
#define FLAG_HIDE_LILYCOVE_HARBOR_FERRY_ATTENDANT                   0x38C
#define FLAG_HIDE_LILYCOVE_HARBOR_FERRY_SAILOR                      0x38D
#define FLAG_HIDE_SOUTHERN_ISLAND_EON_STONE                         0x38E
#define FLAG_HIDE_SOUTHERN_ISLAND_UNCHOSEN_EON_DUO_MON              0x38F
#define FLAG_HIDE_MAUVILLE_CITY_WATTSON                             0x390
#define FLAG_HIDE_MAUVILLE_GYM_WATTSON                              0x391
#define FLAG_HIDE_ROUTE_121_TEAM_AQUA_GRUNTS                        0x392
#define FLAG_UNKNOWN_0x393                                          0x393 // Set, however has no purpose.
#define FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE                             0x394
#define FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA                          0x395
#define FLAG_HIDE_BATTLE_TOWER_REPORTER                             0x396
#define FLAG_HIDE_ROUTE_110_RIVAL                                   0x397
#define FLAG_HIDE_CHAMPIONS_ROOM_RIVAL                              0x398
#define FLAG_HIDE_CHAMPIONS_ROOM_BIRCH                              0x399
#define FLAG_HIDE_ROUTE_110_RIVAL_ON_BIKE                           0x39A
#define FLAG_HIDE_ROUTE_119_RIVAL_ON_BIKE                           0x39B
#define FLAG_HIDE_AQUA_HIDEOUT_GRUNTS                               0x39C
#define FLAG_HIDE_LILYCOVE_MOTEL_GAME_DESIGNERS                     0x39D
#define FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA                              0x39E
#define FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA                             0x39F
#define FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO                        0x3A0
#define FLAG_HIDE_LAVARIDGE_TOWN_RIVAL                              0x3A1
#define FLAG_HIDE_LAVARIDGE_TOWN_RIVAL_ON_BIKE                      0x3A2
#define FLAG_HIDE_RUSTURF_TUNNEL_ROCK_1                             0x3A3
#define FLAG_HIDE_RUSTURF_TUNNEL_ROCK_2                             0x3A4
#define FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL                      0x3A5
#define FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL                     0x3A6
#define FLAG_HIDE_REGIROCK                                          0x3A7
#define FLAG_HIDE_REGICE                                            0x3A8
#define FLAG_HIDE_REGISTEEL                                         0x3A9
#define FLAG_HIDE_METEOR_FALLS_TEAM_AQUA                            0x3AA
#define FLAG_HIDE_METEOR_FALLS_TEAM_MAGMA                           0x3AB
#define FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN                      0x3AC
#define FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT               0x3AD
#define FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO                          0x3AE
#define FLAG_HIDE_AQUA_HIDEOUT_B2F_SUBMARINE_SHADOW                 0x3AF
#define FLAG_HIDE_ROUTE_128_ARCHIE                                  0x3B0
#define FLAG_HIDE_ROUTE_128_MAXIE                                   0x3B1
#define FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS                       0x3B2
#define FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE                          0x3B3
#define FLAG_ITEM_MOSSDEEP_CITY_MILOTICITE                          0x3B4
#define FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE              0x3B5
#define FLAG_HIDE_SS_TIDAL_CORRIDOR_MR_BRINEY                       0x3B6
#define FLAG_HIDE_SS_TIDAL_ROOMS_SNATCH_GIVER                       0x3B7
#define FLAG_RECEIVED_SHOAL_SALT_1                                  0x3B8
#define FLAG_RECEIVED_SHOAL_SALT_2                                  0x3B9
#define FLAG_RECEIVED_SHOAL_SALT_3                                  0x3BA
#define FLAG_RECEIVED_SHOAL_SALT_4                                  0x3BB
#define FLAG_RECEIVED_SHOAL_SHELL_1                                 0x3BC
#define FLAG_RECEIVED_SHOAL_SHELL_2                                 0x3BD
#define FLAG_RECEIVED_SHOAL_SHELL_3                                 0x3BE
#define FLAG_RECEIVED_SHOAL_SHELL_4                                 0x3BF
#define FLAG_HIDE_ROUTE_111_SECRET_POWER_MAN                        0x3C0
#define FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION                       0x3C1
#define FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN      0x3C2
#define FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL                          0x3C3
#define FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL                          0x3C4
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT 0x3C5
#define FLAG_HIDE_ROUTE_118_STEVEN                                  0x3C6
#define FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN                0x3C7
#define FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_MELTAN_POKEBALL       0x3C8
#define FLAG_HIDE_FORTREE_CITY_KECLEON                              0x3C9
#define FLAG_HIDE_ROUTE_120_KECLEON_BRIDGE                          0x3CA
#define FLAG_HIDE_LILYCOVE_CITY_RIVAL                               0x3CB
#define FLAG_HIDE_ROUTE_120_STEVEN                                  0x3CC
#define FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN                            0x3CD
#define FLAG_HIDE_NEW_MAUVILLE_ELECTRODE_1                          0x3CE
#define FLAG_HIDE_NEW_MAUVILLE_ELECTRODE_2                          0x3CF
#define FLAG_HIDE_NEW_MAUVILLE_ELECTRODE_3                          0x3D0
#define FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_1                      0x3D1
#define FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_2                      0x3D2
#define FLAG_HIDE_OLDALE_TOWN_RIVAL                                 0x3D3
#define FLAG_HIDE_UNDERWATER_SEA_FLOOR_CAVERN_STOLEN_SUBMARINE      0x3D4
#define FLAG_HIDE_ROUTE_120_KECLEON_BRIDGE_SHADOW                   0x3D5
#define FLAG_HIDE_ROUTE_120_KECLEON_1                               0x3D6
#define FLAG_HIDE_RUSTURF_TUNNEL_WANDA                              0x3D7
#define FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDA                0x3D8
#define FLAG_HIDE_ROUTE_120_KECLEON_2                               0x3D9
#define FLAG_HIDE_ROUTE_120_KECLEON_3                               0x3DA
#define FLAG_HIDE_ROUTE_120_KECLEON_4                               0x3DB
#define FLAG_HIDE_ROUTE_120_KECLEON_5                               0x3DC
#define FLAG_HIDE_ROUTE_119_KECLEON_1                               0x3DD
#define FLAG_HIDE_ROUTE_119_KECLEON_2                               0x3DE
#define FLAG_HIDE_ROUTE_101_BOY                                     0x3DF
#define FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M                 0x3E0
#define FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON          0x3E1
#define FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY                       0x3E2
#define FLAG_HIDE_PETALBURG_CITY_SCOTT                              0x3E3
#define FLAG_HIDE_SOOTOPOLIS_CITY_RAYQUAZA                          0x3E4
#define FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE                            0x3E5
#define FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON                           0x3E6
#define FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT                0x3E7

// Item Ball Flags
#define FLAG_ITEM_ROUTE_102_POTION                                  0x3E8
#define FLAG_ITEM_ROUTE_116_X_SPECIAL                               0x3E9
#define FLAG_ITEM_ROUTE_104_PP_UP                                   0x3EA
#define FLAG_ITEM_ROUTE_105_ABILITY_PATCH                           0x3EB
#define FLAG_ITEM_ROUTE_106_KINGLERITE                              0x3EC
#define FLAG_ITEM_ROUTE_109_PP_UP                                   0x3ED
#define FLAG_ITEM_ROUTE_109_RARE_CANDY                              0x3EE
#define FLAG_ITEM_ROUTE_110_MANECTITE                               0x3EF
#define FLAG_ITEM_ROUTE_111_TM_37                                   0x3F0
#define FLAG_ITEM_ROUTE_111_STAR_PIECE                              0x3F1
#define FLAG_ITEM_ROUTE_111_ROCK_SLIDE                              0x3F2
#define FLAG_ITEM_ROUTE_112_HOUNDOOMINITE                           0x3F3
#define FLAG_ITEM_ROUTE_113_MAX_ETHER                               0x3F4
#define FLAG_ITEM_ROUTE_113_SHINY_STONE                             0x3F5
#define FLAG_ITEM_ROUTE_114_RARE_CANDY                              0x3F6
#define FLAG_ITEM_ROUTE_114_TM53_PSYSHOCK                           0x3F7
#define FLAG_ITEM_ROUTE_115_SUPER_POTION                            0x3F8
#define FLAG_ITEM_ROUTE_115_TM_01                                   0x3F9
#define FLAG_ITEM_ROUTE_115_MOON_BALL                               0x3FA
#define FLAG_ITEM_ROUTE_116_ETHER                                   0x3FB
#define FLAG_ITEM_ROUTE_116_REPEL                                   0x3FC
#define FLAG_ITEM_ROUTE_116_HP_UP                                   0x3FD
#define FLAG_ITEM_ROUTE_117_GREAT_BALL                              0x3FE
#define FLAG_ITEM_ROUTE_117_REVIVE                                  0x3FF
#define FLAG_ITEM_ROUTE_119_TOXIC_ORB                               0x400
#define FLAG_ITEM_ROUTE_119_SCIZORITE                               0x401
#define FLAG_ITEM_ROUTE_119_ELIXIR_1                                0x402
#define FLAG_ITEM_ROUTE_119_TM84_POISON_JAB                         0x403
#define FLAG_ITEM_ROUTE_119_RARE_CANDY                              0x404
#define FLAG_ITEM_ROUTE_119_HYPER_POTION_1                          0x405
#define FLAG_ITEM_ROUTE_120_NUGGET                                  0x406
#define FLAG_ITEM_ROUTE_120_PIDGEOTITE                              0x407
#define FLAG_ITEM_ROUTE_123_WIDE_LENS                               0x408
#define FLAG_ITEM_RUSTBORO_FLOAT_STONE                              0x409
#define FLAG_ITEM_ROUTE_127_ZINC                                    0x40A
#define FLAG_ITEM_ROUTE_127_LAPRASITE                               0x40B
#define FLAG_ITEM_ROUTE_132_RARE_CANDY                              0x40C
#define FLAG_ITEM_ROUTE_133_PEARL_STRING                            0x40D
#define FLAG_ITEM_ROUTE_133_COMET_SHARD                             0x40E
#define FLAG_ITEM_PETALBURG_CITY_MAX_REVIVE                         0x40F
#define FLAG_ITEM_PETALBURG_CITY_VENUSAURITE                        0x410
#define FLAG_ITEM_RUSTBORO_CITY_ABILITY_CAPSULE                     0x411
#define FLAG_ITEM_LILYCOVE_CITY_LIGHT_CLAY                          0x412
#define FLAG_ITEM_MOSSDEEP_CITY_NET_BALL                            0x413 // Unused
#define FLAG_ITEM_METEOR_FALLS_1F_1R_TM_23                          0x414
#define FLAG_ITEM_METEOR_FALLS_1F_1R_COMET_SHARD                    0x415
#define FLAG_ITEM_METEOR_FALLS_1F_1R_TM59_DRAGON_PULSE              0x416
#define FLAG_ITEM_METEOR_FALLS_1F_1R_PP_UP                          0x417
#define FLAG_ITEM_RUSTURF_TUNNEL_POKE_BALL                          0x418
#define FLAG_ITEM_RUSTURF_TUNNEL_SABLENITE                          0x419
#define FLAG_ITEM_GRANITE_CAVE_1F_ESCAPE_ROPE                       0x41A
#define FLAG_ITEM_GRANITE_CAVE_B1F_POKE_BALL                        0x41B
#define FLAG_ITEM_MT_PYRE_5F_LAX_INCENSE                            0x41C
#define FLAG_ITEM_GRANITE_CAVE_B2F_REPEL                            0x41D
#define FLAG_ITEM_GRANITE_CAVE_B2F_RARE_CANDY                       0x41E
#define FLAG_ITEM_PETALBURG_WOODS_X_ATTACK                          0x41F
#define FLAG_ITEM_PETALBURG_WOODS_GREAT_BALL                        0x420
#define FLAG_ITEM_ROUTE_104_FRIEND_BALL                             0x421
#define FLAG_ITEM_PETALBURG_WOODS_ETHER                             0x422
#define FLAG_ITEM_MAGMA_HIDEOUT_3F_3R_TM35_FLAMETHROWER             0x423
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_1_DAWN_STONE                   0x424
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_2_DUSK_STONE                   0x425
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_2_HEAVY_BALL                   0x426
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_3_BIG_NUGGET                   0x427
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_3_EXPERT_BELT                  0x428
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_4_ASSAULT_VEST                 0x429
#define FLAG_ITEM_ROUTE_124_YELLOW_SHARD                            0x42A
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_6_MEWTWONITE_X                 0x42B
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_7_LUCKY_EGG                    0x42C
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_8_DESTINY_KNOT                 0x42D
#define FLAG_ITEM_JAGGED_PASS_TM69_ROCK_POLISH                      0x42E
#define FLAG_ITEM_AQUA_HIDEOUT_B1F_MAX_ELIXIR                       0x42F
#define FLAG_ITEM_AQUA_HIDEOUT_B2F_NEST_BALL                        0x430
#define FLAG_ITEM_MT_PYRE_EXTERIOR_GENGARITE                        0x431
#define FLAG_ITEM_MT_PYRE_EXTERIOR_TM_48                            0x432
#define FLAG_ITEM_NEW_MAUVILLE_FAST_BALL                            0x433
#define FLAG_ITEM_NEW_MAUVILLE_DUSK_BALL                            0x434
#define FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_6_LUXURY_BALL    0x435
#define FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_4_SCANNER        0x436
#define FLAG_ITEM_SCORCHED_SLAB_TM_11                               0x437
#define FLAG_ITEM_METEOR_FALLS_B1F_2R_TM_02                         0x438
#define FLAG_ITEM_SHOAL_CAVE_ENTRANCE_BIG_PEARL                     0x439
#define FLAG_ITEM_SHOAL_CAVE_INNER_ROOM_RARE_CANDY                  0x43A
#define FLAG_ITEM_SHOAL_CAVE_STAIRS_ROOM_TM70_AURORA_VEIL           0x43B
#define FLAG_ITEM_VICTORY_ROAD_1F_MAX_ELIXIR                        0x43C
#define FLAG_ITEM_VICTORY_ROAD_1F_METAGROSSITE                      0x43D
#define FLAG_ITEM_VICTORY_ROAD_B1F_TM_29                            0x43E
#define FLAG_ITEM_VICTORY_ROAD_B1F_FULL_RESTORE                     0x43F
#define FLAG_ITEM_VICTORY_ROAD_B2F_FULL_HEAL                        0x440
#define FLAG_ITEM_MT_PYRE_6F_TM_30                                  0x441
#define FLAG_ITEM_SEAFLOOR_CAVERN_ROOM_9_TM_26                      0x442
#define FLAG_ITEM_FIERY_PATH_TM06                                   0x443 
#define FLAG_ITEM_ROUTE_124_RED_SHARD                               0x444 
#define FLAG_ITEM_ROUTE_124_BLUE_SHARD                              0x445 
#define FLAG_ITEM_SAFARI_ZONE_NORTH_WEST_TM_22                      0x446 
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_1F_LOPUNNITE                 0x447 
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_B1F_BIG_NUGGET               0x448 
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_2_B1F_LEVEL_BALL             0x449 
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_B1F_TM_13                    0x44A 
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_2_1F_REVIVE                  0x44B 
#define FLAG_ITEM_ABANDONED_SHIP_CAPTAINS_OFFICE_STORAGE_KEY        0x44C 
#define FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_3_LUCARIONITE    0x44D 
#define FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_1_TM_18          0x44E 
#define FLAG_ITEM_ROUTE_121_CARBOS                                  0x44F
#define FLAG_ITEM_ROUTE_123_MEADOW_PLATE                            0x450
#define FLAG_ITEM_ROUTE_126_GREEN_SHARD                             0x451
#define FLAG_ITEM_ROUTE_119_HYPER_POTION_2                          0x452
#define FLAG_ITEM_ROUTE_120_HYPER_POTION                            0x453
#define FLAG_ITEM_ROUTE_120_NEST_BALL                               0x454
#define FLAG_ITEM_ROUTE_123_ELIXIR                                  0x455
#define FLAG_ITEM_NEW_MAUVILLE_AMPHAROSITE                          0x456
#define FLAG_ITEM_FIERY_PATH_CHARIZARDITE_X                         0x457
#define FLAG_ITEM_SHOAL_CAVE_ICE_ROOM_TM_07                         0x458
#define FLAG_ITEM_SHOAL_CAVE_ICE_ROOM_NEVER_MELT_ICE                0x459
#define FLAG_ITEM_ROUTE_103_TM40_AERIAL_ACE                         0x45A
#define FLAG_ITEM_ROUTE_104_AUDINITE                                0x45B
#define FLAG_ITEM_MAUVILLE_CITY_X_SPEED                             0x45C
#define FLAG_ITEM_PETALBURD_WOODS_PARALYZE_HEAL                     0x45D
#define FLAG_ITEM_ROUTE_115_GREAT_BALL                              0x45E
#define FLAG_ITEM_SAFARI_ZONE_NORTH_ABSOLITE                        0x45F
#define FLAG_ITEM_MT_PYRE_3F_SUPER_REPEL                            0x460
#define FLAG_ITEM_ROUTE_118_HYPER_POTION                            0x461
#define FLAG_ITEM_NEW_MAUVILLE_FULL_HEAL                            0x462
#define FLAG_ITEM_NEW_MAUVILLE_ELECTIRIZER                          0x463
#define FLAG_ITEM_AQUA_HIDEOUT_B1F_MASTER_BALL                      0x464
#define FLAG_ITEM_SLATEPORT_CITY_ALAKAZITE                          0x465
#define FLAG_RECEIVED_GALLADITE                                     0x466
#define FLAG_ITEM_ROUTE_119_TM62_ACROBATICS                         0x467
#define FLAG_ITEM_NEW_MAUVILLE_INSIDE_TM91                          0x468
#define FLAG_ITEM_MT_PYRE_2F_ULTRA_BALL                             0x469
#define FLAG_ITEM_MT_PYRE_4F_SEA_INCENSE                            0x46A
#define FLAG_ITEM_SAFARI_ZONE_SOUTH_WEST_MAX_REVIVE                 0x46B
#define FLAG_ITEM_AQUA_HIDEOUT_B1F_SHARPEDONITE                     0x46C
#define FLAG_ITEM_ROUTE_111_MEDICHAMITE                             0x46D
#define FLAG_ITEM_ROUTE_119_NUGGET                                  0x46E
#define FLAG_ITEM_ROUTE_104_SOOTHE_BELL                             0x46F
#define FLAG_ITEM_SHOAL_CAVE_ICE_ROOM_GLALITITE                     0x470
#define FLAG_ITEM_ROUTE_103_PP_UP                                   0x471
#define FLAG_ITEM_ROUTE_124_TM85_DREAM_EATER                        0x472
#define FLAG_ITEM_ROUTE_108_STAR_PIECE                              0x473
#define FLAG_ITEM_ROUTE_109_ZOOM_LENS                               0x474
#define FLAG_ITEM_ROUTE_110_ELIXIR                                  0x475
#define FLAG_ITEM_ROUTE_111_ELIXIR                                  0x476
#define FLAG_ITEM_ROUTE_113_HYPER_POTION                            0x477
#define FLAG_ITEM_ROUTE_115_HERACRONITE                             0x478
#define FLAG_ITEM_AQUA_HIDEOUT_B1F_TM97_DARK_PULSE                  0x479
#define FLAG_ITEM_ROUTE_116_BINDING_BAND                            0x47A
#define FLAG_ITEM_ROUTE_119_ELIXIR_2                                0x47B
#define FLAG_ITEM_ROUTE_120_REVIVE                                  0x47C
#define FLAG_ITEM_ROUTE_121_REVIVE                                  0x47D
#define FLAG_ITEM_ROUTE_121_MACHAMPITE                              0x47E
#define FLAG_ITEM_MAGMA_HIDEOUT_1F_RARE_CANDY                       0x47F
#define FLAG_ITEM_ROUTE_123_PP_UP                                   0x480
#define FLAG_ITEM_ROUTE_123_TM99_DAZZLING_GLEAM                     0x481
#define FLAG_ITEM_ROUTE_125_BIG_PEARL                               0x482
#define FLAG_ITEM_ROUTE_127_RARE_CANDY                              0x483
#define FLAG_ITEM_ROUTE_132_PROTEIN                                 0x484
#define FLAG_ITEM_ROUTE_133_MAX_REVIVE                              0x485
#define FLAG_ITEM_ROUTE_134_CARBOS                                  0x486
#define FLAG_ITEM_ROUTE_134_COMET_SHARD                             0x487
#define FLAG_ITEM_ROUTE_114_PROTECTIVE_PADS                         0x488
#define FLAG_ITEM_ROUTE_115_PP_UP                                   0x489
#define FLAG_ITEM_ARTISAN_CAVE_B1F_HP_UP                            0x48A
#define FLAG_ITEM_ARTISAN_CAVE_1F_CARBOS                            0x48B
#define FLAG_ITEM_MAGMA_HIDEOUT_2F_2R_MAX_ELIXIR                    0x48C
#define FLAG_ITEM_MAGMA_HIDEOUT_2F_2R_FULL_RESTORE                  0x48D
#define FLAG_ITEM_MAGMA_HIDEOUT_3F_1R_CAMERUPTITE                   0x48E
#define FLAG_ITEM_MAGMA_HIDEOUT_3F_2R_PP_MAX                        0x48F
#define FLAG_ITEM_MAGMA_HIDEOUT_4F_MAX_REVIVE                       0x490
#define FLAG_ITEM_SAFARI_ZONE_NORTH_EAST_KANGASKHANITE              0x491
#define FLAG_ITEM_SAFARI_ZONE_SOUTH_EAST_TM53_ENERGY_BALL           0x492
#define FLAG_HIDE_RUSTBORO_HIKER                                    0x493
#define FLAG_WEATHER_INSTITUTE_ROCKS                                0x494
#define FLAG_ITEM_TRICK_HOUSE_TERRAIN_EXTENDER                      0x495
#define FLAG_HIDE_LAVARIDGE_POKECENTER_LUCY                         0x496
#define FLAG_HIDE_FORTREE_POKECENTER_SPENSER                        0x497
#define FLAG_DEFEATED_SLATEPORT_GRETA                               0x498
#define FLAG_ITEM_DEWFORD_MEADOW_TM95                               0x499
#define FLAG_ITEM_DEWFORD_MEADOW_RING_TARGET                        0x49A
#define FLAG_ITEM_DEWFORD_MANOR_TM100                               0x49B
#define FLAG_ITEM_DEWFORD_MANOR_BANETTITE                           0x49C
#define FLAG_WEATHER_INSTITUTE_BOTTLE_CAPS                          0x49D
#define FLAG_HIDE_RUSTBORO_ROXANNE                                  0x49E
#define FLAG_ITEM_LILYCOVE_CITY_ALTARIANITE                         0x49F
#define FLAG_DEFEATED_ARTICUNO                                      0x4A0
#define FLAG_DEFEATED_ZAPDOS                                        0x4A1
#define FLAG_DEFEATED_MOLTRES                                       0x4A2
#define FLAG_DEFEATED_MEWTWO                                        0x4A3
#define FLAG_DEFEATED_ENTEI                                         0x4A4
#define FLAG_DEFEATED_RAIKOU                                        0x4A5
#define FLAG_DEFEATED_SUICUNE                                       0x4A6
#define FLAG_DEFEATED_CELEBI                                        0x4A7
#define FLAG_DEFEATED_JIRACHI                                       0x4A8
#define FLAG_DEFEATED_UXIE                                          0x4A9
#define FLAG_DEFEATED_MESPRIT                                       0x4AA
#define FLAG_DEFEATED_AZELF                                         0x4AB
#define FLAG_DEFEATED_DIALGA                                        0x4AC
#define FLAG_DEFEATED_PALKIA                                        0x4AD
#define FLAG_DEFEATED_HEATRAN                                       0x4AE
#define FLAG_DEFEATED_REGIGIGAS                                     0x4AF
#define FLAG_DEFEATED_GIRATINA                                      0x4B0
#define FLAG_DEFEATED_CRESSELIA                                     0x4B1
#define FLAG_RECEIVED_MANAPHY                                       0x4B2
#define FLAG_DEFEATED_DARKRAI                                       0x4B3
#define FLAG_DEFEATED_SHAYMIN                                       0x4B4
#define FLAG_DEFEATED_ARCEUS                                        0x4B5
#define FLAG_DEFEATED_VICTINI                                       0x4B6
#define FLAG_DEFEATED_COBALION                                      0x4B7
#define FLAG_DEFEATED_VIRIZION                                      0x4B8
#define FLAG_DEFEATED_TERRAKION                                     0x4B9
#define FLAG_DEFEATED_TORNADUS                                      0x4BA
#define FLAG_DEFEATED_THUNDURUS                                     0x4BB
#define FLAG_DEFEATED_RESHIRAM                                      0x4BC
#define FLAG_DEFEATED_ZEKROM                                        0x4BD
#define FLAG_DEFEATED_LANDORUS                                      0x4BE
#define FLAG_DEFEATED_KYUREM                                        0x4BF
#define FLAG_DEFEATED_KELDEO                                        0x4C0
#define FLAG_RECEIVED_MELOETTA                                      0x4C1
#define FLAG_DEFEATED_GENESECT                                      0x4C2
#define FLAG_DEFEATED_XERNEAS                                       0x4C3
#define FLAG_DEFEATED_YVELTAL                                       0x4C4
#define FLAG_DEFEATED_ZYGARDE                                       0x4C5
#define FLAG_DEFEATED_DIANCIE                                       0x4C6
#define FLAG_DEFEATED_HOOPA                                         0x4C7
#define FLAG_DEFEATED_VOLCANION                                     0x4C8
#define FLAG_RECEIVED_TYPE_NULL                                     0x4C9
#define FLAG_DEFEATED_TAPU_KOKO                                     0x4CA
#define FLAG_DEFEATED_TAPU_LELE                                     0x4CB
#define FLAG_DEFEATED_TAPU_BULU                                     0x4CC
#define FLAG_DEFEATED_TAPU_FINI                                     0x4CD
#define FLAG_RECEIVED_COSMOG                                        0x4CE
#define FLAG_DEFEATED_BIG_COSMOG                                    0x4CF
#define FLAG_DEFEATED_NECROZMA                                      0x4D0
#define FLAG_DEFEATED_MARSHADOW                                     0x4D1
#define FLAG_DEFEATED_ZERAORA                                       0x4D2
#define FLAG_DEFEATED_ZACIAN                                        0x4D3
#define FLAG_DEFEATED_ZAMAZENTA                                     0x4D4
#define FLAG_DEFEATED_ETERNATUS                                     0x4D5
#define FLAG_RECEIVED_KUBFU_1                                       0x4D6
#define FLAG_RECEIVED_KUBFU_2                                       0x4D7
#define FLAG_DEFEATED_ZARUDE                                        0x4D8
#define FLAG_DEFEATED_REGIELEKI                                     0x4D9
#define FLAG_DEFEATED_REGIDRAGO                                     0x4DA
#define FLAG_DEFEATED_GLASTRIER                                     0x4DB
#define FLAG_DEFEATED_SPECTRIER                                     0x4DC
#define FLAG_DEFEATED_CALYREX                                       0x4DD
#define FLAG_DEFEATED_ARTICUNO_GALAR                                0x4DE
#define FLAG_DEFEATED_ZAPDOS_GALAR                                  0x4DF
#define FLAG_DEFEATED_MOLTRES_GALAR                                 0x4E0
#define FLAG_TM21_FRUSTRATION                                       0x4E1
#define FLAG_ITEM_MAGMA_HIDEOUT_2F_2R_MAGMA_STONE                   0x4E2
#define FLAG_SANDSTREWN_RUINS_ODD_KEYSTONE                          0x4E3
#define FLAG_RECEIVED_AUDINO                                        0x4E4
#define FLAG_HIDE_ASHEN_WOODS_CHANSEY                               0x4E5
#define FLAG_HIDE_ASHEN_WOODS_POKE_BALL                             0x4E6
#define FLAG_EVERGRANDE_MEWTWONITEY                                 0x4E7
#define FLAG_ALTERING_CAVE_MASTER_BALL_1                            0x4E8
#define FLAG_ALTERING_CAVE_COMET_SHARD                              0x4E9
#define FLAG_ALTERING_CAVE_MASTER_BALL_2                            0x4EA
#define FLAG_DEFEATED_LEAF                                          0x4EB
#define FLAG_LENT_NURSE_SURF                                        0x4EC
#define FLAG_RAN_FROM_TRAINER                                       0x4ED // Unused Flag
#define FLAG_HANDED_OVER_METEORITE                                  0x4EE
#define FLAG_OBTAINED_SHUCKLENITE                                   0x4EF

#define FLAG_DEFEATED_RUSTBORO_GYM                                  0x4F0
#define FLAG_DEFEATED_DEWFORD_GYM                                   0x4F1
#define FLAG_DEFEATED_MAUVILLE_GYM                                  0x4F2
#define FLAG_DEFEATED_LAVARIDGE_GYM                                 0x4F3
#define FLAG_DEFEATED_PETALBURG_GYM                                 0x4F4
#define FLAG_DEFEATED_FORTREE_GYM                                   0x4F5
#define FLAG_DEFEATED_MOSSDEEP_GYM                                  0x4F6
#define FLAG_DEFEATED_SOOTOPOLIS_GYM                                0x4F7
#define FLAG_DEFEATED_METEOR_FALLS_STEVEN                           0x4F8 // Unused Flag

#define FLAG_TRAINER_CALVIN_E4                                      0x4F9 // Trainer Flag
#define FLAG_GOT_LEGENDARY_NPC_ITEMS                                0x4FA

#define FLAG_DEFEATED_ELITE_4_SIDNEY                                0x4FB
#define FLAG_DEFEATED_ELITE_4_PHOEBE                                0x4FC
#define FLAG_DEFEATED_ELITE_4_GLACIA                                0x4FD
#define FLAG_DEFEATED_ELITE_4_DRAKE                                 0x4FE

#define FLAG_OBTAINED_LAPRASITE_X                                   0x4FF //

// Trainer Flags
// Trainer flags occupy 0x500 - 0x85F, the last 9 of which are unused
// See constants/opponents.h. The values there + FLAG_TRAINER_FLAG_START are the flag IDs

#define TRAINER_FLAGS_START                                         0x500
#define TRAINER_FLAGS_END                                           (TRAINER_FLAGS_START + MAX_OLD_TRAINERS_COUNT - 1) // 0x85F

// System Flags

#define SYSTEM_FLAGS                                   (TRAINER_FLAGS_END + 1) // 0x860

#define FLAG_SYS_POKEMON_GET                         (SYSTEM_FLAGS + 0x0) // FLAG_0x860
#define FLAG_SYS_POKEDEX_GET                         (SYSTEM_FLAGS + 0x1)
#define FLAG_SYS_POKENAV_GET                         (SYSTEM_FLAGS + 0x2)
#define FLAG_REMOVE_LEGENDARY_NPC                    (SYSTEM_FLAGS + 0x3)
#define FLAG_SYS_GAME_CLEAR                          (SYSTEM_FLAGS + 0x4)
#define FLAG_SYS_CHAT_USED                           (SYSTEM_FLAGS + 0x5)
#define FLAG_SYS_HIPSTER_MEET                        (SYSTEM_FLAGS + 0x6)

// Badges
#define FLAG_BADGE01_GET                             (SYSTEM_FLAGS + 0x7)
#define FLAG_BADGE02_GET                             (SYSTEM_FLAGS + 0x8)
#define FLAG_BADGE03_GET                             (SYSTEM_FLAGS + 0x9)
#define FLAG_BADGE04_GET                             (SYSTEM_FLAGS + 0xA)
#define FLAG_BADGE05_GET                             (SYSTEM_FLAGS + 0xB)
#define FLAG_BADGE06_GET                             (SYSTEM_FLAGS + 0xC)
#define FLAG_BADGE07_GET                             (SYSTEM_FLAGS + 0xD)
#define FLAG_BADGE08_GET                             (SYSTEM_FLAGS + 0xE)
#define NUM_BADGES                                   (1 + FLAG_BADGE08_GET - FLAG_BADGE01_GET)

// Towns and Cities
#define FLAG_VISITED_LITTLEROOT_TOWN                (SYSTEM_FLAGS + 0xF)
#define FLAG_VISITED_OLDALE_TOWN                    (SYSTEM_FLAGS + 0x10)
#define FLAG_VISITED_DEWFORD_TOWN                   (SYSTEM_FLAGS + 0x11)
#define FLAG_VISITED_LAVARIDGE_TOWN                 (SYSTEM_FLAGS + 0x12)
#define FLAG_VISITED_FALLARBOR_TOWN                 (SYSTEM_FLAGS + 0x13)
#define FLAG_VISITED_VERDANTURF_TOWN                (SYSTEM_FLAGS + 0x14)
#define FLAG_VISITED_PACIFIDLOG_TOWN                (SYSTEM_FLAGS + 0x15)
#define FLAG_VISITED_PETALBURG_CITY                 (SYSTEM_FLAGS + 0x16)
#define FLAG_VISITED_SLATEPORT_CITY                 (SYSTEM_FLAGS + 0x17)
#define FLAG_VISITED_MAUVILLE_CITY                  (SYSTEM_FLAGS + 0x18)
#define FLAG_VISITED_RUSTBORO_CITY                  (SYSTEM_FLAGS + 0x19)
#define FLAG_VISITED_FORTREE_CITY                   (SYSTEM_FLAGS + 0x1A)
#define FLAG_VISITED_LILYCOVE_CITY                  (SYSTEM_FLAGS + 0x1B)
#define FLAG_VISITED_MOSSDEEP_CITY                  (SYSTEM_FLAGS + 0x1C)
#define FLAG_VISITED_SOOTOPOLIS_CITY                (SYSTEM_FLAGS + 0x1D)
#define FLAG_VISITED_EVER_GRANDE_CITY               (SYSTEM_FLAGS + 0x1E)

#define FLAG_IS_CHAMPION                            (SYSTEM_FLAGS + 0x1F) // Seems to be related to linking.
#define FLAG_NURSE_UNION_ROOM_REMINDER              (SYSTEM_FLAGS + 0x20)

#define FLAG_SYS_DEXNAV_SEARCH                      (SYSTEM_FLAGS + 0x21)
#define FLAG_SHINY_CREATION                         (SYSTEM_FLAGS + 0x22) // force creation of a shiny mon
#define FLAG_SYS_DETECTOR_MODE                      (SYSTEM_FLAGS + 0x23) // allow player to find hidden mons
#define FLAG_SYS_DEXNAV_GET                         (SYSTEM_FLAGS + 0x24) // dexnav shows in start menu
#define FLAG_USED_CANDY_BOX                         (SYSTEM_FLAGS + 0x25)
#define FLAG_TRAINER_NEW_TEST                       (SYSTEM_FLAGS + 0x26) // New trainer example
#define FLAG_UPDATED_MEGA_STONE_POCKET              (SYSTEM_FLAGS + 0x27)

#define FLAG_SYS_USE_FLASH                          (SYSTEM_FLAGS + 0x28)
#define FLAG_SYS_USE_STRENGTH                       (SYSTEM_FLAGS + 0x29)
#define FLAG_SYS_WEATHER_CTRL                       (SYSTEM_FLAGS + 0x2A)
#define FLAG_SYS_CYCLING_ROAD                       (SYSTEM_FLAGS + 0x2B)
#define FLAG_SYS_SAFARI_MODE                        (SYSTEM_FLAGS + 0x2C)
#define FLAG_SYS_CRUISE_MODE                        (SYSTEM_FLAGS + 0x2D)

#define FLAG_SYS_RECEIVED_KEYSTONE                  (SYSTEM_FLAGS + 0x2E) // Must be set to enable Mega Evolution
#define FLAG_SYS_INVERSE_BATTLE                     (SYSTEM_FLAGS + 0x2F) // Set for inverse battles

#define FLAG_SYS_TV_HOME                            (SYSTEM_FLAGS + 0x30)
#define FLAG_SYS_TV_WATCH                           (SYSTEM_FLAGS + 0x31)
#define FLAG_SYS_TV_START                           (SYSTEM_FLAGS + 0x32)
#define FLAG_SYS_CHANGED_DEWFORD_TREND              (SYSTEM_FLAGS + 0x33)
#define FLAG_SYS_MIX_RECORD                         (SYSTEM_FLAGS + 0x34)
#define FLAG_SYS_CLOCK_SET                          (SYSTEM_FLAGS + 0x35)
#define FLAG_SYS_NATIONAL_DEX                       (SYSTEM_FLAGS + 0x36)
#define FLAG_SYS_CAVE_SHIP                          (SYSTEM_FLAGS + 0x37) // Unused Flag, leftover from R/S debug, presumably used by Emerald's debug too
#define FLAG_SYS_CAVE_WONDER                        (SYSTEM_FLAGS + 0x38) // Unused Flag, same as above
#define FLAG_SYS_CAVE_BATTLE                        (SYSTEM_FLAGS + 0x39) // Unused Flag, same as above
#define FLAG_SYS_SHOAL_TIDE                         (SYSTEM_FLAGS + 0x3A)
#define FLAG_SYS_RIBBON_GET                         (SYSTEM_FLAGS + 0x3B)

#define FLAG_LANDMARK_FLOWER_SHOP                   (SYSTEM_FLAGS + 0x3C)
#define FLAG_LANDMARK_MR_BRINEY_HOUSE               (SYSTEM_FLAGS + 0x3D)
#define FLAG_LANDMARK_ABANDONED_SHIP                (SYSTEM_FLAGS + 0x3E)
#define FLAG_LANDMARK_SEASHORE_HOUSE                (SYSTEM_FLAGS + 0x3F)
#define FLAG_LANDMARK_NEW_MAUVILLE                  (SYSTEM_FLAGS + 0x40)
#define FLAG_LANDMARK_OLD_LADY_REST_SHOP            (SYSTEM_FLAGS + 0x41)
#define FLAG_LANDMARK_TRICK_HOUSE                   (SYSTEM_FLAGS + 0x42)
#define FLAG_LANDMARK_WINSTRATE_FAMILY              (SYSTEM_FLAGS + 0x43)
#define FLAG_LANDMARK_GLASS_WORKSHOP                (SYSTEM_FLAGS + 0x44)
#define FLAG_LANDMARK_LANETTES_HOUSE                (SYSTEM_FLAGS + 0x45)
#define FLAG_LANDMARK_POKEMON_DAYCARE               (SYSTEM_FLAGS + 0x46)
#define FLAG_LANDMARK_SEAFLOOR_CAVERN               (SYSTEM_FLAGS + 0x47)
#define FLAG_LANDMARK_BATTLE_FRONTIER               (SYSTEM_FLAGS + 0x48)
#define FLAG_LANDMARK_SOUTHERN_ISLAND               (SYSTEM_FLAGS + 0x49)
#define FLAG_LANDMARK_FIERY_PATH                    (SYSTEM_FLAGS + 0x4A)

#define FLAG_SYS_PC_LANETTE                         (SYSTEM_FLAGS + 0x4B)
#define FLAG_SYS_MYSTERY_EVENT_ENABLE               (SYSTEM_FLAGS + 0x4C)
#define FLAG_SYS_ENC_UP_ITEM                        (SYSTEM_FLAGS + 0x4D)
#define FLAG_SYS_ENC_DOWN_ITEM                      (SYSTEM_FLAGS + 0x4E)
#define FLAG_SYS_BRAILLE_DIG                        (SYSTEM_FLAGS + 0x4F)
#define FLAG_SYS_REGIROCK_PUZZLE_COMPLETED          (SYSTEM_FLAGS + 0x50)
#define FLAG_SYS_BRAILLE_REGICE_COMPLETED           (SYSTEM_FLAGS + 0x51)
#define FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED         (SYSTEM_FLAGS + 0x52)
#define FLAG_ENABLE_SHIP_SOUTHERN_ISLAND            (SYSTEM_FLAGS + 0x53)

#define FLAG_LANDMARK_POKEMON_LEAGUE                (SYSTEM_FLAGS + 0x54)
#define FLAG_LANDMARK_ISLAND_CAVE                   (SYSTEM_FLAGS + 0x55)
#define FLAG_LANDMARK_DESERT_RUINS                  (SYSTEM_FLAGS + 0x56)
#define FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE          (SYSTEM_FLAGS + 0x57)
#define FLAG_LANDMARK_SCORCHED_SLAB                 (SYSTEM_FLAGS + 0x58)
#define FLAG_LANDMARK_ANCIENT_TOMB                  (SYSTEM_FLAGS + 0x59)
#define FLAG_LANDMARK_TUNNELERS_REST_HOUSE          (SYSTEM_FLAGS + 0x5A)
#define FLAG_LANDMARK_HUNTERS_HOUSE                 (SYSTEM_FLAGS + 0x5B)
#define FLAG_LANDMARK_SEALED_CHAMBER                (SYSTEM_FLAGS + 0x5C)

#define FLAG_SYS_TV_LATIAS_LATIOS                   (SYSTEM_FLAGS + 0x5D)

#define FLAG_LANDMARK_SKY_PILLAR                    (SYSTEM_FLAGS + 0x5E)

#define FLAG_SYS_SHOAL_ITEM                         (SYSTEM_FLAGS + 0x5F)
#define FLAG_SYS_B_DASH                             (SYSTEM_FLAGS + 0x60) // RECEIVED Running Shoes
#define FLAG_SYS_CTRL_OBJ_DELETE                    (SYSTEM_FLAGS + 0x61)
#define FLAG_SYS_RESET_RTC_ENABLE                   (SYSTEM_FLAGS + 0x62)

#define FLAG_LANDMARK_BERRY_MASTERS_HOUSE           (SYSTEM_FLAGS + 0x63)

#define FLAG_SYS_TOWER_SILVER                       (SYSTEM_FLAGS + 0x64)
#define FLAG_SYS_TOWER_GOLD                         (SYSTEM_FLAGS + 0x65)
#define FLAG_SYS_DOME_SILVER                        (SYSTEM_FLAGS + 0x66)
#define FLAG_SYS_DOME_GOLD                          (SYSTEM_FLAGS + 0x67)
#define FLAG_SYS_PALACE_SILVER                      (SYSTEM_FLAGS + 0x68)
#define FLAG_SYS_PALACE_GOLD                        (SYSTEM_FLAGS + 0x69)
#define FLAG_SYS_ARENA_SILVER                       (SYSTEM_FLAGS + 0x6A)
#define FLAG_SYS_ARENA_GOLD                         (SYSTEM_FLAGS + 0x6B)
#define FLAG_SYS_FACTORY_SILVER                     (SYSTEM_FLAGS + 0x6C)
#define FLAG_SYS_FACTORY_GOLD                       (SYSTEM_FLAGS + 0x6D)
#define FLAG_SYS_PIKE_SILVER                        (SYSTEM_FLAGS + 0x6E)
#define FLAG_SYS_PIKE_GOLD                          (SYSTEM_FLAGS + 0x6F)
#define FLAG_SYS_PYRAMID_SILVER                     (SYSTEM_FLAGS + 0x70)
#define FLAG_SYS_PYRAMID_GOLD                       (SYSTEM_FLAGS + 0x71)
#define FLAG_SYS_FRONTIER_PASS                      (SYSTEM_FLAGS + 0x72)

#define FLAG_MAP_SCRIPT_CHECKED_DEOXYS              (SYSTEM_FLAGS + 0x73)
#define FLAG_DEOXYS_ROCK_COMPLETE                   (SYSTEM_FLAGS + 0x74)
#define FLAG_ENABLE_SHIP_BIRTH_ISLAND               (SYSTEM_FLAGS + 0x75)
#define FLAG_ENABLE_SHIP_FARAWAY_ISLAND             (SYSTEM_FLAGS + 0x76)

#define FLAG_SHOWN_BOX_WAS_FULL_MESSAGE             (SYSTEM_FLAGS + 0x77)

#define FLAG_ARRIVED_ON_FARAWAY_ISLAND              (SYSTEM_FLAGS + 0x78)
#define FLAG_ARRIVED_AT_MARINE_CAVE_EMERGE_SPOT     (SYSTEM_FLAGS + 0x79)
#define FLAG_ARRIVED_AT_TERRA_CAVE_ENTRANCE         (SYSTEM_FLAGS + 0x7A)

#define FLAG_SYS_MYSTERY_GIFT_ENABLE                (SYSTEM_FLAGS + 0x7B)

#define FLAG_ENTERED_MIRAGE_TOWER                   (SYSTEM_FLAGS + 0x7C) // Appears to be written but never read?
#define FLAG_LANDMARK_ALTERING_CAVE                 (SYSTEM_FLAGS + 0x7D)
#define FLAG_LANDMARK_DESERT_UNDERPASS              (SYSTEM_FLAGS + 0x7E)
#define FLAG_LANDMARK_ARTISAN_CAVE                  (SYSTEM_FLAGS + 0x7F)
#define FLAG_ENABLE_SHIP_NAVEL_ROCK                 (SYSTEM_FLAGS + 0x80)
#define FLAG_ARRIVED_AT_NAVEL_ROCK                  (SYSTEM_FLAGS + 0x81)
#define FLAG_LANDMARK_TRAINER_HILL                  (SYSTEM_FLAGS + 0x82)

#define FLAG_DEBUG_GODMODE                          (SYSTEM_FLAGS + 0x83) // Debug

#define FLAG_RECEIVED_POKEDEX_FROM_BIRCH            (SYSTEM_FLAGS + 0x84)

#define FLAG_LANDMARK_DEWFORD_MEADOW                (SYSTEM_FLAGS + 0x85)
#define FLAG_LANDMARK_DEWFORD_MANOR                 (SYSTEM_FLAGS + 0x86)
#define FLAG_LANDMARK_VERDANT_MEADOW                (SYSTEM_FLAGS + 0x87)
#define FLAG_LANDMARK_EMBER_PATH                    (SYSTEM_FLAGS + 0x88)
#define FLAG_LANDMARK_ASHEN_WOODS                   (SYSTEM_FLAGS + 0x89)
#define FLAG_LANDMARK_SANDSTREWN_RUINS              (SYSTEM_FLAGS + 0x8A)
#define FLAG_TRAINER_BANEFUL_PETALBURG_WOODS        (SYSTEM_FLAGS + 0x8B) // Primal Cascoon battle
#define FLAG_LAST_MOVE_SECONDARY_EFFECT_ACTIVATED   (SYSTEM_FLAGS + 0x8C)
#define FLAG_TRAINER_YDA_MTPYRE                     (SYSTEM_FLAGS + 0x8D) //
#define FLAG_UNUSED_0x8EE                           (SYSTEM_FLAGS + 0x8E) // Unused Flag
#define FLAG_UNUSED_0x8EF                           (SYSTEM_FLAGS + 0x8F) // Unused Flag
#define FLAG_UNUSED_0x8F0                           (SYSTEM_FLAGS + 0x90) // Unused Flag
#define FLAG_UNUSED_0x8F1                           (SYSTEM_FLAGS + 0x91) // Unused Flag
#define FLAG_UNUSED_0x8F2                           (SYSTEM_FLAGS + 0x92) // Unused Flag
#define FLAG_UNUSED_0x8F3                           (SYSTEM_FLAGS + 0x93) // Unused Flag
#define FLAG_UNUSED_0x8F4                           (SYSTEM_FLAGS + 0x94) // Unused Flag
#define FLAG_UNUSED_0x8F5                           (SYSTEM_FLAGS + 0x95) // Unused Flag
#define FLAG_UNUSED_0x8F6                           (SYSTEM_FLAGS + 0x96) // Unused Flag
#define FLAG_UNUSED_0x8F7                           (SYSTEM_FLAGS + 0x97) // Unused Flag
#define FLAG_UNUSED_0x8F8                           (SYSTEM_FLAGS + 0x98) // Unused Flag
#define FLAG_UNUSED_0x8F9                           (SYSTEM_FLAGS + 0x99) // Unused Flag
#define FLAG_UNUSED_0x8FA                           (SYSTEM_FLAGS + 0x9A) // Unused Flag
#define FLAG_UNUSED_0x8FB                           (SYSTEM_FLAGS + 0x9B) // Unused Flag
#define FLAG_UNUSED_0x8FC                           (SYSTEM_FLAGS + 0x9C) // Unused Flag
#define FLAG_UNUSED_0x8FD                           (SYSTEM_FLAGS + 0x9D) // Unused Flag
#define FLAG_UNUSED_0x8FE                           (SYSTEM_FLAGS + 0x9E) // Unused Flag
#define FLAG_UNUSED_0x8FF                           (SYSTEM_FLAGS + 0x9F) // Unused Flag
#define FLAG_UNUSED_0x900                           (SYSTEM_FLAGS + 0xA0) // Unused Flag
#define FLAG_UNUSED_0x901                           (SYSTEM_FLAGS + 0xA1) // Unused Flag
#define FLAG_UNUSED_0x902                           (SYSTEM_FLAGS + 0xA2) // Unused Flag
#define FLAG_UNUSED_0x903                           (SYSTEM_FLAGS + 0xA3) // Unused Flag
#define FLAG_UNUSED_0x904                           (SYSTEM_FLAGS + 0xA4) // Unused Flag
#define FLAG_UNUSED_0x905                           (SYSTEM_FLAGS + 0xA5) // Unused Flag
#define FLAG_UNUSED_0x906                           (SYSTEM_FLAGS + 0xA6) // Unused Flag
#define FLAG_UNUSED_0x907                           (SYSTEM_FLAGS + 0xA7) // Unused Flag
#define FLAG_UNUSED_0x908                           (SYSTEM_FLAGS + 0xA8) // Unused Flag
#define FLAG_UNUSED_0x909                           (SYSTEM_FLAGS + 0xA9) // Unused Flag
#define FLAG_UNUSED_0x90A                           (SYSTEM_FLAGS + 0xAA) // Unused Flag
#define FLAG_UNUSED_0x90B                           (SYSTEM_FLAGS + 0xAB) // Unused Flag
#define FLAG_UNUSED_0x90C                           (SYSTEM_FLAGS + 0xAC) // Unused Flag
#define FLAG_UNUSED_0x90D                           (SYSTEM_FLAGS + 0xAD) // Unused Flag
#define FLAG_UNUSED_0x90E                           (SYSTEM_FLAGS + 0xAE) // Unused Flag
#define FLAG_UNUSED_0x90F                           (SYSTEM_FLAGS + 0xAF) // Unused Flag
#define FLAG_UNUSED_0x910                           (SYSTEM_FLAGS + 0xB0) // Unused Flag
#define FLAG_UNUSED_0x911                           (SYSTEM_FLAGS + 0xB1) // Unused Flag
#define FLAG_UNUSED_0x912                           (SYSTEM_FLAGS + 0xB2) // Unused Flag
#define FLAG_UNUSED_0x913                           (SYSTEM_FLAGS + 0xB3) // Unused Flag
#define FLAG_UNUSED_0x914                           (SYSTEM_FLAGS + 0xB4) // Unused Flag
#define FLAG_UNUSED_0x915                           (SYSTEM_FLAGS + 0xB5) // Unused Flag
#define FLAG_UNUSED_0x916                           (SYSTEM_FLAGS + 0xB6) // Unused Flag
#define FLAG_UNUSED_0x917                           (SYSTEM_FLAGS + 0xB7) // Unused Flag
#define FLAG_UNUSED_0x918                           (SYSTEM_FLAGS + 0xB8) // Unused Flag
#define FLAG_UNUSED_0x919                           (SYSTEM_FLAGS + 0xB9) // Unused Flag
#define FLAG_UNUSED_0x91A                           (SYSTEM_FLAGS + 0xBA) // Unused Flag
#define FLAG_UNUSED_0x91B                           (SYSTEM_FLAGS + 0xBB) // Unused Flag
#define FLAG_UNUSED_0x91C                           (SYSTEM_FLAGS + 0xBC) // Unused Flag
#define FLAG_UNUSED_0x91D                           (SYSTEM_FLAGS + 0xBD) // Unused Flag
#define FLAG_UNUSED_0x91E                           (SYSTEM_FLAGS + 0xBE) // Unused Flag
#define FLAG_UNUSED_0x91F                           (SYSTEM_FLAGS + 0xBF) // Unused Flag

// Daily Flags
// These flags are cleared once per day
// The start and end are byte-aligned because the flags are cleared in byte increments
#define DAILY_FLAGS_START                           (FLAG_UNUSED_0x91F + (8 - FLAG_UNUSED_0x91F % 8))
#define FLAG_DAILY_REMATCH_STEVEN                   (DAILY_FLAGS_START + 0x0)
#define FLAG_DAILY_CONTEST_LOBBY_RECEIVED_BERRY     (DAILY_FLAGS_START + 0x1)
#define FLAG_DAILY_SECRET_BASE                      (DAILY_FLAGS_START + 0x2)
#define FLAG_DAILY_REMATCH_BUFFEL                   (DAILY_FLAGS_START + 0x3)
#define FLAG_DAILY_REMATCH_RIVAL                    (DAILY_FLAGS_START + 0x4)
#define FLAG_UNUSED_0x925                           (DAILY_FLAGS_START + 0x5)  // Unused Flag
#define FLAG_UNUSED_0x926                           (DAILY_FLAGS_START + 0x6)  // Unused Flag
#define FLAG_UNUSED_0x927                           (DAILY_FLAGS_START + 0x7)  // Unused Flag
#define FLAG_UNUSED_0x928                           (DAILY_FLAGS_START + 0x8)  // Unused Flag
#define FLAG_UNUSED_0x929                           (DAILY_FLAGS_START + 0x9)  // Unused Flag
#define FLAG_DAILY_PICKED_LOTO_TICKET               (DAILY_FLAGS_START + 0xA)
#define FLAG_DAILY_ROUTE_114_RECEIVED_BERRY         (DAILY_FLAGS_START + 0xB)
#define FLAG_DAILY_ROUTE_111_RECEIVED_BERRY         (DAILY_FLAGS_START + 0xC)
#define FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY      (DAILY_FLAGS_START + 0xD)
#define FLAG_DAILY_ROUTE_120_RECEIVED_BERRY         (DAILY_FLAGS_START + 0xE)
#define FLAG_DAILY_LILYCOVE_RECEIVED_BERRY          (DAILY_FLAGS_START + 0xF)
#define FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY       (DAILY_FLAGS_START + 0x10)
#define FLAG_DAILY_BERRY_MASTERS_WIFE               (DAILY_FLAGS_START + 0x11)
#define FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY        (DAILY_FLAGS_START + 0x12)
#define FLAG_DAILY_REMATCH_CYNTHIA                  (DAILY_FLAGS_START + 0x13)
#define FLAG_DAILY_APPRENTICE_LEAVES                (DAILY_FLAGS_START + 0x14)
#define FLAG_DAILY_RECEIVED_DAYCARE_EGG             (DAILY_FLAGS_START + 0x15)
#define FLAG_DAILY_REMATCH_ROXANNE                  (DAILY_FLAGS_START + 0x16)
#define FLAG_DAILY_REMATCH_BRAWLY                   (DAILY_FLAGS_START + 0x17)
#define FLAG_DAILY_REMATCH_WATTSON                  (DAILY_FLAGS_START + 0x18)
#define FLAG_DAILY_REMATCH_FLANNERY                 (DAILY_FLAGS_START + 0x19)
#define FLAG_DAILY_REMATCH_NORMAN                   (DAILY_FLAGS_START + 0x1A)
#define FLAG_DAILY_REMATCH_WINONA                   (DAILY_FLAGS_START + 0x1B)
#define FLAG_DAILY_REMATCH_TATE_AND_LIZA            (DAILY_FLAGS_START + 0x1C)
#define FLAG_DAILY_REMATCH_JUAN                     (DAILY_FLAGS_START + 0x1D)
#define FLAG_UNUSED_0x938                           (DAILY_FLAGS_START + 0x1E) // Unused Flag
#define FLAG_UNUSED_0x939                           (DAILY_FLAGS_START + 0x1F) // Unused Flag
#define FLAG_UNUSED_0x940                           (DAILY_FLAGS_START + 0x20) // Unused Flag
#define FLAG_UNUSED_0x941                           (DAILY_FLAGS_START + 0x21) // Unused Flag
#define FLAG_UNUSED_0x942                           (DAILY_FLAGS_START + 0x22) // Unused Flag
#define FLAG_UNUSED_0x943                           (DAILY_FLAGS_START + 0x23) // Unused Flag
#define FLAG_UNUSED_0x944                           (DAILY_FLAGS_START + 0x24) // Unused Flag
#define FLAG_UNUSED_0x945                           (DAILY_FLAGS_START + 0x25) // Unused Flag
#define FLAG_UNUSED_0x946                           (DAILY_FLAGS_START + 0x26) // Unused Flag
#define FLAG_UNUSED_0x947                           (DAILY_FLAGS_START + 0x27) // Unused Flag
#define FLAG_UNUSED_0x948                           (DAILY_FLAGS_START + 0x28) // Unused Flag
#define FLAG_UNUSED_0x949                           (DAILY_FLAGS_START + 0x29) // Unused Flag
#define FLAG_UNUSED_0x94A                           (DAILY_FLAGS_START + 0x2A) // Unused Flag
#define FLAG_UNUSED_0x94B                           (DAILY_FLAGS_START + 0x2B) // Unused Flag
#define FLAG_UNUSED_0x94C                           (DAILY_FLAGS_START + 0x2C) // Unused Flag
#define FLAG_UNUSED_0x94D                           (DAILY_FLAGS_START + 0x2D) // Unused Flag
#define FLAG_UNUSED_0x94E                           (DAILY_FLAGS_START + 0x2E) // Unused Flag
#define FLAG_UNUSED_0x94F                           (DAILY_FLAGS_START + 0x2F) // Unused Flag
#define FLAG_UNUSED_0x950                           (DAILY_FLAGS_START + 0x30) // Unused Flag
#define FLAG_UNUSED_0x951                           (DAILY_FLAGS_START + 0x31) // Unused Flag
#define FLAG_UNUSED_0x952                           (DAILY_FLAGS_START + 0x32) // Unused Flag
#define FLAG_UNUSED_0x953                           (DAILY_FLAGS_START + 0x33) // Unused Flag
#define FLAG_UNUSED_0x954                           (DAILY_FLAGS_START + 0x34) // Unused Flag
#define FLAG_UNUSED_0x955                           (DAILY_FLAGS_START + 0x35) // Unused Flag
#define FLAG_UNUSED_0x956                           (DAILY_FLAGS_START + 0x36) // Unused Flag
#define FLAG_UNUSED_0x957                           (DAILY_FLAGS_START + 0x37) // Unused Flag
#define FLAG_UNUSED_0x958                           (DAILY_FLAGS_START + 0x38) // Unused Flag
#define FLAG_UNUSED_0x959                           (DAILY_FLAGS_START + 0x39) // Unused Flag
#define FLAG_UNUSED_0x95A                           (DAILY_FLAGS_START + 0x3A) // Unused Flag
#define FLAG_UNUSED_0x95B                           (DAILY_FLAGS_START + 0x3B) // Unused Flag
#define FLAG_UNUSED_0x95C                           (DAILY_FLAGS_START + 0x3C) // Unused Flag
#define FLAG_UNUSED_0x95D                           (DAILY_FLAGS_START + 0x3D) // Unused Flag
#define FLAG_UNUSED_0x95E                           (DAILY_FLAGS_START + 0x3E) // Unused Flag
#define FLAG_UNUSED_0x95F                           (DAILY_FLAGS_START + 0x3F) // Unused Flag
#define DAILY_FLAGS_END                             (FLAG_UNUSED_0x95F + (7 - FLAG_UNUSED_0x95F % 8))

#define FLAGS_COUNT (DAILY_FLAGS_END + 1) * 2

// Special Flags (Stored in EWRAM (gSpecialFlags), not in the SaveBlock)
#define SPECIAL_FLAGS_START                     0x4000
#define FLAG_HIDE_MAP_NAME_POPUP                (SPECIAL_FLAGS_START + 0x0)
#define FLAG_DONT_TRANSITION_MUSIC              (SPECIAL_FLAGS_START + 0x1)
#define FLAG_ENABLE_MULTI_CORRIDOR_DOOR         (SPECIAL_FLAGS_START + 0x2)
#define FLAG_SPECIAL_FLAG_UNUSED_0x4003         (SPECIAL_FLAGS_START + 0x3) // Unused Flag
#define FLAG_STORING_ITEMS_IN_PYRAMID_BAG       (SPECIAL_FLAGS_START + 0x4)
// FLAG_SPECIAL_FLAG_0x4005 - 0x407F also exist and are unused
#define SPECIAL_FLAGS_END                       (SPECIAL_FLAGS_START + 0x7F)

#endif // GUARD_CONSTANTS_FLAGS_H
