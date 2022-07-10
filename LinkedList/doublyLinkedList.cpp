#include<iostream>
using namespace std;

class Node {

    public: 
    int data;
    Node* prev;
    Node* next;

    Node(int data) {

        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node() {
        int val = this -> data;

        if(next != NULL) {
            delete next;
            next = NULL;
        }

        cout<< "memory free for node with data "<<val<<endl;

    }

};

void print(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    } cout<<endl;
}

int getLength(Node* head) {

    Node* temp = head;
    int len = 0;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    } cout<<endl;

    return len;
}

void insertAtHead(Node* &head,Node* &tail, int data) {

    if(head == NULL) {

        Node* temp = new Node(data);
        head = temp;
        tail = temp;

    } else {
        Node* temp = new Node(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
    
}

void insertAtTail(Node* &head, Node* &tail, int data) {

    if(tail == NULL) {

        Node* temp = new Node(data);
        tail = temp;
        head = temp;

    } else {

        Node* temp = new Node(data);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
    
}

void insertAtPosition(Node* &head,Node* &tail, int position, int data) {

    if(position == 1) {
        insertAtHead(head, tail, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == NULL) {
        insertAtTail(head, tail, data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
    
}

void deleteNode(int position, Node* &head, Node* &tail) {

    //deleting staarting node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        //memory free
        delete temp;
        
    } else {

        //deleting middle or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {

            prev = curr;
            curr = curr -> next;
            cnt++;

        }

        //Handling tail before deleting last node
        if(curr -> next == NULL) {
            curr -> prev = NULL;
            prev -> next = curr -> next;
            tail = prev;
        } else {
            curr -> prev = NULL;
            prev -> next = curr -> next;
            curr -> next = NULL;
        }

        delete curr;
    }
}

int main() {
    
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    cout<<getLength(head)<<endl;

    insertAtHead(head, tail, 11);
    print(head);

    insertAtTail(head, tail, 25);
    print(head);

    deleteNode(3, head, tail);
    print(head);

    return 0;
}
