#ifndef EMPLOYEE_H
#define EMPLOYEE_H
using namespace std;
#include <iostream>
#include <string>
#include "Actor.h"
class Employee: public Actor
{
private:
	string login;
	string* password;
	string role;
public:
	Employee();
	Employee(string l, string f, int i, string lo, string r);
	Employee(const Employee& e);
	~Employee();
	void resetPassword();
	void setPassword(const string& pw);
	void setRole(string r);
	void setLogin(string l);
	string tuple() const override;
	string toString() const override;
	string getPassword() const ;
	string getRole() const;
	string getLogin() const;
	friend ostream& operator<<(ostream& s, const Employee& e);
	Employee& operator=(const Employee& e);
};
#endif