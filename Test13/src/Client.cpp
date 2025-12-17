#include "Client.h"

/***************************************************************************************************************************/
////////////////////////////////////////////////////////// CONSTRUCTEURS ////////////////////////////////////////////////////
/***************************************************************************************************************************/
Client::Client():Actor()
{
	gsm = "";
}
Client::Client(string l, string f, int i, string g):Actor(l, f, i)
{
	this->setGsm(g);
}
Client::Client(const Client& c):Actor(c)
{
	setGsm(c.gsm);
}
/***************************************************************************************************************************/
////////////////////////////////////////////////////////// SETTERS //////////////////////////////////////////////////////////
/***************************************************************************************************************************/
void Client::setGsm(string g)
{
	gsm = g;
}
/***************************************************************************************************************************/
////////////////////////////////////////////////////////// GETTERS //////////////////////////////////////////////////////////
/***************************************************************************************************************************/
string Client::getGsm() const
{
	return gsm;
}
string Client::getLastName() const
{
	return lastName;
}
int Client::getId() const
{
	return this->id;
}
// Affichage
string Client::tuple() const 
{
	return to_string(this->id) + ";" + this->lastName + ";" + this->firstName + ";" + this->gsm;
}
string Client::toString() const 
{
	return "[C" + to_string(this->id) + "] " + lastName + " " + firstName;
}
/***************************************************************************************************************************/
////////////////////////////////////////////////////////// OPERATORS ////////////////////////////////////////////////////////
/***************************************************************************************************************************/
ostream& operator<<(ostream& s, const Client& c)
{
	s << "<Client>" << endl;
	s << "<lastName>" << endl;
	s << c.lastName << endl;
	s << "</lastName>" << endl;
	s << "<firstName>" << endl;
	s << c.firstName << endl;
	s << "</firstName>" << endl;
	s << "<id>" << endl;
	s << c.id << endl;
	s << "</id>" << endl;
	s << "<gsm>" << endl;
	s << c.gsm << endl;
	s << "</gsm>" << endl;
	s << "</Client>";
	return s;
}
istream& operator>>(istream& s, Client& c)
{
	string line;
	getline(s, line); // car
	getline(s, line); // lastName
	getline(s, line); // variable
	c.setLastName(line);
	getline(s, line); // /lastName
	getline(s, line); // firstName
	getline(s, line); // variable
	c.setFirstName(line);
	getline(s, line); // /firstName
	getline(s, line); // id
	getline(s, line); // id
	c.setId(stoi(line));
	getline(s, line); // /id
	getline(s, line); // gsm
	getline(s, line); // variable
	c.setGsm(line);
	getline(s, line); // /gsm
	getline(s, line); // /Client
	return s;
}
bool Client::operator<(const Client& c) const
{
	return this->getLastName() < c.getLastName();
}