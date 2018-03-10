//Create Time: 2018-03-09 17:30:55
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
#include <climits>
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
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
/****head****/
const int Max_N=200009;
struct Edge{
    int t;
    Edge *nxt;
    Edge(){}
    Edge(int _t):t(_t){}
    void set(int _t, Edge *n){
        t = _t; nxt = n;
    }
};
Edge pool[Max_N], *head[Max_N], *bat;
void init_graph(int n){
    bat = pool;
    memset(head, 0, n * sizeof head[0]);
}
void add_edge(int s, int t){
    bat->set(t, head[s]); head[s]=bat++;
}
namespace SCC{
    int dfs_clock, cnt;
    int pre[Max_N], lowlink[Max_N];
    int stk[Max_N], top;

    void dfs(int u, int*sccno, Edge *hd[]){
        pre[u] = lowlink[u] = ++dfs_clock;
        stk[top++] = u;
        for(Edge *p = hd[u]; p; p = p->nxt){
            int v = p->t;
            if(!pre[v]){
                dfs(v, sccno, hd);
                lowlink[u] = min(lowlink[u], lowlink[v]);
            } else if(sccno[v] == -1){
                lowlink[u] = min(lowlink[u], pre[v]);
            }
        }
        if(lowlink[u] == pre[u]){
            cnt++;
            for(;;){
                int x = stk[--top];
                sccno[x] = cnt;
                if(x == u) break;
            }
        }
    }

    //index 0-based
    int calc_scc(int n, int *sccno, Edge *hd[]){
        dfs_clock = top = 0; cnt = -1;
        memset(sccno, -1, n * sizeof sccno[0]);
        memset(pre, 0, n * sizeof pre[0]);
        for(int i = 0; i < n; ++ i)
            if(!pre[i]) dfs(i, sccno, hd);
        return ++cnt;
    }
}
bool out[Max_N];
int siz[Max_N];
int u[Max_N],sccno[Max_N];
int main(){
    int n,m,h;scanf("%d%d%d",&n,&m,&h);
    init_graph(n);
    rep(i,0,n)scanf("%d",u+i);
    int t1,t2;
    rep(i,0,m){
        scanf("%d%d",&t1,&t2);--t1;--t2;
        if((u[t1]+1)%h==u[t2])add_edge(t1,t2);
        if((u[t2]+1)%h==u[t1])add_edge(t2,t1);
    }
    int scc_cnt=SCC::calc_scc(n,sccno,head);
    rep(i,0,n)++siz[sccno[i]];

    Edge*it;
    rep(i,0,n){
        for(it=head[i];it;it=it->nxt){
            if(sccno[i]!=sccno[it->t]){
                out[sccno[i]]=1;
                break;
            }
        }
    }

    int ans_no=0;
    rep(i,0,scc_cnt)if(!out[i]){
        if(siz[i]<siz[ans_no]){
            ans_no=i;
        }
    }
    printf("%d\n",siz[ans_no]);
    rep(i,0,n)if(sccno[i]==ans_no)printf("%d ",i+1);
    return 0;
}
