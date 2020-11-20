#include "armadillo.hpp"
#include <cassert>
#include <cmath>

int main(){

    // read in files
    arma::mat labelY;
    labelY.load("dataY.dat");
    arma::mat dataX;
    dataX.load("dataX.dat");
    arma::mat dataXtest;
    dataXtest.load("dataXtest.dat");

    // declearation of functions
    arma::mat CalculateGradient(arma::mat wT, arma::mat x, arma::mat y);
    double CalculateMagnitude(arma::mat grad);

    // gradient descendant
    double alpha = 0.5;
    double epsilon = 10;
    arma::mat wT(dataX.n_cols, 1, arma::fill::zeros);  // initial guess is a column of 0s

    while(epsilon > pow(10, -7)){
        arma::mat gradient = CalculateGradient(wT, dataX, labelY);
        wT = wT - (alpha * gradient);  // element-wise addition for wT
        epsilon = CalculateMagnitude(gradient);
    }

    // predict labels for dataXtest
    arma::mat testLabel = dataXtest * wT;
    testLabel.for_each([](arma::mat::elem_type& e){
        if(e>=0){
            e = 1;}
        else{e = -1;}
            });

    arma::imat testLabelInt = arma::conv_to<arma::imat>::from(testLabel);
    // out put the file
    testLabelInt.save("LogReg.dat", arma::csv_ascii);
    
    return 0;
}

// function definions

// calculate the gradient of L, return a column matrix
arma::mat CalculateGradient(arma::mat wT, arma::mat x, arma::mat y){
    assert(x.n_cols == wT.n_rows);
    assert(wT.n_cols == 1);
    assert(x.n_rows == y.n_rows);
    arma::mat tmpMultiplyMatrix(1, 1);
    arma::mat tmpOne(1, x.n_cols);
    arma::mat tmpSum(x.n_cols, 1, arma::fill::zeros);
    for(int i=0; i<x.n_rows; i++){
        tmpMultiplyMatrix = x.row(i) * wT; 
        tmpOne = y(i, 0) * (1 / (1 + exp(y(i, 0) * tmpMultiplyMatrix(0, 0)) ) ) * x.row(i);
        tmpOne.reshape(x.n_cols, 1);
        tmpSum = tmpSum + tmpOne;
    }
    arma::mat gL =  -tmpSum / x.n_rows;
    return gL;
}

// calculate the magnitude of gradient
double CalculateMagnitude(arma::mat grad){
    double sumOfSquare = arma::accu(arma::square(grad));
    double magnitude = sqrt(sumOfSquare);
    return magnitude;
}