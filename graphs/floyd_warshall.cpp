//Floyd-Warshall Algorithm: finds shortest path between all nodes in O(N^3)
//(negative edge weights allowed, no negative cycles)

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> d; //lowest distance between two nodes
const int INF = 1e9;

void FloydWarshall(){
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(d[i][k] < INF && d[k][j] < INF) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main(){
    cin >> N >> M;
    d = vector<vector<int>>(N, vector<int>(N, INF));
    for(int i = 0; i < M; i++){
        int a, b, w; cin >> a >> b >> w; a--; b--; //assume 1-indexed, convert to 0-indexed
        d[a][b] = w; //assume directed graph
    }

    FloydWarshall();
}