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
    string image;
  public:
    Model();
    Model(const char *n, int power, Engine e, float prix);
    Model(const Model& m);
    ~Model();
    friend istream& operator>>(istream& s, Model& m);
    friend ostream& operator<<(ostream& s, const Model& m);

    Model& operator=(const Model&);

    void display() const;

    void setPower(int);
    void setBasePrice(float);
    void setName(const char*);
    void setEngine(Engine e);
    void setEngine(int e);
    void setEngine(string e);
    void setImage(const string& i);


    string enginetoString(Engine e) const;
    string toString() const;


    float getBasePrice() const;
    const char* getName() const;
    int getPower() const;
    Engine getEngine() const;
    string getImage() const;
  };
}

#endif