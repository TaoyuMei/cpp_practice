#include <iostream>
#include "2_6.cpp"
#include "3_3.cpp"
#include "5_3.cpp"
#include "5_4.cpp"
#include "5_6.cpp"
#include "5_9.cpp"
#include "5_10.cpp"

int main(){
    // 2.6
    //newton_Raphson(0 , 1.0e-6);

    // 3.3
    //implicit_Euler(100);

    // 5.3
    /*
    double x=15, y=24;
    std::cout << "x=" << x << ", y=" << y << ";\n";
    swap_pointer(&x, &y);
    std::cout << "x=" << x << ", y=" << y << ";\n";
    swap_ref(x, y);
    std::cout << "x=" << x << ", y=" << y << ";\n";
    */

    //  5.4
    /*
    double a[6] = {1, 2, 3, 4, 5, 2.3};
    double b[4] = {10, 10, 10, 10};
    double c[1] = {4};

    double a_mean = calc_mean(a, 6);
    std::cout << "the mean of a is " << a_mean << "\n";
    double a_std = calc_std(a, 6);
    std::cout << "the std of a is " << a_std << "\n";

    double b_mean = calc_mean(b, 4);
    std::cout << "the mean of b is " << b_mean << "\n";
    double b_std = calc_std(b, 4);
    std::cout << "the std of b is " << b_std << "\n";

    double c_mean = calc_mean(c, 1);
    std::cout << "the mean of c is " << c_mean << "\n";
    double c_std = calc_std(c, 1);
    std::cout << "the std of c is " << c_std << "\n";
    */
    
    // 5.6
    /*
    double **AA = new double* [2];
    for(int i=0; i<2; i++){
        AA[i] = new double [3];
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            AA[i][j] = 8;
        }
    }

    double **BB = new double* [3];
    for(int i=0; i<3; i++){
        BB[i] = new double [2];
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<2; j++){
            BB[i][j] = 9;
        }
    }
    double **res1 = new double* [2];

    Multiply(res1, AA, BB, 2, 3, 3, 2);
    std::cout << **res1;
    delete[] res1;
    for(int i=0; i<3; i++){
        BB[i] = new double [2];
    }
    for(int i=0; i<3; i++){
        delete[] BB[i];
    }
    delete[] BB;

    for(int i=0; i<2; i++){
        delete[] AA[i];
    }
    delete[] AA;

    double AAA[3] = {1, 2, 3};
    double res2[2];
    Multiply(res2, AAA, BB, 3, 3, 2);

    double BBB[3] = {1, 2, 3};
    double res3[2];
    Multiply(res3, AA, BBB, 2, 3, 3);

    double res4[3][2];
    Multiply(res4, 6, BB, 3, 2);

    double res5[3][2];
    Multiply(res5, BB, 6, 3, 2);
    */
    
    // 5.9
    /*
    double **A = new double* [3];
    for(int i=0; i<3; i++){
        A[i] = new double [3];
    }
    A[0][0] = 5; A[0][1] = 1; A[0][2] = 3; 
    A[1][0] = 2; A[1][1] = 4; A[1][2] = 8; 
    A[2][0] = 5; A[2][1] = 6; A[2][2] = 24; 

    double *b;
    b = new double [3];
    b[0] = 15; b[1] = 22; b[2] = 81;

    double *u;
    u = new double [3];

    solve3by3(A, b, u);
    std::cout << u[0] << ",\n" << u[1] << ",\n" << u[2];

    for(int i=0; i<3; i++){
        delete[] A[i];
    }
    delete[] A;
    delete[] b;
    delete[] u;
    */

    // 5.10
    
    double **A = new double* [4];
    for(int i=0; i<4; i++){
        A[i] = new double [4];
    }
    A[0][0] = 0; A[0][1] = 1; A[0][2] = 3; A[0][3] = -5;
    A[1][0] = 2; A[1][1] = 4; A[1][2] = 8; A[1][3] = 9;
    A[2][0] = 5; A[2][1] = 6; A[2][2] = 24; A[2][3] = 13;
    A[3][0] = 14; A[3][1] = 15; A[3][2] = 16; A[3][3] = 17;

    double *b;
    b = new double [4];
    b[0] = 15; b[1] = 22; b[2] = 81; b[3] = 416;

    double *u;
    u = new double [4];

    //guassian_elimination(A, b, u, 3);
    //std::cout << u[0] << ",\n" << u[1] << ",\n" << u[2];

    guassian_elimination(A, b, u, 4);
    std::cout << u[0] << ",\n" << u[1] << ",\n" << u[2] << ",\n" << u[3];

    for(int i=0; i<4; i++){
        delete[] A[i];
    }
    delete[] A;
    delete[] b;
    delete[] u;
    

    return 0;
}