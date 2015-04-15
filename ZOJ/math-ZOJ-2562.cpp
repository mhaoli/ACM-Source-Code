/*
 * Author:  Plumrain
 * Created Time:  2013-10-25 00:18
 * File Name: math-ZOJ-2562.cpp
 */
#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

#define PB push_back
typedef long long int64;

vector<int64> cur;
int64 cnt, ans, N;
int64 prm[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int64 min(int64 a, int64 b)
{
    return a < b ? a : b;
}

void DFS(int64 n, int64 pos, int64 num)
{
    int64 tmp = 1;
    for (int64 i = 0; i < (int64)cur.size(); ++ i)
        tmp *= (cur[i] + 1);
    if (tmp > cnt){
        ans = n; 
        cnt = tmp;
    }
    else if (tmp == cnt) 
        ans = min(ans, n);

    if (pos >= 14) return; 

    int64 ttmp = prm[++pos] * n;
    int64 ntmp = 1;
    while (ttmp <= N && ntmp <= num){
        cur.PB(ntmp);
        DFS (ttmp, pos, ntmp);
        cur.pop_back();

        ttmp *= prm[pos];
        ++ ntmp;
    }
}

int main()
{
    while (scanf ("%lld", &N) != EOF){
        cur.clear();
        int64 tmp = 2, num = 1;
        cnt = ans = 1;
        while (tmp <= N){
            cur.PB(num);
            DFS (tmp, 0, num);
            cur.pop_back();
            tmp *= 2;
            ++ num;
        }

        printf ("%lld\n", ans);
    }
    return 0;
}
