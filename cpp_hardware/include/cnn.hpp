#ifndef __CNN__
#define __CNN__

#include "types.hpp"

#include "coeffs.hpp"
#include "biases.hpp"
#include "images_norm.hpp"

#include "convolution.hpp"
#include "maxpool.hpp"
#include "perceptron.hpp"
#include "reshape.hpp"

void CNN_HARDWARE(
    d_type img_in[SIZE_IN],
    l_type label_out[1]
);

#endif