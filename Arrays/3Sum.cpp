#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//a + b + c = sum
//b + c = sum - a

vector<vector<int>> threesome(vector<int> &v, int sum) {

    sort(v.begin(), v.end());

    vector<vector<int>> ans;

    for(int i=0;i<v.size()-2;i++) { //For a

        if(i == 0 || (i > 0 && v[i] != v[i-1])) {

            //Two pointer approach
            int lo = i+1, hi = v.size()-1, sumOf2 = sum - v[i];

            while(lo < hi) {

                if(v[lo] + v[hi] == sumOf2) {

                    vector<int> temp;
                    temp.push_back(v[i]);
                    temp.push_back(v[lo]);
                    temp.push_back(v[hi]);
                    ans.push_back(temp);

                    while(lo<hi && v[lo] == v[lo+1]) lo++; //removing duplicates from front
                    while(lo<hi && v[hi] == v[hi-1]) hi--; //removing duplicates from back

                    lo++; hi--;

                } else if(v[lo] + v[hi] < sumOf2) {
                    lo++;
                } else {
                    hi++;
                }

            }
        }
    }

    return ans;
}

int main() {
    
    vector<int> a = {0,1,4,6,3,3,7,8,10,2,6,6,2,2,7,7,7,4,4,3,3,1,1,0,0};

    vector<vector<int>> ans = threesome(a, 7);

    for(int i=0;i<ans.size();i++) {
        for(int j=0;j<3; j++) {
            cout<<ans[i][j]<<" ";
        } cout<<endl;
    }

    return 0;
}
