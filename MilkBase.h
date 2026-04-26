
#ifndef TEMA_2_POO_MILKBASE_H
#define TEMA_2_POO_MILKBASE_H

#include "Product.h"
#include <string>
using namespace std;

class MilkBase : virtual public Product{
protected:
    int reqMilk;
public:
    //Constructors and Deconstructor
    MilkBase(const string &cat, const string &n, double p, int m);
    MilkBase();
    MilkBase(const MilkBase&);
    ~MilkBase() override;

    //Operators overload
    MilkBase& operator=(const MilkBase& m);
    friend ostream& operator<<(ostream& os, const MilkBase& m);
    friend istream& operator>>(istream& is, MilkBase& m);
};


#endif //TEMA_2_POO_MILKBASE_H