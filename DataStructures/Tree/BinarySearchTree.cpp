#include <iostream> 
using namespace std; 
  
#include<iostream>
using namespace std;

class node{

    private:

    int data;
    node *left;
    node *right;

    public:

//default constructor
    node();
//parameterized constructor
    node(int);
//insert member function
    node* Insert(node*, int);
};

//default constructor defination
node :: node() : data(0),left(NULL),right(NULL){}
// parameterized constructor defination
node :: node(int value){
    data = value;
    left = NULL;
    right = NULL;
}

//insert member function defination
node* node:: Insert(node* root, int value){

/*since the root is either equal to the value null or some assigned value so if root is equals to null it will behave as true
the function will execute
here if it is the leaf then this condition will make a new node and assign the value*/
if(!root){

//it will make the new node type element and will assign it the value
    return new node(value);
}
if(value > root->data){
    root -> right = Insert(root->right, value);
}
else if(value < root->data){
    root -> left= Insert(root->left, value);
}

//it will at last will at last give the main root address back
return root;
}


int main(){
    node n, *root = NULL;
    root = n.Insert(root,70);
    root = n.Insert(root, 30); 
    cout<<root<<endl;
    root = n.Insert(root, 47); 
    cout<<root<<endl;
    root = n.Insert(root, 20); 
    cout<<root<<endl;
    root = n.Insert(root, 65); 
    cout<<root<<endl;
    root = n.Insert(root, 10); 
    cout<<root<<endl;
}