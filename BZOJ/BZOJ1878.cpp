#include<bits/stdc++.h>
const int M = 200009;
const int N = 50009;
struct nod{
    int x, id;
    nod *n;
    void add (int _x, int i, nod*t){ x = _x; id = i; n = t;}
}memo[M], *bat=memo, *head[M*5];
int last[N], pre[M*5], ans[M], n, c[N];
void adde (int x, int y, int id){
    bat->add (x, id, head[y]); head[y] = bat ++; 
}
void modify (int x, int d){
    while (x <= n+1) c[x] += d, x += ((x)&(-x));
}
int sum (int x){
    int ret = 0;
    for ( ; x; x -= ((x)&(-x))) ret += c[x];
    return ret;
}
int main(){
    scanf ("%d", &n);
    for (int i = 1, t; i <= n; ++ i){
        scanf ("%d", &t);
        last[i] = pre[t] + 1;
        pre[t] = i;
    }
    int m; scanf ("%d", &m);
    for (int i = 1, x, y; i <= m; ++ i){
        scanf ("%d%d", &x, &y);
        adde (x, y, i);
    }
    for (int i = 1; i <= n; ++ i){
        modify (last[i], 1);
        for (nod*p = head[i]; p; p = p->n)
            ans[p->id] = sum (p->x);
        modify (i+1, -1);
    }
    for (int i = 1; i <= m; ++ i)
        printf ("%d\n", ans[i]);
    return 0;
}
