#include <bits/stdc++.h>
using namespace std;

/*
https://dmoj.ca/problem/acmtryouts2b


2 approaches
1. simulate each balloon going along the cells, checking each tower at each cell
2. calculating the damage a balloon will take by going to each cell, then checking how far each balloon would make it

the second approach is easier to optimize
lets break it down into 2 parts
1. calculating the damage dealt in each cell by the towers: O(N)
2. calculating how far each balloon can go without dying: O(Mlog(L))

O(n)
since each tower deals a certain amount of damage to a range of cells, we can see that this part can be reduced to range increments. we use difference arrays to do this in O(1) for each tower, resulting in O(n)

now that we know the damage a balloon will receive in each cell, how can we find out how far it will go in sublinear time?

dmg[i] stores the amount of damage a balloon will take in cell i by all the towers

compute the prefix sum of dmg

find the largest index of the prefix sum array that does not exceed the hp
the balloon will make it to the cell to the right of that cell
*/

const int nax = 1e3 + 5;
long long l,n,c,r,d,m,h,diff[nax];

void solve(){
	memset(diff, 0, sizeof(diff));
	cin >> l >> n;
	for (int i = 1; i <= n; ++i){
		cin >> c >> r >> d;
		diff[max(1ll,c-r)] += d;
		diff[min(l,c+r)+1] -= d;
	}
	//restore the original updated array
	for (int i = 1; i <= l; ++i){
		diff[i] += diff[i-1];
	}
	//construct the prefix sum array
	for (int i = 1; i <= l; ++i){
		diff[i] += diff[i-1];
	}
	cin >> m;
	while (m--){
		int hp; cin >> hp;
		int lo = 0, hi = l;
		int ans = 0;
		while (lo <= hi){
			int mid = (lo + hi) / 2;
			if (hp > diff[mid]){
				//can sustain the damage, go further
				lo = mid + 1;
				ans = mid;
			}
			else{
				//can't sustain the damage, go back
				hi = mid - 1;
			}
		}
		if (ans == l and hp > diff[l]){
			//sustains all damage, makes it all the way through
			cout << "Bloon leakage" << "\n";
		}
		else cout << ans + 1 << "\n";
	}
		
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}