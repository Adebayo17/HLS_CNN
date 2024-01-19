#include <iostream>
#include "../include/top.hpp"

// Fonction pour imprimer un tableau 3D 
template <int N, int M, int P>
void printArray(double array[N][M][P]) {
    std::cout << "{";
    for (int i = 0; i < N; i++) {
        std::cout << "{";
        for (int j = 0; j < M; j++) {
            std::cout << "{";
            for (int k = 0; k < P; k++) {
                std::cout << array[i][j][k];
                if (k < P - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "}";
            if (j < M - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "}";
        if (i < N - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";
}

// Fonction pour imprimer un tableau 2D 
template <int N, int M>
void printArray2D(double array[N][M]) {
    std::cout << "{";
    for (int i = 0; i < N; i++) {
        std::cout << "{";
        for (int j = 0; j < M; j++) {
            std::cout << array[i][j];
            if (j < M - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "}\n\n";
        if (i < N - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";
}


// Fonction pour imprimer un tableau 1D 
template <int N>
void printArray(double array[N]) {
    std::cout << "{";
    for (int i = 0; i < N; ++i) {
        std::cout << array[i];
        std::cout << ", ";
    }
    std::cout << "}\n";
}


/*
void test_top_0();
void test_top_0_label();
void test_top_10();
void test_top_10_label();

void test_convolution_1(int choix);
void test_convolution_2();
void test_convolution_3();

void test_maxpool_1();
void test_maxpool_2();
void test_maxpool_3();

void test_perceptron();

void test_conv1_maxpool1(int choix);


int main(){
    //test_convolution_1(0);

    //test_convolution_1(1);

    //test_conv1_maxpool1(0);

    //test_conv1_maxpool1(1);

    test_top_0();

    test_top_10();
    
    return 0;
}

void test_top_0() {
    std::cout << "TOP_0 : START" << std::endl;
    int label[1];
    double img_out[SIZE_IN];
    TOP_0(label);
    std::cout << "Label for image 0 = " << label[0] << std::endl;
    std::cout << "TOP_0 : END" << std::endl;
}

void test_top_10() {
    int label_10[10];
    int count = 0;
    double true_detected[10] = {0};

    TOP_10(label_10);
    for(int i=0; i<10; i++){
        std::cout << "Label for image_" <<  i << " = " << label_10[i] << std::endl;
    }
    for(int i=0; i<10; i++) {
        if(label_10[i] == image_norm_labels[i]) {
            count++;
            true_detected[i] = (double)(i);
        }
    }
    std::cout << "Image true detected = " << count << std::endl << std::endl;
    printArray<10>(true_detected);
}

void test_convolution_1(int choix) {
    double data_out_1[NK_CONV1*IMG_SIZE_CONV1*IMG_SIZE_CONV1];
    if(choix == 0) {
        std::cout << "CONVOLUTION_1 (with original coeffs and biaises) : START" << std::endl;
        CONVOLUTION_1_HARDWARE(image_norm_0, conv1_coeff, conv1_biases, data_out_1);
        printArray<NK_CONV1*IMG_SIZE_CONV1*IMG_SIZE_CONV1>(data_out_1);
        std::cout << "CONVOLUTION_1 : END" << std::endl;
    } else {
        std::cout << "CONVOLUTION_1 : START" << std::endl;
        double data_in_1[NC_CONV1*IMG_SIZE_CONV1*IMG_SIZE_CONV1];
        double coeffs_1[NK_CONV1*NC_CONV1*KERNEL_SIZE*KERNEL_SIZE];
        double biaises_1[NK_CONV1];

        for(int i=0; i<NK_CONV1*NC_CONV1*KERNEL_SIZE*KERNEL_SIZE; i++) {
            coeffs_1[i] = 1.0 ;
        }

        for (int i=0;i<NK_CONV1;i++) {
            biaises_1[i] = 0.0 ;
        }

        for (int i=0; i<NC_CONV1*IMG_SIZE_CONV1*IMG_SIZE_CONV1; i++) {
            data_in_1[i] = 1.0 ;
        }

        CONVOLUTION_1_HARDWARE(data_in_1, coeffs_1, biaises_1, data_out_1);
        //printArray<NK_CONV1*IMG_SIZE_CONV1*IMG_SIZE_CONV1>(data_out_1);

        std::cout << "CONVOLUTION_1 : END" << std::endl;
    }
}

void test_conv1_maxpool1(int choix) {
    double data_out_1[NK_CONV1*IMG_SIZE_CONV1*IMG_SIZE_CONV1];
    if(choix == 0) {
        std::cout << "CONVOLUTION_1 (with original coeffs and biaises) : START" << std::endl;
        CONVOLUTION_1_HARDWARE(image_norm_0, conv1_coeff, conv1_biases, data_out_1);
        printArray<NK_CONV1*IMG_SIZE_CONV1*IMG_SIZE_CONV1>(data_out_1);
        std::cout << "CONVOLUTION_1 : END" << std::endl;
    } else {
        std::cout << "CONVOLUTION_1 : START" << std::endl;
        double data_in_1[NC_CONV1*IMG_SIZE_CONV1*IMG_SIZE_CONV1];
        double coeffs_1[NK_CONV1*NC_CONV1*KERNEL_SIZE*KERNEL_SIZE];
        double biaises_1[NK_CONV1];

        for(int i=0; i<NK_CONV1*NC_CONV1*KERNEL_SIZE*KERNEL_SIZE; i++) {
            coeffs_1[i] = 1.0 ;
        }

        for (int i=0;i<NK_CONV1;i++) {
            biaises_1[i] = 0.0 ;
        }

        for (int i=0; i<NC_CONV1*IMG_SIZE_CONV1*IMG_SIZE_CONV1; i++) {
            data_in_1[i] = 1.0 ;
        }

        CONVOLUTION_1_HARDWARE(data_in_1, coeffs_1, biaises_1, data_out_1);
        printArray<NK_CONV1*IMG_SIZE_CONV1*IMG_SIZE_CONV1>(data_out_1);

        std::cout << "CONVOLUTION_1 : END" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "MAXPOOL_1 : START" << std::endl;
    double maxpool1_out[NC_MAXPOOL1*IMG_SIZE_MAXPOOL1_out*IMG_SIZE_MAXPOOL1_out];
    MAXPOOL_1_HARDWARE(data_out_1, maxpool1_out);
    printArray<NC_MAXPOOL1*IMG_SIZE_MAXPOOL1_out*IMG_SIZE_MAXPOOL1_out>(maxpool1_out);
    std::cout << "MAXPOOL_1 : END" << std::endl;

}

*/

// g++ test.cpp top.cpp cnn.cpp convolution.cpp maxpool.cpp reshape.cpp perceptron.cpp -o test
// g++ top.cpp cnn.cpp convolution.cpp maxpool.cpp reshape.cpp perceptron.cpp -o test