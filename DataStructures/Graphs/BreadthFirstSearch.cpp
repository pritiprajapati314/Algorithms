// g++ -std=c++11 source.cpp

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void breadthFirstSearch(vector<vector<int> > adjList, int startIndex, vector<int> &visited, vector<int> &parent, vector<int> &level){
    queue<int> que;
    int temp;
    
    visited[startIndex] = 1;
    que.push(startIndex);

    while(!que.empty()){
        temp = que.front(); que.pop();
        for(int i = 0; i<adjList[temp].size(); i++){
            if(visited[adjList[temp][i]] == 0){
                visited[adjList[temp][i]] = 1;
                parent[adjList[temp][i]] = temp;
                level[adjList[temp][i]] = 1+level[temp];
                que.push(adjList[temp][i]);
            }
        }
    }
}

void testBreadthFirstSearch(){
    vector<vector<int> > testAdjList{
        {1,2,3},
        {0,2},
        {0,1},
        {0,4,7},
        {3,5,6},
        {4,6,7,8},
        {4,5},
        {3,5,8},
        {5,7,9},
        {8}
    };
    vector<int> visited(testAdjList.size(), 0);
    vector<int> parent(testAdjList.size(),-1);
    vector<int> level(testAdjList.size(), 0);

    breadthFirstSearch(testAdjList, 0, visited, parent, level);

    cout<<"visited : ";
    for(int i=0; i<visited.size(); i++){
        cout<< visited[i]<< " ";
    }
    cout<< endl;

    cout<<"parent : ";
    for(int i=0; i<parent.size(); i++){
        cout<< parent[i]<< " ";
    }
    cout<<endl;

    cout<<"level : ";
    for(int i=0; i<level.size(); i++){
        cout<<  level[i]<<" ";
    }
    cout<<endl;
}

int main(){
    testBreadthFirstSearch();
    return 0;
}
