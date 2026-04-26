#include "Snack.h"

Snack::Snack(const string& cat, const string& n, const double p, const int c) : Product(cat, n, p), cal(c) {}
Snack::Snack() : Product(), cal(0) {};
Snack::Snack(const Snack& s) : Product(s) {
    cal = s.cal;
}
Snack::~Snack()= default;

void Snack::prepare(Ingredients& s) {
    if (s.getSnacks() <= 0)
        throw runtime_error("Out of Snacks!");

    s.setSnacks(s.getSnacks()-1);
}
string Snack::serialize() const {
    return "SWEET,"+name+","+to_string(price)+","+to_string(cal);
}

Product* Snack::clone() const {
    return new Snack(*this);
}

Snack& Snack::operator=(const Snack& s) {
    if (this != &s) {
        Product ::operator=(s);
        cal = s.cal;
    }
    return *this;
}
istream& operator>>(istream& is, Snack& s) {
    is >> s.cal;
    return is;
}
ostream& operator<<(ostream& os, const Snack& s) {
    os << s.serialize();
    return os;
}