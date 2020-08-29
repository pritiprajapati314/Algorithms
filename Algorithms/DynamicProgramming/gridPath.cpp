#include <iostream>
#include <vector>

using namespace std;

//corrdinates
#define N 6
#define M 11

//holes
#define H1 2
#define H2 4

vector<vector <int> >memo(N, vector<int> (M, 0));

int path(int i, int j){
    
    if(i == H1 && j == H2){
        return 0;
    }
    if(memo[i][j]){
        return memo[i][j];
    }
    else if(i == 0 && j == 0){
        return 1;
    }
    else if(i != 0 && j == 0){
       memo[i][j] = path(i-1, 0);
       return memo[i][j];
    }
    else if(i == 0 && j != 0){
        memo[i][j] = path(0, j-1);
        return memo[i][j];
    }
    else if(i != 0 && j != 0){
        memo[i][j] = path(i-1, j) + path(i, j-1);
        return memo[i][j];
    }
    
}

int main(){
    cout<<path(N-1, M-1);
}