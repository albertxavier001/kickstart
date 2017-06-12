// #include <bits/stdc++.h>
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
#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;
using namespace placeholders;

const bool debug=0;
const bool local=1;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const ll MOD = 1E9 + 7, INV2 = (MOD + 1) / 2, INV3 = (MOD + 1) / 3;

int main(){
	if (local) {
		freopen("./A-large-practice.in", "r", stdin);
		freopen("./output_gt.txt", "w", stdout);
	}
	
	int cas;
	// scanf("%d", &cas);
	cin >> cas;
	for (int casi = 1; casi <= cas; ++casi){
		printf("Case #%d: ", casi);

		ll n, m;
		// scanf("%lld%lld", &n, &m);
		cin >> n >> m;
		if (n > m)
			swap(n, m);
		ll c1 = n * (n + 1) / 2 % MOD;
		ll c2 = c1 * (2 * n + 1) % MOD * INV3 % MOD;
		ll c3 = c1 * c1 % MOD;
		ll ans = n * m % MOD * c1 % MOD;
		ans = (ans - (n + m) * c2) % MOD;
		ans = (ans + c3) % MOD;
		// cout << "c1 = " << c1 << endl;
		// cout << "c2 = " << c2 << endl;
		// cout << "c3 = " << c3 << endl;
		printf("%lld\n", (ans + MOD) % MOD);
	}
	return 0;
}
