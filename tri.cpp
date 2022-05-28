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
int a[MAX],A[MAX];
int D[MAX];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("tri.inp","r",stdin);
    freopen("tri.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];A[i]=a[i]+A[i-1];
    }
    int ans=0;
    if(m==4){
        for(int i=1;i<=n-3;i++){
            bool tt=0;
            int M=0;
            for(int j=i;j<=i+3;j++){
                tt|=(a[j]!=a[i]);
                maxx(M,a[j]);
            }
            if(tt && M*2<(A[i+3]-A[i-1]) ) ans++;
        }
        cout<<ans;return 0;
    }
    deque < int > Q;
    for(int i=1;i<=n;i++){
        while(!Q.empty() && a[Q.back()]<a[i]) Q.pop_back();
        Q.push_back(i);
        if(Q.front()==i-m) Q.pop_front();
        int M=a[Q.front()];
        if(i>=m && M*2<(A[i]-A[i-m]) ) ans++;
    }
    cout<<ans;






}
