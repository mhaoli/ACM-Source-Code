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
struct RMQ_2D{
        static const int Max_N = 1000;
        static const int Max_M = 1000;
        int mx[Max_N+3][Max_M+3][11][11], lg[1005];
        void build(int n, int m, int a[1001][1001]){
                for(int i = 0, t = max(n, m); i <= t; ++i) {
                        lg[i] = (!i ? -1 : lg[i>>1] + 1);
                }
                for(int k = 0; (1<<k) <= n; ++k) {
                        for(int l = 0; (1<<l) <= m; ++l) {
                                for(int i = 0; i + (1<<k) - 1 < n; ++i) {
                                        for(int j = 0; j + (1<<l) - 1 < m; ++j) {
                                                if(!k && !l) mx[i][j][0][0] = a[i][j];
                                                else if(!k) {
                                                        mx[i][j][0][l] = max(mx[i][j][0][l-1], mx[i][j+(1<<(l-1))][0][l-1]);
                                                } else if(!l) {
                                                        mx[i][j][k][0] = max(mx[i][j][k-1][0], mx[i+(1<<(k-1))][j][k-1][0]);
                                                } else {
                                                        mx[i][j][k][l] = max(mx[i][j][k-1][l-1], mx[i+(1<<(k-1))][j][k-1][l-1]);
                                                        chmax(mx[i][j][k][l], mx[i][j+(1<<(l-1))][k-1][l-1]);
                                                        chmax(mx[i][j][k][l], mx[i+(1<<(k-1))][j+(1<<(l-1))][k-1][l-1]);
                                                }
                                        }
                                }
                        }
                }
        }
        int query(int x1, int y1, int x2, int y2) { //[x1, x2], [y1, y2]
                int k = lg[x2 - x1 + 1], l = lg[y2 - y1 + 1], ans = mx[x1][y1][k][l];
                chmax(ans, mx[x2-(1<<k)+1][y1][k][l]);
                chmax(ans, mx[x1][y2-(1<<l)+1][k][l]);
                chmax(ans, mx[x2-(1<<k)+1][y2-(1<<l)+1][k][l]);
                return ans;
        }
}rmq;
int A[1001][1001], dp[1001][1001];
int main() {
        int n, m, nq;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                        rd(A[i][j]);
                }
        }
        for(int i = n-1; i >= 0; --i) {
                for(int j = m-1; j >= 0; --j) {
                        dp[i][j] = A[i][j] ? 1 + min(dp[i+1][j+1], min(dp[i][j+1], dp[i+1][j])) : 0;
                }
        }
        rmq.build(n, m, dp);
        scanf("%d", &nq);
        for(int x1, x2, y1, y2, l, r, ans, mid; nq--; ) {
                rd(x1); rd(y1); rd(x2); rd(y2);
                --x1; --x2; --y1; --y2;

                ans = 0; l = 1; r = min(x2 - x1, y2 - y1) + 1;
                while(l <= r) {
                        mid = l + r >> 1;
                        if(rmq.query(x1, y1, x2-mid+1, y2-mid+1) >= mid) {
                                ans = mid;
                                l = mid + 1;
                        } else {
                                r = mid - 1;
                        }
                }
                printf("%d\n", ans);
        }
        return 0;
}
