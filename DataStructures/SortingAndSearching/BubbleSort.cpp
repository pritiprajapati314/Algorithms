#include<iostream>

using namespace std;

void bubbleSort(int arr[], int length){
    int temp;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


int main(){
    int arr[] = { 4, 5, 3, 9, 6, 7, 1, 8, 2, 0};

    bubbleSort(arr, 10);
    
    for(int i = 0; i< 10; i++){
        cout<<arr[i] << " ";
    }
    cout<< endl;
    return 0;

}