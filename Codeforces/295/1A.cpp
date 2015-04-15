#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const int Max_N = 9 + (int)1e5;
const long long mod = 7 + (int)1e9;
char s[Max_N];
int idx[1111], cnt[1111];
int main() {
        int n;
        scanf("%d%s", &n, s);
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; i < n; ++i) ++cnt[s[i]-'A'];
        int mx = -1, num = 1;
        for(int i = 0; i < 26; ++i) {
                if(mx == cnt[i]) ++num;
                else if(mx < cnt[i]) {
                        mx = cnt[i]; num = 1;
                }
        }
        long long ans = 1;
        for(int i = 0; i < n; ++i) ans = ans * num % mod;
        printf("%d\n", (int)ans);
        return 0;
}
