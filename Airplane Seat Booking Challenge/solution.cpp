#include <iostream>
#include <iomanip>

using namespace std;

// Function declarations
void DisplayMenu();
void ShowSeatingArrangement();
bool IsSeatAvailable(int row, int seat);
bool BookSeat(int row, int seat);

// Constants
const int rows = 13;
const int seatsPerRow = 6;

// Initial seating arrangement
char seating[rows][seatsPerRow] = {
    {'*', '*', 'x', '*', 'x', 'x'},
    // ... (rest of the initial seating arrangement)
    {'*', '*', '*', '*', 'x', '*'}
};

int main()
{
    int choice;
    int row;
    char seat;
    int attempts = 2;

    // User selects ticket type
    do
    {
        DisplayMenu();
        cout << "Enter your choice(1-3): ";
        cin >> choice;
        if (choice < 1 || choice > 3)
        {
            cout << "Invalid choice. Please enter a number between 1 and 3" << endl;
            attempts--;
        }
    } while ((choice < 1 || choice > 3) && attempts > 0);

    // Check if too many wrong choices
    if (attempts == 0) {
        cout << "Too many wrong choices. Aborting program" << endl;
        return 1;
    }

    // Display initial seating arrangement
    ShowSeatingArrangement();

    // User books a seat
    do {
        cout << "Enter the desired row (1-13) and seat letter (A-F): ";
        cin >> row >> seat;

        // Validate row and seat input
        if (row < 1 || row > rows || seat < 65 || seat > 90) {
            cout << "Invalid row or seat. Please enter a valid combination" << endl;
            attempts--;
        }
        // Validate seat for the selected ticket type
        else if ((choice == 1 && row > 2) || (choice == 2 && (row < 3 || row > 7)) || (choice == 3 && row < 8)) {
            cout << "Invalid seat for your ticket type. Please select another seat" << endl;
            attempts--;
        }
        // Attempt to book the seat
        else {
            if (BookSeat(row, seat))
                break;
            attempts--;
        }

    } while (attempts > 0);

    // Check if too many wrong choices
    if (attempts == 0) {
        cout << "Too many wrong choices. Aborting program." << endl;
        return 1;
    }

    return 0;
}

// Function to book a seat
bool BookSeat(int row, int seat) {
    if (IsSeatAvailable(row, seat)) {
        seating[row - 1][seat - 'A'] = 'X';
        cout << "Seat booked successfully!" << endl;
        return true;
    } else {
        cout << "Seat already booked. Please select another seat.\n";
        return false;
    }
}

// Function to check if a seat is available
bool IsSeatAvailable(int row, int seat) {
    return seating[row - 1][seat - 'A'] == '*';
}

// Function to display the ticket type menu
void DisplayMenu() {
    cout << "Select Ticket Type:\n"
        << "1. First Class\n"
        << "2. Business Class\n"
        << "3. Economy Class\n";
}

// Function to display the current seating arrangement
void ShowSeatingArrangement()
{
    cout << setw(7) << " ";
    for (int i = 0; i < seatsPerRow; ++i) {
        cout << setw(2) << char('A' + i) << " ";
    }
    cout << endl;

    for (int i = 0; i < rows; ++i) {
        cout << "Row " << setw(2) << i + 1 << " ";
        for (int j = 0; j < seatsPerRow; ++j) {
            cout << setw(2) << seating[i][j] << " ";
        }
        cout << endl;
    }
}
