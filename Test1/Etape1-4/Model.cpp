#include "Model.h"
#include <cstring>
// Constructeurs
Model::Model()
{
	power = 0;
	basePrice = 0;
	name = new char[20];
	engine = Petrol; 

}

Model::Model(const char *nom, int puissance, Engine moteur, float prix)
{
	name = nom;
	power = puissance;
	engine = moteur;
	basePrice = prix;
}
Model::~Model()
{
	cout << "liberation d'allocation dynamique" << endl;
	if (name != nullptr)
	{
		delete[] name;
	}
}




// Autres Fonctions
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