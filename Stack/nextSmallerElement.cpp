#include<iostream>
#include<vector>
#include<stack>
using namespace std;


vector<int> nextSmallerElement(vector<int> &arr, int n) {

    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for(int i=n-1; i>=0; i--) { //if the question asks for prev smaller element then we will run from i = 0 to i < n

        int curr = arr[i];
        while(s.top() >= curr) {
            s.pop();
        }

        ans[i] = s.top();
        s.push(curr);

    }

    return ans;
}
