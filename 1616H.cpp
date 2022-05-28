#include<bits/stdc++.h>
using namespace std;
#define int long long
#define X first
#define Y second
#define pb push_back
using ii = pair < int , int >;
const int MAX=150000+4,mod=998244353;
bool cmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
bool cmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
void maxx(int &a,int b){if(b>a)a=b;}
void minn(int &a,int b){if(b<a)a=b;}
using ll = long long;
void PL(int &a,const int &b){a+=b;if(a>=mod) a-=mod;}
void DO(int &a,const int &b){(a+=b)%=mod;}
int fix(int &a){
    if(a>=mod) a-=mod;
}
int a[MAX];
int P[MAX];
int S[MAX*30];
int nex[MAX*30][2];
int node;
bool b[31];
int dp[MAX*30];
int cnt(int i,int u,int v){
    if(i==-1){
        return ((S[u]+1)*(S[v]+1))%mod;
    }
    if(u<v) swap(u,v);
    if(dp[u]!=-1) return dp[u];
    int &res=dp[u];
    res=0;
    if(b[i]){
        DO(res,cnt(i-1,nex[u][1],nex[v][0])*cnt(i-1,nex[u][0],nex[v][1]));
    }else{
        PL(res,cnt(i-1,nex[u][1],nex[v][1]));
        PL(res,cnt(i-1,nex[u][0],nex[v][0]));
        res--;if(res<0) res+=mod;
        DO(res,S[nex[u][0]]*S[nex[u][1]]+S[nex[v][0]]*S[nex[v][1]] ) ;
    }
    //cout<<i<<' '<<u<<' '<<v<<' '<<res<<'\n';
    return res;
}
int ans=0;
void dfs(int i,int u){
    if(b[i]){
        //cout<<i<<' '<<u<<'\n';
        PL(ans,cnt(i-1,nex[u][0],nex[u][1])-1);
        return;
    }
    if(nex[u][0]) dfs(i-1,nex[u][0]);
    if(nex[u][1]) dfs(i-1,nex[u][1]);

}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("bao.inp","r",stdin);freopen("bao.out","w",stdout);
    //cout<<__lg(inf);return 0;
    //srand(time(0));
    ///cos = END-a[i]
    memset(dp,-1,sizeof dp);
    int n,x;
    cin>>n>>x;
    P[0]=1;
    for(int i=1;i<=n;i++){
        fix(P[i]=P[i-1]<<1);
    }
    if(!x){
        for(int i=1;i<=n;i++){
            cin>>a[i];//a[i]=1;
        }
        sort(a+1,a+1+n);
        int cn=1,ans=0;
        for(int i=2;i<=n;i++){
            if(a[i]==a[i-1]){
                cn++;
            }else{
                PL(ans,P[cn]-1);cn=1;
            }
        }
        PL(ans,P[cn]-1);
        PL(ans,mod);
        cout<<ans;return 0;
    }
    int fir=0;
    for(int i=0;i<30;i++){
        b[i]=(x>>i)&1;
        if(b[i]) fir=i;
    }

    for(int i=1;i<=n;i++){
        cin>>a[i];//a[i]=1;
        int t=0;
        for(int j=29;j>=0;j--)if(a[i]&(1<<j)){
            if(!nex[t][1]) nex[t][1]=++node;
            t=nex[t][1];S[t]++;
        }else{
            if(!nex[t][0]) nex[t][0]=++node;
            t=nex[t][0];S[t]++;
        }
        //cout<<a[i]<<' '<<t<<'\n';
    }

    for(int i=1;i<=node;i++){
        S[i]=P[S[i]]-1;
        if(S[i]<0) S[i]+=mod;
    }
    nex[++node][0]=nex[0][0];
    nex[node][1]=nex[0][1];
    //cout<<nex[node][0]<<' '<<nex[node][1]<<'\n';
    nex[0][0]=nex[0][1]=0;
    dp[0]=1;
    dfs(29,node);
    if(ans<0) ans+=mod;
    cout<<ans;
}
