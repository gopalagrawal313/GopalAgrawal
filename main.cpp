#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
    
    ~Node() {
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        
    cout << "Memory free for the node with value " << value << endl;
    }
};

void printList(Node* &head) {
    if(head == NULL) {
        cout << "List is Empty, kya Print kare bro!!" <<endl;
        return;
    }
    
    Node* temp = head;
    while(temp != NULL) {                   //**************// Na ki temp->next
        cout << temp -> data <<" ";
        temp = temp -> next;
    }
    cout << endl;
    
}

void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &head, int data) {
    Node* newNode = new Node(data);
    
    Node* temp = head;
    while(temp -> next != NULL){                //***************// ka next
        temp = temp -> next;
    }
    
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void insertAtPosition(Node* &head, int position, int data) {
    
    //Special Case handle kar lo bhaii
    if(position == 0){
        cout<<"0 is Invalid Position to insert into List, Baaki sab badiya hai " << endl;
        return ;
    }
    
    if(position == 1) {
        insertAtHead(head, data);
        return;
    }
    
    Node* temp = head;
    int count = 1;
    while(count < position -1) {
        temp = temp->next;
        count++;
    }
    
    if(temp -> next == NULL) {
        insertAtTail(head, data);
        return;
    }
    
    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNode(Node* &head, int position) {
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else {
        int count = 1;
        Node* prev = head;
        Node* curr = head -> next;
        
        while(count < position - 1) {
            prev = curr;
            curr = curr -> next;
            count++;
        }
        
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
    
}

int main()
{
    cout << "Thik hai Sab" << endl << endl;
    
    Node* head = new Node(10);
    cout<<"Head value is: ";
    printList(head);
    cout << endl;
    
    cout << "Insertion At Head starts from here " << endl;
    insertAtHead(head, 20);
    printList(head);
    insertAtHead(head, 50);
    printList(head);
    insertAtHead(head, 150);
    printList(head);
    cout << endl;
    
    cout << "Insertion At Tail starts from here " << endl;
    insertAtTail(head, 211);
    printList(head);
    insertAtTail(head, 511);
    printList(head);
    insertAtTail(head, 611);
    printList(head);
    insertAtTail(head, 711);
    printList(head);
    cout << endl;
    
    cout << "Insertion At Position starts from here " << endl;
    insertAtPosition(head, 4, 1900);
    printList(head);
    insertAtPosition(head, 1, 2100);
    printList(head);
    insertAtPosition(head, 11, 2200);
    printList(head);
    cout << endl;
    
    cout << "Insertion At 0th index, Special Case " << endl;
    insertAtPosition(head, 0, 2200);
    cout << endl;
    
    
    cout<<"Deletion starts from here "<<endl;
    deleteNode(head, 8);
    printList(head);
    deleteNode(head, 2);
    printList(head);
    deleteNode(head, 3);
    printList(head);
    deleteNode(head, 4);
    printList(head);
    deleteNode(head, 1);
    printList(head);
    
    
    return 0;
}









