// Example of Bellman-Ford
// shortest path from one node to all other nodes, in O(NM) (relatively slow)

// Uses:
// 1) works in the case of negative edge weights, unlike Dijsktra's
// 2) detect negative cycles by running one extra round; if last round reduces any distances, then a negative cycle exists
// Verification: https://open.kattis.com/problems/shortestpath3

#include <bits/stdc++.h>
using namespace std;

struct edge {int a, b, w;};

int N, M, Q, S; //number of nodes, number of edges, number of queries, starting node
vector<int> dist;
vector<edge> edges;
vector<vector<int>> adjList;
const int INF = 1e9;

void DFS(int n){ //only used to mark distances which can be arbitrarily small using a neg cycle
    dist[n] = -INF;
    for(int next : adjList[n]){
        if(dist[next] != -INF) DFS(next);
    }
}

void BellmanFord(int x){ //the actual Bellman Ford Algorithm
    //basic Bellman Ford
    dist = vector<int>(N, INF);
    dist[x] = 0;
    for(int i = 1; i <= N-1; i++){
        for(edge e : edges){
            if(dist[e.a] < INF) dist[e.b] = min(dist[e.b], dist[e.a] + e.w);
        }
    }
    
    //one extra iteration here to detect negative cycles
    for(edge e : edges){
        //if updating distances again would result in a lower distance, means neg cycle
        if(dist[e.a] < INF && dist[e.a] + e.w < dist[e.b]){
            DFS(e.b); //set all nodes reachable from b to a distance of -INF
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    while(true){
        cin >> N >> M >> Q >> S;
        if(!N && !M && !Q && !S) return 0;
        
        edges = vector<edge>();
        adjList = vector<vector<int>>(N);
        for(int i = 0; i < M; i++){
            int a, b, w; cin >> a >> b >> w;
            edges.push_back({a,b,w});
            adjList[a].push_back(b);
        }
        
        BellmanFord(S);
        
        for(int i = 0; i < Q; i++){
            int q; cin >> q;
            if(dist[q] == INF) cout << "Impossible\n";
            else if(dist[q] == -INF) cout << "-Infinity\n";
            else cout << dist[q] << "\n";
        }

        cout << endl;
    }
}