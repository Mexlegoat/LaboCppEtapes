#ifndef ACTOR_H
#define ACTOR_H
#include <iostream>
#include <string>
using namespace std;
#include "Person.h"
class Actor: public Person
{
public:
	static int currentId;
protected:
	int id;
public:
	Actor();
	Actor(string l, string f, int i);
	Actor(const Actor& a);
	void setId(int);
	int getId() const;
	// virtual
	virtual ~Actor() = default;
	virtual string tuple() const = 0;
	virtual string toString() const = 0;
};
#endif