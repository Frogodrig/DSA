#include<iostream>
using namespace std;

int leftMostOccurence(int arr[], int n, int k) {

    int start = 0;
    int end = n;
    int mid = start + (end - start)/2;
    int ans = -1;

    while(start <= end) {

        if(arr[mid] == k) {
            ans = mid;
            end = mid - 1;
        } else {
            if(arr[mid] > k) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        mid = start + (end - start)/2;
    }

    return ans;
}

int rightMostOccurence(int arr[], int n, int k) {

    int start = 0;
    int end = n;
    int mid = start + (end - start)/2;
    int ans = -1;

    while(start <= end) {

        if(arr[mid] == k) {
            ans = mid;
            start = mid + 1;
        } else {
            if(arr[mid] > k) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        mid = start + (end - start)/2;
    }

    return ans;
}

int main()
{
    
    int a[] = {0,1,2,2,3,3,3,3,4,4,4,4,4,5};

    int firstOccurence = leftMostOccurence(a, 14, 4);
    int lastOccurence = rightMostOccurence(a, 14, 4);

    int totalOccurences = lastOccurence - firstOccurence + 1;
    cout<<"Total occurences of 4 is: "<<totalOccurences;

    return 0;
}
