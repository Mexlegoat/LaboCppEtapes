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
		string line;
		getline(s, line);
		getline(s, line);
		getline(s, line);
		o.setCode(line);
		getline(s, line);
		getline(s, line);
		getline(s, line);
		o.setLabel(line);
		getline(s, line);
		getline(s, line);
		s >> o.price;
		getline(s, line);
		getline(s, line);
		getline(s, line);

		return s;
	}
	ostream& operator<<(ostream& s, const Option& o)
	{
		s << "<Option>" << endl;
		s << "<code>" << endl;
		s << o.code << endl;
		s << "</code>" << endl;
		s << "<label>" << endl;
		s << o.label << endl;
		s << "</label>" << endl;
		s << "<price>" << endl;
		s << o.price << endl;
		s << "</price>" << endl;
		s << "</Option>" << endl;
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
	string Option::toString() const
	{
		return this->code + ", " + this->label + ", "+ to_string(this->price); 
	}
	/***********************************************************************************************************************************************/
	/************************************					SETTERS						************************************************************/
	/***********************************************************************************************************************************************/
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