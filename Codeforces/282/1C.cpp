#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
const int Max_N = 5009;
struct RMQ {
        const static int Max_N = 9 + (int)1e5;
        int lg2[Max_N], mx[Max_N][22];
        void init(int *a, int n) {
                for (int i = 0; i < n; ++ i){
                        mx[i][0] = a[i];
                        lg2[i] = (!i ? -1 : lg2[i>>1] + 1);
                }
                lg2[n] = lg2[n>>1] + 1;
                for (int j = 1, l = 2; l <= n; ++ j, l <<= 1){
                        for (int i = 0; i + l - 1 < n; ++ i)
                                mx[i][j] = std::max (mx[i][j-1], mx[i+(l>>1)][j-1]);
                }

        }
        int calc(int a, int b) {
                int k = lg2[b - a + 1];
                return std::max(mx[a][k], mx[b-(1<<k)+1][k]);
        }
}rmq;
struct Node {
        int l, r;
        double p;
        bool operator<(const Node&t) const {
                return l == t.l ? r > t.r : l < t.l;
        }
        void read() {
                scanf("%d%d%lf", &l, &r, &p); --l; --r;
        }
} b[Max_N];
std::vector<int> son[Max_N];
int f[Max_N], n, m, a[111111];
double dp[Max_N][Max_N], sum[Max_N][Max_N];
void dfs(int x, int pre) {
        f[x] = pre;
        if(~pre) son[pre].push_back(x);
        if(x + 1 < m && b[x].l == b[x+1].l && b[x].r == b[x+1].r) dfs(x + 1, x);
        else for(int i = x+1, j; i < m && b[i].r <= b[x].r; ++i) {
                dfs(i, x);
                for(j = i+1; j < m && b[j].l <= b[i].r; ++j);
                i = j - 1;
        }
}
void calc(int x) {
        bool u = 0;
        int i, t, mx, MX = rmq.calc(b[x].l, b[x].r);
        double p = b[x].p, ts;

        dp[x][0] = 1;
        dp[x][1] = 0;
        for(i = 0; i < m; ++i) sum[x][i] = 1;
        snuke(it, son[x]) {
                calc(*it);
                mx = rmq.calc(b[*it].l, b[*it].r);

                ts = 0;
                for(i = 0; i < m; ++i) {
                        t = std::max(mx + i - MX, 0);
                        if(mx + i - MX >= 0 || i == m-1) {
                                if(!t) dp[x][t] = dp[x][t] * (dp[*it][i] + ts);
                                else dp[x][t] = (dp[x][t] * ts + sum[x][t-1] * dp[*it][i] + dp[x][t] * dp[*it][i]);
                        }
                        ts += dp[*it][i];
                }

                sum[x][0] = dp[x][0];
                for(i = 1; i < m; ++i)
                        sum[x][i] = sum[x][i-1] + dp[x][i];
        }
        for(i = m-1; i >= 0; --i) {
                dp[x][i] = dp[x][i] * (1 - p);
                if(i) dp[x][i] += dp[x][i-1] * p;
        }
}
int main() {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i) {
                scanf("%d", a + i);
        }
        rmq.init(a, n);

        ++m;
        b[0].l = 0; b[0].r = n-1; b[0].p = 0;
        for(int i = 1; i < m; ++i) {
                b[i].read();
        }
        std::sort(b, b + m);

        memset(f, -1, sizeof f);
        dfs(0, -1);
        calc(0);

        //for(int i = 0; i < m; ++i) {
                //for(int j = 0; j < m; ++j)
                        //printf("%.5f ", dp[i][j]);
                //puts("");
        //}
//
        int mx = rmq.calc(0, n-1);
        double ans = 0;
        for(int i = 0; i < m; ++i) ans += (mx + i) * dp[0][i];
        printf("%.7f\n", ans);
        return 0;
}
