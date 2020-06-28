#include <iostream>

using namespace std;

class node{
    public :
        int data;
        node* previous;
        node* next;

        node(){
            this->data = -1;
            this->next = NULL;
            this->previous = NULL;
        }
        node(int data, node* previous){
            this->data = data;
            this->next = NULL;
            this->previous = previous;
        }
};

void insert(node *currentNode, int data){

    node* head = currentNode;
    node* temp = currentNode;
    do{
        
        if(currentNode->next == NULL){
            break;
        }
        else{
        currentNode = currentNode->next;
        temp = currentNode;
        }

    }while(currentNode->next != head);

    currentNode->next = new node(data, temp);
    currentNode->next->next = head;
}

void update(node *currentNode,int index, int data){
    int currentIndex = 0;

    while(currentNode->next != NULL){
        if(currentIndex == index){
            node *temp = currentNode->next;
            currentNode->next = new node(data, currentNode);

            currentNode = currentNode->next;
            currentNode->next = temp;
            currentNode->next->previous = currentNode;
            return;
        }else{
            currentNode = currentNode->next;
            currentIndex++;
        }
    }
    cout<<" This is an invalid index ";
    return;
}

void remove(node *currentNode, int index){
    
    int currentIndex = 0; 

    while(currentNode->next != NULL){
        if(currentIndex == index){
            node *temp = currentNode;
            currentNode->next = currentNode->next->next;

            currentNode = currentNode->next;
            currentNode->previous = temp;
            return;
        }else{
            currentNode = currentNode->next;
            currentIndex++;
        }
    }
}

void printDLL(node* head){

    node *currentNode = head;
    int index = 0;
    do{
        currentNode = currentNode->next;  
        cout<<index<<" "<<currentNode->previous->data<<" "<<currentNode->data<<" "<<currentNode->next->data<<endl;  
        index++;
    }while(currentNode->next != head);
}

void testCaseDLL(){
    node head;
    insert(&head, 4);
    insert(&head, 7);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 6);
    insert(&head, 8);
    insert(&head, 9);
    update(&head, 2, 15);
    remove(&head, 2);
    printDLL(&head);
}

int main(){
    testCaseDLL();
    return 0;
}
