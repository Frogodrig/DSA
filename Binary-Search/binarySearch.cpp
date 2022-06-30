#include<iostream>
using namespace std;

//T.C = O(logN)
int binarySearch(int arr[], int n, int k) {
    
    int start = 0;
    int end = n;
    int mid = start + (end - start)/2;
    while(start <= end) {

        if(arr[mid] == k) {
            return mid;
        } else {
            if(arr[mid] > k) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        mid = start + (end - start)/2;
    }

    return -1;
}

int main()
{
    int a[] = {1,2,3,4,8,9,10};

    int index = binarySearch(a, 7, 8);

    cout<<" Number 8 found at index: "<<index;

    return 0;
}
