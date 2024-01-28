#include "../include/cnn.hpp"
#include <iostream>


template <int N>
void printOutput(double array[N]) {
    std::cout << "{";
    for (int i = 0; i < N; ++i) {
        std::cout << array[i];
        std::cout << ", ";
    }
    std::cout << "}\n";
}


void CNN_HARDWARE(
    double img_in[SIZE_IN],
    int label_out[1]
) {
    double conv1_out[NK_CONV1*IMG_SIZE_CONV1*IMG_SIZE_CONV1];
    double maxpool1_out[NC_MAXPOOL1*IMG_SIZE_MAXPOOL1_out*IMG_SIZE_MAXPOOL1_out];

    double conv2_out[NK_CONV2*IMG_SIZE_CONV2*IMG_SIZE_CONV2];
    double maxpool2_out[NC_MAXPOOL2*IMG_SIZE_MAXPOOL2_out*IMG_SIZE_MAXPOOL2_out];

    double conv3_out[NK_CONV3*IMG_SIZE_CONV3*IMG_SIZE_CONV3];
    double maxpool3_out[NC_MAXPOOL3*IMG_SIZE_MAXPOOL3_out*IMG_SIZE_MAXPOOL3_out];

    double reshape_out[NC_MAXPOOL3*IMG_SIZE_MAXPOOL3_out*IMG_SIZE_MAXPOOL3_out];
    double perceptron_out[IMG_SIZE_out_Perceptron];

    CONVOLUTION_1: CONVOLUTION_1_HARDWARE(img_in, conv1_coeff, conv1_biases, conv1_out);

    MAXPOOL_1: MAXPOOL_1_HARDWARE(conv1_out, maxpool1_out);

    CONVOLUTION_2: CONVOLUTION_2_HARDWARE(maxpool1_out, conv2_coeff, conv2_biases, conv2_out);

    MAXPOOL_2: MAXPOOL_2_HARDWARE(conv2_out, maxpool2_out);

    CONVOLUTION_3: CONVOLUTION_3_HARDWARE(maxpool2_out, conv3_coeff, conv3_biases, conv3_out); 

    MAXPOOL_3: MAXPOOL_3_HARDWARE(conv3_out, maxpool3_out);

    RESHAPE: RESHAPE(maxpool3_out, reshape_out);

    PERCEPTRON: PERCEPTRON_HARDWARE(reshape_out, perceptron_coeff, perceptron_biases, perceptron_out);
    
    int indiceMax = 0;
    GET_LABEL: for(int i = 0; i<IMG_SIZE_out_Perceptron; i++) {
        if( perceptron_out[i] > perceptron_out[indiceMax] ) {
            indiceMax = i;
        }
    }

    label_out[0] = indiceMax;

}
