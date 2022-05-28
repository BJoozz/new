#include<bits/stdc++.h>
using namespace std;
#define int long long
#define X first
#define Y second
#define pb push_back
using ii = pair < int , int >;
const int MAX=1e5+4,MAX2=4e5+4,inf=1e9,mod=9e15+7;
bool cmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
bool cmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
void maxx(int &a,int b){if(b>a)a=b;}
void minn(int &a,int b){if(b<a)a=b;}
using ll = long long;
int a[MAX];
bool b[MAX],B[MAX];
int L[MAX],R[MAX];
int sz[MAX],pa[MAX],D[MAX],U[MAX];
int lasU[MAX];
int cn=0,C1,C2,END;
ii ST[MAX*4];
int lz[MAX*4];
int nx,val;
vector < int > vec;
void build(int id,int l,int r){
    if(l==r) {
        ST[id]=ii(-a[U[l]]*C1+l*C2,l);
        return;
    }
    int mid=l+r>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    ST[id]=min(ST[id<<1],ST[id<<1|1]);
}
void upd(int id,int l,int r){
    if(l==r) {
        ST[id].X-=val;
        return;
    }
    int mid=l+r>>1;
    if(lz[id]){
        ST[id<<1].X-=lz[id];
        lz[id<<1]+=lz[id];
        ST[id<<1|1].X-=lz[id];
        lz[id<<1|1]+=lz[id];
        lz[id]=0;
    }
    if(nx<=mid)
        upd(id<<1,l,mid);
    else upd(id<<1|1,mid+1,r);
    ST[id]=min(ST[id<<1],ST[id<<1|1]);
}
void del(int id,int l,int r){
    if(l==r) {
        ST[id]=ii(inf,0);
        return;
    }
    int mid=l+r>>1;
    if(lz[id]){
        ST[id<<1].X-=lz[id];
        lz[id<<1]+=lz[id];
        ST[id<<1|1].X-=lz[id];
        lz[id<<1|1]+=lz[id];
        lz[id]=0;
    }
    if(nx<=mid){
        ST[id<<1|1].X-=C2;
        lz[id<<1|1]+=C2;
        del(id<<1,l,mid);
    }
    else del(id<<1|1,mid+1,r);
    ST[id]=min(ST[id<<1],ST[id<<1|1]);
}
void del(int x){
    nx=x;del(1,1,cn);
}
void upd(int x,int va){
    nx=x;val=va;upd(1,1,cn);
}

void popd(int v){
    L[R[v]]=L[v];
    R[L[v]]=R[v];
    sz[pa[v]]--;
    if(sz[pa[v]]==0){del(pa[v]);return;}
    D[pa[v]]=R[v];
}
void popu(int v){
    L[R[v]]=L[v];
    R[L[v]]=R[v];
    sz[pa[v]]--;
    if(sz[pa[v]]==0){del(pa[v]);return;}
    upd(pa[v],a[L[v]]*C1-a[v]*C1);
    U[pa[v]]=L[v];
}
void comb(int u,int v){
    if(sz[u]>sz[v]){
        sz[u]+=sz[v];
        for(int i=D[v];i<=U[v];i=R[i])
            pa[i]=u;
        upd(u,a[U[v]]*C1-a[U[u]]*C1);
        U[u]=U[v];
        del(v);
    }else{
        sz[v]+=sz[u];
        for(int i=D[u];i<=U[u];i=R[i])
            pa[i]=v;
        D[v]=D[u];
        del(u);
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("1120F.inp","r",stdin);freopen("1120F.out","w",stdout);
    //cout<<__lg(inf);return 0;
    //srand(time(0));
    ///cos = END-a[i]
    int n;
    cin>>n>>C1>>C2;
    char ch;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch;
        b[i]=(ch=='W');
    }
    cin>>END;
    bool tt=!b[1];
    R[0]=1;L[n+1]=n;
    for(int i=1;i<=n;i++){
        L[i]=i-1;R[i]=i+1;
        if(b[i]==tt){
            sz[cn]++;
        }else{
            tt^=1;
            U[cn]=i-1;
            sz[++cn]=1;
            D[cn]=i;
            B[cn]=tt;
        }
        pa[i]=cn;
    }
    U[cn]=n;
    pa[n+1]=cn+1;
    build(1,1,cn);
    int ans=0;
    for(int i=1;i<=n;i++)cout<<pa[i]<<' ';cout<<'\n';
    while(R[0]!=n+1){
        vec.clear();
        int z=ST[1].Y;

        int cos=END-a[U[z]];
        //cout<<"st "<<z<<' '<<ST[1].X<<' '<<U[z]<<'\n';
        cout<<U[z]<<' ';
        popu(U[z]);
        vec.pb(z);

        z=pa[R[U[z]]];
        while(z<=cn){
            cout<<D[z]<<' ';
            popd(D[z]);
            vec.pb(z);
            z=pa[R[U[z]]];
        }
        for(int u:vec)if(sz[u]){
            z=pa[L[D[z]]];
            if(z && B[z]==B[u])
                comb(z,u);
        }
        ans+=min(C1*cos,C2*vec.size());
        cout<<"total "<<cos<<' '<<min(C1*cos,C2*vec.size())<<'\n';
    }
    cout<<ans;
}
