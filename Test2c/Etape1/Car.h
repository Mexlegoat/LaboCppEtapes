#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <string>
#include "Model.h"
#include "Option.h"
using namespace std;
using namespace carconfig;
class Car
{
private:
	char* name;
	Model model;
	Option* option[5];

public:
	Car();
	~Car();
	Car(const char* n, Model m);
	void display();
	void setName(const char* n);
	void setModel(Model m);
	Model getModel();
	char* getName();
};
#endif