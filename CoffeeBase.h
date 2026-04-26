
#ifndef TEMA_2_POO_COFFEEBASE_H
#define TEMA_2_POO_COFFEEBASE_H

#include <string>
#include "Product.h"
using namespace std;

class CoffeeBase : virtual public Product{
protected:
    int reqBeans, reqWater;
public:
    //Constructors and deconstructor
    CoffeeBase(const string &cat, const string &n, double p, int b, int w);
    CoffeeBase();
    CoffeeBase(const CoffeeBase& c);
    ~CoffeeBase() override;

    //operators overload
    CoffeeBase& operator=(const CoffeeBase& c);
    friend ostream& operator<<(ostream& os, const CoffeeBase& c);
    friend istream& operator>>(istream& is, CoffeeBase& c);
};


#endif //TEMA_2_POO_COFFEEBASE_H