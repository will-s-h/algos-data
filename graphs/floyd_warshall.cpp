// Floyd-Warshall Algorithm: finds shortest path between all nodes in O(N^3)
// (negative edge weights allowed, no negative cycles)
// Verification: https://open.kattis.com/problems/allpairspath

#include <bits/stdc++.h>
using namespace std;

int N, M, Q;
vector<vector<int>> d; //lowest distance between two nodes
const int INF = 1e9;

void FloydWarshall(){
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(d[i][k] < INF && d[k][j] < INF) {
                    if(d[k][k] < 0) d[i][j] = -INF; //k is part of a negative cycle
                    else if(d[i][k] == -INF || d[k][j] == -INF) d[i][j] = -INF; //neg cycle
                    else d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    while(cin >> N >> M >> Q){
        d = vector<vector<int>>(N, vector<int>(N, INF));
        for(int i = 0; i < N; i++) d[i][i] = 0; //set distance to oneself to 0
        for(int i = 0; i < M; i++){
            int a, b, w; cin >> a >> b >> w;
            d[a][b] = min(w, d[a][b]); //directed edge, allow distance to onself to be 0
        }
        FloydWarshall();
        for(int i = 0; i < Q; i++){
            int a, b; cin >> a >> b;
            if(d[a][b] == INF) cout << "Impossible\n";
            else if(d[a][b] == -INF) cout << "-Infinity\n";
            else cout << d[a][b] << "\n";
        }
    }
}