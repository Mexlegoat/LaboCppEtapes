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
		Car operator+(const Option& o) const;
		Car operator-(const Option& o) const;
		Car operator-(const string) const;
		bool operator<(const Car& c) const;
		bool operator>(const Car& c) const;
		bool operator==(const Car& c) const;
		friend Car operator+(const Option& o, const Car& c);
		~Car();
		Car& operator= (const Car&);
		void display();
		void addOption(const Option& option);
		void setName(const string n);
		void setModel(Model m);
		void removeOption(string);
		Model getModel();
		string getName();
		float getPrice() const;
	};
}
#endif