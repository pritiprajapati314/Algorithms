#include <iostream>
#include <cstdlib>
using namespace std;

class Node{
    private:
    int data;
    Node* parent;
    Node* left;
    Node* right;
    public:
    Node(){
        this->data = -1;
        this->parent = NULL;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data){
        this->data = data;
        this->parent = NULL;
        this->left = NULL;
        this->right = NULL;
    }
}

Node* insert(Node* current_node, int data){
    if(current_node == NULL){
        return new Node(value);
    }
    else if(current)
}