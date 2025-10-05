#include <cstring>
#include "Car.h"
// Constructeurs
using namespace std;
Car::Car()
{
	name = "Modele sans nom";
	model = Model();
}
Car::Car(const string nom, Model m)
{
	name = nom;
	model = m;
}
// Autres fonctions
// display
void Car::display()
{
	cout << name << endl;
	model.display();
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
