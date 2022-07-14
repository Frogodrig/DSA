//Max area of rectangle in a binary matrix with all 1's (GFG)
//https://practice.geeksforgeeks.org/problems/max-rectangle/1

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextSmallerElement(int *arr, int n) {

    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for(int i=n-1; i>=0; i--) {

        int curr = arr[i];
        while(s.top() <= curr) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }

    return ans;
}

vector<int> prevSmallerElement(int *arr, int n) {

    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for(int i=0; i<n-1; i++) {

        int curr = arr[i];
        while(s.top() <= curr) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }

    return ans;
}

int largestRectangleArea(int *heights, int n) {

    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = INT16_MIN;

    for(int i=0; i<n; i++) {
        int l = heights[i];

        if(next[i] == -1) {
            next[i] = n;
        }

        int b = next[i] - prev[i] - 1;
        int newArea = l*b;
        area = max(area, newArea);

    }

    return area;
}

int maxArea(int M[10000][10000], int n, int m) {

    //compute area for 1st row
    int area = largestRectangleArea(M[0], m);

    //for remaining rows
    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {

            //row update: by adding prev row values
            if(M[i][j] != 0) {
                M[i][j] = M[i][j] + M[i-1][j];

            } else {
                M[i][j] = 0;

            }
        }

        //Entire row is updated now
        int newArea = largestRectangleArea(M[i], m);
        area = max(area, newArea);

    }

    return area;
}
