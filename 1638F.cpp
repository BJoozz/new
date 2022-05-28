#include<bits/stdc++.h>
using namespace std;
#define int long long
#define X first
#define Y second
#define pb push_back
using ii = pair < int , int >;
const int MAX=10000+4,MAX2=4e5+4,inf=1e12+1,mod=9e15+7;
bool cmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
bool cmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
void maxx(int &a,int b){if(b>a)a=b;}
void minn(int &a,int b){if(b<a)a=b;}
using ll = long long;
int a[MAX],b[MAX],c[MAX],d[MAX];
int C[MAX];
bool vs[MAX];
int dp[MAX];
int D[MAX],L[MAX],R[MAX];
bool cmp(int u,int v){
    return a[u]<a[v];
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("bao.inp","r",stdin);freopen("bao.out","w",stdout);
    //cout<<__lg(inf);return 0;
    //srand(time(0));
    ///cos = END-a[i]
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];//a[i]=1;
    }
    int top=0;
    for(int i=1;i<=n;i++){
        while(a[D[top]]>=a[i]) top--;
        L[i]=D[top]+1;
        D[++top]=i;
    }
    top=0;D[0]=n+1;a[n+1]=0;
    for(int i=n;i>0;i--){
        while(a[D[top]]>=a[i]) top--;
        R[i]=D[top]-1;
        D[++top]=i;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        b[i]=i;
    sort(b+1,b+1+n,cmp);

    L[0]=n+1;R[0]=0;
    for(int i=1;i<=n;i++){
        maxx(dp[i],dp[i-1]);
        int temp=dp[L[i]-1];
        for(int j=L[i];j<=R[i];j++){
            maxx(temp,(a[j]-a[i])*(R[j]-L[j]+1));
            vs[j]=0;
        }
        temp+=a[i]*(R[i]-L[i]+1);
        maxx(dp[R[i]],a[i]*(R[i]-L[i]+1));
        maxx(ans,temp);


        int nL=L[i],nR=R[i];
        for(int j=1;j<nL;j++)if(R[j]>=i){
            vs[j]=1;C[j]=a[j]*(nR-L[j]+1);
        }else vs[j]=0;
        for(int j=nR+1;j<=n;j++)if(L[j]<=i){
            vs[j]=1;C[j]=a[j]*(R[j]-nL+1);
        }else vs[j]=0;
        int H=a[i];
        int m1=0,m2=0;
        for(int j=1;j<=n;j++)if(vs[b[j]])
        {
            if(b[j]<i)c[++m1]=b[j];
            else d[++m2]=b[j];
        }
        c[m1+1]=d[m2+1]=0;
        int poi=1;
        int T=0;
        temp=0;
        for(int j=m1,x;j>0;j--){
            x=c[j];
            while(poi<=m2 && a[d[poi]]<=H-a[x]){
                maxx(T,C[d[poi]]);
                poi++;
            }
            maxx(T,(R[d[poi]]-nL+1)*(H-a[x]));
            maxx(ans,T+C[x]);
        }
        T=0;poi=0;
        for(int j=m2,x;j>0;j--){
            x=d[j];
            while(poi<=m1 && a[c[poi]]<=H-a[x]){
                maxx(T,C[c[poi]]);
                poi++;
            }
            maxx(T,(nR-L[c[poi]]+1)*(H-a[x]));
            maxx(ans,T+C[x]);
        }
    }
    cout<<ans;
}
