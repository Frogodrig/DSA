//LeetCode 443.
//String Compression
//https://leetcode.com/problems/string-compression/


#include<iostream>
#include<vector>
#include<string>
using namespace std;

int compress(vector<char> &chars) {

    int i=0;
    int ansIndex = 0;
    int n = chars.size();

    while(i < n) {

        int j = i+1;

        while(j<n && chars[i] == chars[j]) {

            j++;
        }

        /*coming out of this loop signifies 
          that either the vector has been traversed
          or a different character has been encountered*/

        //old character stored and ansIndex incremented
        chars[ansIndex++] = chars[i];

        int count = j-i;

        if(count > 1) {
            //converting count into single digits and saving in the answer
            string cnt = to_string(count);
            for(char ch: cnt) {
                chars[ansIndex++] = ch;
            }
        }

        i = j;
    }

    return ansIndex;
}


int main() {
    
    return 0;
}

