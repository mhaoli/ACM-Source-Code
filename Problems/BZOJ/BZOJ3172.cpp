#include<bits/stdc++.h>
const int N = 9 + (int)2e6;
const int S = 26;
struct nod{
    int cnt;
    nod *ch[S], *f;
}memo[N], *head[N], *bat=memo, *rt=bat++, *q[N], *pos[222];
void insert (char *s, int id){
    nod *x = rt;
    for (; s[0]; ++ s){
        if (!x->ch[s[0]-'a']){
            x->ch[s[0]-'a'] = bat++;
        }
        (x = x->ch[s[0]-'a'])->cnt++;
    }
    pos[id] = x;
}
char s[N];
void AC_build (){
    int qr = 0, ql = 0;
    q[qr++] = rt;
    for (nod *x, *last; ql != qr; ++ ql){
        x = q[ql];
        for (int i = 0; i < S; ++ i) if (x->ch[i]){
            last = x->f;
            while (last && !last->ch[i]) last = last->f;
            if (last) x->ch[i]->f = last->ch[i];
            else x->ch[i]->f = rt;
            q[qr++] = x->ch[i];
        }
    }
    for (int i = qr-1; i; -- i) q[i]->f->cnt += q[i]->cnt;
}
int main(){
    int n; scanf ("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf ("%s", s);
        insert (s, i);
    }
    AC_build ();
    for (int i = 0; i < n; ++ i)
        printf ("%d\n", pos[i]->cnt);
    return 0;
}
