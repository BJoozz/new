#define X first
#define Y second
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
#define int long long
using ii = pair < int , int >;
const int MAX=4000+2,inf=1e16,mod=1e9+7;
void PL(int &a,int b){a+=b;if(a>=mod) a-=mod;}
using ll = long long;
vector < int > pr[MAX];
bool vs[MAX];
int a[MAX],b[MAX],c[MAX],d[MAX];
int tr[MAX];

int D[MAX];
int ok[MAX];
int n,m;
bool done[MAX];
bool check(int lim){
    for(int i=1;i<=n;i++) done[i]=0;
            done[0]=done[1]=1;
            int now=lim;
            //now=17;
            //cerr<<now<<endl;
            memset(D,0,sizeof D);
            while(1){
                queue < int > Q;
                for(int i=1;i<=n;i++) ok[i]=done[i];
                int x=0,y=0;
                for(int z=1;z<=n && !y;z++) if(done[z]){
                    for(int u:pr[z])if(!done[d[u]] && now>a[d[u]]){
                        D[u]=now+b[d[u]];
                        tr[u]=0;
                        Q.push(u);
                        if(!ok[d[u]])ok[d[u]]=u;
                        else{
                            if(done[d[u]]) x=0;
                            else x=ok[d[u]];
                            y=u;break;
                        }
                    }
                }
                while(!Q.empty() && !y){
                    int v=Q.front();Q.pop();
                    for(int u:pr[d[v]])if( (u^1)!=v && D[v]>a[d[u]]){
                        D[u]=D[v]+b[d[u]];
                        Q.push(u);
                        tr[u]=v;
                        if(!ok[d[u]])ok[d[u]]=u;
                        else{
                            if(done[d[u]]) x=0;
                            else x=ok[d[u]];
                            y=u;break;
                        }
                    }
                }
                //cerr<<now<<endl;
                //cerr<<x<<' '<<y<<' '<<c[x]<<' '<<d[x]<<' '<<c[y]<<' '<<d[y]<<endl;
                if(y==0){
                    for(int i=1;i<=n;i++)
                    if(!done[i] && D[i]>D[y]) y=i;
                    while(!done[d[y]]){
                        now+=b[d[y]];
                        done[d[y]]=1;
                        y=tr[y];
                    }
                    break;
                }

                //for(int i=1;i<=n;i++)cout<<done[i];cout<<'\n';
                if(!done[d[y]]) {
                    done[d[y]]=1;
                    now+=b[d[y]];
                }
                //cout<<"goy "<<' '<<c[y]<<' '<<d[y]<<'\n';
                y=tr[y];
                while(!done[d[y]]){
                        //cout<<"goy "<<' '<<c[y]<<' '<<d[y]<<'\n';
                    now+=b[d[y]];
                    done[d[y]]=1;
                    y=tr[y];
                }
                x=tr[x];//cout<<"gox "<<' '<<c[x]<<' '<<d[x]<<'\n';
                while(!done[d[x]]){
                    now+=b[d[x]];
                    done[d[x]]=1;
                    x=tr[x];
                }
                //for(int i=1;i<=n;i++)cout<<done[i];cout<<'\n';
            }
            //for(int i=1;i<=n;i++)cout<<done[i];cout<<'\n';
            for(int i=1;i<=n;i++)if(!done[i])return 0;
            return 1;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1558E.inp","r",stdin);
    //freopen("1558E.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=2;i<=n;i++)
            cin>>a[i];
        for(int i=2;i<=n;i++)
            cin>>b[i];
        for(int i=1;i<=n;i++) pr[i].clear();
        for(int i=1,x,y;i<=m;i++) {
            cin>>c[i<<1]>>d[i<<1];
            c[i<<1|1]=d[i<<1];d[i<<1|1]=c[i<<1];
            pr[c[i<<1]].pb(i<<1);
            pr[d[i<<1]].pb(i<<1|1);
        }
        int l=1,r=inf,ans=0;

        //cout<<check(550497547)<<'\n';return 0;
        //cout<<l<<' '<<r<<' '<<ans<<'\n';
        while(l<=r){
            int lim=l+r>>1;

            if(check(lim)){
                r=lim-1;
                ans=lim;
            }
            else l=lim+1;
            //cout<<tt;return 0;
        }
        cout<<ans<<'\n';
        //return 0;
    }




}
