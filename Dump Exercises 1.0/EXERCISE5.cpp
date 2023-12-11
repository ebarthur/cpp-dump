#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


struct menuItemType {
    string name;
    double price;
};


vector<menuItemType> getData() {
    vector<menuItemType> menuList = {
        {"Plain Egg", 1.45},
        {"Bacon and Egg", 2.45},
        {"Muffin", 0.99},
        {"French Toast", 1.99},
        {"Fruit Basket", 2.49},
        {"Cereal", 0.69},
        {"Coffee", 0.50},
        {"Tea", 0.75}
    };
    return menuList;
}


void showMenu(const vector<menuItemType>& menuList) {
    cout << "Welcome to Johnny's Restaurant" << endl;
    for (size_t i = 0; i < menuList.size(); ++i) {
        cout << i + 1 << " " << menuList[i].name << " $" << fixed << setprecision(2) << menuList[i].price << endl;
    }
}


void printCheck(const vector<menuItemType>& menuList, const vector<int>& selectedItems) {
    double total = 0.0;
    for (int item : selectedItems) {
        double price = menuList[item - 1].price;
        total += price;
    }

    double tax = total * 0.05;
    double amountDue = total + tax;

    cout << "Tax $" << fixed << setprecision(2) << tax << endl;
    cout << "Amount Due $" << fixed << setprecision(2) << amountDue << endl;
}


int main() {
    vector<menuItemType> menuList = getData();
    showMenu(menuList);

    vector<int> selectedItems;
    while (true) {
        int choice;
        cout << "Enter the item number (0 to exit): ";
        cin >> choice;

        if (choice == 0) {
            break;
        } else if (choice < 1 || choice > menuList.size()) {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        int quantity;
        cout << "Enter the quantity: ";
        cin >> quantity;

        if (quantity < 1) {
            cout << "Invalid quantity. Please try again." << endl;
            continue;
        }

        for (int i = 0; i < quantity; ++i) {
            selectedItems.push_back(choice);
        }
    }

    printCheck(menuList, selectedItems);

    return 0;
}
