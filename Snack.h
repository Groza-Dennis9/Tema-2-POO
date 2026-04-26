
#ifndef TEMA_2_POO_SNACK_H
#define TEMA_2_POO_SNACK_H

#include "Product.h"
#include <string>
using namespace std;

class Snack : public Product {
private:
    int cal;
public:
    //Constructors and Deconstructor
    Snack(const string& cat, const string& n, double p, int c);
    Snack();
    Snack(const Snack& s);
    ~Snack() override;

    //initializing the pure methods from Product
    void prepare(Ingredients& s) override;
    string serialize() const override;
    Product* clone() const override;

    //Operators overload
    Snack& operator=(const Snack& s);
    friend istream& operator>>(istream& is, Snack& s);
    friend ostream& operator<<(ostream& os, const Snack& s);
};


#endif //TEMA_2_POO_SNACK_H