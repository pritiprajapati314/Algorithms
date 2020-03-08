#include<iostream>
using namespace std;

void selectionSort(int arr[], int length)
{

    for(int i = 0; i< length; i++)
    {
        int sma = i;
        for(int j = i+1; j < length; j++)
        {
            if(arr[j]<arr[sma])
                sma = j;
        }
        int temp = arr[i];
        arr[i] = arr[sma];
        arr[sma] = temp; 
    }
}

int main()
{
    int arr[] = {5, 7, 3, 4, 8, 2, 6, 1, 0, 9};

    selectionSort(arr, 10);

    for(int i = 0 ; i< 10; i++)
    {
        cout<<arr[i] << " ";
    }
    cout<< endl;
}