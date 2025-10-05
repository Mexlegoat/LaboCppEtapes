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
	};
}
#endif