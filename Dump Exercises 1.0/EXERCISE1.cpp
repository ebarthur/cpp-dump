#include <iostream>
#include <string>

using namespace std;

struct FruitType {
    string name;
    string color;
    int fat;
    int sugar;
    int carbohydrate;
};

int main() {
    FruitType myFruit;

    cout << "Enter the name of the fruit: ";
    cin >> myFruit.name;

    cout << "Enter the color of the fruit: ";
    cin >> myFruit.color;

    cout << "Enter the fat content of the fruit: ";
    cin >> myFruit.fat;

    cout << "Enter the sugar content of the fruit: ";
    cin >> myFruit.sugar;

    cout << "Enter the carbohydrate content of the fruit: ";
    cin >> myFruit.carbohydrate;

    cout << "\nFruit Data:\n";
    cout << "Name: " << myFruit.name << "\n";
    cout << "Color: " << myFruit.color << "\n";
    cout << "Fat: " << myFruit.fat << "\n";
    cout << "Sugar: " << myFruit.sugar << "\n";
    cout << "Carbohydrate: " << myFruit.carbohydrate << "\n";

    return 0;
}
