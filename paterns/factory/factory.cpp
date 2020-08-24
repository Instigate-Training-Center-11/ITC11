#include "factory.h"

/* Creating objects with object factories */

int main()
{

  MercedesFactory *Mercedes_Factory = new MercedesFactory;
  BMWFactory *BMW_Factory = new BMWFactory;
  AudiFactory *Audi_Factory = new AudiFactory;

  std::vector<Car *> v;

  v.push_back(Mercedes_Factory->createCar());
  v.push_back(BMW_Factory->createCar());
  v.push_back(Audi_Factory->createCar());

  for (int i = 0; i < v.size(); i++)
  {
    v[i]->info();
  }

  return 0;
}