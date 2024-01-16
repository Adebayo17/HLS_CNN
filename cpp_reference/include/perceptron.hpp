#ifndef __PERCEPTRON__
#define __PERCEPTRON__

#include "types.hpp"

void PERCEPTRON_HARDWARE(
    double data_in[IMG_SIZE_in_Perceptron],
    double coeffs[NK_PERCEPTRON*IMG_SIZE_in_Perceptron],
    double biaises[NK_PERCEPTRON],
    double data_out[IMG_SIZE_out_Perceptron]
);



#endif