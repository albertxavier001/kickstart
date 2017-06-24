#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <limits>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

const int N = 105;
const int INF = 1e9;

int n, m, k;
int dp[N][N][N];
string s[N];
int psum[N][N];

void read() {
	cin >> n >> m >> k;
	for(int i = 1 ; i <= n ; i++) {
		cin >> s[i];
		s[i] = "." + s[i];
	}
}

void prepare() {
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m; j++)
			psum[i][j] = psum[i][j-1] + (s[i][j] == '#');
}

int DP() {
	for(int it = 1 ; it <= k ; it++) {
		for(int j = 1 ; j <= m ; j++)
			dp[it][n+1][j] = -INF;

		for(int i = n ; i >= 1 ;  i--)
			for(int j = 1 ; j <= m ; j++)
				if(s[i][j] == '.') {
					dp[it][i][j] = -INF;
				} else {
					dp[it][i][j] = -INF;
					for(int lvl = 0 ; i+lvl <= n ; lvl++) {
						int row = i+lvl;
						int kiri = j-lvl;
						int kanan = j+lvl;

						if(kiri < 1 || kanan > m || psum[row][kanan]-psum[row][kiri-1] != kanan-kiri+1) {
							break;
						}

						int add = (lvl+1)*(lvl+1);

						for(int x = kiri ; x <= kanan ; x++) {
							dp[it][i][j] = max(dp[it][i][j], add + dp[it-1][row+1][x]);
						}
					}
				}
	}

	int ret = 0;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			ret = max(ret, dp[k][i][j]);

	return ret;
}

int main() {
	freopen("../C-small-practice.in", "r", stdin);
	// freopen("../input.txt", "r", stdin);
	freopen("../output_ref.txt", "w", stdout);
	int t; cin >> t;
	for(int tc = 1 ; tc <= t ; tc++) {
		read();
		prepare();
		int ret = DP();
		printf("Case #%d: %d\n", tc, ret);
	}
	return 0;
}