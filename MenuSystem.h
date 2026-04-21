
#ifndef TEMA_2_POO_MENUSYSTEM_H
#define TEMA_2_POO_MENUSYSTEM_H

#include "ShopManager.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class MenuSystem {
private:
    ShopManager& shop;

    int getChoiceInRange(int min, int max);

public:
MenuSystem(ShopManager& s) : shop(s) {}
    void header();

    void admin();

    void customer();

    void pause();

    void run();
};


#endif //TEMA_2_POO_MENUSYSTEM_H