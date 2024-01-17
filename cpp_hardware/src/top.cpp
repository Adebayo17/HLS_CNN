#include "../include/top.hpp"

#pragma hls_design top

void DispProcTest(
    img_type image_out[SIZE_OUT]
) {
    l_type label[1];
    CNN_HARDWARE(image_norm_0, label);

    int indice_overlay = (label[0].to_int())*OVERLAY_0*OVERLAY_1;
    int indice_image = 0;

    lx: for(int x=0; x<SIZE_OUT_0; x++) {
        ly: for(int y=0; y<SIZE_OUT_1; y++) {
            if(x<OVERLAY_0 && y<OVERLAY_1) {
                image_out[x*SIZE_OUT_0 + y] = OVERLAYS_LIST[indice_overlay + x*OVERLAY_0 + y];
            }
            else {
                image_out[x*SIZE_OUT_0 + y] = image_0[indice_image*original_image_size + indice_image];
                indice_image++;
            }
        }
    }
}

/*
void DispProcTest(
    img_type image_out[SIZE_OUT*10]
) {
    GET_IMAGE: for(int i=0; i<10; i++) {
        l_type label[1];
        CNN_HARDWARE(image_norm_array[i], label);

        int indice_overlay = (label[0].to_int())*OVERLAY_0*OVERLAY_1;
        int indice_image = 0;

        lx: for(int x=0; x<SIZE_OUT_0; x++) {
            ly: for(int y=0; y<SIZE_OUT_1; y++) {
                if(x<OVERLAY_0 && y<OVERLAY_1) {
                    image_out[i*SIZE_OUT + x*SIZE_OUT_0 + y] = OVERLAYS_LIST[indice_overlay + x*OVERLAY_0 + y];
                }
                else {
                    image_out[i*SIZE_OUT + x*SIZE_OUT_0 + y] = image_array[i][indice_image*original_image_size + indice_image];
                    indice_image++;
                }
            }
        }
        for(int wait=0; wait<100; wait++){}
    }
}
*/