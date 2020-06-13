#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

int minimum(int a, int b){
    if(a < b){
        return a;
    }else{
        return b;
    }
    
}

void bellmanFord(vector<vector<int>> weight, vector<int> &distance, int source){   
    distance[source] = 0;

    for(int i=0; i<weight.size()-1; i++){
        for(int j = 0; j<weight.size() ; j++){
            for(int k = 0; k<weight.size(); k++){
                if(weight[j][k] != 0){
                    distance[k] = minimum(distance[k], distance[j] + weight[j][k]);
                }

            }
        }
    }
}

void testCaseBellmanFord(){

    vector<vector<int>> weight{
        {0, 10, 0, 0, 0, 0, 0, 8},
        {0, 0, 0, 0, 0, 2, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, -1, 0, 0},
        {0, 0, -2, 0, 0, 0, 0, 0},
        {0, -4, 0, 0, 0, -1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0} 
        };

    vector< vector<int> > adjList{
        {1},
        {5},
        {1, 3},
        {4},
        {5},
        {1},
        {1, 5},
        {6}
    };

    vector<int> distance(weight.size(), 999);

    bellmanFord(weight, distance, 0);

    for(int i = 0; i<distance.size(); i++){
        cout<<distance[i]<<" ";
    }
}

int main(){
    testCaseBellmanFord();
    return 0;
}