#include <bits/stdc++.h>
using namespace std;

/*
https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/E

f(x) = x^2 + sqrt(x)
f(x) >= f(y) for all x >= y >= 0
monotonic function - non-decreasing
*/

double f(double x){
	return x*x + sqrt(x);
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	double c; cin >> c;
	double lo = 0, hi = 1e5;
	//log(10^12)
	while (hi - lo >= 1e-7){
		double mid = (lo + hi) / 2;
		if (f(mid) > c){
			hi = mid;
		}
		else lo = mid;
	}
	//hi - lo < 10^-7
	cout << fixed << setprecision(8) << lo << "\n";
	return 0;
}