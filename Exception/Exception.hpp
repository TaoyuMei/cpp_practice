#ifndef EXCEPTIONDEF
#define EXCEPTIONDEF

#include <string>
class Exception	{
	private:
		std::string mTag, mProblem;
	public:
		Exception(std::string tagString, std::string probString);
		void PrintDebug() const;
};

void ReadFile(const std::string& fileName, double x[], double y[]);

#endif //EXCEPTIONDEF
