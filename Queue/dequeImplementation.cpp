#include<iostream>
using namespace std;

class Deque {

    int *arr;
    int front;
    int rear;
    int size;

    public:

        Deque(int n) {
            this -> size = n;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        bool pushFront(int x) {

            //check if full
            if((front == 0 && rear == size-1) or (front != 0 and rear == (front-1)%(size-1))) {
                cout<<"Queue is full"<<endl;
                return false;

            }

            else if(front == -1) { //pushing 1st element
                front = rear = 0;

            }

            else if(front == 0 && rear != size-1) { //maintaining cyclic nature
                front = size-1;

            }

            else {
                front--;
            }
            arr[front] = x;

            return true;
        }

        bool pushRear(int x) {
            //check if full
            if((front == 0 && rear == size-1) or (front != 0 and rear == (front-1)%(size-1))) {
                cout<<"Queue is full"<<endl;
                return false;

            }

            else if(rear == -1) { //pushing 1st element
                front = rear = 0;

            }

            else if(rear == size-1 && front != 0) { //maintaining cyclic nature
                rear = 0;

            }

            else {
                rear++;
            }
            arr[rear] = x;

            return true;
        }

        int popFront() {
            //Check is empty
            if(front == -1) {
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            int ans = arr[front];
            arr[front] - 1;
            if(front == rear) { //single element to be popped
                front = rear = -1;

            }
            else if(front == size-1) { //to maintain cyclic nature
                front = 0;

            }
            else { //normal flow
                front++;

            }

            return ans;
        }

        int popRear() {
            if(rear == -1) {
                cout<<"Queue is empty"<<endl;
                return -1;

            }
            int ans = arr[rear];
            arr[rear] - 1;
            if(front == rear) { //single element to be popped
                front = rear = -1;

            }

            else if(rear == 0) { //maintain cyclic nature
                rear == size - 1;

            }

            else { //normal flow
                rear--;

            }
            
            return ans;
        }

        int getFront() {
            if(isEmpty()) {
                return -1;

            }

            return arr[front];
        }

        int getRear() {
            if(isEmpty()) {
                return -1;

            }

            return arr[rear];
        }

        bool isEmpty() {
            if(front == -1) {
                return true;

            } else {
                return false;

            }
        }

        bool isFull() {
            if((front == 0 and rear == size-1) or (front != 0 and rear == (front-1)%(size-1))) {
                return true;

            } else {
                return false;

            }
        }
};