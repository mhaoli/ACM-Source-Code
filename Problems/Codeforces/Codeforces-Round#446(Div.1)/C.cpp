//Create Time: 2017-11-19 21:29:34
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <functional>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>
#include <complex>
#include <cassert>
using namespace std;
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,n,a) for (int i=(n)-1;i>=(a);i--)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define TST(x) std::cout<<(x)<<" "
#define SZ(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define unq(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define mem(f,x) memset((f), (x), sizeof(f))
#define clr(f) mem(f,0)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define DEBUG
template<class T> void rd(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
typedef pair<int, int> pii; typedef vector<int> vi; typedef vector<pii > vii;
/****head****/
const int Max_N=(int)5e5+9;
struct E{
    int u,v,w,id;
    void input(int _id){
        scanf("%d%d%d",&u,&v,&w);--u;--v;
        id=_id;
    }
};
E et[Max_N];
vector<E> eg[Max_N];
vii qw[Max_N];
bool wa[Max_N];
int T,f[Max_N],f2[Max_N],qt[Max_N];
int find(int x){
    return x==f[x]?x:f[x]=find(f[x]);
}
int find2(int x){
    if(qt[x]!=T){
        f2[x]=f[x];
        qt[x]=T;
    }
    return x==f2[x]?x:f2[x]=find2(f2[x]);
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,0,m){
        et[i].input(i);
        eg[et[i].w].pb(et[i]);
    }
    int q; scanf("%d",&q);
    rep(i,0,q){
        int K,t;
        scanf("%d",&K);
        while(K--){
            scanf("%d",&t);--t;
            qw[et[t].w].pb(pii(i,t));
        }
    }
    rep(i,0,Max_N-5)sort(all(qw[i]));

    T=0;
    rep(i,0,n)f[i]=i;
    rep(i,0,Max_N-5){
        int x,y,idx;
        rep(j,0,SZ(qw[i])){
            idx=qw[i][j].x;
            x=et[qw[i][j].y].u;
            y=et[qw[i][j].y].v;
            // TST(idx);TST(qw[i][j-1].x);
            if(j==0||idx!=qw[i][j-1].x)++T;
            // OUT(T);
            // if(idx==0){
                // rep(_,0,n) TST(_),TST(qt[_]),TST(find(_)),OUT(find2(_));
            // }
            // cout<<"i="<<i<<" q_idx="<<idx<<" x="<<x+1<<" y="<<y+1<<" find2(x)="<<find2(x)+1<<" find2(y)="<<find2(y)+1<<endl;
            find(x);find(y);
            if(find2(x)==find2(y)){
                // puts("aaaaaaaaaaa");
                wa[idx]=1;
            }
            f2[find2(x)]=find2(y);
        }
        rep(j,0,SZ(eg[i])){
            x=eg[i][j].u;
            y=eg[i][j].v;
            if(find(x)!=find(y)){
                f[find(x)]=find(y);
            }
        }
    }
    rep(i,0,q)puts(wa[i]?"NO":"YES");
    return 0;
}
