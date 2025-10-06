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
		void display();
		void setCode(const string c);
		void setLabel(const string l);
		void setPrice(float p);
		float getPrice();
		string getCode();
	};
}
#endif