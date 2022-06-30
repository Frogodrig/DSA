#include<iostream>
using namespace std;

bool isPossibleSolution(int arr[], int n, int m, int mid) {

    int studentCount = 1;
    int pagesAllocated = 0;

    for(int i = 0; i<n; i++) {
        if(pagesAllocated + arr[i] <= mid) {
            pagesAllocated += arr[i];
        } else {
            studentCount++;
            if(studentCount > m || arr[i] > mid) {
                return false;
            } else {
                pagesAllocated = arr[i];
            }
        }
    }

    return true;
}

int allocateBooks(int arr[], int n, int m) {

    int s = 0;
    int sum = 0;

    for(int i=0; i<n; i++) {
        sum += arr[i];
    }

    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;

    while(s <= e) {

        if(isPossibleSolution(arr, n, m, mid)) {
            ans = mid;
            e = mid - 1; // Because we aspire for a minimum solution
        } else { //Solution is not feasible
            s = mid + 1;
        }

        mid = s + (e-s)/2;
    }

    return ans;
}

int main(){
    
    int a[] = {10, 20, 30, 40};

    cout<<"Partition at : "<<allocateBooks(a, 4, 2)<<" pages";

    return 0;
}


