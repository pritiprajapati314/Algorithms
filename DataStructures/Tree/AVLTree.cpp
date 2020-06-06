#include<iostream>
using namespace std;

class Node{
public:
    public:
    int data;
    int height;
    Node* parent;
    Node* right;
    Node* left;


    Node(){
        this->data = -1;
        this->height = 0;
        this->parent = NULL;
        this->right = NULL;
        this->left = NULL;
    }
    Node(int data){
        this->data = data;
        this->height = 0;
        this->parent = NULL;
        this->right = NULL;
        this->left = NULL;
    }
    Node(int data, Node* parent, int height){
        this->data = data;
        this->height = height;
        this->parent = parent;
        this->right = NULL;
        this->left = NULL;
    }

    void setBothChild(Node* leftChild, Node* rightChild){
        this->left = leftChild;
        this->right = rightChild;
        leftChild->parent = this;
        rightChild->parent = this;
    }

    void setOnlyRightChild(Node* rightChild){
        this->right = rightChild;
        rightChild->parent = this;
    }

    void setOnlyLeftChild(Node* leftChild){
        this->left = leftChild;
        leftChild->parent = this;
    }
};

//returns max between value1 and value2
int maximumValue(int value1, int value2){
    if(value1>value2){
        return value1;
    }
    else{
        return value2;
    }
}

// returns the height of the currentNode
int height(Node* currentNode){
    if(currentNode == NULL)
        return 0;
    return 1 + maximumValue(height(currentNode->left), height(currentNode->right));
}

void inorderTraversal(Node* currentNode){
    if(currentNode != NULL){
        inorderTraversal(currentNode->left);
        cout<< currentNode->data<< " ";
        inorderTraversal(currentNode->right);
    }
}


Node* insert(int data, Node* currentNode, Node* currentParentNode,int height){    
    if(currentNode == NULL){
        return new Node(data, currentParentNode, height);
    }
    else if(currentNode->data > NULL){
        currentNode->left = insert(data,currentNode->left,currentNode,height+1);
    }
    else{
        currentNode->right = insert(data,currentNode->right,currentNode,height+1);
    }
    return currentNode;
}

//it passses the address of the last element

void rebalance(Node* currentNode, Node* childRebalance){
    
    if(slope == 2 || slope == -2){

    }
}

void testBalancedTree(){
    Node* five = new Node(5);
    Node* three = new Node(3);
    Node* one = new Node(1);
    Node* four = new Node(4);
    Node* two = new Node(2);
    Node* seven = new Node(7);
    Node* nine = new Node(9);
    Node* eight = new Node(8);

    five->setBothChild(three, seven);
    three->setBothChild(one, four);
    one->setOnlyRightChild(two);
    seven->setOnlyRightChild(nine);
    nine->setOnlyLeftChild(eight);


    inorderTraversal(five);
    cout<< endl;

    cout<< height(five);
}

int main(){
    testBalancedTree();
    return 0;
}