
#ifndef TEMA_2_POO_LATTE_H
#define TEMA_2_POO_LATTE_H

#include "CoffeeBase.h"
#include "MilkBase.h"
#include <string>
using namespace std;

class Latte : public CoffeeBase, public MilkBase {
public:
    //Constructor
    Latte(const string& c, const string& n, double p, int b, int w, int m);
    Latte();
    Latte(const Latte& l);
    ~Latte() override;

    //initializing the pure methods for Product
    void prepare(Ingredients& s) override;
    string serialize() const override;
    Product* clone() const override;

    //operators overload
    Latte& operator= (const Latte& l);
    friend ostream& operator<< (ostream& os, const Latte &l);
    friend istream& operator>> (istream& is, Latte &l);
};


#endif //TEMA_2_POO_LATTE_H