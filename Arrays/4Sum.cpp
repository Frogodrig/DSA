#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> foursome(vector<int> &v, int sum) {

    vector<vector<int>> ans;

    int n = v.size();
    sort(v.begin(), v.end());

    for(int i=0;i<n;i++) { //number 1

        for(int j=i+1;j<n;j++) { //number 2

            int nextSum = sum - v[j] - v[i];

            int front = j + 1;
            int back = n - 1;

            while(front < back) {
                int sumOf2 = v[front] + v[back];

                if(sumOf2 < nextSum) {
                    front++;
                } else if(sumOf2 > nextSum) {
                    back--;
                } else {
                    vector<int> quad;
                    quad[0] = v[i];
                    quad[1] = v[j];
                    quad[2] = v[front];
                    quad[3] = v[back];
                    ans.push_back(quad);

                    //Removing duplicates of number 3 and 4
                    while(front < back && v[front] == quad[1]) front++;
                    while(front < back && v[back] == quad[2]) back--;
                }
            }

            //Removing duplicates of number 2
            while(j+1 < n && v[j+1] == v[j]) j++;
        }

        //Removing duplicates of number 1
        while(i+1 < n && v[i+1] == v[i]) i++;
    }

    return ans;
}


int main() {
    
    vector<int> a = {0,1,4,6,3,3,7,8,10,2,6,6,2,2,7,7,7,4,4,3,3,1,1,0,0};

    vector<vector<int>> ans = foursome(a, 8);

    for(int i=0;i<ans.size();i++) {
        for(int j=0;j<4; j++) {
            cout<<ans[i][j]<<" ";
        } cout<<endl;
    }

    return 0;
}
