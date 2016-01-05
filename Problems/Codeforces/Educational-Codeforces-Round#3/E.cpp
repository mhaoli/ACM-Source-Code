#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
using namespace std;
/****head****/
const int Max_N = 1 << 18;
namespace SegmentTree {
#define lson l, mid, rt<<1
#define rson mid+1, r, rt<<1|1
        int mx[Max_N<<2];
        int n;
        void init(int _n) {
                n = _n;
                memset(mx, 0, sizeof mx);
        }
        void Up(int l, int r, int rt) {
                mx[rt] = max(mx[rt<<1], mx[rt<<1|1]);
        }
        int query(int ql, int qr, int l = 0, int r = n-1, int rt = 1) {
                if(ql <= l && qr >= r) {
                        return mx[rt];
                }

                int mid = l + r >> 1, ret = 0;
                if(ql <= mid) chmax(ret, query(ql, qr, lson));
                if(qr > mid) chmax(ret, query(ql, qr, rson));
                return ret;
        }
        void modify(int p, int v, int l = 0, int r = n-1, int rt = 1) {
                if(l == r) {
                        mx[rt] = v;
                        return;
                }

                int mid = l + r >> 1;
                if(p <= mid) modify(p, v, lson);
                else modify(p, v, rson);
                Up(l, r, rt);
        }
}
struct Edge {
        int u, v, w;
        Edge *nxt;
        void Set(int _u, int _v, int _w, Edge*n) {
                u = _u; v = _v; w = _w; nxt = n;
        }
};
struct Tree {
        //Tree
        Edge E[Max_N<<1];
        Edge*head[Max_N], *mem;
        int n;
        void init(int n) {
                this->n = n;
                mem = E;
                memset(head, 0, sizeof head);
        }
        void addE(int u, int v, int w) {
                mem->Set(u, v, w, head[u]);
                head[u] = mem++;
        }

        //LCA
        int Q[Max_N], siz[Max_N], dep[Max_N], belong[Max_N], fa[Max_N];
        void LAC_init(int rt) {
                memset(belong, -1, sizeof belong);
                memset(siz, 0, sizeof siz);

                int l = 0, r = 1;
                Q[0] = rt; dep[rt] = 0; fa[rt] = -1;
                while(l < r) {
                        int x = Q[l++];
                        for(Edge*p = head[x]; p; p = p->nxt) if(p->v != fa[x]){
                                fa[p->v] = x;
                                dep[p->v] = dep[x] + 1;
                                Q[r++] = p->v;
                        }
                }

                for(int i = r-1; i; --i) siz[fa[Q[i]]] += ++siz[Q[i]];
                belong[rt] = rt;
                for(int i = 0; i < r; ++i) {
                        int t = Q[i], ma = -1, son = -1;
                        if(belong[t] == -1) belong[t] = t;
                        for(Edge*p = head[t]; p; p = p->nxt) if(p->v != fa[t] && siz[p->v] > ma){
                                ma = siz[p->v];
                                son = p->v;
                        }
                        if(son != -1) belong[son] = belong[t];
                }
        }
        int LCA(int x, int y) {
                while(1) {
                        if(dep[x] > dep[y]) std::swap(x, y);
                        if(belong[x] == belong[y]) return x;
                        if(dep[belong[x]] < dep[belong[y]]) std::swap(x, y);
                        x = fa[belong[x]];
                }
                return y;
        }

        //specific
        vector<pair<int, int> > q[Max_N];
        //SegmentTree SegTree;
        void calc(int*ans) {
                SegmentTree::init(*max_element(dep, dep + n) + 1);
                dfs(0, -1, ans);
        }
        void dfs(int x, int pre, int *ans) {
                for(auto it : q[x]) {
                        chmax(ans[it.second], SegmentTree::query(dep[it.first], dep[x]-1));
                }
                for(Edge*p = head[x]; p; p = p->nxt) {
                        if(p->v == pre) continue;
                        SegmentTree::modify(dep[x], p->w);
                        dfs(p->v, x, ans);
                }
        }
}tree;
int _;
vector<pair<pair<int, int>, pair<int, int> > > vec;
vector<pair<int, int> > Q;
int f[1<<18], ans[1<<18], Ew[1<<18];
bool inMst[1<<18];
int find(int x) {
        return x == f[x] ? f[x] : f[x] = find(f[x]);
}
long long Kruskal(int n) {
        for(int i = 0; i < n; ++i) {
                f[i] = i;
        }
        memset(inMst, 0, sizeof inMst);
        sort(ALL(vec));

        long long sum = 0;
        for(auto it : vec) {
                int t1 = find(it.second.first), t2 = find(it.second.second);
                if(t1 == t2) continue;
                sum += it.first.first;
                inMst[it.first.second] = true;
                tree.addE(it.second.first, it.second.second, it.first.first);
                tree.addE(it.second.second, it.second.first, it.first.first);
                f[t1] = t2;
//
                //printf("Edge : %d %d %d\n", it.second.first, it.second.second, it.first.first);
        }
        return sum;
}
int main() {
        //freopen("a.out","w",stdout);
        int n, m;
        cin >> n >> m;
        tree.init(n);

        for(int i = 0, t1, t2, v; i < m; ++i) {
                scanf("%d%d%d", &t1, &t2, &v); --t1; --t2;
                vec.push_back(make_pair(make_pair(v, i), make_pair(t1, t2)));
                Ew[i] = v;
        }
        long long Mst = Kruskal(n);

        memset(ans, 0, sizeof ans);

        tree.LAC_init(0);

        for(auto &it : vec) {
                if(inMst[it.first.second]) continue;
                int t1 = it.second.first, t2 = it.second.second;
                int t = tree.LCA(t1, t2);
                if(t != t2) tree.q[t2].push_back(make_pair(t, it.first.second));
                if(t != t1) tree.q[t1].push_back(make_pair(t, it.first.second));
        }
        tree.calc(ans);
        for(int i = 0; i < m; ++i) {
                printf("%I64d\n", Mst + (inMst[i] ? 0 : Ew[i] - ans[i]));
        }
        return 0;
}
