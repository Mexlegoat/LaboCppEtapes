#ifndef XMLFILESERIALIZEREXCEPTION_H
#define XMLFILESERIALIZEREXCEPTION_H
#include <iostream>
#include <string>
#include "Exception.h"
class XmlFileSerializerException: public Exception
{
public:
	static const int NOT_ALLOWED;
	static const int FILE_NOT_FOUND;
	static const int END_OF_FILE;
private:
	int code;
public:
	XmlFileSerializerException();
	XmlFileSerializerException(int c, string);
	void setCode(int);
	int getCode() const;
};
#endif