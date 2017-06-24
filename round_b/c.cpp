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

typedef std::vector<std::vector<char> > gridc;
typedef std::vector<std::vector<int> > gridi;
typedef std::vector<std::vector<double> > gridd;


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

int tri(int si, int sj, gridc &m) {
	debug {if(si == 4 && sj == 16) cout << "si = " << si << " sj = " << sj << endl;}
	int h = 0, s = sj, e = sj;
	while (1) {
		debug {if (si == 4 && sj == 16) cout << "s = " << s << " e = " << e << " h = " << h << endl;}
		rep(j,s,e+1) {
			if (s < 0 || e >= m[0].size() || h+si >= m.size()) {
				debug {if (si == 4 && sj == 16) cout << "outside\n";} 
				return h;
			}
			if (m[h+si][j] == '.') { 
				debug {if (si == 4 && sj == 16) cout << "is . " << "h = " << h << " s = " << s << " e = " << e << endl;} 
				return h;
			}
		}
		s--; e++; h++;
	} 
	return h;
}


int ma(gridc &m) {
	int maxnum = 0;
	rep(i,0,m.size()) {
		rep(j,0,m[0].size()) {
			int h = tri(i,j,m); 
			// debug {cout << "h = " << h << endl;} 
			maxnum = max(maxnum, h*h);
		}
	}
	return maxnum;
}

void solve (int iter) {

	/* code here */
	readi(N)
	readi(M)
	readi(K)
	vector<vector<char> > m(N, vector<char>(M));
	rep(i,0,N) {
		rep(j,0,M) {
			cin >> m[i][j];
		}
	}

	debug {
		cout << "T = " << iter << endl; 
		repa(row, m) {
			repa(x, row) {
				cout << x;
			}
			cout << endl;
		}
	}

	int num = ma(m);

	cout << "Case #" << iter << ": ";
	cout << num;
	cout << endl;
}

int main () {
	local {
		// freopen("./input.txt", "r", stdin);
		freopen("./C-small-practice.in", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	
	readi(T);
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

