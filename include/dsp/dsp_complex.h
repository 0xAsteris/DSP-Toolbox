#ifndef __DSP_COMPLEX_H__
#define __DSP_COMPLEX_H__

/*  
    dsp/dsp_complex.h
    basic complex arithmetic header
*/

#ifdef __cplusplus
extern "C" {
#endif

#include "dsp/dsp_base.h"

// complex type
typedef struct {
    float re;
    float im;
} comp_t;



// constructors
static inline comp_t c_make(float re, float im) {return (comp_t){re, im};}      // re + j * im
comp_t c_make_pol(float r, float theta);    // r * e ^ (j * theta)    
comp_t c_make_uc(float theta);              // on unit circle: e ^ (j * theta)



// constants
static inline comp_t c_0(void) {return (comp_t){0.0f, 0.0f};}   // 0 + j0
static inline comp_t c_1(void) {return (comp_t){1.0f, 0.0f};}   // 1 + j0
static inline comp_t c_j(void) {return (comp_t){0.0f, 1.0f};}   // 0 + j1



// complex operators
static inline comp_t c_add(comp_t z1, comp_t z2) {
    return (comp_t){z1.re + z2.re, z1.im + z2.im};
}   // z1 + z2

static inline comp_t c_sub(comp_t z1, comp_t z2) {
    return (comp_t){z1.re - z2.re, z1.im - z2.im};
}   // z1 - z2

static inline comp_t c_mul(comp_t z1, comp_t z2) {
    return (comp_t){
        z1.re * z2.re - z1.im * z2.im,
        z1.re * z2.im + z1.im * z2.re
    };
}   // z1 * z2

comp_t c_div(comp_t z1, comp_t z2);     // z1 / z2

static inline comp_t c_conj(comp_t z) {
    return (comp_t){z.re, -z.im};
}   // z*



// utilities
static inline float c_abs2(comp_t z) {
    return z.re * z.re + z.im * z.im;
}   // |z|^2

float c_abs(comp_t z);                  // |z|
float c_arg(comp_t z);                  // arg(z) (rad)
comp_t c_inv(comp_t z);                  // 1/z



#ifdef __cplusplus
}
#endif

#endif  // __DSP_COMPLEX_H__