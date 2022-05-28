#define X first
#define Y second
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
#define int long long
using ii = pair < int , int >;
const int MAX=100000+2,inf=1e18,mod=1e9+7;
void PL(int &a,int b){a+=b;if(a>=mod) a-=mod;}
using ll = long long;
vector < int > pr[MAX];
queue < int > Q[MAX];
bool vs[MAX];
int sz[MAX];
int lim;
void dfs(int v,int pa){
    sz[v]=1;
    for(int u:pr[v])if(u!=pa){
        dfs(u,v);sz[v]+=sz[u];
    }
}
int fincen(int v,int pa){
    for(int u:pr[v])if(u!=pa && sz[u]>lim)
        return fincen(u,v);
    return v;
}
ll Smax=0,Smin=0;
int S[MAX],P[MAX],pa[MAX],in[MAX],out[MAX],h[MAX];
int now;
void DFS(int v,int paa){
    sz[v]=1;
    Smax+=h[v];
    int &z=S[v];
    for(int u:pr[v])if(u!=paa){
        h[u]=h[v]+1;
        DFS(u,v);
        pa[u]=v;
        sz[v]+=sz[u];
        if(sz[u]>sz[z]) z=u;
        Smin+=(sz[u]&1);
    }
    Q[now].push(v);
}
int tim=0;
void dfshld(int v,int pa){
    in[v]=++tim;
    if(S[v]){
        P[S[v]]=P[v];
        dfshld(S[v],v);
        for(int u:pr[v])if(u!=pa && u!=S[v]){
            P[u]=u;
            dfshld(u,v);
        }
    }
    out[v]=tim;
}
int r,n,K;
int a[MAX],b[MAX];
int nex[MAX];
bool cmp(int u,int v){
    return sz[u]>sz[v];
}
int ST[MAX*4];
bool LZ[MAX*4];
int nowx,nowy;
int get(int id,int l,int r){
    if(nowx>r || nowy<l) return 0;
    if(nowx<=l && r<=nowy)
        return ST[id];
    int mid=l+r>>1;
    if(LZ[id]){
        LZ[id<<1]^=1;ST[id<<1]=mid-l+1-ST[id<<1];
        LZ[id<<1|1]^=1;ST[id<<1|1]=r-mid-ST[id<<1|1];
        LZ[id]=0;
    }
    return get(id<<1,l,mid)+get(id<<1|1,mid+1,r);
}
int get(int x,int y){
    nowx=x;nowy=y;
    return get(1,1,n);
}
void upd(int id,int l,int r){
    if(nowx<=l && r<=nowy){
        ST[id]=r-l+1-ST[id];
        LZ[id]^=1;return;
    }
    int mid=l+r>>1;
    if(LZ[id]){
        LZ[id<<1]^=1;ST[id<<1]=mid-l+1-ST[id<<1];
        LZ[id<<1|1]^=1;ST[id<<1|1]=r-mid-ST[id<<1|1];
        LZ[id]=0;
    }
    if(mid>=nowx)upd(id<<1,l,mid);
    if(mid<nowy) upd(id<<1|1,mid+1,r);
    ST[id]=ST[id<<1]+ST[id<<1|1];
}
void upd(int x,int y){
    nowx=x;nowy=y;
    upd(1,1,n);
}
void upd(int u){
    int x=u;
    while(x!=r){
        int z=P[x];
        if(z==r){
            upd(in[z]+1,in[x]);
            break;
        }
        else{
            upd(in[z],in[x]);
            x=pa[z];
        }
    }
}

int cnt(int u){
    int x=u,res=0;
    while(x!=r){
        int z=P[x];
        if(z==r){
            res+=get(in[z]+1,in[x]);
            break;
        }
        else{
            res+=get(in[z],in[x]);
            x=pa[z];
        }
    }
    res=res*2-h[u];
    return res;
}
bool ok[MAX];
vector < ii > ans;
void TRY(int u,int v){
    ///cnt=sl(1)-sl(0);

    int res=cnt(u)+cnt(v);
    //cout<<"oop "<<u<<' '<<v<<' '<<res<<'\n';
    if(K-h[u]-h[v]>=Smin-res){
        upd(u);upd(v);
        K-=h[u]+h[v];Smin-=res;
        //cout<<u<<' '<<v<<'\n';
        ans.pb(ii(u,v));ok[u]=ok[v]=1;
    }
    else{
        if(v!=r) TRY(pa[v],u);
        else TRY(pa[u],v);
    }

    return ;
}
int solve(int v,int pa){
    int pre=0;
    if(!ok[v])pre=v;
    //cout<<v<<' '<<pre<<'\n';
    for(int u:pr[v])if(u!=pa){
        int x=solve(u,v);
        if(x){
            if(pre) {
                cout<<pre<<' '<<x<<'\n';
                pre=0;
            }
            else pre=x;
        }
    }
    return pre;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1396E.inp","r",stdin);
    //freopen("1396E.out","w",stdout);
    cin>>n>>K;
    for(int i=1,x,y;i<n;i++){
        cin>>x>>y;
        pr[x].pb(y);
        pr[y].pb(x);
    }
    dfs(1,0);
    lim=n/2;
    r=fincen(1,0);

    for(int u:pr[r]) {
        h[u]=1;
        now=u;
        DFS(u,r);pa[u]=r;
        Smin+=(sz[u]&1);
    }
    //cout<<r<<' '<<Smin<<' '<<Smax<<'\n';
    if((K&1)!=(Smin&1) || K<Smin || K>Smax) {
        cout<<"NO";return 0;
    }

    sort(pr[r].begin(),pr[r].end(),cmp);
    S[r]=pr[r][0];
    P[r]=r;
    dfshld(r,0);

    vector < int > A=pr[r];
    nex[A.size()]=A.size();
    A.pb(0);
    for(int i=A.size()-2;i>=0;i--)
    if(sz[A[i]]==sz[A[i+1]]) nex[i]=nex[i+1];
    else nex[i]=i;

    //cout<<r;return 0;
    //upd(1,tim);cout<<get(2,tim)<<'\n';return 0;
    for(int i=1;i<=n;i++) upd(i);
    //cout<<Smin<<' '<<get(1,tim)<<'\n';return 0;
    for(int i=1;i<=n/2 && Smin!=K;i++)if(i!=n/2){
        int x=nex[0],y=nex[1];
        if(x) {
            y=x;x--;
            nex[0]=x-1;
        }
        else{
            nex[1]--;
        }
        sz[A[x]]--;sz[A[y]]--;
        if(sz[A[y]]==sz[A[y+1]])
            nex[y]=nex[y+1];
        else nex[y]=y;
        if(sz[A[x]]==sz[A[x+1]])
            nex[x]=nex[x+1];
        else nex[x]=x;
        int u=Q[A[x]].front(),v=Q[A[y]].front();
        Q[A[x]].pop();Q[A[y]].pop();
        TRY(u,v);
    }else{
        int u=Q[A[0]].front(),v=r;
        Q[A[0]].pop();
        TRY(u,v);
    }
    //cout<<K<<' '<<Smin<<' '<<get(2,tim)<<'\n';
    //for(int i=1;i<=n;i++) if(!ok[i]) cout<<i<<' ';cout<<'\n';
    cout<<"YES\n";

    for(ii u:ans) cout<<u.X<<' '<<u.Y<<'\n';
    solve(r,0);



}
