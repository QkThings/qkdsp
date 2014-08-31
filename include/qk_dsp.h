#ifndef QK_DSP_H
#define QK_DSP_H

/**
@mainpage QkDSP

Many sensor based applications require the use of DSP algorithms and in particular digital filters. They may be used for noise reduction but also to extract meaningful information from digital signals. Some implementations may be complex and require considerable computational power and memory. Hence, small and low power embedded systems presents some challenges due to their lack of processing power and scarce memory. As such, a library that makes digital filters easy to use and implement at the embedded level was implemented.

*/

#include "qk_avg.h"
#include "qk_fir.h"
#include "qk_iir.h"


#define QK_DSP_MULSS(a,b) (a*b)
//#define QK_DSP_MULSS(a,b) __builtin_mulss(a,b) // hack for Microchip microcontrollers

#endif
