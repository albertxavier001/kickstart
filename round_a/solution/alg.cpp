#include <cstdio>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int add(int x, int y){ return (x + y < MOD ? x + y : x + y - MOD); }
int mul(int x, int y){ return 1LL * x * y % MOD; }

int main(){
  int T; scanf("%d", &T);
  for(int tt = 1; tt <= T; tt++){
    int R, C; scanf("%d%d", &R, &C);
    R--; C--; if(R > C) swap(R, C);

    int v1 = R, v2 = R + 1, v3 = 1;
    if(v1 % 2 == 0) v1 /= 2; else v2 /= 2;

    int S1 = mul(v1, v2);

    v1 = R; v2 = R + 1; v3 = 2 * R + 1;
    if(v1 % 2 == 0) v1 /= 2; else v2 /= 2;
    if(v1 % 3 == 0) v1 /= 3; else if(v2 % 3 == 0) v2 /= 3; else v3 /= 3;

    int S2 = mul(mul(v1, v2), v3);

    int S3 = mul(S1, S1);

    int V1 = add(add(add(mul(R, C), R), C), 1);
    int V2 = R + C + 2;
    int V3 = 1;

    int M1 = mul(S1, V1);
    int M2 = mul(S2, V2);
    int M3 = mul(S3, V3);

    int ans = add(add(M1, MOD - M2), M3);

    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}
