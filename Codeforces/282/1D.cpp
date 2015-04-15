#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
const int Max_N = 9 + (int)1e5;
const long long mod = 7 + (int)1e9;
std::vector<std::pair<int, int> > E[Max_N];
int n, clk;
int f[Max_N], dep[Max_N], len[Max_N], le[Max_N], ri[Max_N], fc[Max_N];
int sz[Max_N], s1[Max_N], s2[Max_N], rsz[Max_N], rs1[Max_N], rs2[Max_N], S1;
void add(int &a, int b) {
        a += b; if(a >= mod) a -= mod;
}
void dfs(int u) {
        le[u] = clk++;
        sz[u] = 1; s1[u] = 0; s2[u] = 0;
        snuke(it, E[u]) if(it->first != f[u]) {
                f[it->first] = u;
                dep[it->first] = dep[u] + 1;
                len[it->first] = len[u];
                add(len[it->first], fc[it->first] = it->second);

                dfs(it->first);

                sz[u] += sz[it->first];
                add(s1[u], s1[it->first]);
                add(s1[u], (long long)sz[it->first] * it->second % mod);
                add(s2[u], s2[it->first]);
                add(s2[u], (long long)it->second * it->second % mod * sz[it->first] % mod);
                add(s2[u], 2ll * it->second * s1[it->first] % mod);
        }
        ri[u] = clk - 1;
}
int belong[Max_N], q[Max_N];
void bfs() {
        memset(belong, -1, sizeof belong);
        q[0] = 0;
        for(int u, mx, id, ql = 0, qr = 1; ql != qr; ++ql) {
                u = q[ql]; mx = -1; 
                if(belong[u] == -1) belong[u] = u;
                snuke(it, E[u]) if(it->first != f[u]){
                        q[qr++] = it->first;
                        if(mx < sz[it->first]) mx = sz[id = it->first];
                }
                if(mx != -1) belong[id] = belong[u];
        }
        for(int u, fu, c, t, i = 1; i < n; ++i) {
                u = q[i]; fu = f[u]; c = fc[u];
                rsz[u] = n - sz[u];
                rs1[u] = rs1[fu]; 
                add(rs1[u], s1[fu]);
                add(rs1[u], mod - s1[u]);
                t = n; add(t, mod - sz[u]); add(t, mod - sz[u]);
                add(rs1[u], (long long)c * t % mod);

                rs2[u] = rs2[fu];
                add(rs2[u], s2[fu]);
                add(rs2[u], mod - s2[u]);
                t = rs1[fu]; add(t, s1[fu]); add(t, mod - s1[u]); add(t, mod - s1[u]);
                add(rs2[u], 2ll * c * t % mod);
                t = n; add(t, mod - 4 * sz[u]);
                add(rs2[u], (long long)c * c % mod * t % mod);
        }
}
int LCA(int x, int y) {
        while(1) {
                if(dep[x] < dep[y]) std::swap(x, y);
                if(belong[x] == belong[y]) return y;
                if(dep[belong[x]] < dep[belong[y]]) std::swap(x, y);
                x = f[belong[x]];
        }
}
int main() {
        //freopen("a.in","r",stdin);
        //freopen("a.out","w",stdout);
        scanf("%d", &n);
        for(int i = 0, u, v, c; i < n-1; ++i) {
                scanf("%d%d%d", &u, &v, &c);
                E[--u].push_back(std::make_pair(--v, c));
                E[v].push_back(std::make_pair(u, c));
        }
        f[0] = -1; fc[0] = dep[0] = len[0] = 0;
        dfs(0);
        rsz[0] = rs1[0] = rs2[0] = 0;
        bfs();

        //for(int i = 0; i < n; ++i) {
                //printf("%d %d %d %d\n", i, sz[i], s1[i], s2[i]);
        //}
        //puts("");
        //for(int i = 0; i < n; ++i) {
                //printf("%d %d %d %d\n", i, rsz[i], rs1[i], rs2[i]);
        //}

        int nq; scanf("%d", &nq);
        for(int u, v, ans, A, d; nq--; ) {
                scanf("%d%d", &u, &v); --u; --v;
                //printf("%d %d : ", u, v);
                if(le[v] <= le[u] && le[u] <= ri[v]) {
                        d = len[u]; add(d, mod - len[v]);
                        ans = (long long)d * d % mod * rsz[v] % mod;
                        add(ans, 2ll * d * rs1[v] % mod);
                        add(ans, rs2[v]);
                        ans = mod - (ans * 2 % mod);
                        add(ans, s2[u]); add(ans, rs2[u]);
                } else {
                        A = LCA(u, v);
                        d = len[u]; add(d, len[v]); add(d, mod - len[A]); add(d, mod - len[A]);
                        ans = (long long)d * d % mod * sz[v] % mod;
                        add(ans, 2ll * d * s1[v] % mod);
                        add(ans, s2[v]);
                        ans = ans * 2 % mod;
                        add(ans, mod - s2[u]); add(ans, mod - rs2[u]);
                }
                printf("%d\n", ans);
        }
        return 0;
}
