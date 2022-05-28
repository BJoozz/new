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
int a[MAX];
int d[MAX];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1396E.inp","r",stdin);
    //freopen("1396E.out","w",stdout);
    cin>>n>>m>>Q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0,x,y,c;i<m;i++){
        cin>>x>>y>>c;
        pr[x].pb(ii(y,c));
        pr[y].pb(ii(x,c));
    }
    priority_queue < ii , vector < ii > , greater < ii > > Q;
    ///dijstra=>d



}
