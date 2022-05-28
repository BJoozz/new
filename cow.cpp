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
using ld = long double;
const ld eps = 1e-9;

ld dis(int a1,int b1,int a2,int b2) {
    return sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2));
}

signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("cow.inp","r",stdin);
    freopen("cow.out","w",stdout);

    ld res = 1e18;
    int n , a , b;
    cin >> n >> a >> b;
    for (int i = 1,x,y,r ; i <= n ; ++i) {
        cin>>x>>y>>r;
        res = min(res , dis(x , y , a , b) - r);
    }
    int x = res;
    if (res<eps+x) cout<<x-1;
    else cout<<x;
}
