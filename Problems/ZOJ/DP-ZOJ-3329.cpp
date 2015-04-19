/*
 * Author:  Plumrain
 * Created Time:  2013-10-30 09:57
 * File Name: math-ZOJ-3329.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, 0.0, sizeof(x))

int n, tot;
double p[20], a[1000], b[1000];

void init()
{
    int k[3], tmp, sum = 0;
    scanf ("%d", &n);
    for (int i = 0; i < 3; ++ i)
            scanf ("%d", &k[i]);
    for (int i = 0; i < 3; ++ i){
        scanf ("%d", &tmp);
        sum += tmp;
    }

    int num[20]; CLR (num);
    for (int i = 1; i <= k[0]; ++ i)
        for (int j = 1; j <= k[1]; ++ j)
            for (int l = 1; l <= k[2]; ++ l)
                ++ num[i+j+l]; 
    -- num[sum];

    int mul = k[0] * k[1] * k[2];
    tot = k[0] + k[1] + k[2];
    num[0] = 1;
    for (int i = 0; i <= tot; ++ i)
        p[i] = (double)num[i] / mul;
}

double DP()
{
    CLR (a); CLR (b);
    for (int i = n; i >= 0; -- i){ 
        a[i] = p[0];
        b[i] = 1.0;
        for (int j = 1; j <= tot; ++ j){
            a[i] += a[i+j] * p[j];
            b[i] += b[i+j] * p[j];
        }
    }
    
    return b[0] / (1 - a[0]);
}

int main()
{
    int T;
    scanf ("%d", &T);
    while (T--){
        init();
        printf ("%.10f\n", DP());
    }
    return 0;
}
