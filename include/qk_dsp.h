#ifndef QK_DSP_H
#define QK_DSP_H

#include "qk_avg.h"
#include "qk_fir.h"
#include "qk_iir.h"


#define QK_DSP_MULSS(a,b) (a*b)
//#define QK_DSP_MULSS(a,b) __builtin_mulss(a,b) // hack for Microchip microcontrollers

#endif
