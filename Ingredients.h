
#ifndef TEMA_2_POO_INGREDIENTS_H
#define TEMA_2_POO_INGREDIENTS_H

#include <iostream>
using namespace std;

class Ingredients {
private:
    int beans, milk, water, fruit, tea, snacks;

    //Error catching
    static void validate(int value) ;

public:
    //Constructors
    Ingredients();
    Ingredients(int b, int m, int w, int f, int t, int s);
    Ingredients(const Ingredients& i);
    ~Ingredients();

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

    //operators overload
    Ingredients& operator=(const Ingredients& i);
    friend ostream& operator<<(ostream& os, const Ingredients& i);
    friend istream& operator>>(istream& is, Ingredients& i);
};


#endif //TEMA_2_POO_INGREDIENTS_H