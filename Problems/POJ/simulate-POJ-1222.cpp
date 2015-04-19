/*
 * Author:  Plumrain
 * Created Time:  2013-10-08 18:52
 * File Name: simulate-POJ-1222.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<utility>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<#a<<endl

int a[10][10], tmp[10][10], num[10][10];
vector<pair<int, int> > ans;

void init()
{
    ans.clear();
    for (int i = 0; i < 5; ++ i)
        for (int j = 0; j < 6; ++ j)
            scanf ("%d", &a[i][j]);

    for (int i = 0; i < 5; ++ i)
        for (int j = 0; j < 6; ++ j)
            tmp[i][j] = a[i][j];
}

void change(int x, int y)
{
    ans.PB (make_pair(x, y));
    a[x][y] = 1 - a[x][y];
    if (x) a[x-1][y] = 1 - a[x-1][y];
    if (x < 4) a[x+1][y] = 1 - a[x+1][y];
    if (y) a[x][y-1] = 1 - a[x][y-1];
    if (y < 5) a[x][y+1] = 1 - a[x][y+1];
}

void all_init()
{
    ans.clear();
    for (int i = 0; i < 5; ++ i)
        for (int j = 0; j < 6; ++ j)
            a[i][j] = tmp[i][j];
}

bool all_off(int x)
{
    for (int i = 0; i < 6; ++ i)
        if (a[x][i]) return false;
    return true;
}

void gao()
{
    for (int i = 0; i < (1<<6); ++ i){
        for (int j = 0; j < 6; ++ j)
            if (i & (1<<j)) change(0, j);

        for (int j = 1; j < 5; ++ j)
            for (int k = 0; k < 6; ++ k)
                if (a[j-1][k]) change(j, k);

        if (all_off(4)) return;
        all_init();
    }
}

int main()
{
    int T, test = 0;
    scanf ("%d", &T);
    while (T--){
        printf ("PUZZLE #%d\n", ++ test);

        init();
        gao();

        CLR (num);
        for (int i = 0; i < ans.size(); ++ i)
            num[ans[i].first][ans[i].second] = 1;

        for (int i = 0; i < 5; ++ i){
            for (int j = 0; j < 5; ++ j)
                printf ("%d ", num[i][j]);
            printf ("%d\n", num[i][5]);
        }
    }
    return 0;
}


