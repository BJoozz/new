#define X first
#define Y second
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
#define int long long
using ii = pair < int , int >;
const int MAX=1000+2,inf=1e18,mod=1e9+7;
void PL(int &a,int b){a+=b;if(a>=mod) a-=mod;}
using ll = long long;

namespace dinic {
    const int INF = INT_MAX;

    vector <int> head, dis, work;
    vector <int> to, nxt, capa, flow;
    int n; queue <int> q;

    void init(int n) {
        dinic::n = n;
        head.assign(n + 5, -1);
        dis.assign(n + 5, 0);
        work.assign(n + 5, 0);
        to.clear(); nxt.clear();
        capa.clear(); flow.clear();
    }

    int add_edge(int u, int v, int c, bool r = 0) {
        to.push_back(v); nxt.push_back(head[u]);
        capa.push_back(c); flow.push_back(0);
        head[u] = to.size() - 1;
        to.push_back(u); nxt.push_back(head[v]);
        capa.push_back(c * r); flow.push_back(0);
        head[v] = to.size() - 1;
        return head[u];
    }

    bool bfs(int s, int t) {
        fill(dis.begin(), dis.end(), -1);
        dis[s] = 0; q.push(s);
        while (q.size()) {
            int u = q.front(); q.pop();
            for (int i = head[u]; i >= 0; i = nxt[i])
                if (flow[i] < capa[i] && dis[to[i]] < 0) {
                    dis[to[i]] = dis[u] + 1; q.push(to[i]);
                }
        }
        return dis[t] >= 0;
    }
    int get(int u){
        for (int i = head[u]; i >= 0; i = nxt[i])if(flow[i]>0){
            return to[i];
        }
    }
    bool sok(int z){
        if(z==-1) return 0;
        return flow[z]>0;
    }
    int dfs(int s, int t, int f) {
        if (s == t) return f;
        for (int &i = work[s]; i >= 0; i = nxt[i])
            if (flow[i] < capa[i] && dis[to[i]] == dis[s] + 1) {
                int d = dfs(to[i], t, min(f, capa[i] - flow[i]));
                if (d > 0) {
                    flow[i] += d; flow[i ^ 1] -= d; return d;
                }
            }
        return 0;
    }

    int max_flow(int s, int t) {
        int res = 0, aug;
        while (bfs(s, t)) {
            copy(head.begin(), head.end(), work.begin());
            while ((aug = dfs(s, t, INF)) > 0) res += aug;
        }
        return res;
    }
};
using namespace dinic;
int A[MAX][MAX][4];
int B[MAX][MAX];
char ans[MAX*3][MAX*3];
int P[MAX][MAX][4];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("Alliances.inp","r",stdin);freopen("Alliances.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int cn=1,s=0,t=1;
    init(n*m*6);
    int U=0,V=0;
    int L=n*3,R=m*3;
    for(int i=1;i<=L;i++){
        for(int j=1;j<=R;j++) ans[i][j]='.';
    }
    for(int i=1,x;i<=n;i++){
        for(int j=1;j<=m;j++)if((i^j)&1){
            cin>>x;
            if(x) ans[i*3-1][j*3-1]='O';
            U+=x;
            B[i][j]=++cn;
            if(x==2){
                add_edge(s,cn,1);
                add_edge(s,++cn,1);
                for(int k=0;k<2;k++){
                    A[i][j][k]=++cn;
                    add_edge(B[i][j],cn,1);
                }
                for(int k=2;k<4;k++){
                    A[i][j][k]=++cn;
                    add_edge(B[i][j]+1,cn,1);
                }
            }
            else{
                add_edge(s,cn,x);
                for(int k=0;k<4;k++){
                    A[i][j][k]=++cn;
                    add_edge(B[i][j],cn,1);
                }
            }

        }
        else{
            cin>>x;if(x) ans[i*3-1][j*3-1]='O';
            V+=x;
            B[i][j]=++cn;
            if(x==2){
                add_edge(cn,t,1);
                add_edge(++cn,t,1);
                for(int k=0;k<2;k++){
                    A[i][j][k]=++cn;
                    add_edge(cn,B[i][j],1);
                }
                for(int k=2;k<4;k++){
                    A[i][j][k]=++cn;
                    add_edge(cn,B[i][j]+1,1);
                }
            }
            else{
                add_edge(cn,t,x);
                for(int k=0;k<4;k++){
                    A[i][j][k]=++cn;
                    add_edge(cn,B[i][j],1);
                }
            }
        }
    }
    memset(P,-1,sizeof P);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)if((i^j)&1){
            if(i!=n) P[i][j][0]=add_edge(A[i][j][0],A[i+1][j][1],1);
            if(j!=m) P[i][j][2]=add_edge(A[i][j][2],A[i][j+1][3],1);

            if(i!=1) P[i][j][1]=add_edge(A[i][j][1],A[i-1][j][0],1);
            if(j!=1) P[i][j][3]=add_edge(A[i][j][3],A[i][j-1][2],1);
        }
    }
    if(U!=V || U!=max_flow(s,t)) {cout<<"Impossible!";return 0;}
    for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++)if((i^j)&1){
        if(sok(P[i][j][0]))ans[i*3][j*3-1]=ans[i*3+1][j*3-1]='X';
        if(sok(P[i][j][1]))ans[i*3-2][j*3-1]=ans[i*3-3][j*3-1]='X';
        if(sok(P[i][j][2]))ans[i*3-1][j*3]=ans[i*3-1][j*3+1]='X';
        if(sok(P[i][j][3]))ans[i*3-1][j*3-2]=ans[i*3-1][j*3-3]='X';
    }
    }

    for(int i=1;i<=L;i++){
        cout<<ans[i]+1<<'\n';
    }


}
