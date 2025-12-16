#include "Contract.h"
int Contract::currentId = 1;
Contract::Contract()
{
	id = 0;
	client = "";
	seller = "";
	projectName = "";
}
Contract::Contract(int i, string s, string c, string p)
{
	setId(i);
	setClient(c);
	setSeller(s);
	setProjectName(p);
}
void Contract::setId(int i)
{
	id = i;
}
void Contract::setSeller(string s)
{
	seller = s;
}
void Contract::setClient(string c)
{
	client = c;
}
void Contract::setProjectName(string p)
{
	projectName = p;
}
int Contract::getId()const
{
	return id;
}
string Contract::getSeller()const
{
	return seller;
}
string Contract::getClient()const
{
	return client;
}
string Contract::getProjectName()const
{
	return projectName;
}
ostream& operator<<(ostream& o, const Contract& c)
{
	o << "<Contract>" << endl;
	o << "<id>" << endl;
	o << c.getId() << endl;
	o << "</id>" << endl;
	o << "<seller>" << endl;
	o << c.getSeller() << endl;
	o << "</seller>" << endl;
	o << "<client>" << endl;
	o << c.getClient() << endl;
	o << "</client>" << endl;
	o << "<projectName>" << endl;
	o << c.getProjectName() << endl;
	o << "</projectName>" << endl;
	o << "</Contract>";
	return o;
}
istream& operator>>(istream& s, Contract& c)
{
	string line;
	getline(s, line);
	getline(s, line);
	getline(s, line);
	c.setId(stoi(line));
	getline(s, line);
	getline(s, line);
	getline(s, line);
	c.setSeller(line);
	getline(s, line);
	getline(s, line);
	getline(s, line);
	c.setClient(line);
	getline(s, line);
	getline(s, line);
	getline(s, line);
	c.setProjectName(line);
	getline(s, line);
	getline(s, line);
	return s;
}
string Contract::tuple() const
{
	return to_string(id) + ";" + this->getSeller() + ";" + this->getClient() + ";" + this->getProjectName();
}
Contract& Contract::operator=(const Contract& c)
{
	setId(c.getId());
	setSeller(c.getSeller());
	setClient(c.getClient());
	setProjectName(c.getProjectName());
	return *this;
}
bool Contract::operator<(const Contract& c) const
{
	return this->getSeller() < c.getSeller();
}