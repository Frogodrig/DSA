//In a given array of n integers there are n-1 uniquely occuring integers but 1 integer occurs twice. Find that duplicate integer.
//Example: 1,2,2,3,4,5  => ans = 2
#include<iostream>
using namespace std;

int findDuplicate(int arr[], int n) {

    int ans = 0;

    //XORing all array elements.
    for(int i=0;i<n;i++) {
        ans = ans ^ arr[i];
    }

    //XORing the elements again with themselves.
    for(int i=1;i<n;i++) {
        ans = ans ^ i;
    }

    return ans;
}

int main() {
    
    int a[] = {1,2,2,3,4,5};
    cout<<findDuplicate(a, 6)<<endl;
    return 0;
}
