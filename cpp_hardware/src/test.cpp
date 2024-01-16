#include <iostream>
#include "../include/top.hpp"
#include "mc_scverify.h"


CCS_MAIN(int argc, char **argv) {

    printf( "Start verification CNN_HARDWARE\n");
    l_type label[1];
    CCS_DESIGN(CNN_HARDWARE)(image_norm_0, label);
    std::cout << "Class detected = " << label[0].to_int() << std::endl;
    printf( "End verification CNN_HARDWARE\n");
    CCS_RETURN(0);

}

// g++ test.cpp top.cpp cnn.cpp convolution.cpp maxpool.cpp reshape.cpp perceptron.cpp -o test