#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const ll MOD = 1E9 + 7, INV2 = (MOD + 1) / 2, INV3 = (MOD + 1) / 3;

const int MAXN = 8E3 + 10;

char s[MAXN];
int n, m, a[MAXN], b[MAXN];
int f[MAXN][MAXN];

int getStr(int a[]){
	scanf("%s", s);
	int n = 0;
	for (int i = 0; s[i]; ++i)
		if (s[i] == '*'){
			a[++n] = 0;
			a[++n] = 0;
			a[++n] = 0;
			a[++n] = 0;
		}
		else
			a[++n] = s[i];
	return n;
}

int main(){
	int cas;
	scanf("%d", &cas);
	for (int casi = 1; casi <= cas; ++casi){
		printf("Case #%d: ", casi);

		n = getStr(a), m = getStr(b);
		for (int i = 0; i <= n; ++i)
			fill_n(f[i], m + 1, false);
		f[0][0] = true;
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= m; ++j){
				if (f[i][j]){
					f[i][j + 1] |= b[j + 1] == 0;
					f[i + 1][j] |= a[i + 1] == 0;
					f[i + 1][j + 1] |= !a[i + 1] || !b[j + 1] || a[i + 1] == b[j + 1];
				}
			}
		puts(f[n][m] ? "TRUE" : "FALSE");
	}
	return 0;
}
