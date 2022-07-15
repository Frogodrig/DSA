#include<iostream>
#include<queue>
#include <cstring>
using namespace std;

class kQueue {

    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freeSpot;
    int *next;

    public:
        kQueue(int n, int k) {
            this -> n = n;
            this -> k = k;
            front = new int[k];
            memset(front, -1, k);

            rear = new int[k];
            memset(rear, -1, k);

            arr = new int[n];

            next = new int[n];
            for(int i=0; i<n; i++) {
                next[i] = i+1;
            } next[n-1] = -1;

            freeSpot = 0;
        }

        void enqueue(int data, int qn) {
            //check for overflow
            if(freeSpot == -1) {
                cout<<"Queue is full"<<endl;
                return;

            }
            
            //find free index
            int index = freeSpot;

            //update freeSpot
            freeSpot = next[index];

            if(front[qn-1] == -1) { //1st element to be pushed (zero based indexing)
                front[qn-1] = index;
        
            } else { //link prev element to the new element
                next[rear[qn-1]] = index;

            }

            //update next
            next[index] = -1;

            //update rear
            rear[qn-1] = index;

            //push element
            arr[index] = data;
        }

        int dequeue(int qn) {

            //check for underflow
            if(front[qn-1] == -1) {
                cout<<"Queue is empty"<<endl;
                return -1;

            }

            //find index to pop
            int index = front[qn-1];

            //update front
            front[qn-1] = next[index];

            //Manage free slots
            next[index] = freeSpot;

            //update freeSpot
            freeSpot = index;

            return arr[index];
        }
};

int main() {

    kQueue q(10, 3);

    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);

    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;

    return 0;
}