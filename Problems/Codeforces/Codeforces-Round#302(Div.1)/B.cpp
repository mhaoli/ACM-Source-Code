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
const int inf = ~0u>>2;
int _, n;
std::vector<int> E[3333];
void Dijskra(int s, int *dis) {
        std::priority_queue<std::pair<int, int> > Q;
        Q.push(std::make_pair(0, s));
        dis[s] = 0;
        while(!Q.empty()) {
                int x = Q.top().second, d = -(Q.top().first);
                Q.pop();
                for(auto i : E[x]) if(dis[i] > d + 1){
                        dis[i] = d + 1;
                        Q.push(std::make_pair(-dis[i], i));
                }
        }
}
int dis[3005][3005];
int main() {
        int m;
        scanf("%d%d", &n, &m);
        for(int i = 0, s, e; i < m; ++i) {
                scanf("%d%d", &s, &e);
                --s; --e;
                E[s].push_back(e);
                E[e].push_back(s);
        }
        int S0, T0, S1, T1, L0, L1;
        std::cin >> S0 >> T0 >> L0 >> S1 >> T1 >> L1;
        --S0; --S1; --T0; --T1;
        memset(dis, 127, sizeof dis);
        for(int i = 0; i < n; ++i) {
                Dijskra(i, dis[i]);
        }

        //for(int i = 0; i < n; ++i) {
                //for(int j = 0; j < n; ++j) {
                        //printf("%d ", dis[i][j]);
                //}
                //puts("");
        //}
//
        int ans = inf;
        if(dis[S0][T0] <= L0 && dis[S1][T1] <= L1) {
                chmin(ans, dis[S0][T0] + dis[S1][T1]);
        }
        for(int i = 0, j; i < n; ++i) {
                for(j = 0; j < n; ++j) {
                        int t0 = dis[i][j] + dis[S0][i] + dis[T0][j];
                        int t1 = dis[i][j] + dis[S1][i] + dis[T1][j];
                        if(t0 <= L0 && t1 <= L1) {
                                chmin(ans, t0 + t1 - dis[i][j]);
                        }

                        std::swap(S0, T0);
                        
                        t0 = dis[i][j] + dis[S0][i] + dis[T0][j];
                        t1 = dis[i][j] + dis[S1][i] + dis[T1][j];
                        if(t0 <= L0 && t1 <= L1) {
                                chmin(ans, t0 + t1 - dis[i][j]);
                        }
                }
        }
        if(ans == inf) return puts("-1");
        printf("%d\n", m - ans);
        return 0;
}
