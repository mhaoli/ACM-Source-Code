/*
 * Author:  Plumrain
 * Created Time:  2014/10/25 0:58:29
 * File Name: POJ2104.cpp
 */
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
#define foreach(it,T) for(__typeof(T.begin()) it = T.begin(); it != T.end(); ++ it)
const int N = 9 + (int)1e5;
struct nod;
struct nod{
    nod *ls, *rs;
    int v;
}memo[N*20], *bat=memo, *rt[N], Tnull, *null=&Tnull;

void init(){
    null->ls = null->rs = null;
    null->v = 0;
}
void insert (int v, int l, int r, nod *&x){
    (*bat) = (*x); x = bat++; x->v ++;
    if (l == r) return;
    int m = l + r >> 1;
    if (v <= m) insert (v, l, m, x->ls);
    else insert (v, m+1, r, x->rs);
}
int query (int k, nod *ql, nod *qr, int l, int r){
    if (l < r){
        int t = qr->ls->v - ql->ls->v, m = l + r >> 1;
        if (k <= t) return query (k, ql->ls, qr->ls, l, m);
        else return query (k-t, ql->rs, qr->rs, m+1, r);
    } else return l;
}
std::pair<int, int> a[N];
int rank[N];
int main(){
    init ();
    int n, m; scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i)
        scanf ("%d", &a[i].first), a[i].second = i;
    sort (a + 1, a + n + 1);

    for (int i = 1; i <= n; ++ i) rank[a[i].second] = i;

    rt[0] = null;
    for (int i = 1; i <= n; ++ i)
        insert (rank[i], 1, n, rt[i] = rt[i-1]);

    for (int l, r, k; m; -- m){
        scanf ("%d%d%d", &l, &r, &k);
        printf ("%d\n", a[query (k, rt[l-1], rt[r], 1, n)].first);
    }
    return 0;
}
