#include "global.h"
#include "tmhm_struct.h"
#include "mgba_printf/mgba.h"

#define TM_DECORATOR(tm) [TM_ENUM(tm)] = tm,

const u16 gTmMoveMapping[TM_COUNT] =
{
    ALL_TMS
};

#undef TM_DECORATOR

#define TUTOR_DECORATOR(tutor) [TUTOR_ENUM(tutor)] = tutor,

const u16 gTutorMoveMapping[TUTOR_COUNT] =
{
    ALL_TUTORS
};

#undef TUTOR_DECORATOR

u16 GetTmMove(u8 tmId)
{
    return tmId >= TM_COUNT ? MOVE_NONE : gTmMoveMapping[tmId];
}

u16 GetTutorMove(u8 tutorId)
{
    return tutorId >= TUTOR_COUNT ? MOVE_NONE : gTutorMoveMapping[tutorId];
}