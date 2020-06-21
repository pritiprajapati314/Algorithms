#include<iostream> 
#include<vector>
using namespace std;

//it is called bottem up approch because here we first find the values for the least element
//in the array and than we move up.
int stairCase(int stairs, int stepSize[], int size){
    if(stairs == 0){
        return 1;
    }
    int nums[stairs+1];   // for storing the previously found values
    nums[0] = 1; 
    
    for(int i = 1; i <= stairs; i++){
        int total = 0;
        for(int j = 0; j < size; j++){
            if(i - stepSize[j] >= 0){
                total += nums[i-stepSize[j]];
            }
        }
        nums[i] = total;
    }
    return nums[stairs];
};

// n = no. of stairs
int simpleStairCase(int n){
    vector<int> stairArr(n+1, 0);

    stairArr[0] = 1;
    stairArr[1] = 1;
    stairArr[2] = 2;

    for(int i=3; i<n+1; i++){
        stairArr[i] = stairArr[i-1] + stairArr[i-2];
    }

    return stairArr[n];
}


void testSimpleStairCase(){

    cout<< simpleStairCase(5)<< endl;

}

int main(){

    testSimpleStairCase();

    int stepSize[] = {1, 3, 5};
    int  stairs = 27;

    cout<<stairCase(stairs, stepSize, sizeof(stepSize)/sizeof(stepSize[0])); 
}