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
int ln[1<<21], rn[1<<21];
int an[1<<21], bn[1<<21], idx[3*(1<<21)];
int ansl[3*(1<<21)], ansr[3*(1<<21)];
set<int> st;
map<int, int> has;
pair<int, int> tmp;
int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i) {
                scanf("%d%d", an + i, bn + i);
                st.insert(an[i]);
                st.insert(bn[i]);
        }

        int t = 0;
        for(set<int>::iterator it = st.begin(); it != st.end(); ++it) has[*it] = ++t, idx[t] = *it;

        for(int i = 0; i < n; ++i) {
                ++ln[has[an[i]]];
                ++rn[has[bn[i]]];
        }

        int cnt = 0, ansCnt = 0, pre;
        for(int i = 1; i <= t; ++i) {
                if(cnt >= m) {
                        cnt += ln[i] - rn[i];
                        if(cnt < m) {
                                ansl[ansCnt] = pre;
                                ansr[ansCnt++] = idx[i];
                        }
                } else {
                        cnt += ln[i];
                        if(cnt < m) {
                                cnt -= rn[i];
                                continue;
                        }
                        cnt -= rn[i];
                        pre = idx[i];
                        if(cnt < m) {
                                ansl[ansCnt] = pre;
                                ansr[ansCnt++] = idx[i];
                        }
                }
        }
        printf("%d\n", ansCnt);
        for(int i = 0; i < ansCnt; ++i) {
                printf("%d %d\n", ansl[i], ansr[i]);
        }
        
        return 0;
}
