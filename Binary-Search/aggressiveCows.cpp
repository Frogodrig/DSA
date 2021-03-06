#include<iostream>
#include<algorithm>
using namespace std;

bool isPossible(int arr[], int n, int k, int mid) {

    int cowCount = 1;
    int lastPos = arr[0];

    for(int i=0;i<n;i++) {
        if(arr[i] - lastPos >= mid) {
            cowCount++;
            if(cowCount == k) {
                return true;
            }
            lastPos = arr[i];
        }
    }
    return false;
}

int aggressiveCows(int arr[], int n, int k) {

    sort(arr, arr+n);

    int start = 0;
    int end = 0;

    int maxi = -1;

    for(int i=0; i<n ;i++) {
        maxi = max(maxi, arr[i]);
    }

    end = maxi; //or end = maxelement - minelement

    int mid = start + (end-start)/2;
    int ans = -1;

    while(start <= end) {

        if(isPossible(arr, n, k, mid)) { //ex: 2 cows not fighting at dist. 4 will also not fight at dist. 5,6,7.....

            ans = mid;
            start = mid + 1; //Because we aspire for the maximum distance. Therefore, going to the right side.

        } else { //ex: Not mandatory for 2 cows to not fight at dist. 4 and also not fight at dist. < 4

            end = mid - 1;

        }

        mid = start + (end-start)/2;
    }

    return ans;
}


int main(){
    
    int a[] = {1,2,3,4,6};
    cout<<aggressiveCows(a, 5, 2)<<endl;
    return 0;
}
