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
int pos[1<<18], ansCnt[1<<18];
long long v[1<<18];
set<pair<long long, int> > st;
map<pair<long long, int>, int> mos;
void modify(int id, long long L, long long t) {
        {
                v[id] += t;
                st.erase(make_pair(L, id));
                auto tmp = make_pair(L + t, 1 << 30);
                auto it = st.upper_bound(tmp);
                if(it != st.end() && pos[it->second] < pos[id]) return;
                auto it2 = it;
                if(it != st.begin()) {
                        --it;
                        while(pos[it->second] > pos[id]) {
                                if(it == st.begin()) {
                                        st.erase(it);
                                        break;
                                } else {
                                        it2 = it;
                                        --it2;
                                        st.erase(it);
                                        it = it2;
                                }
                        }
                }
                tmp.second = id;
                st.insert(tmp);
        }

        long long sum = 0;
        auto tmp = make_pair(L + t, 1 << 30);
        auto it = mos.upper_bound(tmp), it2 = it;
        if(it == mos.begin()) return;
        --it;
        while(it->first.first > L) {
                sum += 1ll * (it->first.second) * it->second;
                ansCnt[id] += it->second;

                if(it == mos.begin()) {
                        mos.erase(it);
                        break;
                } else {
                        it2 = it;
                        --it2;
                        mos.erase(it);
                        it = it2;
                }
        }
        if(sum) modify(id, L + t, sum);
}
int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0, t; i < n; ++i) {
                scanf("%d%d", pos + i, &t);
                v[i] = pos[i];
                st.insert(make_pair((long long)pos[i], i));
                modify(i, pos[i], t);
        }

        for(int i = 0, p1, t1; i < m; ++i) {
                scanf("%d%d", &p1, &t1);
                auto it = st.lower_bound(make_pair((long long)p1, -1));
                if(it == st.end() || pos[it->second] > p1) {
                        ++mos[make_pair((long long)p1, t1)];
                } else {
                        int id = it->second;
                        ++ansCnt[id];
                        modify(id, it->first, t1);
                }
        }
        for(int i = 0; i < n; ++i) {
                printf("%d %I64d\n", ansCnt[i], v[i] - pos[i]);
        }
        return 0;
}
