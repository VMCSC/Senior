#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int n,m;
vector<pair<int,int>> adj[maxn];
int dist[maxn];

int32_t main(){
	cin >> n >> m;
	for (int i = 0; i < m; ++i){
		int a,b,c;
		cin >> a >> b >> c;
		adj[a].emplace_back(b,c);
		adj[b].emplace_back(a,c);
	}
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,1}); //{cost, node}
	while (!pq.empty()){
		int cost,node;
		tie(cost,node) = pq.top(); pq.pop();
		if (dist[node] != cost) continue;
		for (auto t: adj[node]){
			int newcost = t.second + cost;
			if (newcost < dist[t.first]){
				dist[t.first] = newcost;
				pq.push({newcost,t.first});
			}
		}
	}
	for (int i = 1; i <= n; ++i){
		cout << (dist[i] == dist[0] ? -1 : dist[i]) << "\n";
	}
	return 0;
}