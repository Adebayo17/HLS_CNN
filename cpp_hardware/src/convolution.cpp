#include "../include/convolution.hpp"

#pragma hls_design inline

void CONVOLUTION_1_HARDWARE (
	d_type data_in[NC_CONV1*IMG_SIZE_CONV1*IMG_SIZE_CONV1],
    d_type coeffs[NK_CONV1*NC_CONV1*KERNEL_SIZE*KERNEL_SIZE],
    d_type biaises[NK_CONV1],
    d_type data_out[NK_CONV1*IMG_SIZE_CONV1*IMG_SIZE_CONV1]
) {
    CONVOLUTION_HARDWARE(1, data_in, coeffs, biaises, data_out);
}

void CONVOLUTION_2_HARDWARE (
	d_type data_in[NC_CONV2*IMG_SIZE_CONV2*IMG_SIZE_CONV2],
    d_type coeffs[NK_CONV2*NC_CONV2*KERNEL_SIZE*KERNEL_SIZE],
    d_type biaises[NK_CONV2],
    d_type data_out[NK_CONV2*IMG_SIZE_CONV2*IMG_SIZE_CONV2]
) {
    CONVOLUTION_HARDWARE(2, data_in, coeffs, biaises, data_out);
}

void CONVOLUTION_3_HARDWARE (
	d_type data_in[NC_CONV3*IMG_SIZE_CONV3*IMG_SIZE_CONV3],
    d_type coeffs[NK_CONV3*NC_CONV3*KERNEL_SIZE*KERNEL_SIZE],
    d_type biaises[NK_CONV3],
    d_type data_out[NK_CONV3*IMG_SIZE_CONV3*IMG_SIZE_CONV3]
) {
    CONVOLUTION_HARDWARE(3, data_in, coeffs, biaises, data_out);
}
