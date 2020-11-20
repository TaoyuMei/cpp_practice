#include "Exception.hpp"
#include "OutOfRangeException.cpp"
#include "FileNotOpenException.cpp" 
#include <iostream>
#include <fstream>

// specified constructor
Exception::Exception(std::string tagString, std::string probString){
    mTag = tagString;
    mProblem = probString;
}

void Exception::PrintDebug() const{
    std::cerr << "** Error ("<<mTag<<") **\n";
    std::cerr << "Problem: " << mProblem << "\n\n";
}


void ReadFile(const std::string& fileName, double x[], double y[]){
    try{
        std::ifstream read_file(fileName.c_str());

        if (read_file.is_open() == false){
            throw(FileNotOpenException("File can't be opened"));
        }
        for (int i=0; i<6; i++){
            if(read_file.eof() == true){
                read_file.close();
                throw(OutOfRangeException("Out of range of the file"));
            }
            read_file >> x[i] >> y[i];
        }
        read_file.close();

        std::cout << fileName <<" read successfully\n";
    }
    catch(Exception& error){
        error.PrintDebug();
        //std::cout << "Couldn’t open Output.dat\n";
        //std::cout << "Give alternative location\n";
        //std::string file_name;
        //std::cin >> file_name;
        //ReadFile(file_name, x, y);
    }
}
