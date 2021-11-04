#include <bits/stdc++.h>
using namespace std;

/*
https://dmoj.ca/problem/grind


what do difference arrays do?
- perform range updates in O(1)

how does it perform range updates?
- performs an operation (such as addition) to the starting point of the range, then performs the inverse operation (e.g. inverse of addition is subtraction) to the exclusive ending point of the range
- when we calculate the prefix sum array of the array in the end, we are left with the updated array


- easy to implement
- can't access the elements in between updates in constant time
*/

const int nax = 1e7 + 5;
long long n,diff[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i){
		int s,f; cin >> s >> f;
		++diff[s];
		--diff[f];
	}
	for (int i = 1; i <= 1e7; ++i){
		diff[i] += diff[i-1];
	}
	long long ans = 0;
	for (int i = 1; i <= 1e7; ++i){
		ans = max(ans, diff[i]);
	}
	cout << ans << "\n";
	return 0;
}