#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, W, dp[100005];

int32_t main(){
	cin >> N >> W;
	for (int i = 1; i <= N; ++i){
		ll w,v; cin >> w >> v;
		for (int j = W; j >= w; --j){
			dp[j] = max(dp[j], dp[j-w] + v); //take the item
		}
	}
	cout << dp[W] << "\n";
	return 0;
}s