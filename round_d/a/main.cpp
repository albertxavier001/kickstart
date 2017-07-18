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


template <class T>
void printMatrix(vector<vector<T> > &m) {
	for (auto l: m) {
		for (auto e: l) {
			cerr << e << " ";
		}
		cerr << endl;
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


const int inf = 1e9;

void solve (int iter) {

	/* code here */
	readi(N) readi(Ts) readi(Tf)
	veci Si(N+1,-1), Fi(N+1,-1), Di(N+1,-1);
	rep(i,1,N) cin >> Si[i] >> Fi[i] >> Di[i];

	new_gridi(dp, N+1, Tf+1, -1);
	rep(i,0,dp[0].size()) {
		dp[0][i] = 0;
	}
	Si[0] = Fi[0] = Di[0] = 0;
	Fi[0] = 1;
//	for (int i = Ts; i <= Tf; i++) {
//		dp[0][i] = 1;
//	}

	rep (c,0,N) {
		rep(arrive,0,Tf+1) {
//			rep(leave,0,inf) {
				if (dp[c][arrive] < 0) continue;
				int k = 0;
				if (c >= 1 && arrive >= Si[c]) {
					k = (arrive-Si[c])/Fi[c];
				}
				int leave = k * Fi[c] + Si[c];
				if (leave < arrive) leave += Fi[c];
//				debug cerr << " leave start = " << leave << endl;
//				for (int K = leave; K <= Tf; K+=Fi[c]) {
////						if (K+Di[c] <= Tf ) dp[c+1][K+Di[c]] = 0;
//					debug cerr << " c = " << c << " arrive = " << arrive << endl;
//					debug cerr << " K = " << K << endl;
//					int nextArrive = K+Di[c];
//					if (nextArrive < 0) continue;
////					if (nextArrive <= arrive) continue;
//					debug {
//						if (c==1&&arrive==6) {
//							cerr << "dp = " << dp[c][arrive] << endl;
//							cerr<<"aa"<<endl;
//						}
//					};
//					debug {
//						if (c+1==1 && nextArrive == 6) {
//							cerr << "xx\n";
//						}
//					};
//
//					if (nextArrive <= Tf && c > 0) dp[c+1][nextArrive] = max(dp[c+1][nextArrive], dp[c][arrive] + (int)(K-arrive>=Ts?1:0));
//					else if (nextArrive <= Tf) dp[c+1][K+Di[c]] = dp[c][arrive];
//				}

//			}
		}
	}


	debug {
		cerr << "dp"<<endl;
		printMatrix(dp);
	}
	int ret = -1;
	rep(i,0,Tf+1){
		ret = max(ret, dp[N][i]);
	}


//	if (ret == N) ret--;
	cout << "Case #" << iter << ": ";
	if (ret ==-1) cout << "IMPOSSIBLE";
	else cout << ret;
	cout << endl;
}



int main () {
	local {
		freopen("input.txt", "r", stdin);
		 freopen("A-small-attempt2.in", "r", stdin);
		 freopen("A-large.in", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	
	readi(T);
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

