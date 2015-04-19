#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define sqr(x) ((x) * (x))
const int Max_N = 404;
struct Edge {
        int u, v;
        double d;
        bool operator<(const Edge&t) const {
                return d < t.d;
        }
}E[Max_N*Max_N];
int x[Max_N], y[Max_N], cnt, f[Max_N];
std::pair<int, int> ans[Max_N];
double dis(int t1, int t2) {
        return sqrt(sqr(x[t1] - x[t2]) + sqr(y[t1] - y[t2]) + 0.0);
}
int find(int x) {
        return x == f[x] ? f[x] : f[x] = find(f[x]);
}
void kruskal(int n) {
        for(int i = 0; i < n; ++i) f[i] = i;
        std::sort(E, E + cnt);
        int tot = 0;
        for(int u, v, i = 0; i < cnt; ++i) {
                u = E[i].u; v = E[i].v;
                if(find(u) == find(v)) continue;
                f[find(u)] = find(v);
                ans[tot].first = std::min(u, v);
                ans[tot++].second = std::max(u, v);
        }
}
int main() {
        int _; scanf("%d", &_);
        for(int n; _--; ) {
                scanf("%d", &n);
                for(int i = 0; i < n; ++i) {
                        scanf("%d%d", x + i, y + i);
                }
                cnt = 0;
                for(int j, i = 0; i < n; ++i) 
                        for(j = i+1; j < n; ++j) {
                                E[cnt].u = i; E[cnt].v = j; E[cnt++].d = dis(i, j);
                        }
                kruskal(n);
                std::sort(ans, ans + n-1);
                for(int i = 0; i < n-1; ++i)
                        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
        }
        return 0;
}
