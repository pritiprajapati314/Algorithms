#include<iostream>
#include<vector>
using namespace std;

void max_min(int arr[], int* max, int* min, int length){
 
for(int i = 0; i<length; i++){
if(arr[i] > *max)
    *max = arr[i];
if(arr[i] < *min)
    *min = arr[i];    
}
}

void countingSort(int arr[],int brr[], int length , int max, int min){
    int i = 1;
   while(i <= length)
   {
       int  a = arr[i];
       //cout<<brr<<endl;
       brr[a]++;
       i++;
   }
}


int main(){

    int arr[] = {0, 1, 2, 3, 4, 3, 2, 0, 5}, max = 0, min = 0;

    max_min(arr, &max, &min, sizeof(arr)/sizeof(arr[0]));
    int brr[max + 1] = {0};
    countingSort(arr, brr,sizeof(arr)/sizeof(arr[0]), max, min);

    for(int i = 0; i<= max; i++)
    {
        cout<<i<<" is repeated "<<brr[i]<<" times."<<endl;
    }
}