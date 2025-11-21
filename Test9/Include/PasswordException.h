#ifndef PASSWORDEXCEPTION_H
#define PASSWORDEXCEPTION_H
#include <iostream>
#include <string>
#include "Exception.h"
class PasswordException: public Exception
{
public:
	static const int INVALID_LENGTH;
	static const int ALPHA_MISSING;
	static const int DIGIT_MISSING;
	static const int NO_PASSWORD;
private:
	int code;
public:
	PasswordException();
	PasswordException(int, string);
	void setCode(int);
	int getCode();
};
#endif