#include <cstring>
#include "Car.h"
// Constructeurs

Car::Car()
{
	name = new char[50];
	// model = Model();
}
Car::~Car()
{
	cout << "liberation d'allocation dynamique" << endl;
	if (name != nullptr)
	{
		delete[] name;
	}
}

// Autres fonctions
void Car::display()
{
	cout << name << endl;
}