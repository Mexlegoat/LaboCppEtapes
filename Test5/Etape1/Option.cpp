#include "Option.h"
namespace carconfig
{
	/***********************************************************************************************************************************************/
	/************************************					CONSTRUCTEURS/DESTRUCTEURS						****************************************/
	/***********************************************************************************************************************************************/
	Option::Option()
	{
		code = "0000";
		label = "Modele sans nom";
		price = 0;
	}
	Option::Option(const string c, const string l, float p)
	{
		setCode(c);
		setLabel(l);
		setPrice(p);
	}
	Option::Option(const Option &source)
	{
		setCode(source.code);
		setLabel(source.label);
		setPrice(source.price);
		
	}
	/***********************************************************************************************************************************************/
	/************************************					OPERATEURS						********************************************************/
	/***********************************************************************************************************************************************/
	istream& operator>> (istream& s, Option& o)
	{
		string c, l;
		float p;
		cout << "Code: ";
		s >> c;
		if (c.length() != 4)
		{
			throw OptionException("Code invalide, le code doit avoir exactement 4 lettres!");
		}
		s.ignore();
		cout << "Nom: ";
		getline(s, l);
		if (l.length() == 0)
		{
			throw OptionException("Intitulee invalide, l'intitulee doit contenir au moins 1 lettre!");
		}
		cout << "Prix:";
		s >> p;
		if (p  < 0)
		{
			throw OptionException("Prix invalide, le prix doit etre positive!");
		}
		o.code = c;
		o.label = l;
		o.price = p;
		return s;
	}
	ostream& operator<<(ostream& s, const Option& o)
	{
		s << "Code: " << o.code << endl << "Nom: " << o.label << endl << "Prix: " << o.price << "Euros";
		return s;
	}

	Option Option::operator--()
	{
		(*this).price-= 50;
		if (price < 0)
		{
			throw OptionException("Erreur, le prix est devenu negatif!");
		}
		return (*this);
	}
	Option Option::operator--(int)
	{
		Option temp(*this);

		price -= 50;

		if (price < 0)
		{
			throw OptionException("Erreur, le prix est devenu negatif!");
		}
		return temp;
	}
	/***********************************************************************************************************************************************/
	/************************************					AUTRES FONCTIONS						************************************************/
	/***********************************************************************************************************************************************/

	/***********************************************************************************************************************************************/
	/************************************					DISPLAY						************************************************************/
	/***********************************************************************************************************************************************/
	void Option::display()
	{
		cout << "Code: " << code << endl << "Nom: " << label << endl << "Prix: " << price << endl;
	}
	/***********************************************************************************************************************************************/
	/************************************					SETTERS						************************************************************/
	/***********************************************************************************************************************************************/
	void Option::setCode(const string c)
	{
		if (c.length() != 4)
		{
			throw OptionException("Code invalide, le code doit avoir exactement 4 lettres!");
		}
		code = c;
	}
	void Option::setLabel(const string l)
	{
		if (l.length() == 0)
		{
			throw OptionException("Intitulee invalide, l'intitulee doit contenir au moins 1 lettre!");
		}
		label = l;
	}
	void Option::setPrice(float l)
	{
		if (l  < 0)
		{
			throw OptionException("Prix invalide, le prix doit etre positive!");
		}
		price = l;
	}
	/***********************************************************************************************************************************************/
	/************************************					GETTERS						************************************************************/
	/***********************************************************************************************************************************************/
	float Option::getPrice() const
	{
		return price;
	}
	string Option::getCode() const
	{
		return code;
	}
	string Option::getLabel() const
	{
		return label;
	}
}