#include<bits/stdc++.h>
using namespace std;
#define int long long
#define X first
#define Y second
#define pb push_back
#define pf push_front
using ii = pair < int , int >;
const int MAX=500+2,MAX2=4e5+4,inf=1e9,mod=9e15+7;
bool cmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
bool cmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
void maxx(int &a,int b){if(b>a)a=b;}
void minn(int &a,int b){if(b<a)a=b;}
using ll = long long;
vector < int > pr[MAX];
int a[MAX];
int b[MAX];
int c[MAX];
ii D[MAX*MAX];
vector < ii > vec;
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1641A.inp","r",stdin);freopen("1641A.out","w",stdout);
    //cout<<__lg(inf);return 0;
    //srand(time(0));
    int T,n,x;
    cin>>T;
    while(T--){
        cin>>n;

        set < int > S;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            if(S.find(a[i])!=S.end())S.erase(a[i]);
            else S.insert(a[i]);
        }
        if(!S.empty()){
            cout<<-1<<'\n';continue;
        }
        int m=n;
        int dem=0,cn=0;
        vec.clear();
        for(int k=1;k*2<=n;k++){
            int cs=0;
            for(int i=2;i<=m;i++)if(a[i]==a[1]){
                cs=i;break;
            }
            for(int i=2;i<cs;i++){
                D[++cn]=ii(dem+i+cs-2,a[i]);
                b[cs-i]=a[i];
            }
            m-=2;
            for(int i=cs-1;i<=m;i++)
                b[i]=a[i+2];
            for(int i=1;i<=m;i++) a[i]=b[i];
            c[k]=(cs-1)*2;
            dem+=c[k];
        }
        cout<<cn<<'\n';
        for(int i=1;i<=cn;i++){
            cout<<D[i].X<<' '<<D[i].Y<<'\n';
        }
        cout<<n/2<<'\n';
        for(int k=1;k*2<=n;k++){
            cout<<c[k]<<' ';
        }
        cout<<'\n';
    }

}
