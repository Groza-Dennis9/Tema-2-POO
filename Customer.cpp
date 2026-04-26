#include "Customer.h"

using namespace std;

Customer::Customer() : name(" "), points(0) {}
Customer::Customer(string n, const int p) : name(n), points(p) {}

Customer::Customer(const Customer &c) {
    name = c.name;
    points = c.points;
}

Customer::~Customer() = default;

string Customer::getName() const { return name; }
int Customer::getPoints() const { return points; }
double Customer::getDiscount() const {return (points > 150) ? 0.15 : (points > 50 ? 0.05 : 0.0); }

void Customer::addPoints(int p) { points += p; }

Customer& Customer::operator=(const Customer& c) {
    if (this != &c) {
        name = c.name;
        points = c.points;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Customer& c) {
    os << "User: " << c.name << " | Loyalty: " << (c.points > 150 ? "GOLD" : (c.points > 50 ? "SILVER" : "BRONZE")) << " (" << c.points << " pts)";
    return os;
}

istream& operator>>(istream& is, Customer& c) {
    is >> c.name >> c.points;
    return is;
}