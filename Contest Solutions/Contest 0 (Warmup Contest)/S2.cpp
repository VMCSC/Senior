#include <bits/stdc++.h>
using namespace std;

/*
n events each starting and ending on some day
recruit volunteers to attend them

what is the maximum number of events occuring on any given day?

events[i] store the number of events on day i
*/

const int nax = 1e6 + 5;
int n, events[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i){
		int x,y; cin >> x >> y;
		// y - x + 1 <= 10
		for (int j = x; j <= y; ++j){
			++events[j];
		}
	}
	int ans = 0;
	for (int i = 0; i <= 1e6; ++i){
		ans = max(ans,events[i]);
	}
	cout << ans << "\n";
	
	return 0;
}