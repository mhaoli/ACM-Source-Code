/*
 * Author:  Plumrain
 * Created Time:  2013-11-28 10:26
 * File Name: DS-POJ-1417.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define CLR1(x) memset(x, -1, sizeof(x))
#define PB push_back
typedef pair<int, int> pii;

struct oo{
    int a, b, pos;
    void clr(){
        a = 0; b = 0;
    }
};

struct node{
    int f, r;
};

node p[5005];
pii num[5005];
vector<int> ans;
oo cnt[5005];
map<int, int> mp;
int n, m, p1, p2, d[1205][1205];

int find(int x)
{
    if (x != p[x].f){
        int y = p[x].f;
        p[x].f = find(p[x].f);
        p[x].r = (p[x].r + p[y].r) % 2;
    }
    return p[x].f;
}

void merge(int a, int b, int x, int t1, int t2)
{
    p[t1].f = t2;
    p[t1].r = (p[a].r + p[b].r + x) % 2;
}

void init()
{
    for (int i = 0; i <= n; ++ i)
        cnt[i].clr();

    for (int i = 0; i <= n; ++ i){
        p[i].f = i;
        p[i].r = 0;
    }
    
    int a, b, x;
    char s[10];
    for (int i = 0; i < m; ++ i){
        scanf ("%d%d%s", &a, &b, s);
        if (s[0] == 'y') x = 0;
        else x = 1;

        int t1 = find(a), t2 = find(b);
        if (t1 != t2)
            merge(a, b, x, t1, t2);
    }
}

void gao0()
{
    if (p2 == 0 || p1 == 0){
        for (int i = 1; i <= p1; ++ i)
            printf ("%d\n", i);
        printf ("end\n");
        return;
    }
    printf ("no\n");
}

int main()
{
    while (scanf ("%d%d%d", &m, &p1, &p2) != EOF){    
        if (!m && !p1 && !p2) break;

        if (!m){
            gao0();
            continue;
        }

        n = p1 + p2;
        init();

        if (p1 == p2){
            printf ("no\n");
            continue;
        }

        CLR (num);
        for (int i = 1; i <= n; ++ i){
            int y = find(i);
            if (!p[i].r) ++ num[y].first;
            else ++ num[y].second;
        }

        int all = 1;
        for (int i = 1; i <= n; ++ i)
            if (num[i].first + num[i].second){
                cnt[all].a = num[i].first;
                cnt[all].b = num[i].second;
                cnt[all].pos = i;
                ++ all;
            }

        CLR1 (d);
        d[0][0] = 1;
        for (int i = 1; i < all; ++ i)
            for (int j = 0; j <= p1; ++ j){
                if (j >= cnt[i].a && d[i-1][j-cnt[i].a] >= 0){
                    if (d[i][j] == -1) d[i][j] = 0;
                    d[i][j] += d[i-1][j-cnt[i].a];
                }
                if (j >= cnt[i].b && d[i-1][j-cnt[i].b] >= 0){
                    if (d[i][j] == -1) d[i][j] = 0;
                    d[i][j] += d[i-1][j-cnt[i].b];
                }
            }

        if (d[all-1][p1] != 1) printf ("no\n");
        else{
            int j = p1;
            mp.clear();
            for (int i = all-1; i; -- i){
                if (j >= cnt[i].a && d[i-1][j-cnt[i].a] == 1){
                    j -= cnt[i].a;
                    mp[cnt[i].pos] = 0;
                }
                else if (j >= cnt[i].b && d[i-1][j-cnt[i].b] == 1){
                    j -= cnt[i].b;
                    mp[cnt[i].pos] = 1;
                }
            }

            ans.clear();
            for (int i = 1; i <= n; ++ i){
                int y = find(i);
                if (mp.count(y) && mp[y] == p[i].r)
                    ans.PB (i);
            }
            
            sort(ans.begin(), ans.end());
            int sz = ans.size();
            for (int i = 0; i < sz; ++ i)
                printf ("%d\n", ans[i]);
            printf ("end\n");
        }

    }
    return 0;
}


