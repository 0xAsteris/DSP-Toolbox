#ifndef __DSP_COMPLEX_SIGNAL_H__
#define __DSP_COMPLEX_SIGNAL_H__

/*  
    dsp/dsp_complex_signal.h
    complex signals header
*/

#ifdef __cplusplus
extern "C" {
#endif

#include "dsp/dsp_base.h"
#include "dsp/dsp_complex.h"
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t size;
    cplx_t* signal;
} signal_cplx_t;



#ifdef __cplusplus
}
#endif

#endif  // __DSP_COMPLEX_SIGNAL_H__