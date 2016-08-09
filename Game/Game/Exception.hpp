#ifndef ___Class_Exception
#define ___Class_Exception

#include <iostream>
#include <string>

class Exception : public std::exception {
private:
	std::string file;
	int line;

public:
	Exception(const std::string& file, int line);
	~Exception() throw();
	const char* what() const throw();
	std::string getFile(void) const;
	int getLine(void) const;
};

inline Exception::Exception(const std::string& file, int line)
	: file(file), line(line)
{

}

inline Exception::~Exception() throw()
{

}

inline const char* Exception::what() const throw()
{
	std::string str;
	str += "\nfile : ";
	str += file;
	str += "\nline : ";
	str += std::to_string(line);
	return str.c_str();
}

inline std::string Exception::getFile(void) const
{
	return file;
}

inline int Exception::getLine(void) const
{
	return line;
}

#define Exception() Exception(__FILE__, __LINE__)

#endif

