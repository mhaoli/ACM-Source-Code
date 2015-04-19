#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const long long mod = 1000000007;
int temp[] = {2, 3, 4, 6, 8, 9};
int dp[155][155][155];
inline int calc(int t, int fg) {
        if(fg == 2) {
                if(t == 2 || t == 6) return 1;
                if(t == 4) return 2;
                if(t == 8) return 3;
        } else {
                if(t == 3 || t == 6) return 1;
                else if(t == 9) return 2;
                else return 0;
        }
        return 0;
}
void add(int &a, int b) {
        a += b; if(a >= mod) a -= mod;
}
char str[2222];
int cnt[222], fac[222], CC[222][222];
int gao(int tmp, int k) {
        int ret = 0;
        while(tmp % k == 0) {
                ++ret; tmp /= k;
        }
        return ret;
}
long long Mypow(long long p, int n) {
        long long ret = 1;
        while(n) {
                if(n & 1) ret = ret * p % mod;
                p = p * p % mod;
                n >>= 1;
        }
        return ret;
}
long long Cinit(int n, int m) {
        long long ret = fac[n];
        ret = ret * Mypow(fac[m], mod - 2) % mod;
        ret = ret * Mypow(fac[n-m], mod - 2) % mod;
        return ret;
}
long long C(int n, int m) {
        return CC[n][m];
}
void init() {
        fac[0] = 1;
        for(int i = 1; i <= 200; ++i) fac[i] = (long long)fac[i-1] * i % mod;
        for(int i = 0, j; i <= 200; ++i) for(j = 0; j <= i; ++j) CC[i][j] = Cinit(i,j);
}
int main() {
        init();
        dp[0][0][0] = 1;
        for(int i = 1, j, k, t; i <= 150; ++i) {
                for(j = 0; j <= 150; ++j){
                        for(k = 0; k <= 150; ++k) if(dp[i-1][j][k]){
                                for(t = 0; t < 6; ++t) {
                                        add(dp[i][j+calc(temp[t],2)][k+calc(temp[t],3)], dp[i-1][j][k]);
                                }
                        }
                }
        }
        int n;
        while(scanf("%d", &n) != EOF) {
                scanf("%s", str);
                memset(cnt, 0, sizeof cnt);
                for(int i = 0; i < n; ++i) {
                        if(str[i] == '5') ++cnt[5];
                        else if(str[i] == '7') ++cnt[7];
                        else {
                                cnt[2] += gao(str[i] - '0', 2);
                                cnt[3] += gao(str[i] - '0', 3);
                        }
                }

                int ans = 0;
                //for(int i = 0, j, k; i <= 3*n; ++i) {
                        //for(j = 0; j <= cnt[2]; ++j)
                                //for(k = 0; k <= cnt[3]; ++k) dp[i][j][k] = 0;
                //}
                //dp[0][0][0] = 1;
                int len, a = cnt[5], b = cnt[7];
                for(int i = 1, j, k, t; i <= 3*n; ++i) {
                        //for(j = 0; j <= cnt[2]; ++j){
                                //for(k = 0; k <= cnt[3]; ++k) if(dp[i-1][j][k]){
                                        //for(t = 0; t < 6; ++t) {
                                                //add(dp[i][j+calc(temp[t],2)][k+calc(temp[t],3)], dp[i-1][j][k]);
                                        //}
                                //}
                        //}
                        len  = i;
                        //if(dp[i][cnt[2]][cnt[3]] > 0) puts("b");
                        add(ans, (long long)dp[i][cnt[2]][cnt[3]] * C(len + a + b, a) % mod * C(len + b, b) % mod);
                        //add(ans, );
                }
                printf("%d\n", ans);
        }
        return 0;
}
