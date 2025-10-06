#include "Model.h"
#include <cstring>
// Constructeurs
Model::Model()
{
	power = 0;
	basePrice = 0;
	name = nullptr;
	engine = Petrol; 

}
Model::Model(const char* nom, int puissance, Engine moteur, float prix)
{
	power = puissance;
	engine = moteur;
	name = new char[strlen(nom) + 1];
	strcpy(name, nom);
	basePrice = prix;
}



// Autres Fonctions
// setters
// display
void Model::display()
{
	cout << "Nom: " << name << endl;
	cout << "Puissance: " << power << " Prix de base :" << basePrice << endl;
	cout<< "Moteur: ";
	switch(engine)
	{
		case Petrol:
			cout << "Petrol";
			break;
		case Diesel:
			cout << "Diesel";
			break;
		case Electric:
			cout << "Electric";
			break;
		case Hybrid:
			cout << "Hybrid";
			break;
	}
	cout<< endl;
} 
// getters
float Model::getBasePrice()
{
	return basePrice;
}