#include <iostream>
#include "../include/top.hpp"
#include "../ac_fixed/mc_scverify.h"


CCS_MAIN(int argc, char **argv) {
    img_type image[SIZE_OUT];
    printf( "Start verification CNN_HARDWARE\n");
    l_type label[1];
    CCS_DESIGN(DispProcTest)(image);
    printf( "End verification CNN_HARDWARE\n");
    CCS_RETURN(0);

}

// g++ test.cpp top.cpp cnn.cpp convolution.cpp maxpool.cpp reshape.cpp perceptron.cpp -o test