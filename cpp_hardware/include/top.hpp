#ifndef __TOP__
#define __TOP__

#include "cnn.hpp"
#include "overlays.hpp"


#define SIZE_OUT_0 320
#define SIZE_OUT_1 240

#define SIZE_OUT SIZE_OUT_0*SIZE_OUT_1

#define original_image_size 32

void DispProcTest(
    img_type img_out[SIZE_OUT]
    //int labels[10]
) ;


#endif