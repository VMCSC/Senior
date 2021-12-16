#include <bits/stdc++.h>
using namespace std;

/*
dp[i] stores the the minimum number of coins to make i cents
transition dp[i+j] = min(dp[i+j],dp[i] + 1) for the n values j
dp[0] = 0
*/

int32_t main(){
	int x,n; cin >> x >> n;
	vector<int> dp(x+1,100000000);
	vector<int> coins;
	for (int i = 0; i < n; ++i){
		int a; cin >> a;
		coins.emplace_back(a);
	}
	dp[0] = 0;
	for (int i = 0; i < x; ++i){
		for (int coin: coins){
			if (i + coin <= x) dp[i+coin] = min(dp[i+coin], dp[i] + 1);
		}
	}
	cout << dp[x] << "\n";
	return 0;
}