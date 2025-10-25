#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include <cstring>
using namespace std;
namespace carconfig
{
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
    friend istream& operator>>(istream& s, Model& m);
    friend ostream& operator<<(ostream& s, const Model& m);
    void display() const;
    float getBasePrice() const;
  };
}

#endif