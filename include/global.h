#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include <string.h>
#include <limits.h>
#include "config.h" // we need to define config before gba headers as print stuff needs the functions nulled before defines.
#include "gba/gba.h"
#include "constants/global.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/species.h"
#include "constants/berry.h"
#include "constants/expansion_branches.h"

// Prevent cross-jump optimization.
#define BLOCK_CROSS_JUMP asm("");

// to help in decompiling
#define asm_comment(x) asm volatile("@ -- " x " -- ")
#define asm_unified(x) asm(".syntax unified\n" x "\n.syntax divided")
#define NAKED __attribute__((naked))

// IDE support
#if defined (__APPLE__) || defined (__CYGWIN__) || defined (_MSC_VER)
#define _(x) x
#define __(x) x

// Fool CLion IDE
#define INCBIN(x) {0}
#define INCBIN_U8 INCBIN
#define INCBIN_U16 INCBIN
#define INCBIN_U32 INCBIN
#define INCBIN_S8 INCBIN
#define INCBIN_S16 INCBIN
#define INCBIN_S32 INCBIN
#endif // IDE support

#define ARRAY_COUNT(array) (size_t)(sizeof(array) / sizeof((array)[0]))

// GameFreak used a macro called "NELEMS", as evidenced by
// AgbAssert calls.
#define NELEMS(arr) (sizeof(arr)/sizeof(*(arr)))

#define SWAP(a, b, temp)    \
{                           \
    temp = a;               \
    a = b;                  \
    b = temp;               \
}

#define DEBUG_BUILD
#define CURRENT_GAME_VERSION 1033

// free saveblock 1 defines             If defined it will free the space
#define FREE_TRAINER_HILL               //frees up trainer hill data. 28 bytes.                        WARNING THIS HAS BEEN SHOWN TO BREAK MULTI BATTLES
#define FREE_MYSTERY_EVENT_BUFFERS      //frees up mystery event and ramScript. roughly 1880 bytes     Needed by FREE_BATTLE_TOWER_E_READER
#define FREE_MATCH_CALL                 //frees up match call data. 104 bytes
#define FREE_UNION_ROOM_CHAT            //frees up field unk3C88. 210 bytes
#define FREE_ENIGMA_BERRY               //frees up enigma berry. 52 bytes
#define FREE_LINK_BATTLE_RECORDS        //frees link battle record data. 88 bytes
                                        //saveblock1 total: 1846 bytes
//free saveblock 2 defines
#define FREE_BATTLE_TOWER_E_READER      //frees up battle tower e reader trainer data. 188 bytes.        WARNING THIS HAS BEEN SHOWN TO BREAK THE POKÉ MARTS' QUESTIONNAIRE
#define FREE_POKEMON_JUMP               //frees up pokemon jump data. 16 bytes
#define FREE_RECORD_MIXING_HALL_RECORDS //frees up hall records for record mixing. 1032 bytes
                                        // saveblock2 total: 1236 bytes
                                        
                                        //grand total: 3082

// useful math macros

// Converts a number to Q8.8 fixed-point format
#define Q_8_8(n) ((s16)((n) * 256))

#define UQ_4_12_PRECISION 10
#define Q_4_12_PRECISION 12

// Converts a number to Q4.12 fixed-point format
#define Q_4_12(n)  ((s16)((n) * (1 << Q_4_12_PRECISION)))
#define UQ_4_12(n)  ((u16)((n) * (1 << UQ_4_12_PRECISION)))

// Converts a number to Q24.8 fixed-point format
#define Q_24_8(n)  ((s32)((n) << 8))

// Converts a Q8.8 fixed-point format number to a regular integer
#define Q_8_8_TO_INT(n) ((int)((n) / 256))

// Converts a Q4.12 fixed-point format number to a regular integer
#define Q_4_12_TO_INT(n)  ((int)((n) / (1 << Q_4_12_PRECISION)))
#define UQ_4_12_TO_INT(n)  ((int)((n) / (1 << UQ_4_12_PRECISION)))

// Converts a Q24.8 fixed-point format number to a regular integer
#define Q_24_8_TO_INT(n) ((int)((n) >> 8))

// Rounding value for Q4.12 fixed-point format
#define Q_4_12_ROUND ((1) << (Q_4_12_PRECISION - 1))
#define UQ_4_12_ROUND ((1) << (UQ_4_12_PRECISION - 1))

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))

#if MODERN
#define abs(x) (((x) < 0) ? -(x) : (x))
#endif

// Used in cases where division by 0 can occur in the retail version.
// Avoids invalid opcodes on some emulators, and the otherwise UB.
#ifdef UBFIX
#define SAFE_DIV(a, b) ((b) ? (a) / (b) : 0)
#else
#define SAFE_DIV(a, b) ((a) / (b))
#endif

// Extracts the upper 16 bits of a 32-bit number
#define HIHALF(n) (((n) & 0xFFFF0000) >> 16)

// Extracts the lower 16 bits of a 32-bit number
#define LOHALF(n) ((n) & 0xFFFF)

// There are many quirks in the source code which have overarching behavioral differences from
// a number of other files. For example, diploma.c seems to declare rodata before each use while
// other files declare out of order and must be at the beginning. There are also a number of
// macros which differ from one file to the next due to the method of obtaining the result, such
// as these below. Because of this, there is a theory (Two Team Theory) that states that these
// programming projects had more than 1 "programming team" which utilized different macros for
// each of the files that were worked on.
#define T1_READ_8(ptr)  ((ptr)[0])
#define T1_READ_16(ptr) ((ptr)[0] | ((ptr)[1] << 8))
#define T1_READ_32(ptr) ((ptr)[0] | ((ptr)[1] << 8) | ((ptr)[2] << 16) | ((ptr)[3] << 24))
#define T1_READ_PTR(ptr) (u8*) T1_READ_32(ptr)

// T2_READ_8 is a duplicate to remain consistent with each group.
#define T2_READ_8(ptr)  ((ptr)[0])
#define T2_READ_16(ptr) ((ptr)[0] + ((ptr)[1] << 8))
#define T2_READ_32(ptr) ((ptr)[0] + ((ptr)[1] << 8) + ((ptr)[2] << 16) + ((ptr)[3] << 24))
#define T2_READ_PTR(ptr) (void*) T2_READ_32(ptr)

// Macros for checking the joypad
#define TEST_BUTTON(field, button) ((field) & (button))
#define JOY_NEW(button) TEST_BUTTON(gMain.newKeys,  button)
#define JOY_HELD(button)  TEST_BUTTON(gMain.heldKeys, button)
#define JOY_HELD_RAW(button) TEST_BUTTON(gMain.heldKeysRaw, button)
#define JOY_REPEAT(button) TEST_BUTTON(gMain.newAndRepeatedKeys, button)

#define S16TOPOSFLOAT(val)   \
({                           \
    s16 v = (val);           \
    float f = (float)v;      \
    if(v < 0) f += 65536.0f; \
    f;                       \
})

// Branch defines: Used by other branches to detect each other.
// Each define must be here for each of RHH's branch you have pulled.
// e.g. If you have both the battle_engine and pokemon_expansion branch,
//      then both BATTLE_ENGINE and POKEMON_EXPANSION must be defined here.
#define BATTLE_ENGINE
#define POKEMON_EXPANSION
#define ITEM_EXPANSION
#define REBALANCED_VERSION
//tx_registered_items_menu
#define REGISTERED_ITEMS_MAX 10

#define ROUND_BITS_TO_BYTES(numBits)(((numBits) / 8) + (((numBits) % 8) ? 1 : 0))

#define DEX_FLAGS_NO (ROUND_BITS_TO_BYTES(POKEMON_SLOTS_NUMBER))
#define NUM_FLAG_BYTES (ROUND_BITS_TO_BYTES(FLAGS_COUNT))

#define POKEMON_SPECIES_NAME_LENGTH 12

struct Coords8
{
    s8 x;
    s8 y;
};

struct UCoords8
{
    u8 x;
    u8 y;
};

struct Coords16
{
    s16 x;
    s16 y;
};

struct UCoords16
{
    u16 x;
    u16 y;
};

struct Coords32
{
    s32 x;
    s32 y;
};

struct UCoords32
{
    u32 x;
    u32 y;
};

struct RegisteredItemSlot
{
    u16 itemId;
};

struct ItemSlot
{
    u16 itemId;
    u16 quantity;
};

struct Time
{
    /*0x00*/ s16 days;
    /*0x02*/ s8 hours;
    /*0x03*/ s8 minutes;
    /*0x04*/ s8 seconds;
};

struct Pokedex
{
    /*0x00*/ u8 order;
    /*0x01*/ u8 mode;
    /*0x02*/ u8 nationalMagic; // must equal 0xDA in order to have National mode
    /*0x03*/ u8 unknown2;
    /*0x04*/ u32 unownPersonality; // set when you first see Unown
    /*0x08*/ u32 spindaPersonality; // set when you first see Spinda
    /*0x0C*/ u32 unknown3;
};

struct PokemonJumpRecords
{
    u16 jumpsInRow;
    u16 unused1; // Set to 0, never read
    u16 excellentsInRow;
    u16 gamesWithMaxPlayers;
    u32 unused2; // Set to 0, never read
    u32 bestJumpScore;
};

struct BerryPickingResults
{
    u32 bestScore;
    u16 berriesPicked;
    u16 berriesPickedInRow;
    u8 field_8;
    u8 field_9;
    u8 field_A;
    u8 field_B;
    u8 field_C;
    u8 field_D;
    u8 field_E;
    u8 field_F;
};

// two arrays for lvl50 and open level
struct PyramidBag
{
    u16 itemId[2][PYRAMID_BAG_ITEMS_COUNT];
    u8 quantity[2][PYRAMID_BAG_ITEMS_COUNT];
};

struct BerryCrush
{
    u16 pressingSpeeds[4]; // For the record with each possible group size, 2-5 players
    u32 berryPowderAmount;
    u32 unk;
};

struct ApprenticeMon
{
    u16 species;
    u16 moves[MAX_MON_MOVES];
    u16 item;
};

// This is for past players Apprentices or Apprentices received via Record Mix.
// For the current Apprentice, see struct PlayersApprentice
struct Apprentice
{
    u8 id:5;
    u8 lvlMode:2; // + 1
    u8 numQuestions;
    u8 number;
    struct ApprenticeMon party[MULTI_PARTY_SIZE];
    u16 speechWon[EASY_CHAT_BATTLE_WORDS_COUNT];
    u8 playerId[TRAINER_ID_LENGTH];
    u8 playerName[PLAYER_NAME_LENGTH];
    u8 language;
    u32 checksum;
};

struct BattleTowerPokemon
{
    u16 species;
    u16 heldItem;
    u16 moves[MAX_MON_MOVES];
    u8 level;
    u8 ppBonuses;
    u8 hpEV;
    u8 attackEV;
    u8 defenseEV;
    u8 speedEV;
    u8 spAttackEV;
    u8 spDefenseEV;
    u32 otId;
    u32 hpIV:5;
    u32 attackIV:5;
    u32 defenseIV:5;
    u32 speedIV:5;
    u32 spAttackIV:5;
    u32 spDefenseIV:5;
    u32 gap:1;
    u32 abilityNum:1;
    u32 personality;
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u8 friendship;
    u8 hpType;
};

#define NULL_BATTLE_TOWER_POKEMON { .nickname = __("$$$$$$$$$$$") }

struct EmeraldBattleTowerRecord
{
    /*0x00*/ u8 lvlMode; // 0 = level 50, 1 = level 100
    /*0x01*/ u8 facilityClass;
    /*0x02*/ u16 winStreak;
    /*0x04*/ u8 name[PLAYER_NAME_LENGTH + 1];
    /*0x0C*/ u8 trainerId[TRAINER_ID_LENGTH];
    /*0x10*/ u16 greeting[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x1C*/ u16 speechWon[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x28*/ u16 speechLost[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x34*/ struct BattleTowerPokemon party[MAX_FRONTIER_PARTY_SIZE];
    /*0xE4*/ u8 language;
    /*0xE8*/ u32 checksum;
};

struct BattleTowerInterview
{
    u16 playerSpecies;
    u16 opponentSpecies;
    u8 opponentName[PLAYER_NAME_LENGTH + 1];
    u8 opponentMonNickname[POKEMON_NAME_LENGTH + 1];
    u8 opponentLanguage;
};

struct BattleTowerEReaderTrainer
{
    /*0x00*/ u8 unk0;
    /*0x01*/ u8 facilityClass;
    /*0x02*/ u16 winStreak;
    /*0x04*/ u8 name[PLAYER_NAME_LENGTH + 1];
    /*0x0C*/ u8 trainerId[TRAINER_ID_LENGTH];
    /*0x10*/ u16 greeting[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x1C*/ u16 farewellPlayerLost[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x28*/ u16 farewellPlayerWon[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x34*/ struct BattleTowerPokemon party[FRONTIER_PARTY_SIZE];
    /*0xB8*/ u32 checksum;
};

// For displaying party information on the player's Battle Dome tourney page
struct DomeMonData
{
    u16 moves[MAX_MON_MOVES];
    u8 evs[NUM_STATS];
    u8 nature;
};

struct RentalMon
{
    u16 monId;
    u32 personality;
    u8 ivs;
    u8 abilityNum;
};

struct BattleDomeTrainer
{
    u16 trainerId:10;
    u16 isEliminated:1;
    u16 eliminatedAt:2;
    u16 forfeited:3;
};

#define DOME_TOURNAMENT_TRAINERS_COUNT 16
#define BATTLE_TOWER_RECORD_COUNT 5

struct BattleFrontier
{
    struct EmeraldBattleTowerRecord towerPlayer;
    struct EmeraldBattleTowerRecord towerRecords[BATTLE_TOWER_RECORD_COUNT]; // From record mixing.
    struct BattleTowerInterview towerInterview;
    #ifndef FREE_BATTLE_TOWER_E_READER
    struct BattleTowerEReaderTrainer ereaderTrainer;  //188 bytes
    #endif
    u8 challengeStatus;
    u8 lvlMode:2;
    u8 challengePaused:1;
    u8 disableRecordBattle:1;
    u16 selectedPartyMons[MAX_FRONTIER_PARTY_SIZE];
    u16 curChallengeBattleNum; // Battle number / room number (Pike) / floor number (Pyramid)
    u16 trainerIds[20];
    u32 winStreakActiveFlags;
    u16 towerWinStreaks[4][2];
    u16 towerRecordWinStreaks[4][2];
    u16 battledBrainFlags;
    u16 towerSinglesStreak; // Never read
    u16 towerNumWins; // Increments to MAX_STREAK but never read otherwise
    u8 towerBattleOutcome;
    u8 towerLvlMode;
    u8 domeAttemptedSingles50:1;
    u8 domeAttemptedSinglesOpen:1;
    u8 domeHasWonSingles50:1;
    u8 domeHasWonSinglesOpen:1;
    u8 domeAttemptedDoubles50:1;
    u8 domeAttemptedDoublesOpen:1;
    u8 domeHasWonDoubles50:1;
    u8 domeHasWonDoublesOpen:1;
    u8 domeUnused;
    u8 domeLvlMode;
    u8 domeBattleMode;
    u16 domeWinStreaks[2][2];
    u16 domeRecordWinStreaks[2][2];
    u16 domeTotalChampionships[2][2];
    struct BattleDomeTrainer domeTrainers[DOME_TOURNAMENT_TRAINERS_COUNT];
    u16 domeMonIds[DOME_TOURNAMENT_TRAINERS_COUNT][FRONTIER_PARTY_SIZE];
    u16 palacePrize;
    u16 palaceWinStreaks[2][2];
    u16 palaceRecordWinStreaks[2][2];
    u16 arenaPrize;
    u16 arenaWinStreaks[2];
    u16 arenaRecordStreaks[2];
    u16 factoryWinStreaks[2][2];
    u16 factoryRecordWinStreaks[2][2];
    u16 factoryRentsCount[2][2];
    u16 factoryRecordRentsCount[2][2];
    u16 pikePrize;
    u16 pikeWinStreaks[2];
    u16 pikeRecordStreaks[2];
    u16 pikeTotalStreaks[2];
    u8 pikeHintedRoomIndex:3;
    u8 pikeHintedRoomType:4;
    u8 pikeHealingRoomsDisabled:1;
    u16 pikeHeldItemsBackup[FRONTIER_PARTY_SIZE];
    u16 pyramidPrize;
    u16 pyramidWinStreaks[2];
    u16 pyramidRecordStreaks[2];
    u16 pyramidRandoms[4];
    u8 pyramidTrainerFlags;
    struct PyramidBag pyramidBag;
    u8 pyramidLightRadius;
    u16 verdanturfTentPrize;
    u16 fallarborTentPrize;
    u16 slateportTentPrize;
    struct RentalMon rentalMons[FRONTIER_PARTY_SIZE * 2];
    u16 battlePoints;
    u16 cardBattlePoints;
    u32 battlesCount;
    u16 domeWinningMoves[DOME_TOURNAMENT_TRAINERS_COUNT];
    u8 trainerFlags;
    u8 opponentNames[2][PLAYER_NAME_LENGTH + 1];
    u8 opponentTrainerIds[2][TRAINER_ID_LENGTH];
    u8 savedGame:1;
    u8 filler:7; // Never read
    struct DomeMonData domePlayerPartyData[FRONTIER_PARTY_SIZE];
};

struct ApprenticeQuestion
{
    u8 questionId:2;
    u8 monId:2;
    u8 moveSlot:2;
    u8 suggestedChange:2; // TRUE if told to use held item or second move, FALSE if told to use no item or first move
    u16 data; // used both as an itemId and a moveId
};

struct PlayersApprentice
{
    /*0xB0*/ u8 id;
    /*0xB1*/ u8 lvlMode:2;  //0: Unassigned, 1: Lv 50, 2: Open Lv
    /*0xB1*/ u8 questionsAnswered:4;
    /*0xB1*/ u8 leadMonId:2;
    /*0xB2*/ u8 party:3;
    /*0xB2*/ u8 saveId:2;
    /*0xB3*/ u8 unused;
    /*0xB4*/ u8 speciesIds[MULTI_PARTY_SIZE];
    /*0xB8*/ struct ApprenticeQuestion questions[APPRENTICE_MAX_QUESTIONS];
};

struct RankingHall1P
{
    u8 id[TRAINER_ID_LENGTH];
    u16 winStreak;
    u8 name[PLAYER_NAME_LENGTH + 1];
    u8 language;
};

struct RankingHall2P
{
    u8 id1[TRAINER_ID_LENGTH];
    u8 id2[TRAINER_ID_LENGTH];
    u16 winStreak;
    u8 name1[PLAYER_NAME_LENGTH + 1];
    u8 name2[PLAYER_NAME_LENGTH + 1];
    u8 language;
};

// quest menu
#include "constants/quests.h"
#define SIDE_QUEST_FLAGS_COUNT     ((SIDE_QUEST_COUNT / 8) + ((SIDE_QUEST_COUNT % 8) ? 1 : 0))

struct SaveBlock2
{
    u8 playerName[PLAYER_NAME_LENGTH + 1];
    u8 playerGender; // MALE, FEMALE
    u8 specialSaveWarpFlags;
    u8 playerTrainerId[TRAINER_ID_LENGTH];
    u16 playTimeHours;
    u8  playTimeMinutes;
    u8  playTimeSeconds;
    u8  playTimeVBlanks;
    struct Pokedex pokedex;
    struct Time localTimeOffset;
    struct Time lastBerryTreeUpdate;
    u32 encryptionKey;
    struct PlayersApprentice playerApprentice;
    struct Apprentice apprentices[APPRENTICE_COUNT]; //272 bytes
    struct BerryCrush berryCrush;
    #ifndef FREE_POKEMON_JUMP
    struct PokemonJumpRecords pokeJump;   //16 bytes
    #endif
    struct BerryPickingResults berryPick;
    #ifndef FREE_RECORD_MIXING_HALL_RECORDS
    struct RankingHall1P hallRecords1P[HALL_FACILITIES_COUNT][2][3]; // From record mixing.
    struct RankingHall2P hallRecords2P[2][3]; // From record mixing.
    #endif
    u16 contestLinkResults[CONTEST_CATEGORIES_COUNT][CONTESTANT_COUNT];
    struct BattleFrontier frontier;

    //Game Options
    u16 optionsTextSpeed:3;       // OPTIONS_TEXT_SPEED_[SLOW/MID/FAST]
    u16 optionsWindowFrameType:5; // Specifies one of the 20 decorative borders for text boxes
    u16 optionsSound:1;           // OPTIONS_SOUND_[MONO/STEREO]
    u16 optionsBattleStyle:1;     // OPTIONS_BATTLE_STYLE_[SHIFT/SET]
    u16 optionsBattleSceneOff:1;  // whether battle animations are disabled
    u16 regionMapZoom:1;          // whether the map is zoomed in
    u16 gameDifficulty:4;         // Which difficulty the player chose (Normal/Hard/Challenge/Insanity, with Normal being 0)

    u16 levelCaps:3;              // Various options for level caps
    u16 innaterandomizedMode:1;
    u16 encounterRandomizedMode:1;
    u16 abilityRandomizedMode:1;
    u16 moveRandomizedMode:1;
    u16 typeRandomizedMode:1;
    u16 encounterRandomizedLegendaryMode:1;
    u16 optionsHpBarSpeed:2;
    u16 autoRun:1;
    u16 permanentRepel:1;
    u16 damageDone:1;
    u16 askForNickname:1;

    u16 shinyrate:2;
    u16 enableEvs:1;
    u16 playerAI:1;
    u16 individualColors:1;
    u16 doubleBattleMode:1;
    u16 optionsButtonMode:3;  // OPTIONS_BUTTON_MODE_[NORMAL/LR/L_EQUALS_A]
    u16 automaticEVGain:1;
    u16 automaticExpGain:1;
    u16 permanentMegaMode:1;
    u16 automaticEvolution:1;
    u16 filler:3;
    u8 questStatus[SIDE_QUEST_FLAGS_COUNT];
    //u8 unlockedQuests[SIDE_QUEST_FLAGS_COUNT];
    //u8 completedQuests[SIDE_QUEST_FLAGS_COUNT];
    u8 activeQuest;
}; // sizeof=0xF2C

extern struct SaveBlock2 *gSaveBlock2Ptr;

struct SecretBaseParty
{
    u32 personality[PARTY_SIZE];
    u16 moves[PARTY_SIZE * MAX_MON_MOVES];
    u16 species[PARTY_SIZE];
    u16 heldItems[PARTY_SIZE];
    u8 levels[PARTY_SIZE];
    u8 EVs[PARTY_SIZE];
};

struct SecretBase
{
    /*0x1A9C*/ u8 secretBaseId;
    /*0x1A9D*/ bool8 toRegister:4;
    /*0x1A9D*/ u8 gender:1;
    /*0x1A9D*/ u8 battledOwnerToday:1;
    /*0x1A9D*/ u8 registryStatus:2;
    /*0x1A9E*/ u8 trainerName[PLAYER_NAME_LENGTH];
    /*0x1AA5*/ u8 trainerId[TRAINER_ID_LENGTH]; // byte 0 is used for determining trainer class
    /*0x1AA9*/ u8 language;
    /*0x1AAA*/ u16 numSecretBasesReceived;
    /*0x1AAC*/ u8 numTimesEntered;
    /*0x1AAD*/ u8 unused;
    /*0x1AAE*/ u8 decorations[DECOR_MAX_SECRET_BASE];
    /*0x1ABE*/ u8 decorationPositions[DECOR_MAX_SECRET_BASE];
    /*0x1AD0*/ struct SecretBaseParty party;
};

#include "constants/game_stat.h"
#include "global.fieldmap.h"
#include "global.berry.h"
#include "global.tv.h"
#include "pokemon.h"

struct WarpData
{
    s8 mapGroup;
    s8 mapNum;
    s8 warpId;
    s16 x, y;
};

struct Pokeblock
{
    u8 color;
    u8 spicy;
    u8 dry;
    u8 sweet;
    u8 bitter;
    u8 sour;
    u8 feel;
};

struct Roamer
{
    /*0x00*/ u32 ivs;
    /*0x04*/ u32 personality;
    /*0x08*/ u16 species;
    /*0x0A*/ u16 hp;
    /*0x0C*/ u8 level;
    /*0x0D*/ u8 status;
    /*0x0E*/ u8 cool;
    /*0x0F*/ u8 beauty;
    /*0x10*/ u8 cute;
    /*0x11*/ u8 smart;
    /*0x12*/ u8 tough;
    /*0x13*/ bool8 active;
};

struct RamScriptData
{
    u8 magic;
    u8 mapGroup;
    u8 mapNum;
    u8 objectId;
    u8 script[995];
};

struct RamScript
{
    u32 checksum;
    struct RamScriptData data;
};

// See dewford_trend.c
struct DewfordTrend
{
    u16 trendiness:7;
    u16 maxTrendiness:7;
    u16 gainingTrendiness:1;
    u16 rand;
    u16 words[2];
}; /*size = 0x8*/

struct MailStruct
{
    /*0x00*/ u16 words[MAIL_WORDS_COUNT];
    /*0x12*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
    /*0x1A*/ u8 trainerId[TRAINER_ID_LENGTH];
    /*0x1E*/ u16 species;
    /*0x20*/ u16 itemId;
};

struct MauvilleManCommon
{
    u8 id;
};

struct MauvilleManBard
{
    /*0x00*/ u8 id;
    /*0x02*/ u16 songLyrics[BARD_SONG_LENGTH];
    /*0x0E*/ u16 temporaryLyrics[BARD_SONG_LENGTH];
    /*0x1A*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
    /*0x25*/ u8 playerTrainerId[TRAINER_ID_LENGTH];
    /*0x29*/ bool8 hasChangedSong;
    /*0x2A*/ u8 language;
}; /*size = 0x2C*/

struct MauvilleManStoryteller
{
    u8 id;
    bool8 alreadyRecorded;
    u8 gameStatIDs[NUM_STORYTELLER_TALES];
    u8 trainerNames[NUM_STORYTELLER_TALES][PLAYER_NAME_LENGTH];
    u8 statValues[NUM_STORYTELLER_TALES][4];
    u8 language[NUM_STORYTELLER_TALES];
};

struct MauvilleManGiddy
{
    /*0x00*/ u8 id;
    /*0x01*/ u8 taleCounter;
    /*0x02*/ u8 questionNum;
    /*0x04*/ u16 randomWords[10];
    /*0x18*/ u8 questionList[8];
    /*0x20*/ u8 language;
}; /*size = 0x2C*/

struct MauvilleManHipster
{
    u8 id;
    bool8 alreadySpoken;
    u8 language;
};

struct MauvilleOldManTrader
{
    u8 id;
    u8 decorations[NUM_TRADER_ITEMS];
    u8 playerNames[NUM_TRADER_ITEMS][11];
    u8 alreadyTraded;
    u8 language[NUM_TRADER_ITEMS];
};

typedef union OldMan
{
    struct MauvilleManCommon common;
    struct MauvilleManBard bard;
    struct MauvilleManGiddy giddy;
    struct MauvilleManHipster hipster;
    struct MauvilleOldManTrader trader;
    struct MauvilleManStoryteller storyteller;
} OldMan;

struct RecordMixing_UnknownStructSub
{
    u32 unk0;
    u8 data[0x34];
    //u8 data[0x38];
};

struct RecordMixing_UnknownStruct
{
    struct RecordMixing_UnknownStructSub data[2];
    u32 unk70;
    u16 unk74[0x2];
};

#define LINK_B_RECORDS_COUNT 5

struct LinkBattleRecord
{
    u8 name[PLAYER_NAME_LENGTH + 1];
    u16 trainerId;
    u16 wins;
    u16 losses;
    u16 draws;
};

struct LinkBattleRecords
{
    struct LinkBattleRecord entries[LINK_B_RECORDS_COUNT];
    u8 languages[LINK_B_RECORDS_COUNT];
};

struct RecordMixingGiftData
{
    u8 unk0;
    u8 quantity;
    u16 itemId;
};

struct RecordMixingGift
{
    int checksum;
    struct RecordMixingGiftData data;
};

struct ContestWinner
{
    u32 personality;
    u32 trainerId;
    u16 species;
    u8 contestCategory;
    u8 monName[POKEMON_NAME_LENGTH + 1];
    u8 trainerName[PLAYER_NAME_LENGTH + 1];
    u8 contestRank;
};

struct DaycareMail
{
    struct MailStruct message;
    u8 OT_name[PLAYER_NAME_LENGTH + 1];
    u8 monName[POKEMON_NAME_LENGTH + 1];
    u8 gameLanguage:4;
    u8 monLanguage:4;
};

struct DaycareMon
{
    struct BoxPokemon mon;
    struct DaycareMail mail;
    u32 steps;
};

struct DayCare
{
    struct DaycareMon mons[DAYCARE_MON_COUNT];
    u32 offspringPersonality;
    u8 stepCounter;
};

struct RecordMixingDaycareMail
{
    struct DaycareMail mail[DAYCARE_MON_COUNT];
    u32 numDaycareMons;
    bool16 holdsItem[DAYCARE_MON_COUNT];
};

struct LilycoveLadyQuiz
{
    /*0x000*/ u8 id;
    /*0x001*/ u8 state;
    /*0x002*/ u16 question[9];
    /*0x014*/ u16 correctAnswer;
    /*0x016*/ u16 playerAnswer;
    /*0x018*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
    /*0x020*/ u16 playerTrainerId[TRAINER_ID_LENGTH];
    /*0x028*/ u16 prize;
    /*0x02a*/ bool8 waitingForChallenger;
    /*0x02b*/ u8 questionId;
    /*0x02c*/ u8 prevQuestionId;
    /*0x02d*/ u8 language;
};

struct LilycoveLadyFavor
{
    /*0x000*/ u8 id;
    /*0x001*/ u8 state;
    /*0x002*/ bool8 likedItem;
    /*0x003*/ u8 numItemsGiven;
    /*0x004*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
    /*0x00c*/ u8 favorId;
    /*0x00e*/ u16 itemId;
    /*0x010*/ u16 bestItem;
    /*0x012*/ u8 language;
};

struct LilycoveLadyContest
{
    /*0x000*/ u8 id;
    /*0x001*/ bool8 givenPokeblock;
    /*0x002*/ u8 numGoodPokeblocksGiven;
    /*0x003*/ u8 numOtherPokeblocksGiven;
    /*0x004*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
    /*0x00c*/ u8 maxSheen;
    /*0x00d*/ u8 category;
    /*0x00e*/ u8 language;
};

typedef union // 3b58
{
    struct LilycoveLadyQuiz quiz;
    struct LilycoveLadyFavor favor;
    struct LilycoveLadyContest contest;
    u8 id;
    u8 pad[0x40];
} LilycoveLady;

struct WaldaPhrase
{
    u16 colors[2]; // Background, foreground.
    u8 text[16];
    u8 iconId;
    u8 patternId;
    bool8 patternUnlocked;
};

struct TrainerNameRecord
{
    u32 trainerId;
    u8 trainerName[PLAYER_NAME_LENGTH + 1];
};

struct SaveTrainerHill
{
    /*0x3D64*/ u32 timer;
    /*0x3D68*/ u32 bestTime;
    /*0x3D6C*/ u8 unk_3D6C;
    /*0x3D6D*/ u8 unused;
    /*0x3D6E*/ u16 receivedPrize:1;
    /*0x3D6E*/ u16 checkedFinalTime:1;
    /*0x3D6E*/ u16 spokeToOwner:1;
    /*0x3D6E*/ u16 hasLost:1;
    /*0x3D6E*/ u16 maybeECardScanDuringChallenge:1;
    /*0x3D6E*/ u16 field_3D6E_0f:1;
    /*0x3D6E*/ u16 tag:2;
};

struct MysteryEventStruct
{
    u8 unk_0_0:2;
    u8 unk_0_2:3;
    u8 unk_0_5:3;
    u8 unk_1;
};

 struct WonderNews
{
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04[40];
    u8 unk_2C[10][40];
};

 struct WonderNewsSaveStruct
{
    u32 crc;
    struct WonderNews data;
};

 struct WonderCard
{
    u16 unk_00;
    u16 unk_02;
    u32 unk_04;
    u8 unk_08_0:2;
    u8 unk_08_2:4;
    u8 unk_08_6:2;
    u8 unk_09;
    u8 unk_0A[40];
    u8 unk_32[40];
    u8 unk_5A[4][40];
    u8 unk_FA[40];
    u8 unk_122[40];
};

 struct WonderCardSaveStruct
{
    u32 crc;
    struct WonderCard data;
};

 struct WonderCardMetadata
{
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08[2][7];
};

 struct MEventBuffer_3430
{
    u32 crc;
    struct WonderCardMetadata data;
};

 struct MysteryGiftSave
{
    /*0x000 0x322C*/ struct WonderNewsSaveStruct wonderNews;
    /*0x1c0 0x33EC*/ struct WonderCardSaveStruct wonderCard;
    /*0x310 0x353C*/ struct MEventBuffer_3430 cardMetadata;
    /*0x338 0x3564*/ u16 questionnaireWords[NUM_QUESTIONNAIRE_WORDS];
    /*0x340 0x356C*/ struct MysteryEventStruct newsMetadata;
    /*0x344 0x3570*/ u32 unk_344[2][5];
}; // 0x36C 0x3598

// Ignore addresses, struct has been modified and they weren't updated
// For external event data storage. The majority of these may have never been used.
// In Emerald, the only known used fields are the PokeCoupon and BoxRS ones, but hacking the distribution discs allows Emerald to receive events and set the others
struct ExternalEventData
{
    u8 unknownExternalDataFields1[7]; // if actually used, may be broken up into different fields.
    u32 unknownExternalDataFields2:8;
    u32 currentPokeCoupons:24; // PokéCoupons stored by Pokémon Colosseum and XD from Mt. Battle runs. Earned PokéCoupons are also added to totalEarnedPokeCoupons. Colosseum/XD caps this at 9,999,999, but will read up to 16,777,215.
    u32 gotGoldPokeCouponTitleReward:1; // Master Ball from JP Colosseum Bonus Disc; for reaching 30,000 totalEarnedPokeCoupons
    u32 gotSilverPokeCouponTitleReward:1; // Light Ball Pikachu from JP Colosseum Bonus Disc; for reaching 5000 totalEarnedPokeCoupons
    u32 gotBronzePokeCouponTitleReward:1; // PP Max from JP Colosseum Bonus Disc; for reaching 2500 totalEarnedPokeCoupons
    u32 receivedAgetoCelebi:1; // from JP Colosseum Bonus Disc
    u32 unknownExternalDataFields3:4;
    u32 totalEarnedPokeCoupons:24; // Used by the JP Colosseum bonus disc. Determines PokéCoupon rank to distribute rewards. Unread in International games. Colosseum/XD caps this at 9,999,999.
    u8 unknownExternalDataFields4[5]; // if actually used, may be broken up into different fields.
} __attribute__((packed)); /*size = 0x14*/

// For external event flags. The majority of these may have never been used.
// In Emerald, Jirachi cannot normally be received, but hacking the distribution discs allows Emerald to receive Jirachi and set the flag
struct ExternalEventFlags
{
    u8 usedBoxRS:1; // Set by Pokémon Box: Ruby & Sapphire; denotes whether this save has connected to it and triggered the free False Swipe Swablu Egg giveaway.
    u8 boxRSEggsUnlocked:2; // Set by Pokémon Box: Ruby & Sapphire; denotes the number of Eggs unlocked from deposits; 1 for ExtremeSpeed Zigzagoon (at 100 deposited), 2 for Pay Day Skitty (at 500 deposited), 3 for Surf Pichu (at 1499 deposited)
    u8 padding:5;
    u8 unknownFlag1;
    u8 receivedGCNJirachi; // Both the US Colosseum Bonus Disc and PAL/AUS Pokémon Channel use this field. One cannot receive a WISHMKR Jirachi and CHANNEL Jirachi with the same savefile.
    u8 unknownFlag3;
    u8 unknownFlag4;
    u8 unknownFlag5;
    u8 unknownFlag6;
    u8 unknownFlag7;
    u8 unknownFlag8;
    u8 unknownFlag9;
    u8 unknownFlag10;
    u8 unknownFlag11;
    u8 unknownFlag12;
    u8 unknownFlag13;
    u8 unknownFlag14;
    u8 unknownFlag15;
    u8 unknownFlag16;
    u8 unknownFlag17;
    u8 unknownFlag18;
    u8 unknownFlag19;
    u8 unknownFlag20;

} __attribute__((packed));/*size = 0x15*/

struct SaveBlock1
{
    struct Coords16 pos;
    struct WarpData location;
    struct WarpData continueGameWarp;
    struct WarpData dynamicWarp;
    struct WarpData lastHealLocation; // used by white-out and teleport
    struct WarpData escapeWarp; // used by Dig and Escape Rope
    u16 savedMusic;
    u8 weather;
    u8 weatherCycleStage;
    u8 flashLevel;
    u16 mapLayoutId;
    u16 mapView[0x100];
    u8 playerPartyCount;
    struct Pokemon playerParty[PARTY_SIZE];
    u32 money;
    u16 coins;
    u16 registeredItemSelect; // registered for use with SELECT button
    struct ItemSlot pcItems[PC_ITEMS_COUNT];
    struct ItemSlot bagPocket_Items[BAG_ITEMS_COUNT];
    struct ItemSlot bagPocket_KeyItems[BAG_KEYITEMS_COUNT];
    struct ItemSlot bagPocket_PokeBalls[BAG_POKEBALLS_COUNT];
    struct ItemSlot bagPocket_TMHM[BAG_TMHM_COUNT];
    struct ItemSlot bagPocket_Berries[BAG_BERRIES_COUNT];
    struct ItemSlot bagPocket_Medicine[BAG_MEDICINE_COUNT];
    struct ItemSlot bagPocket_Battle[BAG_BATTLE_COUNT];
    struct ItemSlot bagPocket_MegaStones[BAG_MEGASTONES_COUNT];
    struct Pokeblock pokeblocks[POKEBLOCKS_COUNT];
    u16 berryBlenderRecords[3];
    #ifndef FREE_MATCH_CALL
    u16 trainerRematchStepCounter;
    #endif
    u8 trainerRematches[MAX_REMATCH_ENTRIES];
    struct ObjectEvent objectEvents[OBJECT_EVENTS_COUNT];
    struct ObjectEventTemplate objectEventTemplates[OBJECT_EVENT_TEMPLATES_COUNT];
    u8 flags[NUM_FLAG_BYTES];
    u16 vars[VARS_COUNT];
    u32 gameStats[NUM_GAME_STATS];
    struct BerryTree berryTrees[BERRY_TREES_COUNT];
    struct SecretBase secretBases[SECRET_BASES_COUNT];
    u8 playerRoomDecorations[DECOR_MAX_PLAYERS_HOUSE];
    u8 playerRoomDecorationPositions[DECOR_MAX_PLAYERS_HOUSE];
    u8 decorationDesks[10];
    u8 decorationChairs[10];
    u8 decorationPlants[10];
    u8 decorationOrnaments[30];
    u8 decorationMats[30];
    u8 decorationPosters[10];
    u8 decorationDolls[40];
    u8 decorationCushions[10];
    u8 padding_27CA[2];
    TVShow tvShows[TV_SHOWS_COUNT]; //900 bytes
    PokeNews pokeNews[POKE_NEWS_COUNT];
    u16 outbreakPokemonSpecies;
    u8 outbreakLocationMapNum;
    u8 outbreakLocationMapGroup;
    u8 outbreakPokemonLevel;
    u8 outbreakUnk1;
    u16 outbreakUnk2;
    u16 outbreakPokemonMoves[MAX_MON_MOVES];
    u8 outbreakUnk4;
    u8 outbreakPokemonProbability;
    u16 outbreakDaysLeft;
    struct GabbyAndTyData gabbyAndTyData;
    u16 easyChatProfile[EASY_CHAT_BATTLE_WORDS_COUNT];
    u16 easyChatBattleStart[EASY_CHAT_BATTLE_WORDS_COUNT];
    u16 easyChatBattleWon[EASY_CHAT_BATTLE_WORDS_COUNT];
    u16 easyChatBattleLost[EASY_CHAT_BATTLE_WORDS_COUNT];
    struct MailStruct mail[MAIL_COUNT];
    u8 additionalPhrases[8]; // bitfield for 33 additional phrases in easy chat system
    OldMan oldMan;
    struct DewfordTrend dewfordTrends[SAVED_TRENDS_COUNT];
    struct ContestWinner contestWinners[NUM_CONTEST_WINNERS]; // see CONTEST_WINNER_*
    struct DayCare daycare;
    #ifndef FREE_LINK_BATTLE_RECORDS
    struct LinkBattleRecords linkBattleRecords;
    #endif
    u8 giftRibbons[GIFT_RIBBONS_COUNT];
    struct ExternalEventData externalEventData;
    struct ExternalEventFlags externalEventFlags;
    struct Roamer roamer;
    #ifndef FREE_ENIGMA_BERRY
    struct EnigmaBerry enigmaBerry;
    #endif
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    struct MysteryGiftSave mysteryGift;
    #endif
    u8 dexSeen[DEX_FLAGS_NO];
    u8 dexCaught[DEX_FLAGS_NO];
    #ifndef FREE_TRAINER_HILL
    u32 trainerHillTimes[4];
    #endif
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    struct RamScript ramScript;
    #endif
    struct RecordMixingGift recordMixingGift;
    LilycoveLady lilycoveLady;
    struct TrainerNameRecord trainerNameRecords[20];
    #ifndef FREE_UNION_ROOM_CHAT
    u8 registeredTexts[UNION_ROOM_KB_ROW_COUNT][21];
    #endif
    #ifndef FREE_TRAINER_HILL
    struct SaveTrainerHill trainerHill;
    #endif
    struct WaldaPhrase waldaPhrase;
    struct BoxPokemon kyuremFusedMon;
    struct BoxPokemon necrozmaFusedMon;
    struct BoxPokemon calyrexFusedMon;
    u8 dexNavChain;
    u8 registeredItemLastSelected:4; //max 16 items
    u8 registeredItemListCount:4;
    struct RegisteredItemSlot registeredItems[REGISTERED_ITEMS_MAX];
};

extern struct SaveBlock1* gSaveBlock1Ptr;

struct MapPosition
{
    s16 x;
    s16 y;
    s8 height;
};

#endif // GUARD_GLOBAL_H
