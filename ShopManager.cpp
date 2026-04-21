#include "ShopManager.h"
#include "Tea.h"
#include "Snack.h"
#include "Latte.h"
#include "Milkshake.h"
#include <iostream>
#include <fstream>


ShopManager::~ShopManager() {
    for (auto p : menu)
        delete p;
}

double ShopManager::getBank() const { return bankBalance; }
Ingredients& ShopManager::getStorage() { return storage; }

Customer& ShopManager::getCust(string n) {
    if (customers.find(n) == customers.end())
        customers[n] = Customer(n, 0);
    return customers[n];
}
vector<Product*> ShopManager::getByCat(string c) {
    vector<Product*> f;
    for (auto p : menu)
        if (p->getCategory() == c)
            f.push_back(p);
    return f;
}

void ShopManager::addMoney(double v) { bankBalance += v; }
void ShopManager::subMoney(double v) { bankBalance -= v; }

void ShopManager::loadData() {
    try {
        //Load Storage and Balance
        ifstream sFile("storage.txt");
        bankBalance = 300.0; // Default
        if (sFile.is_open()) {
            int b, m, w, f, t, s;
            if (!(sFile >> b >> m >> w >> f >> t >> s)) {
                throw runtime_error("Storage file is corrupted or formatted incorrectly.");
            }
            storage = Ingredients(b, m, w, f, t, s);

            double savedBalance;
            if (sFile >> savedBalance) bankBalance = savedBalance;
            sFile.close();
        }

        // Load Customers
        ifstream cFile("customers.txt");
        if (cFile.is_open()) {
            string line;
            while (getline(cFile, line)) {
                if(line.empty()) continue;
                size_t lastSpace = line.find_last_of(' ');
                if (lastSpace != string::npos) {
                    try {
                        string n = line.substr(0, lastSpace);
                        int p = std::stoi(line.substr(lastSpace + 1));
                        customers[n] = Customer(n, p);
                    } catch (...) {
                    }
                }
            }
            cFile.close();
        }

        //Load Menu
        ifstream mFile("menu.txt");
        if (!mFile.is_open()) {
            throw runtime_error("Critical Error: menu.txt not found!");
        }

        string line;
        while (getline(mFile, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string cat, n, p, e1, e2, e3;
            getline(ss, cat, ','); getline(ss, n, ','); getline(ss, p, ',');

            if (cat == "COFFEE") {
                getline(ss, e1, ','); getline(ss, e2, ','); getline(ss, e3, ',');
                menu.push_back(new Latte(cat, n, stod(p), stoi(e1), stoi(e2), stoi(e3)));
            } else if (cat == "NON-COFFEE") {
                getline(ss, e1, ','); getline(ss, e2, ',');
                if (n.find("Tea") != string::npos)
                    menu.push_back(new Tea(cat, n, stod(p), stoi(e1), stoi(e2)));
                else
                    menu.push_back(new Milkshake(cat, n, stod(p), stoi(e1), stoi(e2)));
            } else if (cat == "SWEET") {
                getline(ss, e1, ',');
                menu.push_back(new Snack(cat, n, stod(p), stoi(e1)));
            }
        }
        mFile.close();

    } catch (const std::exception& e) {
        cerr << "CRITICAL DATA LOAD ERROR: " << e.what() << std::endl;
    }
}

void ShopManager::saveData() const {
    //Save Storage
    ofstream sFile("storage.txt");
    if (sFile) {
        sFile << storage.getBeans() << " " << storage.getMilk() << " "
              << storage.getWater() << " " << storage.getFruit() << " "
              << storage.getTea() << " " << storage.getSnacks() << "\n"
              << bankBalance << "\n";
        sFile.close();
    }

    //Save Customers
    ofstream cFile("customers.txt");
    if (cFile) {
        for (auto const& [name, obj] : customers) {
            cFile << name << " " << obj.getPoints() << "\n";
        }
        cFile.close();
    }
}
