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

        //Memory free
        if(this -> next != NULL) {
            delete next;
            next = NULL;
        }

        cout<<" Memory is free for node with data "<<value<<endl;
    }

    
};

void insertAtHead(Node* &head, int data) { //& because we don't want to make a copy

    //create new node
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;

}

void insertAtTail(Node* &tail, int data) {

    //create new node
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = tail -> next;
}

void insertAtPosition(Node* &tail, Node* &head, int position, int data) {

    //Inserting at start
    if(position == 1) {
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position - 1) {
        temp = temp -> next;
        cnt++;
    }

    //Inserting at end
    if(temp -> next == NULL) {
        insertAtTail(tail, data);
    }

    //create new node
    Node* nodeToInsert = new Node(data);

    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;

}

void deleteNode(int position, Node* &head) {

    //deleting staarting node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free
        temp -> next = NULL;
        delete temp;
    } else {

        //deleting other nodes
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {

            prev = curr;
            curr = curr -> next;
            cnt++;

        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

void print(Node* &head) {

    Node* temp = head;

    while(temp != NULL) {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    } cout<<endl;
}

int main() {
    
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(tail, head, 3, 13);
    print(head);

    deleteNode(1, head);
    print(head);

    return 0;
}
