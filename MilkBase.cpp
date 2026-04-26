#include "MilkBase.h"

MilkBase::MilkBase() : Product(), reqMilk(0) {}
MilkBase::MilkBase(const MilkBase& c) : Product(c){
    reqMilk = c.reqMilk;
}
MilkBase::MilkBase(const string &cat, const string &n, const double p, const int m) : Product(cat, n, p){
    reqMilk = m;
}
MilkBase::~MilkBase() = default;

MilkBase& MilkBase::operator=(const MilkBase& m) {
    if (this != &m) {
        reqMilk = m.reqMilk;
        Product::operator=(m);
    }
    return *this;
}

ostream& operator<<(ostream& os, const MilkBase& m) {
    os << m.reqMilk;
    return os;
}
istream& operator>>(istream& is, MilkBase& m) {
    is >> m.reqMilk;
    return is;
}
