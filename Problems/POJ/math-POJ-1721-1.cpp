/*
 * Author:  Plumrain
 * Created Time:  2013-10-20 15:09
 * File Name: math-POJ-1721.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
const int N = 1000;
typedef vector<int> VI;

int a[N+5], b[2][N+5];

int gao(int n, int m)
{
    int k = 0, idx = 0;
    for (int i = 0; i < n; ++ i)
        b[0][i] = a[i]; 
    while (1){
        bool fla = false;
        for (int i = 0; i < n; ++ i)
            b[idx^1][i] = b[idx][b[idx][i]];
        idx ^= 1;
        ++ k;
        for (int i = 0; i < n; ++ i)
            if (b[idx][i] != a[i]) fla = 1;
        if (!fla) break;
    }

    m %= k;
    int tim = k - m;
    idx = 0;
    for (int i = 0; i < n; ++ i)
        b[0][i] = a[i];
    while (tim--){
        for (int i = 0; i < n; ++ i)
            b[idx^1][i] = b[idx][b[idx][i]];
        idx ^= 1;
    }
    return idx;
}
    
int main()
{
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF){
        for (int i = 0; i < n; ++ i){
            scanf ("%d", &a[i]);
            -- a[i];
        }
        int idx = gao(n, m);
        for (int i = 0; i < n; ++ i)
            printf ("%d\n", b[idx][i] + 1);
    }
    return 0;
}
