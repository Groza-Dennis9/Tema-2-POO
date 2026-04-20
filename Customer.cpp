#include "Customer.h"
using namespace std;

string Customer::getName() const { return name; }
int Customer::getPoints() const { return points; }
double Customer::getDiscount() const {return (points > 150) ? 0.15 : (points > 50 ? 0.05 : 0.0); }

void Customer::addPoints(int p) { points += p; }

ostream& operator<<(ostream& os, const Customer& c) {
    os << "User: " << c.name << " | Loyalty: " << (c.points > 150 ? "GOLD" : (c.points > 50 ? "SILVER" : "BRONZE")) << " (" << c.points << " pts)";
    return os;
}