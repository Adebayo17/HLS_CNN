#ifndef __CONVOLUTION__
#define __CONVOLUTION__

#include "types.hpp"
#include <iostream>

#define CONVOLUTION_MACRO(NK, NC, IMG_SIZE, KERNEL_SIZE, data_in, coeffs, biaises, data_out) \
    int index_out = 0; \
    int indice_img = 0; \
    int rowIndex = 0; \
    int colIndex = 0; \
    int indice_kernel = 0; \
    a_type conv_sum; \
    for(int nk=0; nk < (NK); nk++) { \
        for(int i=0; i< (IMG_SIZE); i++) { \
            for(int j=0; j < (IMG_SIZE); j++) { \
                conv_sum = biaises[nk]; \
                for(int nc=0; nc < (NC); nc++) { \
                    for(int r=-1; r<2; r++) { \
                        for(int c=-1; c<2; c++) { \
                            rowIndex = i + r; \
                            colIndex = j + c; \
                            indice_kernel = (KERNEL_SIZE)*(KERNEL_SIZE)*(nc + nk*(NC)) + (r+1)*KERNEL_SIZE + (c+1); \
                            indice_img = nc*(IMG_SIZE)*(IMG_SIZE) + rowIndex*(IMG_SIZE) + colIndex; \
                            if((rowIndex >=0 && rowIndex < (IMG_SIZE)) && (colIndex >=0 && colIndex < (IMG_SIZE))) { \
                                conv_sum += coeffs[indice_kernel] * data_in[indice_img];; \
                            } else { \
                                conv_sum += 0.0; \
                            } \
                        } \
                    } \
                } \
                RELU: if (conv_sum < 0) { \
                    conv_sum = 0; \
                } \
                data_out[index_out] = conv_sum; \
				index_out++; \
            } \
        } \
    }


#define CONVOLUTION_HARDWARE(layer, data_in, coeffs, biaises, data_out) \
    CONVOLUTION_MACRO(NK_CONV##layer, NC_CONV##layer, IMG_SIZE_CONV##layer, KERNEL_SIZE, data_in, coeffs, biaises, data_out)


void CONVOLUTION_1_HARDWARE (
	d_type data_in[NC_CONV1*IMG_SIZE_CONV1*IMG_SIZE_CONV1],
    d_type coeffs[NK_CONV1*NC_CONV1*KERNEL_SIZE*KERNEL_SIZE],
    d_type biaises[NK_CONV1],
    d_type data_out[NK_CONV1*IMG_SIZE_CONV1*IMG_SIZE_CONV1]
) ;

void CONVOLUTION_2_HARDWARE (
	d_type data_in[NC_CONV2*IMG_SIZE_CONV2*IMG_SIZE_CONV2],
    d_type coeffs[NK_CONV2*NC_CONV2*KERNEL_SIZE*KERNEL_SIZE],
    d_type biaises[NK_CONV2],
    d_type data_out[NK_CONV2*IMG_SIZE_CONV2*IMG_SIZE_CONV2]
) ;

void CONVOLUTION_3_HARDWARE (
	d_type data_in[NC_CONV3*IMG_SIZE_CONV3*IMG_SIZE_CONV3],
    d_type coeffs[NK_CONV3*NC_CONV3*KERNEL_SIZE*KERNEL_SIZE],
    d_type biaises[NK_CONV3],
    d_type data_out[NK_CONV3*IMG_SIZE_CONV3*IMG_SIZE_CONV3]
) ;




#endif