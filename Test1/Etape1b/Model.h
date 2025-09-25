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
  ~Model();
  void display();
  void setName(const char* modelName);
  void setPower(int power);
  void setEngine(Engine engine);
  void setBasePrice(float basePrice);
  const char* getName();
  int getPower();
  Engine getEngine();
  float getBasePrice();
};