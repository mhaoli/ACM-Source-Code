#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
/****head****/
const int Max_M = 4444;
int right[Max_M], left[Max_M];
int main() {
        int _; Read(_);
        for(int n; _--; ) {
                Read(n);
                memset(right, 127, sizeof right);
                memset(left, 127, sizeof left);
                for(int i = 0, l, r; i < n; ++i) {
                        Read(l); Read(r);
                        if(right[l] > r) right[l] = r;
                }
                for(int i = 0; i <= 2000; ++i) if(right[i] < 3000) left[right[i]] = i;
                int ans = 0;
                for(int i = 2000, t, mi = -1; i >= 0; --i){
                        t = left[i];
                        if(t < 3000 && mi < t) mi = t;
                        if(mi == i) ++ans, mi = -1;
                }
                printf("%d\n", ans);
        }
        return 0;
}
