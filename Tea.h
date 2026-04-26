
#ifndef TEMA_2_POO_TEA_H
#define TEMA_2_POO_TEA_H

#include "Product.h"
#include <string>
using namespace std;

class Tea : public Product{
private:
    int reqWater, reqBags;
public:
    //Constructors and Destructor
    Tea(const string& c, const string &n, double p, int w, int t);
    Tea();
    Tea(const Tea& c);
    ~Tea() override;

    //Initializing the pure methods from Product
    void prepare(Ingredients& s) override;
    string serialize() const override;
    Product* clone() const override;

    //Operators overload
    Tea& operator=(const Tea& c);
    friend ostream& operator<<(ostream& os, const Tea& c);
    friend istream& operator>>(istream& is, Tea& c);
};


#endif //TEMA_2_POO_TEA_H