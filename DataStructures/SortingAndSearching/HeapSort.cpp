#include<iostream>
#include<vector>
using namespace std;

int max(vector<int>& heap, int leftChild, int rightChild){
    if(rightChild >= heap.size()){
        return leftChild;
    }
    else if(heap[leftChild] > heap[rightChild]){
        return leftChild;
    }
    else{
        return rightChild;
    }
}

void swap(vector<int> &heap, int newParent, int parent){
    int temp = heap[newParent];
    heap[newParent] = heap[parent];
    heap[parent] = temp;
    
    return;
}

void deleteHeap(vector<int>& heap, int index){
    heap[index] = heap[heap.size()-1];

    heap.pop_back();
    int parent = index;
    int leftChild = index*2+1;
    int rightChild = index*2+2;

    while(leftChild < heap.size()){
        int newParent = max(heap, leftChild, rightChild);

        if(heap[newParent] > heap[parent]){
        swap(heap, newParent, parent);
        parent = newParent;
        leftChild = parent*2+1;
        rightChild = parent*2+2;
        }else{ break;}
    }
    return;
}

void heapSort(vector<int> heap){

    int size = heap.size();

    //we are going to delete the root again and again;

    while(size > 0){
        cout<<heap[0]<<" ";
        deleteHeap(heap,0);
        size--; 
    }
}

void testCase(){

    vector<int> heap;
    heap.push_back(14);
    heap.push_back(2);
    heap.push_back(5);
    heap.push_back(1);
    heap.push_back(0);
    heap.push_back(3);
    heapSort(heap);
}

int main(){

    testCase();
}