#include <bits/stdc++.h>
using namespace std;

/*
intuition:
we want to break along the expensive lines as little as possible
the number of breaks along a line we must perform is equal to the number of perpendicular breaks that have been done already + 1
e.g. if you break the initial chocolate bar horizontally once, the next time you make a vertical break, you need to perform 2 breaks along the vertical line.
therefore it's reasonable to assume that we should greedily break along the lines from most expensive to least expensive

solution:
sort the lines in non-increasing order by cost.
keep track of the number of horizontal and vertical breaks that have been performed already
for every line:
	add cost * (number of perpendicular breaks + 1) to our total
	add to the number of breaks in this direction
*/

const int nax = 1e3 + 5;
int m,n;
pair<int,int> lines[nax*2];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m-1; ++i){
		//O(M)
		int c; cin >> c;
		lines[i] = {c,0};
	}
	for (int i = 0; i < n-1; ++i){
		//O(N)
		int c; cin >> c;
		lines[m-1+i] = {c,1};
	}
	sort(lines, lines + n + m - 2, greater<pair<int,int>>()); //O((N+M)log(N+M))
	int h = 1, v = 1, ans = 0;
	for (int i = 0; i < m + n - 2; ++i){
		// O(M+N)
		if (lines[i].second == 0){
			ans += h * lines[i].first;
			++v;
		}
		else if (lines[i].second == 1){
			ans += v * lines[i].first;
			++h;
		}
	}
	cout << ans << "\n";
	
	return 0;
}