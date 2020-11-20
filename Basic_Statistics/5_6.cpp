#include "5_6.h"

void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols){
    // matrix * matrix = matrix, ACols = BRows
    for(int i=0; i<ARows; i++){  // each row of A
        for(int j=0; j<BCols; j++){  // each column of B
            double ij = 0.0;  // initialise an element in the resulting matrix
            for(int k=0; k<BRows; k++){
                ij += A[i][k] * B[k][j];
            }
            res[i][j] = ij;
        }
    }
}

void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols){
    // vector * matrix = vector, ACols = BRows
    for(int j=0; j<BCols; j++){  // each column of B
        double ij = 0.0;
        for(int k=0; k<BRows; k++){
            ij += A[k] * B[k][j];
        }
        res[j] = ij;
    }
}

void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows){
    // matrix * vector = vector, ACols = BRows
    for(int i=0; i<ARows; i++){
        double ij = 0.0;
        for(int k=0; k<ACols; k++){
            ij += A[i][k] * B[k];
        }
        res[i] = ij;
    }
}

void Multiply(double **res, double scalar, double **B, int BRows, int BCols){
    // scalar * matrix = matrix
    for(int i=0; i<BRows; i++){
        for(int j=0; j<BCols; j++){
            res[i][j] = scalar * B[i][j];
        }
    }
}

void Multiply(double **res, double **B, double scalar, int BRows, int BCols){
    // matrix * scalar = matrix
    for(int i=0; i<BRows; i++){
        for(int j=0; j<BCols; j++){
            res[i][j] = scalar * B[i][j];
        }
    }
}
