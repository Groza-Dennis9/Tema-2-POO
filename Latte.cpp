#include "Latte.h"

void Latte::prepare(Ingredients& s) {
    if (s.getBeans() < reqBeans || s.getWater() < reqWater || s.getMilk() < reqMilk)
        throw std::runtime_error("Insufficient Stock!");

    s.setBeans(s.getBeans()-reqBeans);
    s.setWater(s.getWater()-reqWater);
    s.setMilk(s.getMilk()-reqMilk);
}
string Latte::serialize() const {
    return "COFFEE,"+name+","+to_string(price)+","+to_string(reqBeans)+","+to_string(reqWater)+","+to_string(reqMilk);
}