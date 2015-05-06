#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
/****head****/
#define POSIN(x,y) ((x) >= 0 && (x) < n && (y) >= 0 && (y) < m)
const int DX[] = {0, 0, 1, -1}, DY[] = {-1, 1, 0, 0};
int _;
int n, m, K, cnt;
int Mem[22222], Mem2[22222], Num[10];
int *col[22222], *tot[22222];
void dfs(int x, int y, int c) {
        col[x][y] = c;
        if(c == 0) ++cnt;
        for(int d = 0; d < 4; ++d) if(POSIN(x + DX[d], y + DY[d])) {
                if(~col[x + DX[d]][y + DY[d]]) continue;
                dfs(x + DX[d], y + DY[d], c ^ 1);
        }
}
int calc(int c, int K) {
        memset(Num, 0, sizeof Num);
        for(int i = 0, j, d, tnum; i < n; ++i) {
                for(j = 0; j < m; ++j) if(col[i][j] == c) {
                        tnum = 0;
                        for(d = 0; d < 4; ++d) if(POSIN(i + DX[d], j + DY[d])) {
                                ++tnum;
                        }
                        ++Num[tnum];
                }
        }

        int ret = 0;
        for(int i = 0; i < 5; ++i) {
                if(K > Num[i]) {
                        K -= Num[i];
                        ret += Num[i] * i;
                } else {
                        return ret + K * i;
                }
        }
}
int solve() {
        memset(Mem, -1, sizeof Mem);
        memset(Mem2, 0, sizeof Mem2);
        col[0] = Mem; tot[0] = Mem2;
        for(int i = 1; i < n; ++i) {
                col[i] = col[i-1] + m;
                tot[i] = tot[i-1] + m;
        }

        cnt = 0;
        dfs(0, 0, 0);

        int N = n * m;
        if(cnt >= K || N - cnt >= K) return 0;

        return std::min(calc(0, K - (N - cnt)), calc(1, K - cnt));
}
int main() {
        freopen("a.out","w",stdout);
        for(scanf("%d", &_); _--; ) {
                scanf("%d%d%d", &n, &m, &K);
                static int cas = 0;
                printf("Case #%d: %d\n", ++cas, solve());
        }
        return 0;
}
