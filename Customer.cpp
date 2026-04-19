#include "Customer.h"
using namespace std;

ostream& operator<<(ostream& os, const Customer& c) {
    os << "User: " << c.name << " | Loyalty: " << (c.points > 150 ? "GOLD" : (c.points > 50 ? "SILVER" : "BRONZE")) << " (" << c.points << " pts)";
    return os;
}