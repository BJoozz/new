#include<bits/stdc++.h>
using namespace std;
#define int long long
#define X first
#define Y second
#define pb push_back
#define pf push_front
using ii = pair < int , int >;
const int MAX=1e5+4,MAX2=4e5+4,inf=1e9,mod=9e15+7;
bool cmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
bool cmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
void maxx(int &a,int b){if(b>a)a=b;}
void minn(int &a,int b){if(b<a)a=b;}
using ll = long long;
int C[MAX];
vector < int > pr[MAX],ad[MAX],V[MAX];
stack < int > st;
bool vs[MAX];
int th[MAX],cn;

void dfs(int v){
    vs[v]=1;
    for(int u:pr[v])if(!vs[u]){
        dfs(u);
    }
    st.push(v);
}
void dfs2(int v){
    V[cn].pb(v);
    th[v]=cn;
    for(int u:ad[v])if(!th[u])
        dfs2(u);
    else if(th[u]!=cn){
        C[cn]++;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1142E.inp","r",stdin);freopen("1142E.out","w",stdout);
    //cout<<__lg(inf);return 0;
    //srand(time(0));
    int n,m;
    cin>>n>>m;
    for(int i=1,x,y;i<=m;i++){
        cin>>x>>y;
        pr[x].pb(y);
        ad[y].pb(x);
    }
    for(int i=1;i<=n;i++)if(!vs[i])dfs(i);

    while(!st.empty()){
        int v=st.top();st.pop();
        if(!th[v]) {
            cn++;dfs2(v);
        }
    }
    deque < int > Q;
    for(int i=1;i<=cn;i++)if(!C[i]){
        for(int u:V[i]){
            Q.push_front(u);
        }
    }
    memset(vs,0,sizeof vs);
    int top=Q.front();Q.pop_front();
    for(int u:pr[top]) vs[u]=1;
    for(int u:ad[top]) vs[u]=1;
        for(int u:pr[top]){
            C[th[u]]--;
            if(!C[th[u]])
            for(int z:V[th[u]])Q.push_front(z);
        }

    bool tt=1;
    bool res;
    while(tt){
        tt=0;
        int sz=Q.size();
        while(sz--){
            int v=Q.front();Q.pop_front();
            if(vs[v])
                Q.push_back(v);
            else{
                for(int u:pr[v]){
                    C[th[u]]--;
                    if(!C[th[u]]){
                        for(int z:V[th[u]])Q.push_front(z);
                    }
                }
                cout<<"? "<<v<<' '<<top<<endl;
                cin>>res;
                if(res) {
                    for(int u:pr[top]) vs[u]=0;
                    for(int u:ad[top]) vs[u]=0;
                    top=v;
                    for(int u:pr[top]) vs[u]=1;
                    for(int u:ad[top]) vs[u]=1;

                }
                tt=1;
                break;

            }
        }
    }
    cout<<"! "<<top<<endl;

}
