
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
    //Constructors and Deconstructor
    MilkBase(string cat, string n, double p, int m);
    MilkBase();
    MilkBase(const MilkBase&);
    ~MilkBase();

    //Operators overload
    MilkBase& operator=(const MilkBase& m);
    friend ostream& operator<<(ostream& os, const MilkBase& m);
    friend istream& operator>>(istream& is, MilkBase& m);
};


#endif //TEMA_2_POO_MILKBASE_H