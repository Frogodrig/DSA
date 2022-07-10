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

void insertNode(Node* &tail, int element, int data) {

    if(tail == NULL) {
        Node* temp = new Node(data);
        tail = temp;
        temp -> next = temp;
        return;
    } else {
        //non empty list
        //assuming that the element is present in the list

        Node* pointingAt = tail;

        while (pointingAt -> data != element) {
            pointingAt = pointingAt -> next;
        }

        //element found: pointingAt is on top of the element

        Node* temp = new Node(data);

        temp -> next = pointingAt -> next;
        pointingAt -> next = temp;
        
    }

}

void print(Node* &tail) {

    Node* temp = tail;
    
    if(tail == NULL) {
        cout<<"List is empty"<<endl;
    }

    do{
        cout<<temp -> data<<" ";
        temp = temp -> next;
    } while(temp != tail);
    
    cout<<endl;
}

void deleteNode(Node* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout<<"List is already empty"<<endl;
        return;
    } else {
        //non-empty

        //assuming that 'value' is present in the linked list
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 node LL
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 node LL
        else if(tail == curr) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;
    }
}

int main() {
    
    Node* tail = NULL;

    //inserting in an empty list
    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);

    deleteNode(tail, 3);
    print(tail);

    return 0;
}

