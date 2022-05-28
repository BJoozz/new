#define X first
#define Y second
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
#define int long long
using ii = pair < int , int >;
const int MAX=4000+2,inf=1e16,mod=1e9+7;
void PL(int &a,int b){a+=b;if(a>=mod) a-=mod;}
using ll = long long;
vector < int > pr[MAX];

int a[5];
signed main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1558E.inp","r",stdin);
    //freopen("1558E.out","w",stdout);
    int T,n;cin>>T;
    for(int i=1;i<=20;i++){
            n=i;
        for(int j=1;j<=4;j++)a[j]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=4;j++)a[j]*=j;
        }
        ll ans=0;
        for(int j=1;j<=4;j++)ans+=a[j];
        cout<<ans%8<<'\n';
    }




}
