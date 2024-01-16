#include "../include/top.hpp"

void TOP_0(
    int label_out[1]
) {
    int label_test[1];
    double img[SIZE_IN];
    CNN_HARDWARE(image_norm_4, label_test);
    std::cout << "label (in top) = " << label_test[0] << std::endl;
    label_out[0] = label_test[0];

}

void TOP_0_LABEL(
    double image_out[SIZE_IN],
    int label_out[1]
) {
    int label[1];
    double img[SIZE_IN];
    CNN_HARDWARE(image_norm_0, label);
    ADD_LABEL: for(int i=0; i<SIZE_IN; i++) {
        if( (i == 0) || (i == 576) || (i == 1152)) {
            image_out[i] = label[0];
        } else {
            image_out[i] = image_0[i];
        }
    }
    label_out[0] = label[0];
}


void TOP_10(
    int label_out[10]
) {
    for(int i=0; i<10; i++) {
        int label[1];
        CNN_HARDWARE(image_norm_array[i], label);
        label_out[i] = label[0];
    }
}

void TOP_10_LABEL(
    double images_out[10*SIZE_IN],
    int label_out[10]
) {
    for(int i=0; i<10; i++) {
        int label[1];
        double img[SIZE_IN];
        CNN_HARDWARE(image_norm_array[i], label);
        for(int j=0; j<SIZE_IN; j++) {
            if( (j == 0) || (j == 576) || (j == 1152)) {
                images_out[(i*SIZE_IN) + j] = label[0];
            } else {
                images_out[(i*SIZE_IN) + j] = image_array[i][j];
            }
        }
        label_out[i] = label[0];
    }
}

