#include "../include/perceptron.hpp"

#pragma hls_design inline

void PERCEPTRON_HARDWARE(
    d_type data_in[IMG_SIZE_in_Perceptron],
    d_type coeffs[NK_PERCEPTRON*IMG_SIZE_in_Perceptron],
    d_type biaises[NK_PERCEPTRON],
    d_type data_out[IMG_SIZE_out_Perceptron]
) {
    a_type sum = 0;
    for(int nk=0; nk<NK_PERCEPTRON; nk++) {
        data_out[nk] = biaises[nk];

        for(int i=0; i<IMG_SIZE_in_Perceptron; i++) {
            data_out[nk] +=  data_in[i] * coeffs[(nk * NK_PERCEPTRON) + i];
        }
    }

}
