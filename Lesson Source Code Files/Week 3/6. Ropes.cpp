#include <bits/stdc++.h>
using namespace std;

/*
what is the maximum length l such that we can cut out k pieces of length l from the n ropes?

how many ropes of length l can we cut out given some length l?
f(l) returns the number of ropes we can cut out of length l out of the n ropes
if we had a rope of length a, we can cut out floor(a/l) pieces of rope with length l
for every rope, calculate how many ropes of length l we can cut out from that rope
and sum up the number of ropes from each rope
*/

int n,k;
double lengths[10005];

int f(double length){
	int ropecnt = 0;
	for (int i = 1; i <= n; ++i){
		ropecnt += floor(lengths[i] / length);
	}
	return ropecnt;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i){
		cin >> lengths[i];
	}
	//log(10^14) = 14*log(10)
	double lo = 0, hi = 1e7;
	while (hi - lo >= 1e-7){
		double mid = (lo + hi) / 2;
		if (f(mid) >= k){
			//we can cut more than k ropes of length mid, try cutting longer ropes
			lo = mid;
		}
		else{
			//we cannot cut k ropes of legnth mid, try cutting shorter ropes
			hi = mid;
		}
	}
	cout << fixed << setprecision(10) << lo << "\n";
	return 0;
}