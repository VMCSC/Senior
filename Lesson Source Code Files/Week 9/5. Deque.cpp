#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,a[3005],dp[3005][3005];

ll solve(int l, int r){
	//base case
	if (l == r) return a[l];
	ll& cur = dp[l][r]; //creating a reference
	if (cur == -1){
		//have not visited this state
		cur = max(a[l] - solve(l+1,r), a[r] - solve(l,r-1));
	}
	return cur;
}

int32_t main(){
	cin >> n;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	memset(dp, -1, sizeof dp);
	cout << solve(1,n) << "\n";
	return 0;
}