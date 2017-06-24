#include <bits/stdc++.h>
#include <direct.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second


const int alp=26;
const int N=1e2+5;
const int MOD=1e9+7;
const int inf=1e8;



int n,m,k;
string s[N];
int tr[N][N][N];
int f[N][N][N];
int q[N];

void prepare(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) cin>>s[i];

    memset(tr,0,sizeof(tr));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) tr[0][i][j]=s[i][j]=='#';
    for(int lv=1;lv<n;lv++)
        for(int i=0;i<n-lv;i++)
            for(int j=lv;j<m-lv;j++)
                tr[lv][i][j]=(s[i][j]=='#'&&tr[lv-1][i+1][j-1]&&tr[lv-1][i+1][j]&&tr[lv-1][i+1][j+1]);
}
int solve(){
    int ans=0;
    memset(f,0,sizeof(f));
    for(int lv=1;lv<=k;lv++){
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) f[lv][i][j]=-inf;
        for(int i=0;i<=n-lv;i++)
            for(int depth=0;i+depth+lv-1<n;depth++){
                int top=1,bot=0;
                for(int j=depth,en=0;j<m-depth;j++){
                    if (top<=bot&&q[top]<j-depth) top++;
                    while (en<=min(j+depth,m-1)){
                        while (top<=bot&&f[lv-1][i+depth+1][en]>=f[lv-1][i+depth+1][q[bot]]) bot--;
                        q[++bot]=en++;
                    }
                    if (tr[depth][i][j]) f[lv][i][j]=max(f[lv][i][j],f[lv-1][i+depth+1][q[top]]+(depth+1)*(depth+1));
                }
            }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) ans=max(ans,f[k][i][j]);
    return ans;
}
int main(){
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int test;
    cin>>test;
    for(int te=1;te<=test;te++){
        prepare();
        cout<<"Case #"<<te<<": "<<solve()<<'\n';
    }
}
