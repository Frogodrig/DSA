#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;

//If the question demands the answer in a sorted order we can always use set (s.insert(u))

void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> &edges) {

    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node) {

    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();

        //store frontNode in answer
        ans.push_back(frontNode);

        //traverse all neighbours of frontNode
        for(auto i: adjList[frontNode]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}


vector<int> BFS(int vertex, vector<pair<int, int>> edges) {

    unordered_map<int, list<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    //traverse all components: for disconnected graphs
    for(int i=0; i<vertex; i++) {
        if(!visited[i]) {
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}

