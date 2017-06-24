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

#define debug if (1)
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
#define readll(x) long long x; cin>>x;
#define readd(x) double x; cin>>x;
#define mod (1000000007)

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

const ll MAXN = pow((ll)10, (ll)18);
//const ll MAXN = 20;

/*
	my functions
*/

ll cmpRes (ll base, ll M, ll N) {

	debug cerr << "base = " << base << " M = " << M << " N = " << N << endl;

	ll ans = 0;
	ll mul = 1;
	rep (i, 0, M) {
		debug {
			if (M == 2) {
				cerr << "i = " << i << endl;
				cerr << "before\n";
				cerr << ans << endl;
				cerr << mul << endl;
			}
		};
		if (mul > N || mul <= 0) return 1;
		ans += mul;
		mul *= base;
		debug {
			if (M == 2) {
				cerr << "after\n";
				cerr << ans << endl;
				cerr << mul << endl << endl;
			}
		};

		if (ans > N || ans <= 0) return 1;
	}
	if (ans > N || ans <= 0) return 1;
	debug cerr << "## N = " << N << " ans = " << ans << endl;
	return N == ans ? 0 : -1;
}

ll testBase (ll N, ll M) {
	ll low = 2, mid = -1, high;
// //	high = N;
	// if (M > 2) {
	// 	debug cerr << "????? M = " << M << endl;
	// 	high = pow(N, (double)1/(M-1));
	// } else {
	// 	high = N-1;
	// }
//
//	M = 2;
	
	// high = (M <= 2) ? (N-1) : (pow(N, (double)1/(M-1)));
	high = (M > 2) ? pow(N, (double)1/(M-1)) : (N-1);

	while (low <= high) {
		mid = low + (high - low) / 2;
		debug cerr << "low = " << low << " mid = " << mid << " high = " << high
		           << " N = " << N << " M = " << M << endl;
		int res = cmpRes(mid, M, N);
		debug cerr << "res = " << res << endl;
		if (res == 0) return mid;
		else if (res > 0) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}

void solve (int iter) {

	/* code here */
	debug cerr << "case " << iter << endl;
	readll(N)
	debug cerr << "N = " << N << endl;

	ll base;
	repp(M,62,1) {
		base = testBase(N, M);
		if (base != -1) break;
	}

	cout << "Case #" << iter << ": ";
	cout << base;
	cout << endl;
}

int main () {
	local {
		freopen("input.txt", "r", stdin);
		freopen("/Users/albertxavier/workspace/kickstart/round_c/c/cmake-build-debug/C-large-practice.in", "r", stdin);
		freopen("output.txt", "w", stdout);
	}

	readi(T);
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}
