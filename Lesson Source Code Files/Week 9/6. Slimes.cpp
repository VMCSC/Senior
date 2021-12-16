#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll n,a[401],dp[401][401];

ll solve(int l, int r){
	//base case
	if (l == r) return 0;
	ll& cur = dp[l][r];
	if (cur == -1){
		//process this state for the first time
		cur = LLONG_MAX;
		ll s = 0;
		for (int k = l; k < r; ++k){
			cur = min(cur, solve(l,k) + solve(k+1,r));
			s += a[k];
		}
		cur += s + a[r];
	}
	return cur;
}

int32_t main(){
	int n; cin >> n;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	memset(dp, -1, sizeof dp);
	cout << solve(1, n) << "\n";
	return 0;
}