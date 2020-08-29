#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void testCaseKruskal(){

    vector< vector<int>> weight{
        {0, 7, 8, 1000, 1000, 1000},
        {7, 0, 3, 6, 1000, 1000},
        {8, 3, 0, 4, 3, 1000},
        {1000, 6, 4, 0, 2, 5},
        {1000, 1000, 3, 2, 0, 2},
        {1000, 1000, 1000, 5, 2, 0}
    };
    vector<int> visited(weight.size())
}

int main(){
    testCaseKruskal();
    return 0;
}