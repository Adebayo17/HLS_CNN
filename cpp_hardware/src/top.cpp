#include "../include/top.hpp"
#include <iostream>

#pragma hls_design top

void DispProcTest(
    img_type img_out[SIZE_OUT]
) {
    for(int i=0; i<10; i++) {
        l_type label[1];
        d_type image_norm_i[SIZE_IN];
        for(int select=0; select<SIZE_IN; select++) {
            image_norm_i[select] = image_norm_array[i*SIZE_IN + select];
        }

        CNN_HARDWARE(image_norm_i, label);

        int bits[4] = {0};

        bits[3] = (label[0].to_int() >> 3) & 1; 
        bits[2] = (label[0].to_int() >> 2) & 1;
        bits[1] = (label[0].to_int() >> 1) & 1;
        bits[0] = label[0].to_int() & 1;

        for(int x=0; x<SIZE_OUT_0; x++) {
            for(int y=0; y<SIZE_OUT_1; y++) {
                if(y<60) {
                    img_out[x + y*SIZE_OUT_0] = bits[3]*255;
                }
                else if(60<=y<120) {
                    img_out[x + y*SIZE_OUT_0] = bits[2]*255;
                }
                else if(120<=y<180) {
                    img_out[x + y*SIZE_OUT_0] = bits[1]*255;
                }
                else {
                    img_out[x + y*SIZE_OUT_0] = bits[0]*255;
                }
            }
        }

        std::cout << "Image "  << i << " processed. " << "Class detected = " << label[0] << " and the true class is = " << image_norm_labels[i] << " >> " << (label[0]==image_norm_labels[i]) << std::endl;     

        DELAY: for(int wait=0; wait<100; wait++){
            int delay = 10;
            while (delay > 0 )
            {
                delay--;
            }
            
        }
    }
}


