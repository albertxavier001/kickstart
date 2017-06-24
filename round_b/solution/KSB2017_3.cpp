#include <bits/stdc++.h>

using namespace std;

char a[105][105];
int n, m, k;

bool inside(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

bool ok(int i, int j, int k) {
    if (!inside(i,j)) return false;
    for (int x = j-k; x <= j+k; ++x)
        if (!inside(i,x) || a[i][x]=='.') return false;
    return true;
}

int solve() {
    int res = 0;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
        if (a[i][j]=='.') continue;
        int cnt = 0;
        for (int k = 0; k <= 1000000000; ++k) {
            if (ok(i+k,j,k)) cnt += 2*k + 1;
            else break;
        }
        res = max(res,cnt);
    }
    return res;
}

int main() {
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
    int t; scanf("%d",&t); int te = t;
    while (t--) {
        scanf("%d%d%d\n",&n,&m,&k);
        for (int i = 1; i <= n; ++i)
            scanf("%s\n",a[i]+1);
//        for (int i = 1; i <= n; ++i) {
//            for (int j = 1; j <= m; ++j) cout << a[i][j];
//            cout << endl;
//        }
        cout << "Case #" << te-t << ": " << solve() << endl;
    }
	return 0;
}
