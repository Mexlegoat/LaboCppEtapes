#include "Option.h"
namespace carconfig
{
	Option::Option()
	{
		code = "0000";
		label = "Modele sans nom";
		price = 0;
	}
	void Option::display()
	{
		cout << "Code: " << code << endl << "Nom: " << label << endl << "Prix: " << endl << price;
	}
}