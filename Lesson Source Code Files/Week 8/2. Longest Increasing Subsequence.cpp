#include <bits/stdc++.h>
using namespace std;

/*
https://dmoj.ca/problem/dp1p3
*/

int a[5005], dp[5005];

int32_t main(){
	int n; cin >> n;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	dp[0] = 0;
	for (int i = 1; i <= n; ++i){
		for (int j = 0; j < i; ++j){
			if (a[j] < a[i]){
				//can extend from a subsequence ending at a[j]
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i){
		ans = max(ans, dp[i]);
	}
	cout << ans << "\n";
	return 0;
}