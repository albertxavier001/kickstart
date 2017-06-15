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

#define rep(i,beg,end) for (int i = beg; i < end; ++i)
#define repp(i,beg,end) for (int i = beg; i >= end; --i)
// #define repUpOpen(i,beg,end) for (int i = beg; i < end; ++i)
// #define repUpClose(i,beg,end) for (int i = beg; i <= end; ++i)
// #define repDownOpen(i,beg,end) for (int i = beg; i > end; --i)
// #define repDownClose(i,beg,end) for (int i = beg; i >= end; --i)
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

const bool debug=1;
const bool local=1;

const double MAX =  2000.0;
const double eps = 1e-6;



/*
    my functions
*/

double cost(double X, double Y, 
    vector<double> &x, 
    vector<double> &y, 
    vector<double> &w) {

    double sum = 0.;
    rep (i,0,x.size()) {
        sum+=max(fabs(x[i]-X), fabs(y[i]-Y)) * w[i];
    }
    return sum;
}


double cost(double X, 
    double miny, double maxy,
    vector<double> &x, 
    vector<double> &y, 
    vector<double> &w) {
    double low, high, mid, midd;
    low = miny, high = maxy;
    while (low + eps < high) {
        mid = low + (high - low) / 3;
        midd = low + (high - low) / 3 * 2;
        if (cost(X,mid ,x,y,w) < cost(X,midd ,x,y,w)) high = midd;
        else low = mid;
    }
    return cost(X, low, x,y,w);
}

void solve (int iter) {

    /* code here */
    readi(N)
    std::vector<double> x(N),y(N),w(N);
    double minx, miny, maxx, maxy;
    minx=miny=-MAX;
    maxx=maxy=MAX;

    rep(i,0,N) {
        cin>>x[i]>>y[i]>>w[i];
        minx=min(miny,x[i]);
        miny=min(miny,y[i]);
        maxx=max(maxx,x[i]);
        maxy=max(maxy,y[i]);
    }
    
    double low, high, mid, midd;
    low = minx; high = maxx;
    while (low + eps < high) {
        mid = low + (high - low) / 3;
        midd = low + (high - low) / 3 * 2;
        if (cost(mid, miny,maxy, x,y,w)<cost(midd, miny,maxy, x,y,w)) high = midd;
        else low = mid;
    }

    cout << "Case #" << iter << ": ";
    printf("%.2lf\n", cost(low, miny,maxy, x,y,w));
}

int main () {
    if (local) {
        freopen("B-large-practice.in", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    
    readi(T);
    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}

