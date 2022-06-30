#include<iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int k) {

    int s = start;
    int e = end;

    int mid = s + (e-s)/2;

    while(s <= e) {

        if(arr[mid] == k) {

            return mid;

        } else {

            if(arr[mid] > k) {

                e = mid - 1;

            } else {

                s = mid + 1;
            }
        }

        mid = s + (e-s)/2;
    }

    return -1;
}


int findPivotElement(int arr[], int start, int end) {

    int s = start;
    int e = end;
    int mid = s + (e-s)/2;;

    while(s < e) {

        if(arr[mid] > arr[start]) {
            s = mid + 1;
        } else {
            e = mid;
        }

        mid = s + (e - s)/2;
    }

    return mid;
}

int searchRotatedSorted(int arr[], int start, int end, int pivotIndex, int k) {

    int searchIndex = -1;
    if(arr[pivotIndex] <= k && k <= arr[end - 1]) { //search in line 2

        searchIndex = binarySearch(arr, pivotIndex, end, k);

    } else { //search in line 1

        searchIndex = binarySearch(arr, 0, pivotIndex, k);

    }
   
   return searchIndex;
}


int main()
{
    int a[] = {8,10,17,1,3};
    int pivotIndex = findPivotElement(a, 0, 5);
    int index = searchRotatedSorted(a, 0, 5, pivotIndex, 17);

    cout<<"The element is present at index: "<<index<<endl;

    return 0;
}
