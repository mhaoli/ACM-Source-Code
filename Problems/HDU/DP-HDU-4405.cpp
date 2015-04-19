/*
 * Author:  Plumrain
 * Created Time:  2013-10-30 11:17
 * File Name: DP-HDU-4405.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<utility>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
const int N = 100000;

int n, m;
double e[N+5];
map<int, int> mp;

void init()
{
    mp.clear();
    int t1, t2;
    for (int i = 0; i < m; ++ i){
        scanf ("%d%d", &t1, &t2);
        mp[t1] = t2;
    }

    for (int i = 0; i < n; ++ i) if (mp.count(i)){
        int t = mp[i];
        while (mp.count(t))
            t = mp[t];
        mp[i] = t;
    }
}

double DP()
{
    double p = (double)1 / 6;
    CLR (e);
    for (int i = n-1; i >= 0; -- i){
        e[i] = 1;
        if (mp.count(i)) continue;
        for (int j = 1; j <= 6; ++ j){
            if (mp.count(i+j))
                e[i] += e[mp[i+j]] * p;
            else
                e[i] += e[i+j] * p;
        }
    }

    int ret = 0;
    while (mp.count(ret))
        ret = mp[ret];
    return e[ret];
}

int main()
{
    while (scanf ("%d%d", &n, &m) != EOF && n){
        init();
        printf ("%.4f\n", DP());
    }
    return 0;
}
