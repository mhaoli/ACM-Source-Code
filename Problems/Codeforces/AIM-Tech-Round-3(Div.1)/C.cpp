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
const int Max_N = 400000;
vector<int> m[Max_N];
int ans[Max_N], f[Max_N], sz[Max_N], dp0[Max_N], dp1[Max_N], idx[Max_N];
int n, bound;
int chk(int x) {
        if(x > bound) return 0;
        return x;
}
void dfs(int x, int fa) {
        sz[x] = 1;
        f[x] = fa;
        for(int i = 0, mx, son; i < SZ(m[x]); ++i){
                son = m[x][i];
                if(fa == son) continue;
                dfs(son, x);
                sz[x] += sz[son];
                mx = max(chk(sz[son]), dp0[son]);
                if(mx > dp0[x]) {
                        idx[x] = son;
                        dp1[x] = dp0[x];
                        dp0[x] = mx;
                } else if(mx > dp1[x]) {
                        dp1[x] = mx;
                }
        }
}
void dfs2(int x, int mx) {
        if(n - sz[x] - mx > bound) ans[x] = 0;
        int tmx = max(chk(n - sz[x]), mx);
        for(int i = 0, son; i < SZ(m[x]); ++i) {
                son = m[x][i];
                if(f[x] == son) continue;
                
                if(sz[son] - dp0[son] > bound)
                        ans[x] = 0;
                if(idx[x] == son)
                        dfs2(son, max(tmx, dp1[x]));
                else
                        dfs2(son, max(tmx, dp0[x]));
        }
}
int main() {
        scanf("%d", &n);
        bound = n / 2;
        for(int i = 0; i < n-1; ++i) {
                int a, b;
                scanf("%d%d", &a, &b);
                m[--a].pb(--b);
                m[b].pb(a);
        }

        for(int i = 0; i < n; ++i) {
                ans[i] = 1;
        }
        memset(dp0, 0, sizeof dp0);
        memset(dp1, 0, sizeof dp1);
        dfs(0, -1);
        dfs2(0, 0);

        for(int i = 0; i < n; ++i) {
                if(i) printf(" ");
                printf("%d", ans[i]);
        }
        puts("");
        return 0;
}
