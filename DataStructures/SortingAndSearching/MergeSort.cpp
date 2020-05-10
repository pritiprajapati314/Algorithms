#include<iostream>
using namespace std;


void merge(int*, int, int, int);
void mergeSort(int arr[], int ll, int ul)
{
    int mid = (ll+ul)/2;
    if(ll < ul)
    {
        mergeSort(arr, ll, mid);
        mergeSort(arr,mid+1,ul);
        merge(arr, ll, ul, mid);
    }
}

void merge(int arr[], int ll, int ul, int mid)
{
    int brr[ul-ll], i =ll, j = mid+1,k=0;
    while( i<= mid && j<= ul) 
    {
        if(arr[i]<= arr[j])
        {
            brr[k] = arr[i];
            i++;
        }
        else
        {
            brr[k] = arr[j];
            j++;
        }
        k++;
    }  
    if(i>mid)
    {
        while(j<=ul)
        {
            brr[k] = arr[j];
            k++; j++;
        }
    } 
    else
    {
        while(i<=mid)
        {
            brr[k] = arr[i];
            k++; i++;
        }
    }
    for(int f= ll,g = 0; f<=ul; f++,g++)
    {
        arr[f] = brr[g];
    }
}


/*void merge(int arr[], int lower_limit, int mid, int upper_limit){
    int sortedArr[upper_limit - lower_limit];
    int i = lower_limit, j = mid, k=0;
    while(k < upper_limit-lower_limit){
        if(i != mid && (j == upper_limit || arr[i] <= arr[j])){
            sortedArr[k] = arr[i];
            i++; k++;
        }else{
            sortedArr[k] = arr[j];
            j++; k++;
        }
    }
    /*
    if(i == mid){
        while(j<upper_limit){
            sortedArr[k] = arr[j]; 
            k++; j++;
        }
    }else{
        while(i<mid){
            sortedArr[k] = arr[i];
            k++; i++;
        }
    }
    

    for(int x=lower_limit, k=0; x<upper_limit; x++, k++){
        arr[x] = sortedArr[k];
    }
}


void mergeSort(int arr[], int lower_limit, int upper_limit){
    int mid;
    if(upper_limit - lower_limit > 1){
        mid = (upper_limit + lower_limit)/2;
        mergeSort(arr, lower_limit, mid);
        mergeSort(arr, mid, upper_limit);
        merge(arr, lower_limit, mid, upper_limit);
    }
}

/*
int main(){
    int arr[] = {1, 4, 5 , 7, 3, 6, 56, 72};

    merge(arr, 0, 4 ,8);
    for(int i = 0; i<8; i++){
        cout<<arr[i]<<endl;
    }
}
*/


int main(){
    int arr[] = {1, 7, 5, 3, 9, 0, 2, 6, 4, 8};

    mergeSort(arr, 0, 9);

    for(int i = 0; i<=9; i++)
    {
        cout<<arr[i]<<endl;
    }

    return 0;
}
