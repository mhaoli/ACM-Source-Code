#include<cstdio>
const int N = 9 + (int)1e5;
int *e[N], memo[N], K[N], val[N], *top;
struct set{
    int sz, s[2];
    set (){ sz = 0;}
    set (int x) : sz(1){ s[0] = x;}
    bool merge (const set &o){
        if (sz == 2) return 0;

        if (!o.sz) return 0;
        if (o.sz == 1){
            if (!sz) return sz=1, s[0]=o.s[0], 1;
            else if (s[0]==o.s[0]) return 0;
            else return sz=2, 1;
        } else return sz=2, 1;
    }
    const char* c_str() const{
        static char buf[N];
        if (sz == 2) return "unknown";
        if (!s[0]) return "sober";
        else{
            sprintf (buf, "%d", s[0]);
            return buf;
        }
    }
}st[N];
void dfs (int u){
    for (int i = 0, v; i < K[u]; ++ i){
        v = e[u][i];
        if (st[v].merge (val[u] ? set (val[u]) : st[u])) dfs (v);
    }
}
int main(){
    int n; scanf ("%d", &n);
    top = memo;
    for (int j, i = 0; i < n; ++ i){
        scanf ("%d%d", val + i, K + i);
        e[i] = top;
        top += K[i];
        for (j = 0; j < K[i]; ++ j)
            scanf ("%d", &e[i][j]), -- e[i][j];
    }
    st[0] = set(0);
    dfs (0);
    for (int i = 0; i < n; ++ i){
        printf ("%s ", st[i].c_str());
        printf ("%s\n", (val[i] ? set(val[i]) : st[i]).c_str());
    }
    return 0;
}
