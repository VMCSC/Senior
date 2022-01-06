#include <bits/stdc++.h>
using namespace std;

/*
Input
8 8
1 3
2 5
2 6
3 4
3 5
5 6
8 6
4 7

Output
0
1061109567
1
2
2
3
3
1061109567
*/

int n,m;
int dist[10]; //dist[i] stores the distance from node 1 to node i
vector<int> adj[10];

int32_t main(){
	cin >> n >> m;
	for (int i = 0; i < m; ++i){
		int a,b; cin >> a >> b;
		adj[a].push_back(b); //b is a neighbor of a
	}
	memset(dist, 0x3f, sizeof dist); //filling the array with large integers
	dist[1] = 0;
	queue<int> q;
	q.push(1); //push node 1 into the queue
	while (!q.empty()){
		int node = q.front(); q.pop();
		for (int v: adj[node]){
			//for every neighbor v
			int newcost = dist[node] + 1;
			if (newcost < dist[v]){
				//the distance is better than the current distance to v
				dist[v] = newcost; //update dist[v]
				q.push(v); //push neighbor into queue
			}
		}
	}
	for (int i = 1; i <= n; ++i){
		cout << dist[i] << "\n";
	}
	return 0;
}