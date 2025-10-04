#include "Option.h"
namespace carconfig
{
	// Constructeurs
	Option::Option()
	{
		code = nullptr;
		label = nullptr;
		price = 0;
	}
	Option::Option(const char* c, const char* l, float p)
	{
		code = new char[strlen(c) + 1];
		strcpy(code, c);
		label = new char[strlen(l) + 1];
		strcpy(label, l);
		price = p;
	}
	Option::Option(const Option &source)
	{
		price = source.price;
		if (source.code != nullptr)
		{
			code = new char[strlen(source.code) + 1];
			strcpy(code, source.code);
		}
		else
		{
			code = nullptr;
		}
		if (source.label != nullptr)
		{
			label = new char[strlen(source.label) + 1];
			strcpy(label, source.label);
		}
		else
		{
			label = nullptr;
		}
		
	}
	// Destructeur
	Option::~Option()
	{
		cout << "[Option] Destructeur des variables: code et label" << endl;
		if (code != nullptr)
		{
			delete[] code;
		}
		if (label != nullptr)
		{
			delete[] label;
		}
	}
	// Affichage
	void Option::display()
	{
		cout << "Code: " << code << endl << "Nom: " << label << endl << "Prix: " << price << endl;
	}
	// Setters
	void Option::setCode(const char* c)
	{
		delete[] code;
		strcpy(code, c);
	}
	void Option::setLabel(const char* l)
	{
		delete[] label;
		strcpy(label, l);
	}
	void Option::setPrice(float l)
	{
		price = l;
	}
	// Getters
}