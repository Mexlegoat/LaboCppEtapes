#include "Model.h"
#include <cstring>
// Constructeurs
Model::Model()
{
	name = nullptr;
	setName("default");
	setPower(80);
	setEngine(Engine::Petrol);
	setBasePrice(15000);

}
Model::Model(const char* nom, int puissance, Engine moteur, float prix)
{
	power = puissance;
	engine = moteur;
	name = new char[strlen(nom) + 1];
	strcpy(name, nom);
	basePrice = prix;
}
Model::Model(const Model& mod) // constructeur de copie
{
	name = nullptr;
	setName(mod.getName());
	setPower(mod.getPower());
	setEngine(mod.getEngine());
	setBasePrice(mod.getBasePrice());
}

Model::~Model()
{
	if (name != nullptr)
	{
		delete[] name;
		name = nullptr;
	}
}
// Autres Fonctions
// setters
void Model::setName(const char* modelName)
{
	if (name != nullptr) delete[] name;
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
void Model::display() const
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
const char* Model::getName() const
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
int Model::getPower() const
{
	return power;
}
Engine Model::getEngine() const
{
	return engine;
}
float Model::getBasePrice() const
{
	return basePrice;
}