#ifndef GARAGE_H
#define GARAGE_H
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sstream>

#include "Employee.h"
#include "Client.h"
#include "Model.h"
#include "Option.h"
#include "Car.h"
#include "Contract.h" // step 13


#include "Credentials.h"
#include "XmlFileSerializer.hpp"
#include "XmlFileSerializerException.h"

#include <set>
#include <vector>
#include <list>
using namespace std;
using namespace carconfig;

class Garage
{	
private:
	set<Employee> employees;
	set<Client> clients;
	vector<Contract> contracts;
	list<Model> models;
	list<Option> options;
	Garage() = default;
	static Garage instance;
	static Car currentProject;
	Garage& operator=(const Garage& g) = delete;
	Garage(const Garage& g) = delete;
public:
	static int idLoggedEmployee;
	void setId(int i);
	int getId() const;

	static Garage& getInstance();
	static Car& getCurrentProject();
	static void resetCurrentProject();


	~Garage() = default;

	void addModel(const Model& m);
	void displayAllModels() const;
	Model getModel(int index) const;

	void addOption(const Option& o);
	void displayAllOptions() const;
	Option getOption(int index) const;

	int addClient(string lastName, string firstName, string gsm);
	void displayClients() const;
	void deleteClientByIndex(int index);
	void deleteClientById(int id);
	Client findClientByIndex(int index) const;
	Client findClientById(int id) const;
	const set<Client>& getClients() const;

	int addEmployee(string lastName, string firstName, string login, string role);
	int modifyEmployee(Employee e, int id);
	void displayEmployees() const;
	void deleteEmployeeByIndex(int index);
	void deleteEmployeeById(int id);
	Employee findEmployeeByIndex(int index) const;
	Employee findEmployeeById(int id) const;
	const set<Employee>& getEmployees() const;

	int addContract(int i, string c, string s, string p);
	void deleteContractByIndex(int index);
	void deleteContractById(int id);
	Contract findContractByIndex(int index) const;
	Contract findContractById(int id) const;
	const vector<Contract>& getContracts() const;


	// applicgarage import
	void importModelsFromCsv(string filename);
	void importOptionsFromCsv(string filename);

	// save & load
	int save();
	int load();
	// crypt et decrypt
	void crypt(Credentials& c);
	void decrypt(Credentials& c);
};
#endif