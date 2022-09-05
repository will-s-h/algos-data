//Kruskal's Algorithm
//Finds Minimum Spanning Tree in O(E log E), using DSU
//verification: https://cses.fi/problemset/task/1675/

#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

struct edge{
    int a, b, w;
};

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    int N, M; cin >> N >> M;
    vector<edge> edges;
    for(int i = 0; i < M; i++){
        int a, b, w; cin >> a >> b >> w; a--; b--;
        edges.push_back({a, b, w});
    }

    sort(edges.begin(), edges.end(), [](edge &a, edge &b){
        return a.w < b.w;
    });

    vector<edge> MST;
    long long cost = 0;
    DSU dsu(N);

    for(int i = 0; i < M; i++){
        if(!dsu.same_set(edges[i].a, edges[i].b)){
            dsu.unite(edges[i].a, edges[i].b);
            cost += edges[i].w;
            MST.push_back(edges[i]);
            if(MST.size() == N-1) break;
        }
    }

    if(MST.size() == N-1) cout << cost;
    else cout << "IMPOSSIBLE";
}