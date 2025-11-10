#ifndef GARAGE_H
#define GARAGE_H
#include <iostream>
#include <cstring>
#include <string>
#include "Employee.h"
#include "Client.h"
#include "Model.h"
#include "Option.h"
#include <set>
#include <list>
using namespace std;
using namespace carconfig;

class Garage
{	
private:
	set<Employee> employees;
	set<Client> clients;
	list<Model> models;
	list<Option> options;
	Garage() = default;
	static Garage instance;
	Garage& operator=(const Garage& g) = delete;
	Garage(const Garage& g) = delete;
public:
	static Garage& getInstance();
	~Garage() = default;

	void addModel(const Model& m);
	void displayAllModels() const;
	Model getModel(int index) const;

	void addOption(const Option& o);
	void displayAllOptions() const;
	Option getOption(int index);

	int addClient(string lastName, string firstName, string gsm);
	void displayClients() const;
	void deleteClientByIndex(int index);
	void deleteClientById(int id);
	Client findClientByIndex(int index) const;
	Client findClientById(int id) const;

	int addEmployee(string lastName, string firstName, string login, string role);
	void displayEmployees() const;
	void deleteEmployeeByIndex(int index);
	void deleteEmployeeById(int id);
	Employee findEmployeeByIndex(int index) const;
	Employee findEmployeeById(int id) const;
};
#endif