#define X first
#define Y second
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define bit(s,i) ((s >> i) & 1)
using ii = pair < int , int >;
const int MAX=120000+2,inf=1e16,mod=1e9+7;
void PL(int &a,int b){a+=b;if(a>=mod) a-=mod;}
using ll = long long;
queue < int > pr[MAX];
bool th[MAX];
bool vs[MAX];
int a[MAX];
bool A[MAX];
int cs[MAX];
int n;
bool all;
void dfs(int v){
    vs[v]=1;
    queue < int > &Q=pr[v];
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        if(!th[u]){
            th[u]=th[4*n+1-u]=1;
            dfs(a[u]);
            all=!all;
            A[u]=A[4*n+1-u]=all;
        }
    }
}


const int maxn = 3e5 + 5;

struct node {
    int dis , mask , ty;
    node(){}
    node(int dis,int mask,int ty):
    dis(dis) , mask(mask) , ty(ty){}
};

node pre[35][35 * 35 * 4 * 4];

int  m[maxn] , c[maxn];
vector < int > vc[maxn];
bool dp[35][35 * 35 * 4 * 4];

void solve() {
    for (int i = 1 ; i <= 4 * n ; ++i) {
        cin >> m[i] >> c[i];
        vc[c[i]].push_back(i);
    }
    vector < int > mss;
    for (int mask = 0 ; mask < (1 << 4) ; ++mask)
    if (__builtin_popcount(mask) == 2) mss.push_back(mask);
    dp[0][0] = 1;
    for (int i = 0 ; i < n ; ++i)
    for (int dis = 0 ; dis <= 16 * i * i ; ++dis) {
        for (auto mask : mss) {
            int sum1 = 0 , sum2 = 0;
            for (int j = 0 ; j < 4 ; ++j)
            if (bit(mask , j)) sum1 += m[vc[i + 1][j]];
            else sum2 += m[vc[i + 1][j]];
            if (dis + sum1 - sum2 >= 0) {
                if (dp[i + 1][dis + sum1 - sum2] == 0 && dp[i][dis] == 1)
                    pre[i + 1][dis + sum1 - sum2] = node(dis , mask , 0);
                dp[i + 1][dis + sum1 - sum2] |= dp[i][dis];
            } else {
                if (dp[i + 1][sum2 - sum1 - dis] == 0 && dp[i][dis] == 1)
                    pre[i + 1][sum2 - sum1 - dis]  = node(dis , mask , 1);
                dp[i + 1][sum2 - sum1 - dis] |= dp[i][dis];
            }
        }
    }
    int res = 0;
    for (int dis = 0 ; dis <= 16 * n * n ; ++dis)
    if (dp[n][dis]) {
        res = dis;
        break;
    }
    vector < int > v1 , v2;
    while (n > 0) {
        node x = pre[n][res];
        int mask = pre[n][res].mask;
        int ty = pre[n][res].ty;
        for (int j = 0 ; j < 4 ; ++j)
        if (bit(mask , j)) v1.push_back(vc[n][j]);
        else v2.push_back(vc[n][j]);
        if (ty) swap(v1 , v2);
        res = pre[n][res].dis;
        n--;
    }
    for (auto v : v1) cout << v << ' ';
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("stones.inp","r",stdin);
    //freopen("stones.out","w",stdout);

    cin>>n;
    if(n<=30){
        solve();return 0;
    }
    for(int i=1,x,y;i<=n*4;i++){
        cin>>x>>y;
        a[x]=y;
        cs[x]=i;
    }
    for(int i=1;i<=2*n;i++){
        pr[a[i]].push(4*n-i+1);
        pr[a[4*n-i+1]].push(i);
    }
    for(int i=1;i<=n;i++)if(!vs[i])dfs(i);
    vector < int > ans;
    for(int i=1;i<=4*n;i++)if(A[i]){
        ans.pb(cs[i]);
    }
    sort(ans.begin(),ans.end());
    for(int u:ans) cout<<u<<' ';
    //cout<<'\n';for(int u:ans) cout<<a[u]<<' ';
}
