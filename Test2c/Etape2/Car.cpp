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
			cout << "Option " << i+1 << " :" << endl;
			option[i]->display();
			isTrue = true;
		}
	}
	if (!isTrue)
	{
		cout << "Aucune option detectee" << endl;
	}
	cout << endl << endl;
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
void Car::addOption(const Option& o)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		if (option[i] == nullptr)
		{
			option[i] = new Option(o);
			return;
		}
	}
	cout << "Impossible d'ajouter plus que 5 options" << endl;
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