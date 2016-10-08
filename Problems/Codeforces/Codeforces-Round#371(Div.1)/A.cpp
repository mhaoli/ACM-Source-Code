//good solution: http://codeforces.com/contest/713/submission/20572370
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
int bi[300005];
int convert(char *dig) {
        int ret = 0;
        while(dig[0]) {
                ret = (ret << 1) | (dig[0] - '0');
                ++dig;
        }
        return ret;
}
void solve(char*dig, int flag) {
        char*idx = dig;
        while(dig[0]) {
                dig[0] = ((dig[0] - '0') % 2) + '0';
                ++dig;
        }
        bi[convert(idx)] += flag;
}
int main() {
        int nq;
        scanf("%d", &nq);

        char opt[11], dig[22];
        while(nq--) {
                scanf("%s%s", opt, dig);
                if(opt[0] == '?') {
                        printf("%d\n", bi[convert(dig)]);
                } else {
                        solve(dig, opt[0] == '+' ? 1 : -1);
                }
        }
        return 0;
}
