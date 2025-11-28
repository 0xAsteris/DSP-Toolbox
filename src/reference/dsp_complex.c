#include "dsp/dsp_complex.h"

#include <math.h>

cplx_t cplx_make_pol(float r, float theta) {
    return (cplx_t){r * cosf(theta), r * sinf(theta)};
}

cplx_t cplx_make_uc(float theta) {
    return (cplx_t){cosf(theta), sinf(theta)};
}

// z1 / z2 --- implement Kahan's complex division algorithm
cplx_t cplx_div(cplx_t z1, cplx_t z2) {
    if (fabsf(z2.re) >= fabsf(z2.im)) {
        float r = z2.im / z2.re;
        float den = z2.re + z2.im * r;
        return (cplx_t){
            (z1.re + z1.im * r) / den,
            (z1.im - z1.re * r) / den
        };
    } else {
        float r = z2.re / z2.im;
        float den = z2.im + z2.re * r;
        return (cplx_t){
            (z1.re * r + z1.im) / den,
            (z1.im * r - z1.re) / den
        };
    }
}

float cplx_abs(cplx_t z) {
    return sqrtf(z.re * z.re + z.im * z.im);
}

float cplx_arg(cplx_t z) {
    return atan2f(z.im, z.re);
}         
// 1 / z --- implement Kahan's complex division algorithm
cplx_t cplx_inv(cplx_t z) {
    if (fabsf(z.re) >= fabsf(z.im)) {
        float r = z.im / z.re;
        float den = z.re + z.im * r;
        return (cplx_t){
            1.0f / den,
            -r / den
        };
    } else {
        float r = z.re / z.im;
        float den = z.im + z.re * r;
        return (cplx_t){
            r / den,
            -1.0f / den
        };
    }
}

