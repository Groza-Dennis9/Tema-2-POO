
#ifndef TEMA_2_POO_INGREDIENTS_H
#define TEMA_2_POO_INGREDIENTS_H

#include <iostream>
using namespace std;

class Ingredients {
private:
    int beans, milk, water, fruit, tea, snacks;
public:
    Ingredients() : beans(0), milk(0), water(0), fruit(0), tea(0), snacks(0) {}
    Ingredients(int b, int m, int w, const int f, int t, int s) : beans(b), milk(m), water(w), fruit(f), tea(t), snacks(s) {}

    friend ostream& operator<<(ostream& os, const Ingredients& i);
};


#endif //TEMA_2_POO_INGREDIENTS_H