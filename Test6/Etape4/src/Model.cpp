#include "Model.h"
namespace carconfig
{
	/***********************************************************************************************************************************************/
	/************************************					CONSTRUCTEURS/DESTRUCTEURS						****************************************/
	/***********************************************************************************************************************************************/
	Model::Model()
	{
		power = 0;
		basePrice = 0;
		name = nullptr;
		engine = Petrol; 

	}
	Model::Model(const char* nom, int puissance, Engine moteur, float prix)
	{
		setPower(puissance);
		setEngine(moteur);
		setBasePrice(prix);
		name = nullptr;
		setName(nom);
	}
	/***********************************************************************************************************************************************/
	/************************************					OPERATEURS						********************************************************/
	/***********************************************************************************************************************************************/
	istream& operator>>(istream& s, Model& m)
	{
    string line;

    getline(s, line); // <Model>

    getline(s, line); // <name>
    getline(s, line); // variable
    delete[] m.name;
    m.name = new char[line.length() + 1];
    strcpy(m.name, line.c_str());
    getline(s, line); // </name>

    // POWER
    getline(s, line); // <power>
    getline(s, line); // variable
    m.power = stoi(line);
    getline(s, line); // </power>

    // ENGINE
    getline(s, line); // <engine>
    getline(s, line); // variable
    m.setEngine(stoi(line));
    getline(s, line); // </engine>

    // BASEPRICE
    getline(s, line); // <basePrice>
    getline(s, line); // variable
    m.basePrice = stof(line);
    getline(s, line); // </basePrice>

    getline(s, line); // </Model>

    return s;
	}
	ostream& operator<<(ostream& s, const Model& m)
	{
		s << "<Model>" << endl;
		s << "<name>" << endl;
		s << m.name << endl;
		s << "</name>" << endl;
		s << "<power>" << endl;
		s << m.power << endl;
		s << "</power>" << endl;
		s << "<engine>" << endl;
		s << m.engine << endl;
		s << "</engine>" << endl;
		s << "<basePrice>" << endl;
		s << m.basePrice << endl;
		s << "</basePrice>" << endl;
		s << "</Model>" << endl;
		return s;
	}




	/***********************************************************************************************************************************************/
	/************************************					AUTRES FONCTIONS						************************************************/
	/***********************************************************************************************************************************************/

	/***********************************************************************************************************************************************/
	/************************************					DISPLAY						************************************************************/
	/***********************************************************************************************************************************************/
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
	string Model::enginetoString(Engine e) const
	{
		switch(e)
		{
			case Petrol:
				return "Petrol";
			case Diesel:
				return "Diesel";
			case Electric:
				return "Electric";
			case Hybrid:
				return "Hybrid";
			default: 
				return "Inconnu";
		}
	}
	string Model::toString() const
	{
		return string(this->name) + " " + to_string(this->power) + " " + enginetoString(this->engine) + " " + to_string(this->basePrice); 
	}
	/***********************************************************************************************************************************************/
	/************************************					SETTERS						************************************************************/
	/***********************************************************************************************************************************************/

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
	void Model::setEngine(int val)
	{
	    switch(val)
	    {
	        case 0: 
		        engine = Petrol; 
		        break;
	        case 1: 
		        engine = Diesel;
		        break;
	        case 2: 
		        engine = Electric;
		        break;
	        case 3: 
		        engine = Hybrid;
		        break;
	        default: 
	        	engine = Petrol;
	    }
	}
	void Model::setBasePrice(float modelBasePrice)
	{
		basePrice = modelBasePrice;
	}

	/***********************************************************************************************************************************************/
	/************************************					GETTERS						************************************************************/
	/***********************************************************************************************************************************************/
	float Model::getBasePrice() const
	{
		return basePrice;
	}
	const char* Model::getName() const
	{
		return name;
	}
	int Model::getPower() const
	{
		return power;
	}
	Engine Model::getEngine() const
	{
		return engine;
	}
}
