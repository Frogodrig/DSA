#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
 public:
    int data;
    int row;
    int col;

    Node(int data, int row, int col) {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare {
 public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini = INT_FAST16_MAX, maxi = INT_FAST16_MIN;

    priority_queue<Node*, vector<Node*>, compare> minHeap;

    //insert first elements of all lists in heap
    for(int i=0; i<k; i++) {
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new Node(element, i, 0));
    }

    int start = mini, end = maxi;

    //process ranges
    while(!minHeap.empty()) {

        //fetch mini
        Node* temp = minHeap.top();
        minHeap.pop();

        mini = temp -> data;


        //range or answer
        if(maxi - mini < end - start) {
            start = mini;
            end = maxi;
        }

        //next element exist, then update maxi
        if(temp->col + 1 < n) {
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            minHeap.push(new Node(a[temp->row][temp->col + 1], temp->row, temp->col + 1));

        } else {
            break;

        }
    }

    return (end-start+1);
}