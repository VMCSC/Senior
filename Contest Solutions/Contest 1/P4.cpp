#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
the problem essentially states, "given a set of people with heights and money, find the maximum amount of money you can get by choosing some subset of these people such that no two people have a height difference > d"

O(2^n) subsets * O(n) to sum up

notice that if we sort the people by their height, we will always be picking a subarray (a contiguous interval) of people instead of a subset

O(nlogn) to sort + O(n^2) subarrays * O(n) to sum up = O(n^3)

if we fix a left end point, we can binary search for the furthest right end point of the interval such that the difference in height between the right and left is <= d. we don't have to check any right endpoints before the one we found, since the money value is non-negative.

O(nlogn) to sort + O(n) left endpoints * (O(logn) to binary search + O(n) to sum up) = O(n^2)

notice that we are summing up a contiguous interval every time. we can optimize this by precomputing a prefix sum array

O(nlogn) to sort + O(n) to precompute PSA + O(n) left endpoints * (O(logn) to binary search + O(1) to sum up) = O(nlogn)

which is enough to pass.
*/

const int nax = 2e5 + 5;
ll n,d,psa[nax];
pair<ll,ll> a[nax]; //{height,money}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> d;
	for (int i = 1; i <= n; ++i){
		cin >> a[i].first >> a[i].second;
	}
	sort(a+1,a+n+1);
	//psa
	for (int i = 1; i <= n; ++i){
		psa[i] = psa[i-1] + a[i].second;
	}
	//process the intervals
	ll ans = 0;
	for (int i = 1; i <= n; ++i){
		int lo = 0, hi = n, r;
		while (lo <= hi){
			int mid = (lo + hi) / 2;
			if (a[mid].first - a[i].first <= d){
				r = mid;
				lo = mid + 1;
			}
			else hi = mid - 1;
		}
		//sum of money from [i,r]
		ans = max(ans,psa[r]-psa[i-1]);
	}
	cout << ans << "\n";
	return 0;
}