//a^b = (a^(b/2))^2 if b is even
//a^b = (a^(b/2))^2 * a if b is odd


#include<iostream>
using namespace std;

int fastExponentiation(int x, int n) {

    int res = 1;

    while(n>0) {

        if(n&1) { //odd
            res = res * x;
        }

        x = x*x;
        n = n>>1; //right shifting a bit = dividing by 2
    }

    return res;
}


int main() {
    
    return 0;
}
