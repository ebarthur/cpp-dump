#include <iostream>

using namespace std;

int main()
{
    // Set the initial value of 'month' to 12
    int month = 12;

    // Prompt the user to enter a month number
    cout << "Enter month number: " << endl;

    // Read the user's input into the 'month' variable
    cin >> month;

    // Use a switch statement to determine and output the corresponding month name
    switch (month) {
        case 1:
            cout << "January";
            break;
        case 2:
            cout << "February";
            break;
        case 3:
            cout << "March";
            break;
        case 4:
            cout << "April";
            break;
        case 5:
            cout << "May";
            break;
        case 6:
            cout << "June";
            break;
        case 7:
            cout << "July";
            break;
        case 8:
            cout << "August";
            break;
        case 9:
            cout << "September";
            break;
        case 10:
            cout << "October";
            break;
        case 11:
            cout << "November";
            break;
        case 12:
            cout << "December";
            break;
        default:
            // If the entered month number is not in the range 1-12, output "Invalid"
            cout << "Invalid month number";
    }
}
