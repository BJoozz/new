#include<bits/stdc++.h>
using namespace std;
using ii = pair < int , int >;
const int MAX=1e5+3;
int dp[MAX];
ii a[MAX];
int b[MAX];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("XH.inp","r",stdin);freopen("XH.out","w",stdout);
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[a[i].second]=i;
    }
    for(int i=1,x;i<=n;i++){
        x=b[i];
        dp[x]=dp[x-1]+1;
        ans=max(ans,dp[x]);
    }
    cout<<n-ans;
}
