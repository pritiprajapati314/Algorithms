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

void insert(node *head, int data){

    node *currentNode = head;

    do{
        if(currentNode->next == NULL){
            break;
        }else{
        currentNode = currentNode->next;
        }

    }while(currentNode->next != head );

    currentNode->next = new node(data);
    currentNode->next->next = head; 
    
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

    node *head = currentNode;

    do{
        currentNode = currentNode->next;  
        cout<<currentNode->data<<" "<<currentNode->next->data<<endl;  
    }while(currentNode->next != head);
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