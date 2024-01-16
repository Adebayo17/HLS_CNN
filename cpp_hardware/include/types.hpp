#ifndef __TYPES__
#define __TYPES__

#include "ac_fixed.h"
#include "ac_channel.h"

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

#define DATA_WIDTH 8
#define COEFF_WIDTH 8
#define LABEL_WIDTH 4

#define INT 4
#define HEADROOM 4

typedef ac_fixed<DATA_WIDTH,INT,true,AC_RND_INF,AC_SAT> d_type ;
typedef ac_fixed<COEFF_WIDTH,INT,true,AC_RND_INF,AC_SAT> c_type ;
typedef ac_fixed<DATA_WIDTH+COEFF_WIDTH+HEADROOM,DATA_WIDTH+HEADROOM+1,true> a_type ;

typedef ac_fixed<LABEL_WIDTH,LABEL_WIDTH,false,AC_RND_INF,AC_SAT> l_type ;
typedef ac_fixed<DATA_WIDTH,DATA_WIDTH,false,AC_RND_INF,AC_SAT> img_type ;

#endif