#ifndef OPTION_H
#define OPTION_H
#include <iostream>
#include <cstring>
using namespace std;
namespace carconfig
{
	class Option
	{
	private:
		string code;
		string label;
		float price;

	public:
		Option();
		Option(const string c, const string l, float p);
		Option(const Option &source);
		friend istream& operator>>(istream& s, Option& o);
		friend ostream& operator<<(ostream& s, const Option& o);
		void display();
		void setCode(const string c);
		void setLabel(const string l);
		void setPrice(float p);
		float getPrice() const;
		string getCode() const;
	};
}
#endif