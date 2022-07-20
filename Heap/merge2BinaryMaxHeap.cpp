#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> arr, int n, int i) {
    
    int largest = i;
    int left = 2*i+1; //0 based indexing
    int right = 2*i+2; //0 based indexing

    if(left < n and arr[largest] < arr[left]) {
        largest = left;
    }

    if(right < n and arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {

    //step 1:Merge both arrays into one
    vector<int> ans;
    for(auto i: a) {
        ans.push_back(i);
    }
    for(auto i: b) {
        ans.push_back(i);
    }

    //step 2:Build heap using merged array
    for(int i = (n+m)/2-1; i>=0; i--) {
        heapify(ans, (n+m), i);
    }

    return ans;
}
