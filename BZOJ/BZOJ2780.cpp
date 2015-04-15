#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>
#include <complex>
using namespace std;
const int N = 9 + (3e5);
struct nod{
    map<int, nod*> c;
    nod *f;
    int fg, cnt, ans;
}memo[N], *bat = memo, *rt, *q[N], *pos[N];
map<int, nod*>::iterator it;
char ts[N], *ss;
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
        scanf ("%s", ts); ss = ts;
        for ( ; ss[0]; ++ ss)
            s[tot++] = ss[0];
        s[tot++] = 20000;
    }

    rt = bat++;
    for (int i = 1, l; i <= m; ++ i){
        scanf ("%s", ts); ss = ts;
        nod *x = rt;
        for (int t; ss[0]; ++ ss){
            t = ss[0];
            it = x->c.find (t);
            if (it != x->c.end ()) x = it->second;
            else x->c[t] = bat, x = bat++;
        }
        x->cnt++; pos[i] = x;
    }

    AC_build ();

    int p = 0;
    for (int i = 1; i <= n; ++ i){
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
    return 0;
}

