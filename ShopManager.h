
#ifndef TEMA_2_POO_SHOPMANAGER_H
#define TEMA_2_POO_SHOPMANAGER_H

#include "Ingredients.h"
#include "Product.h"
#include "Customer.h"
#include <map>
#include <vector>
#include <string>
using namespace std;

class ShopManager {
private:
    vector<Product*> menu;
    map<string, Customer> customers;
    Ingredients storage;
    double bankBalance;
public:
    //Constructor and Destructor
    ShopManager();
    ShopManager(double bank);
    ShopManager(const ShopManager& other);
    ~ShopManager();

    //Getters
    double getBank() const;
    Ingredients& getStorage();
    Customer& getCust(string n);
    vector<Product*> getByCat(string c);

    //Functions
    void addMoney(double v);
    void subMoney(double v);

    void loadData();
    void saveData() const;

    //Operators overload
    ShopManager& operator=(const ShopManager& other);
    friend ostream& operator<<(ostream& os, const ShopManager&);
    friend istream& operator>>(istream& is, ShopManager& m);

};


#endif //TEMA_2_POO_SHOPMANAGER_H