/*
 * Author:  Plumrain
 * Created Time:  2013-10-21 16:46
 * File Name: math-POJ-3128.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))

char s[100];
int a[100], num[100];
bool vis[100];

bool gao()
{
    CLR (vis); CLR (num);
    for (int i = 0; i < 26; ++ i) if (!vis[i]){
        int cnt = 0, pos = i;
        while (!vis[pos]){
            vis[pos] = 1;
            ++ cnt;
            pos = a[pos];
        }
        ++ num[cnt];
    }
    for (int i = 2; i <= 26; i += 2)
        if (num[i] & 1) return false;
    return true;
}

int main()
{
    int T;
    scanf ("%d", &T);
    while (T--){
        CLR (s); scanf ("%s", s);
        for (int i = 0; i < 26; ++ i)
            a[i] = s[i] - 'A';
        if (gao()) printf ("Yes\n");
        else printf ("No\n");
    }
    return 0;
}
