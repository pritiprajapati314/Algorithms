#include<iostream>

using namespace std;

class Node{
    
    public:
    int value;
    Node* left;
    Node* right;
    Node(){
        
    }
    Node(int value){
        this->value = value;
        left = NULL;
        right= NULL;
        cout<<"value assigned : "<<value<<endl;
    }
};

Node* insertion(Node* current_node, int value){
    if(current_node->left == NULL){
        cout<<"job done here "<<endl;
        return new Node(value);
    }
    else if(current_node->left != NULL && current_node->right == NULL){
        Node element = value;
        cout<<"job done here "<<endl;
        return new Node(value);
    }
    else{
        insertion(current_node->left, value);
    }
    return current_node;
}

void print_data(Node* current_node){
    cout<<"i entered here"<<endl<<current_node->value<<endl;
    if(current_node == NULL){
        return;
    }
    else{
        cout<<current_node->value<<" i exectue this value"<<endl;
        print_data(current_node->left);
        cout<<current_node->value<<" i exectue this value"<<endl;
        print_data(current_node->right);
    }
    cout<<"i completed the fuction"<<endl;
    return;
}
int main(){
    Node root = 10;
    insertion(&root, 20);
    insertion(&root, 30);
    print_data(&root);
}