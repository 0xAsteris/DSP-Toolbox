#ifndef __DSP_BASE_H__
#define __DSP_BASE_H__

/*  
    dsp/dsp_base.h
    core constants and macros shared across the DSP toolkit.
*/

// fundamental constants 
#ifndef DSP_PI
#define DSP_PI 3.14159265358979323846f
#endif

#ifndef DSP_TAU
#define DSP_TAU (2.0f * DSP_PI)
#endif

#ifndef DSP_E
#define DSP_E  2.71828182845904523536f
#endif

// small epsilon for float comparisons 
#ifndef DSP_EPS
#define DSP_EPS 1e-7f
#endif

/* utility macros */
#define DSP_MIN(a,b) (( (a) < (b) ) ? (a) : (b))
#define DSP_MAX(a,b) (( (a) > (b) ) ? (a) : (b))
#define DSP_CLAMP(x,lo,hi) (DSP_MAX((lo), DSP_MIN((x), (hi))))

typedef enum {
    DSP_OK = 0,
    DSP_ERR_BADARG = 1,     // unwanted argument
    DSP_ERR_NULL = 2,       // unwanted null pointer 
    DSP_ERR_SIZE = 3,       // size mismatch error
    DSP_ERR_OOM = 4,        // alloc fail
    DSP_ERR_RANGE = 5,      // legal range mismatch
    DSP_ERR_UNSUPPORTED = 6
} dsp_err_t;

#endif  // __DSP_BASE_H__
