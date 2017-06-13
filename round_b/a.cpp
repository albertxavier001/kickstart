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
#define MOD (1000000007)

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

int C(int m, int n) {
    if (m==0) return 1;
    int fz, fm;
    fz=fm=1;
    repDownClose(i,n,m+1) {
        fz *= i;
    }

    repDownClose(i,n-m,1) {
        fm *= i;
    }

    return fz/fm;
}


void solve (int iter) {

    /* code here */
    readi(N)
    std::vector<int> a(N);

    repUpOpen(i,0,N) {
        cin >> a[i];
    }

    int sum = 0;

    repUpClose(k,2,N) {
        repUpClose(j,0,N-2) {
            repUpClose(i,1,N-1) {
                if (i-j<k-1) continue;
                int c = C(k-2,i-j-1);
                sum += (a[i]-a[j])*c;
                if (debug) {
                    cout << "i = " << i << " j = " << j << endl;
                    cout << "c = " << c << endl;
                    cout << "a = " << a[i] << endl;
                    cout << "b = " << a[j] << endl << endl;

                }
            }
        }

        if (debug) {
            cout << "k = " << k;
            cout << " sum = " << sum << endl;
        }
    }

    cout << "Case #" << iter << ": " << sum;
    cout << endl;
}

int main () {
    if (local) {
        freopen("A-large-practice.in", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    
    readi(T);
    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}

