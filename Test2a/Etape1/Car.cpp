#include <cstring>
#include "Car.h"
// Constructeurs
using namespace std;
Car::Car()
{
	name = "Modele sans nom";
	// model = Model();
}
// Autres fonctions
void Car::display()
{
	cout << name << endl;
}