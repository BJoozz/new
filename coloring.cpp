#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pb push_back
using ll =long long;
const int inf=1e9,MAX=1003;
void minn(int &a,int b){if(b<a) a=b;}
#define cnt(u) __builtin_popcount(u)
using ii = pair < int , int >;
vector < int > pr[MAX];
vector < ll > vec;
ll getd(ii u,ii v){
    return 1LL*(u.X-v.X)*(u.X-v.X)+1LL*(u.Y-v.Y)*(u.Y-v.Y);
}
int n,m;
ll dis[MAX][MAX];
short hav[MAX];
set < int > S[6];
int rans(set < int > &S){
    int u=rand()%(*S.rbegin());
    return *S.lower_bound(u);
}
int col[MAX];
bool ch(){
    for(int i=1;i<m;i++) S[i].clear();
    for(int i=1;i<=n;i++) {
        col[i]=0;
        hav[i]=((1<<m)-1)<<1;
        S[m].insert(i);
    }
    int Q=n;
    vector < int > V1;
    for(int i=1;i<=m;i++) V1.pb(i);
    while(Q--){
        int cs=0;
        for(int u=1;u<=m;u++)if(!S[u].empty()){
            cs=rans(S[u]);
            S[u].erase(cs);break;
        }
        if(!cs) return 0;
        //random_shuffle(V1.begin(),V1.end());
        int co;
        for(int i:V1)if(hav[cs]&(1<<i)){
            co=i;break;
        }
        col[cs]=co;//cout<<cs<<' '<<co<<'\n';
        for(int u:pr[cs])if(!col[u]){
            if(hav[u]&(1<<co)){
                S[cnt(hav[u])].erase(u);
                hav[u]^=(1<<co);
                S[cnt(hav[u])].insert(u);
            }
        }
    }
    return 1;
}
bool ok(){
    for(int i=1;i<=30;i++)if(ch()){
        return 1;
    }
    return 0;
}
ii a[MAX];
int A[MAX];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("coloring.inp", "r", stdin);freopen("coloring.out", "w", stdout);
    //cin>>n>>m>>K;
    for(int i=1;i<=1221;i++) rand();
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].X>>a[i].Y;
        for(int j=1;j<i;j++){
            dis[i][j]=dis[j][i]=getd(a[i],a[j]);
            vec.pb(dis[i][j]);
        }
    }
    sort(vec.begin(),vec.end());
    int b=0,e=int(vec.size())-1;
    ll ans=0;
    while(b<=e){
        ll lim=vec[b+e>>1];
        for(int i=1;i<=n;i++) pr[i].clear();
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++)if(dis[i][j]<lim){
                pr[i].pb(j);pr[j].pb(i);
            }
        }
        if(ok()){
            b=(b+e>>1)+1;
            ans=lim;
            //cout<<ans<<'\n';
            for(int i=1;i<=n;i++) A[i]=col[i];
        }
        else{
            e=(b+e>>1)-1;
        }
    }
    //cout<<ans<<'\n';
    for(int i=1;i<=n;i++) cout<<A[i]<<' ';
}

