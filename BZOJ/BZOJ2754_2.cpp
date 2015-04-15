#include<bits/stdc++.h>
using namespace std;
const int N = 9 + (3e5);
struct nod{
    map<int, nod*> c;
    nod *f;
    int fg, cnt, ans;
}memo[N], *bat = memo, *rt, *q[N], *pos[N];
map<int, nod*>::iterator it;
int s[N], ans[N];
void AC_build (){
    int qr = 0, ql = 0;
    q[qr++] = rt;
    for (nod*x = q[ql++]; ql-1 != qr; x = q[ql++]){
        for (it = x->c.begin(); it != x->c.end (); ++ it){
            int c = it->first;
            nod *last = x->f;
            while (last && last->c.find(c) == last->c.end ()) last = last->f;
            if (last) it->second->f = last->c.find(c)->second;
            else it->second->f = rt;
            q[qr++] = it->second;
        }
    }
}
int main(){
    int n, m, tot = 0;
    scanf ("%d%d", &n, &m);
    for (int i = 1, l; i <= n; ++ i){
        scanf ("%d", &l);
        for (int j = 0; j < l; ++ j)
            scanf ("%d", &s[tot++]);
        s[tot++] = 20000;
        scanf ("%d", &l);
        for (int j = 0; j < l; ++ j)
            scanf ("%d", &s[tot++]);
        s[tot++] = 20000;
    }

    rt = bat++;
    for (int i = 1, l; i <= m; ++ i){
        scanf ("%d", &l);
        nod *x = rt;
        for (int j = 0, t; j < l; ++ j){
            scanf ("%d", &t);
            it = x->c.find (t);
            if (it != x->c.end ()) x = it->second;
            else x->c[t] = bat, x = bat++;
        }
        x->cnt++; pos[i] = x;
    }

    AC_build ();

    int p = 0;
    for (int i = 1; i <= n; ++ i)
        for (int xt = 0; xt < 2; ++ xt){
            nod *x = rt;
            while (s[p] != 20000){
                while (x && x->c.find (s[p]) == x->c.end ()) x = x->f;
                if (x) x = x->c.find (s[p])->second;
                else x = rt;

                for (nod*t = x; t && t->fg != i; t = t->f)
                    if (t->cnt){
                        t->fg = i;
                        ans[i] += t->cnt;
                        t->ans ++;
                    }
                ++ p;
            }
            ++ p;
        }

    for (int i = 1; i <= m; ++ i)
        printf ("%d\n", pos[i]->ans);
    for (int i = 1; i <= n; ++ i)
        printf ("%d%c", ans[i], " \n"[i==n]);
    return 0;
}
