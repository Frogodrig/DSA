//No of ways to climb stairs
//2 ways to climb, either by taking 1 or 2 steps at a time.

//f(n) = f(n-1) + f(n-2)

#include<iostream>
using namespace std;

int countDistinctWayToClimbStair(int stairs) {

    if(stairs < 0) {
        return 0;
    }

    if(stairs == 0) {
        return 1;
    }

    int ans = countDistinctWayToClimbStair(stairs-1) + countDistinctWayToClimbStair(stairs-2);


    return ans;
}


int main() {
    
    return 0;
}
