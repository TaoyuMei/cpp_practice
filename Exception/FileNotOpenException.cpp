//#ifndef SUBMISSION_FILENOTOPENEXCEPTION_CPP_
//#define SUBMISSION_FILENOTOPENEXCEPTION_CPP_

#include "FileNotOpenException.hpp"

// constructor 
FileNotOpenException::FileNotOpenException(std::string prob) : Exception("FILE", prob){}

//#endif /* SUBMISSION_FILENOTOPENEXCEPTION_CPP_ */