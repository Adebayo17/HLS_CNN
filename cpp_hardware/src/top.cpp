#include "../include/top.hpp"

#pragma hls_design top

void DispProcTest(
    l_type label_out[1]
) {
    CNN_HARDWARE(image_norm_0, label_out);
}


void DispProcTest(
    img_type image_out[],
    l_type label_out[1]
) {
    CNN_HARDWARE(image_norm_0, label_out);
}