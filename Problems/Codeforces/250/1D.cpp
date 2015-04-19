#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
const int Max_N = 9 + (int)1e5;
int mx[Max_N<<2];
long long sum[Max_N<<2];
void upd(int rt) {
        mx[rt] = std::max(mx[rt<<1], mx[rt<<1|1]);
        sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void build(int l, int r, int rt) {
        if(l != r) {
                int m = l + r >> 1;
                build(lson); build(rson); upd(rt);
        } else scanf("%d", mx + rt), sum[rt] = mx[rt];
}
long long query(int ql, int qr, int l, int r, int rt) {
        if(ql <= l && r <= qr) return sum[rt];
        long long ret = 0;
        int m = l + r >> 1;
        if(ql <= m) ret = query(ql, qr, lson);
        if(qr > m) ret += query(ql, qr, rson);
        return ret;
}
void Mod(int ql, int qr, int mod, int l, int r, int rt) {
        if(mx[rt] < mod) return;
        if(l == r) {
                mx[rt] %= mod;
                sum[rt] = mx[rt];
                return;
        }
        int m = l + r >> 1;
        if(ql <= m) Mod(ql, qr, mod, lson);
        if(qr > m) Mod(ql, qr, mod, rson);
        upd(rt);
}
void modify(int p, int x, int l, int r, int rt) {
        if(l != r) {
                int m = l + r >> 1;
                if(p <= m) modify(p, x, lson);
                else modify(p, x, rson);
                upd(rt);
        } else mx[rt] = sum[rt] = x;
}
int main() {
        int n, nq;
        scanf("%d%d", &n, &nq);
        build(1, n, 1);
        for(int op, l, r, x; nq--;) {
                scanf("%d", &op);
                if(op == 1) {
                        scanf("%d%d", &l, &r);
                        printf("%I64d\n", query(l, r, 1, n, 1));
                } else if(op == 2) {
                        scanf("%d%d%d", &l, &r, &x);
                        Mod(l, r, x, 1, n, 1);
                } else {
                        scanf("%d%d", &l, &x);
                        modify(l, x, 1, n, 1);
                }
        }
        return 0;
}
