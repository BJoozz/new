#include <bits/stdc++.h>

using namespace std;
#define int long long
#define X first
#define Y second
#define pb push_back
const int MAX = 3e5+3,inf=1e9;
int mod;
void maxx(int &a,int b) {if(b>a) a=b;}
void minn(int &a,int b) {if(b<a) a=b;}
using ii = pair < int ,int > ;
using ll = long long;
//vector < int > pr[MAX];
int smod(int u){
    if(u>=mod) return u-mod;
    else return u;
}
void fix(int &u){
    u%=mod;
}
void PL(int &a,const int &b){
    a+=b;if(a>=mod) a-=mod;
}
void DE(int &a,const int &b){
    a-=b;if(a<0) a+=mod;
}
int F0[MAX],F1[MAX];
int F[MAX];
int S0[MAX*4],S1[MAX*4];
bool ok[MAX*4];
int L0[MAX*4],L1[MAX*4],R0[MAX*4],R1[MAX*4];
bool one[MAX*4];
int nx,ny,oz;
void down(const int &id,const int &val1,const int &val2,const int &dis){
    PL(S0[id],val1);
    PL(S1[id],val2);
    PL(L0[id],val1);
    PL(L1[id],val2);
    fix(R0[id]+=val1*F0[dis]+val2*F1[dis] );
    fix(R1[id]+=val1*F0[dis+1]+val2*F1[dis+1] );
}
void upd(int id,int l,int r){
    if(nx<=l && r<=ny){
        PL(S0[id],F[l-nx+1]);
        PL(S1[id],F[l-nx+2]);
        PL(L0[id],F[l-nx+1]);
        PL(L1[id],F[l-nx+2]);
        PL(R0[id],F[r-nx]);
        PL(R1[id],F[r-nx+1]);
        return;
    }
    int mid=l+r>>1;
    if(S0[id]||S1[id]){
        down(id<<1,S0[id],S1[id],mid-l);
        down(id<<1|1,(S0[id]*F0[mid+2-l]+S1[id]*F1[mid+2-l])%mod,
             (S0[id]*F0[mid+3-l]+S1[id]*F1[mid+3-l])%mod,r-mid-1);
        S0[id]=S1[id]=0;
    }
    if(mid>=nx) upd(id<<1,l,mid);
    if(mid<ny) upd(id<<1|1,mid+1,r);
    ok[id]=ok[id<<1]&ok[id<<1|1];
    if(ok[id]){
        if(!one[id<<1] && smod(R0[id<<1]+R1[id<<1])!=L0[id<<1|1]) ok[id]=0;
        else if(!one[id<<1|1] && smod(R1[id<<1]+L0[id<<1|1])!=L1[id<<1|1]) ok[id]=0;
    }
    L0[id]=L0[id<<1];
    if(one[id<<1]) L1[id]=L0[id<<1|1];else L1[id]=L1[id<<1];
    if(one[id<<1|1]) R0[id]=R1[id<<1];else R0[id]=R0[id<<1|1];
    R1[id]=R1[id<<1|1];

}
void dec(int id,int l,int r){
    if(nx<=l && r<=ny){
        DE(S0[id],F[l-nx+1]);
        DE(S1[id],F[l-nx+2]);
        DE(L0[id],F[l-nx+1]);
        DE(L1[id],F[l-nx+2]);
        DE(R0[id],F[r-nx]);
        DE(R1[id],F[r-nx+1]);
        return;
    }
    int mid=l+r>>1;
    if(S0[id]||S1[id]){
        down(id<<1,S0[id],S1[id],mid-l);
        down(id<<1|1,(S0[id]*F0[mid+2-l]+S1[id]*F1[mid+2-l])%mod,
             (S0[id]*F0[mid+3-l]+S1[id]*F1[mid+3-l])%mod,r-mid-1);
        S0[id]=S1[id]=0;
    }
    if(mid>=nx) dec(id<<1,l,mid);
    if(mid<ny) dec(id<<1|1,mid+1,r);
    ok[id]=ok[id<<1]&ok[id<<1|1];
    if(ok[id]){
        if(!one[id<<1] && smod(R0[id<<1]+R1[id<<1])!=L0[id<<1|1]) ok[id]=0;
        else if(!one[id<<1|1] && smod(R1[id<<1]+L0[id<<1|1])!=L1[id<<1|1]) ok[id]=0;
    }
    L0[id]=L0[id<<1];
    if(one[id<<1]) L1[id]=L0[id<<1|1];else L1[id]=L1[id<<1];
    if(one[id<<1|1]) R0[id]=R1[id<<1];else R0[id]=R0[id<<1|1];
    R1[id]=R1[id<<1|1];

}
int A[MAX];
void build(int id,int l,int r){
    if(l==r){
        S0[id]=L0[id]=R1[id]=A[l];ok[id]=1;one[id]=1;
        return;
    }
    int mid=l+r>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    ok[id]=ok[id<<1]&ok[id<<1|1];
    if(ok[id]){
        if(!one[id<<1] && smod(R0[id<<1]+R1[id<<1])!=L0[id<<1|1]) ok[id]=0;
        else if(!one[id<<1|1] && smod(R1[id<<1]+L0[id<<1|1])!=L1[id<<1|1]) ok[id]=0;
    }
    L0[id]=L0[id<<1];
    if(one[id<<1]) L1[id]=L0[id<<1|1];else L1[id]=L1[id<<1];
    if(one[id<<1|1]) R0[id]=R1[id<<1];else R0[id]=R0[id<<1|1];
    R1[id]=R1[id<<1|1];

}
int n;
void upd(int x,int y){
    nx=x;ny=y;
    upd(1,1,n);
}
void dec(int x,int y){
    nx=x;ny=y;
    dec(1,1,n);
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1634F.inp", "r", stdin);
    //freopen("A.out", "w", stdout);
    int Q;
    cin>>n>>Q>>mod;
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    for(int i=1,x;i<=n;i++){
        cin>>x;
        DE(A[i],x);
    }

    F[1]=1;
    F[2]=1;
    F0[1]=1;
    F1[2]=1;
    for(int i=3;i<=n;i++){
        F0[i]=smod(F0[i-1]+F0[i-2]);
        F1[i]=smod(F1[i-1]+F1[i-2]);
        F[i]=smod(F[i-1]+F[i-2]);
    }
    if(n==1){
        int dem=A[1];
        char c;
    int x,y;
        while(Q--){
            cin>>c>>x>>y;
            if(c=='A'){
                PL(dem,1);
            }else{
                DE(dem,1);
            }

            if( dem==0 )
                cout<<"YES\n";
            else cout<<"NO\n";
        }
        return 0;
    }
    build(1,1,n);
    char c;
    int x,y;

    while(Q--){
        cin>>c>>x>>y;
        //cerr<<x<<' '<<y<<' ';
        if(c=='A'){
            upd(x,y);
        }else{
            dec(x,y);
        }

        if( L0[1]==0 && L1[1]==0 && ok[1] )
            cout<<"YES\n";
        else cout<<"NO\n";
        //cout<<L0[1]<<' '<<L1[1]<<' '<<ok[1]<<' '<<(dem+mod*1000)%mod<<endl;
    }

}

