
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
    Customer();
    Customer(string n, int p);
    Customer (const Customer &c);
    ~Customer();

    //Getters
    string getName() const;
    int getPoints() const;
    double getDiscount() const;

    //Setter
    void addPoints(int p);

    //Operators overload
    Customer& operator=(const Customer& c);
    friend ostream& operator<<(ostream& os, const Customer& c);
    friend istream& operator>>(istream& is, Customer& c);
};


#endif //TEMA_2_POO_CUSTOMER_H