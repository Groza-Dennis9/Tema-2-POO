#include "Ingredients.h"

ostream& operator<<(ostream& os, const Ingredients& i) {
    os << "Beans: " << i.beans << "g | Milk: " << i.milk << "ml | Water: " << i.water << "ml\n"
       << "Fruit: " << i.fruit << "pcs | Tea: " << i.tea << "bags | Snacks: " << i.snacks << "pcs";
    return os;
}