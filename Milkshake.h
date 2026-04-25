
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
    //Constructors and Deconstructor
    Milkshake(string c, string n, double p, int m, int f);
    Milkshake();
    Milkshake(const Milkshake& m);
    ~Milkshake();

    //initializing the pure methods from Product
    void prepare(Ingredients& s) override;
    string serialize() const override;
    Product* clone() const override;

    //Operators overload
    Milkshake& operator=(const Milkshake& m);
    friend ostream& operator<<(ostream& os, const Milkshake& m);
    friend istream& operator>>(istream& is, Milkshake& m);
};


#endif //TEMA_2_POO_MILKSHAKE_H