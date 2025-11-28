#include "dsp/dsp_complex.h"
#include <stdio.h>

int main(void) {
    cplx_t z1 = cplx_make(1.0f, 2.0f);
    cplx_t z2 = cplx_make_pol(3.2f, DSP_PI / 4.0f);
    cplx_t z3 = cplx_make_uc(DSP_PI / 3.0f);
    
    cplx_t z4 = cplx_add(z1, z2);      // z1 + z2
    cplx_t z5 = cplx_mul(z2, z3);      // z2 * z3
    cplx_t z6 = cplx_inv(z2);          // 1 / z2
    
    float arg3 = cplx_arg(z3);         // arg(z3)
    float abs2 = cplx_abs(z2);         // |z2|
    
    printf("z1 + z2 = %f + %fj\n"
        "z2 * z3 = %f + %fj\n"
        "1 / z2 = %f + %fj\n"
        "arg(z3) = %f (rad)\n"
        "abs(z2) = %f\n",
        z4.re, z4.im, z5.re, z5.im, z6.re, z6.im, arg3, abs2);
}