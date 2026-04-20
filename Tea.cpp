#include "Tea.h"

void Tea::prepare(Ingredients& s) {
    if (s.getWater() < reqWater || s.getTea() < reqBags)
        throw std::runtime_error("Insufficient Stock!");

    s.setWater(s.getWater()-reqWater);
    s.setTea(s.getTea()-reqBags);
}

string Tea::serialize() const {
    return "NON-COFFEE,"+name+","+to_string(price)+","+to_string(reqWater)+","+to_string(reqBags);
}