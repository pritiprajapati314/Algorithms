#include<iostream>
#include<vector>
using namespace std;


/*void countingSort(int arr[], int length){
    int size = std::max_length(arr, arr+length);
    cout<< size;
}


int main(){
    int arr[] = {2, 1, 1, 0, 2, 5, 4, 0, 2, 8, 7, 7, 9, 2, 0, 1, 9};
    int length = sizeof(arr)/sizeof(arr[0]);

    countingSort(arr, length);

    return 0;
}*/


// Priti

void max_min(int arr[], int* max, int* min, int length){
for(int i = 0; i<length; i++){
if(arr[i] > *max)
    *max = arr[i];
if(arr[i] < *min)
    *min = arr[i];    
}
}

void countingSort(int arr[],int brr[], int length , int max, int min){
    int i = min;
   while(i<= length - 1)
   {
       int  a = arr[i];
       brr[a]++;
       i++;
   }
}


int main(){

    int arr[] = {2,1,1,2,5,4,2,8,7,7,9,2,1,9}, max = 0, min = 0;

    max_min(arr, &max, &min, sizeof(arr)/sizeof(arr[0]));
    int brr[max+1] = {0};

    countingSort(arr, brr,sizeof(arr)/sizeof(arr[0]), max, min);

    int length = sizeof(arr)/sizeof(arr[0]);
    
    ///algorithm 1
    for(int i = 0; i<= max; i++){
           for(int j = 0; j<brr[i]; j++){
               cout<<i<<" ";
           }
    }cout<<endl;

    ///address updation: number of degits repeating itself
    int sum = 0;
    for(int i = 0; i<= max; i++){
               sum += brr[i];
               brr[i] = sum;
               cout<<brr[i]<<" ";               
    }cout<<endl;


    //counting sort algorithm
    int crr[length];
    for(int i = length-1; i>-1; i--)
    {
        int temp = arr[i];
        int kemp = brr[temp];
        brr[temp]--;
        crr[kemp] = arr[i];
    }
    
    for(int i = 1; i<length+1; i++)
    {
        cout<<crr[i]<<" ";
    }
}

/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
    long int n;
    cin >> n;
    
    string ar[n];
    
    for(long int i = 0; i < n/2; i++){
        int x;
        cin >> x;
        
        string s;
        cin >> s;
        
        ar[x] = ar[x] + "-" + " ";
        
    }

    
    for(long int i = n/2; i < n; i++){
        int x;
        cin >> x;
        
        string s;
        cin >> s;

        ar[x] = ar[x] + s + " ";
        
    }
    
    
    for(int i = 0; i < n; i++)
        cout << ar[i];

    return 0;
}





//0 ab
0 ef
0 ab
0 ef
0 ij
0 to
1 be
1 or
2 not
2 to
3 be
4 ij
4 that
4 is
4 the
5 question
6 cd
6 gh
6 cd
6 gh
sorted = [['-', '-', '-', '-', '-', 'to'], ['be', 'or'], ['not', 'to'], ['be'], ['-', 'that', 'is', 'the'], ['question'], ['-', '-', '-', '-'], [], [], [], []]
*/


