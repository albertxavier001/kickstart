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

#define debug if (1)
#define local if (1)
#define ndebug if (0)

/*
	macros
*/


#define rep(i,beg,end) for (int i = beg; i < end; ++i)
#define repp(i,beg,end) for (int i = beg; i >= end; --i)
#define repa(x,v) for (auto x: v)
// #define repUpOpen(i,beg,end) for (int i = beg; i < end; ++i)
// #define repUpClose(i,beg,end) for (int i = beg; i <= end; ++i)
// #define repDownOpen(i,beg,end) for (int i = beg; i > end; --i)
// #define repDownClose(i,beg,end) for (int i = beg; i >= end; --i)
#define pb push_back
#define readc(x) char x; cin>>x;
#define readi(x) int x; cin>>x;
#define readd(x) double x; cin>>x;
#define mod (1000000007)

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

bool lineOk (int i, int beg, int end, gridc &mat) {
	int n = mat.size(), m = mat[0].size();
	if (i < 0 || i >= n || beg < 0 || beg >= m || end < 0 || end >= m) return false;
	rep (j, beg, end+1) {
		if (mat[i][j] == '.') return false;
	}
	return true;
}


void solve (int iter) {

	/* code here */
	readi(N)
	readi(M)
	readi(K)
	gridc mat(N, vecc(M));
	cubei dp(N+1, gridi(M, veci(K+1, 0)));
	cubeb can(N, gridb(M, vecb(M, 0)));
	rep(i,0,N) rep (j,0,M) cin >> mat[i][j];

	int maxCell = 0;
	rep (i,0,N) {
		rep (j,0,M) {
			// start (i,j)
			if (mat[i][j] == '.') continue; 
			rep (k,1,K+1) {
				// grow tree
				if (dp[i][j][k-1] == 0 && k-1>0) continue; 
				rep (rad,0,M+1) {
					int h = i+rad;
					bool ok = lineOk(h, j-rad, j+rad, mat);
					if (!ok) break;
					// segment
					if (h+1 > N || k == 0) continue;
					rep (x, j-rad, j+rad+1) {
						ndebug {
							cout << "k = " << k << " i = " << i << " j = " << j;
							cout << " h = " << h <<" x = "<< x << "\n";
						}
						dp[h+1][x][k] = max(dp[i][j][k-1]+(rad+1)*(rad+1), dp[h+1][x][k]);
						if (k == K) maxCell = max(maxCell, dp[h+1][x][k]);
					}
				}
			ndebug {cout << "??" << endl;}
			}
		}
	}


	ndebug {
		rep (k,0,K+1) {
			cout << "k = " << k << endl;
			rep (i,0,N) {
				rep (j,0,M) {
					cout << dp[i][j][k] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
	}

	cout << "Case #" << iter << ": ";
	cout << maxCell;
	cout << endl;
}

int main () {
	local {
		// freopen("input.txt", "r", stdin);
		freopen("C-large-practice.in", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	
	readi(T);
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

