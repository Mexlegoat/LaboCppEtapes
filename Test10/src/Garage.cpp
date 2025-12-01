#include "Garage.h"
Garage Garage::instance; // definition de la variable statique
// definition currentProject
Car Garage::currentProject;
/**************************************** MODEL ***********************************/

void Garage::addModel(const Model& m)
{
	models.push_back(m);
}
void Garage::displayAllModels() const
{
	int index = 0;
	for(list<Model>::const_iterator it = models.cbegin(); it != models.cend(); it++)
	{
		cout << "Modele " << index << ": " << it->toString() << endl;
		index++;
	}
}
Model Garage::getModel(int index) const
{
	if (index < 0 || index >= models.size())
	{
		return Model();
	}
	auto it = models.cbegin();
	advance(it, index); // faire avancer it jusqu'à index;
	if (it != models.cend())
	{
		return *it;
	}
	else
	{
		return Model();
	}
}
/**************************************** OPTION ***********************************/

void Garage::addOption(const Option& o)
{
	options.push_back(o);
}
void Garage::displayAllOptions() const
{
	int index = 0;
	for (list<Option>::const_iterator it = options.cbegin(); it != options.cend(); it++)
	{
		cout << "Option " << index << ": " << it->toString() << endl;
	}
}
Option Garage::getOption(int index) const
{
	if (index < 0 || index >= options.size())
	{
		return Option();
	}
	auto it = options.cbegin();
	advance(it, index);
	if (it != options.cend())
	{
		return *it;

	}
	else
	{
		return Option();
	}
}
/**************************************** CLIENT ***********************************/

int Garage::addClient(string lastName, string firstName, string gsm)
{
	clients.insert(Client(lastName, firstName, Actor::currentId, gsm));
	cout << "Id Client: " << Actor::currentId << endl;
	Actor::currentId++;
	return 1;
}
void Garage::displayClients() const
{
	int i = 0;
	for(set<Client>::const_iterator it = clients.cbegin(); it != clients.cend(); it++)
	{
		cout << "Client " << i << ": " << it->toString() << endl;
		i++;
	}
}
int Garage::addEmployee(string lastName, string firstName, string login, string role)
{
	employees.insert(Employee(lastName, firstName, Actor::currentId, login, role));
	cout << "Id Employee: " << Actor::currentId << endl;
	Actor::currentId++;
	return 1;
}
void Garage::displayEmployees() const
{
	int i = 0;
	for (set<Employee>::const_iterator it = employees.cbegin(); it != employees.cend(); it++)
	{
		cout << "Employee " << i << ": " << it->toString() << endl;
		i++;
	}
}
void Garage::deleteClientByIndex(int index)
{
	auto it = clients.cbegin();
	advance(it, index);
	if (it != clients.cend())
	{
		clients.erase(it);
	}
	else
	{
		cout << "Index hors limite (Client)" << endl;
	}
}
void Garage::deleteClientById(int id)
{
	auto it = clients.begin();
	while(it != clients.end() && it->getId() != id)
	{
		it++;

	}

	if(it != clients.end())
	{
	    clients.erase(it);
		cout << "Comparaison: ClientId: " << it->getId() << " ?= Id:" << id << endl;
	}
	else
	{
	    cout << "Id Client hors limite" << endl;
	}

}
Client Garage::findClientById(int id) const
{
	auto it = clients.cbegin();
	while (it != clients.cend() && it->getId() != id)
	{
		it++;
	}
	if (it != clients.cend())
	{
		return *it;
	}
	cout << "Id client hors limite" << endl;
	return Client();
}
Client Garage::findClientByIndex(int index) const
{
	auto it = clients.cbegin();
	advance(it, index);
	if (it != clients.cend())
	{
		return *it;
	}
	cout << "Index hors limite" << endl;
	return Client();
}
/**************************************** EMPLOYEE ***********************************/

void Garage::deleteEmployeeByIndex(int index)
{
	auto it = employees.cbegin();
	advance(it, index);
	if (it != employees.cend())
	{
		employees.erase(it);
	}
	else
	{
		cout << "Index hors limite (Employee)" << endl;
	}
}
void Garage::deleteEmployeeById(int id)
{
	auto it = employees.begin();
	while(it != employees.end() && it->getId() != id)
	{
		it++;
	}

	if(it != employees.end())
	{
	    employees.erase(it);
	    cout << "Comparaison: EmployeeId: " << it->getId() << " ?= Id:" << id << endl;
	}
	else
	{
	    cout << "Id Employee hors limite" << endl;
	}

}
Employee Garage::findEmployeeById(int id) const
{
	auto it = employees.cbegin();
	while (it != employees.cend() && it->getId() != id)
	{
		it++;
	}
	if (it != employees.cend())
	{
		return *it;
	}
	cout << "Id Employee hors limite" << endl;
	return Employee();
}
Employee Garage::findEmployeeByIndex(int index) const
{
	auto it = employees.cbegin();
	advance(it, index);
	if (it != employees.cend())
	{
		return *it;
	}
	cout << "Index hors limite" << endl;
	return Employee();
}
/**************************************** INSTANCE ***********************************/
Garage& Garage::getInstance()
{
	return instance;
}
/**************************************** CURRENTPROJECT ***********************************/

Car& Garage::getCurrentProject()
{
	return currentProject;
}
void Garage::resetCurrentProject()
{
	currentProject = Car();
}
/**************************************** APPLICGARAGE CSV ***********************************/
void Garage::importModelsFromCsv(string filename)
{
	fstream fd;
	string fn = filename + "models.csv";
	fd.open(fn, ios::in);
	if(!fd.is_open())
	{
		cout << "Fichier introuvable";
		return;
	}
	string line;
	getline(fd, line); // skip entete
	while (getline(fd, line))
	{
		string name, basePriceStr, powerStr, image, engineStr;
		istringstream iss(line);
		getline(iss, name, ';');
		getline(iss, powerStr, ';');
		getline(iss, engineStr, ';');
		getline(iss, image, ';');
		getline(iss, basePriceStr, ';');

		// creer un model pour la combobox
		Model m;

		m.setName(name.c_str());
		m.setBasePrice(stof(basePriceStr));
		m.setEngine(engineStr);
		m.setPower(stoi(powerStr));
		m.setImage(image);

		// créer une liste pour que quand on appelle cette fonction dans applicgarage on peut parcourir la liste
		addModel(m);

	}
}
void Garage::importOptionsFromCsv(string filename)
{
	fstream fd;
	string fn = filename + "options.csv";
	fd.open(fn, ios::in);
	if(!fd.is_open())
	{
		cout << "Fichier introuvable";
		return;
	}
	string line;
	getline(fd, line); // skip entete
	while (getline(fd, line))
	{
		string code, label, priceStr;
		istringstream iss(line);
		getline(iss, code, ';');
		getline(iss, label, ';');
		getline(iss, priceStr, ';');

		// creer une option pour la combobox
		Option o;
		try
		{
			o.setCode(code);
			o.setLabel(label);
			o.setPrice(stof(priceStr));			
		}
		catch(OptionException& op)
		{
	        cout << op.getMessage();
		}

		// créer une liste pour que quand on appelle cette fonction dans applicgarage on peut parcourir la liste
		addOption(o);

	}
}