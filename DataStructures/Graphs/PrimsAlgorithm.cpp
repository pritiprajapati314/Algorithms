//-std=c++11 PrimsAlgorithm.cpp

#include <iostream>
#include <vector>
#include <queue> 

using namespace std;

void primAlgorithm(vector<vector<int>> weight, vector<int> visited, vector<int> &result, vector<int> &parent){
    queue<int> que;
    que.push(0); 

    while(!que.empty()){

        int temp = que.front(); que.pop();
     
        visited[temp] = 1;
        int kemp = 1000; 

       
        for(int j = 0; j<weight[temp].size(); j++){
           
            if(weight[temp][j] != 0 && weight[temp][j] != 1000){
                if(visited[j] == 0){
                que.push(j);}
               
                if(weight[temp][j] < kemp ){
                    kemp = weight[temp][j];
                    parent[temp] = j;
    
                }
                
            }
        }
        result[temp] = kemp;
    }
}

void testCasePrim(){

    vector< vector<int>> weight{
        {0, 7, 8, 1000, 1000, 1000},
        {7, 0, 3, 6, 1000, 1000},
        {8, 3, 0, 4, 3, 1000},
        {1000, 6, 4, 0, 2, 5},
        {1000, 1000, 3, 2, 0, 2},
        {1000, 1000, 1000, 5, 2, 0}
    };

    /*vector< vector<int> > weight{
        {0, 2, 1000, 6, 1000 },  
        { 2, 0, 3, 8, 5 },  
        { 1000, 3, 0, 1000, 7 },  
        { 6, 8, 1000, 0, 9 },  
        { 1000, 5, 7, 9, 0 } };*/

    /*vector< vector<int> > weight{
        {0, 9, -4, 1000},
        {6, 0, 1000, 2},
        {1000, 5, 0, 1000},
        {1000, 1000, 1, 0}
    };*/
    vector<int>result(weight.size()); 
    vector<int> visited(weight.size(), 0);
    vector<int> parent(weight.size(), 0);

    primAlgorithm(weight, visited, result, parent);

    for(int i = 0; i<result.size(); i++){
        cout<<"The distance between : "<<parent[i]<<" and : "<<i<<" is "<<result[i]<<endl;
    }

}

int main(){
    testCasePrim();
    return 0;
}