#ifndef __TOP__
#define __TOP__

#include "cnn.hpp"
#include "overlays.hpp"


#define SIZE_OUT_0 320
#define SIZE_OUT_1 240

#define SIZE_OUT SIZE_OUT_0*SIZE_OUT_1

#define original_image_size 32

void DispProcTest(
    img_type image_out[SIZE_OUT]
) ;

/*
void DispProcTest(
    img_type image_out[SIZE_OUT*10]
) ;
*/

#endif