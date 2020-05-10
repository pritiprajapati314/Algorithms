#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* parent;
    Node* left;
    Node* right;

    Node* insert(Node*,int);
    Node(){
    }
    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right =  NULL;
    }
};

Node* Node :: insert(Node* current_node, int value){
    if(current_node == NULL){
        return new Node(value);
    }
    else if(current_node->data > value){
        insert(current_node->left, value);
    }
    else{
        insert(current_node->right, value);
    }
    return current_node;
}

void inorderTraversal(Node* current_node){
    if(current_node != NULL){
        inorderTraversal(current_node->left);
        cout<< current_node->data << " ";
        inorderTraversal(current_node->right);
    }
}

void preorderTraversal(Node* current_node){
    if(current_node != NULL){
        cout<< current_node->data << " ";
        preorderTraversal(current_node->left);
        preorderTraversal(current_node->right);
    }
}


void postorderTraversal(Node* current_node){
    if(current_node != NULL){
        postorderTraversal(current_node->left);
        postorderTraversal(current_node->right);
        cout<< current_node->data << " ";
    }
}


Node* maximum(Node* current_node){
    Node* ptr = current_node;

    while(ptr->right != NULL){
        ptr = ptr->right;
    }

    return ptr;
}

Node* minimum(Node* current_node){
    Node* ptr = current_node;

    while(ptr->left != NULL){
        ptr = ptr->left;
    }

    return ptr;
}

bool find(Node* current_node, int value){

    if(value == current_node->data){
        return true;
    }
    else if(current_node->data > value){
        return find(current_node->left, value);
    }
    else {
        return find(current_node->right, value);
    }

    return false;
}

void successor(Node* current_node, int& s, int key){

    if(current_node == NULL){
        return;
    }
    if(current_node->data == key){
    if(current_node->right != NULL){
        Node* temp = current_node->right;
        while(temp != NULL){
            s = temp->data;
            temp = temp->left;
        }
    }
    }
    if(current_node->data > key){
        successor(current_node->left, s, key);
    }
    else{
        successor(current_node->right, s, key);
    }
    return;
}

void predecessor(Node* current_node, int& p, int key){
    if(current_node == NULL){
        return;
    }
    if(current_node->data == key){
    if(current_node->left != NULL){
        Node*temp = current_node->left;
        while(temp != NULL){
            p = temp->data;
            temp = temp->right;
        }
    }}
    if(current_node->data > key){
        predecessor(current_node->left, p, key);
    }
    else{
        predecessor(current_node->right, p, key);
    }
    return;
}



int main(){
    Node n, *head=NULL;
    Node ten=10, six=6, eleven=11, twelve=12, three=3, eight=8, fourteen=14; 
    ten.insert(&ten, 2);
    ten.left = &six;
    ten.right = &twelve;

    six.left = &three;
    six.right = &eight;

    twelve.left = &eleven;
    twelve.right = &fourteen;
    
    cout<< "Inorder Traversal: "; inorderTraversal(&ten);
    cout<< endl;
    cout<< "Preorder Traversal: "; preorderTraversal(&ten);
    cout<< endl;
    cout<< "Postorder Traversal: "; postorderTraversal(&ten);
    cout<< endl;
    Node* max = maximum(&ten);
    cout<< "Maximum Element: " << max->data;
    cout<< endl;
    Node* min = minimum(&ten);
    cout<< "Minimum Element: " <<min->data;
    cout<<endl;
    cout<<"if the foud returns 1 else return 0 : "<<find(&ten,6);
    cout<<endl;
    int s, p;
    successor(&ten, s, 10);
    predecessor(&ten, p, 10);
    cout<<"successor : "<<s<<endl;
    cout<<"predecessor : "<<p<<endl;
    return 0;
}

