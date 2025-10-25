#include "Exception.h"

Exception::Exception()
{
	message = "Erreur: ";
}
Exception::Exception(string s)
{
	setMsg(s);
}
void Exception::setMsg(string s)
{
	message = s;
}
string Exception::getMsg() const
{
	return message;
}