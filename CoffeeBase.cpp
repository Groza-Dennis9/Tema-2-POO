#include "CoffeeBase.h"

CoffeeBase::CoffeeBase(string cat, string n, double p, int b, int w) : Product(cat, n, p) {
    reqBeans = b;
    reqWater = w;
}

CoffeeBase::CoffeeBase() : reqBeans(0), reqWater(0), Product() {}

CoffeeBase::CoffeeBase(const CoffeeBase &c) : Product(c) {
    reqBeans = c.reqBeans;
    reqWater = c.reqWater;
}
CoffeeBase::~CoffeeBase() {};

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