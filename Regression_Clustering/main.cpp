#include<iostream>
#include "armadillo.hpp"
//#include "NearestNeighbours.cpp"
#include "LogisticRegression.cpp"


int main(){
    // test the #include armadillo linear algebra library itself
    arma::mat A = arma::randu<arma::mat>(5, 5)*10;
    A.print("matrix A = \n");
    A = 20 * A;
    A.print("matrix A = \n");

    A.row(1).print();
    A.row(2).print();
    std::cout << A.row(1).n_cols << "\n";

    double test = arma::accu(arma::square(A.row(1) - A.row(2)));
    std::cout << test << "\n";

    arma::mat B(A.n_cols, 1, arma::fill::ones);
    (A.row(1) * B).print();
    arma::mat C = A.row(1) * B;
    std::cout << C(0, 0) << "\n";
    B = B + 1;
    B.print();

    A.for_each([](arma::mat::elem_type& e){
        if(e>=0){
            e = 1;}
        else{e = -1;}
            });
    A.print();
    arma::mat D = A.row(1);
    D.reshape(5, 1); 
    D.print();

    // Nearest Neighbour
    //NearestNeighbours();

    // Logistic Regression
    LogisticRegression();

    return 0;
}