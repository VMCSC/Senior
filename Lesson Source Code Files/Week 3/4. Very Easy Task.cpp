#include <bits/stdc++.h>
using namespace std;

/*
https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C
we have 1 copy
we want n more copies
to allow both copiers to work at the same time, make one copy first
ans = min(x,y)
make n-1 more copies
how many copies can we make with both copiers given some amount of time t?
f(t) = t/x + t/y
the more time you give the copiers, the more copies they can make
f(x) >= f(y) for all x >= y
monotonic function - non-decreasing (or non-increasing)

minimum t such that f(t) >= n-1
0 <= t <= 10^9
*/

int n,x,y;

int f(int t){
	return t / x + t / y;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> x >> y;
	int lo = 0, hi = 5*n;
	int ans; //stores the minimum time that we need to make n-1 copies
	//O(logN)
	//log(10^9) = 9*log(10) = ~30
	while (lo <= hi){
		int mid = (lo + hi) / 2;
		if (f(mid) >= n-1){
			//if we can make n-1 copies with time mid, then try to use less time
			ans = mid;
			hi = mid - 1;
		}
		else{
			//if we can't make n-1 copies, use more time
			lo = mid + 1;
		}
	}
	cout << ans + min(x,y) << "\n";
	return 0;
}