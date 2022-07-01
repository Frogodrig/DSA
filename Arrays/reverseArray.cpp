//Reverse array after a certain element 'm'
#include<iostream>
#include<vector>
using namespace std;

//Two pointer approach
void reverseArray(vector<int> &v, int m) {
    int start = m+1;
    int end = v.size() - 1;

    while(start <= end) {
        swap(v[start], v[end]);
        start++;end--;
    }
}


int main() {
    
    vector<int> a ={1,2,3,4,5,6};
    
    reverseArray(a, 3);

    for(int i=0;i<a.size();i++) {

        cout<<a[i]<<" ";
    }cout<<endl;

    return 0;
}
