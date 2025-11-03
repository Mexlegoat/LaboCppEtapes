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
  void display();
  void setName(const char* n);
  void setPower(int);
  void setBasePrice(float);
  void setEngine(Engine);
  float getBasePrice();
};
#endif