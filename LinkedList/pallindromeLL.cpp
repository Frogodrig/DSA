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

Node* getMid(Node* head) {

    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    return slow;
}

Node* reverse(Node* head) {

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool isPallindrome(Node* head) {

    if(head == NULL || head -> next == NULL) {
        return true;
    }

    //get mid
    Node* middle = getMid(head);

    //reverse mid after middle
    Node* temp = middle -> next;
    middle -> next = reverse(temp);

    //compare both halves
    Node* head1 = head;
    Node* head2 = middle -> next;

    while( head2!=NULL ) {
        if(head1 -> data != head2 -> data) {
            return false;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }

    //Undo reverse (optional)
    temp = middle -> next;
    middle -> next = reverse(temp);

    return true;

}   
