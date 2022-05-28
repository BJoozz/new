#include <bits/stdc++.h>

using namespace std;
//#define int long long
#define X first
#define Y second
#define pb push_back
const int MAX = 2000+3,M2=(1<<17),inf=1e9,mod=1e9+7;
void maxx(int &a,int b) {if(b>a) a=b;}
void minn(int &a,int b) {if(b<a) a=b;}
using ii = pair < int ,int > ;
using ll = long long;
vector < int > vec[MAX*2];
int a[MAX][MAX];
ll C[MAX*2];
int D[MAX*2][50];
int B[50];
bool vs[50];
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("1628E.inp", "r", stdin);freopen("1628E.out", "w", stdout);
    int n,Q;
    cin>>n>>Q;
    for(int i=1,x,y,c;i<n;i++){
        cin>>x>>y>>c;
        pr[x].pb(ii(y,c));
        pr[y].pb(ii(x,c));
    }
    for(int i=1;i<n;i++){

    }
    for(int i=1;i<=Q;i++){
        cin>>l>>r>>
    }

}
