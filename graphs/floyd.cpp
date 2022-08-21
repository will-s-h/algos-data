//Floyd's Algorithm: O(N) algorithm for functional/successor graphs (where each node has exactly one outgoing edge)
//detects cycles in O(N) time and O(1) memory, not including the graph itself
//the important part is the O(1) memory; a simple DFS could accomplish the O(N) time. 

#include <bits/stdc++.h>
using namespace std;

void floyd(int n, vector<int>& next){
    int a = next[n];
    int b = next[next[n]];
    while(a != b){
        a = next[a];
        b = next[next[b]];
    }

    a = n;
    while(a != b){
        a = next[a];
        b = next[b];
    }

    cout << "first node in cycle: " << a << endl;

    b = next[a];
    int length = 1;
    while(b != a){
        b = next[b];
        length++;
    }

    cout << "length of cycle: " << length << endl;
}

int main(){
    freopen("../input.in", "r", stdin);
    freopen("../output.out", "w", stdout);

    int N; cin >> N;
    vector<int> next(N);

    for(int i = 0; i < N; i++){
        cin >> next[i]; next[i]--;
    }

    //execute Floyd's Algorithm on only the first node:
    floyd(0, next);
}