#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
/****head****/
const int Max_N = 1e5 + 9;
struct Edge {
        int e;
        Edge*nxt;
        void add(int te, Edge*n) {
                e = te;
                nxt = n;
        }
};
Edge E[Max_N << 1], *head[Max_N], *bat;
void adde(int s, int e) {
        bat->add(e, head[s]); head[s] = bat++;
}
int _;
void init(int n) {
        bat = E;
        for(int i = 0; i < n; ++i) {
                head[i] = 0;
        }
}
long long f[Max_N], up = 1e10 + 9, sum[Max_N];
int an[Max_N], sz[Max_N], dep[Max_N];
int top = 0;
std::pair<int, int> vec[Max_N];
void dfs(int u, int pre) {
        vec[top].first = dep[u];
        vec[top].second = dep[u] + an[u];
        ++top;
        for(Edge*p = head[u]; p; p = p->nxt) if(p->e != pre) {
                dfs(p->e, u);
                dep[p->e] = dep[u] + 1;
        }
}
int main() {
        for(scanf("%d", &_); _--; ) {
                int n, s;
                scanf("%d%d", &n, &s);
                --s;
                init(n);
                for(int i = 0, s, e; i < n-1; ++i) {
                        scanf("%d%d", &s, &e); --s; --e;
                        adde(s, e);
                        adde(e, s);
                }

                for(int i = 0; i < n; ++i) {
                        scanf("%d", an + i);
                }
                
                long long ans = 0, mx;
                for(Edge*p = head[s]; p; p = p->nxt) {
                        dep[p->e] = 0;
                        top = 0;
                        dfs(p->e, s);

                        std::sort(vec, vec + top);
                        mx = -1;
                        for(int i = 0; i < top; ++i) {
                                if(vec[i].first < mx) {
                                        mx += vec[i].second - vec[i].first;
                                } else {
                                        mx = vec[i].second;
                                }
                        }
                        chmax(ans, mx);
                }
                static int cas = 1;
                std::cout << "Case #" << cas << ": " << ans << "\n";
                ++cas;
        }
        return 0;
}
