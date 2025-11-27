#ifndef __DSP_BASE_H__
#define __DSP_BASE_H__

/*  
    dsp/base.h
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

#endif
