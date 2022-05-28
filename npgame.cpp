#define X first
#define Y second
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
#define int long long
using ii = pair < int , int >;
const int MAX=500+2,inf=1e18,mod=1e9+7;
void PL(int &a,int b){a+=b;if(a>=mod) a-=mod;}
using ll = long long;
vector < int > pr[MAX],ad[MAX];
bool vs[MAX];
int L[MAX],R[MAX];
int now=0;
bool GO(int v){
    if(vs[v]) return 0;
    vs[v]=1;
    for(int u:pr[v])if(R[u]){
        if(GO(R[u])) {
            L[v]=u;
            R[u]=v;return 1;
        }
    }else if(u!=now){
        L[v]=u;
        R[u]=v;return 1;
    }
    return 0;
}

bool GO2(int v){
    if(vs[v]) return 0;
    vs[v]=1;
    for(int u:ad[v])if(L[u]){
        if(GO2(L[u])) {
            R[v]=u;
            L[u]=v;return 1;
        }
    }else if(u!=now){
        R[v]=u;
        L[u]=v;return 1;
    }
    return 0;
}
bool ok(int v){
    memset(vs,0,sizeof vs);
    now=v;
    int u=L[v];
    L[v]=0;R[u]=0;
    if(GO2(u))
        return 0;
    else {
        L[v]=u;
        R[u]=v;
        return 1;
    }
}
bool ok2(int v){
    memset(vs,0,sizeof vs);
    now=v;
    int u=R[v];
    R[v]=0;L[u]=0;
    if(GO(u))
        return 0;
    else {
        R[v]=u;
        L[u]=v;
        return 1;
    }
}
signed main(){

    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("dancer2.inp","r",stdin);
    //freopen("dancer2.out","w",stdout);
    int n,m,K,x,y;
    cin>>n>>m>>K;
    while(K--){
        cin>>x>>y;
        pr[x].pb(y);ad[y].pb(x);
    }
    for(int i=1;i<=n;i++){
        if(GO(i)){
            memset(vs,0,sizeof vs);
        }
    }
    string ans;
    for(int i=1;i<=n;i++)if(L[i] && ok(i)){
        ans+='N';
    }else ans+='P';
    ans+="\n";
    for(int i=1;i<=m;i++)if(R[i] && ok2(i)){
        ans+='N';
    }else ans+='P';
    cout<<ans;
}
