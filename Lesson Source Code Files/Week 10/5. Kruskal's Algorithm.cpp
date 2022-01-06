#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int n,k,parent[maxn],size[maxn]; //parent[i] stores the node above it in the set; if the node is the representative of the set, the node will have parent that is itself
vector<pair<int,pair<int,int>>> edges;

int find(int node){
	if (node == parent[node]){
		//this node is the representative
		return node;
	}
	else {
		return parent[node] = find(parent[node]); //redefine parent of node to be the representative
	}
}

bool merge(int a, int b){
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) return false;
	if (size[pa] > size[pb]) swap(pa,pb); //make sure pa is the smaller set
	parent[pa] = pb;
	size[pb] += size[pa];
	return true;
}

int32_t main(){
	cin >> n >> k;
	for (int i = 1; i < n; ++i){
		int w; cin >> w;
		edges.push_back({w,{i,i+1}});
		if (i + k <= n){
			edges.push_back({0,{i,i+k}});
		}
	}
	for (int i = 1; i <= n; ++i){
		parent[i] = i; //make i the representative of its set
		size[i] = 1;
	}
	sort(edges.begin(),edges.end());
	int ans = 0;
	for (auto e: edges){
		int a,b,c;
		c = e.first;
		tie(a,b) = e.second;
		if (merge(a,b)){
			ans += c;
		}
	}
	cout << ans << "\n";
	return 0;
}