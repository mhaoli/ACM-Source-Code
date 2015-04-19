/*
 * Author:  Plumrain
 * Created Time:  2013-10-04 11:41
 * File Name: math-POJ-1026.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back

const int N = 200;

typedef vector<int> VI;

int n;
int a[N+5], tmp[N+5];
bool fla[N+5];

void gao(int m)
{
    CLR (fla); CLR (tmp);
    VI cur;
    for (int i = 0; i < n; ++ i) if (!fla[i]){
        cur.clear();
        int pos = i;
        while (!fla[pos]){
            fla[pos] = 1;
            cur.PB (pos);
            pos = a[pos];
        }
        int sz = cur.size();
        for (int i = 0; i < sz; ++ i)
            tmp[cur[(i+m)%sz]] = cur[i];
    }

    char s[N+5], c;
    int len = 0;
    CLR (s);
    scanf ("%c", &c);
    while (scanf ("%c", &c) != EOF && c != '\n')
        s[len++] = c;
    while (len < n) s[len++] = ' ';
    for (int i = 0; i < n; ++ i)
        printf ("%c", s[tmp[i]]);
    printf ("\n");
}

int main()
{
    while (scanf("%d", &n) != EOF && n){
        for (int i = 0; i < n; ++ i){
            scanf ("%d", &a[i]);
            -- a[i];
        }

        int x;
        while (scanf("%d", &x) != EOF && x)
            gao(x);
        printf ("\n");
    }
    return 0;
}
