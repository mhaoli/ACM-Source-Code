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
int manacher (int *str, int *len, int n){  //len[i] means the max palindrome length centered i/2
        for (int i = 0; i < 2*n; ++ i) len[i] = 0;
        int mx = 0;
        for (int i = 0, j = 0, k; i < 2*n; i += k, j = std::max (j-k, 0)){
                while (i - j >= 0 && i + j + 1 < 2*n && str[(i-j) / 2] == str[(i+j+1) / 2]) ++ j;
                len[i] = j;
                mx = std::max (mx, j);
                for (k = 1; i - k >= 0 && j - k >= 0 && len[i - k] != j - k; ++ k){
                        len[i+k] = std::min (len[i - k], j - k);
                }
        }
        return mx;
}
int _;
int an[505];
int dp[505][505];
int len[1111];
bool check(int s, int t) {
        int L = t - s + 1;
        return len[L-1+(s<<1)] >= L;
}
int main() {
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {
                cin >> an[i];
        }
        manacher(an, len, n);
        memset(dp, 127, sizeof dp);
        for(int l = 1, i, j, t; l <= n; ++l) {
                for(i = 0, j = l-1; j < n; ++i, ++j) {
                        if(l == 1) dp[i][i] = 1;
                        else {
                                if(an[i] == an[j]) chmin(dp[i][j], i+1 <= j-1 ? dp[i+1][j-1] : 1);
                                for(t = i; t < j; ++t) {
                                        chmin(dp[i][j], dp[i][t] + dp[t+1][j]);
                                }
                        }
                }
        }
        printf("%d\n", dp[0][n-1]);
        return 0;
}
