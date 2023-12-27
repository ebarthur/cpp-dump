#include <iostream>

using namespace std;

int main()
{
    // Define a 2D array to represent a chessboard
    string chessboard[8][8];

    // Determine the number of rows and columns in the chessboard
    int row = sizeof(chessboard) / sizeof(chessboard[0]);
    int col = sizeof(chessboard[0]) / sizeof(string);

    // Initialize the chessboard with an alternating pattern of "O" and "X"
    string board[8][8] = {{"O", "X", "O", "X", "O", "X", "O", "X"},
                          {"X", "O", "X", "O", "X", "O", "X", "O"},
                          {"O", "X", "O", "X", "O", "X", "O", "X"},
                          {"X", "O", "X", "O", "X", "O", "X", "O"},
                          {"O", "X", "O", "X", "O", "X", "O", "X"},
                          {"X", "O", "X", "O", "X", "O", "X", "O"},
                          {"O", "X", "O", "X", "O", "X", "O", "X"},
                          {"X", "O", "X", "O", "X", "O", "X", "O"} };

    // Copy the pattern to the chessboard
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            chessboard[i][j] = board[i][j];
        }
    }

    // Display the chessboard
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == col - 1) {
                // Print a new line at the end of each row
                cout << chessboard[i][j] << endl;
            } else {
                // Print the chessboard cell
                cout << chessboard[i][j];
            }
        }
    }

    return 0;
}
