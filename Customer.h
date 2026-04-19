
#ifndef TEMA_2_POO_CUSTOMER_H
#define TEMA_2_POO_CUSTOMER_H

#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
    string name;
    int points;

public:
    Customer() : name(""), points(0) {}
    Customer(string n, int p) : name(n), points(p) {}

    friend std::ostream& operator<<(std::ostream& os, const Customer& c);
};


#endif //TEMA_2_POO_CUSTOMER_H