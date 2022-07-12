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

void insertAtTail(Node* &tail, Node* curr) {

    tail -> next = curr;
    tail = curr;

}

Node* sortList(Node* head) {

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    //create seperate lists 0s, 1s, 2s
    while(curr != NULL) {

        int value = curr -> data;

        if(value == 0) {
            insertAtTail(zeroTail, curr);
        } else if(value == 1) {
            insertAtTail(oneTail, curr);
        } else if(value == 2) {
            insertAtTail(twoTail, curr);
        }

        curr = curr -> next;
    }

    //merge the 3 sublists

    if(oneHead -> next != NULL) { //1s list is not empty

        zeroTail -> next = oneHead -> next;
        oneTail -> next = twoHead -> next;
        twoTail -> next = NULL;

    } else {// 1s list is empty

        zeroTail -> next = twoHead -> next;
        twoTail -> next = NULL;
    }

    //setup the head
    head = zeroHead -> next;

    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}