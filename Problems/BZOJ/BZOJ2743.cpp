#include<bits/stdc++.h>
const int N = 9 + (int)1e6;
struct nod{
    int x, id;
    nod *n;
    void add (int _x, int i, nod*t){ x = _x; id = i; n = t;}
}memo[N], *bat=memo, *head[N];

int c[N], n, last[N], ans[N], pre[N];
void adde (int x, int y, int id){
    bat->add (x, id, head[y]); head[y] = bat ++; 
}
void modify (int x, int d){
    for ( ; x; x -= ((x)&(-x))) c[x] += d;
}
void modify (int x, int y, int d){
    modify (y, d); modify (x-1, -d);
}
int sum (int x){
    int ret = 0;
    for ( ; x <= n; x += ((x)&(-x))) ret += c[x];
    return ret;
}
int main(){
    int m;
    scanf ("%d%*d%d", &n, &m);
    for (int i = 1, t; i <= n; ++ i){
        scanf ("%d", &t);
        last[i] = pre[t];
        pre[t] = i;
    }
    for (int i = 1, x, y; i <= m; ++ i){
        scanf ("%d%d", &x, &y);
        adde (x, y, i);
    }
    for (int i = 1; i <= n; ++ i){
        if (last[i]){
            modify (last[last[i]] + 1, last[i], 1);
        }
        for (nod*p = head[i]; p; p = p->n)
            ans[p->id] = sum (p->x);
    }
    for (int i = 1; i <= m; ++ i)
        printf ("%d\n", ans[i]);
    return 0;
}

