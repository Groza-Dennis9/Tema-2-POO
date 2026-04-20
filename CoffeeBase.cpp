#include "CoffeeBase.h"

CoffeeBase::CoffeeBase(string cat, string n, double p, int b, int w) : Product(cat, n, p) {
    reqBeans = b;
    reqWater = w;
}