#ifndef GUARD_CONSTANTS_GLOBAL_H
#define GUARD_CONSTANTS_GLOBAL_H
// Invalid Versions show as "----------" in Gen 4 and Gen 5's summary screen.
// In Gens 6 and 7, invalid versions instead show "a distant land" in the summary screen.
// In Gen 4 only, migrated Pokemon with Diamond, Pearl, or Platinum's ID show as "----------".
// Gen 5 and up read Diamond, Pearl, or Platinum's ID as "Sinnoh".
// In Gen 4 and up, migrated Pokemon with HeartGold or SoulSilver's ID show the otherwise unused "Johto" string.
#define VERSION_SAPPHIRE 1
#define VERSION_RUBY 2
#define VERSION_EMERALD 3
#define VERSION_FIRE_RED 4
#define VERSION_LEAF_GREEN 5
#define VERSION_HEART_GOLD 7
#define VERSION_SOUL_SILVER 8
#define VERSION_DIAMOND 10
#define VERSION_PEARL 11
#define VERSION_PLATINUM 12
#define VERSION_GAMECUBE 15

#define LANGUAGE_JAPANESE 1
#define LANGUAGE_ENGLISH  2
#define LANGUAGE_FRENCH   3
#define LANGUAGE_ITALIAN  4
#define LANGUAGE_GERMAN   5
#define LANGUAGE_KOREAN   6 // 6 goes unused but the theory is it was meant to be Korean
#define LANGUAGE_SPANISH  7
#define NUM_LANGUAGES     7

#define GAME_VERSION (VERSION_EMERALD)
#define GAME_LANGUAGE (LANGUAGE_ENGLISH)

// capacities of various saveblock objects
#define DAYCARE_MON_COUNT 2
#define POKEBLOCKS_COUNT 40
#define OBJECT_EVENTS_COUNT 16
#define BERRY_TREES_COUNT 128
#define MAIL_COUNT 1 // was 16
#define SECRET_BASES_COUNT 4 // was 20. This frees up 2512 bytes of save space, which can go to bag space
#define TV_SHOWS_COUNT 25
#define POKE_NEWS_COUNT 16
#define PC_ITEMS_COUNT 30
#define BAG_ITEMS_COUNT 93
#define BAG_MEDICINE_COUNT 44
#define BAG_BATTLE_COUNT 180
#define BAG_TMHM_COUNT 108
#define BAG_BERRIES_COUNT 66
#define BAG_POKEBALLS_COUNT 27
#define BAG_KEYITEMS_COUNT 55
#define BAG_MEGASTONES_COUNT_NEW 140
#define BAG_MEGASTONES_COUNT 70 //Unused
#define OBJECT_EVENT_TEMPLATES_COUNT 64
#define DECOR_MAX_SECRET_BASE 16
#define DECOR_MAX_PLAYERS_HOUSE 12
#define APPRENTICE_COUNT 4
#define APPRENTICE_MAX_QUESTIONS 9
#define MAX_REMATCH_ENTRIES 78 // only REMATCH_TABLE_ENTRIES (78) are used
#define NUM_CONTEST_WINNERS 13
#define UNION_ROOM_KB_ROW_COUNT 10
#define GIFT_RIBBONS_COUNT 11
#define SAVED_TRENDS_COUNT 5

#define PYRAMID_BAG_ITEMS_COUNT 10
#define HALL_FACILITIES_COUNT 9 // 7 facilities for single mode + tower double mode + tower multi mode.

#define TRAINER_ID_LENGTH 4
#define MAX_MON_MOVES 4
#define NUM_STATS 6

#define CONTESTANT_COUNT 4
#define CONTEST_CATEGORY_COOL     0
#define CONTEST_CATEGORY_BEAUTY   1
#define CONTEST_CATEGORY_CUTE     2
#define CONTEST_CATEGORY_SMART    3
#define CONTEST_CATEGORY_TOUGH    4
#define CONTEST_CATEGORIES_COUNT  5

// party sizes
#define PARTY_SIZE 6
#define MULTI_PARTY_SIZE (PARTY_SIZE / 2)
#define FRONTIER_PARTY_SIZE         3
#define FRONTIER_DOUBLES_PARTY_SIZE 4
#define FRONTIER_MULTI_PARTY_SIZE   2
#define MAX_FRONTIER_PARTY_SIZE     FRONTIER_DOUBLES_PARTY_SIZE
#define UNION_ROOM_PARTY_SIZE       2

// string lengths
#define ITEM_NAME_LENGTH 17
#define POKEMON_NAME_LENGTH 10
#define PLAYER_NAME_LENGTH 7
#define MAIL_WORDS_COUNT 9
#define EASY_CHAT_BATTLE_WORDS_COUNT 6
#define MOVE_NAME_LENGTH 12
#define LONG_MOVE_NAME_LENGTH 18
#define NUM_QUESTIONNAIRE_WORDS 4

#define MALE 0
#define FEMALE 1
#define GENDER_COUNT 2

#define BARD_SONG_LENGTH       6
#define NUM_STORYTELLER_TALES  4
#define NUM_TRADER_ITEMS       4

#define OPTIONS_BUTTON_MODE_NORMAL 0
#define OPTIONS_BUTTON_MODE_LR 1
#define OPTIONS_BUTTON_MODE_L_EQUALS_A 2

#define OPTIONS_TEXT_SPEED_SLOW 0
#define OPTIONS_TEXT_SPEED_MID 1
#define OPTIONS_TEXT_SPEED_FAST 2
#define OPTIONS_TEXT_SPEED_INSTANT 3

#define OPTIONS_SOUND_MONO 0
#define OPTIONS_SOUND_STEREO 1

#define OPTIONS_BATTLE_STYLE_SHIFT 0
#define OPTIONS_BATTLE_STYLE_SET 1

#define DIR_NONE        0
#define DIR_SOUTH       1
#define DIR_NORTH       2
#define DIR_WEST        3
#define DIR_EAST        4
#define DIR_SOUTHWEST   5
#define DIR_SOUTHEAST   6
#define DIR_NORTHWEST   7
#define DIR_NORTHEAST   8

#define DIFFICULTY_EASY        0
#define DIFFICULTY_ACE         1
#define DIFFICULTY_ELITE       2

#define LEVEL_CAPS_EASY        0
#define LEVEL_CAPS_MORE        1
#define LEVEL_CAPS_ELITE       2
#define LEVEL_CAPS_OFF         3

//Saveblock Toggle Stuff
#define SAVEBLOCK_RANDOMIZER        0
#define SAVEBLOCK_INNATE_RANDOMIZER 1
#define SAVEBLOCK_DIFFICULTY        2
#define SAVEBLOCK_ENABLE_LEGENDARY  3

//In Battle Debug Stuff
#define MACROS_PRINT_MGBA_MESSAGE                          0
#define MACROS_FORCE_FALSE_SWIPE_EFFECT                    1
#define MACROS_RESET_MULTIHIT_HITS                         2
#define MACROS_GET_DOUBLE_HEALTH                           3
#define MACROS_TRY_TO_ACTIVATE_INTIMIDATE_CLONE_TARGET_1   4
#define MACROS_TRY_TO_ACTIVATE_INTIMIDATE_CLONE_TARGET_2   5
#define MACROS_SAVE_ABILITY_TO_VARIABLE                    6
#define MACROS_OVERWRITE_NEXT_STRING                       7
#define MACROS_CLEAN_OVERWRITEN_STRINGS                    8

#endif // GUARD_CONSTANTS_GLOBAL_H
