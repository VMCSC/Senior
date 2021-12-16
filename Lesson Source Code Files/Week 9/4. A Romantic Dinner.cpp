#include <bits/stdc++.h>
using namespace std;

int M,U,R,dp[151][301][101];

int32_t main(){
	cin >> M >> U >> R;
	for (int i = 1; i <= R; ++i){
		int v,t,f; cin >> v >> t >> f;
		for (int j = 1; j <= M; ++j){
			for (int k = 1; k <= U; ++k){
				//not go to the restaurant
				dp[i][j][k] = dp[i-1][j][k];
				//go to the restaurant
				if (j >= t and k >= f) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-t][k-f]+v);
			}
		}
	}
	cout << dp[R][M][U] << "\n";
	return 0;
}