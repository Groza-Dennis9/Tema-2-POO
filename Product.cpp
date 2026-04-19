
#include "Product.h"
#include <iomanip>
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const Product& p) {
    os << left << setw(15) << p.name << " | $" << fixed << setprecision(2) << p.price;
    return os;
}

