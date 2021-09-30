#include <bits/stdc++.h>
using namespace std;

/*
let adj[i] store the nodes adjacent to i
let hot[i] store whether the node i is hot
dfs while keeping track of number of consecutive hot nodes traversed upon reaching the current node
*/

const int nax = 1e5 + 5;
int n, m;
vector<int> adj[nax];
bool hot[nax];

int dfs(int u, int p, int hotcnt){
	// O(n)
	if (hot[u]) ++hotcnt;
	else hotcnt = 0;
	if (hotcnt > m) return 0;
	int ret = 0;
	for (int v: adj[u]){
		if (v == p) continue;
		ret += dfs(v,u,hotcnt);
	}
	return ret + 1;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i){
		cin >> hot[i];
	}
	for (int i = 0; i < n-1; ++i){
		int x,y; cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}
	cout << dfs(1,0,0) << "\n";	
	return 0;
}