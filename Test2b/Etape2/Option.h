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
		char* code;
		char* label;
		float price;

	public:
		Option();
		~Option();
		void display();
		void setCode(const char* c);
		void setLabel(const char* l);
		void setPrice(float p);
	};
}
#endif