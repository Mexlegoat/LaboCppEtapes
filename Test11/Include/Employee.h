#ifndef EMPLOYEE_H
#define EMPLOYEE_H
using namespace std;
#include <iostream>
#include <string>
#include "Actor.h"
#include "PasswordException.h"
class Employee: public Actor
{
public:
	static const string ADMINISTRATIVE;
	static const string SELLER;
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
	void setRole(const string r);
	void setLogin(string l);
	void setRole(int r);
	string tuple() const override;
	string toString() const override;
	string getPassword() const ;
	string getRole() const;
	string getLogin() const;
	string getLastName() const;
	int getCurrentId() const;
	friend ostream& operator<<(ostream& s, const Employee& e);
	Employee& operator=(const Employee& e);
	bool operator<(const Employee& e) const;

};
#endif