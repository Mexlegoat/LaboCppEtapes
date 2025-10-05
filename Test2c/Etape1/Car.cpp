#include <cstring>
#include "Car.h"
// Constructeurs

Car::Car()
{
	name = "Modele sans nom";
	model = Model();
	for (int i = 0; i < 5; i++)
	{
		option[i] = nullptr;
	}
}
Car::Car(const string nom, Model m)
{
	name = nom;
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
void Car::setName(const string copy)
{
	name = copy;
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
string Car::getName()
{
	return name;
}
