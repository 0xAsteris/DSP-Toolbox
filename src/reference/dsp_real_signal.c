#include "dsp/dsp_real_signal.h"

dsp_err_t rsig_alloc(rsig_t* s, size_t length) {
    if (!s) return DSP_ERR_NULL;
    if (length == 0) return DSP_ERR_SIZE;
    
    s->size = 0;
    s->signal = (float*)malloc(length * sizeof(float));
    if (!s->signal) return DSP_ERR_OOM;
    s->size = length;
    return DSP_OK;
}

dsp_err_t rsig_free(rsig_t* s) {
    if (!s) return DSP_ERR_NULL;

    free(s->signal);
    s->signal = NULL;
    s->size = 0;
    return DSP_OK;
}

dsp_err_t rsig_fill(rsig_t* s, float val) {
    if(!s || !s->signal) return DSP_ERR_NULL;

    float* p = s->signal;
    float* end = p + s->size;
    while (p < end) *p++ = val;
    return DSP_OK;
}

dsp_err_t rsig_copy(rsig_t* dest, rsig_t* src) {
    if (!dest || !dest->signal || !src || !src->signal) return DSP_ERR_NULL;
    if (src->size != dest->size) return DSP_ERR_SIZE;

    float* p = src->signal;
    float* end = p + src->size;
    float* q = dest->signal;
    while (p < end) *q++ = *p++;
    return DSP_OK;   
}

dsp_err_t rsig_zero_pad(rsig_t* s, size_t indx) {
    if (!s || !s->signal) return DSP_ERR_NULL;
    if (s->size <= indx) return DSP_ERR_SIZE;

    float* p = s->signal + indx;
    float* end = s->signal + s->size;
    while (p < end) *p++ = 0;
    return DSP_OK; 
} 

dsp_err_t rsig_add(rsig_t* dest, const rsig_t* s1, const rsig_t* s2) {
    if (!dest || !dest->signal || !s1 || !s1->signal || !s2 || !s2->signal) return DSP_ERR_NULL;
    if (s1->size != s2->size || s1->size != dest->size) return DSP_ERR_SIZE;

    float* p = s1->signal;
    float* end = p + s1->size;
    float* q = s2->signal;
    float* r = dest->signal;
    while (p < end) *r++ = *p++ + *q++;
    return DSP_OK;
}

dsp_err_t rsig_sub(rsig_t* dest, const rsig_t* s1, const rsig_t* s2) {
    if (!dest || !dest->signal || !s1 || !s1->signal || !s2 || !s2->signal) return DSP_ERR_NULL;
    if (s1->size != s2->size || s1->size != dest->size) return DSP_ERR_SIZE;

    float* p = s1->signal;
    float* end = p + s1->size;
    float* q = s2->signal;
    float* r = dest->signal;
    while (p < end) *r++ = *p++ - *q++;
    return DSP_OK;
}

dsp_err_t rsig_mul(rsig_t* dest, const rsig_t* s1, const rsig_t* s2) {
    if (!dest || !dest->signal || !s1 || !s1->signal || !s2 || !s2->signal) return DSP_ERR_NULL;
    if (s1->size != s2->size || s1->size != dest->size) return DSP_ERR_SIZE;

    float* p = s1->signal;
    float* end = p + s1->size;
    float* q = s2->signal;
    float* r = dest->signal;
    while (p < end) *r++ = *p++ * *q++;
    return DSP_OK;
}

dsp_err_t rsig_scale(rsig_t* dest, const rsig_t* s, float f) {
    if (!dest || !dest->signal || !s || !s->signal) return DSP_ERR_NULL;
    if (s->size != dest->size) return DSP_ERR_SIZE;

    float* p = s->signal;
    float* end = p + s->size;
    float* q = dest->signal;
    while (p < end) *q++ = *p++ * f;
    return DSP_OK;
}

dsp_err_t rsig_conv_direct(rsig_t* dest, const rsig_t* s1, const rsig_t* s2) {
    if (!dest || !dest->signal || !s1 || !s1->signal || !s2 || !s2->signal) return DSP_ERR_NULL;
    if (s1->size != s2->size) return DSP_ERR_SIZE;
    size_t conv_size = s1->size + s2->size - 1;
    if (dest->size != conv_size) return DSP_ERR_SIZE;

    float* p = s1->signal;
    float* q = s2->signal;
    float* r = dest->signal;
    float* end = dest->signal + dest->size;
    // to be continued
    return DSP_OK;
}