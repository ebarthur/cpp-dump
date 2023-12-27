#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct MenuItem {
    string itemName;
    double price;
};

int main() {
    const int numItems = 3;
    MenuItem menu[numItems] = {
        {"Plain Egg", 1.45},
        {"Bacon and Egg", 2.45},
        {"Muffin", 0.99},
        {"French Toast", 1.99},
        {"Fruit Basket", 2.49},
        {"Cereal", 0.69},
        {"Coffee", 0.50},
        {"Tea", 0.75}
    };

    double totalBill = 0.0;
    vector<int> orderItems;

    cout << "Welcome to the breakfast billing system!" << endl;
    cout << "Here are the breakfast items and their prices:" << endl;

    for (int i = 0; i < numItems; ++i) {
        cout << i + 1 << ". " << setw(15) << left << menu[i].itemName << " $ " << fixed << setprecision(2) << menu[i].price << endl;
    }

    cout << "Enter the numbers of the items you'd like to order (separated by spaces), and enter 0 to finish ordering: ";

    int itemNumber;
    while (cin >> itemNumber && itemNumber != 0) {
        if (itemNumber >= 1 && itemNumber <= numItems) {
            totalBill += menu[itemNumber - 1].price;
            orderItems.push_back(itemNumber);
        } else {
            cout << "Invalid item number. Please enter a valid item number or enter 0 to finish ordering." << endl;
        }
    }

    cout << fixed << setprecision(2);
    cout << "Your order includes:" << endl;
    for (int item : orderItems) {
        cout << menu[item - 1].itemName << " $ " << menu[item - 1].price << endl;
    }

    cout << "Your total bill is: $" << totalBill << endl;

    return 0;
}
