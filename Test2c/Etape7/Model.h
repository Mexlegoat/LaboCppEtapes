#ifndef MODEL_H
#define MODEL_H
#include <iostream>
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
    void display();

    void setName(const char* n);
    void setPower(const int p);
    void setBasePrice(const float b);
    void setEngine(const Engine e);
    
    float getBasePrice();
  };
}

#endif