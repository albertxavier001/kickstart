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

char a[105][105];
int n, m, K, T[105][105][105];

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

    memset(T, 0, sizeof T);
    int res = 0;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
        if (a[i][j]=='.') continue;
        for (int k = 0; k < K; ++k) {
            if (k != 0 && T[i][j][k]==0) continue;
            int cnt = T[i][j][k];
            for (int x = 0; x <= 1000000000; ++x) {
                if (ok(i+x,j,x)) {
                    cnt += 2*x + 1;
                    for (int y = j-x; y <= j+x; ++y) {
                        T[i+x+1][y][k+1] = max(T[i+x+1][y][k+1],cnt);
                        if (k+1==K)
                            res = max(res,T[i+x+1][y][k+1]);
                    }
                }
                else break;
            }
        }
    }

//    int res = 0;
//    for (int i = 1; i <= n; ++i)
//    for (int j = 1; j <= m; ++j) {
//        if (a[i][j]=='.') continue;
//        int cnt = 0;
//        for (int k = 0; k <= 1000000000; ++k) {
//            if (ok(i+k,j,k)) F[i][j] += 2*k + 1;
//            else break;
//        }
//        //
//        //
//    }
    return res;
}

int main() {
	freopen("../C-large-practice.in", "r", stdin);
    freopen("../output_ref.txt", "w", stdout);
    int t; scanf("%d",&t); int te = t;
    while (t--) {
        scanf("%d%d%d\n",&n,&m,&K);
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
