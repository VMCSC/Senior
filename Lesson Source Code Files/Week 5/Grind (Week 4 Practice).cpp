#include <bits/stdc++.h>
using namespace std;

/*
given a range [l,r]
is the sum from l to r > k?
	compute the sum using prefix sum arrays and compare with k
does a appear in the range?
does b appear in the range?

keep track of an array of indices where the number x appears
{1,5,43,12,6,1,5,1} 1 indexed
freq[1] = {1,6,8}

freq[x] stores all i where a[i] = x
unordered_map<keytype,valuetype> m;
m[key] -> value
m[key] = value

binary search for the lowest index >= l
then compare with r
lowest index -> i
if i > r: there is no value in the range [l,r]
else there is a value in the range [l,r]

alternatively, we can use a binary search tree
*/

const int nax = 1e5 + 5;
int n,q,k,prefix[nax];
unordered_map<int,set<int>> freq;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k >> q;
	for (int i = 1; i <= n; ++i){
		cin >> prefix[i];
		freq[prefix[i]].insert(i);
		prefix[i] += prefix[i-1];
	}
	while (q--){
		int a,b,l,r; cin >> a >> b >> l >> r;
		if (prefix[r] - prefix[l-1] > k and freq[a].lower_bound(l) != freq[a].end() and *freq[a].lower_bound(l) <= r and freq[b].lower_bound(l) != freq[b].end() and *freq[b].lower_bound(l) <= r){
			cout << "Yes\n";
		}
		else cout << "No\n";
	}
	return 0;
}