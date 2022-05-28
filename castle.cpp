#include <bits/stdc++.h>

using namespace std;
#define int long long
using ll = long long;
using ii = pair < int , int >;
const int MAX=3e5+3,inf=2e15;
//vector < int > pr[M];
string F[5];
int G[100];
void minn(int &a,int b){
    if(b<a) a=b;
}
string comb(string &s,string &t){
    string st;
    //t+='0';s+='0';
    int n=s.length(),m=t.length();
    G[0]=-1;
    for(int i=1,K=-1;i<m;i++){
        while(K>=0 && t[i]!=t[K+1]) K=G[K];
        if(t[i]==t[K+1]) K++;
        G[i]=K;
    }
    int K=-1;
    for(int i=0;i<n;i++){
        while(K>=0 && s[i]!=t[K+1]) K=G[K];
        if(s[i]==t[K+1]) K++;
    }
    for(int i=K+1;i<m;i++) st+=t[i];
    //t.pop_back();
    return st;

}
int p1[]={1,0,-1,0};
int p2[]={0,-1,0,1};

int cnz(string &s,int lim){
    int ans=0;
    for(char i=0;i<lim;i++)
        ans+=s[i]-64;
    return ans;
}
int cnz(string &s){
    int ans=0;
    for(char u:s)
        ans+=u-64;
    return ans;
}
int css(int u){
    if(u>1e8) return inf;
    else return u*(u+1)/2;
    return u*(u+1)/2;
}
string s , t;
int cnt(int M){
    int A1=cnz(F[1]),A2=cnz(F[2]);
    int n=F[1].length(),m=F[2].length();

    int L1=s.length(),L2=t.length();
    int P1=cnz(s),P2=cnz(t);
    int b=1,e=inf,an=0;
    while(b<=e){
        int mid=b+e>>1;
        int z;
        if(mid&1) z=mid;
        else z=mid-1;
        int sum=m*(mid-1)+n;
        if(mid>=2) sum+=(L1+L2)*css((mid-2)/2);
        minn(sum,inf);
        if(mid>=3) sum+=L1*(z-1)/2+(L1+L2)*css((z-3)/2);
        minn(sum,inf);
        if(sum>M){
            e=mid-1;
        }
        else {
            b=mid+1;
            an=mid;
        }
    }
        int z;
        if(an&1) z=an;
        else z=an-1;
        int res=A2*(an-1)+A1;
        if(an>=2)res+=(P1+P2)*css((an-2)/2);
        if(an>=3)res+=P1*(z-1)/2+(P1+P2)*css((z-3)/2);
        int sum=m*(an-1)+n;
        if(an>=2)sum+=(L1+L2)*css((an-2)/2);
        if(an>=3)sum+=L1*(z-1)/2+(L1+L2)*css((z-3)/2);
        M-=sum;
        if(M>=m){
            res+=A2;
            M-=m;
            int u=M/(L1+L2);
            M%=L1+L2;
            res+=u*(P1+P2);
            if(M>=L1){
                M-=L1;
                res+=P1;
                res+=cnz(t,M);
            }
            else res+=cnz(s,M);
        }
        else{
            res+=cnz(F[2],M);
        }

        return res;
}
signed main() {

    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("CASTLE.INP","r",stdin);
    //freopen("CASTLE.OUT","w",stdout);


    cin >> F[1];
    cin >> F[2];
    s=comb(F[2],F[1]);
    F[3]=F[2]+s;
    t=comb(F[3],F[2]);
    F[4]=F[3]+t;
    int x,y,m;
    cin>>x>>y>>m;
    int z=0,u=0,v=0,L=1;
    int dis=0;
    while(1){
        //cerr<<u<<' '<<v<<endl;
        if(z&1){
            if(x==u && (y-v)*(v+p2[z]*L-y)>0){ // ok(v,y,v+p2[z]*L)){
                dis+=abs(y-v);
                break;
            }
            v+=p2[z]*L;
            dis+=L;
        }
        else{
            if(y==v && (x-u)*(u+p1[z]*L-x)>0){ // ok(v,y,v+p2[z]*L)){
                dis+=abs(x-u);
                break;
            }
            u+=p1[z]*L;
            dis+=L;
        }
        if(z&1) L++;
        z=(z+1)%4;

    }
    //cerr<<dis<<endl;
    //cout<<dis<<'\n';//return 0;
    cout<<cnt(dis+m)-cnt(dis);
}
