#include "../include/reshape.hpp"
#include <iostream>


void RESHAPE(
    double data_in[NC_MAXPOOL3*IMG_SIZE_MAXPOOL3_out*IMG_SIZE_MAXPOOL3_out],
    double data_out[NC_MAXPOOL3*IMG_SIZE_MAXPOOL3_out*IMG_SIZE_MAXPOOL3_out]
) {
    for (int i = 0; i < NC_MAXPOOL3; ++i) {
        for (int j = 0; j < IMG_SIZE_MAXPOOL3_out; j++) {
            for (int k = 0; k < IMG_SIZE_MAXPOOL3_out; k++) {
                int index_in = i * (IMG_SIZE_MAXPOOL3_out * IMG_SIZE_MAXPOOL3_out) + j * IMG_SIZE_MAXPOOL3_out + k;
                int index_out = j * (IMG_SIZE_MAXPOOL3_out * NC_MAXPOOL3) + k * NC_MAXPOOL3 + i;
                data_out[index_out] = data_in[index_in];
            }
        }
    }
}



