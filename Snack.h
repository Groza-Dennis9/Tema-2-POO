
#ifndef TEMA_2_POO_SNACK_H
#define TEMA_2_POO_SNACK_H

#include "Product.h"
#include <string>
#include <iostream>
using namespace std;

class Snack : public Product {
private:
    int cal;
public:
    //Constructor
    Snack(string cat, string n, double p, int c) : Product(cat, n, p), cal(c) {}

    //initializing the pure methods from Product
    void prepare(Ingredients& s) override;
    string serialize() const override;
};


#endif //TEMA_2_POO_SNACK_H