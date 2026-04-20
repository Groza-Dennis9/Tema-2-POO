
#ifndef TEMA_2_POO_MILKBASE_H
#define TEMA_2_POO_MILKBASE_H

#include "Product.h"
#include <string>
#include <iostream>
using namespace std;

class MilkBase : virtual public Product{
protected:
    int reqMilk;
public:
    //Constructor
    MilkBase(std::string cat, std::string n, double p, int m);
};


#endif //TEMA_2_POO_MILKBASE_H