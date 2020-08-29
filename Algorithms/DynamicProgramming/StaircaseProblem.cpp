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
/*int simpleStairCase(int n){
    vector<int> stairArr(n+1, 0);

    stairArr[0] = 1;
    stairArr[1] = 1;
    stairArr[2] = 2;

    for(int i=3; i<n+1; i++){
        stairArr[i] = stairArr[i-1] + stairArr[i-2];
    }

    return stairArr[n];
}*/

/*
int complexStairCase(int n, int size, int s[], int p){

    if(n == 0){
        return 0;
    }
    int with[n+1];
    int without[n+1];
    with[0] = 0; 

    without[0] = 1;

    for(int i = 0; i <= n; i++){
        int t1 = 0; int t2 = 0; 
        for(int j = 0; j < size; j++){
            if(i - s[j] >= 0){
            t1 += with[i - s[j]];
            t2 += without[i - s[j]];}
        }
        t1 += without[i - p];
        with[i] = t1;
        without[i] = t2;
    }
    return with[n];
}
*/


/*void testSimpleStairCase(){

    cout<< simpleStairCase(5)<< endl;

}*/

// n = no. of stairs
int complexStaircase(int n){
    vector<int> withThree(n+1, 0);
    vector<int> withoutThree(n+1, 0);

    // base cases;
    withThree[0] = 0;
    withThree[1] = 0;
    withThree[2] = 0;
    withThree[3] = 1;

    withoutThree[0] = 1;
    withoutThree[1] = 1;
    withoutThree[2] = 2;
    withoutThree[3] = 3;

    for(int i=4; i<n+1; i++){
        withThree[i] = withThree[i-1] + withThree[i-2] + withoutThree[i-3];
        withoutThree[i] = withoutThree[i-1] + withoutThree[i-2];
    }

    return withThree[n];
}
int main(){

    //testSimpleStairCase();

    int stepSize[] = {1, 2};
    int  stairs = 27;

    //cout<<stairCase(stairs, stepSize, sizeof(stepSize)/sizeof(stepSize[0])); 

    // cout<<complexStairCase(4, 2, stepSize, 3);
    cout<< complexStaircase(4)<< endl;

    return 0;
}