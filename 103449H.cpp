#define X first
#define Y second
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
#define int long long
using ii = pair < int , int >;
const int MAX=4e5+2,inf=1e16,mod=1e9+7;
void PL(int &a,int b){a+=b;if(a>=mod) a-=mod;}
void DE(int &a,int b){a-=b;if(a<0) a+=mod;}
int smod(int a){if(a>=mod) return a-mod;else return a;}
using ll = long long;
vector < int > pr[MAX],ad[MAX];
int p[MAX];
bool C[MAX];
void upd(int id,int val){
    for(;id<MAX;id+=id&-id) PL(F[id],val);
}
void pop(int id,int val){
    for(;id<MAX;id+=id&-id) DE(F[id],val);
}
int get(int id){
    int res=0;
    for(;id>0;id-=id&-id) PL(res,F[id]);
    return res;
}
void dfs(int v,int trc){
    in[v]=++tim;
    for(int u:pr[v]) if(u!=trc){
        dfs(u,v);
    }
    out[v]=tim;
}
int p[MAX];
void dfs(int )
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("103449H.inp","r",stdin);
    //freopen("1286E.out","w",stdout);
    int n,Q;cin>>n>>Q;
    for(int i=2,x;i<=n;i++){
        cin>>x;p[i]=x;
        pr[x].pb(i);
        pr[i].pb(x);
    }
    for(int i=1;i<=Q;i++){
        cin>>a[i]>>b[i];
        if(a[i]==1){
            p[b[i]]=p[p[b[i]]];
        }
    }

}
