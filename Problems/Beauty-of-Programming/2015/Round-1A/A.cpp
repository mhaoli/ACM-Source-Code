#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
using namespace std;
const int Max_N = 200020;
struct Edge {
        int e;
        Edge*nxt;
        void add(int E, Edge*t) {
                e = E; nxt = t;
        }
} E[Max_N], *head[Max_N], *bat;
void add(int s, int e) {
        bat->add(e, head[s]); head[s] = bat++;
}
//set<int> has[Max_N];
map<int, int> mp[Max_N];
int _, fa[Max_N], col[Max_N], col_pre[Max_N], son[Max_N];
void dfs(int x) {
        son[x] = 0;
        for(Edge*p = head[x]; p; p = p->nxt) if(p->e != fa[x]){
                fa[p->e] = x;
                dfs(p->e);
                ++son[x];
                //++mp[x][0];
                //has[x].insert(p->e);
        }
        mp[x][0] = son[x];
}
void init(int n) {
        bat = E;
        for(int i = 0; i < n; ++i) {
                head[i] = 0;
                col_pre[i] = 0;
                col[i] = 0;
                mp[i].clear();
        }
}
int ans;
void change(int x, int y) {
        if(col[x] == y) return;
        if(x) {
                if(col[x] == col[fa[x]]) ++ans;
                if(y == col[fa[x]]) --ans;
                --mp[fa[x]][col[x]];
                ++mp[fa[x]][y];
        }
        ans += mp[x][col[x]];
        ans -= mp[x][y];
        col[x] = y;
}
int main() {
        int n, nq, t1, t2, type;
        for(scanf("%d", &_); _--; ) {
                scanf("%d", &n);
                init(n);
                for(int i = 0, s, e; i < n-1; ++i) {
                        scanf("%d%d", &s, &e); --s; --e;
                        add(s, e); add(e, s);
                }

                fa[0] = -1; dfs(0);

                ans = 1;
                static int cas = 0;
                printf("Case #%d:\n", ++cas);
                for(scanf("%d", &nq); nq--; ) {
                        scanf("%d", &type);
                        if(type == 1) {
                                printf("%d\n", ans);
                        } else {
                                scanf("%d%d", &t1, &t2); --t1;
                                change(t1, t2);
                        }
                }
        }
        return 0;
}
