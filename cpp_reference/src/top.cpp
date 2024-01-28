#include "../include/top.hpp"
#include <iostream>

template <int N, int M>
void printArray2D(double array[N][M]);

template <int Rows, int Cols>
void convert1DTo2D(double array1D[], double array2D[Rows][Cols]);

void DispProcTest(
    double img_out[SIZE_OUT]
) {
    for(int i=0; i<10; i++) {
        int label[1];
        double image_norm_i[SIZE_IN];
        for(int select=0; select<SIZE_IN; select++) {
            image_norm_i[select] = image_norm_array[i*SIZE_IN + select];
        }

        CNN_HARDWARE(image_norm_i, label);

        int bits[4] = {0};

        bits[3] = (label[0] >> 3) & 1;  // msb
        bits[2] = (label[0] >> 2) & 1;
        bits[1] = (label[0] >> 1) & 1;
        bits[0] = label[0] & 1;         // lsb

        // Conversion sur 4 bits
        bits[3] = (label[0] / 8) % 2;   // Bit de poids fort
        bits[2] = (label[0] / 4) % 2;
        bits[1] = (label[0] / 2) % 2;
        bits[0] = label[0] % 2;         // Bit de poids faible

        for(int x=0; x<SIZE_OUT_0; x++) {
            for(int y=0; y<SIZE_OUT_1; y++) {
                if(y<60) {
                    img_out[x + y*SIZE_OUT_0] = bits[3]*255;
                }
                else if(60<=y && y<120) {
                    img_out[x + y*SIZE_OUT_0] = bits[2]*255;
                }
                else if(120<=y && y<180) {
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


int main() {
    printf( "Start verification CNN_HARDWARE\n\n");

    double image[SIZE_OUT];
    DispProcTest(image);

    printf( "\nEnd verification CNN_HARDWARE\n");

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////// FUNCTION IMPLEMENTATIONS //////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
        std::cout << "}";
        if (i < N - 1) {
            std::cout << ", \n ";
        }
    }
    std::cout << "}\n";
}

template <int Rows, int Cols>
void convert1DTo2D(double array1D[], double array2D[Rows][Cols]) {
    int index = 0;
    for (int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            array2D[i][j] = array1D[index++];
        }
    }
}

