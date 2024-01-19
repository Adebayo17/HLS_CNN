#include "../include/perceptron.hpp"
#include <cmath>

double my_exp(double x) {
    double result = 1.0;
    double term = 1.0;

    for(int i=1; i<=30; i++) {
        term *= x/i;
        result += term;
    }
    return result;
}

void softmax(
    double data_in[IMG_SIZE_out_Perceptron] 
) {
    double max_val = data_in[0];
    double data_temp[IMG_SIZE_out_Perceptron];
    for(int i = 1; i < IMG_SIZE_out_Perceptron; i++) {
        max_val = (data_in[i] > max_val) ? data_in[i] : max_val;
    }

    double sum = 0;
    for(int i = 0; i < IMG_SIZE_out_Perceptron; i++) {
        double temp = my_exp(data_in[i] - max_val);
        sum += temp;
    }

    for(int i = 0; i < IMG_SIZE_out_Perceptron; i++) {
        data_temp[i] = my_exp(data_in[i] - max_val - sum);
    }

    for(int i = 0; i < IMG_SIZE_out_Perceptron; i++) {
        data_in[i] = data_temp[i];
    }
}


void PERCEPTRON_HARDWARE(
    double data_in[IMG_SIZE_in_Perceptron],
    double coeffs[NK_PERCEPTRON*IMG_SIZE_in_Perceptron],
    double biaises[NK_PERCEPTRON],
    double data_out[IMG_SIZE_out_Perceptron]
) {
    int sum = 0;
    for(int nk=0; nk<NK_PERCEPTRON; nk++) {
        data_out[nk] = biaises[nk];

        for(int i=0; i<IMG_SIZE_in_Perceptron; i++) {
            data_out[nk] +=  data_in[i] * coeffs[(nk * NK_PERCEPTRON) + i];
        }
    }

    SOFTMAX: softmax(data_out);
}
