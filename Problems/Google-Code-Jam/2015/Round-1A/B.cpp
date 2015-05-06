#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
int n, m;
int use[1111];
//std::pair<int, int> use[1000];
long long ok(long long time) {
        if(time < 0) return 0;
        long long ret = 0;
        for(int i = 0; i < n; ++i) {
                ret += (time / use[i]) + 1;
                if(ret > m) return ret;
        }
        return ret;
}
long long solve() {
        long long l = 0, r = 100000ll * m, mid, ret = 0;
        for(; l <= r; ) {
                mid = (l + r) >> 1;
                if(ok(mid) >= m) ret = mid, r = mid - 1;
                else l = mid + 1;
        }
        return ret;
}
bool check(int t, long long time) {
        if(time % t == 0) return 1;
        return 0;
}
int main() {
        freopen("a.out","w",stdout);
        std::vector<int> Q;
        int _, cas = 0;
        scanf("%d", &_);
        while(_--) {
                scanf("%d%d", &n, &m);
                for(int i = 0; i < n; ++i) {
                        scanf("%d", use + i);
                }
                long long time = solve();
                long long cut = ok(time - 1);
                Q.clear();
                for(int i = 0; i < n; ++i) {
                        if(check(use[i], time)) {
                                Q.push_back(i + 1);
                        }
                }
                printf("Case #%d: %d\n", ++cas, Q[m - cut - 1]);
        }
        return 0;
}
