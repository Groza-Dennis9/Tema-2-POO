#include "Ingredients.h"

void Ingredients::validate(int value) const {
    if (value < 0) throw std::invalid_argument("Stock amount cannot be negative!");
}

int Ingredients::getBeans() const { return beans; }
int Ingredients::getMilk() const { return milk; }
int Ingredients::getWater() const { return water; }
int Ingredients::getFruit() const { return fruit; }
int Ingredients::getTea() const { return tea; }
int Ingredients::getSnacks() const { return snacks; }

void Ingredients::setBeans(int v) { validate(v); beans = v; }
void Ingredients::setMilk(int v) { validate(v); milk = v; }
void Ingredients::setWater(int v) { validate(v); water = v; }
void Ingredients::setFruit(int v) { validate(v); fruit = v; }
void Ingredients::setTea(int v) { validate(v); tea = v; }
void Ingredients::setSnacks(int v) { validate(v); snacks = v; }

ostream& operator<<(ostream& os, const Ingredients& i) {
    os << "Beans: " << i.beans << "g | Milk: " << i.milk << "ml | Water: " << i.water << "ml\n"
       << "Fruit: " << i.fruit << "pcs | Tea: " << i.tea << "bags | Snacks: " << i.snacks << "pcs";
    return os;
}