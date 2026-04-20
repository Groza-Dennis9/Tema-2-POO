#include "MilkBase.h"

MilkBase::MilkBase(std::string cat, std::string n, double p, int m) : Product(cat, n, p){
    reqMilk = m;
}