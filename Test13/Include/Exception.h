#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Exception
{
protected:
	string message;

public:
	Exception();
	Exception(string);
	void setMsg(string);
	string getMessage() const;
};
#endif