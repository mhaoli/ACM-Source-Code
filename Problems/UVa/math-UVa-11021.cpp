/*
 * Author:  Plumrain
 * Created Time:  2013-09-05 20:43
 * File Name: math-UVa-11021.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))

const int N = 1000;

int n, k, m;
double p[N+10], f[N+10];

double gao()
{
    f[0] = 0;
    for (int i = 1; i <= m; ++ i){
        double tmp = 1.0;
        f[i] = p[0];
        for (int j = 1; j < n; ++ j){ 
            tmp *= f[i-1];
            f[i] += p[j] * tmp;
        }
    }

    double ret = 1.0;
    for (int i = 0; i < k; ++ i)
        ret *= f[m];
    return ret;
}
int main()
{
    int T;
    scanf ("%d", &T);
    int test = 0;
    while (T--){
        scanf ("%d%d%d", &n, &k, &m);
        for (int i = 0; i < n; ++ i)
            cin >> p[i];

        printf ("Case #%d: %.7lf\n", ++test,  gao());
    }
    return 0;
}
