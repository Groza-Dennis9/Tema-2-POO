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