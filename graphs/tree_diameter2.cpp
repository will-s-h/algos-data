//tree diameter algorithm
// uses DP, O(N)
// 1) root the tree arbitrarily
// 2) calculate for each node maximum length x to any leaf (toLeaf(x))
// 3) calculate for each node maximum length of path whose highest point is x (maxLength(x) = max(toLeaf(a) + toLeaf(b)))
// algorithm explanations found here: https://usaco.guide/CPH.pdf#page=145

#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5;
vector<int> edges[MN] = {};
int toLeaf[MN] = {};
int maxLength[MN] = {};
int totalMax = 0;

void dfs(int n){
	maxLength[n] = 1; //toLeaf[n] = 0 is unnecessary
	int toLeaf2nd = 0;
	for(int next : edges[n]){
		if(maxLength[next] == 0){
			dfs(next); //not visited yet
			if(toLeaf[next] + 1 >= toLeaf2nd){ //update top 2 toLeafs
				if(toLeaf[next] + 1 >= toLeaf[n]){
					toLeaf2nd = toLeaf[n];
					toLeaf[n] = toLeaf[next] + 1;
				} else {
					toLeaf2nd = toLeaf[next] + 1;
				}
				maxLength[n] = toLeaf[n] + toLeaf2nd; //update maxLength
				totalMax = max(totalMax, maxLength[n]);
			}
		}
	}
}

int main() {
	int N; cin >> N;
	for(int i = 0; i < N-1; i++){
		int a, b; cin >> a >> b; a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	dfs(0);
	cout << totalMax;
}