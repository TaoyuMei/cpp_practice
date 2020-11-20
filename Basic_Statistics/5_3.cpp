#include "5_3.h"

void swap_pointer(double *a, double *b){
    // swap the values of 2 double precision floating point variables using pointers
    double temp;
    temp = *a;  // de-reference the pointer and assign its content to temp
    *a = *b;
    *b = temp; 
}

void swap_ref(double &a, double &b){
    // swap the values of 2 double precision floating point variables using references
    double temp;
    temp = a;
    a = b;
    b = temp;
}