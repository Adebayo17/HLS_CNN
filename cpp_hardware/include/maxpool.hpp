#ifndef __MAXPOOL__
#define __MAXPOOL__

#include "types.hpp"

#define MAXPOOL_MACRO(data_in, data_out, NC, IMG_SIZE_IN, IMG_SIZE_OUT, KERNEL_SIZE, STRIDE) \
    do { \
        int out_index = 0; \
        for (int nc = 0; nc < NC; nc++) { \
            for (int i = 0; i < IMG_SIZE_IN; i += STRIDE) { \
                for (int j = 0; j < IMG_SIZE_IN; j += STRIDE) { \
                    int index_start = (nc * IMG_SIZE_IN * IMG_SIZE_IN) + i  * IMG_SIZE_IN + j ; \
                    d_type max_val = data_in[index_start]; \
                    MAXPOOL: for (int m = 0; m < KERNEL_SIZE; m++) { \
                        for (int n = 0; n < KERNEL_SIZE; n++) { \
                            int current_index = index_start + m * IMG_SIZE_IN + n; \
                            d_type current_val; \
                            if(( (i + m) >= 0 && (i + m) < IMG_SIZE_IN) && ((j + n) >=0 && (j + n) < IMG_SIZE_IN)) { \
                                current_val = data_in[current_index]; \
                            } else { \
                                current_val = data_in[current_index - 1 - IMG_SIZE_IN]; \
                            } \
                            if (current_val > max_val) { \
                                max_val = current_val; \
                            } \
                        } \
                    } \
                    data_out[out_index] = max_val; \
                    out_index++; \
                } \
            } \
        } \
    } while (0)

void MAXPOOL_1_HARDWARE (
	d_type data_in[NC_MAXPOOL1*IMG_SIZE_MAXPOOL1_in*IMG_SIZE_MAXPOOL1_in],
    d_type data_out[NC_MAXPOOL1*IMG_SIZE_MAXPOOL1_out*IMG_SIZE_MAXPOOL1_out]
);

void MAXPOOL_2_HARDWARE (
	d_type data_in[NC_MAXPOOL2*IMG_SIZE_MAXPOOL2_in*IMG_SIZE_MAXPOOL2_in],
    d_type data_out[NC_MAXPOOL2*IMG_SIZE_MAXPOOL2_out*IMG_SIZE_MAXPOOL2_out]
);

void MAXPOOL_3_HARDWARE (
	d_type data_in[NC_MAXPOOL3*IMG_SIZE_MAXPOOL3_in*IMG_SIZE_MAXPOOL3_in],
    d_type data_out[NC_MAXPOOL3*IMG_SIZE_MAXPOOL3_out*IMG_SIZE_MAXPOOL3_out]
);


#endif