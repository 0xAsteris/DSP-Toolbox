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
} cplx_t;



// constructors
static inline cplx_t cplx_make(float re, float im) {return (cplx_t){re, im};}      // re + j * im
cplx_t cplx_make_pol(float r, float theta);    // r * e ^ (j * theta)    
cplx_t cplx_make_uc(float theta);              // on unit circle: e ^ (j * theta)



// constants
static inline cplx_t cplx_0(void) {return (cplx_t){0.0f, 0.0f};}   // 0 + j0
static inline cplx_t cplx_1(void) {return (cplx_t){1.0f, 0.0f};}   // 1 + j0
static inline cplx_t cplx_j(void) {return (cplx_t){0.0f, 1.0f};}   // 0 + j1



// complex operators
static inline cplx_t cplx_add(cplx_t z1, cplx_t z2) {
    return (cplx_t){z1.re + z2.re, z1.im + z2.im};
}   // z1 + z2

static inline cplx_t cplx_sub(cplx_t z1, cplx_t z2) {
    return (cplx_t){z1.re - z2.re, z1.im - z2.im};
}   // z1 - z2

static inline cplx_t cplx_mul(cplx_t z1, cplx_t z2) {
    return (cplx_t){
        z1.re * z2.re - z1.im * z2.im,
        z1.re * z2.im + z1.im * z2.re
    };
}   // z1 * z2

cplx_t cplx_div(cplx_t z1, cplx_t z2);     // z1 / z2

static inline cplx_t cplx_conj(cplx_t z) {
    return (cplx_t){z.re, -z.im};
}   // z*



// utilities
static inline float cplx_abs2(cplx_t z) {
    return z.re * z.re + z.im * z.im;
}   // |z|^2

float cplx_abs(cplx_t z);                  // |z|
float cplx_arg(cplx_t z);                  // arg(z) (rad)
cplx_t cplx_inv(cplx_t z);                  // 1/z



#ifdef __cplusplus
}
#endif

#endif  // __DSP_COMPLEX_H__