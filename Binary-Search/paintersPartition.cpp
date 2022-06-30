#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid) {

    int painters = 1;
    int boards = 0;

    for(int i=0; i<n; i++) {

        if(boards + arr[i] <= mid) {
            boards += arr[i];
        } else {
            painters++;
            if(painters > m || arr[i] > mid) {
                return false;
            } else {
                boards = arr[i];
            }
        }
    }

    return true;
}

int paintersPartition(int arr[], int n, int m) {

    int start = 0; //Can also take the maximum board length as a starting point
    int end = 0;

    for(int i=0;i<n;i++) {
        end += arr[i];
    }

    int mid = start + (end-start)/2;
    int ans = -1;

    while(start <= end) {

        if(isPossible(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1; //Because we aspire for a minimum solution
        } else { //Solution is not feasible

            start = mid + 1;
        }
        mid = start + (end-start)/2;
    }

    return ans;

}

int main() {
    
    int a[] = {5,5,5,5};

    cout<<"Partition at : "<<paintersPartition(a, 4, 2)<<" boards."<<endl;

    return 0;
}
