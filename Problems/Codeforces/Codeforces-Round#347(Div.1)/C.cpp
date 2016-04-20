#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define x first
#define y second
#define mp make_pair
#define pb push_back
template<class T> void rd(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
/****head****/
using namespace std;
const int Max_N = 2e5;
int n, m, u[Max_N], v[Max_N], d[Max_N];
int C, col[Max_N], top[2], S[2][Max_N];
vector<pair<int, int> > G[Max_N];
bool dfs(int x, int c) {
        col[x] = c;
        S[c][top[c]++] = x;
        for(auto i : G[x]) {
                int nxt = i.y == C ? c : (c^1);
                if(col[i.x] == -1) {
                        if(!dfs(i.x, nxt)) return 0;
                } else if(col[i.x] != nxt) return 0;
        }
        return 1;
}
void gao(vector<int>&res, int c) {
        C = c;
        memset(col, -1, sizeof col);
        bool fg = 1;
        res.clear();
        for(int i = 0; i < n; ++i) if(col[i] == -1) {
                top[0] = top[1] = 0;
                if(!dfs(i, 0)) {
                        fg = 0; break;
                }
                int id = 0;
                if(top[1] <= top[0]) id = 1;
                while(top[id]) res.pb(S[id][--top[id]]);
        }
        if(!fg) res.resize(n+1, 0);
}
void output(vector<int>&an) {
        if(SZ(an) == n+1) puts("-1");
        else {
                printf("%d\n", SZ(an));
                bool fg = 0;
                for(int i : an) {
                        if(fg) printf(" ");
                        fg = 1;
                        printf("%d", i + 1);
                }
                puts("");
        }
}
int main() {
        scanf("%d%d", &n, &m);
        char s[111];
        for(int i = 0, u, v; i < m; ++i) {
                scanf("%d%d%s", &u, &v, s); --u; --v;
                G[u].pb(mp(v, s[0]=='R'));
                G[v].pb(mp(u, s[0]=='R'));
        }
                
        vector<int> ans, res;
        gao(ans, 0);
        gao(res, 1);
        if(SZ(ans) <= SZ(res)) output(ans);
        else output(res);
        return 0;
}
