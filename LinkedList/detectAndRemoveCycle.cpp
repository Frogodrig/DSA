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

//fast and slow pointer approach
Node* floydDetectLoop(Node* head) {

    if(head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL) {
        
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }
        slow = slow -> next;

        if(slow == fast) {
            cout<<"Cycle is present at: "<<slow -> data<<endl; //the element will be a part of the loop, not necessary that it is the starting of the loop
            return slow;
        }
    }

    return NULL;
}

//get the starting node of loop
Node* getStartingNode(Node* head) {

    if(head == NULL) {
        return NULL;
    }

    Node* intersection = floydDetectLoop(head);

    Node* slow = head;
    while(slow != intersection) {

        slow = slow -> next;
        intersection = intersection -> next;

    }

    return slow;

}