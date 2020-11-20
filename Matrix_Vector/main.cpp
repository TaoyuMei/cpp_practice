#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
// test the new templates
#include "Vector.hpp"
#include "Matrix.hpp"
#include "SparseVector.hpp"  // also include a "Vector()" which causes chaos

/*
// test the old templates
#include "Vector_o.hpp"
#include "Matrix_o.hpp"
// #include "SparseVector_o.hpp"   // also include a "Vector()" which causes chaos
*/

int main(){

    /*
    // *************** test the old Vector *******************

    // initialise to 0, with a given length
    Vector v1(3);
    std::cout << v1[0] << v1[1]  << v1[2] << "\n";

    // copy constructor
    v1[0] = 2.5; v1[1] = 4; v1[2] = 10.7;
    Vector v2(v1);
    std::cout << v1[0] << ", " << v1[1] << ", " << v1[2] << "\n";
    std::cout << v2[0] << ", " << v2[1] << ", " << v2[2] << "\n";

    // delete (destructor): automatically called at an appropriate point, no need to test

    // get size
    std::cout << v1.size() << "\n" << v2.size() << "\n";

    // get an element by v[i], read only: tested before

    // get an element by v[i], assign to it: tested before

    // assignment operator

    Vector v3(3);
    v3 = v1;
    std::cout << v3[0] << ", " << v3[1] << ", " << v3[2] << "\n";

    // overloading the unary - operator
    Vector v4(3);
    v4 = -v1;
    std::cout << v4[0] << ", " << v4[1] << ", " << v4[2] << "\n";

    // overloading the binary + operator
    v4 = v1 + v2;
    std::cout << v4[0] << ", " << v4[1] << ", " << v4[2] << "\n";

    // overloading the binary - operator
    v4 = v4 - v1;
    std::cout << v4[0] << ", " << v4[1] << ", " << v4[2] << "\n";

    // scalar multiplication (a scalar * a vector, return a vector, overriding the "*" operator)
    v4 = v4 * 3;  // 3 * v4 is not OK
    std::cout << v4[0] << ", " << v4[1] << ", " << v4[2] << "\n";

    // p-norm method (raise every element to the power of p, sum up, and raise to the power of 1/p)
    Vector v5(3);
    v5[0] = 1; v5[1] = 2; v5[2] = 3;
    std::cout << v5.CalculateNorm(3) << "\n";
    */

/*
    // ******* test the general property of std::vector *******
    std::vector<double> tv;
    std::cout << tv.size() << "\n";
    //tv.reserve(4);
    //std::cout << tv.size() << "\n";
    tv.push_back(2.5);
    //tv[3] = 2.5;
    std::cout << tv.size() << "\n";
    std::cout << tv[0] << "\n";   
    tv.erase(tv.begin(), tv.end());
    std::cout << tv.size() << "\n";

    std::vector<double> tv2(3);
    std::cout << tv2[0] << ", " << tv2[1] << ", " << tv2[2] << "\n";
    std::cout << tv2.size() << "\n";
    std::vector<double> tv3 = {4.5, 6.6, 9};
    tv2 = tv3;
    std::cout << tv2[0] << ", " << tv2[1] << ", " << tv2[2] << "\n";
    std::vector<double> tv4(10);
    tv4 = tv3;
    std::cout << tv4[0] << ", " << tv4[1] << ", " << tv4[2] << "\n";
    std::cout << tv4.size() << "\n";

    std::cout << (std::lower_bound(tv3.begin(), tv3.end(), 9) - tv3.begin()) << "\n";

    auto pos = std::lower_bound(tv3.begin(), tv3.end(), 9);
    tv3.insert(pos, 9);
    std::cout << tv3[0] << ", " << tv3[1] << ", " << tv3[2] << ", " << tv3[3] << "\n";
    std::cout << tv3.size() << "\n";
*/

/*
    // *************** test the new Vector *******************
    std::cout << "\n" << "Vector" << "\n";

    Vector<std::complex<double>> v1(3);
    std::cout << v1[0] << v1[1]  << v1[2] << "\n";

    // copy constructor; if the vector is Vector<int> type, the number assigned become int
    v1[0] = 2.5; v1[1] = 4; v1[2] = 10.7; 
    Vector<std::complex<double>> v2(v1);
    std::cout << v1[0] << ", " << v1[1] << ", " << v1[2] << "\n";
    std::cout << v2[0] << ", " << v2[1] << ", " << v2[2] << "\n";

    // delete (destructor): automatically called at an appropriate point, no need to test

    // get size
    std::cout << v1.size() << "\n" << v2.size() << "\n";

    // get an element by v[i], read only: tested before

    // get an element by v[i], assign to it: tested before

    // assignment operator

    Vector<std::complex<double>> v3(3);
    v3 = v1;
    std::cout << v3[0] << ", " << v3[1] << ", " << v3[2] << "\n";

    // overloading the unary - operator
    Vector<std::complex<double>> v4(3);
    v4 = -v1;
    std::cout << v4[0] << ", " << v4[1] << ", " << v4[2] << "\n";

    // overloading the binary + operator
    v4 = v1 + v2;
    std::cout << v4[0] << ", " << v4[1] << ", " << v4[2] << "\n";

    // overloading the binary - operator
    v4 = v4 - v1;
    std::cout << v4[0] << ", " << v4[1] << ", " << v4[2] << "\n";

    // scalar multiplication (a scalar * a vector, return a vector, overriding the "*" operator)
    v4 = v4 * 3;  // 3 * v4 is not OK
    std::cout << v4[0] << ", " << v4[1] << ", " << v4[2] << "\n";

    // p-norm method (raise every element to the power of p, sum up, and raise to the power of 1/p)
    Vector<std::complex<double>> v5(3);
    v5[0] = 1; v5[1] = 2; v5[2] = 3;
    std::cout << v5.CalculateNorm(3) << "\n";

    // test the newly added std::vector<T> const reference to mData
    std::cout << v4.getStorage()[0] << ", " << v4.getStorage()[1] << ", " << v4.getStorage()[2] << "\n";
*/

    /*
    // *************** test the old Matrix *******************
    // specify the nrow and ncol, fill a new matrix with 0
    Matrix m1(2, 3);
    std::cout << m1(0, 0) << ", " << m1(0, 1) << ", " << m1(0, 2) << "\n";
    std::cout << m1(1, 0) << ", " << m1(1, 1) << ", " << m1(1, 2) << "\n"; 

    // copy constructor
    Matrix m2(2, 3);
    m2(0, 0) = 2.6; m2(0, 1) = 3.7; m2(0, 2) = 10;
    m2(1, 0) = 2; m2(1, 1) = 50; m2(1, 2) = 6;

    Matrix m3(m2);

    std::cout << m2(0, 0) << ", " << m2(0, 1) << ", " << m2(0, 2) << "\n";
    std::cout << m2(1, 0) << ", " << m2(1, 1) << ", " << m2(1, 2) << "\n"; 

    std::cout << m3(0, 0) << ", " << m3(0, 1) << ", " << m3(0, 2) << "\n";
    std::cout << m3(1, 0) << ", " << m3(1, 1) << ", " << m3(1, 2) << "\n"; 

    // delete (destructor): automatically called at an appropriate point, no need to test

    // GetNumberOfRows()
    std::cout << m2.GetNumberOfRows() << "\n";

    // GetNumberOfColumns()
    std::cout << m2.GetNumberOfColumns() << "\n";

    // use m(i, j) to access the element, read only: tested above

    // use m(i, j) to access the element, assign value to it: tested above

    // overriding "=" to assign between matrices
    m1 = m2;
    std::cout << m1(0, 0) << ", " << m1(0, 1) << ", " << m1(0, 2) << "\n";
    std::cout << m1(1, 0) << ", " << m1(1, 1) << ", " << m1(1, 2) << "\n"; 

    // unary -
    m1 = -m1;
    std::cout << m1(0, 0) << ", " << m1(0, 1) << ", " << m1(0, 2) << "\n";
    std::cout << m1(1, 0) << ", " << m1(1, 1) << ", " << m1(1, 2) << "\n"; 

    // binary +
    m1 = m2 + m3;
    std::cout << m1(0, 0) << ", " << m1(0, 1) << ", " << m1(0, 2) << "\n";
    std::cout << m1(1, 0) << ", " << m1(1, 1) << ", " << m1(1, 2) << "\n"; 

    // binary -
    m1 = m1 - m2;
    std::cout << m1(0, 0) << ", " << m1(0, 1) << ", " << m1(0, 2) << "\n";
    std::cout << m1(1, 0) << ", " << m1(1, 1) << ", " << m1(1, 2) << "\n"; 

    // m * scalar
    m1 = m1 * 3;
    std::cout << m1(0, 0) << ", " << m1(0, 1) << ", " << m1(0, 2) << "\n";
    std::cout << m1(1, 0) << ", " << m1(1, 1) << ", " << m1(1, 2) << "\n"; 

    // matrix * vector = new_vector
    std::cout << "\n";
    Vector vt1(3);
    vt1[0] = 1; vt1[1] = 2; vt1[2] = 3;
    Vector vtr1(2);
    vtr1 = m1 * vt1;
    std::cout << vtr1[0] << ", " << vtr1[1] << "\n";

    // vector * matrix = new_vector
    Vector vt2(2);
    vt2[0] = 1; vt2[1] = 2;
    Vector vtr2(3);
    vtr2 = vt2 * m1;
    std::cout << vtr2[0] << ", " << vtr2[1] << ", " << vtr2[2] << "\n";
    */

    
    // *************** test the new Matrix *******************
    std::cout << "\n" << "Matrix" << "\n";

    // specify the nrow and ncol, fill a new matrix with 0
    Matrix<std::complex<double>> m1(2, 3);
    //std::cout << m1(0, 0) << ", " << m1(0, 1) << ", " << m1(0, 2) << "\n";
    //std::cout << m1(1, 0) << ", " << m1(1, 1) << ", " << m1(1, 2) << "\n"; 

    // copy constructor
    Matrix<std::complex<double>> m2(2, 3);
    m2(0, 0) = 2.6; m2(0, 1) = 3.7; m2(0, 2) = 10;
    m2(1, 0) = 2; m2(1, 1) = 50; m2(1, 2) = 6;

    Matrix<std::complex<double>> m3(m2);

    //std::cout << m2(0, 0) << ", " << m2(0, 1) << ", " << m2(0, 2) << "\n";
    //std::cout << m2(1, 0) << ", " << m2(1, 1) << ", " << m2(1, 2) << "\n"; 

    //std::cout << m3(0, 0) << ", " << m3(0, 1) << ", " << m3(0, 2) << "\n";
    //std::cout << m3(1, 0) << ", " << m3(1, 1) << ", " << m3(1, 2) << "\n"; 

    // delete (destructor): automatically called at an appropriate point, no need to test

    // GetNumberOfRows()
    //std::cout << m3.GetNumberOfRows() << "\n";

    // GetNumberOfColumns()
    //std::cout << m3.GetNumberOfColumns() << "\n";

    // use m(i, j) to access the element, read only: tested above

    // use m(i, j) to access the element, assign value to it: tested above

    // overriding "=" to assign between matrices
    m1 = m3;
    //std::cout << m1(0, 0) << ", " << m1(0, 1) << ", " << m1(0, 2) << "\n";
    //std::cout << m1(1, 0) << ", " << m1(1, 1) << ", " << m1(1, 2) << "\n"; 

    // unary -
    m1 = -m1;
    //std::cout << m1(0, 0) << ", " << m1(0, 1) << ", " << m1(0, 2) << "\n";
    //std::cout << m1(1, 0) << ", " << m1(1, 1) << ", " << m1(1, 2) << "\n"; 

    // binary +
    m1 = m2 + m3;
    //std::cout << m1(0, 0) << ", " << m1(0, 1) << ", " << m1(0, 2) << "\n";
    //std::cout << m1(1, 0) << ", " << m1(1, 1) << ", " << m1(1, 2) << "\n"; 

    // binary -
    m1 = m1 - m2;
    //std::cout << m1(0, 0) << ", " << m1(0, 1) << ", " << m1(0, 2) << "\n";
    //std::cout << m1(1, 0) << ", " << m1(1, 1) << ", " << m1(1, 2) << "\n"; 

    // m * scalar
    m1 = m1 * std::complex<double>(3);
    std::cout << m1(0, 0) << ", " << m1(0, 1) << ", " << m1(0, 2) << "\n";
    std::cout << m1(1, 0) << ", " << m1(1, 1) << ", " << m1(1, 2) << "\n"; 

    // matrix * vector = new_vector
    //std::cout << "\n";
    Vector<std::complex<double>> vt1(3);
    vt1[0] = 1; vt1[1] = 2; vt1[2] = 3;
    Vector<std::complex<double>> vtr1(2);
    vtr1 = m1 * vt1;
    //std::cout << vtr1[0] << ", " << vtr1[1] << "\n";

    // vector * matrix = new_vector
    Vector<std::complex<double>> vt2(2);
    vt2[0] = 1; vt2[1] = 2;
    Vector<std::complex<double>> vtr2(3);
    vtr2 = vt2 * m1;
    //std::cout << vtr2[0] << ", " << vtr2[1] << ", " << vtr2[2] << "\n";
    
    // test the newly added std::vector<T> const reference to mData
    //std::cout << m1.getStorage()[0] << ", " << m1.getStorage()[1] << ", " << m1.getStorage()[2] << "\n";
    //std::cout << m1.getStorage()[3] << ", " << m1.getStorage()[4] << ", " << m1.getStorage()[5] << "\n"; 


    // *************** test the new Sparse Vector *******************
    std::cout << "\n" << "Sparse Vector" << "\n";

    SparseVector<double> sv1;
    std::cout << sv1.size() << "\n";

    SparseVector<double> sv2(10);
    std::cout << sv2.size() << "\n";
    sv2.setValue(6, 2.75);
    std::cout << sv2.getValue(0) << ", " << sv2.getValue(6) << ", " << sv2.getValue(9) << "\n";
    sv2.setValue(6, 4.5);
    sv2.setValue(20, 10.3);
    std::cout << sv2.getValue(0) << ", " << sv2.getValue(6) << ", " << sv2.getValue(9) << ", " << sv2.getValue(20) << "\n";
    std::cout << sv2.size() << "\n";
    std::cout << sv2.nonZeroes() << "\n";
    std::cout << sv2.indexNonZero(1) << "\n";
    std::cout << sv2.valueNonZero(1) << "\n";

    SparseVector<double> sv3(21);
    sv3.setValue(6, 10);
    sv3.setValue(15, 3.65);

    sv2 = sv2 + sv3;
    std::cout << sv2.getValue(0) << ", " << sv2.getValue(6) << ", " << sv2.getValue(9) << ", " << sv2.getValue(15) << ", " << sv2.getValue(20) << "\n";
    sv2 = sv2 - sv3;
    std::cout << sv2.getValue(0) << ", " << sv2.getValue(6) << ", " << sv2.getValue(9) << ", " << sv2.getValue(15) << ", " << sv2.getValue(20) << "\n";

    // matrix * vector = new_vector
    std::cout << "\n";
    std::cout << m1(0, 0) << ", " << m1(0, 1) << ", " << m1(0, 2) << "\n";
    std::cout << m1(1, 0) << ", " << m1(1, 1) << ", " << m1(1, 2) << "\n"; 

    SparseVector<std::complex<double>> vtt1(3);
    vtt1.setValue(0, 4.5); vtt1.setValue(2, 11.2);
    Vector<std::complex<double>> vttr1(2);
    vttr1 = m1 * vtt1;
    std::cout << vttr1[0] << ", " << vttr1[1] << "\n";

    // vector * matrix = new_vector
    SparseVector<std::complex<double>> vtt2(2);
    vtt2.setValue(0, 2.2); 
    Vector<std::complex<double>> vttr2(3);
    vttr2 = vtt2 * m1;
    std::cout << vttr2[0] << ", " << vttr2[1] << ", " << vttr2[2] << "\n";

    // +=, -=
    std::cout << "+= & -=" << "\n";
    sv2 += sv3;
    std::cout << sv2.getValue(0) << ", " << sv2.getValue(6) << ", " << sv2.getValue(9) << ", " << sv2.getValue(15) << ", " << sv2.getValue(20) << "\n";
    sv2 -= sv3;
    std::cout << sv2.getValue(0) << ", " << sv2.getValue(6) << ", " << sv2.getValue(9) << ", " << sv2.getValue(15) << ", " << sv2.getValue(20) << "\n";
    SparseVector<double> sv4(21);
    sv4.setValue(0, 2.8);
    sv4.setValue(9, 7.3);
    sv2 += sv4;
    std::cout << sv2.getValue(0) << ", " << sv2.getValue(6) << ", " << sv2.getValue(9) << ", " << sv2.getValue(15) << ", " << sv2.getValue(20) << "\n";
    
    return 0;
}