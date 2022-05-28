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
vector < int > pr[MAX];
int L[MAX];
int a[MAX];
int A[MAX],B[MAX],F[MAX];
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
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1583G.inp","r",stdin);
    //freopen("1583G.out","w",stdout);
    int n;cin>>n;
    for(int i=1,x,y;i<=n;i++){
        cin>>x>>y;
        L[y]=x;a[i]=y;
    }
    int m;cin>>m;
    for(int i=1,x;i<=m;i++){
        cin>>x;
        C[a[x]]=1;

    }
    for(int i=1;i<=2*n;i++)if(L[i]){
        int x=L[i];
        B[i]=1+A[i-1]-get(x);
        B[i]=(B[i]+mod*2)%mod;
        upd(x,B[i]);
        A[i]=smod(A[i-1]+B[i]);
    }else{
        B[i]=0;
        A[i]=A[i-1];
    }
    int lax=0,ans=0;
    for(int i=n*2;i>0;i--)if(L[i]){
        int x=L[i];
        pop(x,B[i]);
        if(C[i] && x>lax){
            ans+=A[i-1]-get(lax)+1;

            lax=x;
        }
    }
    ans=(ans%mod+mod)%mod;
    cout<<ans;


}
