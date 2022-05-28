
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define X first
#define Y second
#define pb push_back
#define pf push_front
using ii = pair < int , int >;
const int MAX=2e5+100,M=2e5+1,inf=1e9,mod=9e15+7;
bool cmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
bool cmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
void maxx(int &a,int b){if(b>a)a=b;}
void minn(int &a,int b){if(b<a)a=b;}
using ll = long long;

vector < int > V[MAX*4],Sc[MAX*4],Sr[MAX*4];

int C[MAX],R[MAX],d[MAX];
int memc[MAX],memr[MAX];
int t[MAX],h[MAX];
using VI = vector < int >;
void comb(VI & vec,VI &V1, VI &V2){
    int po=0,sz=V2.size();
    for(int u:V1){
        while(po!=sz && V2[po]<u){
            vec.pb(V2[po]);po++;
        }
        if(po==sz || V2[po]!=u)vec.pb(u);
    }
    while(po<sz) vec.pb(V2[po++]);
}
int nx,val,lim;
void build(int id,int l,int r){
    if(l==r){
        V[id].pb(d[l]);
        Sc[id]={0,C[l]};
        Sr[id]={R[l],0};
        return;
    }
    int mid=l+r>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    comb(V[id],V[id<<1],V[id<<1|1]);
    /// >= r
    /// < c
    auto &nc=Sc[id],&nr=Sr[id],&nv=V[id];
    int sz=nv.size();
    nc.resize(sz+1);
    nr.resize(sz+1);
    for(int i=l,x;i<=r;i++){
        memc[d[i]]+=C[i];
        memr[d[i]]+=R[i];
        nc[sz]+=C[i];
    }
    for(int i=sz-1;i>=0;i--){
        nc[i]=nc[i+1]-memc[nv[i]];
        nr[i]=nr[i+1]+memr[nv[i]];
        memc[nv[i]]=memr[nv[i]]=0;
    }
}
int pos;
int tim[MAX],L[MAX],nex[MAX];



void get(int id,int l,int r){
    if(l>=nx){
        int z=lower_bound(V[id].begin(),V[id].end(),lim)-V[id].begin();
        z=Sc[id][z]+Sr[id][z]*lim;
        if(val>z){
            val-=z;pos=r;return;
        }
        if(l==r) return;
    }
    int mid=l+r>>1;
    if(mid>=nx) get(id<<1,l,mid);
    if(pos>=mid) get(id<<1|1,mid+1,r);
}

int n,m;
//priority_queue < int , vector < int > , greater < int > > ad[MAX];
vector < int > ad[MAX];
bool vs[MAX];
int h2[MAX];
void put(int v){
    if(tim[v]==n){
        h2[v]=-h[v];return;
    }
    nx=tim[v]+1,val=h[v],lim=t[v]-t[L[v]];
    //cerr<<"st "<<v<<endl;
    //cerr<<nx<<' '<<val<<' '<<lim<<'\n';
    pos=tim[v];
    //pos=0;
    get(1,1,n);
    ad[pos+1].pb(v);
    h2[v]=min(C[pos+1],R[pos+1]*lim)-val;
    //cerr<<"en "<<v<<' '<<pos<<' '<<val<<' '<<h2[v]<<'\n';
}
int now,ny;
void get2(int id,int l,int r){
    if(nx<=l && r<=ny){
        int z=lower_bound(V[id].begin(),V[id].end(),lim)-V[id].begin();
        z=Sc[id][z]+Sr[id][z]*lim;
        val+=z;return;
    }
    int mid=l+r>>1;
    if(mid>=nx) get2(id<<1,l,mid);
    if(mid<ny) get2(id<<1|1,mid+1,r);
}
void pop(int u){
    //cerr<<u<<' '<<h2[u]<<'\n';
    vs[u]=1;
    L[nex[u]]=L[u];
    nex[L[u]]=nex[u];
    if(nex[u]>m) return;
    int v=nex[u];
    nx=tim[v]+1;ny=now-1;lim=t[v]-t[u];
    if(nx<=ny){
        val=0;
        get2(1,1,n);
        h[v]-=val;
    }
    h[v]-=min(C[now],R[now]*lim+h2[u]);
    tim[v]=now;
    //cerr<<v<<' '<<h[v]<<'\n';
    if(h[v]<=0){
        h2[v]=-h[v];
        pop(v);
    }else put(v);
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("1651F.inp","r",stdin);freopen("1651F.out","w",stdout);
    //cout<<__lg(inf);return 0;
    //srand(time(0));
    /*vector < int > bao={1,2,3};
    int cs=lower_bound(bao.begin(),bao.end(),1000)-bao.begin();
    cout<<cs;return 0;*/
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>C[i]>>R[i];
        d[i]=min(C[i]/R[i],M);

    }
    build(1,1,n);
    cin>>m;

    t[0]=-M;
    for(int i=1;i<=m;i++){
        cin>>t[i]>>h[i];
        L[i]=i-1;nex[i]=i+1;
        put(i);
    }
    //return 0;
    for(int i=1;i<=n;i++){
        now=i;
        sort(ad[i].begin(),ad[i].end());
        for(int u:ad[i])if(!vs[u]){
            pop(u);
        }
    }
    int ans=0;
    for(int i=1;i<=m;i++) if(!vs[i]){
        //cout<<i<<' '<<-h2[i]<<'\n';
        ans-=h2[i];
    }
    cout<<ans;
}
