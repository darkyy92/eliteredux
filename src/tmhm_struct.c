#include "global.h"
#include "tmhm_struct.h"

#define TM_DECORATOR(tm) [TM_ENUM(tm)] = tm,

EWRAM_DATA const u16 gTmMoveMapping[TM_COUNT] =
{
    ALL_TMS
};

#undef TM_DECORATOR

#define TUTOR_DECORATOR(tutor) [TUTOR_ENUM(tutor)] = tutor,

EWRAM_DATA const u16 gTutorMoveMapping[TUTOR_COUNT] =
{
    ALL_TUTORS
};

#undef TUTOR_DECORATOR

u16 GetTmMove(u8 tmId)
{
    return tmId >= TM_COUNT ? MOVE_NONE : gTmMoveMapping[tmId];
}