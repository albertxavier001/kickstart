// #include <bits/stdc++.h>
// #define IOS ios_base::sync_with_stdio(0); cin.tie(0);
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

typedef long long ll;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll mod = (ll)(1e9 + 7);
const int MAX_N = 100010;
int T, n, cases = 0;
int data[MAX_N];
ll pw[MAX_N];
int main() { 
     // freopen("input.txt", "r", stdin);
        freopen("A-large-practice.in", "r", stdin);
        freopen("output.txt", "w", stdout);
    pw[0] = 1;
    for (int i = 1; i < MAX_N; ++i) pw[i] = pw[i - 1] * 2 % mod;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &data[i]);
        sort(data, data + n);
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int diff = j - i - 1;
                ans = (ans + 1ll * (data[j] - data[i]) * pw[diff] % mod) % mod;
            }
        }
        
        printf("Case #%d: %lld\n", ++cases, ans);
    }
    return 0;
}