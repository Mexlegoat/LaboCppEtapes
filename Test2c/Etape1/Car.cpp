#include <cstring>
#include "Car.h"
// Constructeurs

Car::Car()
{
	name = nullptr;
	model = Model();
	for (int i = 0; i < 5; i++)
	{
		option[i] = nullptr;
	}
}
Car::~Car()
{
	cout << "Destructeur" << endl;
	if (name != nullptr)
	{
		delete[] name;
	}
	for(int i = 0; i < 5; i++)
	{
		if (option[i] != nullptr)
		{
			delete[] option[i];
		}
	}
}
Car::Car(const char* nom, Model m)
{
	name = new char[strlen(nom) + 1];
	strcpy(name, nom);
	model = m;

	for (int i = 0; i < 5; i++)
	{
		option[i] = nullptr;
	}
}
// Autres fonctions
// display
void Car::display()
{
	cout << name << endl;
	model.display();
	bool isTrue = false;
	for (int i = 0; i < 5; i++)
	{
		if (option[i] != nullptr)
		{
			option[i]->display();
			isTrue = true;
		}
	}
	if (!isTrue)
	{
		cout << "Aucune option detectee" << endl;
	}
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
