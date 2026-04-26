#include "Latte.h"

Latte::Latte(const string& c, const string& n, const double p, const int b, const int w, const int m) : Product(c, n, p), CoffeeBase(c, n, p, b, w), MilkBase(c, n, p, m) {}
Latte::Latte() : Product(), CoffeeBase(), MilkBase() {}
Latte::Latte(const Latte &l) : Product(l), CoffeeBase(l), MilkBase(l) {}

Latte::~Latte() = default;

void Latte::prepare(Ingredients& s) {
    if (s.getBeans() < reqBeans || s.getWater() < reqWater || s.getMilk() < reqMilk)
        throw runtime_error("Insufficient Stock!");

    s.setBeans(s.getBeans()-reqBeans);
    s.setWater(s.getWater()-reqWater);
    s.setMilk(s.getMilk()-reqMilk);
}
string Latte::serialize() const {
    return "COFFEE,"+name+","+to_string(price)+","+to_string(reqBeans)+","+to_string(reqWater)+","+to_string(reqMilk);
}

Product* Latte::clone() const {
    return new Latte(*this);
}


Latte& Latte::operator= (const Latte& l) {
    if (this != &l) {
        Product::operator=(l);
        CoffeeBase::operator=(l);
        MilkBase::operator=(l);
    }
    return *this;
}

ostream& operator<< (ostream& os, const Latte &l) {
    return os << l.serialize();
}

istream& operator>> (istream& is, Latte &l) {
    return is;
}