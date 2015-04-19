#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
/****head****/
const int Max_N = 9 + (int)1e5;
bool vis[10];
int a[Max_N];
int main() {
        //freopen("a.in","r",stdin);
        //freopen("my.out","w",stdout);
        long long sum, ans;
        int _; Read(_);
        for(int n, k; _--; ) {
                Read(n); Read(k);

                memset(vis, 0, sizeof vis);
                sum = 0;
                for(int i = 0, t; i < k; ++i) {
                        Read(t);
                        a[i] = t;
                        if(t < 10) vis[t] = 1;
                        sum += t;
                }
                ans = n * (n+1ll) / 2 - sum + 1;

                std::sort(a, a + k);
                sum = 0;
                for(int i = 0; i < k; ++i) {
                        sum += a[i];
                        if(a[i] * (a[i]+1ll) / 2 - sum < a[i]) {
                                ans = a[i]; break;
                        }
                }

                if(vis[1]) ans = 1;
                else if(vis[2]) ans = 2;
                else if(vis[3] && vis[4]) ans = 4;
                puts(ans & 1 ? "Chef" : "Mom");
        }
        return 0;
}
