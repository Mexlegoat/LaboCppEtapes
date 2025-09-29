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
void Model::setName(const char* modelName)
{
	name = new char [strlen(modelName) + 1];
	strcpy(name, modelName);
}
void Model::setPower(int modelPower)
{
	power = modelPower;
}
void Model::setEngine(Engine modelEngine)
{
	engine = modelEngine;
}
void Model::setBasePrice(float modelBasePrice)
{
	basePrice = modelBasePrice;
}
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
const char* Model::getName()
{
	if (name != nullptr)
	{
		return name;
	}
	else
	{
		return "Modele sans nom";
	}
}
int Model::getPower()
{
	return power;
}
Engine Model::getEngine()
{
	return engine;
}
float Model::getBasePrice()
{
	return basePrice;
}