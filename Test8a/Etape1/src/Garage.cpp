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
		cout << "Index " << index << ": " << it->toString() << endl;
		index++;
	}
}
Model Garage::getModel(int index) const
{
	auto it = models.cbegin();
	advance(it, index); // faire avancer it jusqu'à index;
	return *it;
}