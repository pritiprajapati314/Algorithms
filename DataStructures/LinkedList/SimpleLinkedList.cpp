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

    while(currentNode->next != NULL){
        currentNode = currentNode->next;
    }
    currentNode->next = new node(data);
    
}

void update(node *currentNode, int index, int data){
    int currentIndex = 0; 

    while(currentNode->next != NULL){
        if(currentIndex == index){
            node* temp = currentNode->next;
            currentNode->next = new node(data);
            currentNode->next->next = temp;
            return;
        }else{
            currentNode = currentNode->next;
            currentIndex++;
        }
    }
    cout<<"The given index is not valid. "<<endl;
    return;
}

void remove(node *currentNode, int index){
    int currentIndex = 0;

    while(currentNode->next != NULL){
        if(currentIndex == index){
            currentNode->next = currentNode->next->next;
            return;
        }else{
            currentNode = currentNode->next;
            currentIndex++;
        }
    }
}
void printSLL(node* currentNode){
    
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