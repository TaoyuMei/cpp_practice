#include "5_4.h"
#include <cmath>

double calc_mean(double a[], int length){
    // calculate the mean of an array of double precision floating point numbers
    double sum = 0.0;
    for(int i=0; i<length; i++){
        sum += a[i];
    }
    double mean = sum / ((double)(length));
    return mean;
}

double calc_std(double a[], int length){
    // calculate the standard deviation of an array of double precision floating point numbers
    if(length == 1){
        return 0;
    }
    else{
        double mean = calc_mean(a, length);
        double square_sum = 0.0;
        for(int i=0; i<length; i++){
            square_sum += pow((a[i] - mean), 2);
        }
        double std = sqrt(square_sum / (((double)(length)) - 1));
        return std;
    }
}