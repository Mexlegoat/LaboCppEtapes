#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <string>
#include "Model.h"
using namespace std;

class Car
{
private:
	string name;
	Model model;

public:
	Car();
	Car(const string nom, Model m);
	Car(const Car &source);
	void display();
	void setName(const string n);
	void setModel(Model m);
	Model getModel();
	string getName();
};
#endif