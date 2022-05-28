#define X first
#define Y second
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
using ii = pair < int , int >;
const int MAX=1000+2,mod=1e9+7;
void PL(int &a,int b){a+=b;if(a>=mod) a-=mod;}
using ll = long long;
void minn(int &a,int b){if(b<a) a=b;}
int a[MAX][MAX];
ll B[MAX][MAX];
signed main(){

    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("wmt.inp","r",stdin);
    //freopen("wmt.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
        sort(a[i]+1,a[i]+1+m);
        for(int j=1;j<=m;j++){
            B[i][j]=B[i][j-1]+a[i][j];
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int b=1,e=m,l=1,r=m;
            bool tt=0;
            while(b<=e){
                int mi=b+e>>1;
                int x=(upper_bound(a[j]+1,a[j]+1+m,a[i][mi])-a[j])-1;
                /// <=
                if(x+mi==m){
                    ans+=(B[i][m]+B[j][m])-(B[i][mi]+B[j][x])*2;tt=1;break;
                }
                if(x+mi>m)
                {
                    r=x;
                    e=mi-1;
                }
                else {
                    l=x;
                    b=mi+1;
                }
            }
            //cout<<l<<' '<<r<<'\n';
            if(tt) continue;
            b=l;e=r;
            while(b<=e){
                int mi=b+e>>1;
                int x=(lower_bound(a[i]+1,a[i]+1+m,a[j][mi])-a[i])-1;
                /// <=
                if(x+mi==m){
                    ans+=(B[i][m]+B[j][m])-(B[j][mi]+B[i][x])*2;break;
                }
                if(x+mi>m)
                    e=mi-1;
                else b=mi+1;
            }
            //cout<<tt;
        }
    }
    cout<<ans;
}
