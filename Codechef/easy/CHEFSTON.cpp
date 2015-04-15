#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
const int Max_N = 9 + (int)2e5;
int a[Max_N], b[Max_N];
int main() {
        int _; scanf("%d", &_);
        for(int n, m; _--; ) {
                scanf("%d%d", &n, &m);
                for(int i = 0; i < n; ++i) {
                        scanf("%d", a + i);
                }
                long long ans = 0, tmp;
                for(int i = 0; i < n; ++i) {
                        scanf("%d", b + i);
                        tmp = (long long)m / a[i] * b[i];
                        if(tmp > ans) ans = tmp;
                }
                std::cout << ans << std::endl;
        }
        return 0;
}
