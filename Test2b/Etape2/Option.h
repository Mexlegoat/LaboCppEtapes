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
		void display();
		void setCode(const string c);
		void setLabel(const string l);
		void setPrice(float p);
	};
}
#endif