// 0 1 2 Sort, 3 pointer approach
//low mid and high pointers
//arr[0] to arr[low-1] = Zeros
//arr[high] to arr[n-1] = Twos

//mid == 0 , swap low and mid elements low++, mid++
//mid == 1, mid++
//mid == 2, swap high and mid elements high--

#include<iostream>
#include<vector>
using namespace std;

void dnfSort(vector<int> &v, int n) {

    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid <= high) {

        if(v[mid] == 0) {

            swap(v[mid], v[low]);
            low++;mid++;

        } else if(v[mid] == 1) {

            mid++;

        } else {

            swap(v[mid], v[high]); 
            high--;

        }
    }
}

int main() {

    vector<int> a = {0,1,1,2,2,0,1,1,2,0,0,0,1,2,2,1};
    dnfSort(a, 16);

    for(int i=0;i<16;i++) {
        cout<<a[i]<<" ";
    } cout<<endl;

    return 0;
}
