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
vector<pair<int, pair<int, int> > > vec;
map<pair<int, int>, int> has;
pair<int, int> ans[1<<18];
int n, m;
bool check() {
        vector<pair<int, int> > use;
        int idx = 0;
        int top = 1;
        for(auto it : vec) {
                if(it.second.first == 0) {
                        if(idx == SZ(use)) return false;
                        ans[it.second.second] = use[idx];
                        ++idx;
                } else {
                        ans[it.second.second] = make_pair(top, top - 1);
                        for(int j = 0; j < top-1 && SZ(use) <= m + 10; ++j) {
                                use.push_back(make_pair(j, top));
                        }
                        ++top;
                }
        }
        return true;
}
int main() {
        scanf("%d%d", &n, &m);
        for(int i = 0, t1, t2, t3; i < m; ++i) {
                scanf("%d%d", &t1, &t2);
                vec.push_back(make_pair(t1, make_pair(-t2, i)));
        }
        sort(ALL(vec));

        if(check()) {
                for(int i = 0; i < m; ++i) {
                        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
                }
        } else puts("-1");
        return 0;
}
