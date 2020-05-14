#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* parent;
    Node* right;
    Node* left;
    Node(){
        this->data = -1;
        this->parent = NULL;
        this->right = NULL;
        this->left = NULL;
    }
    Node(int data){
        this->data = data;
        this->parent = NULL;
        this->right = NULL;
        this->left = NULL;
    }
    Node(int data, Node* parent){
        this->data = data;
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


// inorder traversal for binary search tree
void inorderTraversal(Node* currentNode){
    if(currentNode != NULL){
        inorderTraversal(currentNode->left);
        cout<< currentNode->data<< " ";
        inorderTraversal(currentNode->right); 
    }
}

// returns the node in binary search tree whose data is equal to value
// returns NULL if there is no such node
Node* find(Node* currentNode, int value){
    if(currentNode == NULL){
        return NULL;
    }
    if(currentNode->data == value){
        return currentNode;
    }
    if(currentNode->data > value){
        return find(currentNode->left, value);
        //cout<< currentNode->data << " " <<  currentNode<< endl;
    }
    else{
        return find(currentNode->right, value);
        //cout<< currentNode->data << " " << currentNode<< endl;
    }
}

// Returns the minimum value in a binary search tree i.e leftmost node 
Node* minVal(Node* currentNode){
    if(currentNode->left == NULL){
        return currentNode;
    }
    else{
        return minVal(currentNode->left);
    }
}

// returns the minimum value in a binary serch tree i.e rightmost node
Node* maxVal(Node* currentNode){
    if(currentNode->right == NULL){
        return currentNode;
    }
    else{
        return maxVal(currentNode->right);
    }
}

// returns the successor node of the currentNode
// returns NULL if there is no successor to the currentNode
Node* successor(Node* currentNode){
    if(currentNode->right != NULL){
        return(minVal(currentNode->right));
    }
    Node* y = currentNode->parent;

    while(y != NULL && currentNode == y->right){
        currentNode = y;
        y = y->parent;
    }
    return(y);
}

// returns the predecessor node of the currentNode
// returns NULl if there is no predecessor to the currentNode
Node* predecessor(Node* currentNode){
    if(currentNode->left != NULL){
        return(maxVal(currentNode->left));
    }
    Node* y = currentNode->parent;

    while(y != NULL && currentNode == y->right){
        currentNode = y;
        y = y->parent;
    }
    return(y);
}


//Insert a new node in binary search tree
//genral function call syntax:
//insert(rootNode, parent, valueToInsert);
Node* insert(Node* currentNode, Node* currentNodeParent, int data){
    if(currentNode == NULL){
        return new Node(data, currentNodeParent);
    }
    else if(currentNode->data> data){
        currentNode->left= insert(currentNode->left, currentNode, data);
    }
    else{
        currentNode->right = insert(currentNode->right, currentNode, data);
    }
    
    return currentNode;
}

void deleteNode(Node* currentNode, int data){
    currentNode = find(currentNode,data);

    //for leaf
    if(currentNode->left == NULL && currentNode->right == NULL){
        if(currentNode == currentNode->parent->left){
            currentNode->parent->left = NULL;
        }else{
            currentNode->parent->right = NULL;
        }
    }

    //for one child
    //one left child
    if(currentNode->left != NULL && currentNode->right == NULL){
        currentNode->left->parent = currentNode->parent;
        if(currentNode == currentNode->parent->left){
            currentNode->parent->left = currentNode->left;
        }else{
            currentNode->parent->right = currentNode->left;
        }
    }

    //for one child
    //one right child
    if(currentNode->right != NULL && currentNode->left == NULL){
        currentNode->right->parent = currentNode->parent;
        if(currentNode == currentNode->parent->right){
            currentNode->parent->right = currentNode->right;
        }else{
            currentNode->parent->left = currentNode->right;
        }
    }

    //for two child
    if(currentNode->right != NULL && currentNode->left != NULL){
        Node* pv = predecessor(currentNode);
        Node* sv = successor(currentNode);
        if( pv->data != -1){
            currentNode->data = pv->data;
            delete(pv);
        }else{
            currentNode->data = sv->data;
            delete(sv);
        }
    }
}

//function for testing binary search tree functions
void testBinarySearchTree(){
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


    // check insert function
    cout<< "checking insert function ...... " <<endl;

    inorderTraversal(five);
    cout<<endl;
    insert(five, NULL, 15);
    deleteNode(five,8);
    inorderTraversal(five);
    cout<<endl<< endl;

    // checking find function
    cout<< "checking find function ...... "<<endl;
    Node* node = find(five, 9);
    cout<< node->data<< endl;
    cout<< endl;

    // checking predecessor function
    cout<< "checking predecessor function ...... "<< endl;
    Node* predecessorNode = predecessor(nine);
    cout<< predecessorNode->data;
    cout<< endl;
}

int main(){
    testBinarySearchTree();
    return 0;
}