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

//Recursive solution 2 || T.C = O(n), S.C = O(n)
Node* reverseRecursive1(Node* head) {

    //base case 
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    Node* smallHead = reverseRecursive1(head -> next);

    head -> next -> next = head;
    head -> next = NULL;

    return smallHead;
}

//Recursive solution 1
void reverseRecursive(Node* &head, Node* curr, Node* prev) {
    //Base case
    if(curr == NULL) {
        head = prev;
        return;
    }
 
    Node* forward = curr -> next;
    reverseRecursive(head, forward, curr);

    curr -> next = prev;
}

Node* reverseLinkedList(Node* &head) {

    if(head == NULL || head -> next == NULL) { //empty list or single node list
        return head;
    }

    /*Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    //iterative solution T.C = O(n), S.C = O(1)
    while(curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }*/

    //recursive solution 1
    Node* prev = NULL;
    Node* curr = head;
    reverseRecursive(head, curr, prev);

    return prev;

}
