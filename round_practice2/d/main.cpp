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
#include <cmath>
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
#define readll(x) long long x; cin>>x;
#define readd(x) double x; cin>>x;
#define mod (1000000007)

#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))

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


bool cmpPair(const pll &a, const pll &b) {
	if (a.first == b.first && a.second < b.second) return true;
	if (a.first < b.first) return true;
	return false;
}

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


const int MAXN = (int)1e9;

ll coverAll(vector<pll> &intervals) {

	ll cnt = 0;
	ll left = intervals[0].first;
	ll right = intervals[0].second;

	rep(i, 1, intervals.size()) {
		if (intervals[i].first > right) {
			debug cerr << "left = " << left << " right = " << right << endl;
			cnt += right - left + 1;
			left = intervals[i].first;
			right = intervals[i].second;
			continue;
		}
		if (intervals[i].second > right) {
			right = intervals[i].second;
			continue;
		}
	}
	cnt += right - left + 1;

	return cnt;
}


ll cover(vector<pll> &intervals) {
	ll tail = intervals[0].first - 1;
	ll secondTail = intervals[0].second - 1;
//	ll cnt = 0;
	vector<ll> cnts(intervals.size(), 0);
	ll ind = -1;
	rep (i, 0, intervals.size()) {
		// update cnt
		if (i > 0 && intervals[i].first > secondTail) {
			cnts[ind] += min(tail, intervals[i].first-1) - secondTail;
		}

		// update second tail
		if (tail > intervals[i].second) secondTail = max(secondTail, intervals[i].second);
		else secondTail = max(tail, intervals[i].first-1);

		// update tail
		if (intervals[i].second > tail) {
			tail = intervals[i].second;
			ind = i;
		}
	}

	cnts[ind] += tail - secondTail;

	ll maxCover = 0;

	repa(x, cnts) {
		maxCover = max(maxCover, x);
	}
	return maxCover;
}

void solve (int iter) {

	readll(N)
	readll(L1)
	readll(R1)
	readll(A)
	readll(B)
	readll(C1)
	readll(C2)
	readll(M)
	debug
		cerr << "\nN = " << N << " L1 =" << L1 << " R1 = " << R1
	     << " A = " << A << " B = " << B
	     << " C1 = " << C1 << " C2 = " << C2 << " M = " << M << endl;

	vector<pll> intervals(N);
	intervals[0].first = L1;
	intervals[0].second = R1;
	ll x = L1,y = R1,x_ = L1,y_ = R1;
	rep(i, 1, N) {
		x = (A * x_ + B * y_ + C1 ) % M;
		y = (A * y_ + B * x_ + C2 ) % M;
		debug cerr << "x = " << x << " y = " << y << endl;
		intervals[i].first = min(x, y);
		intervals[i].second = max(x, y);
		x_ = x;
		y_ = y;
	}
	sort(intervals.begin(), intervals.end());
	debug {
		cerr << "intervals = " << endl;
		repa(inv, intervals) {
			cerr << "(" << inv.first << ", " << inv.second << ")\n";
		}
	};
	ll nCoverAll = coverAll(intervals);
	ll nCover = cover(intervals);
	debug cerr << "ncoverall = " << nCoverAll << endl;
	debug cerr << "cover = " << nCover << endl;
	cout << "Case #" << iter << ": ";
	cout << (ll)(nCoverAll - nCover);
	cout << endl;
}

int main () {
	local {
		freopen("C-large-practice.in", "r", stdin);
//		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}

	readi(T);
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

