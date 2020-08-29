#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int max(int a, int b){
    if(a >= b ){ return a; }
    else{ return b; }
}

void degreeSort(vector< vector<int> > &adjList,vector<int> &inDegree, vector<int> &freeEnd){
    for(int i = 0; i<inDegree.size(); i++){
        for(int j = 0; j<adjList[i].size(); j++){
            inDegree[adjList[i][j]] += 1;
        }
    }

    for(int i = 0; i<inDegree.size(); i++){
        if(inDegree[i] == 0){
            freeEnd.push_back(i);
        }
    }
}

void topologicalOrder(vector< vector<int> > &adjList, vector<int> inDegree, vector<int> &topOrder, vector<int> freeEnd, vector<int> &longestPathList ){
    queue<int> que;
    int count = 0;
    for(int j = 0; j<freeEnd.size(); j++){
        int i = freeEnd[j];
        if(inDegree[i] == 0 ){
            que.push(i);
            longestPathList[i] = 0;
        }
        while(!que.empty()){
            int temp = que.front(); que.pop();
            topOrder[count] = temp;
            count++;
        
            
            for(int j = 0; j < adjList[temp].size(); j++){
                inDegree[adjList[temp][j]] -= 1;
                longestPathList[adjList[temp][j]] = max(longestPathList[adjList[temp][j]],1+longestPathList[temp]);
                if(inDegree[adjList[temp][j]] == 0){
                    que.push(adjList[temp][j]);
                }
            }
        }
    }
}

void testTopologicalOrder(){
    vector< vector<int> > adjList{
        {2,3,4},
        {2,7},
        {5},
        {5,7},
        {7},
        {6},
        {7},
        {}
    };
    vector<int> inDegree(adjList.size(),0);
    vector<int> topOrder(adjList.size(),0);
    vector<int> freeEnd;
    vector<int> longestPathList(adjList.size());
    
    degreeSort(adjList, inDegree, freeEnd);
    topologicalOrder(adjList,inDegree,topOrder,freeEnd,longestPathList);

    cout<<"indegree list : ";
    for(int i=0; i<inDegree.size(); i++){
        cout<<inDegree[i]<<" ";
    }
    cout<<endl;

    cout<<"topological order : ";
    for(int i=0; i<topOrder.size(); i++){
        cout<<topOrder[i]<<" ";
    }
    cout<<endl;

    cout<<"longest path of the list : ";
    for(int i=0; i<longestPathList.size(); i++){
        cout<<longestPathList[i]<<" ";
    }
    cout<<endl;
}

int main(){
    testTopologicalOrder();
    return 0;
}