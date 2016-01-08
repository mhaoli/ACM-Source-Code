/*
other: http://codeforces.com/contest/603/submission/14586280
   */
#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
template<class T> void RD(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
using namespace std;
/****head****/
int _;
char s[1<<18];
int tmp[2][1<<18], idx[2];
int main() {
        int n;
        cin >> n >> s;

        tmp[0][0] = 0; tmp[1][0] = 1;
        for(int i = 1; i < n; ++i) {
                tmp[0][i] = tmp[0][i-1] ^ 1;
                tmp[1][i] = tmp[1][i-1] ^ 1;
        }

        for(int i = 0; i < n; ++i) {
                for(int j = 0; j < 2; ++j) {
                        if(tmp[j][idx[j]] == s[i] - '0') {
                                ++idx[j];
                        }
                }
        }
        //int mx = *max_element(dp, dp + 2);
        int mx = max(idx[0], idx[1]);
        cout << min(mx + 2, n);
        return 0;
}
