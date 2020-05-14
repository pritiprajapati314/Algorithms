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
    int rightChild = index*2+1;

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

void printHeap(vector<int>& heap){

    for(int i = 0; i<heap.size(); i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    return;
}

void insert(vector<int> &heap, int data){

    heap.push_back(data);
    int child = heap.size()-1;
    int parent = (child-1)/2;
    while(parent >= 0){
        if(heap[parent] < heap[child]){
            swap(heap,parent,child);
            child = parent;
            parent = (parent-1)/2;
        }else{
            break;
        }
    }
    return;
}

void testCase(){

    vector<int> heap;

    for(int i = 5; i>0; i--){
        heap.push_back(i);
    }

    printHeap(heap);
    deleteHeap(heap,0);
    printHeap(heap);
    insert(heap,5);
    printHeap(heap);
    return;
}

int main(){   
    testCase();
    return 0;
}