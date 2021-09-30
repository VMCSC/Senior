#include <bits/stdc++.h>
using namespace std;

/*
let largest store the largest element in the array
let answer store our final answer (initialized to -1)
loop to find largest
another loop: if the element is smaller than largest and greater than answer, update answer
*/

const int nax = 1e6 + 5;
int a[nax];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	int largest = 0, ans = -1;
	for (int i = 0; i < n; ++i){
		// O(n)
		cin >> a[i];
		largest = max(largest, a[i]);
	}
	for (int i = 0; i < n; ++i){
		// O(n)
		if (a[i] < largest){
			ans = max(ans, a[i]);
		}
	}
	cout << ans << "\n";
	return 0;
}