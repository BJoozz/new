
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
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    int m=0;
    int res=0;
    for(int i=1;i<=n;i++)if(a[i]==a[i-1]){
        cnt[i]=cnt[i-1]+1;
    }else cnt[i]=1;
    //cout<<cnt[6]<<'\n';
    queue < int > Q;
    for(int i=n;i>0;i--){
        if(!Q.empty() && Q.front()>a[i]){
            b[++m]=ii(Q.front(),a[i]);
            Q.pop();
        }
        else {
            if(i-cnt[i]<cnt[i]){
                    //cout<<i<<' '<<res<<'\n';
                int P=i-cnt[i];
                int u=a[i],sz=cnt[i];

                for(int j=m;j>0 && sz>P+1;j--)if(b[j].Y>u){
                    if(b[j].X+u*2>b[j].Y+b[j].X){
                        res+=b[j].Y;
                        sz-=2;

                    }
                    m--;
                }
                //cout<<sz<<' '<<res<<'\n';
                /*if(sz==P){
                    res+=sz*a[i];
                }
                if()*/
                for(int j=2;j<=P;j++){
                    res+=a[i];sz--;
                }
                if(sz==1){
                    res+=a[i];break;
                }
                if(sz==2){
                    if(m)res+=min(a[i]+a[i],b[m].Y+a[1]);
                    else res+=a[i]+a[i];
                    break;
                }
                res+=sz*a[i];
                break;
            }
            res+=a[i];
            Q.push(a[i]);
        }
    }
    cout<<res;

}
