#ifndef __DSP_REAL_SIGNAL_H__
#define __DSP_REAL_SIGNAL_H__

/*  
    dsp/dsp_real_signal.h
    real signals header
*/

#ifdef __cplusplus
extern "C" {
#endif

#include "dsp/dsp_base.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t size;
    float* signal;
} rsig_t;

// dynamic signal allocation
dsp_err_t rsig_alloc(rsig_t* s, size_t length);
dsp_err_t rsig_free(rsig_t* s);

// basic operation
dsp_err_t rsig_fill(rsig_t* s, float val);          // fill with constant value
dsp_err_t rsig_copy(rsig_t* dest, rsig_t* src);
dsp_err_t rsig_zero_pad(rsig_t* s, size_t indx);    // zero pads everything after (including) s[indx]

// elementwise operation
dsp_err_t rsig_add(rsig_t* dest, const rsig_t* s1, const rsig_t* s2);   // s1 + s2
dsp_err_t rsig_sub(rsig_t* dest, const rsig_t* s1, const rsig_t* s2);   // s1 - s2
dsp_err_t rsig_mul(rsig_t* dest, const rsig_t* s1, const rsig_t* s2);   // s1 * s2
dsp_err_t rsig_scale(rsig_t* dest, const rsig_t* s, float f);           // f * s

// s1 (convolve) s2 --- direct convolution
dsp_err_t rsig_conv_direct(rsig_t* dest, const rsig_t* s1, const rsig_t* s2); 

// dot product
dsp_err_t rsig_dot(float* dest, const rsig_t* s1, const rsig_t* s2);    // s1 \cdot s2

#ifdef __cplusplus
}
#endif

#endif  // __DSP_REAL_SIGNAL_H__