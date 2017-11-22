//Create Time: 2017-11-21 15:55:04
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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
/****head****/
const int Max_N=(int)1e6+9;
struct Edge{
    int t;
    ll w;
    Edge *nxt;
    Edge(){}
    Edge(int _t,ll _w):t(_t),w(_w){}
    void set(int _t, long long _w, Edge *n){
        t = _t; w = _w; nxt = n;
    }
};
Edge pool[Max_N], *head[Max_N], *bat;
void init_graph(int n){
    bat = pool;
    memset(head, 0, n * sizeof head[0]);
}
void add_edge(int s, int t, long long w){
    bat->set(t, w, head[s]); head[s]=bat++;
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
namespace Top_Sort{
    int in[Max_N];
    void sort(int n, int *top, Edge *hd[]){
        memset(in, 0, n * sizeof in[0]);
        set<pii> has;
        rep(i, 0, n){
            for(Edge *p = hd[i]; p; p = p->nxt){
                ++in[p->t];
            }
        }
        int idx = 0;
        rep(i, 0, n){
            has.insert(pii(in[i],i));
        }
        while(!has.empty()){
            top[idx++] = has.begin()->second;
            has.erase(has.begin());
            for(Edge *p = hd[top[idx-1]]; p; p = p->nxt){
                int tar = p->t;
                has.erase(pii(in[tar],tar));
                has.insert(pii(--in[tar],tar));
            }
        }
    }
}
int sccno[Max_N],top[Max_N];
ll cost[Max_N],dp[Max_N];
map<pii,ll> ch;
ll calc_cost(ll w){
    ll t=sqrt(w*2)+5ll;
    while((t+1)*t>w*2)t--;
    return (t+1)*w - t*(t+1)*(t+2)/6;
}
int main(){
    int n,m;scanf("%d%d",&n,&m);
    init_graph(n);
    rep(i,0,m){
        int s,t,w;
        scanf("%d%d%d",&s,&t,&w);--s;--t;
        add_edge(s,t,w);
    }
    int start;scanf("%d",&start);--start;
    int sn=SCC::calc_scc(n,sccno,head);
    // OUT(sn);
    // rep(i,0,n) TST(i),OUT(sccno[i]);
    rep(i,0,n)for(Edge *p=head[i];p;p=p->nxt){
        if(sccno[i]==sccno[p->t]){
            cost[sccno[i]]+=calc_cost(p->w);
        }else{
            pii tpr=pii(sccno[i],sccno[p->t]);
            ch[tpr]=max(ch[tpr],p->w);
        }
    }
    init_graph(sn);
    for(auto &it:ch){
        add_edge(it.x.x,it.x.y,it.y);
    }
    Top_Sort::sort(sn,top,head);
    memset(dp,-1,sizeof dp);
    dp[sccno[start]]=0;
    ll ans=0;
    rep(i,0,sn)if(~dp[top[i]]){
        int s=top[i];
        dp[s]+=cost[s];
        chmax(ans,dp[s]);
        for(Edge*p=head[s];p;p=p->nxt){
            chmax(dp[p->t], dp[s]+p->w);
        }
    }
    cout<<ans<<endl;
    return 0;
}
