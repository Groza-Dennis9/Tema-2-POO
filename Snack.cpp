#include "Snack.h"

void Snack::prepare(Ingredients& s) {
    if (s.getSnacks() <= 0)
        throw std::runtime_error("Out of Snacks!");

    s.setSnacks(s.getSnacks()-1);
}
string Snack::serialize() const {
    return "SWEET,"+name+","+to_string(price)+","+to_string(cal);
}
