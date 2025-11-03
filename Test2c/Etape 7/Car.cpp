#include <cstring>
#include "Car.h"
// Constructeurs
namespace carconfig
{
	Car::Car()
	{
		name = "Modele sans nom";
		model.setName("pas de nom");
		model.setPower(0);
		model.setEngine(Engine::Petrol);
		model.setBasePrice(0);
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
	Car::Car(const Car &source)
	{
		name = source.name;
		model = source.model;
		for (int i = 0; i < 5; i++)
		{
			if (source.option[i] != nullptr)
			{
				option[i] = new Option(*source.option[i]);
			}
			else
			{
				option[i] = nullptr;
			}
		}
	}
	Car::~Car()
	{
		cout << "Destructeur" << endl;
		for (int i = 0; i < 5; i++)
		{
			if (option[i] != nullptr)
			{
				delete option[i];
				option[i] = nullptr;

			}
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

	void Car::setModel(const Model& m)
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
	float Car::getPrice()
	{
		int i;
		float sum = model.getBasePrice();
		for (i = 0; i < 5; i++)
		{
			if (option[i] != nullptr)
			{
				sum += option[i]->getPrice();
			}
		}
		return sum;
	}
	// Autres fonctions:
	void Car::removeOption(string code)
	{
		int i;
		for (i = 0; i < 5; i++)
		{
			if (option[i] != nullptr)
			{
				if (option[i]->getCode() == code)
				{
					delete option[i];
					option[i] = nullptr;

					return;
				}
			}

		}
		if (option[i]->getCode() != code)
		{
			cout << "L'option n'existe pas" << endl;
		}
	}
}
