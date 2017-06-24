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
#define readc(x) char x; cin>>x;
#define reads(x) string x; cin>>x;
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


void solve (int iter) {

    /* code here */

    reads(lights)
    ll n = lights.size();
    ll cnt = 0;
    for (auto li: lights) {if (li == 'B') cnt++;}
    ll I, J;
    cin >> I >> J;
    I--,J--;
    ll repeat = (J-I)/ n;
    ll total = cnt * repeat;
    ll beg, end;
    beg = I % n;
    end = J % n;
    lights += lights;
    if (end < beg) end += n; 
    if (beg <= end) {
    	rep (i, beg, end+1) {
    		if (lights[i%n] == 'B') total++;
    	}
    }

    cout << "Case #" << iter << ": ";
    cout << total;
    cout << endl;
}

int main () {
    local {
        freopen("A-large-practice.in", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    readi(T);
    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}

