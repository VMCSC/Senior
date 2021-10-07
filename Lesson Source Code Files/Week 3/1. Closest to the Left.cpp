#include <bits/stdc++.h>
using namespace std;

/*
https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B
*/

const int nax = 1e5 + 5;
int n,k,arr[nax];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i){
		cin >> arr[i];
	}
	//O(k*logn)
	//Estimate: 10^5*5*log2(10)
	//C++: 10^8
	while (k--){
		//O(k)
		int a;
		cin >> a;
		int lo = 1, hi = n;
		int ans = 0;
		while (lo <= hi){
			//O(logN)
			int mid = (lo + hi) / 2;
			if (arr[mid] <= a){
				ans = mid;
				lo = mid + 1;
			}
			else hi = mid - 1;
		}
		cout << ans << "\n";
	}
	return 0;
}