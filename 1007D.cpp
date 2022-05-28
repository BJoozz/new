
#define X first
#define Y second
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+4,mod=1e9+7;
void maxx(int &a,int b){if(b>a) a=b;}
using ll = long long;
void minn(ll &a,ll b){if(b<a) a=b;}
//int down(const int &id){return id^1;}
//int upd(const int &id){return id;}
const int M2=MAX*70;
vector < int > pr[MAX],V[M2],reV[M2];
bool vs[M2];
int B[M2];
//int D[MAX*4],U[MAX*4];
int node,nx,M;
int cn=0;
int P[M2];
int L[M2],R[M2];
void dfs1(int v){
    vs[v]=1;
    for(int u:V[v])if(!vs[u])
        dfs1(u);
    P[++cn]=v;
}
void dfs2(int v){
    B[v]=cn;
    for(int u:reV[v])if(!B[u])
        dfs2(u);
}

#define down(u) u^1
#define up(u) u
#define addedge(u,v) V[u].pb(v),reV[v].pb(u)
//void addedge(int u,int v){V[u].pb(v),reV[v].pb(u);cout<<u<<' '<<v<<'\n';}
void DO(int id){
    ///up(r)->down(l)
    ///up(l)->down(r)
    ///up(id)->up(pa)
    ///down(pa)->down(id)
    ///down(l==r)=l^1;
    ///upd(l==r)=l;
    //cerr<<id<<' '<<L[id]<<' '<<R[id]<<'\n';
    if(L[id]>=0){
        addedge(down(id),down(L[id]));
        addedge(up(L[id]),up(id));
    }
    if(R[id]>=0){
        addedge(down(id),down(R[id]));
        addedge(up(R[id]),up(id));
        if(L[id]>=0){
            addedge(up(R[id]),down(L[id]));
            addedge(up(L[id]),down(R[id]));
        }
    }
}
int del(int now,int l,int r){
    if(l==r) return -1;
    int id=(node+=2);
    int mid=l+r>>1;
    if(nx<=mid) {
        L[id]=del(L[now],l,mid);R[id]=R[now];
    } else {
        L[id]=L[now];R[id]=del(R[now],mid+1,r);
    }
    DO(id);
    return id;
}
int add(int now,int l,int r){
    if(l==r) return l;
    int id=(node+=2),mid=l+r>>1;
    if(nx<=mid) {
        L[id]=add(L[now],l,mid);R[id]=R[now];
    } else {
        L[id]=L[now];R[id]=add(R[now],mid+1,r);
    }
    DO(id);
    return id;
}
int build(int l,int r){
    if(l==r) return -1;
    int mid=l+r>>1,id=(node+=2);
    L[id]=build(l,mid);
    R[id]=build(mid+1,r);
    DO(id);
    return id;
}
vector < int > ad[MAX];
set < int > S[MAX];
int A[MAX];
int top[MAX];
void del(int x,int &now){
    //cerr<<"del "<<x<<"\n";
    nx=x;now=del(now,0,M);
}
void add(int x,int &now){
    //cerr<<"add "<<x<<"\n";
    nx=x;now=add(now,0,M);
}
void dfs(int v,int trc){
    int cs=0;
    for(int u:pr[v])if(u!=trc){
        dfs(u,v);
        if(S[cs].size()<S[u].size()) cs=u;
    }
    //cerr<<v<<' '<<cs<<endl;
    S[v].swap(S[cs]);
    int dem=0;
    int now=top[cs];
    for(int z:ad[v]) if(S[v].find(z)!=S[v].end()){
        S[v].erase(z);del(z,now);
    }else{
        S[v].insert(z);A[++dem]=z;
    }
    //cerr<<"xuong nao\n";
    for(int u:pr[v]) if(u!=trc && u!=cs){
        //cerr<<"st "<<u<<'\n';
        for(int z:S[u])if(S[v].find(z)!=S[v].end()){
            S[v].erase(z);del(z,now);
        }else {
            S[v].insert(z);A[++dem]=z;
        }
    }
    for(int i=1;i<=dem;i++) if(S[v].find(A[i])!=S[v].end())
    add(A[i],now);
    top[v]=now;
    //cerr<<v<<' '<<now<<' '<<node<<'\n';
}

signed main(){
    ///g++ grader.cpp .cpp -std=c++14 -O2 -Wl,--stack,10485760
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1007D.inp","r",stdin);freopen("1007D.out","w",stdout);
    int n,m;
    cin>>n;
    for(int i=1,x,y;i<n;i++){

        cin>>x>>y;
        pr[x].pb(y);
        pr[y].pb(x);
    }
    cin>>m;
    for(int i=0,x,y,u,v;i<m*2;i+=2){
        cin>>x>>y>>u>>v;
        ad[x].pb(i);
        ad[y].pb(i);
        ad[u].pb(i^1);
        ad[v].pb(i^1);
    }
    M=2*m-1;
    node=M;
    top[0]=build(0,M);//return 0;
    srand(time(0));
    int root=rand()%n+1;
    for(int u:pr[root]) dfs(u,root);


    for(int i=0;i<=node;i++)if(!vs[i])
        dfs1(i);
    int cn2=cn;cn=0;
    for(int i=cn2;i>0;i--)if(!B[P[i]])
    {cn++;dfs2(P[i]);}
    //for(int i=0;i<M;i+=2) cout<<B[i]<<' '<<B[i^1]<<'\n';
    for(int i=0;i<M;i+=2) if(B[i]==B[i^1]){
        //cout<<i<<'\n';
        cout<<"NO";return 0;
    }
    cout<<"YES\n";
    for(int i=0;i<M;i+=2)if(B[i]>B[i^1]){
        cout<<1<<'\n';
    }else cout<<2<<'\n';
}
