/*#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int lower_limit, int upper_limit){
    int pivot = arr[upper_limit-1];
    int lower_ptr = 0; 
    int upper_ptr = 0;
    for(int i=lower_limit; i<upper_limit-1; i++){
        if(arr[i] > pivot){

            upper_ptr++;
        }
        else{
            lower_ptr++;
            upper_ptr++;
        }
    }

    arr[lower_ptr+1] = arr[upper_limit-1] + arr[lower_ptr + 1];
    arr[upper_limit-1] = arr[lower_ptr+1] - arr[upper_limit-1];
    arr[lower_ptr+1] = arr[lower_ptr+1] - arr[upper_limit-1];
    for(int i = 0; i< 10; i++){
        cout<<arr[i]<< " ";
    }
    cout<< endl;

    return lower_ptr;
}

void quickSort(int arr[], int lower_limit, int upper_limit){
    if(upper_limit - lower_limit > 1){
        int mid = partition(arr, lower_limit, upper_limit);
        quickSort(arr, lower_limit, mid+1);
        quickSort(arr, mid+1, upper_limit);
    }
}*/


// Priti
#include<iostream>
using namespace std;


int partition(int*, int , int);
void quicksort(int arr[],int ll, int ul)
{
    if(ll<ul)
    {
        int pos = partition(arr, ll, ul);
        quicksort(arr,ll, pos-1);
        quicksort(arr,pos +1, ul);
    }
}

int partition(int arr[], int ll, int ul)
{
    int privot = arr[ll];
    int start = ll;
    int end = ul;
    while(start<end){

        while(arr[start] <= privot){
            start++;
        }
        while(arr[end] > privot){
            end--;
        }
        if(start<end){
            int temp;
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
        
    }       int temp;
            temp = arr[ll];
            arr[ll] = arr[end];
            arr[end] = temp;
            cout<<end<<endl;
                return end;
}


int main(){
    int arr[] = {5, 3, 9, 1, 4, 7, 8, 2, 0, 6};
    quicksort(arr, 0, 9);
    for(int i = 0; i< 10; i++){
        cout<<arr[i]<< " "<< endl;
    }

    return 0;
}