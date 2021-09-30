#include <bits/stdc++.h>
using namespace std;

/*
binary search implementation for
https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
*/

const int nax = 1e5 + 5;
int n,k,arr[nax];

int32_t main() {
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
		bool found = false;
		int lo = 1, hi = n;
		while (lo <= hi){
			//O(logN)
			int mid = (lo + hi) / 2;
			if (arr[mid] == a){
				found = true;
				break;
			}
			else if (arr[mid] > a){
				hi = mid - 1;
			}
			else if (arr[mid] < a){
				lo = mid + 1;
			}
		}
		if (found) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	return 0;
}