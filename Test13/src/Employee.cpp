#include "Employee.h"

/***************************************************************************************************************************/
////////////////////////////////////////////////////////// CONSTRUCTEURS ////////////////////////////////////////////////////
/***************************************************************************************************************************/
const string Employee::ADMINISTRATIVE = "Administratif";
const string Employee::SELLER = "Vendeur";
Employee::Employee():Actor()
{
	login = "";
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
	if (password != nullptr) delete password;
}

/***************************************************************************************************************************/
////////////////////////////////////////////////////////// SETTERS //////////////////////////////////////////////////////////
/***************************************************************************************************************************/
void Employee::setPassword(const string& pw)
{
    if (password != nullptr) delete password;
    if (pw.length() < 6)
    {
    	throw PasswordException(PasswordException::INVALID_LENGTH, "Le mot de passe doit avoir au minimum 6 lettres");
    }
    char c;
    bool lettre = false, chiffre = false;
    for(int i = 0; i < pw.length(); i++)
    {
    	c = pw[i];
    	if (isalpha(c))
    	{
    		lettre = true;
    	}
    	if (isdigit(c))
    	{
    		chiffre = true;
    	}
    }
    if (!lettre)
    {
    	throw PasswordException(PasswordException::ALPHA_MISSING, "Mot de passe invalide, il doit contenir au moins 1 lettre");
    }
    if (!chiffre)
    {
    	throw PasswordException(PasswordException::DIGIT_MISSING, "Mot de passe invalide, il doit contenir au moins 1 chiffre");
    }
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
void Employee::setRole(int r)
{
	switch(r)
	{
		case 0:
			role = Employee::ADMINISTRATIVE;
			break;
		case 1:
			role = Employee::SELLER;
			break;
	}
}
/***************************************************************************************************************************/
////////////////////////////////////////////////////////// GETTERS //////////////////////////////////////////////////////////
/***************************************************************************************************************************/
string Employee::getPassword() const
{
    if (password != nullptr)
        return *password;
    else
    	throw PasswordException(PasswordException::NO_PASSWORD, "L'utilisateur n'a pas encore de mot de passe, vous devez en creer un");
}
string Employee::getRole() const
{
	return role;
}
string Employee::getLogin() const
{
	return login;
}
string Employee::getLastName() const
{
	return lastName;
}
int Employee::getId() const
{
	return this->id;
}
string Employee::tuple() const
{
	return to_string(this->id) + ";" + this->lastName + ";" + this->firstName + ";" + this->role;
}
string Employee::toString() const
{
	if (role == Employee::ADMINISTRATIVE)
	{
		return "[A" + to_string(this->id) + "] " + lastName + " " + firstName;
	}
	else
	{
		return "[V" + to_string(this->id) + "] " + lastName + " " + firstName;
	}
}
void Employee::resetPassword()
{
	if (password != nullptr)
		delete password;
	password = nullptr;
}
/***************************************************************************************************************************/
////////////////////////////////////////////////////////// OPERATORS ////////////////////////////////////////////////////////
/***************************************************************************************************************************/
ostream& operator<<(ostream& s, const Employee& e)
{
	s << "<Employee>" << endl;
	s << "<lastName>" << endl;
	s << e.lastName << endl;
	s << "</lastName>" << endl;
	s << "<firstName>" << endl;
	s << e.firstName << endl;
	s << "</firstName>" << endl;
	s << "<id>" << endl;
	s << e.id << endl;
	s << "</id>" << endl;
	s << "<login>" << endl;
	s << e.login << endl;
	s << "</login>" << endl;
	s << "<role>" << endl;
	s << e.role << endl;
	s << "</role>" << endl;
	s << "</Employee>";


	return s;
}
istream& operator>>(istream& s, Employee& e)
{
	string line;
	getline(s, line);
	getline(s, line);
	getline(s, line);
	e.setLastName(line);
	getline(s, line);
	getline(s, line);
	getline(s, line);
	e.setFirstName(line);
	getline(s, line);
	getline(s, line);
	getline(s, line);
	e.setId(stoi(line));
	getline(s, line);
	getline(s, line);
	getline(s, line);
	e.setLogin(line);
	getline(s, line);
	getline(s, line);
	getline(s, line);
	e.setRole(line);
	getline(s, line);
	getline(s, line);
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
bool Employee::operator<(const Employee& e) const
{
	return this->getLastName() < e.getLastName();
}
void Employee::display() const
{
	if (password != nullptr)
		cout << "Mot de passe employe actuel: " << password << endl;
	else
		cout << "Pas de mot de passe" << endl;
}