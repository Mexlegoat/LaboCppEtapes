#include "XmlFileSerializerException.h"
const int XmlFileSerializerException::END_OF_FILE = 0;
const int XmlFileSerializerException::NOT_ALLOWED = 1;
const int XmlFileSerializerException::FILE_NOT_FOUND = 2;
XmlFileSerializerException::XmlFileSerializerException()
{
	code = 0;
}
XmlFileSerializerException::XmlFileSerializerException(int c, string msg):Exception(msg)
{
	setCode(c);
}
void XmlFileSerializerException::setCode(int c)
{
	code = c;
}
int XmlFileSerializerException::getCode() const
{
	return code;
}