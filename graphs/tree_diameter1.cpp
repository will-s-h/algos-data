//finds diameter of tree in O(N), using two DFS's. Algorithm:
// 1) choose arbitrary node a
// 2) find farthest node b from a
// 3) find farthest node c from b; this is the diameter
// algorithm explanation found here: https://usaco.guide/CPH.pdf#page=145

#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = (int) 2e5+1;
vector<int> adj[MAXN];
 
int depth;
int farthest_node;
int farthest_depth;
 
bool visited[MAXN] = {};
 
void setup(int start){
	for(int i = 0; i < MAXN; i++) visited[i] = false;
	visited[start] = true;
	depth = 0;
	farthest_node = start;
	farthest_depth = 0;
}
 
void dfs(int node){
	for(int other : adj[node]){
		if(!visited[other]){
			visited[other] = true;
			depth++;
			if(depth > farthest_depth){
				farthest_depth = depth;
				farthest_node = other;
			}
			dfs(other);
			depth--;
		}
	}
}
 
int main() {
	int N; cin >> N;
	for(int i = 0; i < N-1; i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
 
	setup(1);
	dfs(1);
	int new_start = farthest_node;
	setup(new_start);
	dfs(new_start);
	cout << farthest_depth;
}
