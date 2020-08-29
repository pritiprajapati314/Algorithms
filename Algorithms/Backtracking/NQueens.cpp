#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

#define NUM 4

vector<int> board(NUM, -1);
vector<int> row(NUM, 0);
vector<int> column(NUM, 0);
vector<int> leftDiagonal(2*NUM-1, 0);
vector<int> rightDiagonal(2*NUM-1, 0);
// r stands for current row index
// c stands for current column index

bool freeQueen(int r, int c){
   
    return (row[r] == 0 && column[c] == 0 && leftDiagonal[r+c] == 0 && rightDiagonal[NUM+r-c] == 0 );
}

void update(int r, int c){

    board[r] = c;
    row[r] = 1;
    column[c] = 1;
    leftDiagonal[r+c] = 1;
    rightDiagonal[NUM+r-c] = 1;
}

void undoQueen(int r, int c){

    board[r] = -1;
    row[r] = 0;
    column[c] = 0;
    leftDiagonal[r+c] = 0;
    rightDiagonal[NUM+r-c] = 0;
}

void displayBoard(){

    for(int i = 0; i<NUM; i++){
        for(int j = 0; j<NUM; j++){
            if(board[i] == j){
                cout<<" 1 ";
            }else{
                cout<<"[ ]";
            }
        }
        cout<<endl;
    }
}

bool placeQueen(int currentRow){

    for(int currentColumn = 0; currentColumn<NUM; currentColumn++){
        //cout<<currentColumn<<endl;
        
        if(freeQueen(currentRow, currentColumn)){

            update(currentRow, currentColumn);

            if(currentRow == NUM-1){
                //cout<<"terminate"<<endl;
                return true;
            }
            else{
                bool extendSol = placeQueen(currentRow+1);
                //cout<<extendSol<<" for "<<currentRow+1<<endl;
                if(extendSol){
                    return true;
                }
                else{
                    undoQueen(currentRow, currentColumn);
                }

            }
        }
    }
    return false;
} 

int main(){
   
    int const startingIndex = 0;

    cout<<placeQueen(startingIndex)<<endl;

    for(int i = 0; i<NUM; i++){
        cout<<i<<" "<<board[i]<<endl;
    }
    displayBoard();
}