#include <bits/stdc++.h>
using namespace std;

/*
set in c++ is different than a set in python
sets store unique elements in "sorted order"

find(x) - return an iterator pointing to x
insert(x) - inserts x into the set
erase(x) - erases the element x
erase(iterator) - erase the element that the iterator points to

lower_bound(x) - return an iterator that points to the first element that is greater than or equal to x
upper_bound(x) - return an iterator that points to the first element that is strictly greater than x

O(logN)
wrt the size of the set
*/

set<int> s = {1,6,3,23,6,34,7,4,1,4,9,10};

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (int k: s) cout << k << " ";
	cout << "\n";
	// cout << (s.find(100) == s.end()) << "\n";
	// s.insert(12);
	// s.erase(7);
	// s.erase(s.begin());
	// for (int k: s) cout << k << " ";
	// cout << "\n";
	cout << *s.upper_bound(7) << "\n";
	return 0;
}