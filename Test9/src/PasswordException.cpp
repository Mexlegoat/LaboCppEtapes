#include "PasswordException.h"
const int PasswordException::INVALID_LENGTH = 0;
const int PasswordException::ALPHA_MISSING = 1;
const int PasswordException::DIGIT_MISSING = 2;
const int PasswordException::NO_PASSWORD = 3;
PasswordException::PasswordException(int c,string s):Exception(s)
{	
	setCode(c);
}
void PasswordException::setCode(int c)
{
	code = c;
}
int PasswordException::getCode()
{
	return code;
}