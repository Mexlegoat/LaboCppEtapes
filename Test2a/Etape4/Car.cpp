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
Car::Car(const char* nom, Model m)
{
	name = new char[strlen(nom) + 1];
	strcpy(name, nom);
	model = m;
}
Car::Car(const Car &source)
{
	if (source.name != nullptr)
	{
		name = new char[strlen(source.name) + 1];
		strcpy(name, source.name);
	}
	else
	{
		name = nullptr;
	}
	model = source.model;
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
