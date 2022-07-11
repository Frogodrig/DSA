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

Node* kReverse(Node* head, int k) {

    //base case
    if(head == NULL) {
        return NULL;
    }

    //step 1: reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while(curr!=NULL && count < k) {

        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    //step 2: recursion will solve the rest
    if(next != NULL) {
        head -> next = kReverse(next, k);
    }

    //step 3: return head of reversed list
    return prev;
}