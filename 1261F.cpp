#define X first
#define Y second
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int randint(int l,int r){return uniform_int_distribution < int > (l,r) (rng);}
///shuffle(a.begin(), a.end(), rng)
#define int long long
const int MAX=100+4,inf=1e9,M=1030,mod=1e9+7;
void maxx(int &a,int b){if(b>a) a=b;}
void minn(int &a,int b){if(b<a) a=b;}
template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}
bool cmax(int &a,int b){
    if(b>a){a=b;return 1;} else return 0;
}
typedef pair < int, int > ii;
int nex[6000][2];
signed main(){
    ///g++ grader.cpp .cpp -std=c++14 -O2 -Wl,--stack,10485760
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("1261F.inp","r",stdin);freopen("1261F.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }

        cin>>n>>m;
    }


}
