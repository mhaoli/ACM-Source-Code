#include<bits/stdc++.h>
char str[55];
long long dp[55];
int main(){
        int n;
        scanf ("%d", &n);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) dp[i] = dp[i-1]<<1|1;
        scanf ("%s", str);
        long long ans = 0;
        for (int i = 0; i < n; ++i){
                if (str[i] == 'B') ans += 1 + dp[i];
        }
        printf ("%I64d\n", ans);
        return 0;
}
