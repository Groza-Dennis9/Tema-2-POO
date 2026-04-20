#include "Milkshake.h"

void Milkshake::prepare(Ingredients& s) {
    if (s.getMilk() < reqMilk || s.getFruit() < reqFruit)
        throw std::runtime_error("Insufficient Stock!");

    s.setMilk(s.getMilk()-reqMilk);
    s.setFruit(s.getFruit()-reqFruit);
}

string Milkshake::serialize() const {
    return "NON-COFFEE,"+name+","+to_string(price)+","+to_string(reqMilk)+","+to_string(reqFruit);
}