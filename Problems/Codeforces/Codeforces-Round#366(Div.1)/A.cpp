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
set<int> app[300005];
set<int, greater<int> > st;
int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = -1, type, t; m--; ){
                scanf("%d%d", &type, &t);
                if(type == 1) {
                        st.insert(++i);
                        app[t].insert(i);
                } else if(type == 2) {
                        for(auto i : app[t]) {
                                auto idx = st.find(i);
                                if(idx != st.end()) st.erase(idx);
                        }
                        app[t].clear();
                } else {
                        auto idx = st.lower_bound(t-1);
                        auto idx2 = idx;
                        while(idx != st.end()) {
                                idx2 = idx;
                                ++idx;
                                st.erase(idx2);
                        }
                }
                printf("%d\n", SZ(st));
        }
        return 0;
}
