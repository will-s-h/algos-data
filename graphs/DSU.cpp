// Disjoint Set Union (DSU) or Union Find
// a data structure to test whether two nodes are connected, which is updated in O(log* N) time and checked in O(log* N) time
// see https://stackoverflow.com/questions/2387656/what-is-olog-n for an explanation of O(log* N)
// code for the structure comes from https://usaco.guide/gold/dsu?lang=cpp

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
