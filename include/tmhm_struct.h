#ifndef GUARD_TMHM_STRUCT_H
#define GUARD_TMHM_STRUCT_H

#include "global.h"
#include "constants/moves.h"

#define ALL_TMS \
TM_DECORATOR(MOVE_FOCUS_PUNCH) \
TM_DECORATOR(MOVE_DRAGON_CLAW) \
TM_DECORATOR(MOVE_WATER_PULSE) \
TM_DECORATOR(MOVE_CALM_MIND) \
TM_DECORATOR(MOVE_ROAR) \
TM_DECORATOR(MOVE_TOXIC) \
TM_DECORATOR(MOVE_HAIL) \
TM_DECORATOR(MOVE_BULK_UP) \
TM_DECORATOR(MOVE_BULLET_SEED) \
TM_DECORATOR(MOVE_HIDDEN_POWER) \
TM_DECORATOR(MOVE_SUNNY_DAY) \
TM_DECORATOR(MOVE_TAUNT) \
TM_DECORATOR(MOVE_ICE_BEAM) \
TM_DECORATOR(MOVE_BLIZZARD) \
TM_DECORATOR(MOVE_HYPER_BEAM) \
TM_DECORATOR(MOVE_LIGHT_SCREEN) \
TM_DECORATOR(MOVE_PROTECT) \
TM_DECORATOR(MOVE_RAIN_DANCE) \
TM_DECORATOR(MOVE_GIGA_DRAIN) \
TM_DECORATOR(MOVE_SAFEGUARD) \
TM_DECORATOR(MOVE_FRUSTRATION) \
TM_DECORATOR(MOVE_SOLAR_BEAM) \
TM_DECORATOR(MOVE_IRON_TAIL) \
TM_DECORATOR(MOVE_THUNDERBOLT) \
TM_DECORATOR(MOVE_THUNDER) \
TM_DECORATOR(MOVE_EARTHQUAKE) \
TM_DECORATOR(MOVE_RETURN) \
TM_DECORATOR(MOVE_DIG) \
TM_DECORATOR(MOVE_PSYCHIC) \
TM_DECORATOR(MOVE_SHADOW_BALL) \
TM_DECORATOR(MOVE_BRICK_BREAK) \
TM_DECORATOR(MOVE_DOUBLE_TEAM) \
TM_DECORATOR(MOVE_REFLECT) \
TM_DECORATOR(MOVE_SLUDGE_WAVE) \
TM_DECORATOR(MOVE_FLAMETHROWER) \
TM_DECORATOR(MOVE_SLUDGE_BOMB) \
TM_DECORATOR(MOVE_SANDSTORM) \
TM_DECORATOR(MOVE_FIRE_BLAST) \
TM_DECORATOR(MOVE_ROCK_TOMB) \
TM_DECORATOR(MOVE_AERIAL_ACE) \
TM_DECORATOR(MOVE_TORMENT) \
TM_DECORATOR(MOVE_FACADE) \
TM_DECORATOR(MOVE_SECRET_POWER) \
TM_DECORATOR(MOVE_REST) \
TM_DECORATOR(MOVE_ATTRACT) \
TM_DECORATOR(MOVE_THIEF) \
TM_DECORATOR(MOVE_STEEL_WING) \
TM_DECORATOR(MOVE_SKILL_SWAP) \
TM_DECORATOR(MOVE_SLEEP_TALK) \
TM_DECORATOR(MOVE_OVERHEAT) \
TM_DECORATOR(MOVE_ROOST) \
TM_DECORATOR(MOVE_FOCUS_BLAST) \
TM_DECORATOR(MOVE_ENERGY_BALL) \
TM_DECORATOR(MOVE_PSYSHOCK) \
TM_DECORATOR(MOVE_SCALD) \
TM_DECORATOR(MOVE_LEECH_LIFE) \
TM_DECORATOR(MOVE_CHARGE_BEAM) \
TM_DECORATOR(MOVE_ENDURE) \
TM_DECORATOR(MOVE_DRAGON_PULSE) \
TM_DECORATOR(MOVE_DRAIN_PUNCH) \
TM_DECORATOR(MOVE_WILL_O_WISP) \
TM_DECORATOR(MOVE_ACROBATICS) \
TM_DECORATOR(MOVE_ROCK_SLIDE) \
TM_DECORATOR(MOVE_EXPLOSION) \
TM_DECORATOR(MOVE_SHADOW_CLAW) \
TM_DECORATOR(MOVE_PAYBACK) \
TM_DECORATOR(MOVE_RECYCLE) \
TM_DECORATOR(MOVE_GIGA_IMPACT) \
TM_DECORATOR(MOVE_ROCK_POLISH) \
TM_DECORATOR(MOVE_AURORA_VEIL) \
TM_DECORATOR(MOVE_STONE_EDGE) \
TM_DECORATOR(MOVE_VOLT_SWITCH) \
TM_DECORATOR(MOVE_THUNDER_WAVE) \
TM_DECORATOR(MOVE_GYRO_BALL) \
TM_DECORATOR(MOVE_SWORDS_DANCE) \
TM_DECORATOR(MOVE_STEALTH_ROCK) \
TM_DECORATOR(MOVE_STRUGGLE_BUG) \
TM_DECORATOR(MOVE_BULLDOZE) \
TM_DECORATOR(MOVE_FREEZE_DRY) \
TM_DECORATOR(MOVE_VENOSHOCK) \
TM_DECORATOR(MOVE_X_SCISSOR) \
TM_DECORATOR(MOVE_DRAGON_TAIL) \
TM_DECORATOR(MOVE_FLAME_CHARGE) \
TM_DECORATOR(MOVE_POISON_JAB) \
TM_DECORATOR(MOVE_DREAM_EATER) \
TM_DECORATOR(MOVE_GRASS_KNOT) \
TM_DECORATOR(MOVE_SMACK_DOWN) \
TM_DECORATOR(MOVE_LOW_SWEEP) \
TM_DECORATOR(MOVE_U_TURN) \
TM_DECORATOR(MOVE_SUBSTITUTE) \
TM_DECORATOR(MOVE_FLASH_CANNON) \
TM_DECORATOR(MOVE_TRICK_ROOM) \
TM_DECORATOR(MOVE_WILD_CHARGE) \
TM_DECORATOR(MOVE_SUCKER_PUNCH) \
TM_DECORATOR(MOVE_SNARL) \
TM_DECORATOR(MOVE_AVALANCHE) \
TM_DECORATOR(MOVE_DARK_PULSE) \
TM_DECORATOR(MOVE_FALSE_SWIPE) \
TM_DECORATOR(MOVE_DAZZLING_GLEAM) \
TM_DECORATOR(MOVE_CURSE) \
TM_DECORATOR(MOVE_CUT) \
TM_DECORATOR(MOVE_FLY) \
TM_DECORATOR(MOVE_SURF) \
TM_DECORATOR(MOVE_STRENGTH) \
TM_DECORATOR(MOVE_FLASH) \
TM_DECORATOR(MOVE_ROCK_SMASH) \
TM_DECORATOR(MOVE_WATERFALL) \
TM_DECORATOR(MOVE_DIVE)

#define TM_ENUM(tm) TM_ENUM_##tm
#define TM_DECORATOR(tm) TM_ENUM(tm),

typedef enum
{
    ALL_TMS
    TM_COUNT
} TmHmEnum;

#undef TM_DECORATOR

#define TM_BIT_FIELD(tm) TM_FIELD_##tm
#define TM_DECORATOR(tm) bool8 TM_BIT_FIELD(tm):1;

struct TmHmStruct
{
    ALL_TMS
};

union TmHmUnion
{
    u32 bits[(TM_COUNT + 31) / 32];
    struct TmHmStruct fields;
};

#undef TM_DECORATOR

extern const u16 gTmMoveMapping[];

#define ALL_TUTORS \
TUTOR_DECORATOR(MOVE_PSYCHIC_FANGS) \
TUTOR_DECORATOR(MOVE_GRASS_PLEDGE) \
TUTOR_DECORATOR(MOVE_FIRE_PLEDGE) \
TUTOR_DECORATOR(MOVE_WATER_PLEDGE) \
TUTOR_DECORATOR(MOVE_FRENZY_PLANT) \
TUTOR_DECORATOR(MOVE_BLAST_BURN) \
TUTOR_DECORATOR(MOVE_HYDRO_CANNON) \
TUTOR_DECORATOR(MOVE_DRACO_METEOR) \
TUTOR_DECORATOR(MOVE_DRAGON_ASCENT) \
TUTOR_DECORATOR(MOVE_SECRET_SWORD) \
TUTOR_DECORATOR(MOVE_RELIC_SONG) \
TUTOR_DECORATOR(MOVE_FURY_CUTTER) \
TUTOR_DECORATOR(MOVE_ROLLOUT) \
TUTOR_DECORATOR(MOVE_SEISMIC_TOSS) \
TUTOR_DECORATOR(MOVE_COVET) \
TUTOR_DECORATOR(MOVE_VACUUM_WAVE) \
TUTOR_DECORATOR(MOVE_SHOCK_WAVE) \
TUTOR_DECORATOR(MOVE_BUG_BITE) \
TUTOR_DECORATOR(MOVE_AIR_CUTTER) \
TUTOR_DECORATOR(MOVE_SWIFT) \
TUTOR_DECORATOR(MOVE_SNATCH) \
TUTOR_DECORATOR(MOVE_MIMIC) \
TUTOR_DECORATOR(MOVE_MUD_SLAP) \
TUTOR_DECORATOR(MOVE_METRONOME) \
TUTOR_DECORATOR(MOVE_OMINOUS_WIND) \
TUTOR_DECORATOR(MOVE_SUPER_FANG) \
TUTOR_DECORATOR(MOVE_COUNTER) \
TUTOR_DECORATOR(MOVE_SIGNAL_BEAM) \
TUTOR_DECORATOR(MOVE_DEFOG) \
TUTOR_DECORATOR(MOVE_MAGIC_COAT) \
TUTOR_DECORATOR(MOVE_GRAVITY) \
TUTOR_DECORATOR(MOVE_SEED_BOMB) \
TUTOR_DECORATOR(MOVE_DYNAMIC_PUNCH) \
TUTOR_DECORATOR(MOVE_VOLT_TACKLE) \
TUTOR_DECORATOR(MOVE_SYNTHESIS) \
TUTOR_DECORATOR(MOVE_PAIN_SPLIT) \
TUTOR_DECORATOR(MOVE_UPROAR) \
TUTOR_DECORATOR(MOVE_HONE_CLAWS) \
TUTOR_DECORATOR(MOVE_ENDEAVOR) \
TUTOR_DECORATOR(MOVE_WORRY_SEED) \
TUTOR_DECORATOR(MOVE_PSYCH_UP) \
TUTOR_DECORATOR(MOVE_THUNDER_PUNCH) \
TUTOR_DECORATOR(MOVE_FIRE_PUNCH) \
TUTOR_DECORATOR(MOVE_ICE_PUNCH) \
TUTOR_DECORATOR(MOVE_ICY_WIND) \
TUTOR_DECORATOR(MOVE_ELECTROWEB) \
TUTOR_DECORATOR(MOVE_LOW_KICK) \
TUTOR_DECORATOR(MOVE_IRON_DEFENSE) \
TUTOR_DECORATOR(MOVE_MAGNET_RISE) \
TUTOR_DECORATOR(MOVE_TAILWIND) \
TUTOR_DECORATOR(MOVE_ZEN_HEADBUTT) \
TUTOR_DECORATOR(MOVE_DUAL_CHOP) \
TUTOR_DECORATOR(MOVE_BODY_SLAM) \
TUTOR_DECORATOR(MOVE_BRINE) \
TUTOR_DECORATOR(MOVE_SWAGGER) \
TUTOR_DECORATOR(MOVE_IRON_HEAD) \
TUTOR_DECORATOR(MOVE_SOFT_BOILED) \
TUTOR_DECORATOR(MOVE_LAST_RESORT) \
TUTOR_DECORATOR(MOVE_ROLE_PLAY) \
TUTOR_DECORATOR(MOVE_DRILL_RUN) \
TUTOR_DECORATOR(MOVE_TRICK) \
TUTOR_DECORATOR(MOVE_AQUA_TAIL) \
TUTOR_DECORATOR(MOVE_SKY_ATTACK) \
TUTOR_DECORATOR(MOVE_FOUL_PLAY) \
TUTOR_DECORATOR(MOVE_DOUBLE_EDGE) \
TUTOR_DECORATOR(MOVE_BOUNCE) \
TUTOR_DECORATOR(MOVE_HEAL_BELL) \
TUTOR_DECORATOR(MOVE_SUPERPOWER) \
TUTOR_DECORATOR(MOVE_HELPING_HAND) \
TUTOR_DECORATOR(MOVE_HEAT_WAVE) \
TUTOR_DECORATOR(MOVE_OUTRAGE) \
TUTOR_DECORATOR(MOVE_KNOCK_OFF) \
TUTOR_DECORATOR(MOVE_LIQUIDATION) \
TUTOR_DECORATOR(MOVE_HYPER_VOICE) \
TUTOR_DECORATOR(MOVE_EARTH_POWER) \
TUTOR_DECORATOR(MOVE_GUNK_SHOT) \
TUTOR_DECORATOR(MOVE_AURA_SPHERE) \
TUTOR_DECORATOR(MOVE_THROAT_CHOP) \
TUTOR_DECORATOR(MOVE_GASTRO_ACID) \
TUTOR_DECORATOR(MOVE_POWER_GEM) \
TUTOR_DECORATOR(MOVE_HURRICANE) \
TUTOR_DECORATOR(MOVE_HYDRO_PUMP) \
TUTOR_DECORATOR(MOVE_RAZOR_SHELL) \
TUTOR_DECORATOR(MOVE_CRUNCH) \
TUTOR_DECORATOR(MOVE_MYSTICAL_FIRE) \
TUTOR_DECORATOR(MOVE_MEGAHORN) \
TUTOR_DECORATOR(MOVE_BATON_PASS) \
TUTOR_DECORATOR(MOVE_LEAF_BLADE) \
TUTOR_DECORATOR(MOVE_DRAGON_DANCE) \
TUTOR_DECORATOR(MOVE_CLOSE_COMBAT) \
TUTOR_DECORATOR(MOVE_TOXIC_SPIKES) \
TUTOR_DECORATOR(MOVE_FLARE_BLITZ) \
TUTOR_DECORATOR(MOVE_BUG_BUZZ) \
TUTOR_DECORATOR(MOVE_BRAVE_BIRD) \
TUTOR_DECORATOR(MOVE_LEAF_STORM) \
TUTOR_DECORATOR(MOVE_POWER_WHIP) \
TUTOR_DECORATOR(MOVE_PLAY_ROUGH) \
TUTOR_DECORATOR(MOVE_NASTY_PLOT) \
TUTOR_DECORATOR(MOVE_HEAT_CRASH) \
TUTOR_DECORATOR(MOVE_STORED_POWER) \
TUTOR_DECORATOR(MOVE_BLAZE_KICK) \
TUTOR_DECORATOR(MOVE_ENCORE) \
TUTOR_DECORATOR(MOVE_SOLAR_BLADE) \
TUTOR_DECORATOR(MOVE_PIN_MISSILE) \
TUTOR_DECORATOR(MOVE_REVERSAL) \
TUTOR_DECORATOR(MOVE_SELF_DESTRUCT) \
TUTOR_DECORATOR(MOVE_REVENGE) \
TUTOR_DECORATOR(MOVE_WEATHER_BALL) \
TUTOR_DECORATOR(MOVE_ICICLE_SPEAR) \
TUTOR_DECORATOR(MOVE_MUD_SHOT) \
TUTOR_DECORATOR(MOVE_ROCK_BLAST) \
TUTOR_DECORATOR(MOVE_ICE_FANG) \
TUTOR_DECORATOR(MOVE_FIRE_FANG) \
TUTOR_DECORATOR(MOVE_THUNDER_FANG) \
TUTOR_DECORATOR(MOVE_JAGGED_FANGS) \
TUTOR_DECORATOR(MOVE_SHADOW_FANGS) \
TUTOR_DECORATOR(MOVE_PSYCHO_CUT) \
TUTOR_DECORATOR(MOVE_CROSS_POISON) \
TUTOR_DECORATOR(MOVE_HEX) \
TUTOR_DECORATOR(MOVE_DEFENSE_CURL) \
TUTOR_DECORATOR(MOVE_PHANTOM_FORCE) \
TUTOR_DECORATOR(MOVE_DRAINING_KISS) \
TUTOR_DECORATOR(MOVE_GRASSY_TERRAIN) \
TUTOR_DECORATOR(MOVE_ELECTRIC_TERRAIN) \
TUTOR_DECORATOR(MOVE_MISTY_TERRAIN) \
TUTOR_DECORATOR(MOVE_PSYCHIC_TERRAIN) \
TUTOR_DECORATOR(MOVE_AIR_SLASH) \
TUTOR_DECORATOR(MOVE_METEOR_MASH) \
TUTOR_DECORATOR(MOVE_AURORA_BEAM) \
TUTOR_DECORATOR(MOVE_QUIVER_DANCE) \
TUTOR_DECORATOR(MOVE_EXPANDING_FORCE) \
TUTOR_DECORATOR(MOVE_RISING_VOLTAGE) \
TUTOR_DECORATOR(MOVE_MISTY_EXPLOSION) \
TUTOR_DECORATOR(MOVE_GRASSY_GLIDE) \
TUTOR_DECORATOR(MOVE_TERRAIN_PULSE) \
TUTOR_DECORATOR(MOVE_SCALE_SHOT) \
TUTOR_DECORATOR(MOVE_METEOR_BEAM) \
TUTOR_DECORATOR(MOVE_POLTERGEIST) \
TUTOR_DECORATOR(MOVE_ICE_BALL) \
TUTOR_DECORATOR(MOVE_BABY_DOLL_EYES) \
TUTOR_DECORATOR(MOVE_FLIP_TURN) \
TUTOR_DECORATOR(MOVE_TRIPLE_AXEL) \
TUTOR_DECORATOR(MOVE_DUAL_WINGBEAT) \
TUTOR_DECORATOR(MOVE_SCORCHING_SANDS) \
TUTOR_DECORATOR(MOVE_SKITTER_SMACK) \
TUTOR_DECORATOR(MOVE_COACHING) \
TUTOR_DECORATOR(MOVE_BODY_PRESS) \
TUTOR_DECORATOR(MOVE_FOCUS_ENERGY) \
TUTOR_DECORATOR(MOVE_SPIKES) \
TUTOR_DECORATOR(MOVE_HIGH_HORSEPOWER) \
TUTOR_DECORATOR(MOVE_STOMPING_TANTRUM) \
TUTOR_DECORATOR(MOVE_INFESTATION) \
TUTOR_DECORATOR(MOVE_POWER_UP_PUNCH) \
TUTOR_DECORATOR(MOVE_AGILITY) \
TUTOR_DECORATOR(MOVE_TELEPORT) \

#define TUTOR_ENUM(tutor) TUTOR_ENUM_##tutor
#define TUTOR_DECORATOR(tutor) TUTOR_ENUM(tutor),

typedef enum
{
    ALL_TUTORS
    TUTOR_COUNT
} TutorEnum;

#undef TUTOR_DECORATOR

#define TUTOR_BIT_FIELD(tutor) TUTOR_FIELD_##tutor
#define TUTOR_DECORATOR(tutor) bool8 TUTOR_BIT_FIELD(tutor):1;

struct TutorStruct
{
    ALL_TUTORS
};

union TutorUnion
{
    u32 bits[(TUTOR_COUNT + 31) / 32];
    struct TutorStruct fields;
};

#undef TUTOR_DECORATOR

extern const u16 gTutorMoveMapping[];

u16 GetTmMove(u8 tmId);
u16 GetTutorMove(u8 tutorId);

#endif