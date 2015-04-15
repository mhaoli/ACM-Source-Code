#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
using namespace std;
const int Max_N = 9 + (int)5e5;

pair<int, int> c[Max_N], b[Max_N];
int K[Max_N], res[Max_N];
set<int> st, Q;
map<int, int> has;
vector<pair<int, int> > que[Max_N], sing[Max_N];
vector<int> use[Max_N];
int main() {
        int n, m;
        scanf("%d", &n);
        for(int i = 0, u, v; i < n; ++i) {
                scanf("%d%d", &b[i].first, &b[i].second);
                st.insert(b[i].first); st.insert(b[i].second);
        }
        scanf("%d", &m);
        for(int i = 0; i < m; ++i) {
                scanf("%d%d%d", &c[i].first, &c[i].second, K + i);
                st.insert(c[i].first); st.insert(c[i].second);
        }

        int tot = 0;
        snuke(it, st) has[*it] = tot++;
        for(int i = 0; i < n; ++i) {
                que[has[b[i].first]].push_back(make_pair(has[b[i].second], i));
        }
        for(int i = 0; i < m; ++i) {
                sing[has[c[i].first]].push_back(make_pair(has[c[i].second], i));
        }

        bool ans = 1;
        for(int i = 0, t; ans && i < tot; ++i) {
                snuke(it, sing[i]) {
                        use[it->first].push_back(it->second);
                        Q.insert(it->first);
                }
                snuke(it, que[i]) {
                        auto pos = Q.lower_bound(it->first);
                        if(pos == Q.end()) ans = 0;
                        else {
                                t = use[*pos].back();
                                res[it->second] = t;
                                --K[t];
                                if(!K[t]) {
                                        use[*pos].pop_back();
                                        if((int)use[*pos].size() == 0) Q.erase(pos);
                                }
                        }
                }
        }
        if(!ans) puts("NO");
        else {
                puts("YES");
                for(int i = 0; i < n; ++i) printf("%d%c", res[i]+1, " \n"[i==n-1]);
        }
        return 0;
}
