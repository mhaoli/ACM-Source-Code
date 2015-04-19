#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
char str[111];
int n;
long long inf = 1ll<<62;
long long mymin(long long a, long long b) {
        return a > b ? b : a;
}
long long abs(long long a) {
        return a < 0 ? -a : a;
}
long long solve(int s, int t) {
        long long ret = 0;
        for(int i = s; i <= t; ++i) {
                ret = ret * 10 + str[i] - '0';
                if(ret < 0) return ret;
        }
        return ret;
}
long long calc(int mid) {
        long long t1 = solve(0, mid), t2 = solve(mid+1, n-1);
        if(t1 < 0 || t2 < 0) return inf;
        return abs(solve(0, mid) - solve(mid+1, n-1));
}
int main() {
        while(scanf("%s", str) != EOF) {
                n = strlen(str);
                long long ans = inf;
                //int mid = (n - 1) >> 1;
                //long long ans = mymin(calc(mid), calc(mid + 1));
                for(int i = 0; i < n-1; ++i) {
                        ans = mymin(ans, calc(i));
                }
                std::cout << ans << std::endl;
        }
        return 0;
}
