#define X first
#define Y second
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
#define int long long
using ii = pair < int , int >;
const int MAX=1e5+2,inf=1e16,mod=1e9+7;
void PL(int &a,int b){a+=b;if(a>=mod) a-=mod;}
void maxx(int &a,int b){if(a<b) a=b;}
using ll = long long;
int a[MAX],b[MAX];
int L[MAX];
int ST[18][MAX];
int get(int l,int r){
    int z=L[r-l+1];
    return __gcd(ST[z][l],ST[z][r-(1<<z)+1]);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("seq.inp","r",stdin);
    freopen("seq.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        ST[0][i]=abs(b[i]-a[i]);
    }
    for(int i=2;i<=n;i++){
        L[i]=L[i>>1]+1;
    }
    for(int j=1;j<=L[n];j++){
        for(int i=1;i<=n-(1<<j)+1;i++){
            ST[j][i]=__gcd(ST[j-1][i],ST[j-1][i+(1<<j-1)]);
        }
    }
    int x,y;
    while(m--){
        cin>>x>>y;
        cout<<get(x,y)<<'\n';
    }


}
