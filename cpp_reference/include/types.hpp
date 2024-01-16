#ifndef __TYPES__
#define __TYPES__

#define SIZE_IN 1728

#define KERNEL_SIZE 3

// Convolution
#define NC_CONV1 3
#define NK_CONV1 64
#define IMG_SIZE_CONV1 24

#define NC_CONV2 64
#define NK_CONV2 32
#define IMG_SIZE_CONV2 12

#define NC_CONV3 32
#define NK_CONV3 20
#define IMG_SIZE_CONV3 6

// Maxpool
#define STRIDE 2

#define NC_MAXPOOL1 64
#define IMG_SIZE_MAXPOOL1_in 24
#define IMG_SIZE_MAXPOOL1_out 12

#define NC_MAXPOOL2 32
#define IMG_SIZE_MAXPOOL2_in 12
#define IMG_SIZE_MAXPOOL2_out 6

#define NC_MAXPOOL3 20
#define IMG_SIZE_MAXPOOL3_in 6
#define IMG_SIZE_MAXPOOL3_out 3

// Perceptron
#define NK_PERCEPTRON 10
#define IMG_SIZE_in_Perceptron 180
#define IMG_SIZE_out_Perceptron 10

// Reshape
#define NC_RESHAPE 20
#define IMG_SIZE_RESHAPE 3


#endif