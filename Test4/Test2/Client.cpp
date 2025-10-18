#include "Client.h"
Client::Client():Actor()
{
	gsm = "0/0";
}
Client::Client(string l, string f, int i, string g):Actor(l, f, i)
{
	this->setGsm(g);
}
Client::Client(const Client& c):Actor(c)
{
	setGsm(c.gsm);
}
void Client::setGsm(string g)
{
	gsm = g;
}

string Client::getGsm() const
{
	return gsm;
}

string Client::tuple() const
{
	return to_string(this->id) + ";" + this->lastName + ";" + this->firstName + ";" + this->gsm;
}
string Client::toString() const
{
	return "[C" + to_string(this->id) + "] " + lastName + " " + firstName;
}
ostream& operator<<(ostream& s, const Client& c)
{
	s << c.tuple();
	return s;
}