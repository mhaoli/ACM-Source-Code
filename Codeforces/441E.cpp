#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
const int Max_N = 205;
double dp[Max_N][Max_N];
int len(int x) {
        int ret = 0;
        for(; !(x & 1); x >>= 1, ++ret);
        return ret;
}
int main() {
        int x, K, pp;
        scanf("%d%d%d", &x, &K, &pp);
        double p = pp / 100.0;
        for(int i = 0, j; i <= K; ++i) {
                for(j = 0; j <= K; ++j) {
                        if(!i) dp[0][j] = len(x + j);
                        else {
                                dp[i][j] += dp[i-1][j+1] * (1 - p);
                                if(!(j & 1)) dp[i][j] += p * (dp[i-1][j>>1] + 1);
                        }
                }
        }
        printf("%.7f\n", dp[K][0]);
        return 0;
}
