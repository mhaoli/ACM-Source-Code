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
int _;
const int mod = (int)1e9 + 7;
inline void add(int &a, int b) {
        a += b;
        if(a >= mod) a -= mod;
}
struct SegmentTree {
#define lson l, mid, rt<<1
#define rson mid+1, r, rt<<1|1
        const static int Max_N = 1<<20;
        int n;
        int s[Max_N];
        long long laz[Max_N];
        void init(int l, int r, int rt) {
                s[rt] = 0; laz[rt] = 1;
                if(l == r) return;
                int mid = l + r >> 1;
                init(lson); init(rson);
        }
        void Down(int l, int r, int rt) {
                if(laz[rt] != 1) {
                        laz[rt<<1] = laz[rt<<1] * laz[rt] % mod;
                        laz[rt<<1|1] = laz[rt<<1|1] * laz[rt] % mod;
                        s[rt<<1] = s[rt<<1] * laz[rt] % mod;
                        s[rt<<1|1] = s[rt<<1|1] * laz[rt] % mod;
                        laz[rt] = 1;
                }
        }
        void Up(int l, int r, int rt) {
                s[rt] = s[rt<<1];
                add(s[rt], s[rt<<1|1]);
        }
        void addV(int q, int v, int l, int r, int rt) {
                if(l == r) {
                        s[rt] = laz[rt] * v % mod;
                        return ;
                }
                int mid = l + r >> 1;
                Down(l, r, rt);
                if(q <= mid) addV(q, v, lson);
                else addV(q, v, rson);
                Up(l, r, rt);
        }
        void modify(int ql, int qr, int v, int l, int r, int rt) {
                if(ql <= l && qr >= r) {
                        long long xt = pow_mod(v, mod-2, mod) * (v+1) % mod;
                        laz[rt] = laz[rt] * xt % mod;
                        s[rt] = s[rt] * xt % mod;
                        return;
                }

                int mid = l + r >> 1;
                Down(l, r, rt);
                if(ql <= mid) modify(ql, qr, v, lson);
                if(qr > mid) modify(ql, qr, v, rson);
                Up(l, r, rt);
        }
        int queryP(int p, int l, int r, int rt) {
                if(l == r) return laz[rt];

                int mid = l + r >> 1, ret;
                Down(l, r, rt);
                if(p <= mid) ret = queryP(p, lson);
                else ret = queryP(p, rson);
                Up(l, r, rt);
                return ret;
        }
        int queryS(int ql, int qr, int l, int r, int rt) {
                if(ql <= l && r <= qr) {
                        return s[rt];
                }

                int mid = l + r >> 1, ret = 0;
                Down(l, r, rt);
                if(ql <= mid) add(ret, queryS(ql, qr, lson));
                if(qr > mid) add(ret, queryS(ql, qr, rson));
                Up(l, r, rt);
                return ret;
        }

        void init(int n) {
                this->n = n;
                init(0, n-1, 1);
        }
        int query(int r) {
                return queryP(r, 0, n-1, 1);
        }
        int sum(int l, int r) {
                return queryS(l, r, 0, n-1, 1);
        }
        void addV(int r, int v) {
                addV(r, v, 0, n-1, 1);
        }
        void modify(int l, int r, int v) {
                modify(l, r, v, 0, n-1, 1);
        }
}tree;

int n, clk;
int ln[1<<18], rn[1<<18];
vector<int> son[1<<18], que[1<<18];
int du[1<<18], fa[1<<18];
void addE(int x, int y) {
        son[x].push_back(y);
}
void dfs(int x, int pre) {
        fa[x] = pre;
        ln[x] = ++clk;
        for(auto i : son[x]) {
                dfs(i, x);
        }
        rn[x] = clk;
}
int main() {
        //freopen("a.out","w",stdout);
        int v, q;
        n = 1;
        cin >> v >> q;
        for(int i = 0, t1, op; i < q; ++i) {
                scanf("%d%d", &op, &t1);
                que[i].push_back(--t1);
                if(op == 1) {
                        addE(t1, n++);
                        scanf("%d", &t1);
                        que[i].push_back(t1);
                }
        }

        clk = -1;
        dfs(0, -1);

        tree.init(n);
        tree.addV(ln[0], v);

        //for(int i = 0; i < n; ++i) {
                //printf("%d : %d\n", i, ln[i]);
        //}
//
        n = 1; du[0] = 1;
        long long tmp;
        for(int i = 0; i < q; ++i) {
                if(SZ(que[i]) == 1) {
                        int t = que[i][0];
                        if(t == 0) tmp = 1;
                        else tmp = pow_mod(tree.query(ln[fa[t]]), mod-2, mod);
                        printf("%d\n", (int)(tree.sum(ln[t], rn[t]) * tmp % mod));
                } else {
                        int t1 = que[i][0], t2 = que[i][1];
                        tree.modify(ln[t1], rn[t1], du[t1]);
                        //printf("%d ----- %d\n", i, ln[n]);
                        tree.addV(ln[n], t2);
                        ++du[t1];
                        du[n++] = 1;
                }
                //for(int i = 0; i < n; ++i) {
                        //cout << tree.query(ln[i]) << " " << tree.sum(ln[i], rn[i]) << endl;
                //}
        }
        return 0;
}
