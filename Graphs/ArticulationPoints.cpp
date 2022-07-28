#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

void dfs(int node, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj, vector<int> &ap, int timer) {

    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0; //to count children of a node

    for(auto neighbour: adj[node]) {
        if(neighbour == parent) {
            continue;
        }

        if(!vis[neighbour]) {
            dfs(neighbour, node, disc, low, vis, adj, ap, timer);
            low[node] = min(low[node], low[neighbour]);

            //check for articulation point
            if(low[neighbour] >= disc[node] and parent != -1) {
                ap[node] = true;
            }
            child++;
        }

        else { //For Back Edge 
            low[node] = min(low[node], disc[neighbour]);
        }
    }

    if(parent == -1 and child > 1) {
        ap[node] = 1;
    }
}


int main() {

    int n = 5;
    int e = 5;

    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));

    //adjacency lsit
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(n);
    vector<int> low(n);
    unordered_map<int, bool> vis;
    vector<int> ap(n, 0);
    int parent = -1;

    for(int i=0; i<n; i++) {
        disc[i] = -1;
        low[i] = -1;
    }

    //dfs
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            dfs(i, parent, disc, low, vis, adj, ap, timer);
        }
    }

    //print articulation points
    cout<<"Articulation points are as follows: "<<endl;
    for(int i=0; i<n; i++) {
        if(ap[i] != 0) {
            cout<<i<<" ";
        }
    } cout<<endl;

    return 0;
}