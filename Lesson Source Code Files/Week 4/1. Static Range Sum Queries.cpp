#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
https://cses.fi/problemset/task/1646/
*/

const int nax = 2e5 + 5;
ll n,q,arr[nax],psa[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i){
		cin >> arr[i];
	}
	for (int i = 1; i <= n; ++i){
		psa[i] = psa[i-1] + arr[i];
	}
	//O(N) + O(N) + O(Q)
	//O(N+Q)
	//2*10^5 + 2*10^5 = 4*10^5 < 10^8
	while (q--){
		//O(Q)
		int a,b; cin >> a >> b;
		cout << psa[b] - psa[a-1] << "\n"; //O(1)
	}
	
	return 0;
}