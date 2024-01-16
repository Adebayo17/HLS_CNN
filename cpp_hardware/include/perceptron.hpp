#ifndef __PERCEPTRON__
#define __PERCEPTRON__

#include "types.hpp"

void PERCEPTRON_HARDWARE(
    d_type data_in[IMG_SIZE_in_Perceptron],
    d_type coeffs[NK_PERCEPTRON*IMG_SIZE_in_Perceptron],
    d_type biaises[NK_PERCEPTRON],
    d_type data_out[IMG_SIZE_out_Perceptron]
);



#endif