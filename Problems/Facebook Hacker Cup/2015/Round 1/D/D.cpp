#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
void Read(int&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const int Max_N = 9 + (int)2e5;
const int Max_M = 21;
int fa[Max_N], q[Max_N], n;
int f[Max_N][Max_M], g[Max_N][Max_M];
std::vector<int> son[Max_N];
void bfs() {
        int qr = 0; q[qr++] = 0;
        for(int i = 0, x; i < qr; ++i) {
                x = q[i];
                snuke(it, son[x]) if(*it != fa[x]){
                        q[qr++] = *it;
                }
        }
        for(int i = qr-1, x, j, fir, sec; i >= 0; --i) {
                x = q[i];
                if(son[x].empty()) for(j = 1; j < Max_M; ++j) f[x][j] = j;
                else {
                        for(j = 1; j < Max_M; ++j) {
                                f[x][j] = j;
                                snuke(it, son[x]) f[x][j] += g[*it][j];
                        }
                }
                
                sec = 0; fir = 1;
                for(j = 2; j < Max_M; ++j) {
                        if(f[x][j] >= f[x][fir]) {
                                if(!sec || f[x][sec] > f[x][j]) sec = j;
                        } else {
                                sec = fir; fir = j;
                        }
                }

                for(j = 1; j < Max_M; ++j) g[x][j] = j == fir ? f[x][sec] : f[x][fir];
        }
}
int main() {
        freopen("corporate_gifting.txt","r",stdin);
        freopen("D.out","w",stdout);
        int _; Read(_);
        for(int cas = 0, ans; _--; ) {
                Read(n);
                for(int i = 0; i < n; ++i) son[i].clear();
                for(int i = 0; i < n; ++i) {
                        Read(fa[i]);
                        son[--fa[i]].push_back(i);
                }
                bfs();
                ans = ~0u>>1;
                for(int i = 1; i < Max_M; ++i) ans = std::min(ans, f[0][i]);
                printf("Case #%d: %d\n", ++cas, ans);
        }
        return 0;
}
