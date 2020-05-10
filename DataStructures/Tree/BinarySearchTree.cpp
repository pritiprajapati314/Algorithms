#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* parent;
    Node* left;
    Node* right;

    Node(){
        this->data=-1;
        this->parent=NULL;
        this->left=NULL;
        this->right=NULL;
    }
    Node(int value){
        this->data=value;
        this->parent=NULL;
        this->left=NULL;
        this->right=NULL;
    }
};


Node* insert(Node* current_node, int value){
    if(current_node == NULL){
        return new Node(value);
    }
    else if(current_node->data > value){
        current_node->left = insert(current_node->left, value);
    }
    else{
        current_node->right = insert(current_node->right, value);
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

Node* findNode(Node* currentNode, int value){
    if(currentNode != NULL){
        if(currentNode->data == value){
            return currentNode;
        }
        else if(currentNode->data > value){
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


void successor(Node* current_node, int& s, int key){

    if(current_node == NULL){
        return;
    }
    if(current_node->data == key){
    if(current_node->right != NULL){
        Node* temp = current_node->right;
        s = temp->data;
        while(temp->left != NULL){
            s = temp->data;
            temp = temp->left;
        }
    }
    }
    if(current_node->data > key){
        s = current_node->data;
        successor(current_node->left, s, key);
    }
    else{
        successor(current_node->right, s, key);
    }
    return;
}

Node* predecessor(Node* current_node, int& p, int key){
    if(current_node == NULL){
        return NULL;
    }
    if(current_node->data == key){
    if(current_node->left != NULL){
        Node* temp = current_node->left;
        p = temp->data;
        while(temp->right != NULL){
            temp = temp->right;
            p = temp->data;
        }
    }
    }
    if(current_node->data > key){
        //cout<<current_node->data<<endl;
        predecessor(current_node->left, p, key);
    }
    else{
        if(current_node->data < key)
            p = current_node->data;
        //cout<<p<<" "<<key<<endl;
        predecessor(current_node->right, p, key);
    }
    return current_node;
}


// determine if the currentNode is left child or right child
Node* determineChild(Node* currentNode) {
    if(currentNode->parent->left == currentNode){
        return currentNode->parent->left;
    }else{
        return currentNode->parent->right;
    }
}

// determine if the currentNode is a left child or right child
void deleteNode(Node* currentNode){
    // case 1: currentNode is a leaf ( No childrens)
    if(currentNode->left == NULL && currentNode->right == NULL){
        Node* n = determineChild(currentNode);
        n = NULL;        
    }
    // case 2: currentNode has only one child (either left or right)
    else if(currentNode->left != NULL || currentNode->right != NULL){
        if(currentNode->left != NULL){                  // if currentNode has only left child
            Node* n = determineChild(currentNode);
            n = currentNode->left;
        }else{                                          // if currentNode has only right child
            Node* n = determineChild(currentNode);
            n = currentNode->right;
        }
    }
    // case 3: currentNode has two children
    else{
        int p;
        Node* predecessorNode = predecessor(currentNode,p,currentNode->data);
        currentNode->data = predecessorNode->data;
        deleteNode(predecessorNode);
    }
    cout<<"task completed"<<endl;
}

void deleteNode(Node* head, int n){
    
    Node current_node = 
}



int main(){
    Node n, *head=NULL;
    Node ten=10, six=6, eleven=11, twelve=12, three=3, eight=8, fourteen=14; 
    ten.left = &six;
    ten.right = &twelve;

    six.left = &three;
    six.right = &eight;

    twelve.left = &eleven;
    twelve.right = &fourteen;
    insert(&ten, 5);
    insert(&ten, 1);
    insert(&ten, 4);
    insert(&ten, 7);
    insert(&ten, 9);
    insert(&ten, 13);
    
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
    int s = -1, p = -1;
    successor(&ten, s, 14);
    predecessor(&ten, p, 14);
    cout<<"successor : "<<s<<endl;
    cout<<"predecessor : "<<p<<endl;
    deleteNode(&six);
    cout<< "Inorder Traversal: "; inorderTraversal(&ten);
    cout<< endl;
    return 0;
}

