#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
/****head****/
int _;
int mon[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
        int target, ans = 0;
        std::string s, t;
        std::cin >> target >> t >> s;
        if(s == "month") {
                for(int i = 0; i < 12; ++i) {
                        if(target <= mon[i]) ++ans;
                }
        } else {
                --target;
                int t1 = 4;
                int day = 1, month = 0;
                while(month < 12) {
                        if(target == t1) ++ ans;
                        t1 = (t1 + 1) % 7;
                        ++day; 
                        if(day > mon[month]) {
                                day = 1;
                                ++month;
                        }
                }
        }
        printf("%d\n", ans);
        return 0;
}
