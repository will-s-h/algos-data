//binary jumping / binary lifting
//finding the kth successor in O(log N) time, with O(N log N) precomputation time
//see https://usaco.guide/plat/binary-jump?lang=cpp for details

#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+2;
const int MS = 18; //ceil(log_2(MN));
int up[MS][MN] = {}; //up[i][j] indicates what happens when you jump 2^i times from node j
int N, Q;

void prepare(){ //O(N log N)
	for(int i = 1; i < MS; i++){
		for(int n = 1; n <= N; n++){
			//jumping 2^i times is equivalent to jumping 2^(i-1) times twice
			up[i][n] = up[i-1][up[i-1][n]];
		}
	}
}

int query(int n, int k){ //O(log N)
	for(int i = 0; i < MS; i++){
		if(k & (1 << i)) n = up[i][n];
	}
	return n ?: -1; //if n > 0 return n, else return -1
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> Q;

	for(int i = 2; i <= N; i++){
		cin >> up[0][i];
	}

	prepare();

	for(int q = 0; q < Q; q++){
		int n, k; cin >> n >> k;
		cout << query(n, k) << "\n";
	}
}
