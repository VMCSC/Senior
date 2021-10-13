#include <bits/stdc++.h>
using namespace std;

/*
https://cses.fi/problemset/task/1652/

visual aid:
https://usaco.guide/silver/more-prefix-sums?lang=cpp
*/

const int nax = 1e3 + 5;
int n,q,psa[nax][nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i){
		string s; cin >> s;
		for (int j = 1; j <= n; ++j){
			psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + (s[j-1] == '*');
		}
	}
	while (q--){
		int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
		cout << psa[y2][x2] - psa[y1-1][x2] - psa[y2][x1-1] + psa[y1-1][x1-1] << "\n";
	}	
	return 0;
}