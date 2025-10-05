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
	Option::Option(const string c, const string l, float p)
	{
		code = c;
		label = l;
		price = p;
	}
	// Affichage
	void Option::display()
	{
		cout << "Code: " << code << endl << "Nom: " << label << endl << "Prix: " << price << endl;
	}
	// Setters
	void Option::setCode(const string c)
	{
		code = c;
	}
	void Option::setLabel(const string l)
	{
		label = l;
	}
	void Option::setPrice(float l)
	{
		price = l;
	}
	// Getters
}