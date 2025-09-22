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
Model::~Model()
{
	cout << "destructeur" << endl;
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
void Model::display()
{

	cout << "Puissance: " << power << " Prix de base :" << basePrice << endl;
} 
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
