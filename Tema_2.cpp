//
// Created by kitty on 4/16/2026.
//

#include "ShopManager.h"
#include "MenuSystem.h"
#include <iostream>
using namespace std;


int main() {
    ShopManager s;
    MenuSystem m(s);
    m.run();

    return 0;
}