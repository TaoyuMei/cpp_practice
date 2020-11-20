#include "5_9.h"

void solve3by3(double **A, double *b , double *u){
    // solve the 3 by 3 linear system Au=b where A and b is known, u is unknown
    // A[3][3], b[3], u[3]
       
    // calculate the determinant of matrix A
    double det_A = A[0][0] * A[1][1] * A[2][2] + A[0][1] * A[1][2] * A[2][0] + A[0][2] * A[1][0] * A[2][1] 
                   - A[0][2] * A[1][1] * A[2][0] - A[0][1] * A[1][0] * A[2][2] - A[0][0] * A[1][2] * A[2][1];
    
    // calculate the inverse of A 
    double A_inv[3][3];  
    double C[3][3];  // A_inv = C / det_A
    C[0][0] = A[1][1] * A[2][2] - A[2][1] * A[1][2]; C[0][1] = A[2][1] * A[0][2] - A[0][1] * A[2][2]; C[0][2] = A[0][1] * A[1][2] - A[0][2] * A[1][1]; 
    C[1][0] = A[1][2] * A[2][0] - A[2][2] * A[1][0]; C[1][1] = A[2][2] * A[0][0] - A[0][2] * A[2][0]; C[1][2] = A[0][2] * A[1][0] - A[0][0] * A[1][2]; 
    C[2][0] = A[1][0] * A[2][1] - A[2][0] * A[1][1]; C[2][1] = A[2][0] * A[0][1] - A[0][0] * A[2][1]; C[2][2] = A[0][0] * A[1][1] - A[0][1] * A[1][0]; 

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            A_inv[i][j] = C[i][j] / det_A;
        }
    }

    // u = A-inv * b (not b * A_inv)
    for(int i=0; i<3; i++){
        double ij = 0.0;
        for(int k=0; k<3; k++){
            ij += A_inv[i][k] * b[k];
        }
        u[i] = ij;
    }

}