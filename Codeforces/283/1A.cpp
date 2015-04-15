#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
char s[1005][1005];
bool vis[1005];
int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i) {
                scanf("%s", s[i]);
        }
        int ans = 0;
        for(int j = 0, i; j < m; ++j) {
                bool u = 0;
                for(i = 0; i < n-1; ++i) if(!vis[i]){
                        if(s[i][j] > s[i+1][j]) u = 1;
                }
                if(u) ++ans;
                else for(i = 0; i < n-1; ++i) if(!vis[i] && s[i][j] < s[i+1][j]) vis[i] = 1;
        }
        printf("%d\n", ans);
        return 0;
}
