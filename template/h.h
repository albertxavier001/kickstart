#include <iostream>
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

#define repUpOpen(i,beg,end) for (int i = beg; i < end; ++i)
#define repUpClose(i,beg,end) for (int i = beg; i <= end; ++i)
#define repDownOpen(i,beg,end) for (int i = beg; i > end; --i)
#define repDownClose(i,beg,end) for (int i = beg; i >= end; --i)
#define pb push_back
#define readc(x) char x; cin>>x;
#define readi(x) int x; cin>>x;
#define readd(x) double x; cin>>x;

/*
	type
*/
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



/*
	common functions
*/

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

const bool debug=0;
const bool local=1;

/*
	my functions
*/

void solve (int iter) {

	/* code here */


	cout << "Case #" << iter << ": ";
	cout << endl;
}

int main () {
	if (local) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	
	readi(T);
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

