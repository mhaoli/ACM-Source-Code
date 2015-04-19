#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
/****head****/

const int Max_N = 9 + (int)1e5;
int gd[Max_N][30], lg2[Max_N];
void init(int n, int *a){ //a: 0...n-1
        for (int i = 0; i < n; ++ i){
                gd[i][0] = a[i];
                lg2[i] = (!i ? -1 : lg2[i>>1] + 1);
        }
        lg2[n] = lg2[n>>1] + 1;
        for (int j = 1, l = 2; l <= n; ++ j, l <<= 1){
                for (int i = 0; i + l - 1 < n; ++ i)
                        gd[i][j] = std::__gcd(gd[i][j-1], gd[i+(l>>1)][j-1]);
        }
}
int query (int a, int b){ //[a, b]
        int k = lg2[b - a + 1];
        return std::__gcd(gd[a][k], gd[b-(1<<k)+1][k]);
}

int a[Max_N];
int main() {
        int _; Read(_);
        for(int n, nq; _--; ) {
                Read(n); Read(nq);
                for(int i = 0; i < n; ++i) Read(a[i]);
                init(n, a);
                for(int l, r, ans; nq--; ) {
                        Read(l); Read(r); --l; --r;
                        ans = 0;
                        if(l) ans = std::__gcd(ans, query(0, l-1));
                        if(r < n-1) ans = std::__gcd(ans, query(r+1, n-1));
                        printf("%d\n", ans);
                }
        }
        return 0;
}
