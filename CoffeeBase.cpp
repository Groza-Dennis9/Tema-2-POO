#include "CoffeeBase.h"

CoffeeBase::CoffeeBase(const string &cat, const string &n, const double p, const int b, const int w) : Product(cat, n, p) {
    reqBeans = b;
    reqWater = w;
}

CoffeeBase::CoffeeBase() : Product(), reqBeans(0), reqWater(0) {}

CoffeeBase::CoffeeBase(const CoffeeBase &c) : Product(c) {
    reqBeans = c.reqBeans;
    reqWater = c.reqWater;
}
CoffeeBase::~CoffeeBase() = default;

CoffeeBase& CoffeeBase:: operator=(const CoffeeBase& c) {
    if (this != &c) {
        reqBeans = c.reqBeans;
        reqWater = c.reqWater;
    }
    return *this;
}

ostream& operator<<(ostream& os, const CoffeeBase& c) {
    os << "This coffee requires: " << c.reqBeans << "g of coffee and " << c.reqWater << "ml of water";
    return os;
}

istream& operator>>(istream& is, CoffeeBase& c) {
    is >> c.reqBeans >> c.reqWater;
    return is;
}