#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
long long a[33], sum[1<<21];
int dp[1<<21];
int main() {
        //freopen("tst.in","r",stdin);
        //freopen("ans.out","w",stdout);
        long long S;
        int _; scanf("%d", &_);
        for(int n, m; _--; ) {
                scanf("%d%d", &n, &m);
                S = 0;
                for(int i = 0; i < n; ++i)
                        scanf("%I64d", a + i), sum[1<<i] = a[i], S += a[i];
                if(S % m) {
                        puts("no"); continue;
                } else if(!S) {
                        puts("yes"); continue;
                }
                else S /= m;
                memset(dp, 0, sizeof dp);
                for(int j, i = 1; i < (1<<n); ++i) {
                        for(j = i & (i-1); j; j = (j-1)&i) {
                                sum[i] = sum[j] + sum[i^j];
                                dp[i] = std::max(dp[i], dp[j] + dp[i^j]);
                        }
                        if(!dp[i] && sum[i] == S) dp[i] = 1;
                }
                puts(dp[(1<<n)-1] == m ? "yes" : "no");
        }
        return 0;
}
