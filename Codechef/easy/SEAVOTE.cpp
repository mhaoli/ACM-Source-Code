#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
int main() {
        int _; scanf("%d", &_);
        for(int n, sum, tot; _--; ) {
                scanf("%d", &n);
                bool ans = 1;
                tot = sum = 0;
                for(int i = 0, t; i < n; ++i) {
                        scanf("%d", &t);
                        if(t > 100) ans = 0;
                        if(t) ++tot;
                        sum += t;
                }
                if(ans && sum >= 100 && sum < 100 + tot) puts("YES");
                else puts("NO");
        }
        return 0;
}
