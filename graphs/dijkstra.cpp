// Dijkstra's Algorithm, O(N + M log N) implementation
// Algorithm to determine shortest path from one node to all other nodes
// use this for dense graphs where M (number of edges) ~ N^2 (number of nodes)
// WARNING: no negative edges allowed
// verification: https://open.kattis.com/problems/shortestpath1

#include <bits/stdc++.h>
using namespace std;

int N, M, Q, S; //nodes, edges, queries, start node
vector<vector<pair<int,int>>> adjList;
vector<int> dist;
const int INF = 1e9;

void Dijkstra(int start){
    dist = vector<int>(N, INF);
    vector<bool> seen = vector<bool>(N);
    dist[start] = 0;
    priority_queue<pair<int,int>> q; q.push({-0, start}); //{-dist, start}
    while(!q.empty()){
        int n = q.top().second; q.pop();
        if(seen[n]) continue;
        seen[n] = true;
        
        for(pair<int,int> e : adjList[n]){
            int b = e.first; int w = e.second;
            if(dist[n] + w < dist[b]){
                dist[b] = dist[n] + w;
                q.push({-dist[b], b});
            }
        }
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    while(cin >> N >> M >> Q >> S){
        if(!N && !M && !Q && !S) break;
        adjList = vector<vector<pair<int,int>>>(N);
        for(int i = 0; i < M; i++){
            int a, b, w; cin >> a >> b >> w;
            adjList[a].push_back({b,w});
        }
        
        Dijkstra(S);
        
        for(int i = 0; i < Q; i++){
            int x; cin >> x;
            if(dist[x] == INF) cout << "Impossible\n";
            else cout << dist[x] << "\n";
        }
    }
}
