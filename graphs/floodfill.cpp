// Floodfill Example
// uses recursion, counts size of each connected component, O(NM)
// source: https://usaco.guide/silver/flood-fill?lang=cpp, with minor changes 

#include <bits/stdc++.h>
using namespace std;

const int MN = 1000;

int grid[MN][MN];  // the grid itself
int row_num;
int col_num;
bool visited[MN][MN];  // keeps track of which nodes have been visited
int curr_size = 0;  // reset to 0 each time we start a new component

void floodfill(int r, int c, int color){
	if (
		(r < 0 || r >= row_num || c < 0 || c >= col_num)  // if out of bounds
		|| grid[r][c] != color  // wrong color
		|| visited[r][c]  // already visited this square
	) return;

	visited[r][c] = true; // mark current square as visited
	curr_size++; // increment the size for each square we visit

	// recursively call flood fill for neighboring squares
	floodfill(r, c + 1, color);
	floodfill(r, c - 1, color);
	floodfill(r - 1, c, color);
	floodfill(r + 1, c, color);
}

int main() {
	//input grid and parameters
	cin >> row_num >> col_num;
	for(int r = 0; r < row_num; r++){
		for(int c = 0; c < col_num; c++){
			cin >> grid[r][c];
		}
	}
	
	for (int i = 0; i < row_num; i++) {
		for (int j = 0; j < col_num; j++) {
			if (!visited[i][j]) {
				curr_size = 0;
				floodfill(i, j, grid[i][j]);
        		cout << curr_size << " ";
			}
		}
	}
	return 0;
}
