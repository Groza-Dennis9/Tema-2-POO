
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
    //Constructor and Destructor
    Product(string cat, string n, double p) : name(n), category(cat), price(p) {}
    virtual ~Product() {}

    //the ingredients of every product
    virtual void prepare(Ingredients& s) = 0;
    //the way each product has to be saved in a separate file
    virtual std::string serialize() const = 0;

    //Getters
    string getName() const;
    string getCategory() const;
    double getPrice() const;

    friend ostream& operator<<(ostream& os, const Product& p);
};


#endif //TEMA_2_POO_PRODUCT_H