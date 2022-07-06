#include<iostream>
using namespace std;

bool binarySearch(int arr[], int start, int end, int key) {

    if(start > end) {
        return false;
    }

    int mid = start + (end-start)/2;

    if(arr[mid] == key) {
        return true;
    }

    else if(arr[mid] < key) {
        bool rightPart = binarySearch(arr, mid+1, end, key);
        return rightPart;
    } else {
        bool leftPart = binarySearch(arr, start, mid-1, key);
        return leftPart;
    }

}



int main() {
    
    int arr[6] = {2,4,6,10,14,16};
    int size = 6;
    int key = 16;

    bool ans = binarySearch(arr, 0, size, key);
    cout<<ans<<endl;

    return 0;
}
