#ifndef MODEL_H
#define MODEL_H
#include <iostream>
using namespace std;
enum Engine { Petrol, Diesel, Electric, Hybrid };

class Model
{
private:
  int power;
  float basePrice;
  char* name;
  Engine engine;

public:
  Model();
  Model(const char *n, int power, Engine e, float prix);
  Model(const Model& source);
  ~Model();

  void setName(const char* n);
  void setPower(const int p);
  void setBasePrice(const float b);
  void setEngine(const Engine e);

  void display() const;
  
  int getPower() const;
  const char* getName() const;
  float getBasePrice() const;
  Engine getEngine() const;
};
#endif