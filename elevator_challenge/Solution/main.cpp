#include <iostream>
#include <vector>

using namespace std;

// Class representing an individual lift
class Lift {
private:
    int currentLevel;   // Current level of the lift
    int maxLevel;       // Maximum level of the building

public:
    // Constructor initializes the lift with the maximum level
    Lift(int maxLevel) : currentLevel(1), maxLevel(maxLevel) {}

    // Move the lift to the specified level
    void moveToLevel(int level) {
        // Check if the requested level is valid
        if (level < 1 || level > maxLevel) {
            cerr << "Invalid level.\n";
            return;
        }

        currentLevel = level;
        cout << "Lift moved to level " << currentLevel << ".\n";
    }

    // Simulate lift operation
    void operate() {
        cout << "Lift started.\n";
        // Simulate lift operation, e.g., by moving to requested levels.
        cout << "Lift reached all destinations.\n";
    }
};

// Class representing the building with multiple lifts
class Building {
private:
    vector<Lift> lifts;   // Vector of Lift objects representing all lifts in the building

public:
    // Constructor creates lifts based on the number and maximum level provided
    Building(int numLifts, int maxLevel) {
        lifts.resize(numLifts, Lift(maxLevel));
    }

    // Request a lift to a specific level for a given lift index
    void requestLift(int liftIndex, int level) {
        // Check if the lift index is valid
        if (liftIndex < 0 || liftIndex >= lifts.size()) {
            cerr << "Invalid lift index.\n";
            return;
        }

        // Move the requested lift to the specified level
        lifts[liftIndex].moveToLevel(level);
    }

    // Operate all lifts in the building
    void operateLifts() {
        for (auto& lift : lifts) {
            lift.operate();
        }
    }
};

// Main function where the program execution begins
int main() {
    int numLifts, maxLevel;
    // User input: number of lifts and maximum level
    cout << "Enter the number of lifts in the building: ";
    cin >> numLifts;
    cout << "Enter the maximum level of the building: ";
    cin >> maxLevel;

    // Create a Building object based on user input
    Building building(numLifts, maxLevel);

    int liftIndex, destination;
    // User input loop for lift requests
    while (true) {
        // Prompt user to enter lift index and destination level or -1 to operate lifts
        cout << "Enter lift index (0 to " << numLifts - 1 << ") and destination level (-1 to operate lifts): ";
        cin >> liftIndex;

        // Break the loop if user enters -1
        if (liftIndex == -1) {
            break;
        }

        cin >> destination;

        // Request a lift to the specified level
        building.requestLift(liftIndex, destination);
    }

    // Operate all lifts in the building
    building.operateLifts();

    return 0;
}
