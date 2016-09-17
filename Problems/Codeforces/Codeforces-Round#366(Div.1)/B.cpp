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
using namespace std;
template<class T> void rd(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
/****head****/
int n, s, e;
vector<int> state, pos, a, b, c, d;
void input(vector<int>&v) {
        v.resize(n + 1);
        for(int i = 1; i <= n; ++i) {
                scanf("%d", &v[i]);
        }
        v[0] = v[1];
}
void input() {
        cin >> n >> s >> e;
        input(pos);
        input(a);
        input(b);
        input(c);
        input(d);
}
ll dp[2][5002];
int main() {
        input();
        memset(dp, 127, sizeof dp);
        ll bound = dp[0][0], temp;
        dp[0][0] = 0;
        int cur = 0, nxt = 1;
        for(int i = 1, flag; i <= n; ++i) {
                flag = 0;
                if(i > s && i <= e) flag = 1;
                if(i > e && i <= s) flag = -1;
                memset(dp[nxt], 127, sizeof dp[nxt]);

                for(int j = 0; j <= i; ++j) if(dp[cur][j] < bound) {
                        if (i > 1 && j == 0 && j == flag) continue;
                        temp = 1ll * j * (pos[i] - pos[i-1]) + 1ll * (j - flag) * (pos[i] - pos[i-1]);
                        if(i != s && i != e) {
                                if(i > 1 && j - flag > 0 && j > 0) {
                                        chmin(dp[nxt][j-1], dp[cur][j] + c[i] + a[i] + temp);
                                }
                                if(i > 1 && i < n && j > 0) {
                                        chmin(dp[nxt][j], dp[cur][j] + a[i] + d[i] + temp);
                                }
                                if(i > 1 && i < n && j-flag > 0) {
                                        chmin(dp[nxt][j], dp[cur][j] + b[i] + c[i] + temp);
                                }
                                if(i < n) {
                                        chmin(dp[nxt][j+1], dp[cur][j] + b[i] + d[i] + temp);
                                }
                        } else if(i == s) {
                                if(i > 1 && j - flag > 0) {
                                        chmin(dp[nxt][j], dp[cur][j] + c[i] + temp);
                                }
                                if(i < n) {
                                        chmin(dp[nxt][j+1], dp[cur][j] + d[i] + temp);
                                }
                        } else {
                                if(i > 1 && j > 0) {
                                        chmin(dp[nxt][j-1], dp[cur][j] + a[i] + temp);
                                }
                                if(i < n) {
                                        chmin(dp[nxt][j], dp[cur][j] + b[i] + temp);
                                }
                        }
                }
                swap(cur, nxt);
        }
        cout << dp[cur][0] << endl;
        return 0;
}
