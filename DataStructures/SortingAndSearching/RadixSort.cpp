#include<iostream>
#include<algorithm>
using namespace std;

void maximum(int arr[], int &max, int length){
    for(int i = 0; i<length; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
}

void length(int max, int &len){
    while(max != 0){
        max = max/10;
        len++;
    }
}

void radixSort(int arr[], int length,int div,int mod){
    int b[length];
    for(int i = 0; i<length; i++){
        b[i] = (arr[i]%mod)/div;
    }
    int count[10] = {0};
    for(int i = 0; i<length; i++){
        count[b[i]]++;
    }
    for(int i = 1; i<10; i++){
        count[i] = count[i]+count[i-1];
    }

    int temp[length];
    for(int i = length-1; i>=0; i--){
        count[b[i]]--;
        temp[count[b[i]]] = arr[i];
    }
    for(int i = 0; i<length; i++){
        arr[i] = temp[i];
    }
}

int main(){
    int arr[] = {432, 8, 1, 530, 90, 88, 231, 11, 45, 677, 199, 999, 1000}, max = 0, len = 0,i=1, j= 0;
    maximum(arr, max, sizeof(arr)/sizeof(arr[0]));
    length(max, len);
    while(j<len){
        radixSort(arr, sizeof(arr)/sizeof(arr[i]), i, i*10);
        i *= 10;
        j++;
    }
    for(int i = 0; i<sizeof(arr)/sizeof(arr[i]); i++){
        cout<<arr[i]<<" ";
    }
    
}