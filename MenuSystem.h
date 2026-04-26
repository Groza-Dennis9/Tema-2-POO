
#ifndef TEMA_2_POO_MENUSYSTEM_H
#define TEMA_2_POO_MENUSYSTEM_H

#include "ShopManager.h"
#include <iostream>
using namespace std;

class MenuSystem {
private:
    ShopManager& shop;
    const string ADMIN_PASSWORD = "coffee123";

    static int getChoiceInRange(int min, int max);

public:
    //Constructor for running the game
    MenuSystem(ShopManager& s) : shop(s) {}

    void header() const;
    void admin() const;
    void customer() const;

    static void pause();
    void run() const;
};


#endif //TEMA_2_POO_MENUSYSTEM_H