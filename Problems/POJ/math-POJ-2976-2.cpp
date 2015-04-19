/*
 * Author:  Plumrain
 * Created Time:  2013-10-13 17:29
 * File Name: math-POJ-2976-2.cpp
 * Dinkelbach算法
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

#define CLR(x) memset(x, 0.0, sizeof(x))
#define PB push_back

const double eps = 1e-4;
const int N = 1000;

int n, m;
int a[N+5], b[N+5];
vector<pair<double, int> > cur;

bool cmp(pair<double, int> x, pair<double, int> y)
{
    return x.first > y.first;
}

double gao()
{
    double p = 0.5, q = 0.0;
    while (1){
        cur.clear();
        for (int i = 0; i < n; ++ i){
            double c = a[i] - p * b[i];
            cur.PB (make_pair(c, i));
        }
        sort (cur.begin(), cur.end(), cmp);
        double tmp1 = 0.0, tmp2 = 0.0;
        for (int i = 0; i < n-m; ++ i){
            tmp1 += a[cur[i].second];
            tmp2 += b[cur[i].second];
        }
        q = tmp1 / tmp2;
        if (fabs(p-q) < eps) break;
        p = q;
    }
    return q;
}

int main()
{
    while (scanf ("%d%d", &n, &m) != EOF && n){
        for (int i = 0; i < n; ++ i)
            scanf ("%d", &a[i]);
        for (int i = 0; i < n; ++ i)
            scanf ("%d", &b[i]);

        printf ("%d\n", (int)(gao()*100.0+0.5));
    }
    return 0;
}
