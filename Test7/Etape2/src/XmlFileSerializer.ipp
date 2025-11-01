#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

#include "XmlFileSerializerException.h"
using namespace std;
template <typename T>
const char XmlFileSerializer<T>::WRITE = 'w';
template <typename T>
const char XmlFileSerializer<T>::READ = 'r';
template <typename T>
XmlFileSerializer<T>::XmlFileSerializer(const string& fn, const char m, const string& cn)
{
	filename = fn;
	mode = m;
	collectionName = cn;
	if (isWritable())
	{
		file.open(getFilename(), ios::out);
		if(!file.is_open())
		{
			throw XmlFileSerializerException(XmlFileSerializerException::FILE_NOT_FOUND, "Fichier introuvable");
		}
		file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
		file << "<" << getCollectionName() << ">" << endl;
	}
	if (isReadable())
	{
		file.open(getFilename(), ios::in);
		if(!file.is_open())
		{
			throw XmlFileSerializerException(XmlFileSerializerException::FILE_NOT_FOUND, "Fichier introuvable");
		}
		string line;
		getline(file, line);
		getline(file, line); // On recupere le <collectionName> dans line
		line = line.substr(1, line.length() - 2); // on enleve les "< >"
		collectionName = line;
	}
}

template <typename T>
string XmlFileSerializer<T>::getCollectionName() const
{
	return collectionName;
}
template <typename T>
string XmlFileSerializer<T>::getFilename() const
{
	return filename;
}
template <typename T>
bool XmlFileSerializer<T>::isReadable()
{
	if (mode == READ)
	{
		return true;
	}
	return false;
}
template <typename T>
bool XmlFileSerializer<T>::isWritable()
{
	if (mode == WRITE)
	{
		return true;
	}
	return false;
}

template <typename T>
void XmlFileSerializer<T>::write(const T& var)
{
	if (isReadable())
	{
		throw(XmlFileSerializerException(XmlFileSerializerException::NOT_ALLOWED, "Ecriture en mode lecture impossible!"));
	}
	file << var << endl;
}
template <typename T>
T XmlFileSerializer<T>::read()
{
	if (isWritable())
	{
		throw(XmlFileSerializerException(XmlFileSerializerException::NOT_ALLOWED, "Lecture en mode ecriture impossible!"));
	}
	string line;
	streampos pos = file.tellg();
	string end = "</" + getCollectionName() + ">";
	file >> line;
	if (line == end)
	{
		throw(XmlFileSerializerException(XmlFileSerializerException::END_OF_FILE, "Lecture de la fin du fichier!"));
	}
	file.seekg(pos);
	T type;
	file >> type;
	return type;
}
template <typename T>
XmlFileSerializer<T>::~XmlFileSerializer()
{
	file << "</" << getCollectionName() << ">" << endl;
	file.close();
}