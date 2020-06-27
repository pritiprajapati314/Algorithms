
#include <iostream> 

using namespace std;

class node{
    public:
    int data;
    node* next;
    
    node(){
        this->data = -1;
        this->next = NULL;
    }
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insert(node *currentNode, int data){

    node* temp = currentNode;
    while(currentNode->next != NULL){
        currentNode = currentNode->next;
        temp = currentNode;
    }
    temp->next = new node(data);
    
}

void update(node *currentNode, int index, int data){
    int currentIndex = 0; 
    node* temp = currentNode;

    while(currentNode->next != NULL){
        if(currentIndex == index){
            node* kemp = currentNode->next;
            temp->next = new node(data);
            temp->next->next = kemp;
            return;
        }else{
            currentNode = currentNode->next;
            temp = currentNode;
            currentIndex++;
        }
    }
    cout<<"The given index is not valid. "<<endl;
    return;
}

void remove(node *currentNode, int index){
    int currentIndex = 0;
    node* temp = currentNode;

    while(currentNode->next != NULL){
        if(currentIndex == index){
            currentNode->next = currentNode->next->next;
            return;
        }else{
            currentNode = currentNode->next;
            temp = currentNode; 
            currentIndex++;
        }
    }
}
void printSLL(node* head){

    node *currentNode = head;

    while(currentNode->next != NULL){
        currentNode = currentNode->next;  
        cout<<currentNode->data<<" ";  
    }
}

void testCaseSLL(){
    node head;
    insert(&head, 7);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 6);
    insert(&head, 8);
    insert(&head, 9);
    update(&head, 2, 16);
    remove(&head, 3);
    printSLL(&head);
    
}

int main(){
    testCaseSLL();
    return 0;
}