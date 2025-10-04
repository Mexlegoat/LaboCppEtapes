#include "Option.h"
namespace carconfig
{
	// Constructeurs
	Option::Option()
	{
		code = new char[5];
		label = new char[30];
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
	// Destructeur
	Option::~Option()
	{
		cout << "Destructeur";
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
		strcpy(code, c);
	}
	void Option::setLabel(const char* l)
	{
		strcpy(label, l);
	}
	void Option::setPrice(float l)
	{
		price = l;
	}
	// Getters
}