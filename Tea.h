
#ifndef TEMA_2_POO_TEA_H
#define TEMA_2_POO_TEA_H

#include "Product.h"
#include <string>
using namespace std;

class Tea : public Product{
private:
    int reqWater, reqBags;
public:
    //Constructor
    Tea(string c, string n, double p, int w, int t) : Product(c,n,p), reqWater(w), reqBags(t) {}

    //initializing the pure methods from Product
    void prepare(Ingredients& s) override;
    string serialize() const override;
};


#endif //TEMA_2_POO_TEA_H