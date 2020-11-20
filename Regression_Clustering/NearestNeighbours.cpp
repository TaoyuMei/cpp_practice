#include "armadillo.hpp"
#include <fstream>
#include <cassert>
#include <cmath>

int main(){  // change to main before submission
    // function declearations
    double CalculateDistance(arma::mat a, arma::mat b);
    arma::vec ExtractDistances(arma::mat r, arma::mat m);

    // read in files
    arma::Col<arma::sword> labelY;
    labelY.load("dataY.dat");
    arma::mat dataX;
    dataX.load("dataX.dat");
    arma::mat dataXtest;
    dataXtest.load("dataXtest.dat");
    
    // K-Nearest Neighbour Clustering, K = 5;
    arma::vec tmpDist(dataX.n_rows);
    arma::Col<arma::sword> fiveLabels(5);
    arma::Col<arma::sword> labelList(dataXtest.n_rows);

    for(int i=0; i<dataXtest.n_rows; i++){
        tmpDist = ExtractDistances(dataXtest.row(i), dataX);
        arma::uvec labelIndicex = sort_index(tmpDist);  // indices of distances, also of labels
        fiveLabels = labelY(labelIndicex.head(5));  // 5 labels with shortest distances
        if(arma::accu(fiveLabels) > 0){  // the majority is 1
            labelList(i) = 1;
        }
        else{  // arma::accu(fiveLabels) < 0, the majority is -1
            labelList(i) = -1;
        }
    }

    // write the classification result of the test set to a file
    labelList.save("NN.dat", arma::csv_ascii);
    return 0;
}

// function definitions

// a function to calculate the distance between 2 points (rows) of the same dimension
double CalculateDistance(arma::mat a, arma::mat b){
    assert(a.n_rows == 1);
    assert(b.n_rows == 1);
    assert(a.n_cols == b.n_cols);
    double dist = arma::accu(arma::square(a - b));  // element wise substraction and square, then sum up
    dist = sqrt(dist);
    return dist;
}

// a funciton to extract the distances between a given point and each points in a matrix, to a column vector
arma::vec ExtractDistances(arma::mat r, arma::mat m){
    assert(r.n_rows == 1);
    assert(r.n_cols == m.n_cols);
    std::vector<double> dists;
    for(int i=0; i<m.n_rows; i++){
        dists.push_back(CalculateDistance(r, m.row(i)));
    }
    arma::vec dists_c(dists);
    return dists_c;
}

