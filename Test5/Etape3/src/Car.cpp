#include <cstring>
#include "Car.h"
namespace carconfig
{

	/***********************************************************************************************************************************************/
	/************************************					CONSTRUCTEURS/DESTRUCTEURS						****************************************/
	/***********************************************************************************************************************************************/
	Car::Car()
	{
		name = "Modele sans nom";
		model = Model();
		for (int i = 0; i < 5; i++)
		{
			option[i] = nullptr;
		}
	}
	Car::Car(const string nom, Model m)
	{
		setName(nom);
		setModel(m);

		for (int i = 0; i < 5; i++)
		{
			option[i] = nullptr;
		}
	}
	Car::Car(const Car &source)
	{
		setName(source.name);
		setModel(source.model);
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
		cout << "[Car] Destructeur d'option" << endl;
		for (int i = 0; i < 5; i++)
		{
			if (option[i] != nullptr)
			{
				delete option[i];
				option[i] = nullptr;

			}
		}
	}
	
	/***********************************************************************************************************************************************/
	/************************************					OPERATEURS						********************************************************/
	/***********************************************************************************************************************************************/
	Car& Car::operator=(const Car& source)
	{
		if (this == &source)
		{
			return *this;
		}
		int i;
		for (i = 0; i < 5; i++)
		{
			if (option[i] != nullptr)
			{
				cout << "Destructeur d'option apres operation =" << endl;
				delete option[i];
				option[i] = nullptr;
			}
		}

		name = source.name;
		model = source.model;
		for (i = 0; i < 5; i++)
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
		return *this;
	}
	Car Car::operator+(const Option& o) const
	{
		Car resultat(*this);
		resultat.addOption(o);
		return resultat;
	}
	Car operator+(const Option& o, const Car& c)
	{
		Car resultat(c);
		resultat.addOption(o);
		return resultat;
	}
	Car Car::operator-(const Option& o) const
	{
		Car resultat(*this);
		resultat.removeOption(o.getCode());
		return resultat;
	}
	Car Car::operator-(const string s) const
	{
		Car resultat(*this);
		resultat.removeOption(s);
		return resultat;
	}
	bool Car::operator<(const Car& c) const
	{
		return this->getPrice() < c.getPrice();

	}
	bool Car::operator>(const Car& c) const
	{
		return this->getPrice() > c.getPrice();

	}
	bool Car::operator==(const Car& c) const
	{
		return this->getPrice() == c.getPrice();
	}
	Option* Car::operator[](int i)
	{
	    if (i <= 0 || i > 6)
	    {
	        throw OptionException("Erreur : indice d'option invalide (doit être entre 1 et 6) !");
	    }

	    return option[i];
	}
	/*************************************************			OPERATEUR << et >> *****************************************************************/

	ostream& operator<<(ostream& s, const Car& c)
	{
		s << "Projet: " << c.name << endl << c.model << endl;
		for (int i = 0; i < 5; i++)
		{
			if(c.option[i] != nullptr)
			{
				s << "Option " << i+1 << " :" << endl;
				s << c.option[i]->getCode() << endl << c.option[i]->getLabel() << endl << c.option[i]->getPrice() << endl << endl;
			}
		}
		return s;
	}
	/***********************************************************************************************************************************************/
	/************************************					AUTRES FONCTIONS						************************************************/
	/***********************************************************************************************************************************************/

	/***********************************************************************************************************************************************/
	/************************************					DISPLAY						************************************************************/
	/***********************************************************************************************************************************************/
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

	/***********************************************************************************************************************************************/
	/************************************					SETTERS						************************************************************/
	/***********************************************************************************************************************************************/
	void Car::setName(const string copy)
	{
		name = copy;
	}

	void Car::setModel(Model m)
	{
		model = m;
	}
	void Car::addOption(const Option& o)
	{
		int i;
		for (i = 0; i < 5; i++)
		{
			if (option[i] != nullptr)
			{
				if (option[i]->getCode() == o.getCode())
				{
					throw OptionException("L'option existe deja dans la voiture");
				}
			}

			else if (option[i] == nullptr)
			{
				option[i] = new Option(o);
				return;
			}
		}
		throw OptionException("Erreur : nombre maximal d'options atteint !");
	}
	
	/***********************************************************************************************************************************************/
	/************************************					GETTERS						************************************************************/
	/***********************************************************************************************************************************************/
	Model Car::getModel()
	{
		return model;
	}
	string Car::getName()
	{
		return name;
	}
	float Car::getPrice() const
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
		bool isTrue = false;
		for (i = 0; i < 5; i++)
		{
			if (option[i] != nullptr && option[i]->getCode() == code)
			{
				delete option[i];
				isTrue = true;
				option[i] = nullptr;
				return;
			}
		}
		if (!isTrue)
		{
			throw OptionException("L'option que vous voulez supprimer n'existe pas");
		}
	}
}
