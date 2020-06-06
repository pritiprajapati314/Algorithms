#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void depthFirstSearch(vector< vector<int> >adjList, vector<int> &visited, int currentIndex, int &count, vector<int> &parent, vector<int> &preNumber, vector<int> &postNumber){
    
    stack<int> sta;
    int temp;

    visited[currentIndex] = 1;
    preNumber[currentIndex] = count;
    count++;
    sta.push(currentIndex);

    while(!sta.empty()){
        temp = sta.top(); sta.pop();
        for(int i = 0; i< adjList[temp].size(); i++){
            if(visited[adjList[temp][i]] == 0){
                parent[adjList[temp][i]] = temp;
                depthFirstSearch(adjList,visited,adjList[temp][i],count,parent,preNumber,postNumber);
                postNumber[adjList[temp][i]] = count; 
                count++;
            }
        }
    }
}

void testCasedepthFirstSearch(){

    vector< vector<int> > adjList{
        {1,2,3},
        {0,2},
        {0,1},
        {0,4,7},
        {3,5,6},
        {4,6,7,8},
        {4,5},
        {3,5,8},
        {5,7,9},
        {8},
        {13}
    };

    vector<int> visited(adjList.size(), 0);
    vector<int> parent(adjList.size(), -1);
    vector<int> preNumber(adjList.size(),-1);
    vector<int> postNumber(adjList.size(), -1);
    int count = 0;
    
    depthFirstSearch(adjList, visited ,3, count, parent, preNumber, postNumber);

    cout<<"visited : ";
    for(int i = 0; i<visited.size(); i++){
        cout<<visited[i]<<" ";
    }
    cout<<endl;

    cout<<"parent : ";
    for(int i = 0; i<parent.size(); i++){
        cout<<parent[i]<<" ";
    }
    cout<<endl;

    for(int i = 0; i<preNumber.size(); i++){
        cout<<"the preNumber of " <<i<<" is : "<<preNumber[i]<<endl;
        cout<<"the postNumber of " <<i<<" is : "<<postNumber[i]<<endl;
        cout<<endl;
    }
    
}

int main(){
    testCasedepthFirstSearch();
    return 0;
}