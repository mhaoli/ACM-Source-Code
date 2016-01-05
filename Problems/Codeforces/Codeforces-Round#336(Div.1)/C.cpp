#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
using namespace std;
/****head****/
int _;
char s1[1<<21], s2[1<<21];
char has[1111];
int nxt[1<<21];
int main() {
        has['N'] = 'S';
        has['S'] = 'N';
        has['W'] = 'E';
        has['E'] = 'W';
        int n;
        cin >> n; --n;
        cin >> s1 >> s2;
        for(int i = 0; i < n; ++i) {
                s1[i] = has[s1[i]];
        }
        reverse(s1, s1 + n);
        for(int i = 0; i < n; ++i) {
                s1[i+n] = s2[i];
        }
        nxt[0] = nxt[1] = 0;
        n <<= 1;
        for(int i = 1, j = 0; i < n; ++i) {
                while(j && s1[i] != s1[j]) j = nxt[j];
                if(s1[i] == s1[j]) ++j;
                nxt[i+1] = j;
        }
        puts(nxt[n] > 0 ? "NO" : "YES");
        return 0;
}
