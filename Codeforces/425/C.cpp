#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
const int Max_N = 9 + (int)1e5;
int a[Max_N], b[Max_N];
std::vector<int> vec[Max_N];
std::vector<int>::iterator it;
int dp[Max_N][303];
int main()
{
        int n, m, s, e, up;
        std::cin >> n >> m >> s >> e; up = s / e;
        if(!up) return puts("0"), 0;
        for(int i = 0; i < n; ++i) scanf("%d", a + i);
        for(int i = 0; i < m; ++i) scanf("%d", b + i), vec[b[i]].push_back(i);

        int ans = 0;
        memset(dp, 127, sizeof dp);
        dp[0][0] = -1;
        if(!vec[a[0]].empty()) {
                dp[0][1] = vec[a[0]][0];
                if(e + 2 + vec[a[0]][0] <= s) ans = 1;
        }
        for(int j, i = 0; i < n-1; ++i) 
                for(j = 0; j < up; ++j) {
                        chmin(dp[i+1][j], dp[i][j]);
                        it = upper_bound(vec[a[i+1]].begin(), vec[a[i+1]].end(), dp[i][j]);
                        if(it != vec[a[i+1]].end()) {
                                if(chmin(dp[i+1][j+1], *it) && j + 1 > ans && (j+1)*e + i + 3 + (*it) <= s) ans = j + 1;
                        }
                }
        return printf("%d\n", ans), 0;
}
