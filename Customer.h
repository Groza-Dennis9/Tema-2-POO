
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
    //Constructors
    Customer() : name(""), points(0) {}
    Customer(string n, int p) : name(n), points(p) {}

    //Getters
    string getName() const;
    int getPoints() const;
    double getDiscount() const;

    //Setter
    void addPoints(int p);

    friend std::ostream& operator<<(std::ostream& os, const Customer& c);
};


#endif //TEMA_2_POO_CUSTOMER_H