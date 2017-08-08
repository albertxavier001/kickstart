#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

//////

/*
        macros
*/

#define debug if (1)
#define local if (1)
#define ndebug if (0)

#define rep(i, beg, end) for (int i = beg; i < end; ++i)
#define repp(i, beg, end) for (int i = beg; i >= end; --i)
#define repa(x, v) for (auto x : v)
// #define repUpOpen(i,beg,end) for (int i = beg; i < end; ++i)
// #define repUpClose(i,beg,end) for (int i = beg; i <= end; ++i)
// #define repDownOpen(i,beg,end) for (int i = beg; i > end; --i)
// #define repDownClose(i,beg,end) for (int i = beg; i >= end; --i)
#define pb push_back

#define reads(x)                                                               \
  string x;                                                                    \
  cin >> x;
#define readc(x)                                                               \
  char x;                                                                      \
  cin >> x;
#define readi(x)                                                               \
  int x;                                                                       \
  cin >> x;
#define readll(x)                                                              \
  long long x;                                                                 \
  cin >> x;
#define readd(x)                                                               \
  double x;                                                                    \
  cin >> x;
#define mod (1000000007)

#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))

/*
        type
*/
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef std::vector<bool> vecb;
typedef std::vector<char> vecc;
typedef std::vector<int> veci;
typedef std::vector<long> vecl;
typedef std::vector<long long> vecll;
typedef std::vector<float> vecf;
typedef std::vector<double> vecd;

typedef std::vector<std::vector<bool>> gridb;
typedef std::vector<std::vector<char>> gridc;
typedef std::vector<std::vector<int>> gridi;
typedef std::vector<std::vector<float>> gridf;
typedef std::vector<std::vector<double>> gridd;

typedef std::vector<std::vector<std::vector<bool>>> cubeb;
typedef std::vector<std::vector<std::vector<char>>> cubec;
typedef std::vector<std::vector<std::vector<int>>> cubei;
typedef std::vector<std::vector<std::vector<float>>> cubef;
typedef std::vector<std::vector<std::vector<double>>> cubed;

#define new_vecb(x, n, val) vecb x(n, val);
#define new_vecc(x, n, val) vecc x(n, val);
#define new_veci(x, n, val) veci x(n, val);
#define new_vecf(x, n, val) vecf x(n, val);
#define new_vecd(x, n, val) vecd x(n, val);

#define new_gridb(x, r, c, val) gridb x(r, vecb(c, val));
#define new_gridc(x, r, c, val) gridc x(r, vecc(c, val));
#define new_gridi(x, r, c, val) gridi x(r, veci(c, val));
#define new_gridf(x, r, c, val) gridf x(r, vecf(c, val));
#define new_gridd(x, r, c, val) gridd x(r, vecd(c, val));

#define new_cubeb(x, r, c, h, val) cubeb x(r, gridb(c, vecb(h, val)));
#define new_cubec(x, r, c, h, val) cubec x(r, gridc(c, vecc(h, val)));
#define new_cubei(x, r, c, h, val) cubei x(r, gridi(c, veci(h, val)));
#define new_cubef(x, r, c, h, val) cubef x(r, gridf(c, vecf(h, val)));
#define new_cubed(x, r, c, h, val) cubed x(r, gridd(c, vecd(h, val)));
/*
        common functions
*/

template <class T> inline void hash_combine(std::size_t &seed, const T &v) {
  std::hash<T> hasher;
  seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    // std::hash<T1> h1;
    // std::hash<T2> h2;

    // // Mainly for demonstration purposes, i.e. works but is overly simple
    // // In the real world, use sth. like boost.hash_combine
    // return h1(p.first) ^ h2(p.second);

    size_t seed = 0;
    ::hash_combine(seed, p.first);
    ::hash_combine(seed, p.second);
    return seed;
  }
};

template <class T> void printMatrix(vector<vector<T>> &m) {
  for (auto l : m) {
    for (auto e : l) {
      cout << e << " ";
    }
    cout << endl;
  }
}

template <class T> void printVector(vector<T> &v) {
  for (auto e : v) {
    cout << e << " ";
  }
  cout << endl;
}

template <class Iter> void mergeSort(Iter beg, Iter end) {
  if (end - beg > 1) {
    Iter mid = beg + (end - beg) / 2;
    mergeSort(beg, mid);
    mergeSort(mid, end);
    inplace_merge(beg, mid, end);
  }
}

///////

/*
        variables
*/

/*
        my functions
*/

void solve(int iter) {

  /* code here */
  int N, K, A1, B1, C, D, E1, E2, F;
  cin >> N >> K >> A1 >> B1 >> C >> D >> E1 >> E2 >> F;

  // gen AB
  vecll A(N), B(N);
  int x, y, r, s;
  x = A1;
  y = B1;
  r = s = 0;
  int x0 = x, y0 = y;
  int r0 = r, s0 = s;
  A[0] = A1;
  B[0] = B1;
  for (int i = 1; i < N; i++) {
    x = (C * x0 + D * y0 + E1) % F;
    y = (D * x0 + C * y0 + E2) % F;
    r = (C * r0 + D * s0 + E1) % 2;
    s = (D * r0 + C * s0 + E2) % 2;
    A[i] = pow(-1, r) * x;
    B[i] = pow(-1, s) * y;
    x0 = x, y0 = y, r0 = r, s0 = s;
  }

  // // cal P
  // debug cerr << "cal P" << endl;
  // new_gridi(P, N, N, 0);
  // rep(i, 0, N) {
  //   rep(j, 0, N) {
  //     int cell = A[i] * B[j];
  //     int part1 = i > 0 ? P[i - 1][j] : 0;
  //     int part2 = j > 0 ? P[i][j - 1] : 0;
  //     int part3 = j > 0 && i > 0 ? P[i - 1][j - 1] : 0;
  //     P[i][j] = part1 + part2 + cell - part3;
  //   }
  // }

  // AA
  AA;
  vecll AA, BB;
  for (int i = 0; i < N; i++) {
    ll sa = 0, sb = 0;
    for (int j = i; j < N; j++) {
      sa += A[j], sb += B[j];
      AA.push_back(sa), BB.push_back(sb);
    }
  }

  // find N max values and N mins values of AA and BB respectly

  // find K max values using max heap with channel of N (separate by AA) similar
  // to house running game

  cout << "Case #" << iter << ": ";
  cout << ret;
  cout << endl;
}

int main() {
  local {
    // freopen("input.txt", "r", stdin);
    freopen("B-small-practice.in", "r", stdin);
    // freopen("A-large-practice.in", "r", stdin);
    freopen("output.txt", "w", stdout);
  }

  readi(T);
  for (int t = 1; t <= T; t++) {
    debug { cerr << "t = " << t << endl; }
    solve(t);
  }

  return 0;
}
