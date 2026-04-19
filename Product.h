
#ifndef TEMA_2_POO_PRODUCT_H
#define TEMA_2_POO_PRODUCT_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Ingredients.h"
using namespace std;

class Product {
protected:
    string name, category;
    double price;

public:
    Product(string cat, string n, double p) : name(n), category(cat), price(p) {}
    virtual ~Product() {}

    virtual void prepare(Ingredients& s) = 0;

    friend ostream& operator<<(ostream& os, const Product& p);

};


#endif //TEMA_2_POO_PRODUCT_H