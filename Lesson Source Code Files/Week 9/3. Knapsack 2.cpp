#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,w,dp[100005];

int32_t main(){
	cin >> n >> w;
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	for (int i = 1; i <= n; ++i){
		ll a,b; cin >> a >> b;
		for (int j = 100004; j >= b; --j){
			if (j >= b) dp[j] = min(dp[j], dp[j-b] + a);
		}
	}
	for (int i = 100004; i >= 0; --i){
		if (dp[i] <= w){
			cout << i << "\n";
			break;
		}
	}
	return 0;
}