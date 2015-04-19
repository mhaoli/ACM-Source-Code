#include<bits/stdc++.h>
#define foreach(it,T) for(__typeof(T.begin()) it = T.begin(); it != T.end(); ++it)
using namespace std;
const int N = 9 + (int)1e5;
const int inf = ~0u>>1;
int d[N], q[N], a[N], cnt[N];
set<pair<int, int> > st[N];
int main(){
    int n; scanf ("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf ("%d", a + i);
    for (int i = 0; i < n; ++i) q[i] = inf;
    int mx = 0;
    for (int p, i = 0; i < n; ++i){
        p = lower_bound (q, q + n, a[i]) - q;
        mx = std::max (mx, d[i] = p + 1);
        q[p] = a[i];
    }
    for (int i = n-1; i >= 0; --i){
        if (d[i] == mx){
            st[mx].insert (make_pair (a[i], i));
        } else if (st[d[i]+1].upper_bound (make_pair (a[i], inf)) != st[d[i]+1].end()){
            st[d[i]].insert (make_pair (a[i], i));
        }
    }
    for (int t, i = 0; i <= mx; ++i){
        t = st[i].size() > 1 ? 1 : 2;
        foreach (it, st[i]) cnt[it->second] = t;
    }
    for (int i = 0; i < n; ++ i) printf ("%d", cnt[i] + 1);
    puts ("");
    return 0;
}
