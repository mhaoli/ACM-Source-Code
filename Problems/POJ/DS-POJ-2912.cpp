/*
 * Author:  Plumrain
 * Created Time:  2013-11-28 19:23
 * File Name: DS-POJ-2912.cpp
 */
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define PB push_back

struct node{
    int f, r;
};

int n, m, line;
node p[505];
char xn[2005];
vector<int> ans;
int an[2005], bn[2005];

int find (int x)
{
    if (x != p[x].f){
        int y = p[x].f;
        p[x].f = find(y);
        p[x].r = (p[x].r + p[y].r) % 3;
    }
    return p[x].f;
}

void merge(int a, int b, char xx, int t1, int t2)
{
    int x;
    if (xx == '=') x = 0;
    else if (xx == '>') x = 1;
    else x = 2;

    p[t1].f = t2;
    p[t1].r = (3 - p[a].r + x + p[b].r) % 3; 
}

bool ok(int a, int b, char xx)
{
    int x;
    if (xx == '=') x = 0;
    else if (xx == '>') x = 1;
    else x = 2;
    
    return x == ((p[a].r + 3 - p[b].r) % 3);
}

bool gao(int x)
{
    for (int i = 0; i < n; ++ i){
        p[i].f = i;
        p[i].r = 0;
    }
    
    for (int i = 0; i < m; ++ i){
        if (an[i] == x || bn[i] == x) continue;
        
        int t1 = find(an[i]), t2 = find(bn[i]);
        if (t1 != t2)
            merge(an[i], bn[i], xn[i], t1, t2);
        if (t1 == t2)
            if (!ok(an[i], bn[i], xn[i])){
                line = max(line, i + 1);
                return 0;
            }
    }
    return 1;
}

int main()
{
    while (scanf ("%d%d", &n, &m) != EOF){
        if (!m){
            if (n == 1) printf ("Player 0 can be determined to be the judge after 0 lines\n");
            else printf ("Can not determine\n");
            continue;
        }

        for (int i = 0; i < m; ++ i)
            scanf ("%d%c%d", &an[i], &xn[i], &bn[i]);
        
        ans.clear();
        line = 0;
        for (int i = 0; i < n; ++ i)
            if (gao(i)) ans.PB (i);

        int sz = ans.size();
        if (sz > 1) printf ("Can not determine\n");
        else if (!sz) printf ("Impossible\n");
        else printf ("Player %d can be determined to be the judge after %d lines\n", ans[0], line);
    }
    return 0;
}
