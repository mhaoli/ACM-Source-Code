#include<bits/stdc++.h>
using namespace std;
const int N = 9 + (int)1e7;
const int M = 9 + (int)1e5;

bool check[M];
int prm[M], idx[M], tot, mi[M];
void prime_init (int n){
    tot = 0; mi[1] = 1;
    for (int i = 2, j; i <= n; ++i){
        if (!check[i]) mi[i] = i, idx[prm[tot] = i] = tot, tot++;
        for (j = 0; j < tot && prm[j]*i <= n; ++j){
            check[prm[j]*i] = 1;
            mi[prm[j]*i] = prm[j];
            if (i % prm[j] == 0) break;
        }
    }
}

pair<int, int> temp;
struct nod{
    nod *ls, *rs;
    int l, r, sz;
    pair<int, int> a;
    void up (){
        sz = ls->sz + rs->sz;
        a = ls->a;
        if (a.first < rs->a.first) a = rs->a;
        else if (a.first == rs->a.first) a.second += rs->a.second;
    }
    void ins (int x){
        if (x == a.first) ++ a.second;
        else a.first = x, a.second = 1;
    }
}memo[N], *bat = memo, *rt[M], Tnull, *null=&Tnull;
nod *newnod (int l, int r){
    nod *x = bat++;
    x->l = l; x->r = r;
    x->sz = 1;
    x->a = temp;
    x->ls = x->rs = null;
    return x;
}
void insert (int p, int v, int l, int r, nod *&x){
    if (x == null) x = newnod (l, r);
    if (l != r){
        int m = l + r >> 1;
        if (p <= m) insert (p, v, l, m, x->ls);
        else insert (p, v, m+1, r, x->rs);
        x->up ();
    } else x->ins (v);
}
pair<int, int> query (int t1, int t2, nod *x){
    if (x == null) return temp;
    if (t1 <= x->l && x->r <= t2) return x->a;
    int m = x->l + x->r >> 1;
    pair<int, int> ret = temp, tmp;
    if (t1 <= m) ret = query (t1, t2, x->ls);
    if (t2 > m){
        tmp = query (t1, t2, x->rs);
        if (tmp.first == ret.first) ret.second += tmp.second;
        else if (tmp.first > ret.first) ret = tmp;
    }
    return ret;
}
int n;
int main(){
    temp.first = temp.second = -1;
    null->ls = null->rs = null;
    null->a = temp; null->sz = 0;
    prime_init (M-5);

    for (int i = 0; i < tot; ++ i) rt[i] = null;

    int m; scanf ("%d%d", &n, &m);
    for (int i = 0, t1, t2, last; i < n; ++ i){
        scanf ("%d", &t1); t2 = t1;
        while (t2 != 1){
            insert (i, t1, 0, n-1, rt[idx[mi[t2]]]);
            last = mi[t2];
            while (mi[t2] == last) t2 /= last;
        }
    }
    pair<int, int> ans;
    for (int t, t1, t2, last; m; -- m){
        scanf ("%d%d%d", &t, &t1, &t2); -- t1; -- t2;
        ans = temp;
        while (t != 1){
            ans = max (ans, query (t1, t2, rt[idx[mi[t]]]));
            last = mi[t];
            while (mi[t] == last) t /= last;
        }
        if (ans.first == -1) ans.second = -1;
        printf ("%d %d\n", ans.first, ans.second);
    }
    return 0;
}
