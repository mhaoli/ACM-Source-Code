#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
const double inf = 1e9;
int n, l;
int a[1111], x[1111], pre[1111], stk[1111];
double dp[1111];
double dis(int t1, int t2) {
        return sqrt(fabs(x[t2] - x[t1] - l + 0.0));
}
bool check(double t, bool fg) {
        dp[0] = 0;
        for(int i = 1; i <= n; ++i) dp[i] = inf;
        double tmp, mi;
        for(int j, pos, i = 1; i <= n; ++i) {
                mi = inf;
                for(j = 0; j < i; ++j) {
                        tmp = dp[j] + dis(j, i);
                        if(tmp < mi) mi = tmp, pos = j;
                }
                dp[i] = mi - t * a[i];
                pre[i] = pos;
        }
        if(!fg) return dp[n] <= 0.0;
        int top = 0;
        for(int p = n; p; p = pre[p]) stk[top++] = p;
        for(; top; ) printf("%d%c", stk[--top], " \n"[top==1]);
}
int main()
{
        std::cin >> n >> l;
        for(int i = 1; i <= n; ++i)
                scanf("%d%d", x + i, a + i);
        x[0] = 0;
        double l = 0, r = inf, m;
        for(int _ = 0; _ < 100; ++_) {
                m = (l + r) / 2.0;
                if(check(m, 0)) r = m;
                else l = m;
        }
        check(l, 1);
        return 0;
}
