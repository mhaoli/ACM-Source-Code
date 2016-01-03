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
char s[1<<20];
map<int, pair<int, int> > has;
int main() {
        has['('] = make_pair(1, 0);
        has['{'] = make_pair(2, 0);
        has['['] = make_pair(3, 0);
        has['<'] = make_pair(4, 0);
        has[')'] = make_pair(1, 1);
        has['}'] = make_pair(2, 1);
        has[']'] = make_pair(3, 1);
        has['>'] = make_pair(4, 1);
        
        cin >> s;
        int n = strlen(s), ans = 0;
        stack<int> S;
        for(int i = 0; i < n; ++i) {
                auto t = has[s[i]];
                if(t.second == 0) S.push(t.first);
                else {
                        if(S.empty()) return puts("Impossible"), 0;
                        else {
                                if(S.top() != t.first) ++ans;
                                S.pop();
                        }
                }
        }
        if(S.empty()) cout << ans;
        else puts("Impossible");
        return 0;
}
