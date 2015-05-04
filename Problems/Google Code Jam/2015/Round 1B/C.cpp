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
int _;
std::vector<long long> an;
std::vector<std::pair<long long, long long> > bn, cn;
void add(int p, int t) {
        an.push_back((360LL - p) * t);
        bn.push_back(std::make_pair((720LL - p) * t, 360LL * t));
}
void calc(int n) {
        std::priority_queue<std::pair<long long, long long> > Q;
        for(auto i : bn) {
                std::pair<long long, long long> tmp;
                Q.push(tmp = std::make_pair(-i.first, i.second));
                //std::cout << tmp.first << " " << tmp.second << std::endl;
        }

        //puts("");

        for(int i = 0; i < n; ++i) {
                auto t = Q.top(); Q.pop();
                long long p = -t.first, d = t.second;
                //std::cout << p << " " << d << std::endl;
                Q.push(std::make_pair(-(p + d), d));
                cn.push_back(std::make_pair(p, 0LL));
        }

        for(auto i : an) {
                cn.push_back(std::make_pair(i, 1LL));
        }

        sort(ALL(cn));
}
int main() {
        freopen("a.out","w",stdout);
        for(scanf("%d", &_); _--; ) {
                an.clear();
                bn.clear();
                cn.clear();

                int n;
                scanf("%d", &n);
                for(int i = 0; i < n; ++i) {
                        int p, m, t;
                        scanf("%d%d%d", &p, &m, &t);
                        for(int j = 0; j < m; ++j) {
                                add(p, t + j);
                        }
                }

                calc(SZ(an));

                int ans = SZ(an), cnt = ans;
                for(auto i : cn) {
                        if(i.second == 0) ++cnt;
                        else --cnt;
                        chmin(ans, cnt);
                }
                static int cas = 0;
                printf("Case #%d: %d\n", ++cas, ans);
        }
        return 0;
}
