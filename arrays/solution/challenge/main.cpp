#include <iostream>

using namespace std;

int main()
{
    string chessboard[8][8];
    int row = sizeof(chessboard)/ sizeof(chessboard[0]);
    int col = sizeof(chessboard[0])/sizeof(string);
//solution start
string board[8][8] =  {{"O", "X", "O", "X", "O", "X", "O", "X"},
                         {"X", "O", "X", "O", "X", "O", "X", "O"},
                         {"O", "X", "O", "X", "O", "X", "O", "X"},
                         {"X", "O", "X", "O", "X", "O", "X", "O"},
                         {"O", "X", "O", "X", "O", "X", "O", "X"},
                         {"X", "O", "X", "O", "X", "O", "X", "O"},
                         {"O", "X", "O", "X", "O", "X", "O", "X"},
                         {"X", "O", "X", "O", "X", "O", "X", "O"} };

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col ; j++){
            chessboard[i][j]= board[i][j];

        }
    }
//solution end
    for (int i = 0;i < row; i++ ){
            for (int j = 0;j < col; j++ ){
                    if(j == col - 1){
                        cout<<chessboard[i][j]<<endl;
                    }
                    else{
                        cout<<chessboard[i][j];
                    }
            }
    }
    return 0;
}
