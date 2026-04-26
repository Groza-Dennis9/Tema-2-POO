
#ifndef TEMA_2_POO_PRODUCT_H
#define TEMA_2_POO_PRODUCT_H

#include <string>
#include <iomanip>
#include "Ingredients.h"
using namespace std;

class Product {
protected:
    string name, category;
    double price;

public:
    virtual ~Product() = default;

    //Constructors and Destructor
    Product(const string& cat, const string& n, double p);
    Product();
    Product (const Product& p);

    //the ingredients of every product
    virtual void prepare(Ingredients& s) = 0;
    //the way each product has to be saved in a separate file
    virtual string serialize() const = 0;
    //for identifying each type of element for the menu
    virtual Product* clone() const = 0;

    //Getters
    string getName() const;
    string getCategory() const;
    double getPrice() const;

    //Operators overload
    Product& operator=(const Product& p);
    friend ostream& operator<<(ostream& os, const Product& p);
    friend istream& operator>>(istream& is, Product& p);
};


#endif //TEMA_2_POO_PRODUCT_H