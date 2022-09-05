//Prim's Algorithm
//Finds Minimum Spanning Tree in O(E log E)
//verification: https://cses.fi/problemset/task/1675/

#include <bits/stdc++.h>
using namespace std;

struct edge{
    int a, b, w;
};

int main(){
    //freopen("../.vscode/input.in", "r", stdin);
    //freopen("../.vscode/output.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);

    int N, M; cin >> N >> M;
    vector<vector<edge>> adjList(N);

    for(int i = 0; i < M; i++){
        int a, b, w; cin >> a >> b >> w; a--; b--;
        adjList[a].push_back({a,b,w});
        adjList[b].push_back({b,a,w});
    }

    vector<edge> MST;
    vector<bool> seen(N); seen[0] = true;
    auto cmp = [](edge &a, edge &b){return a.w > b.w;};
    priority_queue<edge, vector<edge>, decltype(cmp)> pq(cmp); 

    for(edge &e : adjList[0]){
        pq.push(e);
    }

    long long cost = 0;

    while(!pq.empty() && MST.size() < N-1){
        edge e = pq.top(); pq.pop();
        if(seen[e.b]) continue;

        seen[e.b] = true;
        MST.push_back(e);
        cost += e.w;

        for(edge &next : adjList[e.b]){
            if(!seen[next.b]) pq.push(next);
        }
    }

    if(MST.size() == N-1) cout << cost;
    else cout << "IMPOSSIBLE";
}