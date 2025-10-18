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
	return "Nom: " + this->lastName + " Prenom : " + this->firstName + " ID : " + to_string(this->id);
}
string Client::toString() const
{
	return lastName + " " + firstName + " id: " + to_string(id) + " gsm: " + gsm;
}
ostream& operator<<(ostream& s, const Client& c)
{
	s << c.toString();
	return s;
}