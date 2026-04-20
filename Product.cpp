#include "Product.h"
#include <iomanip>
#include <iostream>
using namespace std;

string Product::getName() const { return name; }
string Product::getCategory() const { return category; }
double Product::getPrice() const { return price; }

ostream& operator<<(ostream& os, const Product& p) {
    os << left << setw(15) << p.name << " | $" << fixed << setprecision(2) << p.price;
    return os;
}

