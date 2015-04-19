#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
//template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
//template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
using namespace std;
short int dp[404][404][404], down[404][404][404];
int a[404][404], vis[160009];
short int min(short int t1, short int t2) {
        return t1 < t2 ? t1 : t2;
}
int main()
{
        int n, m;
        scanf("%d%d", &n, &m);
        for(int j, i = 0; i < n; ++i)
                for(j = 0; j < m; ++j) scanf("%d", &a[i][j]);
        for(int i = 0, j, k; i < n; ++i) {
                for(j = 0; j < m; ++j) {
                        for(k = i+1; k < n; ++k)
                                if(a[k][j] == a[i][j]) break;
                        dp[j][j][i] = k - 1;
                }
        }
        for(int j = 0, i, k; j < m; ++j)
                for(k = j+1; k < m; ++k) {
                        memset(vis, 127, sizeof vis);
                        down[j][k][n] = n - 1;
                        for(i = n-1; i >= 0; --i) {
                                if(a[i][j] == a[i][k]) down[j][k][i] = i - 1;
                                else {
                                        down[j][k][i] = min(vis[a[i][j]], vis[a[i][k]]) - 1;
                                        down[j][k][i] = min(down[j][k][i], min((short int)n-1, down[j][k][i+1]));
                                }
                                vis[a[i][j]] = vis[a[i][k]] = i;
                        }
                }
        int ans = 1;
        for(int j = 0, i; j < m; ++j) {
                for(i = n-2; i >= 0; --i) {
                        dp[j][j][i] = min(dp[j][j][i], dp[j][j][i+1]);
                        ans = std::max(ans, dp[j][j][i] -  i + 1);
                }
        }
        for(int l = 2, i, j, k; l <= m; ++l) 
                for(i = 0, j = l - 1; j < m; ++j, ++i) for(k = 0; k < n; ++k) {
                        if(l == 2) dp[i][j][k] = down[i][j][k];
                        else dp[i][j][k] = min(min(dp[i+1][j][k], dp[i][j-1][k]), down[i][j][k]);
                        ans = max(ans, (j - i + 1) * (dp[i][j][k] - k + 1));
                }
        printf("%d\n", ans);
        return 0;
}
