#include <iostream>
#include "ComplexNumber.cpp"  // 6.1.1-7
#include "CalculateExponential.cpp"  // 6.1.7
#include "Matrix2x2.cpp"  // 6.2 
#include "Student.cpp"  // 7.1
#include "GraduateStudent.cpp"  // 7.1
#include "PhdStudent.cpp"  // 7.1
#include "Exercise82.hpp"  // 8.2
#include "Exception.cpp"  // 9.1
#include "OutOfRangeException.cpp"  // 9.1
#include "FileNotOpenException.cpp"  // 9.1

int main(){
    
    /*
    // 6.1
    // 6.1.1
    ComplexNumber z(2.0, 6.0);
    std::cout << z << "\n";
    std::cout << z.GetImaginaryPart() << "\n";
    std::cout << z.GetRealPart() << "\n";

    // 6.1.2
    std::cout << RealPart(z) << "\n";
    std::cout << ImaginaryPart(z) << "\n";

    // 6.1.3
    ComplexNumber z_c(z);
    std::cout << z_c << "\n";

    // 6.1.4
    ComplexNumber z_r(10);
    std::cout << z_r << "\n";    

    // 6.1.5
    std::cout << z.CalculateConjugate() << "\n";

    // 6.1.6
    std::cout << z << "\n";
    z.SetConjugate();
    std::cout << z << "\n";

    //6.1.7
    //std::cout << z * z << "\n";
    
    ComplexNumber **A = new ComplexNumber* [3];
    ComplexNumber cpn(7, 35);
    for(int i=0; i<3; i++){
        A[i] = new ComplexNumber [3];
    }

    A[0][0] = ComplexNumber(2, 3);
    A[1][1] = ComplexNumber(4, 5);
    A[2][2] = ComplexNumber(6, 7);

    // each element in the res matrix is initialised to 0 + 0i
    ComplexNumber **res = new ComplexNumber* [3];
    for(int i=0; i<3; i++){
        res[i] = new ComplexNumber [3];
    }

    printMatrix(res, 3, 3);
    std::cout << "\n";
    CalculateExponential(A, 50, res);
    std::cout << "\n";
    printMatrix(A, 3, 3);
    std::cout << "\n";
    printMatrix(res, 3, 3);

    for(int i=0; i<3; i++){
        delete[] A[i];
    }
    delete[] A;

    for(int i=0; i<3; i++){
        delete[] res[i];
    }
    delete[] res;

    // 6.2
    // 6.2.1
    Matrix2x2 m1;
    m1.Print();

    // 6.2.2 & 3
    Matrix2x2 m2(1, 4.5, 3.9, 2);
    m2.Print();
    Matrix2x2 m3(m2);
    m3.Print();

    // 6.2.4
    std::cout << m2.CalcDeterminant() << "\n";

    // 6.2.5
    m2.CalcInverse().Print();

    // 6.2.6
    Matrix2x2 m4;
    m4 = m2;
    m4.Print();

    // 6.2.7
    (-m2).Print();  // cannot " write -m2.Print() " 

    // 6.2.8
    Matrix2x2 m5(2, 3, 5, 7), m6, m7;
    std::cout << "\n";
    m5.Print();
    m2.Print();
    m6 = m5 + m2;
    m6.Print();
    m7 = m5 - m2;
    m7.Print();

    // 6.2.9
    double scal = 2.5;
    m5.MultScalar(scal);
    m5.Print();

    // 7.1
    Student* taoyu1 = new Student("Taoyu Mei", 100, 55000);
    Student* taoyu2 = new GraduateStudent("Taoyu Mei", 100, 55000, 1);
    Student* taoyu3 = new PhdStudent("Taoyu Mei", 100, 55000, 1);

    std::cout << taoyu1 -> name << "\n";
    std::cout << taoyu2 -> name << "\n";
    std::cout << taoyu3 -> name << "\n";
    std::cout << "\n";

    std::cout << taoyu1 -> GetLibraryFines() << "\n";
    std::cout << taoyu2 -> GetLibraryFines() << "\n";
    std::cout << taoyu3 -> GetLibraryFines() << "\n";
    std::cout << "\n";

    std::cout << taoyu1 -> tuition_fees << "\n";
    std::cout << taoyu2 -> tuition_fees << "\n";
    std::cout << taoyu3 -> tuition_fees << "\n";
    std::cout << "\n";

    std::cout << taoyu1 -> MoneyOwed() << "\n";
    std::cout << taoyu2 -> MoneyOwed() << "\n";
    std::cout << taoyu3 -> MoneyOwed() << "\n";    
    std::cout << "\n";

    std::cout << taoyu1 -> fullTime << "\n";
    std::cout << taoyu2 -> fullTime << "\n";
    std::cout << taoyu3 -> fullTime << "\n";    
    std::cout << "\n";

    delete taoyu1;
    delete taoyu2;
    delete taoyu3;

    // 8.2
    int a = 5, b = -3;
    double c = 6.2, d = -10.8;
    std::cout << CalcAbs<int>(a) << "\n";
    std::cout << CalcAbs<int>(b) << "\n";
    std::cout << CalcAbs<double>(c) << "\n";
    std::cout << CalcAbs<double>(d) << "\n";
    std::cout << CalcAbs<double>(0.0) << "\n";
    std::cout << CalcAbs<int>(0) << "\n";
    */

    // 9.1
    double x[6], y[6];
    ReadFile("Output_shit.dat", x, y);
    
    return 0;
}