
#ifndef TEMA_2_POO_MILKSHAKE_H
#define TEMA_2_POO_MILKSHAKE_H

#include "MilkBase.h"
#include <iostream>
#include <string>
using namespace std;

class Milkshake : public MilkBase {
private:
    int reqFruit;
public:
    //Constructor
    Milkshake(string c, string n, double p, int m, int f) : Product(c,n,p), MilkBase(c,n,p,m), reqFruit(f) {}

    //initializing the pure methods from Product
    void prepare(Ingredients& s) override;
    string serialize() const override;
};


#endif //TEMA_2_POO_MILKSHAKE_H