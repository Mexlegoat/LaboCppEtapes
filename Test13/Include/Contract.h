#ifndef CONTRACT_H
#define CONTRACT_H
#include <iostream>
#include <string>
#include "Client.h"
#include "Employee.h"
using namespace std;
class Contract
{
private:
	int id;
	string seller;
	string client;
	string projectName;
public:
	static int currentId;
	Contract();
	Contract(int id, string, string, string);
	Contract(const Contract& c);
	void setSeller(string);
	void setId(int);
	void setClient(string);
	void setProjectName(string);
	friend ostream& operator<<(ostream& o, const Contract& c);
	friend istream& operator>>(istream& i, Contract& c);
	string getSeller()const;
	string getClient()const;
	string getProjectName()const;
	int getId()const;
	string tuple()const;
	Contract& operator=(const Contract& c);
	bool operator<(const Contract& c)const;
	
};
#endif