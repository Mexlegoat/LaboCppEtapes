#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>
using namespace std;
#include "Actor.h"
class Client: public Actor
{
private:
	string gsm;
public:
	Client();
	Client(string l, string f, int i, string g);
	Client(const Client& c);
	void setGsm(string g);
	string getGsm() const;
	string tuple() const override;
	string toString() const override;
	friend ostream& operator<<(ostream& s, const Client& c);
	friend istream& operator>>(istream& s, Client& c);
};
#endif