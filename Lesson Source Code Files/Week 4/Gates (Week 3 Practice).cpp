#include <bits/stdc++.h>
using namespace std;

/*
https://dmoj.ca/problem/ccc15s3

given a set of available gates, find the highest one that can be used to dock the plane

maintain an ordered set of available gates
find the highest element in the set that is <= g_i
lower_bound -> element >= g_i
upper_bound -> element > g_i

element <= g_i
insert negative values and use lower_bound
-4 -3 -2 -1
*/

const int nax = 1e0 + 5;
int g,p;
set<int> gates;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> g >> p;
	for (int i = 1; i <= g; ++i) gates.insert(-i);
	int ans = 0;
	while (p--){
		int gi; cin >> gi;
		auto it = gates.lower_bound(-gi);
		if (it == gates.end()){
			break;
		}
		else {
			++ans;
			gates.erase(it);
		}
	}
	cout << ans << "\n";	
	return 0;
}