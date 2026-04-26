#include "Tea.h"

Tea::Tea(const string& c, const string &n, const double p, const int w, const int t) : Product(c,n,p), reqWater(w), reqBags(t) {}
Tea::Tea() : Product(), reqWater(0), reqBags(0) {}
Tea::Tea(const Tea &c) : Product(c) {
    reqWater = c.reqWater;
    reqBags = c.reqBags;
}
Tea::~Tea() = default;


void Tea::prepare(Ingredients& s) {
    if (s.getWater() < reqWater || s.getTea() < reqBags)
        throw std::runtime_error("Insufficient Stock!");

    s.setWater(s.getWater()-reqWater);
    s.setTea(s.getTea()-reqBags);
}

string Tea::serialize() const {
    return "NON-COFFEE,"+name+","+to_string(price)+","+to_string(reqWater)+","+to_string(reqBags);
}

Product* Tea::clone() const {
    return new Tea(*this);
}

Tea& Tea::operator=(const Tea& c) {
    if (this != &c) {
        Product::operator=(c);
        reqWater = c.reqWater;
        reqBags = c.reqBags;
    }
     return *this;
}
ostream& operator<<(ostream& os, const Tea& c) {
    os << c.serialize();
    return os;
}

istream& operator>>(istream& is, Tea& c) {
    is >> c.reqWater >> c.reqBags;
    return is;
}