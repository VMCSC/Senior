#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int n,m,k,colour[maxn]; //colour[i] stores the colour of node i
vector<int> adj[maxn];
int col = 0; //current colour

void dfs(int u){
	colour[u] = col;
	for (int v: adj[u]){
		//for every v that is a neighbor
		if (colour[v] == 0){
			dfs(v);
		}
	}
}

int32_t main(){
	cin >> n >> m >> k;
	string r; cin >> r;
	for (int i = 0; i < m; ++i){
		int a,b; cin >> a >> b;
		if (r[a-1] == r[b-1]){
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
	}
	for (int i = 1; i <= n; ++i){
		if (colour[i] == 0){
			++col;
			dfs(i);
		}
	}
	int ans = 0;
	while (k--){
		int x,y; cin >> x >> y;
		ans += (colour[x] == colour[y]);
	}
	cout << ans << "\n";
	return 0;
}