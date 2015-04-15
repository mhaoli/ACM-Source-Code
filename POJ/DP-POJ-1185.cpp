/*
 * Author:  Plumrain
 * Created Time:  2013-11-19 09:12
 * File Name: DP-POJ-1185.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back

int n, m, sz;
bool a[200][20];
int d[105][70][70];
vector<int> sta;
vector<int> pat[70][70];

int xxx;

bool gao1(int opt)
{
    for (int i = 0; i < m; ++ i)
        if (opt & (1<<i)){
            if (i && (opt & (1<<(i-1)))) return 0;
            if (i > 2 && (opt & (1<<(i-2)))) return 0;
            if (i < m-1 && (opt & (1<<(i+1)))) return 0;
            if (i < m-2 && (opt & (1<<(i+2)))) return 0;
        }
    return 1;
}

bool gao2(int opt, int num)
{
    for (int i = 0; i < m; ++ i)
        if ((opt & (1<<i)) && !a[num][i])
            return 0;
    return 1;
}

bool gao3(int t1, int t2, int t3)
{
    int tmp[3];
    tmp[0] = t1; tmp[1] = t2; tmp[2] = t3;

    for (int i = 0; i < m; ++ i){
        int tim = 0;
        for (int j = 0; j < 3; ++ j)
            if (tmp[j] & (1<<i)) ++ tim;
        if (tim > 1) return 0;
    }
    return 1;
}

int get_num(int x)
{
    int ret = 0;
    for (int i = 0; i < m; ++ i)
        if (x & (1<<i)) ++ ret;
    return ret;
}

void init()
{
    char x;
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < m; ++ j){
            x = 'a';
            while (x != 'P' && x != 'H') scanf ("%c", &x);
            if (x == 'P') a[i][(m-1-j)] = 1;
            else a[i][(m-1-j)] = 0;
        }

    sta.clear();
    for (int i = 0; i < (1<<m); ++ i)
        if (gao1(i)) sta.PB(i);
    sz = sta.size();

    for (int i = 0; i < sz; ++ i)
        for (int j = 0; j < sz; ++ j)
            pat[i][j].clear();

    for (int i = 0; i < sz; ++ i)
        for (int j = 0; j < sz; ++ j)
            for (int k = 0; k < sz; ++ k)
                if(gao3(sta[i], sta[j], sta[k]))
                    pat[i][j].PB(k);
}

int DP()
{
    CLR (d);
    for (int i = 0; i < sz; ++ i)
        if (gao2(sta[i], 0)) d[0][i][0] = get_num(sta[i]);

    for (int i = 1; i < n; ++ i)
        for (int j = 0; j < sz; ++ j)
            for (int k = 0; k < sz; ++ k)
                if (gao2(sta[j], i) && gao2(sta[k], i-1)){
                    d[i][j][k] = 0;
                    for (int l = 0; l < (int)pat[j][k].size(); ++ l)
                        d[i][j][k] = max(d[i][j][k], d[i-1][k][pat[j][k][l]] + get_num(sta[j]));
                }

    int ret = 0;
    for (int i = 0; i < sz; ++ i) if (gao2(sta[i], n-1))
        for (int j = 0; j < sz; ++ j) if (gao2(sta[j], n-2))
            ret = max(ret, d[n-1][i][j]);
    return ret;
}

int main()
{
    while (scanf ("%d%d", &n, &m) != EOF){    
        init();
        printf ("%d\n", DP());
    }
    return 0;
}
