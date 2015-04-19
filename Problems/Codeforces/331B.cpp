#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
const int N = 9 + (int)3e5;
int n;
int c[N], a[N], b[N];
void modify (int p, int x){
        for (; p < n; p += lowbit(p)) c[p] += x;
}
int query (int p){
        int ret = 0;
        for (; p > 0; p -= lowbit(p)) ret += c[p];
        return ret;
}
void setIt (int p, int x){
        if (p > 1 && (a[p] > a[p-1]) != (x > a[p-1]))
                modify (p-1, x > a[p-1] ? -1 : 1);
        if (p < n && (a[p] > a[p+1]) != (x > a[p+1]))
                modify (p, x > a[p+1] ? 1 : -1);
}
int main(){
        scanf ("%d", &n);
        for (int i = 1; i <= n; ++i){
                scanf ("%d", b + i);
                a[b[i]] = i;
        }
        for (int i = 2; i <= n; ++i)
                if (a[i] < a[i-1]) modify (i-1, 1);
        int q; scanf ("%d", &q);
        for (int op, x, y; q--;){
                scanf ("%d%d%d", &op, &x, &y);
                if (op == 1){
                        printf ("%d\n", query (--y) - query (--x) + 1);
                } else{
                        setIt (b[y], x);
                        setIt (b[x], y);
                        a[b[y]] = x;
                        a[b[x]] = y;
                        std::swap (b[x], b[y]);
                }
        }
        return 0;
}
