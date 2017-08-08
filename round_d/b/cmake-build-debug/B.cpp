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

#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second

const int maxn = 100010;

int n, k, a1, b1, c, d, e1, e2, f;

LL x[maxn], y[maxn], r[maxn], s[maxn], a[maxn], b[maxn];

void solve() {
  scanf("%d%d%d%d%d%d%d%d%d", &n, &k, &a1, &b1, &c, &d, &e1, &e2, &f);
  x[1] = a1, y[1] = b1;
  r[1] = 0, s[1] = 0;
  REPE(i, 2, n) {
    x[i] = (c * x[i - 1] + d * y[i - 1] + e1) % f;
    y[i] = (d * x[i - 1] + c * y[i - 1] + e2) % f;
  }
  REPE(i, 2, n) {
    r[i] = (c * r[i - 1] + d * s[i - 1] + e1) % 2;
    s[i] = (d * r[i - 1] + c * s[i - 1] + e2) % 2;
  }
  REPE(i, 1, n) {
    a[i] = r[i] == 0 ? x[i] : -x[i];
    b[i] = s[i] == 0 ? y[i] : -y[i];
  }
  vector<LL> aa, bb;
  REPE(i, 1, n) {
    LL sa = 0, sb = 0;
    REPE(j, i, n) {
      sa += a[j];
      sb += b[j];
      aa.PB(sa);
      bb.PB(sb);
    }
  }
  sort(ALL(aa));
  sort(ALL(bb));
  using T = tuple<LL, int, int>;
  priority_queue<T> q;
  const int m = SZ(aa);
  REP(i, m) {
    if (aa[i] <= 0) q.push({aa[i] * bb[0], i, 0});
    else q.push({aa[i] * bb[m - 1], i, m - 1});
  }
  while (k--) {
    LL s;
    int i, j;
    tie(s, i, j) = q.top();
    q.pop();
    if (k == 0) {
      printf("%lld\n", s);
      break;
    }
    if (aa[i] <= 0) j++;
    else j--;
    if (j >= 0 && j < m) q.push({aa[i] * bb[j], i, j});
  }
}

int main() {
  int T;
      freopen("B-small-practice.in", "r", stdin);
    freopen("output_ref.txt", "w", stdout);

  scanf("%d", &T);
  for (int kase = 1; kase <= T; ++kase) {
    printf("Case #%d: ", kase);
    solve();
  }
  return 0;
}

