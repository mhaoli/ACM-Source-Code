#include<bits/stdc++.h>
#define foreach(it,T) for(__typeof(T.begin()) it = T.begin(); it != T.end(); ++it)
const int N = 9 + (int)5e4;
std::unordered_set<int> st[N];
int tag[N], ans[N], top, deg[N], state[N], limit, cnt, q[N];
void add (int u, int v){
        ++deg[u]; 
        ++deg[v];
        if (!tag[u] && state[u]) ++ans[v];
        if (!tag[v] && state[v]) ++ans[u];
        st[u].insert (v);
        st[v].insert (u);
        if (deg[u] >= limit && !tag[u]){
                tag[u] = 1;
                q[cnt++] = u;
                if (state[u]) foreach (it, st[u]) --ans[*it];
        }
        if (deg[v] >= limit && !tag[v]){
                tag[v] = 1;
                q[cnt++] = v;
                if (state[v]) foreach (it, st[v]) --ans[*it];
        }
}
void del (int u, int v){
        --deg[u];
        --deg[v];
        st[u].erase (v);
        st[v].erase (u);
        if (!tag[u] && state[u]) --ans[v];
        if (!tag[v] && state[v]) --ans[u];
}
int query (int x){
        int ret = ans[x];
        for (int i = 0; i < cnt; ++i){
                if (state[q[i]] && st[x].find(q[i]) != st[x].end()) ++ret;
        }
        return ret;
}
int main(){
        int n, m, q, _;
        limit = 1700;
        scanf ("%d%d%d%d", &n, &m, &q, &_);
        for (int t; _--; ){
                scanf ("%d", &t);
                state[--t] = 1;
        }
        for (int u, v; m--; ){
                scanf ("%d%d", &u, &v);
                add (--u, --v);
        }
        for (int k, u, v; q--; ){
                for (k = getchar(); k <= 32; k = getchar());
                if (k == 'O'){
                        scanf ("%d", &u);
                        state[--u] = 1;
                        if (!tag[u]) foreach (it, st[u]) ++ans[*it];
                } else if (k == 'F'){
                        scanf ("%d", &u);
                        state[--u] = 0;
                        if (!tag[u]) foreach (it, st[u]) --ans[*it];
                } else if (k == 'A'){
                        scanf ("%d%d", &u, &v);
                        add (--u, --v);
                } else if (k == 'D'){
                        scanf ("%d%d", &u, &v);
                        del (--u, --v);
                } else{
                        scanf ("%d", &u);
                        printf ("%d\n", query (--u));
                }
        }
        return 0;
}
