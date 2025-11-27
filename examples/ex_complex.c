#include "dsp/dsp_complex.h"
#include <stdio.h>

int main(void) {
    comp_t z1 = c_make(1.0f, 2.0f);
    comp_t z2 = c_make_pol(3.2f, DSP_PI / 4.0f);
    comp_t z3 = c_make_uc(DSP_PI / 3.0f);
    
    comp_t z4 = c_add(z1, z2);      // z1 + z2
    comp_t z5 = c_mul(z2, z3);      // z2 * z3
    comp_t z6 = c_inv(z2);          // 1 / z2
    
    float arg3 = c_arg(z3);         // arg(z3)
    float abs2 = c_abs(z2);         // |z2|
    
    printf("z1 + z2 = %f + j%f\n"
        "z2 * z3 = %f + j%f\n"
        "1 / z2 = %f + j%f\n"
        "arg(z3) = %f (rad)\n"
        "abs(z2) = %f\n",
        z4.re, z4.im, z5.re, z5.im, z6.re, z6.im, arg3, abs2);
}