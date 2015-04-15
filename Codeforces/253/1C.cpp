#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
const int Max_N = 9 + (int)5e5;
int q[Max_N], qr;
long long ans;
void push(int t) {
        while(qr > 1 && t >= q[qr-1] && q[qr-1] <= q[qr-2]) {
                ans += std::min(q[qr-2], t);
                --qr;
        }
        q[qr++] = t;
}
int main() {
        int n;
        scanf("%d", &n);
        for(int i = 0, t; i < n; ++i) {
                scanf("%d", &t); push(t);
        }
        std::sort(q, q + qr);
        for(int i = 0; i < qr-2; ++i) ans += q[i];
        std::cout << ans << "\n";
        return 0;
}
