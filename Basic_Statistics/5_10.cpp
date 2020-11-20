#include "5_10.h"
#include <cmath>

void multiply_mm(double **res, double **M1, double **M2, int n){
    // multiply 2 n * n matrices M1 and M2
    for(int i=0; i<n; i++){  // each row of A
        for(int j=0; j<n; j++){  // each column of B
            double ij = 0.0;  // initialise an element in the resulting matrix
            for(int k=0; k<n; k++){
                ij += M1[i][k] * M2[k][j];
            }
            res[i][j] = ij;
        }
    }
}


void multiply_mv(double *res, double **M, double *V, int n){
    // matrix * vector
    for(int i=0; i<n; i++){
        double ij = 0.0;
        for(int k=0; k<n; k++){
            ij += M[i][k] * V[k];
        }
        res[i] = ij;
    }
}


void pivote(double **matr, int n, int c, double *b){
    // c is the current line i being processed (k outside), n is the total line and row numbers

    // find the index of the row beginning with the largest absolute value
    double val = fabs(matr[c][c]);
    int mi = c;
    for(int t=c+1; t<n; t++){
        if(fabs(matr[t][c]) > val){
            val = fabs(matr[t][c]);
            mi = t;
        }
    }
    if(mi != c){  // if the row beginning with the largest absolute value is not the current row
        double **P = new double* [n];
        for(int i=0; i<n; i++){
            P[i] = new double [n];
        }

        for(int i=0; i<n; i++){  // construct a pivoting matrix to interchange row c and row mi
            for(int j=0; j<n; j++){
                if((i==j && i!=c && j!=c && i!=mi && j!=mi) || (i==c && j==mi) || (i==mi && j==c)){
                    P[i][j] = 1;
                }
                else P[i][j] = 0;
            }
        }

        // pivote the matrix A
        double **matr_tmp = new double* [n];
        for(int i=0; i<n; i++){
            matr_tmp[i] = new double [n];
        }
        multiply_mm(matr_tmp, P, matr, n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matr[i][j] = matr_tmp[i][j];
            }
        }
        for(int i=0; i<n; i++){
            delete[] matr_tmp[i];
        }
        delete[] matr_tmp;

        // pivote the vector b
        double *b_tmp;
        b_tmp = new double [n];
        multiply_mv(b_tmp, P, b, n);
        for(int i=0; i<n; i++){b[i] = b_tmp[i];}
        delete[] b_tmp;

        for(int i=0; i<n; i++){
            delete[] P[i];
        }
        delete[] P;
    }

}


void guassian_elimination(double **A, double *b, double *u, int n){
    //the interface function

    // declare the coefficient ratio matrix M
    double **M = new double* [n];
    for(int i=0; i<n; i++){
        M[i] = new double [n];
    }
    
    for(int k=0; k<n-1; k++){  // each line in the original coefficient matrix A
        //pivote and test whether xxx = 0
        pivote(A, n, k, b);
        if(A[k][k]==0){continue;}

        for(int i=k+1; i<n; i++){  // each line below the current line i being processed
            M[i][k] = A[i][k] / A[k][k];
            for(int j=k+1; j<n; j++){
                A[i][j] = A[i][j] - M[i][k] * A[k][j];
            }
            b[i] = b[i] - M[i][k] * b[k];
            A[i][k] = 0;           
        }

    }  // now A becomes A^(N-1), b becomes b^(N-1)

    // calculate each x backward from the end
    u[n-1] = b[n-1] / A[n-1][n-1];
    for(int i=n-1; i>0; i--){
        double sigma = 0.0;
        for(int j=i; j<=n-1; j++){
            sigma += A[i-1][j] * u[j];
        }
        u[i-1] = (b[i-1] - sigma) / A[i-1][i-1];
    }
    
    // delete the matrix M after use
    for(int i=0; i<n; i++){
        delete[] M[i];
    }
    delete[] M;
}