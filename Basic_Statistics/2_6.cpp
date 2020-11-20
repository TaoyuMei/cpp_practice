#include "2_6.h"
#include <iostream>
#include <cmath>

double newton_Raphson (double initialGuess , double epsilon){
    double x_prev, x_next, diff = 10;
    x_prev = initialGuess;
    while(diff > epsilon){
        x_next = x_prev - (exp(x_prev) + pow(x_prev, 3) - 5) / (exp(x_prev) + 3 * pow(x_prev, 2));
        diff = fabs(x_next - x_prev);
        std::cout << "xi = " << x_next << "\n";  // print the xi value after current iteration
        std::cout << "f(xi) = " <<  exp(x_next) + pow(x_next, 3) - 5 << "\n";  // a check on the xi
        x_prev = x_next;
    }
    return x_next;
}