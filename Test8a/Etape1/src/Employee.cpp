#include "Employee.h"

/***************************************************************************************************************************/
////////////////////////////////////////////////////////// CONSTRUCTEURS ////////////////////////////////////////////////////
/***************************************************************************************************************************/
const string Employee::ADMINISTRATIVE = "Administratif";
const string Employee::SELLER = "Vendeur";
Employee::Employee():Actor()
{
	login = "None";
	password = nullptr;
}
Employee::Employee(string l, string f, int i, string lo, string r):Actor(l, f ,i)
{
	password = nullptr;
	this->setLogin(lo);
	this->setRole(r);
}
Employee::Employee(const Employee& e):Actor(e)
{
	login = e.login;
	role = e.role;
	if (e.password != nullptr)
		password = new string(*e.password);
	else
		this->password = nullptr;
}
/***************************************************************************************************************************/
////////////////////////////////////////////////////////// DESTRUCTEURS /////////////////////////////////////////////////////
/***************************************************************************************************************************/
Employee::~Employee()
{
	cout << "Destructeur ";
	delete password;
}

/***************************************************************************************************************************/
////////////////////////////////////////////////////////// SETTERS //////////////////////////////////////////////////////////
/***************************************************************************************************************************/
void Employee::setPassword(const string& pw)
{
    delete password;
    password = new string(pw);
}
void Employee::setRole(const string r)
{
	role = r;
}
void Employee::setLogin(string l)
{
	login = l;
}
/***************************************************************************************************************************/
////////////////////////////////////////////////////////// GETTERS //////////////////////////////////////////////////////////
/***************************************************************************************************************************/
string Employee::getPassword() const
{
    if (password != nullptr)
        return *password;
    else
    	return nullptr;
}
string Employee::getRole() const
{
	return role;
}
string Employee::getLogin() const
{
	return login;
}
string Employee::tuple() const
{
	return to_string(this->id) + ";" + this->lastName + ";" + this->firstName + ";" + this->role;
}
string Employee::toString() const
{
	if (role == "Administratif")
	{
		return "[A" + to_string(this->id) + "] " + lastName + " " + firstName;
	}
	else
	{
		return "[V" + to_string(this->id) + "] " + lastName + " " + firstName;
	}
}
/***************************************************************************************************************************/
////////////////////////////////////////////////////////// OPERATORS ////////////////////////////////////////////////////////
/***************************************************************************************************************************/
ostream& operator<<(ostream& s, const Employee& e)
{
	s << "Nom: " << e.lastName << endl << "Prenom: " << e.firstName << endl << "ID: " << e.id << endl << "Login: " << e.login << endl
	<< "Fonction: " << e.role << endl;
	return s;
}
Employee& Employee::operator=(const Employee& e)
{
    if (this != &e) {
        Actor::operator=(e);
        this->login = e.login;
        this->role = e.role;
        
        if (this->password != nullptr) delete this->password;
        if (e.password != nullptr)
            this->password = new string(*e.password);
        else
            this->password = nullptr;
    }
    return *this;
}