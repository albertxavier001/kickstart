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



/*
	macros
*/

#define debug if (0)
#define local if (1)
#define ndebug if (0)

#define rep(i,beg,end) for (int i = beg; i < end; ++i)
#define repp(i,beg,end) for (int i = beg; i >= end; --i)
#define repa(x,v) for (auto x: v)
// #define repUpOpen(i,beg,end) for (int i = beg; i < end; ++i)
// #define repUpClose(i,beg,end) for (int i = beg; i <= end; ++i)
// #define repDownOpen(i,beg,end) for (int i = beg; i > end; --i)
// #define repDownClose(i,beg,end) for (int i = beg; i >= end; --i)
#define pb push_back

#define reads(x) string x; cin>>x;
#define readc(x) char x; cin>>x;
#define readi(x) int x; cin>>x;
#define readd(x) double x; cin>>x;
#define mod (1000000007)
#define readll(x) long long x; cin>>x;
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) min(a,max(b,c))
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
typedef std::vector<float> vecf;
typedef std::vector<double> vecd;

typedef std::vector<std::vector<bool> > gridb;
typedef std::vector<std::vector<char> > gridc;
typedef std::vector<std::vector<int> > gridi;
typedef std::vector<std::vector<float> > gridf;
typedef std::vector<std::vector<double> > gridd;

typedef std::vector<std::vector<std::vector<bool> > > cubeb;
typedef std::vector<std::vector<std::vector<char> > > cubec;
typedef std::vector<std::vector<std::vector<int> > > cubei;
typedef std::vector<std::vector<std::vector<float> > > cubef;
typedef std::vector<std::vector<std::vector<double> > > cubed;

#define new_vecb(x,n,val) vecb x(n, val);
#define new_vecc(x,n,val) vecc x(n, val);
#define new_veci(x,n,val) veci x(n, val);
#define new_vecf(x,n,val) vecf x(n, val);
#define new_vecd(x,n,val) vecd x(n, val);

#define new_gridb(x,r,c,val) gridb x(r, vecb(c, val));
#define new_gridc(x,r,c,val) gridc x(r, vecc(c, val));
#define new_gridi(x,r,c,val) gridi x(r, veci(c, val));
#define new_gridf(x,r,c,val) gridf x(r, vecf(c, val));
#define new_gridd(x,r,c,val) gridd x(r, vecd(c, val));

#define new_cubeb(x,r,c,h,val) cubeb x(r, gridb(c, vecb(h, val)));
#define new_cubec(x,r,c,h,val) cubec x(r, gridc(c, vecc(h, val)));
#define new_cubei(x,r,c,h,val) cubei x(r, gridi(c, veci(h, val)));
#define new_cubef(x,r,c,h,val) cubef x(r, gridf(c, vecf(h, val)));
#define new_cubed(x,r,c,h,val) cubed x(r, gridd(c, vecd(h, val)));

/*
	common functions
*/


template <class T>
inline void hash_combine(std::size_t & seed, const T & v)
{
	std::hash<T> hasher;
	seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

struct pair_hash {
	template <class T1, class T2>
	std::size_t operator () (const std::pair<T1,T2> &p) const {
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


template <class T>
void printMatrix(vector<vector<T> > &m) {
	for (auto l: m) {
		for (auto e: l) {
			cout << e << " ";
		}
		cout << endl;
	}
}

template <class T>
void printVector(vector<T> &v) {
	for (auto e: v) {
		cout << e << " ";
	}
	cout << endl;
}


template <class Iter>
void mergeSort(Iter beg, Iter end) {
	if (end - beg > 1) {
		Iter mid = beg + (end - beg) / 2;
		mergeSort(beg, mid);
		mergeSort(mid, end);
		inplace_merge(beg, mid, end);
	}
}

/*
	variables
*/



/*
	my functions
*/




void solve (int iter) {

	/* code here */
	readi(R) readi(C) readi(K)

	new_gridb(mon,R,C,false) new_gridi(dp,R,C,1)

	rep (i,0,K) {
		readi(r) readi(c)
		mon[r][c] = true;
		dp[r][c] = 0;
	}

	ll sum = 0;
	rep(i,0,R) {
		rep(j,0,C) {
			if (mon[i][j] == true) continue;
			if (i == 0 || j == 0) {sum++; continue;}
			// int a1 = dp[i-1][j];
			// int a2 = dp[i][j-1];
			// int a3 = dp[i-1][j-1];
			// int r = max3((i-1) - abs(a1-1), (i) - abs(a2-1), (i-1) - abs(a3-1));
			// int c = max3((j) - abs(a1-1), (j-1) - abs(a2-1), (j-1) - abs(a3-1));
			// int len = min((i) - (r) + 1, (j) - (c) + 1);
			// if (a1 == 0 || a2 == 0 || a3 == 0) len = 1;
			// dp[i][j] = max(len, 1);
			// sum += dp[i][j];
			dp[i][j] = min3(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1;
			ndebug {
//				if (len != dp[i][j]) {
//                    int len2 = dp[i][j];
//                    cerr << "i = " << i << " j = " << j << endl;
//                    cerr << "r = " << r << " c = " << c << endl;
//                    cerr << "a1 = " << a1 << " a2 = " << a2 << " a3 = " << a3 << endl;
//                    cerr << "len = " << len << " dp = " << len2 << endl;
//                    cerr << "diff\n";
//
//                }
			}
			sum += dp[i][j];
		}
	}

	cout << "Case #" << iter << ": ";
	cout << sum;
	cout << endl;

	debug {
		printMatrix(mon);
		printMatrix(dp);
	}


}

int main () {
	local {
        freopen("B-large-practice.in", "r", stdin);
//        freopen("input.txt", "r", stdin);

		freopen("output.txt", "w", stdout);
	}

	readi(T);
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

