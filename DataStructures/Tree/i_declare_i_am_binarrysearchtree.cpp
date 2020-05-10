#include<iostream>
#include<cstdlib>
using namespace std;

class Node{    
public:
    int value;
    Node* left;
    Node* right;
    Node(){
        this->value=0;
        this->left=NULL;
        
    }
    Node(int value){
        this->value = value;
        this->left = NULL;
        this->right= NULL;
    }
};

Node* removal(Node* current_node,int key){
    if(current_node->value == key){
        return current_node;
    }else if(current_node->value > key){
        removal(current_node->left, key);
    }else{
        removal(current_node->right, key);
    }
}

Node* findNode(Node* currentNode, int value){
    if(currentNode != NULL){
        if(currentNode->value == value){
            return currentNode;
        }
        else if(currentNode->value > value){
            return findNode(currentNode->left, value);
        }
        else{
            return findNode(currentNode->right, value);
        }
    }
    else{
        return NULL;
    }
}

void deleteNode(Node* head, int key){
    Node* current_node =removal(head, key);
    Node*temp = current_node;
    if(temp->left == NULL && current_node->right == NULL){
        free(temp);
    }
    else if(current_node->left != NULL &&  current_node->right == NULL){
        temp = temp->left;
        while(temp->right != NULL){
            temp = temp->right;
        }
        cout<<"what is your problem"<<endl;
        current_node->value = temp->value;
        free(temp); 
    }
    else if(current_node->left == NULL && current_node->right != NULL){
        temp = current_node->right;
        while(temp->left != NULL){
            temp = temp->left;
        }
        cout<<"making me sick to death"<<endl;
        current_node->value = temp->value;
        free(temp); 
    } 
}




Node* insertion(Node* current_node, int value){
    if(current_node == NULL){
        return new Node(value);
    }
    if(current_node->value < value){
        current_node->right = insertion(current_node->right, value);
    }
    else{
        current_node->left = insertion(current_node->left, value);
    }
    return current_node;
}


void print_data(Node* current_node){
    if(current_node != NULL){
    print_data(current_node->left);
    cout<<current_node->value<<endl;
    print_data(current_node->right);
    }
}

int main(){
    Node* root = NULL;
    root = insertion(root, 10);
    insertion(root, 6);
    insertion(root, 12);
    insertion(root, 3);
    insertion(root, 8);
    insertion(root, 11);
    insertion(root, 14);
    /*cout<<"enter the number of elements to be entered";
    int x, y;
    cin>>x;
    for(int i = 0; i<x; i++){
        cout<<"enter the element"<<endl;
        cin>>y;
        insertion(root, y);
    }*/
    deleteNode(root,11);
    cout<<endl;
    print_data(root);
}