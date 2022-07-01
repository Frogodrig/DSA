//Leetcode 189.
//Rotate the given array by 'k' places.

#include<iostream>
#include<vector>
using namespace std;

void rotateArray(vector<int> &v, int k) {

    int n = v.size();
    vector<int> temp(n);

    for(int i=0;i<n;i++) {
        temp[(i+k) % n] = v[i];
    }

    v = temp;
}

int main() {
    
    vector<int> a = {1,2,3,4,5,6,7};

    rotateArray(a, 3);

    for(int i=0;i<7;i++) {
        cout<<a[i]<<" ";
    } cout<<endl;
    
    return 0;
}
