#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define x first
#define y second
#define mp make_pair
#define pb push_back
template<class T> void rd(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
/****head****/
void fail(int *s, int n, int *f) {
        f[0] = f[1] = 0;
        int j = 0;
        for(int i = 2; i <= n; ++i) {
                while(j && s[i-1] != s[j]) j = f[j];
                if(s[i-1] == s[j]) ++j;
                f[i] = j;
        }
}
int match(int*s, int n, int *p, int m, int *f) {
        fail(p, m, f);
        int j = 0;
        for(int i = 0; i < n; ++i) {
                while(j && s[i] != p[j]) j = f[j];
                if(s[i] == p[j]) ++j;
                if(j == m) return i - m + 1;
        }
        return -2;
}
int an[1111111], bn[1111111], f[1111111];
int main() {
        int _;
        scanf("%d", &_);
        while(_--) {
                int n, m;
                scanf("%d%d", &n, &m);
                for(int i = 0; i < n; ++i) {
                        scanf("%d", an + i);
                }
                for(int i = 0; i < m; ++i) {
                        scanf("%d", bn + i);
                }
                printf("%d\n", match(an, n, bn, m, f) + 1);
        }
        return 0;
}
