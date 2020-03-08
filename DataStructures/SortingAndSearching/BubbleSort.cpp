#include<iostream>

using namespace std;

void bubbleSort(int arr[], int length){
    int temp;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            if(arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
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

}