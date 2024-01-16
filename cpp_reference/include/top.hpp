#ifndef __TOP__
#define __TOP__

#include "cnn.hpp"


void TOP_0(
    int label_out[1]
) ;

void TOP_0_LABEL(
    double image_out[SIZE_IN],
    int label_out[1]
) ;


void TOP_10(
    int label_out[10]
) ;

void TOP_10_LABEL(
    double images_out[10*SIZE_IN],
    int label_out[10]
) ;

#endif