#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define X first
#define Y second
#define int long long
template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}
template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}
void maxx(int &a,int b){if(b>a) a=b;}
void minn(int &a,int b){if(b<a) a=b;}
mt19937 rng(time(0));
int randint(int l,int r){
    return uniform_int_distribution < int > (l,r) (rng);
}
using ll = long long;
using ii = pair < int , int >;
const int MAX=150+3,inf=1e9,M=1e6+2,mod=1e9+7;
vector < int > pr[MAX];
int N;
int F[MAX];

bool vs[MAX];
void upd(int id,int val){
    for(;id<MAX;id+=id&-id) F[id]+=val;
}
void pop(int id,int val){
    for(;id<MAX;id+=id&-id) F[id]-=val;
}
int get(int id){
    int res=0;
    for(;id>0;id-=id&-id) res+=F[id];
    return res;
}
int a[MAX],B[MAX],B2[MAX];
vector < int > V;
vector < int > vec;
int id(int i) {
    if (i > 0) return 2 * i - 1;
    return -2 * i;
}

void addEdge(int u, int v) {
    adj[id(-u)].push_back(id(v));
    adj[id(-v)].push_back(id(u));
    rev[id(v)].push_back(id(-u));
    rev[id(u)].push_back(id(-v));
}
void init( ) {
    int LG=__lg(S),n=0,res=0;
        vec.clear();
        for(int i=1;i<=130;i++) vec.pb(i);

        if(randint(0,5)!=1) {
            int z=max(0LL,LG+randint(-20,10));
            shuffle(vec.begin()+z,vec.begin()+LG+21,rng);
        }
        else{
            if(randint(0,3)!=1) shuffle(vec.begin()+LG+randint(-10,10),vec.begin()+LG+21,rng);
            int Q=randint(4,15);
            while(Q--){
                int x=randint(1,90);
                swap(vec[x],vec[x-1]);
            }
        }
}
void dfs1(int u) {
    vis[u] = 1;
    for (int v : adj[u])
        if (!vis[v]) dfs1(v);
    ord.push_back(u);
}

void dfs2(int u, int cc) {
    comp[u] = cc;
    for (int v : rev[u])
        if (!comp[v]) dfs2(v, cc);
}
int letgo(int S){

        for(int k:vec)if(res<S){

            int t2=1;
            for(int i=1;i<=n;i++)
                if(a[i]>k) t2+=B2[i];
            int temp=1,cs=0,rmax=res;
            if(res+t2<=S){
                rmax=res+t2;cs=1;
            }
            for(int i=1;i<=n;i++){
                if(a[i]<k) temp+=B[i];
                else t2-=B2[i];
                if(res+temp*t2<=S && cmax(rmax,res+temp*t2))
                    cs=i+1;
            }
            //cout<<n<<' '<<temp<<'\n';
            if(!cs) continue;
            res=rmax;
            for(int i=n+1;i>cs;i--)a[i]=a[i-1];
            a[cs]=k;

            ++n;
            memset(F,0,sizeof F);
            for(int i=1;i<=n;i++){
                B[i]=get(a[i])+1;
                upd(a[i],B[i]);
            }
            memset(F,0,sizeof F);
            for(int i=n;i>0;i--){
                B2[i]=get(MAX-a[i])+1;
                upd(MAX-a[i],B2[i]);
            }

        }
        int ans=0;
        memset(F,0,sizeof F);
        for(int i=1,x;i<=n;i++){
            x=get(a[i])+1;
            upd(a[i],x);
            ans+=x;
        }
        if(ans!=res){
            cout<<"WA\n";exit(0);
        }
        return n;
}
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
signed main(){
    ///g++ grader.cpp .cpp -std=c++14 -O2 -Wl,--stack,10485760
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("bao.inp","r",stdin);
    //freopen("bao.out","w",stdout);
    //-Wl,--stack,10485760

    for(int kk=1;kk<=1000;kk++){
        int S=kk;
        S=randint(3e17,1e18);
        cin>>S;
        int Q=500;
        int best=150;
        while(Q--){
            minn(best,letgo(S));
        }
    }
}

