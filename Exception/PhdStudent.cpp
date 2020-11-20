#include "PhdStudent.hpp"
#include <string>

// constructor to specifies the name and time of the PhD student
PhdStudent::PhdStudent(std::string name, double fines, double fees, bool fullTime){
    PhdStudent::name = name;
    PhdStudent::fullTime = fullTime;
    tuition_fees = 0;
    SetLibraryFines(0);
}

// method to calculate the money owned by the PhD student
double PhdStudent::MoneyOwed() const{
    return 0;
}