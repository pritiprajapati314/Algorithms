#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int minimum(vector< vector<int> > weight, int temp){
    int i = weight[temp][0], k; 
    for(int j = 1; j< weight[temp].size(); j++){
        if(i > weight[temp][j]){
            i = weight[temp][j];
            k = j;
        }
    }
    return k;
}

void dijkstra(vector< vector<int> > weight, int source, vector<int> &visited, vector<int> &distance){
    
    queue<int> que;
    int temp;
    que.push(source);
    distance[source] = 0;
    
    while(!que.empty()){
        temp = que.front(); que.pop();
        visited[temp] = 1;
        
        for(int i = 0; i<weight[temp].size(); i++){
            if(visited[i] == 0 && weight[temp][i] != 1000){
                que.push(i);
            }
            if(distance[i] > distance[temp] + weight[temp][i]){
                distance[i] = distance[temp] + weight[temp][i];
            }
        }
    }
}

void testCaseDijkstra(){

    vector< vector<int> > weight{
        {1000, 10, 80, 1000, 1000, 1000, 1000},
        {10, 1000, 6, 1000, 20, 1000, 1000},
        {80, 6, 1000, 70, 1000, 1000, 1000},
        {1000, 1000, 70, 1000, 1000, 1000, 1000},
        {1000, 20, 1000, 1000, 1000, 50, 10},
        {1000, 1000, 1000, 1000, 50, 1000, 5},
        {1000, 1000, 1000, 1000, 10, 5, 1000}
    };
    vector<int> visited(weight.size(),0);
    vector<int> distance(weight.size(),1000);

    dijkstra(weight, 0, visited, distance);

    for(int i=0; i<distance.size(); i++){
        cout<<distance[i]<<" ";
    }
}

int main(){
    testCaseDijkstra();
    return 0;
}