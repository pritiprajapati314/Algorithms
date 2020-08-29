#include<iostream>
using namespace std;

void insertionSort(int arr[], int len){
    for(int i = 0; i<len; i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
            }
            arr[j+1] = temp;
        }
    }


int main(){
    int arr[] = {4, 7, 2, 1, 8, 5, 9, 3, 0, 6};
    insertionSort(arr, 10);
    for(int i = 0; i<10; i++){
        cout<<arr[i]<<endl;
    }
}