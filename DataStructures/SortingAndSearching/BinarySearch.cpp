#include<iostream>
using namespace std;

int BinarySearch(int arr[], int n, int length, int value)
{
    if(length>= 1)
    {
        int mid = (length + n)/2;
        
        if(arr[mid] == value)
            return true;
        if(arr[mid] > value)
            return BinarySearch(arr, n, mid-1, value);
        if(arr[mid] < value)
            return BinarySearch(arr, mid + 1, length, value);
    }
    return false;
}
int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,};
    
    int result = BinarySearch(arr, 0, 9, 6);
    cout<<result;
    return 0;
}