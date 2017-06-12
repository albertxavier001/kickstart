// #include <bits/stdc++.h>
#include <iostream>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 2E3 + 10;
const ll INF = 1E9;

int n;
ll x[MAXN], y[MAXN], z[MAXN], r[MAXN];
ll s[6];

bool mark[MAXN];

void init(ll s[]){
	s[0] = s[2] = s[4] = INF;
	s[1] = s[3] = s[5] = -INF;
}

void update(ll s[], int i){
	s[0] = min(s[0], x[i] - r[i]), s[1] = max(s[1], x[i] + r[i]);
	s[2] = min(s[2], y[i] - r[i]), s[3] = max(s[3], y[i] + r[i]);
	s[4] = min(s[4], z[i] - r[i]), s[5] = max(s[5], z[i] + r[i]);
}

bool check(ll len){
	static ll s[6];
	ll c[3];
	for (int i = 0; i < 8; ++i){
		c[0] = i & 1 ? ::s[0] : ::s[1] - len;
		c[1] = i & 2 ? ::s[2] : ::s[3] - len;
		c[2] = i & 4 ? ::s[4] : ::s[5] - len;


		for (int j = 0; j < n; ++j)
			mark[j] = c[0] <= x[j] - r[j] && x[j] + r[j] <= c[0] + len
						&& c[1] <= y[j] - r[j] && y[j] + r[j] <= c[1] + len
						&& c[2] <= z[j] - r[j] && z[j] + r[j] <= c[2] + len;
		init(s);
		for (int j = 0; j < n; ++j)
			if (!mark[j])
				update(s, j);

		if (s[1] - s[0] <= len && s[3] - s[2] <= len && s[5] - s[4] <= len)
			return true;
	}
	return false;
}

int main(){
	int cas;
	scanf("%d", &cas);
	for (int casi = 1; casi <= cas; ++casi){
		printf("Case #%d: ", casi);

		scanf("%d", &n);
		init(s);
		for (int i = 0; i < n; ++i){
			scanf("%lld%lld%lld%lld", x + i, y + i, z + i, r + i);
			update(s, i);// xyz最大最小值
		}
		ll low = 0, high = INF, mid;
		while (low < high){
			mid = low + ((high - low) >> 1);
			if (check(mid))
				high = mid;
			else
				low = mid + 1;
		}
		printf("%lld\n", low);
	}
	return 0;
}
