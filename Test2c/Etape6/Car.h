#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <string>
#include "Model.h"
#include "Option.h"
using namespace std;
namespace carconfig
{
	class Car
	{
	private:
		string name;
		Model model;
		Option* option[5];

	public:
		Car();
		Car(const string n, Model m);
		Car(const Car &source);
		~Car();
		void display();
		void addOption(const Option& option);
		void setName(const string n);
		void setModel(Model m);
		void removeOption(string);
		Model getModel();
		string getName();
		float getPrice();
	};
}
#endif