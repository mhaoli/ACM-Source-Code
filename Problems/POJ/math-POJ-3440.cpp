/*
 * Author:  Plumrain
 * Created Time:  2013-10-10 22:19
 * File Name: math-POJ-3440.cpp
 */
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

const double PI = atan(1.0)*4;

typedef long long int64;

int main()
{
    int T, test = 0;
    scanf ("%d", &T);
    while (T--){
        int64 m, n, t, c;
        if (test) printf ("\n");
        printf ("Case %d:\n", ++ test);
        scanf ("%lld%lld%lld%lld", &m, &n, &t, &c);
        int64 s = m * n * t * t;
        int64 s1 = m * n * (t-c) * (t-c) + (m+n) * c * (t-c) + c*c;
        int64 s2 = (2*m*n-m-n) * c * (t-c) + (m+n-2) * c * c;
        double s3 = (m-1) * (n-1) * c * c * (1-PI/4);
        double s4 = (m-1) * (n-1) * PI * c * c / 4;
        printf ("Probability of covering 1 tile  = %.4f%%\n", (double)s1/(double)s * 100.0);
        printf ("Probability of covering 2 tiles = %.4f%%\n", (double)s2/(double)s * 100.0);
        printf ("Probability of covering 3 tiles = %.4f%%\n", s3/(double)s * 100.0);
        printf ("Probability of covering 4 tiles = %.4f%%\n", s4/(double)s * 100.0);
    }
    return 0;
}
