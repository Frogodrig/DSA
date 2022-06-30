#include<iostream>
using namespace std;

int findPivotElement(int arr[], int start, int end) {

    int s = start;
    int e = end;

    int mid = s + (e-s)/2;

    while(s < e) {

        if(arr[mid] >= arr[start]) {
            s = mid + 1;
        } else { //arr[mid] < arr[start] or arr[mid] can be the pivot element
            e = mid;
        }

        mid = s + (e-s)/2;
    }

    return arr[mid];
}


int main() {
    
    int a[] = {8, 10, 17, 1 ,3};

    int pivotElement = findPivotElement(a, 0, 5);

    cout<<"Pivot element is : "<<pivotElement;

    return 0;
}
