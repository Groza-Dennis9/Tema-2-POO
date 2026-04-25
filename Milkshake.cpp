#include "Milkshake.h"

Milkshake::Milkshake(string c, string n, double p, int m, int f) : Product(c,n,p), MilkBase(c,n,p,m), reqFruit(f) {}
Milkshake::Milkshake() : Product(), MilkBase(), reqFruit(0){}
Milkshake::Milkshake(const Milkshake &m) : Product(m), MilkBase(m){
    reqFruit = m.reqFruit;
}
Milkshake::~Milkshake(){};

void Milkshake::prepare(Ingredients& s) {
    if (s.getMilk() < reqMilk || s.getFruit() < reqFruit)
        throw std::runtime_error("Insufficient Stock!");

    s.setMilk(s.getMilk()-reqMilk);
    s.setFruit(s.getFruit()-reqFruit);
}

string Milkshake::serialize() const {
    return "NON-COFFEE,"+name+","+to_string(price)+","+to_string(reqMilk)+","+to_string(reqFruit);
}


Product* Milkshake::clone() const {
    return new Milkshake(*this);
}

Milkshake& Milkshake::operator=(const Milkshake &m) {
    if (this != &m) {
        Product::operator=(m);
        MilkBase::operator=(m);
        reqMilk = m.reqMilk;
    }
    return *this;
}



ostream& operator<<(ostream& os, const Milkshake& m) {
    os << m.serialize();
    return os;
}
istream& operator>>(istream& is, Milkshake& m) {
    return is;
}