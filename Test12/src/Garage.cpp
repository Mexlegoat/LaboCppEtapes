#include "Garage.h"
Garage Garage::instance; // definition de la variable statique
// definition currentProject
Car Garage::currentProject;
int Garage::idLoggedEmployee = 0;
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
const set<Client>& Garage::getClients() const
{
	return clients;
}
/**************************************** EMPLOYEE ***********************************/
int Garage::addEmployee(string lastName, string firstName, string login, string role)
{
	employees.insert(Employee(lastName, firstName, Actor::currentId, login, role));
	cout << "Id Employee: " << Actor::currentId << endl;
	Actor::currentId++;
	return 1;
}
int Garage::modifyEmployee(Employee e, int id)
{
	auto it = employees.cbegin();
	while (it != employees.cend() && it->getId() != id)
	{
		it++;
	}
	employees.erase(it);
	employees.insert(e);
	cout << "Id Employee: " << id << endl;
	return 1;
}
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
const set<Employee>& Garage::getEmployees() const
{
	return employees;
}
void Garage::setId(int i)
{
	Garage::idLoggedEmployee = i;
}
int Garage::getId() const
{
	return Garage::idLoggedEmployee;
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
// save et load
int Garage::save()
{
	int i;
	string NomConcat;
	const char *NomFichier;
	int count = 0;
	NomConcat = "employee.xml";
	XmlFileSerializer<Employee> *FE = new XmlFileSerializer<Employee>(NomConcat, XmlFileSerializer<Employee>::WRITE, "Employees");
	auto it = employees.cbegin();
	i = 0;
	while(it != employees.cend())
	{
		Employee e = findEmployeeByIndex(i);
		FE->write(e);
		i++;
		count++;
		it++;
	}
	delete FE;
	NomConcat = "client.xml";
	XmlFileSerializer<Client> *FC = new XmlFileSerializer<Client>(NomConcat, XmlFileSerializer<Client>::WRITE, "Clients");
	auto itc = clients.cbegin();
	i = 0;
	while(itc != clients.cend())
	{
		Client c = findClientByIndex(i);
		FC->write(c);
		i++;
		itc++;
	}
	delete FC;
	NomConcat = "config.dat";
	NomFichier = NomConcat.c_str();
	int fd;
	if ((fd = open(NomFichier, O_WRONLY | O_CREAT | O_TRUNC, 0777)) == -1)
	{
		cerr << "Une erreur est survenue lors de l'ouverture du fichier";
		return -1;
	}
	write(fd, &Actor::currentId, sizeof(Actor::currentId));
	cout << "current code: " << Actor::currentId << endl;
	write(fd, &count, sizeof(int));
	cout << "current employee count: " << count << endl;
	i = 0;
	while(i < count)
	{
		Credentials cr;
		Employee e = findEmployeeByIndex(i);
		strncpy(cr.login, e.getLogin().c_str(), sizeof(cr.login)-1);
		cr.login[sizeof(cr.login)-1] = '\0';   // toujours terminer par '\0'
		cout << "login: " << cr.login;
		try
		{
		    strncpy(cr.password, e.getPassword().c_str(), sizeof(cr.password)-1);
		    cr.password[sizeof(cr.password)-1] = '\0';

		}
		catch(PasswordException& p)
		{
		    cr.password[0] = '\0';

		}
		cout << "password: " << cr.password;
		crypt(cr);
		cout << "Après cryptage";
		cout << endl << "login: " << cr.login << endl << "password: " << cr.password << endl;
		write(fd, &cr, sizeof(Credentials));
		i++;
	}
	close(fd);
	return 1;

}
int Garage::load()
{
	string NomConcat;
	int i;

	NomConcat = "employee.xml";
	XmlFileSerializer<Employee> *FE = nullptr;
	try
	{
		FE = new XmlFileSerializer<Employee>(NomConcat, XmlFileSerializer<Employee>::READ);
	}
	catch(const XmlFileSerializerException& x)
	{
		cout << "Erreur: " << x.getMessage() << endl;
	}
	if (FE != nullptr)
	{
		bool end = false;
		while(!end)
		{
			try
			{
				Employee e = FE->read();
				addEmployee(e.getLastName(),e.getFirstName(),e.getLogin(),e.getRole());
			}
			catch(const XmlFileSerializerException& x)
			{
				if (x.getCode() == XmlFileSerializerException::END_OF_FILE)
				{
					end = true;
				}
				else
				{
					cout << x.getMessage() << endl;
					break;
				}
			}
		}
		delete FE;
	}

	NomConcat = "client.xml";
	XmlFileSerializer<Client> *FC = nullptr;
	try
	{
		FC = new XmlFileSerializer<Client>(NomConcat, XmlFileSerializer<Client>::READ);
	}
	catch(const XmlFileSerializerException& x)
	{
		cout << "Erreur: " << x.getMessage() << endl;
	}
	if (FC != nullptr)
	{
		bool end = false;
		while(!end)
		{
			try
			{
				Client c = FC->read();
				addClient(c.getLastName(), c.getFirstName(), c.getGsm());
			}
			catch(const XmlFileSerializerException& x)
			{
				if (x.getCode() == XmlFileSerializerException::END_OF_FILE)
				{
					end = true;
				}
				else
				{
					cout << x.getMessage() << endl;
					break;
				}
			}
		}
		delete FC;
	}
	NomConcat = "config.dat";
	const char *NomFichier = NomConcat.c_str();
	int fd, count;
	if ((fd = open(NomFichier, O_RDONLY, 0777)) == -1)
	{
		cerr << "Une erreur est survenue lors de l'ouverture du fichier";
		return -1;
	}
	if(read(fd, &Actor::currentId, sizeof(Actor::currentId)) < 1)
	{
		cerr << "Erreur: Données incorrect" << endl;
		return -1;
	}
	if (read(fd, &count, sizeof(int)) < 1)
	{
		cerr << "Erreur: Données incorrect" << endl;
		return -1;
	}
	i = 0;
	while(i < count)
	{
		Credentials cr;
		Employee e = findEmployeeByIndex(i);
		if(read(fd, &cr, sizeof(cr)) < 1)
		{
			cerr << "Erreur: Données incorrect" << endl;
			return -1;
		}
		decrypt(cr);
		e.setLogin(string(cr.login));
		if (cr.password[0] != '\0')
		{
			e.setPassword(cr.password);
		}
		modifyEmployee(e, e.getId());
		i++;
	}
	close(fd);
	return 1;
}
// cryptage et décryptage
void Garage::crypt(Credentials& c) 
{
	for(int i = 0; i < strlen(c.login); i++)
	{
		int val = c.login[i] + 9;
		if (val > 255)
		{
			val -= 255;
		}
		c.login[i] = val;
	}
	for(int i = 0; i < strlen(c.password); i++)
	{
		
		int val = c.password[i] + 5;
		if (val > 255)
		{
			val -= 255;
		}
		c.password[i] = val;
	}
}
void Garage::decrypt(Credentials& c)
{
	for(int i = 0; i < strlen(c.login); i++)
	{
		int val = c.login[i] - 9;
		if (val < 0)
		{
			val += 255;
		}
		c.login[i] = val;
	}
	for(int i = 0; i < strlen(c.password); i++)
	{
		int val = c.password[i] - 5;
		if (val < 0)
		{
			val += 255;
		}
		c.password[i] = val;
	}
}