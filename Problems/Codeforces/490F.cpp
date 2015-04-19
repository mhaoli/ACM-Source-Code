#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
const int Max_N = 6009;
std::vector<int> E[Max_N], leaf, vec;
int val[Max_N], ans;
void dfs(int u, int pre) {
        int tmp = -1, pos = lower_bound(vec.begin(), vec.end(), val[u]) - vec.begin();
        if(pos == (int)vec.size()) vec.push_back(val[u]), ans = std::max(ans, pos + 1);
        else tmp = vec[pos], vec[pos] = val[u];
        snuke(it, E[u]) if(*it != pre) {
                dfs(*it, u);
        }
        if(tmp != -1) vec[pos] = tmp;
        else vec.pop_back();
}
int main() {
        int n; scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%d", val + i);
        for(int i = 0, u, v; i < n-1; ++i) {
                scanf("%d%d", &u, &v);
                E[--u].push_back(--v);
                E[v].push_back(u);
        }
        for(int i = 0; i < n; ++i) dfs(i, -1);
        printf("%d\n", ans);
        return 0;
}
