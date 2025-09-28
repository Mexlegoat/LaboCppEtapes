#include <iostream>
#include <string>
#include "Model.h"
using namespace std;

class Car
{
private:
	char* name;
	// Model model;

public:
	Car();
	~Car();
	void display();
};