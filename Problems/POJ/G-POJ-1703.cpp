/*
 * Author:  Plumrain
 * Created Time:  2013-11-26 09:19
 * File Name: G-POJ-1703.cpp
 */
#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 100005;

struct node{
    int f, r;
};

char s[10];
int n, m;
node a[maxn];

void init()
{
    for (int i = 0; i < n; ++ i){
        a[i].f = i;
        a[i].r = 0;
    }
}

int find(int x)
{
    if (x == a[x].f){
        a[x].r = 0;
        return x;
    }

    int y = a[x].f;
    a[x].f = find(a[x].f);
    a[x].r = (a[y].r + a[x].r) % 2;
    return a[x].f;
}

void merge(int x, int y)
{
    int t1 = find(x), t2 = find(y);
    a[t1].f = t2;
    a[t1].r = (a[y].r + a[x].r + 1) % 2;
}

int main()
{
    int T;
    scanf ("%d", &T);
    while (T --){
        scanf ("%d%d", &n, &m);
        init();

        int x, y;
        while (m --){
            scanf ("%s%d%d", s, &x, &y);
            int t1 = find(x), t2 = find(y);
            if (s[0] == 'D')
                merge(x, y);
            else{
                if (t1 != t2)
                    printf ("Not sure yet.\n");
                else{
                    if (a[x].r == a[y].r)
                       printf ("In the same gang.\n"); 
                    else
                        printf ("In different gangs.\n");
                }
            }
        }
    }
    return 0;
}
