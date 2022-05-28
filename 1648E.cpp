#define X first
#define Y second
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int randint(int l,int r){return uniform_int_distribution < int > (l,r) (rng);}
///shuffle(a.begin(), a.end(), rng)
#define int long long
const int MAX=2e5+4,inf=1e9,M=1030,mod=1e9+7;
using ii = pair < int ,int >;
void maxx(int &a,int b){if(b>a) a=b;}
void minn(int &a,int b){if(b<a) a=b;}
template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}
bool cmax(int &a,int b){
    if(b>a){a=b;return 1;} else return 0;
}
vector < ii > pr[MAX];
struct qb{
    int x,y,c;
    qb(){}
    bool operator < (const qb &o) const{
        return c<o.c;
    }
    void in(const int &id){
        cin>>x>>y>>c;
        pr[x].pb(ii(y,id));
        pr[y].pb(ii(x,id));
    }
}a[MAX];
int now;
set < int > aset[MAX];
int P[MAX],S[MAX];
int C[MAX];
int sz[MAX],pa[MAX];
vector < int > V[MAX],V2[MAX];
int Q[MAX];
int ans[MAX],nowv;
void comb2(int u,int v){
    u=P[u];v=P[v];
    if(u==v) return;
    if(S[u]>S[v]) swap(u,v);
    S[v]+=S[u];
    aset[nowv].erase(u);
    for(int z:V2[u]) {
        for(ii x:pr[z])if(P[x.X]==v)
            ans[x.Y]=now;
    }
    for(int z:V2[u])P[z]=v,V2[v].pb(z);
}
void comb(int u,int v){
    u=pa[u];v=pa[v];
    if(u==v) return;
    if(sz[u]>sz[v]) swap(u,v);
    //cout<<"st "<<u<<' '<<v<<'\n';
    sz[v]+=sz[u];
    nowv=v;
    aset[v].insert(aset[u].begin(),aset[u].end());
    for(int z:V[u]){
        //pa[z]=v;
        for(ii &x:pr[z])C[P[x.X]]++;
        int sl=0;
        //for(int x:aset[v])cout<<x<<' ';cout<<'\n';
        //for(int x:aset[v])if(C[x]!=S[x]) cout<<x<<'\n';
        for(int x:aset[v])if(C[x]!=S[x])
            Q[++sl]=x;
        for(int i=1;i<=sl;i++) comb2(z,Q[i]);
        for(ii &x:pr[z])C[P[x.X]]=0;
        pa[z]=v;V[v].pb(z);
    }
    //cout<<"end ";for(int x:aset[v])cout<<x<<' ';cout<<'\n';
}
typedef pair < int, int > ii;
signed main(){
    ///g++ grader.cpp .cpp -std=c++14 -O2 -Wl,--stack,10485760
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1648E.inp","r",stdin);freopen("1648E.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            pr[i].clear();V[i].clear();V2[i].clear();
            aset[i].clear();C[i]=0;
        }
        for(int i=1;i<=m;i++){
            a[i].in(i);
        }
        for(int i=1;i<=n;i++){
            sz[i]=pr[i].size()+1;
            pa[i]=i;V[i].pb(i);
            aset[i].insert(i);
            P[i]=i;
            S[i]=1;V2[i].pb(i);

        }
        sort(a+1,a+1+m);
        for(int i=1;i<=m;i++){
            now=a[i].c;
            comb(a[i].x,a[i].y);
        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
        cout<<'\n';


    }


}
