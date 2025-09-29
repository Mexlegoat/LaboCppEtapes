#include <cstring>
#include "Car.h"
// Constructeurs

Car::Car()
{
	name = nullptr;
	model = Model();
}
Car::~Car()
{
	cout << "Destructeur" << endl;
	if (name != nullptr)
	{
		delete[] name;
	}
}

// Autres fonctions
// display
void Car::display()
{
	cout << name << endl;
	model.display();
}
// setters
void Car::setName(const char* copy)
{
	name = new char[strlen(copy) + 1];
	strcpy(name, copy);
}

void Car::setModel(Model m)
{
	model = m;
}
// getters
Model Car::getModel()
{
	return model;
}
char* Car::getName()
{
	return name;
}
