#include <bits/stdc++.h>
using namespace std;

/*
https://dmoj.ca/problem/lcs
*/

int a[1005], b[1005], dp[1005][1005];

int32_t main(){
	int n,m; cin >> n >> m;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for (int i = 1; i <= m; ++i){
		cin >> b[i];
	}
	//base cases
	for (int i = 1; i <= n; ++i){
		dp[i][0] = 0;
	}
	for (int i = 1; i <= m; ++i){
		dp[0][i] = 0;
	}
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			if (a[i] == b[j]){
				//equal elements, extend lcs of dp[i-1][j-1]
				dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
			}
		}
	}
	cout << dp[n][m] << "\n";
	return 0;
}