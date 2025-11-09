#include "Garage.h"
void Garage::addModel(const Model& m)
{
	models.push_back(m);
}
void Garage::displayAllModels() const
{
	int index = 0;
	for(list<Model>::const_iterator it = models.cbegin(); it != models.cend(); it++)
	{
		cout << "Modele " << index << ": " << it->toString() << endl;
		index++;
	}
}
Model Garage::getModel(int index) const
{
	auto it = models.cbegin();
	advance(it, index); // faire avancer it jusqu'à index;
	return *it;
}
void Garage::addOption(const Option& o)
{
	options.push_back(o);
}
void Garage::displayAllOptions() const
{
	int index = 0;
	for (list<Option>::const_iterator it = options.cbegin(); it != options.cend(); it++)
	{
		cout << "Option " << index << ": " << it->toString() << endl;
	}
}
Option Garage::getOption(int index)
{
	auto it = options.cbegin();
	advance(it, index);
	return *it;
}