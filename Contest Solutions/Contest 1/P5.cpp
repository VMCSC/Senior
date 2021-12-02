#include <bits/stdc++.h>
using namespace std;
 
/*
the problem essentially states, "how many triple of (x,y,z) satisfy (A <= x <= B <= y <= C <= z <= D), and x + y > z?"

the brute force solution would be to iterate through all values x,y and z, and checking if the inequality holds

O(n) for x * O(n) for y * O(n) for z = O(n^3)

by computing a frequency array where arr[i] stores the number of pairs (x,y) where x+y = i, we can do the precomputation by looping through pairs of (x,y) and adding 1 to arr[x+y], then for every fixed z we can sum from arr[z+1] to the end

O(n) for x * O(n) for y + O(n) for z * O(n) to sum up = O(n^2)

computing the sum from arr[z+1] to the end of the array can be optimized with prefix sum arrays

O(n) for x * O(n) for y + O(n) to compute PSA + O(n) for z * O(1) to sum up = O(n^2)

if we fix a value of x, we realize that we are essentially adding 1 to each index from x+B to x+C (B and C being the min and max for y). this range update can be optimized with a difference array

O(n) for x * O(1) to update diff array + O(n) to unfold diff array + O(n) to compute PSA + O(n) for z * O(1) to sum up = O(n)

which is enough to pass
*/
 
const int nax = 2e6 + 5;
long long a,b,c,d,arr[nax];
 
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b >> c >> d;
	for (int x = a; x <= b; ++x){
		++arr[x+b];
		--arr[x+c+1];
	}
	//to unfold the difference array
	for (int i = a+b; i < nax; ++i){
		arr[i] += arr[i-1];
	}
	//precompute the psa
	for (int i = a+b; i < nax; ++i){
		arr[i] += arr[i-1];
	}
	long long ans = 0;
	for (int z = c; z <= d; ++z){
		//sum up arr[z+1] to the end
		ans += arr[nax-1] - arr[z];
	}
	cout << ans << "\n";
	return 0;
}	