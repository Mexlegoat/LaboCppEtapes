#include <iostream>
#include <cstring>
using namespace std;
class Person
{
protected:
	string lastName;
	string firstName;
public:
	// constructeurs
	Person();
	Person(const string l,const string f);
	// setters
	void setFirstName(const string f);
	void setLastName(const string l);
	// getters
	string getLastName() const;
	string getFirstName() const;
	// operators
	Person& operator=(const Person& p);
	friend istream& operator>>(istream& s, Person& p);
	friend ostream& operator<<(ostream& s, const Person& p);
};