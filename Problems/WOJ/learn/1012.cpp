#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
char str[2222];
int cnt[2222], pre[2222], n, m;
long long ans, dp[2222];
void init() {
        scanf("%s", str);
        cnt[0] = pre[0] = 0;
        for(int i = 1; i <= m; ++i) cnt[i] = str[i-1] == 'w' ? cnt[i]+1 : 0;
}
void DP();
int main() {
        while(scanf("%d%d", &n, &m) != EOF) {
                ans = 0;
                memset(cnt, 0, sizeof cnt);
                for(int i = 0; i < n; ++i) {
                        init();
                        DP();
                }
                printf("%lld\n", ans);
        }
        return 0;
}
void DP() {
        for(int i = 1, tmp; i <= m; ans += dp[i++]) {
                if(cnt[i] >= cnt[i-1]) dp[i] = dp[i-1] + cnt[i], pre[i] = 0;
                else {
                        pre[i] = pre[i-1] + 1;
                        tmp = i - pre[i];
                        while(tmp && cnt[tmp-1] >= cnt[i]) tmp -= pre[tmp-1] + 1;
                        if(tmp <= 0) {
                                dp[i] = (long long)cnt[i] * i;
                                pre[i] = 0;
                        } else {
                                dp[i] = (long long)cnt[i] * (i - tmp + 1) + dp[tmp-1];
                                pre[i] = i - tmp - 1;
                        }
                }
        }
}
