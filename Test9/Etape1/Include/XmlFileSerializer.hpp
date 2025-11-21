#ifndef XMLFILESERIALIZER_H
#define XMLFILESERIALIZER_H

#include <fstream>
#include <string>
using namespace std;
template<typename T>
class XmlFileSerializer
{
public:
	static const char READ;
	static const char WRITE;
private:
	fstream file;
	string filename;
	char mode;
	string collectionName;
public:
	XmlFileSerializer() = delete;
	XmlFileSerializer(const string& fn, const char m, const string& cn = "entites");
	XmlFileSerializer(const XmlFileSerializer& fs) = delete;
	~XmlFileSerializer();

	bool isReadable();
	bool isWritable();

	string getCollectionName() const;
	string getFilename() const;

	void write(const T& var);
	T read();

	XmlFileSerializer<T> operator=(const XmlFileSerializer<T>& fs) = delete;
};
#include "XmlFileSerializer.ipp"
#endif