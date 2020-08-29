#include<iostream>
#include<vector>

using namespace std;

void flag(int currentIndex[]){
    int row = currentIndex[0];
    int column = currentIndex[1];
    
}

int ratInMaze(vector<vector<int>> maze, vector<vector<int>> &visited, int currentIndex[], int end[]){
    
    while(flag(currentIndex)){

        int nextStep[2];
        choosePath(currentIndex, nextStep);
        
    }    
}

void testCase(){
    vector<vector<int>> maze = {
        {1, 0, 0, 0, 1, 0},
        {1, 1, 0, 0, 1, 1},
        {0, 1, 0, 0, 1, 1},
        {0, 1, 1, 1, 1, 0},
        {0, 0, 0, 1, 1, 0},
        {1, 1, 0, 1, 0, 0}
    };
    vector<vector<int>> visited(maze.size(), vector<int> (maze.size(), 0));
    int start[] = {0, 0};
    int end[] = {5, 5};

    cout<<ratInMaze(maze, visited, start, end);
}

int main(){
    testCase();
}
