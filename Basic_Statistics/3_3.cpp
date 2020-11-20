#include "3_3.h"
#include <fstream>
#include <cassert>

void implicit_Euler(int n){
    assert(n > 1);  // assert that the number of grid n > 1
    double yn = 1, interval_length = 1, h, xn;

    // calculate the step size h using the given value of n
    h = interval_length / n;
    
    std::ofstream write_output("xy.dat");
    assert(write_output.is_open());

    xn = 0 * h;
    write_output << xn << "," << yn << "\n";
    assert(write_output.good());

    for(int i=1; i<=n; i++){
        xn = i * h;
        yn = yn / (h + 1);
        write_output << xn << "," << yn << "\n";
        assert(write_output.good());

    }
    write_output.close();

}