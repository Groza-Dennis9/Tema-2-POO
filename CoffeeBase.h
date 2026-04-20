
#ifndef TEMA_2_POO_COFFEEBASE_H
#define TEMA_2_POO_COFFEEBASE_H

#include <iostream>
#include <string>
#include "Product.h"
using namespace std;

class CoffeeBase : virtual public Product{
protected:
    int reqBeans, reqWater;
public:
    //Constructor
    CoffeeBase(string cat, string n, double p, int b, int w);
};


#endif //TEMA_2_POO_COFFEEBASE_H