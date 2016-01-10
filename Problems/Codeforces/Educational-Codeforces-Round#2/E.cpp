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
using namespace std;
/****head****/
int _;
int mx[1<<17];
set<pair<int, int> > st[1<<17], *idx[1<<17];
ll sum[1<<17];
vector<int> E[1<<17];
set<pair<int, int> >* merge(set<pair<int,int> >*a, set<pair<int,int> >*b, int id, int id2) {
        if(SZ(*a) > SZ(*b)) {
                swap(a, b);
                mx[id] = mx[id2];
                sum[id] = sum[id2];
        }
        for(auto x : *a) {
                auto it = (*b).lower_bound(mp(x.x, 0));
                int d;
                if(it->x == x.x) {
                        d = it->y + x.y;
                        (*b).erase(it);
                } else d = x.y;
                (*b).insert(mp(x.x, d));
                if(d == mx[id]) {
                        sum[id] += x.x;
                } else if(d > mx[id]) {
                        mx[id] = d;
                        sum[id] = x.x;
                }
        }
        return b;
}
void dfs(int x, int pre) {
        //OUT(x);
        //for(auto it : (*idx[x])) OUT(it.x), OUT(it.y);
        for(auto it : E[x]) if(it != pre) {
                dfs(it, x);
                idx[x] = merge(idx[it], idx[x], x, it);
        }
}
int main() {
        int n; rd(n);
        for(int i = 0, c; i < n; ++i) {
                rd(c);
                idx[i] = &st[i];
                st[i].insert(mp(c, 1));
                mx[i] = 1;
                sum[i] = c;
        }
        for(int i = 0, t1, t2; i < n-1; ++i) {
                rd(t1); rd(t2); --t1; --t2;
                E[t1].pb(t2); 
                E[t2].pb(t1); 
        }
        dfs(0, -1);
        for(int i = 0; i < n; ++i) {
                printf("%I64d ", sum[i]);
        }
        return 0;
}
