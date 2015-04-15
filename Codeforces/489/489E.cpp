#include<bits/stdc++.h>
const int N = 1010;
int n, l;
int x[N], v[N], pre[N];
double dp[N];
bool use[N];
bool check (double A){
        double minv, tmp;
        for (int i = 1, j; i <= n; ++i){
                minv = sqrt (abs (x[i] - l) + 0.0);
                pre[i] = 0;
                for (j = 1; j < i; ++j){
                        tmp = dp[j] + sqrt (abs (x[i] - x[j] - l) + 0.0);
                        if (tmp < minv) minv = tmp, pre[i] = j;
                }
                dp[i] = minv - A * v[i];
        }
        return dp[n] <= 0;
}
int main(){
        scanf ("%d%d", &n, &l);
        for (int i = 1; i <= n; ++i)
                scanf ("%d%d", x + i, v + i);
        double l = 0, r = 1e8, mid;
        for (int _ = 0; _ < 100; ++_){
                mid = (l + r) / 2;
                check(mid) ? r = mid : l = mid;
        }
        check (l);
        std::vector<int> ans;
        for (int i = n; i; i = pre[i]){
                ans.push_back (i);
        }
        std::sort (ans.begin(), ans.end());
        n = ans.size();
        for (int i = 0; i < n; ++i)
                printf ("%d%c", ans[i], " \n"[i==n-1]);
        return 0;
}
