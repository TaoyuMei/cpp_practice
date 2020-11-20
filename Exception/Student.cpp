#include "Student.hpp"
#include <string>
#include <iostream>

// override default constructor
Student::Student(){
    fullTime = 1;
    library_fines = 0;
    tuition_fees = 0;
}

// constructor that specifies the student's name, library fines and tuition fees
Student::Student(std::string name, double fines, double fees){
    Student::name = name;
    if(fines<0){  // cannot just use assert
        fines = -fines;
    }
    library_fines = fines;
    tuition_fees = fees;
    fullTime = 1;
}

// method for setting the library fines to a nonnegative number
void Student::SetLibraryFines(double amount){
    if(amount<0){  // cannot just use assert
        amount = -amount;
    }
    library_fines = amount;
}

// method to access the library fines 
double Student::GetLibraryFines() const{
    return library_fines;
}

// method to calculate the money owned by the student
double Student::MoneyOwed() const{
    return (library_fines + tuition_fees);
}