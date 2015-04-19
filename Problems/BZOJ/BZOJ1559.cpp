/*
 * Author:  Plumrain
 * Created Time:  2014/10/7 22:07:52
 * File Name: BZOJ1559.cpp
 */
#include<bits/stdc++.h>
const int N = 1000;
const int S = 26;

struct nod{
    nod *ch[S+5], *f, *jump[S+5];
    int v;
    nod *go (int c);
}*bat, memo[N], *rt, *q[N];

void newnod (nod *&u){
    u = bat++; memset (u->ch, 0, sizeof u->ch); u->v = 0;
}
nod *nod::go (int c){
    if (!ch[c]) newnod (ch[c]);
    return ch[c];
}
void AC_init (){
    bat = memo; newnod (rt);
}
void AC_insert (char *s, int v){
    nod *x;
    for (x = rt; s[0]; ++ s) 
        x = x->go (s[0] - 'a');
    x->v |= v;
}
void AC_build (){
    int qr = 0;
    q[qr++] = rt;
    for (int ql = 0; ql != qr; ){
        nod *x = q[ql++];
        for (int c = 0; c < S; ++ c) if (x->ch[c]){
            nod *v = x->ch[c], *last = x->f;
            while (last && !last->ch[c]) last = last->f;
            if (last) v->f = last->ch[c];
            else v->f = rt;
            q[qr++] = v;
        }
    }
    for (int i = 0; i < S; ++ i) rt->jump[i] = rt->ch[i] ? rt->ch[i] : rt;
    for (int i = 1; i < qr; ++ i){
        nod *x = q[i];
        for (int j = 0; j < S; ++ j)
            x->jump[j] = x->ch[j] ? x->ch[j] : x->f->jump[j];
    }
    for (int i = 1; i < qr; ++ i){
        nod *x = q[i];
        if (x->f) x->v |= x->f->v;
    }
}

int n, m, tot;
char str[22], temp[33];
long long d[30][1<<10][111];
std::string res[100];

void dfs (int p, int s, nod*u){
    if (!p){
        if (!s && u == rt) res[tot++] = (std::string)temp;
        return;
    }

    for (int j = 0; j < (1<<m); ++ j) if ((j|u->v) == s)
        for (nod *k = memo; k < bat; ++ k) if (d[p-1][j][k-memo])
            for (int c = 0; c < S; ++ c) if (k->jump[c] == u){
                temp[p-1] = c + 'a';
                dfs (p - 1, j, k);
            }
}

int main(){
    scanf ("%d%d", &n, &m);
    AC_init ();
    for (int i = 0; i < m; ++ i){
        scanf ("%s", str);
        AC_insert (str, 1 << i);
    }
    AC_build ();
    memset (d, 0, sizeof d);
    d[0][0][0] = 1;
    nod *t;
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < (1<<m); ++ j)
            for (nod *k = memo; k < bat; ++ k) if (d[i][j][k-memo]){
                for (int c = 0; c < S; ++ c){
                    t = k->jump[c];
                    d[i+1][j|t->v][t-memo] += d[i][j][k-memo];
                }
            }

    long long ans = 0;
    int up = (1 << m) - 1;
    for (nod *i = memo; i < bat; ++ i) ans += d[n][up][i-memo];
    printf ("%lld\n", ans);
    if (ans > 42) return 0;
    tot = 0;
    for (nod *i = memo; i < bat; ++ i) if (d[n][up][i-memo]) dfs (n, up, i);
    sort (res, res + tot);
    for (int i = 0; i < tot; ++ i) std::cout << res[i] << "\n";
    return 0;
}
