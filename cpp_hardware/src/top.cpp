#include "../include/top.hpp"

#pragma hls_design top

void TOP(
    l_type label_out[1]
) {
    CNN_HARDWARE(image_norm_0, label_out);
}
