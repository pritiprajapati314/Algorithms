#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printMatrix(vector<vector<int>> &matrix){

    for(int i = 0; i<matrix.size(); i++){
        for(int j = 0; j<matrix[i].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}

void floydwarshell(vector<vector<int>> weight, vector<vector<int>> distance, vector< vector<int>> &assign){
    
    for(int i = 0; i<weight.size(); i++){
        for(int j = 0; j<weight.size(); j++){
            for(int k = 0; k<weight.size(); k++){
                if(distance[j][k] > distance[j][i] + distance[i][k])
                {
                    distance[j][k] = distance[j][i] + distance[i][k];
                } 
            }
        }
    }
    assign = distance;

    return;
}

void testCaseFloydwarshell(){

    vector< vector<int> > weight{
        {0, 9, -4, 1000},
        {6, 0, 1000, 2},
        {1000, 5, 0, 1000},
        {1000, 1000, 1, 0}
    };
    vector<vector<int>> distance;

    floydwarshell(weight,weight,distance);

    printMatrix(distance);

    return;
}

int main(){
    testCaseFloydwarshell();
    return 0;
}