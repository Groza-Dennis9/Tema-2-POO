
#ifndef TEMA_2_POO_INGREDIENTS_H
#define TEMA_2_POO_INGREDIENTS_H

#include <iostream>
using namespace std;

class Ingredients {
private:
    int beans, milk, water, fruit, tea, snacks;

    //Error catching
    void validate(int value) const;

public:
    //Constructors
    Ingredients() : beans(0), milk(0), water(0), fruit(0), tea(0), snacks(0) {}
    Ingredients(int b, int m, int w, const int f, int t, int s) : beans(b), milk(m), water(w), fruit(f), tea(t), snacks(s) {}

    //Getters
    int getBeans() const;
    int getMilk() const;
    int getWater() const;
    int getFruit() const;
    int getTea() const;
    int getSnacks() const;

    //Setters
    void setBeans(int v);
    void setMilk(int v);
    void setWater(int v);
    void setFruit(int v);
    void setTea(int v);
    void setSnacks(int v);

    friend ostream& operator<<(ostream& os, const Ingredients& i);
};


#endif //TEMA_2_POO_INGREDIENTS_H