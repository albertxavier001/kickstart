#include <iostream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstdint>
#include <limits>
using namespace std;

const bool debug=0;
const bool local=1;

const long long MOD = 1000000007;
long long INV2 = (MOD + 1) / 2;
long long INV4 = (MOD + 1) / 4;
long long INV6 = (MOD + 1) / 6;

long long add(long long x, long long y) {
	return x + y < MOD ? x + y : x + y - MOD;
}

long long mul(long long x, long long y) {
	return x * y % MOD;
}

long long solve (long long R, long long C) {
	long long sum = 0;
	// for (long long i = 0; i <= min(R, C); i++) {
	// 	sum += (i * (R-i) * (C-i)) % MOD;
	// 	sum %= MOD;
	// }

	long long N = min(R, C) % MOD;
	long long RC = mul(R,C);
	long long R_C = add(R,C);
	long long t1;
	t1 = mul(mul(N,N+1), INV2);
	long long t2;
	t2 = mul(N, add(N,1));
	t2 = mul(t2, add(mul(2LL,N),1LL));
	t2 = mul(t2, INV6);
	long long t3;
	t3 = mul(t1, t1);

	// cout << "t1  = " << t1 << endl;
	// cout << "t2  = " << t2 << endl;
	// cout << "t3  = " << t3 << endl;
	t1 = mul(t1, RC);
	t2 = mul(t2, R_C);
	sum = add(add(t1,t3),-t2);
	return (sum+MOD)%MOD;
}

int main () {
	if (local) {
		freopen("./A-large-practice.in", "r", stdin);
		freopen("./output.txt", "w", stdout);
	}
	else {
	}

	long long T, R, C;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> R >> C;
		long long cnt = solve(R, C);
		printf("Case #%d: %llu\n", i+1, cnt);
	}

	return 0;
}