#include "Matrix2x2.hpp"
#include <iostream>

// 6.2.1 overridden default constructor setting all elements of the matrix to 0
Matrix2x2::Matrix2x2(){
    val00 = 0.0; // first row, first column
	val01 = 0.0; // first row, second column
	val10 = 0.0; // second row, first column
	val11 = 0.0; // second row, second column
}

// 6.2.2 overridden copy constructor
Matrix2x2::Matrix2x2(const Matrix2x2& other){
    val00 = other.Getval00();  // is 'other.val00' allowed?
	val01 = other.Getval01();
	val10 = other.Getval10();
	val11 = other.Getval11();
}

// 6.2.3 a constructor that specifies the matrix to [[a, b], [c, d]] (filled by row) 
Matrix2x2::Matrix2x2(double a, double b, double c, double d){
    val00 = a;
	val01 = b;
	val10 = c;
	val11 = d;
}

// 6.2.4 a method calculating the determinant of the matrix
double Matrix2x2::CalcDeterminant() const{
    return (val00 * val11 - val01 * val10);
}

// 6.2.5 a method calculating the inverse of the matrix
Matrix2x2 Matrix2x2::CalcInverse() const{
    if(CalcDeterminant() != 0){
        double inv00 = val11 / CalcDeterminant();
        double inv01 = -val01 / CalcDeterminant();
        double inv10 = -val10 / CalcDeterminant();
        double inv11 = val00 / CalcDeterminant();
        Matrix2x2 inverseMatrix(inv00, inv01, inv10, inv11);
        return inverseMatrix;
    }
    else{  // CalcDeterminant() == 0
        Matrix2x2 inverseMatrix(0, 0, 0, 0);  // when the inverse does not exist
        return inverseMatrix;
    }
}

// 6.2.6 overloading the assignment operator
Matrix2x2& Matrix2x2::operator=(const Matrix2x2& z){
    val00 = z.val00;
	val01 = z.val01;
	val10 = z.val10;
	val11 = z.val11;
    return *this;
}

// 6.2.7 overloading of the unary subtraction operator
Matrix2x2 Matrix2x2::operator-() const{
    Matrix2x2 w;
    w.val00 = -val00;
    w.val01 = -val01;
    w.val10 = -val10;
    w.val11 = -val11;
    return w;
}

// 6.2.8 overloading of the binary addition and subtraction operators
Matrix2x2 Matrix2x2::operator+(const Matrix2x2& z) const{
    Matrix2x2 w;
    w.val00 = val00 + z.val00;
    w.val01 = val01 + z.val01;
    w.val10 = val10 + z.val10;
    w.val11 = val11 + z.val11;
    return w;
}

Matrix2x2 Matrix2x2::operator-(const Matrix2x2& z) const{
    Matrix2x2 w;
    w.val00 = val00 - z.val00;
    w.val01 = val01 - z.val01;
    w.val10 = val10 - z.val10;
    w.val11 = val11 - z.val11;
    return w;
}

// 6.2.9 a method multiplying a matrix by a specified double precision floating point variable
void Matrix2x2::MultScalar(double scalar){
    val00 = scalar * val00;
    val01 = scalar * val01;
    val10 = scalar * val10;
    val11 = scalar * val11;
}

//non mandatory
void Matrix2x2::Print() const{
    std::cout << val00 << ", " << val01 << "\n";
    std::cout << val10 << ", " << val11 << "\n";
}
