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
    int arr[] = {3, 46, 1, 8, 97, 7, 6, 5, 104, 2, 100};
    cout<<"unsorted array :"<<endl;
    for(int i = 0 ; i<sizeof(arr)/sizeof(arr[0]); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    shellSort(arr, sizeof(arr)/sizeof(arr[0]));
    cout<<"sorted array by shell sort operation : "<<endl;
    for(int i = 0 ; i<sizeof(arr)/sizeof(arr[0]); i++){
        cout<<arr[i]<<" ";
    }
}