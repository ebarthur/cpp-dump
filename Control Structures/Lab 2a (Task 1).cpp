#include <iostream>

using namespace std;

int main()
{
    // Declare a variable to store the user-inputted month
    int month;

    // Prompt the user to enter a month number
    cout << "Enter month number: " << endl;

    // Read the user's input into the 'month' variable
    cin >> month;

    // Output the corresponding month name based on the user's input
    cout << "The month is ";

    // Check each possible month number and print the corresponding month name
    if (month == 1)
    {
        cout << "January" << endl;
    }
    else if (month == 2)
    {
        cout << "February" << endl;
    }
    else if (month == 3)
    {
        cout << "March" << endl;
    }
    else if (month == 4)
    {
        cout << "April" << endl;
    }
    else if (month == 5)
    {
        cout << "May" << endl;
    }
    else if (month == 6)
    {
        cout << "June" << endl;
    }
    else if (month == 7)
    {
        cout << "July" << endl;
    }
    else if (month == 8)
    {
        cout << "August" << endl;
    }
    else if (month == 9)
    {
        cout << "September" << endl;
    }
    else if (month == 10)
    {
        cout << "October" << endl;
    }
    else if (month == 11)
    {
        cout << "November" << endl;
    }
    else if (month == 12)
    {
        cout << "December" << endl;
    }
    else {
        // If the entered month number is not in the range 1-12, output "Invalid"
        cout << "Invalid";
    }
}
