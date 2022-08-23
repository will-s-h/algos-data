// Shortest Path Faster Algorithm (SPFA)
// shortest path from one node to all other nodes
// variant of Bellman Ford with same worst-case runtime O(NM) but faster average runtime (some claim averages O(m))

// Uses:
// 1) works in the case of negative edge weights, unlike Dijsktra's
// 2) detect negative cycles by running one extra round; if last round reduces any distances, then a negative cycle exists
// 3) faster (on average) than Bellman Ford
// Verification: https://open.kattis.com/problems/shortestpath3

#include <bits/stdc++.h>
using namespace std;

int N, M, Q, S; //number of nodes, number of edges, number of queries, starting node
vector<int> dist;
vector<vector<pair<int,int>>> adjList;
const int INF = 1e9;

void DFS(int n){ //only used to mark distances which can be arbitrarily small using a neg cycle
    dist[n] = -INF;
    for(pair<int,int> p : adjList[n]){
        if(dist[p.first] != -INF) DFS(p.first);
    }
}

void SPFA(int x){ //the actual Bellman Ford Algorithm
    //basic Bellman Ford
    dist = vector<int>(N, INF);
    dist[x] = 0;

    queue<int> q; //queue of nodes
    vector<bool> inqueue = vector<bool>(N); //if q
    vector<int> cnt = vector<int>(N); //number of times a node has been relaxed
    q.push(x);

    while(!q.empty()){
        int n = q.front(); q.pop();
        inqueue[n] = false;

        for(pair<int,int> p : adjList[n]){
            int next = p.first; int w = p.second;
            if(dist[next] != -INF && !inqueue[n] && dist[next] > dist[n] + w){
                if(cnt[next] == N) {DFS(next); break;}
                dist[next] = dist[n] + w;
                q.push(next);
                inqueue[next] = true;
                cnt[next]++;
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    while(true){
        cin >> N >> M >> Q >> S;
        if(!N && !M && !Q && !S) return 0;
        
        adjList = vector<vector<pair<int,int>>>(N);
        for(int i = 0; i < M; i++){
            int a, b, w; cin >> a >> b >> w;
            adjList[a].push_back({b,w});
        }
        
        SPFA(S);
        
        for(int i = 0; i < Q; i++){
            int q; cin >> q;
            if(dist[q] == INF) cout << "Impossible\n";
            else if(dist[q] == -INF) cout << "-Infinity\n";
            else cout << dist[q] << "\n";
        }

        cout << endl;
    }
}