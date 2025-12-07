#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>
#include "Model.h"
#include "Option.h"
#include "OptionException.h"
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
		Car(const string n,const Model& m);
		Car(const Car &source);
		Car operator+(const Option& o) const;
		Car operator-(const Option& o) const;
		Car operator-(const string) const;
		bool operator<(const Car& c) const;
		bool operator>(const Car& c) const;
		bool operator==(const Car& c) const;
		friend ostream& operator<<(ostream& s, const Car& c);
		friend istream& operator>>(istream& s, Car& c);
		friend Car operator+(const Option& o, const Car& c);
		Option* operator[](int);
		~Car();
		Car& operator= (const Car&);
		void display();
		void addOption(const Option& option);
		void setName(const string n);
		void setModel(const Model& m);
		void removeOption(string);
		Model getModel() const;
		string getName() const;
		float getPrice() const;

		// Etape 9
		void save();
		void load(string pn);
	};
}
#endif