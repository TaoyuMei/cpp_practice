#include "GraduateStudent.hpp"
#include <string>

// override default constructor
GraduateStudent::GraduateStudent(){
    tuition_fees = 0;
}

// constructor that specifies the graduate student's name, library fines and time
GraduateStudent::GraduateStudent(std::string name, double fines, double fees, bool fullTime){
    GraduateStudent::name = name;
    SetLibraryFines(fines);
    GraduateStudent::fullTime = fullTime;
    tuition_fees = 0;
}

// method that calculates the money owened by the graduate student who does not pay tuition fees
double GraduateStudent::MoneyOwed() const{
    return GetLibraryFines();
}