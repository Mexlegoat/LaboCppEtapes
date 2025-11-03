#include <cstring>
#include "Car.h"
using namespace std;
// Constructeurs

Car::Car()
{
	name = "Modele sans nom";
	model.setName("pas de nom");
	model.setPower(0);
	model.setEngine(Engine::Petrol);
	model.setBasePrice(0);
}
Car::Car(const string nom, Model m)
{
	setName(nom);
	setModel(m);
}
Car::Car(const Car &source)
{
	setName(source.name);
	setModel(source.model);
}
// Autres fonctions
// display
void Car::display() const
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
	model.setName(m.getName());
	model.setPower(m.getPower());
	model.setBasePrice(m.getBasePrice());
	model.setEngine(m.getEngine());
}
// getters
Model Car::getModel() const
{
	return model;
}
string Car::getName() const
{
	return name;
}
