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
using namespace std;
int cnt[2];
char s[11111];
bool check(int t1, int t2, int n) {
        int sum = t1 * n + (cnt[0] - t1) - t2 * n - (cnt[1] - t2);
        if(sum >= 0 && sum < n) {
                puts("Possible");
                printf("%d", n - sum);
                for(int i = 0; s[i] != '='; ++i) {
                        if(s[i] == '+') {
                                printf(" + %d", t1 ? --t1,n : 1);
                        } else if(s[i] == '-') {
                                printf(" - %d", t2 ? --t2,n : 1);
                        }
                }
                printf(" = %d\n", n);
                return 1;
        }
        return 0;
}
int main() {
        gets(s);
        int L = strlen(s), n;
        cnt[0] = 0; cnt[1] = 0;
        for(int i = 0; i < L; ++i) {
                if(s[i] == '+') ++cnt[0];
                else if(s[i] == '-') ++cnt[1];
                if(s[i] == '=') {
                        i += 2;
                        n = 0;
                        while(i < L) {
                                n = (s[i] - '0') + n * 10;
                                ++i;
                        }
                }
        }
        for(int i = 0; i <= cnt[0]; ++i) {
                for(int j = 0; j <= cnt[1]; ++j) {
                        if(check(i, j, n)) {
                                return 0;
                        }
                }
        }
        puts("Impossible");
        return 0;
}
