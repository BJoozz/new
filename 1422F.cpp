
#define X first
#define Y second
#define pb push_back

#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int MAX=1e5+4,M=2e5+2,mod=1e9+7;
void maxx(int &a,int b){if(b>a) a=b;}
using ll = long long;
void minn(ll &a,ll b){if(b<a) a=b;}
//int down(const int &id){return id^1;}
//int upd(const int &id){return id;}
using ii =pair < int , int >;
const int N=2e7;
int L[N],R[N];
ll ST[N];
int top[MAX];
vector < int > V[M];
int val,now,nx;
int node;
int upd(int fak,int l,int r){
    int id=++node;
    if(l==r){
        ST[id]=ST[fak]*val;return id;
    }
    int mid=l+r>>1;
    if(nx<=mid){
        L[id]=upd(L[fak],l,mid);R[id]=R[fak];
    }else {R[id]=upd(R[fak],mid+1,r);L[id]=L[fak];}
    ST[id]=1LL*ST[L[id]]*ST[R[id]]%mod;
    return id;
}
int pop(int fak,int l,int r){
    int id=++node;
    if(l==r){
        ST[id]=ST[fak]/val;return id;
    }
    int mid=l+r>>1;
    if(nx<=mid){
        L[id]=pop(L[fak],l,mid);R[id]=R[fak];
    }else {R[id]=pop(R[fak],mid+1,r);L[id]=L[fak];}
    ST[id]=1LL*ST[L[id]]*ST[R[id]]%mod;
    return id;
}
ll get(int id,int l,int r){
    if(l==nx) return ST[id];
    int mid=l+r>>1;
    if(nx<=mid)
        return get(L[id],l,mid)*ST[R[id]]%mod;
    else return get(R[id],mid+1,r);
}
int n;
void upd(int x){
    nx=x;
    now=upd(now,1,n);
}
void pop(int x){
    nx=x;
    now=pop(now,1,n);
}
int B[M];
int get(int x,int y){
    nx=x;return get(top[y],1,n);
}
int A[MAX];
vector < int > vec;
signed main(){
    ///g++ grader.cpp .cpp -std=c++14 -O2 -Wl,--stack,10485760
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1422F.inp","r",stdin);//freopen("1422F.out","w",stdout);
    cin>>n;
    //now=build(1,n);
    for(int i=2;i*i<M;i++)if(!B[i]){
        B[i]=i;
        for(int j=i*i;j<M;j+=i) B[j]=i;
    }
    for(int i=2;i<M;i++)if(!B[i])B[i]=i;
    ST[0]=1;
    for(int i=1,x;i<=n;i++){
        A[i]=1;
        cin>>x;
        val=x;upd(i);
        vec.clear();
        while(x!=1){
            int z=B[x],cn=0;
            while(x%z==0) {x/=z;cn++;}
            val=z;
            if(cn>V[z].size()){
                for(int u:V[z]){A[u]*=z;vec.pb(u);}
                V[z].resize(cn);
                for(int &u:V[z]) u=i;
            }else{
                for(int j=0;j<cn;j++){
                    A[V[z][j]]*=z;vec.pb(V[z][j]);V[z][j]=i;
                }
            }
        }
        for(int u:vec)if(A[u]!=1){
            val=A[u];pop(u);A[u]=1;
        }

        top[i]=now;//cout<<now<<' '<<ST[now]<<'\n';
    }
    int Q,x,y;
    cin>>Q;
    int ans=0;
    while(Q--){
        cin>>x>>y;
        x=(x+ans)%n+1;y=(y+ans)%n+1;
        if(x>y) swap(x,y);
        ans=get(x,y);
        cout<<ans<<'\n';
    }


}
