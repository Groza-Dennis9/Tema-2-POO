
#ifndef TEMA_2_POO_LATTE_H
#define TEMA_2_POO_LATTE_H

#include "CoffeeBase.h"
#include "MilkBase.h"
#include <string>
using namespace std;

class Latte : public CoffeeBase, public MilkBase {
public:
    //Constructor
    Latte(string c, string n, double p, int b, int w, int m) : Product(c, n, p), CoffeeBase(c, n, p, b, w), MilkBase(c, n, p, m) {}

    //initializing the pure methods from Product
    void prepare(Ingredients& s) override;
    string serialize() const override;
};


#endif //TEMA_2_POO_LATTE_H