#include <bits/stdc++.h>
using namespace std;
#define f(x, y, z) for(int x = (y); x <= (z); ++x)
#define g(x, y, z) for(int x = (y); x < (z); ++x)
#define h(x, y, z) for(int x = (y); x >= (z); --x)
typedef long long ll;

int n, m;
char a[107][107];
int b[107][107];

int gb(int x, int y)
{
	if(a[x][y] == '.') return 0;
	int k = 0;
	while(x + k + 1 <= n && y - k - 1 >= 1 && y + k + 1 <= m)
	{
		bool ok = true;
		f(j, y - k - 1, y + k + 1) if(a[x + k + 1][j] != '#')
		{
			ok = false; break;
		}
		if(ok) ++k; else break;
	}
	return k + 1;
}

int dp[107][107][107];

// struct ST
// {
	
// } st[107];
int sz[107];

int main()
{
	sz[0] = 0;
	f(i, 1, 100) sz[i] = sz[i - 1] + 2 * i - 1;
	int T; cin >> T;
	f(_, 1, T)
	{
		int kkk; cin >> n >> m >> kkk;
		f(i, 1, n) cin >> (a[i] + 1);
		f(i, 1, n) f(j, 1, m) b[i][j] = gb(i, j);
		memset(dp, 0xcf, sizeof(dp));
		memset(dp[0], 0, sizeof(dp[0]));
		f(k, 1, kkk) f(i, 1, n) f(j, 1, m) f(l, 1, b[i][j]) g(p, j - l + 1, j + l)
		{
			dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i + l][p] + sz[l]);
		}
		int ans = -1;
		f(i, 1, n) f(j, 1, m) ans = max(ans, dp[kkk][i][j]);
		if(ans < 0) ans = 0;
		printf("Case #%d: %d\n", _, ans);
	}
	return 0;
}
