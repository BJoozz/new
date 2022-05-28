
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define X first
#define Y second
void minn(int &a,int b){
    if(b<a) a=b;
}
using ll = long long;
using ii = pair < int , int >;
const int MAX=500000+3,mod=998244353,inf=1e9+1;
void PL(int &a,int b){
    a+=b;if(a>=mod) a-=mod;
}
int cnt[MAX];
int a[MAX];
ii b[MAX];
signed main() {
    //freopen("35F.inp","r",stdin);
    //freopen("335F.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++) if(i&(1<<j)){

        }
    }
}
