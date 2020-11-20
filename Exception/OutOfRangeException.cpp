//#ifndef SUBMISSION_OUTOFRANGEEXCEPTION_CPP_
//#define SUBMISSION_OUTOFRANGEEXCEPTION_CPP_

#include "OutOfRangeException.hpp"

// constructor
OutOfRangeException::OutOfRangeException(std::string prob) : Exception("FILE", prob){}

//#endif /* SUBMISSION_OUTOFRANGEEXCEPTION_CPP_ */