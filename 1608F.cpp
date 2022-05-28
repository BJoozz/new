#include<bits/stdc++.h>
using namespace std;
#define int long long
#define X first
#define Y second
#define pb push_back
#define pf push_front
using ii = pair < int , int >;
const int MAX=2000+2,MAX2=4e5+4,inf=1e9,mod=998244353;
bool cmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
bool cmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
void maxx(int &a,int b){if(b>a)a=b;}
void minn(int &a,int b){if(b<a)a=b;}
void PL(int &a,int b){a+=b;if(a>=mod) a-=mod;}
int smod(int a){if(a>=mod)return a-mod;else return a;}
void fix(int &a){if(a>=mod) a-=mod;}
using ll = long long;
int a[MAX];
int L[MAX],R[MAX];
int dp[2][MAX][MAX];
int outs[MAX][MAX];
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("1608F.inp","r",stdin);freopen("1608F.out","w",stdout);
    //cout<<__lg(inf);return 0;
    //srand(time(0));
    int n,K;
    cin>>n>>K;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        L[i]=max(x-K,L[i-1]);
        R[i]=min(x+K,i);
        if(L[i]>R[i]){
            cout<<0;return 0;
        }
    }
    for(int i=n-1;i>0;i--){
        minn(R[i],R[i+1]);
        if(L[i]>R[i]){
            cout<<0;return 0;
        }
    }
    for(int i=1;i<=n;i++){
        outs[i][i-1]=1;
        for(int j=i;j<=n;j++){
            outs[i][j]=outs[i][j-1]*j%mod;
        }
    }
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++){
        bool x=i&1,y=!x;
        ///u<v
        ///(k-1-u),(v-u-1)
        ///(k-1-u)!/(k-v)!
        ///(k-v+1)->(k-1-u)
        if(R[i-1]<L[i]){
            //int outs=1;
            for(int k=L[i];k<=i;k++){
                int temp=0;
                for(int j=L[i-1];j<=R[i-1]&&j<=k;j++)
                    temp=(temp*(k-j)+dp[y][k-1][j])%mod;
                //for(int i=R[i-1]+1;i<L[i];i++) outs=outs*(k-i)%mod;
                temp=temp*outs[k-L[i]+1][k-R[i-1]-1]%mod;
                for(int j=L[i];j<=R[i]&&j<=k;j++){
                    dp[x][k][j]=temp;
                    temp=temp*(k-j)%mod;
                }
            }
        }else{
            for(int k=L[i];k<=i;k++){
                int temp=0;
                for(int j=L[i-1];j<L[i];j++)
                    temp=(temp*(k-j)+dp[y][k-1][j])%mod;
                for(int j=L[i];j<=R[i] && j<=k;j++){
                    dp[x][k][j]=(temp+dp[y][k-1][j]+dp[y][k][j]*k)%mod;
                    temp=(temp*(k-j)+dp[y][k-1][j])%mod;
                }
            }
        }


    }
    bool tt=n&1;
    int ans=0;
    for(int k=L[n];k<=n;k++){
        /// (n-j)!/(n-k)!
        for(int j=L[n];j<=R[n]&&j<=k;j++){
            ans=(ans+dp[tt][k][j]*outs[n-k+1][n-j])%mod;
        }
    }
    cout<<ans;
}
