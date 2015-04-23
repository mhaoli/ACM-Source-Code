#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
struct Point {
        int x, y;
        Point(int x = 0, int y = 0) : x(x), y(y){ }
        void read() {
                scanf("%d%d", &x, &y);
        }
        void output() {
                printf("%d %d\n", x, y);
        }
        int dim() const {
                return y > 0 || (y == 0 && x >= 0);
        }
};
typedef Point Vector;
Point operator - (const Point &a, const Point &b) {
        return Point(a.x - b.x, a.y - b.y);
}
Point operator + (const Point &a, const Point &b) {
        return Point(a.x + b.x, a.y + b.y);
}
bool operator == (const Point &a, const Point &b) {
        return a.x == b.x && a.y == b.y;
}
bool operator != (const Point &a, const Point &b) {
        return !(a == b);
}
Point operator * (const Point &a, int p) {
        return Point(a.x * p, a.y * p);
}
long long operator ^ (const Point &a, const Point &b) {
        return (long long)a.x * b.y - (long long)a.y * b.x;
}
bool operator < (const Point &a, const Point &b) {
        if(a.dim() != b.dim()) {
                return a.dim() > b.dim();
        } else {
                return (a ^ b) > 0;
        }
}

const int Max_N = 9 + (int)1e5;
const int inf = ~0u>>1;
int _;
Point an[Max_N];
int main() {
        //freopen("a.out","w",stdout);
        for(scanf("%d", &_); _--; ) {
                int n, m, M;
                scanf("%d", &n);
                for(int i = 0; i < n; ++i) an[i].read();
                static int cas = 0;
                printf("Case #%d:\n", ++cas);
                for(int i = 0, j, ans, tmp, special, right; i < n; ++i) {
                        std::vector<std::pair<Point, int> > bn;
                        for(j = 0; j < n; ++j) {
                                if(i != j) {
                                        bn.push_back(std::make_pair(an[j] - an[i], -1));
                                        bn.push_back(std::make_pair(an[i] - an[j], 1));
                                }
                        }
                        std::sort(bn.begin(), bn.end());
                        tmp = 0;
                        ans = inf;
                        m = bn.size();
                        for(j = 0; j < m; ++j) bn.push_back(bn[j]);
                        M = bn.size();
                        for(j = right = 0; j < m; ++j) {
                                if(bn[j].second == 1) {
                                        if(right == j) ++right;
                                        continue;
                                }
                                while(right < M && (bn[j].first ^ bn[right].first) >= 0) {
                                        if(bn[right].second == -1) { 
                                                ++tmp;
                                        }
                                        ++right;
                                }
                                ans = std::min(ans, n - 1 - tmp);
                                if(bn[j].second != 1) --tmp;
                        }
                        if(ans == inf || ans < 0) ans = 0;
                        printf("%d\n", ans);
                }
        }
        return 0;
}
