#include<bits/stdc++.h>
#define snuke(it,T) for(__typeof(T.begin()) it = T.begin(); it != T.end(); ++it)
const int N = 555;
std::vector<int> E[N], son[N];
bool ans;
int pos[N], dfs_clock, idx[N], mx[N], mi[N];
void dfs (int u, int pre){
        snuke (it, E[u]) if (*it != pre) dfs (*it, u), son[u].push_back (*it);
        if (E[u].size() == 1) idx[u] = dfs_clock++;
}
bool cmp (int a, int b){
        return mi[a] < mi[b];
}
void check (int u){
        snuke (it, son[u]) check (*it);

        if (!son[u].size()){
                mi[u] = mx[u] = pos[u];
        } else{
                std::sort (son[u].begin(), son[u].end(), cmp);
                snuke (it, son[u]) if (it != son[u].begin()){
                        if (mx[*(it-1)] + 1 != mi[*it]) ans = 1;
                }
                mx[u] = mx[son[u].back()];
                mi[u] = mi[*son[u].begin()];
        }
}
bool fg;
void output (int u){
        snuke (it, son[u]){
                if (fg) putchar (' ');
                fg = 1;
                printf ("%d", u + 1);
                output (*it);
        }
        printf (" %d", u + 1);
}
int main(){
        int n; scanf ("%d", &n);
        for (int u, v, i = 0; i < n-1; ++i){
                scanf ("%d%d", &u, &v);
                E[--u].push_back (--v);
                E[v].push_back (u);
        }
        dfs (0, -1);
        for (int top=0, i; scanf ("%d", &i) != EOF; pos[--i] = top++);
        check (0);
        if (ans) puts ("-1");
        else output (0), puts ("");
        return 0;
}
