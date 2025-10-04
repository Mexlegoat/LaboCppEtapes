#include "Option.h"
namespace carconfig
{
	// Constructeurs
	Option::Option()
	{
		code = new char[5];
		label = new char[20];
		price = 0;
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