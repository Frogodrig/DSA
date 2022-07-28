#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {//own comparator to sort on the basis of weights
    return a[2] < b[2];
}

//this function will intialize the parents of the nodes as themselves and their ranks as 0
void makeSet(vector<int> &parent, vector<int> &rank, int n) {

    for(int i=0; i<n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node) {

    if(parent[node] == node) {
        return node;
    }

    return parent[node] = findParent(parent, parent[node]); //path compression
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v]) {
        parent[u] = v;

    }
    else if(rank[v] < rank[u]) {
        parent[v] = u;

    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n) {

    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    int minWeight = 0;

    for(int i=0; i<edges.size(); i++) {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        if(u != v) {
            minWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }

    return minWeight;
}