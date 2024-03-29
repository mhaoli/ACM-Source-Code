#include<bits/stdc++.h>
const int N = 9 + (int)5e5;
struct Seg{
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
    int num[2][N<<2], sum[2][N<<2];
    void Up (int rt){
        sum[0][rt] = sum[0][rt<<1] + sum[0][rt<<1|1];
        sum[1][rt] = sum[1][rt<<1] + sum[1][rt<<1|1];
    }
    void init (int v, int l, int r, int rt){
        if (l < r){
            int m = l + r >> 1;
            init (v, lson); init (v, rson);
            Up (rt);
        } else{
            num[0][rt] = sum[0][rt] = l ? 0 : v;
            num[1][rt] = sum[1][rt] = 0;
        }
    }
    void modify (int p, int v, int u, int l, int r, int rt){
        if (l < r){
            int m = l + r >> 1;
            if (p <= m) modify (p, v, u, lson);
            else modify (p, v, u, rson);
            Up (rt);
        } else num[v][rt] += u, sum[v][rt] += u;
    }
    int query (int ql, int qr, int u, int l, int r, int rt){
        if (ql <= l && r <= qr) return sum[u][rt];
        int m = l + r >> 1, ret = 0;
        if (ql <= m) ret = query (ql, qr, u, lson);
        if (qr > m) ret += query (ql, qr, u, rson);
        return ret;
    }
}gao[2];
char op[20];
int last[2][N], val[2][N], num[2][N];
int main(){
    int n, q; scanf ("%d%d", &n, &q);
    gao[0].init (n, 0, q, 1);
    gao[1].init (n, 0, q, 1);
    for (int ans, t1, t2, tlast, fg, i = 1; i <= q; ++ i){
        scanf ("%s%d", op, &t1);
        fg = (op[0] != 'R');
        if (op[3] == 'Q'){
            tlast = last[fg][t1];
            if (val[fg][t1]) ans = gao[fg^1].query (tlast+1, i, 0, 0, q, 1);
            else ans = n - gao[fg^1].query (tlast+1, i, 1, 0, q, 1);
            printf ("%d\n", ans);
        } else{
            scanf ("%d", &t2);
            gao[fg].modify (last[fg][t1], val[fg][t1], -1, 0, q, 1);
            last[fg][t1] = i;
            val[fg][t1] = t2;
            gao[fg].modify (i, t2, 1, 0, q, 1);
        }
    }
    return 0;
}
