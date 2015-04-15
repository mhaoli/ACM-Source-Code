/*
 * Author:  Plumrain
 * Created Time:  2013-11-28 20:27
 * File Name: DS-ZOJ-3261.cpp
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define PB push_back
const int maxn = 10005;
const int maxm = 20005;

struct node{
    int f, r;
};

struct query{
    int s, e;
    int q;
};

struct Pat{
    int s, e;
    bool x;
};

int n, m, q;
int cost[maxn];
Pat pat[maxm];
vector<int> ans;
query ask[maxn*5];
node nod[maxn];

bool cmp(Pat a, Pat b)
{
    return a.s < b.s || (a.s == b.s && a.e < b.e);
}

bool les(int x, int y)
{
    Pat tmp;
    tmp.s = ask[y].s; tmp.e = ask[y].e;
    return cmp(pat[x], tmp);
}

int bin_search(int x)
{
    int l = 0, r = m-1;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (les(mid, x)) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

void pat_del(int x)
{
    int pos = bin_search(x);
    pat[pos].x = 0;
}

void init()
{
    for (int i = 0; i < n; ++ i)
        scanf ("%d", &cost[i]);

    scanf ("%d", &m);
    for (int i = 0; i < m; ++ i){        
        scanf ("%d%d", &pat[i].s, &pat[i].e);
        if (pat[i].s > pat[i].e) swap(pat[i].s, pat[i].e);
        pat[i].x = 1;
    }

    sort(pat, pat+m, cmp);

    scanf ("%d", &q);
    char s[10];
    for (int i = 0; i < q; ++ i){
        scanf ("%s", s);
        if (s[0] == 'q'){
            ask[i].q = 0;
            scanf ("%d", &ask[i].s);
        }
        else{
            scanf ("%d%d", &ask[i].s, &ask[i].e);
            if (ask[i].s > ask[i].e) swap(ask[i].s, ask[i].e);
            pat_del(i);
            ask[i].q = 1;
        }
    }
}

int find(int x)
{
    if (x != nod[x].f){
        nod[x].f = find(nod[x].f);
        int tmp;
        if (cost[nod[x].r] > cost[nod[nod[x].f].r]) tmp = nod[x].r;
        else if (cost[nod[x].r] == cost[nod[nod[x].f].r]) tmp = min(nod[x].r, nod[nod[x].f].r);
        else tmp = nod[nod[x].f].r;
        nod[x].r = nod[nod[x].f].r = tmp;
    }
    return nod[x].f;
}

void merge(int s, int e, int t1, int t2)
{
    nod[t1].f = t2;
    int tmp;
    if (cost[nod[t1].r] > cost[nod[t2].r]) tmp = nod[t1].r;
    else if (cost[nod[t1].r] == cost[nod[t2].r]) tmp = min(nod[t1].r, nod[t2].r);
    else tmp = nod[t2].r;
    nod[t1].r = nod[t2].r = tmp;
}

void gao()
{
    for (int i = 0; i < n; ++ i)
        nod[i].r = nod[i].f = i;

    for (int i = 0; i < m; ++ i) if (pat[i].x){
        int s = pat[i].s, e = pat[i].e; 
        int t1 = find(s), t2 = find(e);
        if (t1 != t2)
            merge(s, e, t1, t2);
    }

    for (int i = q-1; i >= 0; -- i){
        if (ask[i].q == 0){
            int tmp = ask[i].s;
            int y = find(tmp);
            int tmp2 = nod[y].r;
            if (cost[tmp2] <= cost[tmp]) ans.PB (-1);
            else ans.PB (tmp2);
        }
        if (ask[i].q == 1){
            int s = ask[i].s, e = ask[i].e;
            int t1 = find(s), t2 = find(e);
            if (t1 != t2)
                merge(s, e, t1, t2);
        }
    }
}

int main()
{
    bool flag = 0;
    while (scanf ("%d", &n) != EOF){
        if (flag) printf ("\n");
        flag = 1;

        init();
        ans.clear();
        gao();

        int sz = ans.size();
        for (int i = sz-1; i >= 0; -- i)
            printf ("%d\n", ans[i]);
    }
    return 0;
}
