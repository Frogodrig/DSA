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

Node* uniqueSortedList(Node* head) {

    //empty list
    if(head == NULL) {
        return NULL;
    }

    //non empty list
    Node* curr = head;

    while(curr != NULL) {
        
        if((curr -> next != NULL) && curr -> data == curr -> next -> data) {

            Node* next_next = curr -> next -> next;
            Node* nodetoDelete = curr -> next;
            delete(nodetoDelete);
            curr -> next = next_next;

        } else { // not equal

            curr = curr -> next;

        }
    }

    return head;
}