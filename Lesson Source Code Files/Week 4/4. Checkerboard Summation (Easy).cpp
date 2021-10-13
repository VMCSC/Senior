#include <bits/stdc++.h>
using namespace std;

/*
https://dmoj.ca/problem/cheasy
*/

const int nax = 3e3 + 5;
int m,n,board[nax][nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n;
	while (true){
		int r,c,x; cin >> r >> c >> x;
		if (r == 0) break;
		board[r][c] = x * ((r + c) % 2 == 0 ? 1 : -1);
	}
	for (int i = 1; i <= m; ++i){
		for (int j = 1; j <= n; ++j){
			board[i][j] += board[i-1][j] + board[i][j-1] - board[i-1][j-1];
		}
	}
	while (true){
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		if (r1 == 0) break;
		int ans = board[r2][c2] - board[r2][c1-1] - board[r1-1][c2] + board[r1-1][c1-1];
		if ((r1 + c1) % 2 == 0){
			cout << ans << "\n";
		}
		else {
			cout << ans * -1 << "\n";
		}
	}
	
	return 0;
}