#include<iostream>

using namespace std;

shellSort(int arr[], int size){
    int gap = size/2;
    for(int i=0; i<gap;i++){
        if(arr[i] > arr[i+gap]){
            int temp = arr[i];
            arr[i] = arr[i+gap];
            arr[i+gap] = temp;
        }
    }
    for(int i = 1; i<size; i++){
        int j = i-1;
        int temp = arr[i];
        while(j>=0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main(){
    int arr[] = {3, 4, 1, 8, 9, 7, 6, 5, 10, 2};
    shellSort(arr, sizeof(arr)/sizeof(arr[0]));
    for(int i = 0 ; i<sizeof(arr)/sizeof(arr[0]); i++){
        cout<<arr[i]<<endl;
    }
}