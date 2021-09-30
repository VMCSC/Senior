#include <bits/stdc++.h>
using namespace std;

/*
find the number of simple cycles of the implicit graph, subtract from total # of nodes
let a[i] store the number at index i in the initial order
let nxt[i] store the index of the number i in the desired order
let vis[i] store whether the index has been visited
for each cycle, find the length. the number of swaps needed to reposition the cycle is length-1
since the sum of all lengths is n, we can just subtract 1 from the total each time we find a cycle
*/

const int nax = 1e6 + 5;
int n, a[nax], nxt[nax];
bool vis[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i){
		// O(n)
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i){
		// O(n)
		int a; cin >> a;
		nxt[a] = i;
	}
	int ans = n;
	for (int i = 0; i < n; ++i){
		// O(n)
		if (vis[i]) continue;
		for (int j = i; !vis[j]; j = nxt[a[j]]) vis[j] = true;
		--ans;
	}
	cout << ans << "\n";
	return 0;
}