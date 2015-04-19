#include<cstdio>
#include<algorithm>
#include<cmath>
#include<functional>
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
using namespace std;
const int inf = ~0u>>1;
const int N = 9 + (int)2e5;
int ad[N<<2], mx[N<<2], a[N], L, n, s[N];
void Up (int r){
        mx[r] = std::max (mx[r<<1], mx[r<<1|1]);
}
void Down (int r){
        if (ad[r]){
                ad[r<<1] += ad[r];
                ad[r<<1|1] += ad[r];
                mx[r<<1] += ad[r];
                mx[r<<1|1] += ad[r];
                ad[r] = 0;
        }
}
void build (int l, int r, int rt){
        if (l != r){
                int m = l + r >> 1;
                ad[rt] = 0;
                build (lson); build (rson);
                Up (rt);
        } else mx[rt] = s[l], ad[rt] = 0;
}
void add (int ql, int qr, int v, int l, int r, int rt){
        if (ql <= l && r <= qr){
                ad[rt] += v; mx[rt] += v; return;
        }
        int m = l + r >> 1;
        Down (rt);
        if (ql <= m) add (ql, qr, v, lson);
        if (qr > m) add (ql, qr, v, rson);
        Up (rt);
}
int query (int ql, int qr, int l, int r, int rt){
        if (ql <= l && r <= qr) return mx[rt];
        int m = l + r >> 1, ret = -inf;
        Down (rt);
        if (ql <= m) ret = query (ql, qr, lson);
        if (qr > m) ret = std::max (ret, query (ql, qr, rson));
        Up (rt);
        return ret;
}
void setIt (int p, int x){
        if (x != a[p]) add (std::max (L, p), std::min (n, p + L - 1), x - a[p], 1, n, 1);
        a[p] = x;
}
int main(){
        int _; scanf ("%d", &_);
        for (int m; _--; ){
                scanf ("%d%d%d", &n, &m, &L);
                for (int i = 1; i <= n; ++i){
                        scanf ("%d", a + i);
                }
                s[L] = 0;
                for (int i = 1; i <= L; ++i) s[L] += a[i];
                for (int i = L+1; i <= n; ++ i) s[i] = s[i-1] + a[i] - a[i-L];
                build (1, n, 1);
                for (int op, x, y, t1, t2; m--; ){
                        scanf ("%d%d%d", &op, &x, &y);
                        if (op == 0){
                                setIt (x, y);
                        } else if (op == 1){
                                t1 = a[x]; t2 = a[y];
                                setIt (x, t2);
                                setIt (y, t1);
                        } else printf ("%d\n", query (x + L - 1, y, 1, n, 1));
                }
        }
        return 0;
}
