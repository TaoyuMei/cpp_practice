#include "CalculateExponential.hpp"
#include <iostream>

// 6.1.7

void MatricesMultiply(ComplexNumber **A, ComplexNumber **B, ComplexNumber ** res_tmp){
    // matrix * matrix, store the result in res
    for(int i=0; i<3; i++){  // each row of A
        for(int j=0; j<3; j++){  // each column of B
            ComplexNumber ij;  // initialise an element in the resulting matrix
            for(int k=0; k<3; k++){
                ij = ij + A[i][k] * B[k][j];  // cannot use "+="
            }
            res_tmp[i][j] = ij;
        }
    }
}

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res){
    // nMax >= 2
    // when n=0 and n=1
    ComplexNumber one(1, 0);
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i == j){  // elements on the diagonal should add 1, as the I is an identity matrix
                res[i][j] = res[i][j] + one + A[i][j];  // the initial value of res[i][j] must be 0+0i
            }
            else{
                res[i][j] = res[i][j] + A[i][j];
            }
        }
    }

    for(int n=2; n<nMax; n++){

        // calculate the factorial of n and 1/n! (as a complex number)
        double n_factorial = 1.0;
        for(int j=n; j>0; j--){
            n_factorial *= (double)(j);
        }
        ComplexNumber n_factorial_reciprocal(1 / n_factorial, 0);

        // calculate the A ^ n
        ComplexNumber **A_cumulate = new ComplexNumber* [3];
        for(int i=0; i<3; i++){
            A_cumulate[i] = new ComplexNumber [3];   
        }    
        ComplexNumber **res_tmp = new ComplexNumber* [3];
        for(int i=0; i<3; i++){
            res_tmp[i] = new ComplexNumber [3];   
        }

        MatricesMultiply(A, A, res_tmp);  // store the result to res_tmp
        for(int p=0; p<3; p++){  // cannot use **A_cumulate = **res_tmp;
            for(int q=0; q<3; q++){
                A_cumulate[p][q] = res_tmp[p][q];
            }
        }

        for(int i=0; i<3; i++){  // free the memory allocated dynamically to res_tmp
            delete[] res_tmp[i];
        }
        delete[] res_tmp;

        for(int i=0; i<(n-2); i++){
            if(n<3){  // when n = 2, quit this for loop, as A ^ 2 is already calculated
                break;
            }
            ComplexNumber **res_tmp = new ComplexNumber* [3];
            for(int i=0; i<3; i++){
                res_tmp[i] = new ComplexNumber [3];   
            }

            MatricesMultiply(A_cumulate, A, res_tmp);
            for(int p=0; p<3; p++){  // cannot use **A_cumulate = **res_tmp;
                for(int q=0; q<3; q++){
                    A_cumulate[p][q] = res_tmp[p][q];
                }
            }

            for(int i=0; i<3; i++){ 
                delete[] res_tmp[i];
            }
            delete[] res_tmp;
        }

        // calculate (A ^ n) / n! and add it to the res matrix
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                res[i][j] = res[i][j] + A_cumulate[i][j] * n_factorial_reciprocal; 
            }
        }

        for(int i=0; i<3; i++){ 
            delete[] A_cumulate[i];
        }
        delete[] A_cumulate;
    }

}

//non mandatory
void printMatrix(ComplexNumber **A, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            std::cout << A[i][j] << ",\t";
        }
        std::cout << "\n";
    }  
}