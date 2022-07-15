#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>
using namespace std;

string firstNonRepeating(string A) {
    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";

    for(int i=0; i<A.length(); i++) {
        char ch = A[i];

        //increment count
        count[ch]++;

        //push into Q
        q.push(ch);

        //check for repeating and pop
        while(!q.empty()) {
            if(count[q.front()] > 1) { //repeating character
                q.pop();

            } else { //non-repeating character
                ans.push_back(q.front());
                break;
            }
        }

        //Either break encountered or Q has become empty
        if(q.empty()) {
            ans.push_back('#');
        }
    }

    return ans;
}

