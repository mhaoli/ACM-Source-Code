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
bool in[1<<10], ok[1<<10];
double p[1<<10], dp[1<<10];
int an[1<<10][1<<10];
int main() {
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                        scanf("%d", &an[i][j]);
                }
        }
        dp[n-1] = 0; ok[n-1] = 1; 
        for(int i = 0; i < n; ++i) p[i] = 1;

        for(int i = 0; i < n; ++i) {
                int x = -1;
                for(int j = 0; j < n; ++j) if(ok[j] && !in[j]) {
                        if(x == -1) x = j;
                        else if((dp[j] + 1) / (1 - p[j]) < (dp[x] + 1) / (1 - p[x])) x = j;
                }
                if(x == -1) break;

                in[x] = 1;
                OUT(x);
                OUT(p[x]);
                OUT(dp[x]);
                if(x != n-1) dp[x] = (1 + dp[x]) / (1 - p[x]);
                for(int j = 0; j < n; ++j) if(!in[j] && an[j][x]){
                        ok[j] = true;
                        double t = an[j][x] / 100.0;
                        dp[j] += p[j] * t * dp[x];
                        p[j] *= (1 - t);
                        if(j == 0) OUT(dp[j]);
                }
        }
        printf("%.8f\n", dp[0]);
        return 0;
}
