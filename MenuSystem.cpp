#include "MenuSystem.h"
#include <stdexcept>
#include <string>
#include <iomanip>

int MenuSystem::getChoiceInRange(const int min, const int max) {
    string input;
    getline(cin >> ws, input);
    if (input.empty() || input.find(' ') != string::npos)
        throw invalid_argument("Input must be a single number.");
    for (char const &c : input)
        if (!isdigit(c))
            throw invalid_argument("Numeric digits only.");
    const int val = stoi(input);
    if (val < min || val > max)
        throw out_of_range("Option out of bounds.");
    return val;
}

void MenuSystem::header() const {
    cout<<"\n________________________________________________\n";
    cout << "\n--- SHOP BALANCE: $" << fixed << setprecision(2) << shop.getBank() << " ---\n";
}

void MenuSystem::admin() const {
        string input;
        cout << "[SECURITY] Enter Admin Password: ";
        cin >> input;

        if (input != ADMIN_PASSWORD) {
            cout << "ACCESS DENIED: Incorrect password.\n";
            pause();
            return;
        }
        while(true) {
            try {
                header();
                cout << shop.getStorage() << "\n";
                cout << "1.Beans --- $20 for 500g\n2.Milk --- $10 for 500ml\n3.Water --- $5 for 1000ml\n4.Fruit --- $15 for 5pcs\n5.Tea --- $10 for 10bags\n6.Snacks --- $48 for 12pcs\n7.Back\nChoice: ";
                int c = getChoiceInRange(1, 7);
                if(c == 7) {
                    break;
                }

                string msg = " ";
                try {
                    if(c==1 && shop.getBank()>=20) { shop.getStorage().setBeans(shop.getStorage().getBeans()+500); shop.subMoney(20); msg = "Bought 500g of Beans!"; }
                    else if(c==2 && shop.getBank()>=10) { shop.getStorage().setMilk(shop.getStorage().getMilk()+500); shop.subMoney(10); msg = "Bought 500ml of Milk!"; }
                    else if(c==3 && shop.getBank()>=5) { shop.getStorage().setWater(shop.getStorage().getWater()+1000); shop.subMoney(5); msg = "Bought 1000ml of Water!"; }
                    else if(c==4 && shop.getBank()>=15) { shop.getStorage().setFruit(shop.getStorage().getFruit()+5); shop.subMoney(15); msg = "Bought 5pcs of Fruit!"; }
                    else if(c==5 && shop.getBank()>=10) { shop.getStorage().setTea(shop.getStorage().getTea()+10); shop.subMoney(10); msg = "Bought 10 bags of Tea!"; }
                    else if(c==6 && shop.getBank()>=20) { shop.getStorage().setSnacks(shop.getStorage().getSnacks()+12); shop.subMoney(48); msg = "Bought 12pcs of Snacks!"; }
                    else { cout << "Restock failed: Check bank balance.\n"; continue; }
                }catch (const invalid_argument& e) {
                    cout << "Inventory Error: " << e.what() << "\n";
                    pause();
                }

                shop.saveData();
                cout << ">> " << msg << "\n";
            } catch(const exception& e) {
                cout << "Admin Error: " << e.what() << "\n";
            }
        }
    }

void MenuSystem::customer() const {
        cout << "Enter Customer Name: ";
        string fullName;
        getline(cin >> ws, fullName);
        Customer& c = shop.getCust(fullName);

        while(true) {
            try {
                header();
                cout << c << "\n1.Coffee 2.Non-Coffee 3.Sweets 4.Logout\nChoice: ";
                const int catChoice = getChoiceInRange(1, 4);
                if(catChoice == 4) break;

                const string sCat = (catChoice==1)?"COFFEE":(catChoice==2)?"NON-COFFEE":"SWEET";
                auto items = shop.getByCat(sCat);
                if(items.empty()) {
                    cout <<"No items available in this category.\n";
                    continue;
                }

                for(int i=0; i<items.size(); ++i)
                    cout << i << ". " << *items[i] << "\n";
                cout << items.size() << ". Back\nSelection: ";

                const int sel = getChoiceInRange(0, static_cast<int>(items.size()));
                if(sel == static_cast<int>(items.size()))
                    continue;

                items[sel]->prepare(shop.getStorage());
                const double discValue = c.getDiscount();
                const double finalPrice = items[sel]->getPrice() * (1.0 - discValue);

                shop.addMoney(finalPrice);
                c.addPoints(static_cast<int>(finalPrice));
                shop.saveData();

                cout << "\n>> Ordered a " << items[sel]->getName()
                          << " with a discount of " << static_cast<int>(discValue * 100) << "%!\n";
                cout << "Total Paid: $" << fixed << setprecision(2) << finalPrice << "\n";

            } catch(const exception& e) {
                cout << "Order Error: " << e.what() << "\n";
            }
        }
    }

void MenuSystem::pause() {
        cout << "\nPress Enter to continue...";
        cin.ignore(1000, '\n');
        cin.get();
    }

void MenuSystem::run() const {
        try {
            shop.loadData();

        } catch(const exception& e) {
            cout << "\n[!] SYSTEM ALERT: " << e.what() << "\n";
            cout << "[!] Shop has been reset to safe defaults.\n";
            pause();
        }
        while(true) {
            try {
                header();
                cout << "1.Customer Order 2.Admin Mode 3.Exit\nChoice: ";
                int c = getChoiceInRange(1, 3);
                if (c == 1) customer();
                else if (c == 2) admin();
                else if (c == 3) break;
            } catch(const exception& e) {
                cout << "System Error: " << e.what() << "\n";
                pause();
            }
        }
    }
