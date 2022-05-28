#define X first
#define Y second
#define pb push_back

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX=150000+4,inf=1e9,M=1030,mod=1e9+7;
using ii = pair < int ,int >;
using ll = long long;
void maxx(int &a,int b){if(b>a) a=b;}
void minn(int &a,int b){if(b<a) a=b;}
template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}
bool cmax(int &a,int b){
    if(b>a){a=b;return 1;} else return 0;
}
int D[MAX];
int dp[302][MAX];
signed main(){
    ///g++ grader.cpp .cpp -std=c++14 -O2 -Wl,--stack,10485760
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    ll DIS;
    map < int , vector < int > > V;
    cin>>n>>m>>DIS;
    int ans=0;
    for(int i=1,x,y,c;i<=m;i++){
        cin>>x>>y>>c;
        ans+=y;
        V[c].pb(x);
    }
    int pre=0,cn=0;
    for(auto P:V){
        ++cn;
        auto &A=dp[cn-1];
        int top=-1,bot=0;
        int dis=min(DIS*(P.X-pre),n);
        pre=P.X;
        //cout<<dis<<'\n';//
        A[0]=-inf;
        for(int i=1;i<=n;i++){
            while(top >= bot && A[i]>A[D[top]]) top--;
            D[++top]=i;
            while(D[bot]<i-dis) bot++;
            dp[cn][i]=A[D[bot]];
        }
        top=-1,bot=0;D[0]=0;
        for(int i=n;i>0;i--){
            while(top >= bot && A[i]>A[D[top]]) top--;
            D[++top]=i;
            while(D[bot]>i+dis)
                    bot++;
            maxx(dp[cn][i],A[D[bot]]);
        }
        for(int u:P.Y){
            for(int i=1;i<=u;i++) dp[cn][i]-=u-i;
            for(int i=u;i<=n;i++) dp[cn][i]-=i-u;
        }
    }
    int res=-inf;
    for(int i=1;i<=n;i++) maxx(res,dp[cn][i]);
    cout<<ans+res;
}
