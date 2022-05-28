
#define X first
#define Y second
#define pb push_back

#include<bits/stdc++.h>
using namespace std;
//#define int long long
mt19937 rng(time(0));
int randint(int l,int r){
    return uniform_int_distribution < int > (l,r) (rng);
}
void maxx(int &a,int b){if(b>a) a=b;}
using ll = long long;
void minn(ll &a,ll b){if(b<a) a=b;}
using ii =pair < int , int >;
const int MAX=1e5+4,M=1e5+1,mod=1e9+7,base=973831579;
const int N=2e7;
int L[N],R[N];
ll ST[N];
ll P[M];
int G[M];
int top[MAX];
int val,now,nx;
int node;

int n;
void upd(int fak,int l,int r){
    if(l==r){
        ++node;
        PL(ST[node],G[l]);
        return node;
    }
    int id=++node;
    if(nx<=mid){

    }
}
void upd(int x){
    nx=x;upd(now,1,M-1);
}
signed main(){
    ///g++ grader.cpp .cpp -std=c++14 -O2 -Wl,--stack,10485760
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("CLONEME.inp","r",stdin);//freopen("CLONEME.out","w",stdout);
    int T,n,Q;
    cin>>T;
    P[]
    for(int i=1;i<M;i++){
        P[i]=P[i-1]*base%mod;
        G[i]=randint(G[i-1]+1,1LL*base*i/M);
    }
    shuffle(G+1,G+M,rng);
    while(T--){
        cin>>n>>Q;
        for(int i=1,x;i<=n;i++) {
            cin>>x;
            upd(x);
        }
        int x,y,u,v;
        while(Q--){
            cin>>x>>y>>u>>v;
            while()
        }
    }




}
