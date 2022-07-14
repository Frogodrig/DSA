#include<iostream>
#include<vector>
#include<stack>
#include<limits>
using namespace std;

//T.C = O(n), S.C = O(n)
vector<int> nextSmallerElement(vector<int> arr, int n) {

    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for(int i=n-1; i>=0; i--) {

        int curr = arr[i];
        while((s.top() != -1) and (arr[s.top()] >= curr)) {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

vector<int> prevSmallerElement(vector<int> arr, int n) {

    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for(int i=0; i<n; i++) {

        int curr = arr[i];
        while((s.top() != -1) and (arr[s.top()] >= curr)) {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int> &heights) {

    int n =heights.size();

    vector<int> next(n);
    next = nextSmallerElement(heights, n);
    
    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = INT16_MIN;
    for(int i=0; i<n; i++) {
        int l =heights[i];
        
        if(next[i] == -1) { //case when all array elements are equal: prev and next for all elements will be -1
            next[i] = n;    //therefore for each array element the nextsmallest will be n
        }

        int b = next[i] - prev[i] - 1;

        int newArea = l*b;
        area = max(area, newArea);
    }

    return area;
}