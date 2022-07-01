//Leetcode 1752.
//Check if array is sorted and rotated

#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int> &v) {
    
    int n = v.size();
    int count = 0;
    
    for(int i=1;i<n;i++) {
        if(v[i-1] > v[i]) {
            count++;
        }
    }

    if(v[n-1] > v[0]) {
        count++;
    }

    return count<=1;
}


int main() {
    
    vector<int> a = {3,4,5,1,2};
    bool result = check(a);
    cout<<check;

    return 0;
}
