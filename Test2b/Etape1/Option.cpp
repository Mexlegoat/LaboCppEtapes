#include "Option.h"
namespace carconfig
{
	Option::Option()
	{
		code = new char[5];
		label = new char[20];
		price = 0;
	}
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
	void Option::display()
	{
		cout << "Code: " << code << endl << "Nom: " << label << endl << "Prix: " << endl << price;
	}
}