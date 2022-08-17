// Depth First Search (DFS) using recursion; O(N+M)
// basic example, labelling each node by a number which indicates which connected component they are a part of

#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5;
int N, M;
vector<int> edges[maxN] = {};
int group[maxN] = {};

void dfs(int n, int g){
	group[n] = g;
	for(int next : edges[n]){
		if(group[next] == 0) dfs(next, g);
	}
}

int main(){
	cin >> N >> M; //input number of nodes, number of edges
	for(int i = 0; i < M; i++){ //set edges, 0-indexed
		int a, b; cin >> a >> b; a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	int g = 1;
	for(int i = 0; i < N; i++){
		if(group[i] == 0) {
			dfs(i, g);
			g++;
		}
	}

	for(int i = 0; i < N; i++){
		cout << group[i] << " ";
	}
}
