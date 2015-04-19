#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
namespace maxflow{
        typedef int T;
        const static int Max_N = 9 + (int)2e3;
        const static int Max_E = 9 + (int)5e5;
        const static int inf = 1e6;

        template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
        template <class T> int sgn(T x) { return (x > 0) - (x < 0);}

        struct edge{
                int s, e;
                T cap, f;
                edge *nxt;
                void add (int _s, int _e, T c, edge *t){
                        f = 0; s = _s; e = _e; cap = c; nxt = t;
                }
                T flow(){ return cap - f;}
        };

        T flow;
        int n, m, s, t;         // 0,1,2...n-1
        edge memo[Max_E];        //edge
        edge *bat, *head[Max_N], *cur[Max_N];
        int d[Max_N]; // distance
        bool vis[Max_N];    

        void init(){
                bat = memo;
                memset(head, 0, sizeof head);
        }
        void add (int s, int e, T cap){
                bat -> add (s, e, cap, head[s]); head[s] = bat++;
                bat -> add (e, s, 0, head[e]); head[e] = bat++;
        }
        bool bfs(){
                std::queue<int> q;
                q.push (s); d[s] = 0;
                memset (vis, 0, sizeof vis); vis[s] = 1; 
                while (q.size ()){
                        int x = q.front(); q.pop();
                        for (edge *e = head[x]; e; e = e->nxt){
                                if (!vis[e->e] && e->flow() > 0){
                                        q.push (e->e);
                                        vis[e->e] = 1;
                                        d[e->e] = d[x] + 1;
                                }
                        }
                }
                return vis[t];
        }
        T dfs (int x, T rf){
                if (x == t || sgn(rf) == 0) return rf;
                T flow = 0, ff;
                for (edge *&e = cur[x]; e; e = e->nxt){
                        T tmp = rf; chmin(tmp, e->flow());
                        if (d[e->e] == d[x] + 1 && (ff = dfs (e->e, tmp)) > 0){
                                e->f += ff;
                                memo[(e-memo)^1].f -= ff;
                                flow += ff; rf -= ff;
                                if (sgn(rf) == 0) break;
                        }
                }
                return flow;
        }
        T maxflow(int _n, int _s, int _t){
                n = _n; flow = 0;
                s = _s; t = _t;
                while (bfs()){
                        //clr (cur, 0);
                        for (int i = 0; i < n; ++ i) cur[i] = head[i];
                        flow += dfs (s, inf);
                }
                return flow;
        }
        /*************************/
        std::vector<int> E[Max_N], vec;
        bool nodeVis[Max_N];
        void ans_dfs(int u) {
                nodeVis[u] = 1;
                vec.push_back(u);
                snuke(it, E[u]) if(!nodeVis[*it]) {
                        ans_dfs(*it); break;
                }
        }
        void output(int *a, int n) {
                for(int i = 0; i < n; ++i) if(a[i] & 1){
                        for(edge*p = head[i]; p; p = p->nxt) {
                                if(p->cap != 0 && p->f == p->cap) {
                                        E[i].push_back(p->e);
                                        E[p->e].push_back(i);
                                }
                        }
                }
                std::vector<std::vector<int> > ans;
                for(int i = 0; i < n; ++i) if(!nodeVis[i]) vec.clear(), ans_dfs(i), ans.push_back(vec);
                printf("%d\n", ans.size());
                snuke(it, ans) {
                        printf("%d", it->size());
                        snuke(it2, *it) printf(" %d", (*it2) + 1);
                        puts("");
                }
        }
}


const int Max_N = 9 + (int)1e5;
int a[209];
bool check[Max_N];
int prm[Max_N];

void init(int n = Max_N - 5) {
        int tot = 0;
        for(int i = 2, j; i <= n; ++i) {
                if(!check[Max_N]) prm[tot++] = i;
                for(j = 0; j < tot && i * prm[j] <= n; ++j) {
                        check[i * prm[j]] = 1;
                        if(i % prm[j] == 0) break;
                }
        }
}

int main() {
        init();
        int n; Read(n);
        for(int i = 0; i < n; ++i) Read(a[i]);

        maxflow::init();
        int sta = n, tar = sta + 1;
        for(int i = 0, j; i < n; ++i) if(a[i] & 1)
                for(j = 0; j < n; ++j) if((a[j] & 1) == 0 && !check[a[i]+a[j]]) {
                        maxflow::add(i, j, 1);
                }
        int t1 = 0;
        for(int i = 0; i < n; ++i) 
                if(a[i] & 1) maxflow::add(sta, i, 2), ++t1;
                else maxflow::add(i, tar, 2);
        int ans = t1 == n/2 ? maxflow::maxflow(tar + 1, sta, tar) : 0;
        if(ans != n) return puts("Impossible"), 0;
        maxflow::output(a, n);
        return 0;
}
