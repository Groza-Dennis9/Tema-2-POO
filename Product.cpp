#include "Product.h"
#include <iomanip>
#include <iostream>
using namespace std;

string Product::getName() const { return name; }
string Product::getCategory() const { return category; }
double Product::getPrice() const { return price; }

Product::Product(const string& cat, const string& n, const double p) : name(n), category(cat), price(p) {};
Product::Product() : name(" "), category(" "), price(0) {};
Product::Product(const Product &p) {
    name = p.name;
    category = p.category;
    price = p.price;
}

Product& Product::operator=(const Product& p) {
    if (this != &p) {
        name = p.name;
        category = p.category;
        price = p.price;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Product& p) {
    os << left << setw(15) << p.name << " | $" << fixed << setprecision(2) << p.price;
    return os;
}

istream& operator>>(istream& is, Product& p) {
    is >> p.name;
    return is;
}
