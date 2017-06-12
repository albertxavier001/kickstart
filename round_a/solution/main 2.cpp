#include <algorithm>
#include <iostream>

using namespace std;

const long long mod = 1e9 + 7ll;
const long long inv2 = mod / 2ll + 1;
const long long inv6 = 166666668ll;

long long sum1(long long x) {
	long long ans = x;
	ans = (ans * (x+1)) % mod;
	ans = (ans * inv2) % mod;
}
long long sum2(long long x) {
	long long ans = x;
	ans = (ans * (x+1)) % mod;
	ans = (ans * (2*x+1)) % mod;
	ans = (ans * inv6) % mod;
	return ans;
}
long long sum3(long long x) {
	long long ans = sum1(x);
	ans = (ans * ans) % mod;
	return ans;
}
int main(void) {

	int testcase;
	cin >> testcase;

	for (int Case = 1 ; Case <= testcase ; ++Case) {
		long long r, c;
		cin >> r >> c;
		long long ans = 0;
	
		long long lim = min(r-1, c-1);
		ans = (ans + ((r * c) % mod) * sum1(lim)) % mod;
		ans = (ans - ((c + r) % mod) * sum2(lim)) % mod;
		ans = (ans + sum3(lim)) % mod;
		ans = (ans % mod + mod) % mod;
		cout << "Case #" << Case << ": " << ans << endl;
	}

	return 0;
}