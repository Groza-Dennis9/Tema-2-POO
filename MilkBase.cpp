#include "MilkBase.h"

MilkBase::MilkBase() : Product(), reqMilk(0) {}
MilkBase::MilkBase(const MilkBase& c) : Product(c){
    reqMilk = c.reqMilk;
}
MilkBase::MilkBase(string cat, string n, double p, int m) : Product(cat, n, p){
    reqMilk = m;
}
MilkBase::~MilkBase(){}

MilkBase& MilkBase::operator=(const MilkBase& m) {
    if (this != &m) {
        reqMilk = m.reqMilk;
        Product::operator=(m);
    }
    return *this;
}

ostream& operator<<(ostream& os, const MilkBase& m) {
    return os;
}
istream& operator>>(istream& is, MilkBase& m) {
    is >> m.reqMilk;
    return is;
}
