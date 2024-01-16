#ifndef __RESHAPE__
#define __RESHAPE__

#include "types.hpp"

void RESHAPE(
    double data_in[NC_MAXPOOL3*IMG_SIZE_MAXPOOL3_out*IMG_SIZE_MAXPOOL3_out],
    double data_out[NC_MAXPOOL3*IMG_SIZE_MAXPOOL3_out*IMG_SIZE_MAXPOOL3_out]
);

#endif