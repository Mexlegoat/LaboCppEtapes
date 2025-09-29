#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <string>
#include "Model.h"
using namespace std;

class Car
{
private:
	char* name;
	Model model;

public:
	Car();
	~Car();
	void display();
	void setName(const char* n);
	void setModel(Model m);
	Model getModel();
	char* getName();
};
#endif