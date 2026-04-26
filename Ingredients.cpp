#include "Ingredients.h"

Ingredients::Ingredients() : beans(0), milk(0), water(0), fruit(0), tea(0), snacks(0) {}
Ingredients::Ingredients(const int b, const int m, const int w, const int f, const int t, const int s) : beans(b), milk(m), water(w), fruit(f), tea(t), snacks(s) {}

Ingredients::Ingredients(const Ingredients &i) {
    beans = i.beans;
    milk = i.milk;
    water = i.water;
    fruit = i.fruit;
    tea = i.tea;
    snacks = i.snacks;
}

Ingredients::~Ingredients() = default;

void Ingredients::validate(const int value) {
    if (value < 0)
        throw invalid_argument("Stock amount cannot be negative!");
}

int Ingredients::getBeans() const { return beans; }
int Ingredients::getMilk() const { return milk; }
int Ingredients::getWater() const { return water; }
int Ingredients::getFruit() const { return fruit; }
int Ingredients::getTea() const { return tea; }
int Ingredients::getSnacks() const { return snacks; }

void Ingredients::setBeans(const int v) { validate(v); beans = v; }
void Ingredients::setMilk(const int v) { validate(v); milk = v; }
void Ingredients::setWater(const int v) { validate(v); water = v; }
void Ingredients::setFruit(const int v) { validate(v); fruit = v; }
void Ingredients::setTea(const int v) { validate(v); tea = v; }
void Ingredients::setSnacks(const int v) { validate(v); snacks = v; }


Ingredients& Ingredients::operator=(const Ingredients& i) {
    if (this != &i) {
        beans = i.beans;
        milk = i.milk;
        water = i.water;
        fruit = i.fruit;
        tea = i.tea;
        snacks = i.snacks;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Ingredients& i) {
    os << "Beans: " << i.beans << "g | Milk: " << i.milk << "ml | Water: " << i.water << "ml\n"
       << "Fruit: " << i.fruit << "pcs | Tea: " << i.tea << "bags | Snacks: " << i.snacks << "pcs";
    return os;
}

istream& operator>>(istream& is, Ingredients& i) {
    is >> i.beans >> i.milk >> i.water >> i.fruit >> i.tea >> i.snacks;
    return is;
}